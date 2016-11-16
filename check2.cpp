#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    list<pair<int,int>> l1;
    for(int i=0;i<5;i++){
        l1.push_back({i,i});
    }
    // auto i = l1.begin();
    // while(i!=l1.end()){
    //     if(i->first==3){
    //         i=l1.erase(i++);
    //         i--;
    //     }
    //     cout<<i->first<<endl;
	// 	i++;
    // }
    for(auto i:l1){
        if(i.first==3){
            i = l1.erase(i++);
            i--;
        }
        cout<<i->first<<endl;
    }
    return 0;
}
