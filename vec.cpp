#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,i;
    cin>>t;
    while(t--){
        int n,swap=0;
        cin>>n;

        bool flag=true;
        vector<int> a(n),c(n,2);
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        while(flag){
            for(i=0;i<n-1;i++){
                if(i+1==n){
                    flag=false;
                    break;
                }
                if(a[i]>a[i+1]){
                    cout<<"ai and ai+1 are "<<a[i]<<" "<<a[i+1]<<endl;
                    if(c[a[i]-1]>0){
                        cout<<"credit of node ai "<<a[i]-1<<"is "<<c[a[i]-1]<<endl;
                        c[a[i]-1]-=1;
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
            cout<<"swap till now "<<swap<<endl;
            cout<<"array"<<endl;
            bool sorted=true;
            for(i=0;i<n;i++){

                cout<<a[i]<<" ";
                if(i+1==n){
                    sorted=true;
                    flag=false;
                    break;
                }
                if(a[i]>a[i+1])
                    sorted=false;
            }
            if(sorted==true){
                cout<<swap<<endl;
                flag=false;
            }
        }

    }
    return 0;
}
