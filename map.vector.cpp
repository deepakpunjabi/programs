#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<int,vector<int>> map1;

    if(map1.find(2)!=map1.end()){
        cout<<"foudn";
    }
    else{
        cout<<"not found";
    }

    return 0;
}
