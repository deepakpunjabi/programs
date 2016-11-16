#include <iostream>
#include <cstdlib>
#define node struct node
using namespace std;

node *front = NULL;
node *rear = NULL;

node{
    int data;
    node *nxt;
};

void enq(int x){
    node *temp = new node;
    temp->data = x;
    temp->nxt = NULL;

    if(!front && !rear){
        front = rear = temp;
        return;
    }

    rear->nxt = temp;
    rear = temp;
}

void deq(){
    node *temp = front;
    if(!front){
        cout<<"Queue is empty\n";
        return;
    }
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->nxt;
    }
    free(temp);
}

int frontq(){
    if(front == NULL){
        return -1;
    }
    return front->data;
}

void print(){
    node *temp =front;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->nxt;
    }
    cout<<endl;
}

int main(){
    enq(2);
    print();
    enq(4);
    print();
    cout<<frontq()<<endl;
    deq();    
    cout<<frontq()<<endl;
    enq(8);
    print();
    return 0;
}