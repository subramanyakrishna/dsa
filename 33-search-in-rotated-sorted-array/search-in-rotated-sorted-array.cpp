class Solution {
public:
    int search(vector<int>& nums, int target) {
        // we are doign binary search because  this is sorted array and there is searching involved.
        // we take the array and use two pointers low=0 and high = n-1
        // we keep on finding mid 
        // since we are using the binary search we devide the array into two everytime 
        int  n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target ) return mid;
            // then first motive is to find the side which is sorted.
            // why ? becuase we can check whether out element is present or not only in the sorted side. 
            //check whether right side is sorted
            if( nums[mid] <=  nums[high] ){
                //if right is sorted check whether sorted contains the target 
                if(  nums[mid] <= target && target <= nums[high]){
                    //if yes move the low to mid+1 
                    low = mid+1;
                }
                else {
                    high =  mid-1;
                }
            }else{
                if(  nums[low] <= target && target <= nums[mid]){
                    //if yes move the low to mid+1 
                    high =  mid-1;
                    
                }
                else {
                    low = mid+1;
                }
            }

        }
        return -1;
    }
};


