class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0,ns = s.size() , j = 0,tn = t.size();
        while(j < tn ){
            while(i<ns && s[i] != t[j]) i++;
            if(i == ns){
                return tn-j;
            }
            i++;
            j++;
        }
        return 0;  

    }
};