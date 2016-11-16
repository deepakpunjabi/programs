// Program to count islands in boolean 2D matrix
#include <iostream>
#include <list>
//#include <conio.h>
#include <vector>
#include <math.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    int DFSUtil(int v, bool visited[]);

  public:
    Graph(int V);
    void addEdge(int v, int w);
    void connectedComponents();
};

void Graph::connectedComponents()
{
    bool *visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    vector<int> vt;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            vt.push_back(DFSUtil(v, visited));
            cout << "\n";
        }
    }
    int sum = 0;
    for (int l = 0; l < vt.size(); l++)
        sum += ceil(sqrt(float(vt[l])));

    cout << sum << endl;
}

int Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    //cout << v << " ";

    int cnt = 1;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            cnt += DFSUtil(*i, visited);

    return cnt;
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[ V ];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{
    int n, k;
    cin >> n >> k;
    Graph g(n);

    for (int i = 0; i < k; i++)
    {
        int p, q;
        cin >> p >> q;
        g.addEdge(p - 1, q - 1);
    }

    g.connectedComponents();
    //getch();
    return 0;
}