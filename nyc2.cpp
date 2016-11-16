#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t,i;
    cin>>t;
    while(t--){
        int n,swap=0;
        cin>>n;

        bool flag=true,pri=false;
        vector<int> a(n),c(n,2);
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        while(flag){
            for(i=0;i<n-1;i++){
                /*if(i+1==n){
                    flag=false;
                    break;
                }*/
                if(a[i]>a[i+1]){
                    if(c[a[i]-1]>0){
                        c[a[i]-1]-=1;
                        swap++;
                        int temp=a[i];
                        a[i]=a[i+1];
                        a[i+1]=temp;
                    }
                    else{
                        cout<<"Too chaotic"<<endl;
                        flag=false;
                        pri=true;
                        break;
                    }
                }
            }
            bool sorted=true;
            for(i=0;i<n-1;i++){
                /*if(i+1==n){
                    sorted=true;
                    flag=false;
                    break;
                }*/
                if(a[i]>a[i+1]){
                    sorted=false;
                    //flag=false;
                    break;
                }


            }

            if(sorted==true && pri==false){
                cout<<swap<<endl;
                flag=false;
            }
        }

    }
    return 0;
}
