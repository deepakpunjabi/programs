#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int src,dst;
}edge;

typedef struct{
    int v,e;
    vector<edge> edj;
}graph;

graph* createGraph(int v,int e){
    graph* g=new graph;
    g->v=v;
    g->e=e;
    g->edj=vector<edge> (g->e);
    return g;
}

int find(vector<int> parent,int i){
    if(parent[i]==-1)
        return i;
    return find(parent,parent[i]);
}

void union1(vector<int>& parent,int x,int y){
    int set1=find(parent,x);
    int set2=find(parent,y);
    parent[set1]=set2;
}

int isCycle(graph * g){
    vector<int> parent(g->v,-1);

    for(int i=0;i<g->e;i++){

        int x=find(parent,g->edj[i].src);
        int y=find(parent,g->edj[i].dst);

        if(x==y){
            cout<<"parent of "<<g->edj[i].src<<" and "<<g->edj[i].dst<<" is same."<<endl;
            return 1;
        }
        cout<<"merging "<<x<<" and "<<y<<endl;


        union1(parent,x,y);
        for(auto i:parent){
            cout<<i<<endl;
        }
    }

    for(auto i:g->edj){
        cout<<"src "<<i.src<<" ";
        cout<<"dst "<<i.dst<<endl;

    }


    return 0;
}
int main(){
    int v=3,e=3;

    graph* g=createGraph(v,e);

    g->edj[0].src = 0;
    g->edj[0].dst = 1;

    // add edge 1-2
    g->edj[1].src = 1;
    g->edj[1].dst = 2;

    // add edge 0-2
//    g->edj[2].src = 0;
//    g->edj[2].dst = 2;

    if (isCycle(g))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );

    return 0;
}
