class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,bool> mp;
        for(auto &num : nums){
            if(mp.find(num) != mp.end() && !mp[num]){
                ans.push_back(num);
                mp[num] = true;
                
            }else{
                mp[num] = false;
            }
        }
        return ans;
    }
};