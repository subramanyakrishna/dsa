class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        int i = 0 , j = n;
        while(i<=j) {
            long sqr = (long)i*i + (long) j*j;
            if(sqr==c) return true;
            else if(sqr > c) j--;
            else i++; 
        } 
        return false;
    }
};