#include <bits/stdc++.h>

using namespace std;
class graph
{
    int v;
//    list<int> *adj;
    unordered_map<int,vector<int>> adj;

public:


    graph(int v)
    {
        this->v=v;
    }

    void addEdge(int u,int v)
    {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    void bfs(int s)
    {
        vector<bool> visited(v,false);
        vector<int> distance(v,0);

        deque<int> q;

        visited[s]=true;
        q.push_back(s);

        while(!q.empty())
        {
            int f = q.front();
            q.pop_front();

            for(auto i:adj[f])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    q.push_back(i);
                    distance[i]=distance[f]+6;
                }
            }

        }

        for(int i=0; i<v; i++)
        {
            if(i == s)
                continue;

            if(distance[i]==0)
                cout<<"-1 ";
            else
                cout<<distance[i]<<" ";


        }
        cout<<endl;
    }
};
int main()
{
    int query,v,e,s;
    cin>>query;

    while(query--)
    {
        cin>>v>>e;

        graph g(v);
        for(int i=0; i<e; i++)
        {
            int a,b;
            cin>>a>>b;
            g.addEdge(a-1,b-1);
        }

        cin>>s;
        g.bfs(s-1);
    }

    return 0;
}
