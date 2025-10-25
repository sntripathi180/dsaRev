#include <bits/stdc++.h>
using namespace std;

void selectSort(vector<int> &arr){
    int n  = arr.size();
    for(int i = 0;i<n-1;i++){
        int minidx = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minidx]){
                minidx = j;
            }
        }
        swap(arr[i],arr[minidx]);
    }
}

void printArray(const vector<int> &arr) {
    for (int x : arr)
        cout << x << " ";
    cout << "\n";
}

int main(){
 vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr);

    selectSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
