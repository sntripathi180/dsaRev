#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0;i<n;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
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

    insertionSort(arr);

    cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
