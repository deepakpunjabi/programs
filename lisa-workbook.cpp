#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k,p=0,sp=0,pi,ni,np;
    int pre,next;
    cin>>n>>k;
    //cout<<"value of n and k are "<<n<<" "<<k;
    vector<int> t(n);
    for(int i=0;i<n;i++){
        //cout<<endl<<"chapter"<<i+1<<endl;
        cin>>t[i];
        np=t[i];
        //cout<<"no of pro "<<np<<endl;
        pi=0;
        while(np>0){
            p++;
            pre=pi;
            if(np-k>=0){
                next=pi+k;
                pi+=k;
                np-=k;
            }
            else{
                next=pi+np;
                pi+=np;
                np=0;
            }

            //cout<<"pre & next "<<pre<<" "<<next<<endl;
            //cout<<"page no "<<p<<endl;
            if(p>pre && p<=next){
                sp++;

            }
            //cout<<"value of sp: "<<sp<<endl;
            //cout<<"curent value of np: "<<np<<endl;
            /*if(np-k >= 0){
                pi+=k;
                np-=k;

            }
            else{
                pi+=np;
                np=0;
            }*/
            //cout<<"value of next pi "<<pi<<endl;
            //cout<<"value of remaining problems"<<np<<endl;
        }
    }
    cout<<sp<<endl;
    return 0;
}
