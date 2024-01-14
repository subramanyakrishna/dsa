

int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int i = 0, j = i+1;
        while(j<nums.size()){
            if(nums[i] != nums[j]) nums[++i] = nums[j];
            j++;
        }
        return i+1;
    }