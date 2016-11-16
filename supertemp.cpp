#include<bits/stdc++.h>

using namespace std;

//int digit(int x)
//{
//    if(x >= 10)
//       digit(x / 10);
//
//    int digit = x % 10;
//
//    //cout << digit << '\n';
//    return digit;
//}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,same1=0,same2=0;
        cin>>a>>b;

        string x=to_string(a);
        string y=to_string(b);

        int size = min(x.length(),y.length());
        cout<<size<<endl;

        for(int i=0;i<size;i++){
            if(x[i]==y[i]){
                ++same1;
            }
        }
        cout<<"same 1 "<<same1<<endl;

//        for(int i=size-1;i>=0;i--){
//            if(x[i]==y[i]){
//                ++same2;
//            }
//        }

        for(int i=x.length()-1;i>=size;i--){
            if(x[i]==y[i]){
                ++same2;
            }
        }
        cout<<"same2 "<<same2<<endl;

//        string x1(x.begin()+same1,x.length()-same2);
//        string x2(y.begin()+same1,y.length()-same2);

        string x1 = x.substr(same1,x.length()-same2);
        string x2 = y.substr(same1,y.length()-same2);
        cout<<x1<<endl;
        cout<<x2<<endl;

        unordered_map<char,int> m1(10);
        unordered_map<char,int> m2(10);

        //cout<<m1[3]<<endl;

        for(auto i:x1){
            m1[i] +=1;
        }

        for(auto i:x2){
            m2[i] +=1;
        }

        for(auto i:m1){
            cout<<i.first<<" "<<i.second<<endl;
        }
        //cout<<"--------";
        for(auto i:m2)
            cout<<i.first<<" "<<i.second<<endl;
        //cout<<m1[2];


    }

    return 0;
}
