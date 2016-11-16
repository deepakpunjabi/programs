#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int c=a-b;

	string s=to_string(c);
	s[0]=s[0]=='1'?'2':'1';
	cout<<s;
	return 0;
}
