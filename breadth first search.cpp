#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n,a,b,x,count=0;
    cin>>n;
    
    vector<bool> visited(n+1,false);
    vector<int> level(n+1,-1);
    unordered_map<int,vector<int> > tree;
   	queue<int> q;
    
    for(int i=1;i<n;i++){
    	cin>>a>>b;
    	tree[a].push_back(b);
    	tree[b].push_back(a);
    }
    
    cin>>x;
    visited[1]=true;
    level[1]=1;
    q.push(1);
    
    while(!q.empty()){
    	int u=q.front();
    	q.pop();
    	
    	for(auto i:tree[u]){
    		if(!visited[i]){
    			q.push(i);
    			visited[i]=true;
    			level[i]=level[u]+1;
    			if(level[i]==x){
    				count++;
    			}
    		}
    	}
    }
    cout<<count;
    return 0;
}

