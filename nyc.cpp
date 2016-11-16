#include<iostream>
using namespace std;
int main(){
    int t,i;
    cin>>t;
    while(t){
        int n,swap=0;
        cin>>n;

        bool flag=true;
        vector<int> a(n),c(n,2);
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        while(flag){
            for(i=0;i<n;i++){
                if(a[i]>a[i+1]){
                    if(c[i]>0){
                        c[i]--;
                        swap++;
                        int temp=a[i];
                        a[i]=a[i+1];
                        a[i+1]=temp;
                    }
                    else{
                        cout<<"Too chaotic"<<endl;
                        flag=false;
                    }
                }
            }
            bool sorted=true;
            for(i=0;i<n;i++){
                if(a[i]>a[i+1])
                    sorted=false;
            }
            if(sorted==true){
                cout<<swap<<endl;
            }
        }

    }
    return 0;
}
