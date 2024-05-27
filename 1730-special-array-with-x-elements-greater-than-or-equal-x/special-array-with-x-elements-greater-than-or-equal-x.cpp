class Solution {
public:
    int specialArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int  n = nums.size();
        if(nums[0] >= n) return n;
        for(int i = n-1 ; i > 0 ; i--){
            if(nums[n-i] >= i && nums[n-i-1] < i ) return i; 
        }
        return -1;

    }
};
