class Solution {
public:
    int helper(vector<int>& nums,int n,vector<int> &dp ){
        if(n<=0) return 0;
        if(n==1) return nums[0];
        if(dp[n-1]!=-1) return dp[n-1];
        return dp[n-1] = max(helper(nums,n-2,dp)+nums[n-1] , helper(nums,n-1,dp));
    }   
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums,nums.size(),dp);
    }
};

 