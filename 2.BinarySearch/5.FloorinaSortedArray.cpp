// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1


class Solution{
    public:
   int findFloor(vector<int>& arr, int x){
     int ans = -1;
    int l=0;
    int h = arr.size()-1;
    while(l<=h){
        int mid = l +(h-l)/2;
        if(arr[mid]<=x){
            ans = mid;
            l = mid +1;

        }else{
            h = mid+1;
        }
    }
    return ans;
   }
}