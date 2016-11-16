/* A worst case O(nLogn) implementation of quicksort */
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

/*int kthSmallest(vector<int> &a,int low,int high,int k){
    if(k>0 && k<=r-l+1)
    {
        int n = r-l+1;
        int i;
        int median[(n+4)/5];

        for(i=0;i<n/5;i++){
            median[i] = findMedian()
        }
    }

}*/

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    // for (i = l; i < high; i++)
    // {
    //     if (a[i] == med)
    //     {
    //         break;
    //     }
    // }
    // swap(a[i], a[high]);

    int i = low;
    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] <= pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i],a[high]);
    return i;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int size = high - low + 1;
        // int med = kthSmallest(a, low, high, size / 2);
        // int med = low;
        int pivot = partition(a, low, high);

        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}

void printArray(vector<int> &a)
{
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}

// Driver program to test above functions
int main()
{
    vector<int> a = {1000, 10, 7, 8, 9, 30, 900, 1, 5, 6, 20};
    quickSort(a, 0, a.size() - 1);
    cout << "Sorted array is\n";
    printArray(a);
    return 0;
}