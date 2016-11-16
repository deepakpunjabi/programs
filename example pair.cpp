#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<pair<int,string>> student(2);
    for(int i=0;i<=1;i++){
        //student[i]=make_pair(0,"hello");
        cout<<"enter your roll no: "<<endl;
        cin>>student[i].first;
        cout<<"enter your name: "<<endl;
        cin>>student[i].second;
    }

    for(int i=0;i<student.size();i++){
        cout<<student[i].first<<"\t"<<student[i].second<<endl;
    }

    return 1;
}
