// https://www.geeksforgeeks.org/problems/implement-upper-bound/0

// element jusst greater than a given number

class Solution{
    public:
    int upperBound(vector<int>& arr,int target){
        int l = 0;
        int r = arr.size()-1;
        int ans = arr.size();
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]>target){
                ans = mid;
                r = mid -1;

            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
}