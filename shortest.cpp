#include <iostream>
#include <queue>
#include <set>
// #define node struct node
using namespace std;

typedef struct graphnode
{
    string word;
    int clen;
} node;

/*node* createNode(string s,int len){
    node *temp = new node;
    temp->word = s;
    temp->clen = len;
    return temp;
}*/

bool isAdj(string s1, string s2)
{
    int diff = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            diff++;
        }
        if (diff > 1)
        {
            return false;
        }
    }
    return ((diff == 1) ? true : false);
}

int shortestChain(string &start, string &end, set<string> &dict)
{
    queue<node> q;
    node t;

    node first;
    first.word = start;
    first.clen = 1;
    q.push(first);

    while (!q.empty())
    {
        t = q.front();
        q.pop();
        // cout<<t.word<<endl;
        string s = t.word;
        // cout << s << endl;
        for (auto i : dict)
        {
            // cout << "normal " << i << endl;

            if (isAdj(s, i))
            {
                if (i == end)
                {
                    // cout << "match " << i << endl;
                    return t.clen + 1;
                }
                // cout << "matched " << s << " " << i << endl;
                first.word = i;
                first.clen = t.clen + 1;
                q.push(first);
                dict.erase(i);
                // break;
            }
        }
    }

    return -1;
}

int main()
{
    // make dictionary
    set<string> dict;
    dict.insert("poon");
    dict.insert("plee");
    dict.insert("same");
    dict.insert("poie");
    dict.insert("plie");
    dict.insert("poin");
    dict.insert("plea");
    string start = "toon";
    string target = "plea";
    // cout << __LINE__ << endl;
    // for (auto i : dict)
    // {
    //     cout << i << "\t" << endl;
    // }
    // cout << __LINE__ << endl;
    cout << shortestChain(start, target, dict) << endl;
    return 0;
}