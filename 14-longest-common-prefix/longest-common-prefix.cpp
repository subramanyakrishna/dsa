class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0,n=strs.size(); 
        string s="";
        if(!strs[0].size() && s=="") return "";
        while(true){
            char c =  '\0';
            for(int j = 0; j < n; j++){
                if(i < strs[j].size()){
                    if(c == '\0') c = strs[j][i];
                    else if(strs[j][i] != c) {
                        return s;
                    }
                }
                else {
                    return s;
                }
            }
            s.push_back(c);
            i++;
        }
        return s;
    }
};