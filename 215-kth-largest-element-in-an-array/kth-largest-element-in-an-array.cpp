class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> minHeap(nums.begin(), nums.begin() + k);
        int n = nums.size();
        for(int i = k;i < n;i++){
            if(minHeap.top() < nums[i]) {
               minHeap.pop();
               minHeap.push(nums[i]);
            }
        }
        return minHeap.top();

    }
};