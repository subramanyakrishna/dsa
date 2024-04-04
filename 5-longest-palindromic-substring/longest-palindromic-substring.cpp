class Solution {
public:
    void  getPalindrome(const string &s,int l,int r,string &ans){
        int n = s.size();
        while(l > -1 && r < n && s[l] == s[r]){
            l--;
            r++;
        }

        if(r-l-1> ans.size()) ans = s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        int i = 0 , max = 0, n = s.size();
        string ans="";
        for(int i = 0; i < n;i++){
            getPalindrome(s,i,i,ans);
            getPalindrome(s,i,i+1,ans);
        }
        return ans;       
    }

};

