class Solution {
public:
    int countCoprimehelper(vector<vector<int>>& mat, int idx , int gcd,vector<vector<int>>& dp){
        if(mat.size()==idx) {
            if(gcd==1) return 1;
            else return 0;
        }
        const unsigned int M = 1000000007;
        if (dp[idx][gcd]!=-1) return dp[idx][gcd];
        int n = mat[idx].size();
        int res = 0;
        for(int i = 0 ; i <n;i++) {
            int newgcd = std::gcd(gcd,mat[idx][i]);
            res = (res + countCoprimehelper(mat, idx+1,newgcd,dp))%M;
        }
        return dp[idx][gcd] = res;
    }
    int countCoprime(vector<vector<int>>& mat) {
        vector<vector<int>> dp(151, vector<int>(151,-1));
        return countCoprimehelper(mat, 0 , 0,dp);
    }
};


        

