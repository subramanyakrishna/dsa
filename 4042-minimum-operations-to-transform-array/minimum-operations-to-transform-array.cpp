class Solution {
public:
    
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        long long  op = 0;
        int i = 0 ;
        int lastVal =  nums2.back(), last = INT_MAX;
        while(i<nums1.size()) {
            op += std::abs(nums1[i] - nums2[i]);
            if ((nums1[i] <= lastVal && lastVal <= nums2[i] ) ||
                (nums2[i] <= lastVal && lastVal <= nums1[i] )) {
                last = 0;
            } else {
                last = min(last, min(std::abs(nums1[i] -lastVal), std::abs(nums2[i] - lastVal)));
            }
            i++;
        }
        return op+last+1;
    }
};