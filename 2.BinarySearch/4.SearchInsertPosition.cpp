// https://leetcode.com/problems/search-insert-position/description/

class Solution{

    public:
    int searchInsert(vector<int>&nums,int target){
        int l =0;
        int n = nums.size()-1;
        while(l<=n){
            int mid = l +(n-l)/2;
            if(nums[mid]==target){
                    return m;
            }
           else if(nums[mid]<target) l = mid+1;
else n = mid-1;

        }
        return l;
    }
}