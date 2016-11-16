#include<iostream>
#include<vector>

using namespace std;

int main(){
    int row,column;
    cin>>row>>column;
    vector<vector<int>> mat;
    mat = new vector<int>(row,vector<int>(column));

    mat[10][9]=89;
    cout<<mat[10][0]<<endl;
    cout<<mat[7][4]<<endl;
    cout<<mat[10][9]<<endl;
    return 0;
}
