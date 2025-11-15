// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1


// Approach: Binary Search (using custom lowerBound and upperBound)

// Time Complexity: O(log N)
// Space Complexity: O(1)

 int countFreq(vector<int>& arr, int target){
    int l = lowerBound(arr,target);
    if(l == -1 || arr[l] != target) return 0;
    int h = upperBound(arr,target);
    if(h == -1) h = arr.size();
    return  h-l ;
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

========== java ========
 public int countFreq(int[] arr, int target) {
        int l = lowerBound(arr, target);
        if (l == -1 || arr[l] != target) return 0;

        int h = upperBound(arr, target);
        if (h == -1) h = arr.length;

        return h - l;
    }

    private int lowerBound(int[] arr, int target) {
        int low = 0, high = arr.length - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }


    private int upperBound(int[] arr, int target) {
        int low = 0, high = arr.length - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
 