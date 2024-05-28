class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int i = 0 , j = 0, n = s.size() , currCost = 0 ,maxLength = 0;
        while(j<n){
            currCost += abs(s[j]-t[j]);
            while(currCost>maxCost && i < n) {
                currCost -= abs(s[i]-t[i]);
                i++;
            }
            j++;
            maxLength = max(maxLength, j - i);
            
        }
        return maxLength;
    }
};
 