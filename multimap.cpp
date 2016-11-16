#include<iostream>
#include<map>

using namespace std;

int main(){
    multimap<int,int> m1;

    m1.emplace(4,2);
    m1.emplace(1,2);
    m1.emplace(1,3);

    pair<int,int> r=m1.equal_range(1);
    for(auto i=r.first;r!=r.second;r++){
        cout<<r.second<<endl;
    }
    return 0;
}
