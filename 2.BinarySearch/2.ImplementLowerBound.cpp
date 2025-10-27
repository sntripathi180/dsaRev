// https://www.geeksforgeeks.org/problems/implement-lower-bound/1

class Solution {
    public:
    int lowerBound(vector<int> & arr, int target){
        int l =0,r= arr.size()-1;
        int ind = arr.size();

        while(l<=r){
            int mid = l +(r-l)/2;
            if(arr[mid] >= target){
                ind = mid;
                r = mid -1;
            }else{
                l = mid+1;
            }
        }

        return ind;
    }
}