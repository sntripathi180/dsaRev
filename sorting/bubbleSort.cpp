#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0;i<n-1;i++){
       bool flag = false;
       for(int j = 0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag = true;
        }
       }
       if(!flag){
        break;
       }
    }
}

void printArray(const vector<int> &arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}



int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    printArray(arr);

    bubbleSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}