#include <iostream>
#include<vector>
#include<map>
#define o(key) cout<<key<<endl
using namespace std;

int main(){
    int j[]={1,2,3,4,5};
    vector<int> v1(10);
    map<string,string> map1={{"hello","one"},{"world","two"}};

//    for(auto i:j){
//        cout<<i<<endl;
//    }
//    cout<<endl;
//    for(auto i:v1){
//        cout<<v1[i]<<endl;
//    }
//    cout<<endl;
//    for(auto i:map1){
//        cout<<i.first<<"\t"<<i.second<<endl;
//    }

    cout<<map1.erase("hello")<<endl;
    cout<<map1.size()<<endl;
    cout<<map1.empty()<<endl;

    //find a specified key
    if(map1.find("hello")==map1.end())
        o("not found");
    return 1;
}
