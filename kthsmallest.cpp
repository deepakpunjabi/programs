#include <iostream>
using namespace std;

class btree
{
    int val;
    int size;
    btree *left;
    btree *right;

  public:
    btree(int v)
    {
        val = v;
        size = 1;
        left = right = NULL;
    }

    btree *insert(int v)
    {
        if (!this)
        {
            return new btree(v);
        }
        if (v < val)
        {
            left = left->insert(v);
            size++;
        }
        else
        {
            right = right->insert(v);
        }
    }

    int kth(int k)
    {
        if (!this)
        {
            return -1;
        }
        if (k < size)
        {
            return left->kth(k);
        }
        if (size == k)
        {
            return val;
        }
        right->kth(k - size);
    }

    void print()
    {
        if (!this)
        {
            return;
        }
        left->print();
        cout << val << " " << size << endl;
        right->print();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    int n, t;
    cin >> n;
    cin >> t;
    btree root(t);
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        root.insert(t);
    }
    root.print();
    cout << root.kth(2);
    return 0;
}
