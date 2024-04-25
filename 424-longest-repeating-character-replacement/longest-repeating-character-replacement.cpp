class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 , r = 0, maxLen = INT_MIN , maxFreq = INT_MIN, n = s.size();
        int mp[26] = {0};
        while(r<n){
            mp[s[r]-'A']++;
            maxFreq = max(mp[s[r]-'A'] ,maxFreq );
            if( (r-l+1) - maxFreq> k) {
                mp[s[l]-'A']--;
                l++;
            }
            maxLen = max(maxLen,(r-l+1) );
            r++; 
        }
        return maxLen;
    }
};