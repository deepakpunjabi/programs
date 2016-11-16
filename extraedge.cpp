#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
// #include <unordered_map>
// #include <pair>
#define mypair pair<int, int>
using namespace std;

class Graph
{
    int v_;
    map<int, vector<mypair>> adj;

  public:
    Graph(int x)
    {
        v_ = x;
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first + 1 << " --> ";
            for (auto j : i.second)
            {
                cout << " ( " << j.first + 1 << " , " << j.second << " ) , ";
            }
            cout << endl;
        }
    }

    int dijkstra(int start, int end, int extra)
    {

        priority_queue<mypair, vector<mypair>, greater<mypair>> pq;
        vector<int> dis(v_, INT_MAX);

        pq.emplace(0, start);
        dis[start] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            for (auto i : adj[u])
            {
                int v = i.first;
                int w = i.second;

                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    pq.emplace(dis[v], v);
                }
            }
        }

        /*        for (auto &i : dis)
        {
            if (i == 0)
                continue;
            if (i == INT_MAX)
                // i = -1;
                cout << "-1 ";
            else
                cout << i << " ";
        }
        cout << endl;*/

        priority_queue<mypair, vector<mypair>, greater<mypair>> pq1;
        vector<int> dis1(v_, INT_MAX);

        pq1.emplace(0, end);
        dis1[end] = 0;

        while (!pq1.empty())
        {
            int u = pq1.top().second;
            pq1.pop();

            for (auto i : adj[u])
            {
                int v = i.first;
                int w = i.second;

                if (dis1[v] > dis1[u] + w)
                {
                    dis1[v] = dis1[u] + w;
                    pq1.emplace(dis1[v], v);
                }
            }
        }

        /*      for (auto &i : dis1)
        {
            if (i == 0)
                continue;
            if (i == INT_MAX)
                // i = -1;
                cout << "-1 ";
            else
                cout << i << " ";
        }
        cout<<endl;*/
        int distance = dis[end];
        if (distance < extra)
        {
            return distance;
        }
        if (find(adj[start].begin(), adj[start].end(), end) == adj[start].end())
        {
            return extra;
        }
        priority_queue<mypair, vector<mypair>, greater<mypair>> p1, p2;

        for (int i = 0; i < v_; i++)
        {
            if (dis[i] < distance && i != start)
            {
                p1.emplace(dis[i], i);
            }
            if (dis1[i] < distance && i != end)
            {
                p2.emplace(dis1[i], i);
            }
        }

        while (!p1.empty() || !p2.empty())
        {
            if (p1.top().first < p2.top().first)
            {
                if (find(adj[p1.top().second].begin(), adj[p1.top().second].end(), end) == adj[p1.top().second].end() && dis[p1.top().second] + extra < distance)
                {
                    return dis[p1.top().second] + extra;
                }
                p1.pop();
            }
            else
            {
                if (find(adj[p2.top().second].begin(), adj[p2.top().second].end(), start) == adj[p2.top().second].end() && dis1[p2.top().second] + extra < distance)
                {
                    return dis1[p2.top().second] + extra;
                }
                p2.pop();
            }
        }
        return -1;
    }
};

void printall(pair<vector<int>, vector<int>> di)
{
    for (auto i : di.first)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : di.second)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    long n, m;
    cin >> n >> m;
    Graph g(n);

    while (m--)
    {
        int x, y, r;
        cin >> x >> y >> r;
        g.addEdge(x - 1, y - 1, r);
    }

    int s, e, extra;
    cin >> s >> e >> extra;
    //g.print();
    cout << g.dijkstra(s - 1, e - 1, extra);

    return 0;
}