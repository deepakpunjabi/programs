#include<iostream>
using namespace std;

int main()
{

int N;
cin >> N;

int arr[N];
for(int i=0;i<N;i++)
{
	cin >> arr[i];
}

int temp;

//for(int i=0;i<N;i=i+2)
//{
//	if(i+1<N && arr[i+1]>arr[i])
//	{
//
//		temp = arr[i+1];
//		arr[i+1] = arr[i];
//		arr[i] = temp;
//		//swap arr[i+1] and arr[i]
//	}
//
//	if(i+2<N && arr[i+1]>arr[i+2])
//	{
//		temp = arr[i+2];
//		arr[i+2] = arr[i+1];
//		arr[i+1] = temp;
//		//swap arr[i+2] and arr[i+1]
//	}
//
//}

for(int i=0;i<N;i+=2){
    if(i+1<N && arr[i]<arr[i+1])
        swap(arr[i],arr[i+1]);
    if(i+2<N && arr[i+1]>arr[i+2])
        swap(arr[i+1],arr[i+2]);
}
cout << endl;
for(int i=0;i<N;i++)
{
	cout << arr[i] << " ";
}

return 0;
}
