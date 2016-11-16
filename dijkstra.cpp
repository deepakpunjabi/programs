#include <bits/stdc++.h>
#define mypair pair<int,int>

using namespace std;

class Graph {
    int V;
    unordered_map <int,vector<mypair>> adj;

    public:

    Graph(int x){
        V=x;
    }

    void addEdge(int u,int v,int w){
        bool present=false;


        if(adj.find(u)!=adj.end()){

            for(auto& i:adj[u]){
                //find v in it
                if(i.first==v){
                    present=true;

                    if(i.second>w){
                        i.second=w;
                    }
                    break;
                }
            }

            if(present==false){
                adj[u].emplace_back(v,w);
                adj[v].emplace_back(u,w);
            }
            else{
                for(auto& j:adj[v]){
                    if(j.first==u && j.second>w){
                        j.second=w;
                        break;
                    }

                }

            }

        }
        else{
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }

    }

    void print(){
        for(auto i:adj){
            cout<<i.first+1<<" --> ";
            for(auto j:i.second){
                cout<<" ( "<<j.first+1<<" , "<<j.second<<" ) , ";
            }
            cout<<endl;
        }
    }

    void dijkstra(int s){

        priority_queue <mypair, vector<mypair>, greater<mypair> > pq;
        vector<int> dis(V,INT_MAX);

        pq.emplace(0,s);
        dis[s]=0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            for(auto i:adj[u]){
                int v = i.first;
                int w = i.second;

                if(dis[v]>dis[u]+w){
                    dis[v] = dis[u] + w;
                    pq.emplace(dis[v],v);
                }
            }
        }

        for(auto i:dis){
            if(i==0)
                continue;
            if(i==INT_MAX)
                cout<<"-1 ";
            else
                cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main() {
    int t;
    cin>>t;

    while(t--){
        long n,m;
        cin>>n>>m;
        Graph g(n);

        while(m--){
            int x,y,r;
            cin>>x>>y>>r;
            g.addEdge(x-1,y-1,r);
        }


        int s;
        cin>>s;
        //g.print();
        g.dijkstra(s-1);
    }

    return 0;
}
