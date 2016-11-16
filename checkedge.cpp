#include <bits/stdc++.h>

using namespace std;

class Graph{
	int v,e;
	int **a;

	public:
	Graph(int v){
		this->v=v;
		this->e=e;

		a = new int*[v];
		for(int i = 0; i < v; ++i) {
    		a[i] = new int[v];
		}
	}

	void addEdge(int x,int y){
		a[x][y]=1;
		a[y][x]=1;
	}

	void checkEdge(int x,int y){

		if(a[x][y]==1 || a[y][x]==1)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;

	Graph g(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u-1,v-1);
	}

	int q;
	cin>>q;

	int x,y;
	while(q--){
		cin>>x>>y;
		g.checkEdge(x-1,y-1);
	}
    return 0;
}
