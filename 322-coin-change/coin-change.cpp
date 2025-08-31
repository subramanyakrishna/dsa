class Solution {
public:
    int recurr(vector<int>& coins, int amount, vector<int> &  dp) {
        if (amount == 0) return 0;
       
        if (dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for (auto coin : coins) {
            if (coin > amount) continue; 
            ans = min(ans,recurr(coins,amount-coin,dp)) ;
        }
        return (dp[amount] =  ans == INT_MAX ? INT_MAX : 1+ ans);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = recurr(coins,amount,dp);
        return ans == INT_MAX ? -1  : ans;
    }
};