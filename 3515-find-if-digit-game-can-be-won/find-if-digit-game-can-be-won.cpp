class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sing = 0 , doub = 0;
        for(auto n : nums){
            if(n<10) sing+=n;
            else doub+= n;
        }
        return sing!=doub;
    }
};