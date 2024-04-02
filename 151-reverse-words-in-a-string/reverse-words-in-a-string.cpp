class Solution {
public:
    string reverseWords(string s) {
        stringstream  ss(s);
        vector<string> v;
        string word;
        while(ss >> word){
            v.push_back(word);
        }
        string ans="";
        reverse(v.begin(), v.end());
        if(v.size()){
            ans = accumulate(v.begin(),v.end(),
            string{},
            [](string lhs , string rhs){
                return lhs + rhs + " ";
            });
        }
        if(!ans.empty()) ans.pop_back();
        return ans;
    }   
};