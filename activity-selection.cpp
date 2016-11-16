#include<iostream>

using namespace std;

void selectActivity(int s[], int f[], int n){
    int start,finish;
    start=0;
    cout<<"List of activities selected"<<endl;
    cout<<start<<" ";

    for(finish=1;finish<n;finish++){
        if(s[finish]>=f[start]){
            cout<<finish<<" ";
            start=finish;
        }
    }
}

int main()
{
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);

    selectActivity(s, f, n);

    return 0;
}
