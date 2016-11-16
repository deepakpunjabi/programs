#include<iostream>
using namespace std;
class node
{
    int data;
    node *top;
    node *link;
    public:
    node()
    {
       top=NULL;
       link=NULL;
    }
    void push(int x)
    {
        node *n=new node;
        n->data=x;
        n->link=top;
        top=n;
        cout<<"Pushed "<<n->data<<endl;
    }
    void pop()
    {
        node *n=new node;
        n=top;
        top=top->link;
        n->link=NULL;
        cout<<"Popped "<<n->data<<endl;
        delete n;
    }
    void print()
    {
        node *n=new node;
        n=top;
        while(n!=NULL)
        {
            cout<<n->data<<endl;
            n=n->link;
        }
        delete n;
    }
};


int main()
{
    node stack;
    stack.push(5);
    stack.push(7);
    stack.push(9);
    stack.pop();
    stack.print();
}