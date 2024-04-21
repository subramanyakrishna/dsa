class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0 ,high = arr.size()-1;
        int ans =INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[low] < arr[high]) return min(arr[low],ans);
            if (arr[mid] <= arr[high]) {
                ans = min(arr[mid],ans);
                high = mid-1;
            } else {
                ans = min(arr[low],ans);
                low = mid+1;
            }
        }
        return ans;
    }
};