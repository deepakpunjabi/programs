/* 
   I solved it using dijkstra as in my previous post. I noticed how ever, the weight of the additional
   edge is not 0 but 2 and that you may go over an intermediate node since the node you currently are
   has a direct connection to end that is more expensive than when you would add the bonus-Edge to an 
   other node and go from there to the end.
   So, again, I noticed how important it is to verify the steps before coding and getting into depth or
   making wrong statements :-) The further I go with an error the more expensive to fix (in terms of 
   wasted time).

   The key idea is to dynamically extend the graph to a graph g'. When ever we are on a vertex in 
   the original graph g, there are the edges given + to every other vertex where no edge was given
   there exists the "bonus edge". Once used we are in g' and can't use the "bonus edge" anymore.
   That is, im g' there exist only the original edges to vertices in g but to their "mirror" in
   g'. 

   Visually, I drew the original graph g and on top a layer with the graph g'... Besides 
   this I could use dijkstra. A vertex is identified with an integer in this solution. A vertex
   in g has an id below a certain value and a vertex in g' has just an offset to that id. There
   are certainly more apealing designs to that, but it did work and I could verify some basic
   cases.
*/

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <iostream>

struct Edge
{
    int destId_, weight_;

    Edge(int destId, int weight) : destId_(destId), weight_(weight) {}
};

struct TraversalItem
{
    int vertexId_, cost_, parentId_;
    TraversalItem(int vertexId, int cost, int parentId)
        : vertexId_(vertexId), cost_(cost), parentId_(parentId) {}
    TraversalItem() : TraversalItem(-1, -1, -1) {}
};

using Path = std::pair<int, std::vector<std::pair<int, bool>>>;

class Graph
{
  private:
    const int bonusVertexIdOffset = 100000;
    std::unordered_map<int, std::unordered_map<int, int>> edges_;
    std::unordered_set<int> vertices_;

  public:
    void addEdge(int u, int v, int weight)
    {
        if (u >= bonusVertexIdOffset || v >= bonusVertexIdOffset)
            throw "id out of range";
        edges_[u][v] = weight;
        edges_[v][u] = weight;
        addVertex(u);
        addVertex(v);
    }

    void addVertex(int vertexId)
    {
        if (vertexId >= bonusVertexIdOffset || vertexId >= bonusVertexIdOffset)
            throw "id out of range";
        vertices_.insert(vertexId);
    }

    // main part of algorithm
    // it returns the path cost and the visited vertice id's with a flag wether they were in g or g'
    Path getShortestPathWithBonusEdge(int start, int end, int bonusWeight)
    {
        auto tiComparer = [](const TraversalItem &a, const TraversalItem &b) -> bool { return a.cost_ > b.cost_; };
        std::priority_queue<TraversalItem, std::vector<TraversalItem>, decltype(tiComparer)> tqueue(tiComparer);
        std::unordered_map<int, TraversalItem> state;

        tqueue.push(TraversalItem(start, 0, -1));                                         // start with start
        state.emplace(std::pair<int, TraversalItem>(start, TraversalItem(start, 0, -1))); // start must be in state, too
        while (tqueue.size() > 0)
        {
            auto u = tqueue.top();
            tqueue.pop();

            int uId = u.vertexId_;
            if (uId == end || uId == end + bonusVertexIdOffset)
            {
                end = uId; // path end id, it might be in g'
                break;     // if end is now the cheapest to reach: done
            }
            auto edges = getOutEdges(uId, bonusWeight);
            for (auto edge : edges)
            {
                int cost = u.cost_ + edge.weight_;
                int vId = edge.destId_;
                auto vStateIt = state.find(vId);
                if (vStateIt == state.end())
                {
                    TraversalItem ti(vId, cost, uId);
                    vStateIt = state.emplace(std::pair<int, TraversalItem>(vId, ti)).first;
                    tqueue.push(ti);
                }
                else if (vStateIt->second.cost_ > cost)
                {
                    vStateIt->second.cost_ = cost;
                    vStateIt->second.parentId_ = uId;
                    tqueue.push(vStateIt->second); // since there's no update-key function...
                }
            }
        }

        // reconstruct path
        auto stateIt = state.find(end);
        if (stateIt != state.end())
        {
            // reached the end
            std::vector<std::pair<int, bool>> path;
            int vertexId = stateIt->second.vertexId_;
            int cost = stateIt->second.cost_;
            while (vertexId != -1)
            {
                bool gs = vertexId >= bonusVertexIdOffset;
                int vId = gs ? vertexId - bonusVertexIdOffset : vertexId;
                path.push_back(std::pair<int, bool>(vId, gs));
                vertexId = state[vertexId].parentId_;
            }
            return Path(cost, std::vector<std::pair<int, bool>>(path.rbegin(), path.rend()));
        }
        return Path(-1, std::vector<std::pair<int, bool>>()); // empty path
    }

  private:
    std::vector<Edge> getOutEdges(int vertexId, int bonusEdgeWeight)
    {
        std::vector<Edge> edges;

        int u = vertexId;
        int vIdOffset = 0;
        if (u >= bonusVertexIdOffset)
        {
            u -= bonusVertexIdOffset;

            // bonusedge already used, so only original edges are possible
            auto edgeIt = edges_.find(u);
            if (edgeIt != edges_.end())
            {
                for (auto v : edgeIt->second)
                {
                    // use orginial edge but stay in g'
                    edges.push_back(Edge(v.first + bonusVertexIdOffset, v.second));
                }
            }
            return edges;
        }

        // a vertex that was reaches without bonus edge, so
        // every pair of edges is possible: either from the original
        // graph or using the bonusEdge
        for (auto v : vertices_)
        {
            if (v == u)
                continue;
            auto edgeIt1 = edges_.find(u);
            if (edgeIt1 != edges_.end())
            {
                auto edgeIt2 = edgeIt1->second.find(v);
                if (edgeIt2 != edgeIt1->second.end())
                {
                    // use original edge within g
                    edges.push_back(Edge(v, edgeIt2->second));
                    continue;
                }
            }
            // add bonus edge to g'
            edges.push_back(Edge(v + bonusVertexIdOffset, bonusEdgeWeight));
        }

        return edges;
    }
};

void printResult(int start, int end, int bonusWeight, const Path &path)
{
    std::cout << "shortes path from " << start << " to " << end
              << " with bonus edge weight " << bonusWeight << " is " << std::endl;
    std::cout << "  weight: " << path.first << std::endl;
    std::cout << "  path: ";
    for (auto v : path.second)
    {
        std::cout << v.first << (v.second ? "' " : " ");
    }
    std::cout << std::endl
              << std::endl;
}

int main()
{
    Graph g;
    g.addEdge(1, 2, 2);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 8);
    g.addEdge(3, 6, 9);
    g.addEdge(1, 6, 99);
    g.addEdge(2, 6, 99);
    g.addVertex(20);

    printResult(1, 5, 2, g.getShortestPathWithBonusEdge(1, 5, 2));
    printResult(1, 4, 2, g.getShortestPathWithBonusEdge(1, 4, 2));
    printResult(1, 5, 50, g.getShortestPathWithBonusEdge(1, 5, 50));
    printResult(1, 6, 9, g.getShortestPathWithBonusEdge(1, 6, 9));
    printResult(1, 6, 7, g.getShortestPathWithBonusEdge(1, 6, 7));
    printResult(1, 20, 25, g.getShortestPathWithBonusEdge(1, 20, 25));

    /* Output
	shortes path from 1 to 5 with bonus edge weight 2 is
	weight: 2
	path: 1 5'

	shortes path from 1 to 4 with bonus edge weight 2 is
	weight: 3
	path: 1 5' 4'

	shortes path from 1 to 5 with bonus edge weight 50 is
	weight: 5
	path: 1 4 5

	shortes path from 1 to 6 with bonus edge weight 9 is
	weight: 12
	path: 1 2 3 6

	shortes path from 1 to 6 with bonus edge weight 7 is
	weight: 11
	path: 1 4 6'

	shortes path from 1 to 20 with bonus edge weight 25 is
	weight: 25
	path: 1 20'
	*/
}