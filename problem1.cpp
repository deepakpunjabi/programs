/*
number string

You are given two number-strings A and B. A number-string is a string that contains only digits ['0'-'9'].

The task is to make both the strings equal. The only operation that you are allowed to do is to delete a character (i.e. digit) from any of the strings (A or B).

The cost of an operation of deleting a digit D is D units.
Now, you have to make both the number-strings equal in minimum cost.

Constraints:
1 <= T <= 10
1 <= length(A),length(B) <= 1000

Input Format:
First line of each testfile contains T, the number of test cases.
In each testcase, first line contains number-string A and second line contains number-string B.

Output Format:
For each test case, output only line containing the minimum cost to make both number-strings equal.

Example:

Input:
3
7135
135
816337897
816393804
816337597
816393504

Output:
7
36
34

*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define max 99999

using namespace std;

struct comp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)const
    {
        return a.second > b.second;
    }
};

int main()
{
    int n,m;
    int x,y,r;
    int start;

    int sz;

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
        graph[x].push_back(make_pair(y,r));
        graph[y].push_back(make_pair(x,r));
    }

    start  = 0;

    int distance[n];
    bool visited[n];

    for(i=0; i<n; i++)
    {
        distance[i]=max;
        visited[i]=false;
    }

    priority_queue< pair<int,int>, vector<pair<int,int> >, comp> Q;

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
                Q.push(make_pair(y,r));
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
