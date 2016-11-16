#include<bits/stdc++.h>
#define mypair pair<int,int>
#define max 99999

using namespace std;

int main()
{
    int n,m,x,y,r,start,sz;

    cin >> n;
    cin >>m;

    vector< pair<int, int> > graph[n];

    int i;
    for(i=0; i<m; i++)
    {
        cin >> x;
        cin >> y;
        cin >> r;
        if(r==1)
        {
            cin >> r;
        }
        x--;
        y--;
        graph[x].emplace_back(y,r);
        graph[y].emplace_back(x,r);
    }

    start  = 0;

    vector<int> distance(n,max);
    vector<bool> visited(n,false);

    priority_queue< mypair, vector<mypair >, greater<mypair > > Q;
    Q.push(make_pair(start,0));
    distance[start]=0;

    while(!Q.empty())
    {
        x = Q.top().first;
        Q.pop();

        if(visited[x])continue;

        sz= graph[x].size();

        for(i=0; i<sz; i++)
        {
            y= graph[x][i].first;
            r= graph[x][i].second;

            if(visited[y] == false && distance[y] > r)
            {
                distance[y]=r;
                Q.emplace(y,r);
            }
        }

        visited[x]=true;
    }


    int result =0;
    for(i=0; i<n; i++)
    {
        if(distance[i] != max)
        {
            result += distance[i];
        }
    }
    cout << result << endl;
    return 0;
}

