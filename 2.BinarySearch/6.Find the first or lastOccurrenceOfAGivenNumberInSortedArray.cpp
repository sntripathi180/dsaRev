// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


// Approach: Binary Search (Custom lowerBound & upperBound)
// Time Complexity: O(log N)
// Space Complexity: O(1)

vector<int> searchRange(vector<int>& arr, int target){
    int l = lowerBound(arr,target);
    if(l == -1 || arr[l] != target) return {-1,-1};
    int h = upperBound(arr,target);
    if(h == -1) h = arr.size();
    return {l , h -1};
}

int lowerBound(vector<int>&arr, int target){
    int n = arr.size();
    int low = 0;
    int ans = -1;
    int high = n-1 ;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid]>= target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr,int target){
    int ans = -1;
    int n = arr.size();
    int low = 0;

    int high = n-1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(arr[mid]>target){
            ans = mid ;
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    return ans;
}

// =======java ======


public int[] searchRange(int[] nums,int target){
    int l = lowerBound(nums,target);
    if(l == -1 || nums[l] != target) return new int[]{-1,-1};

    int h = upperBound(nums,target);
    if(h == -1)  h = nums.length;

    return new int[]{l,h-1};
}

private int lowerBound(int[] nums,int target){
    int low = 0,high = nums.length-1,ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(nums[mid]>= target){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
    return ans;
}

private int upperBound(int[] nums, int target) {
        int low = 0, high = nums.length - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
}
