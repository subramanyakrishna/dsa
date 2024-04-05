class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string , int> RtoI;
        RtoI = {{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},
                {"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
        int  n = s.size();
        int i = n-1,ans = 0;
        while(i>0){
            int num = RtoI[s.substr(i-1,2)]; 
            ans+= num;
            if(num) { i = i-2; continue;} 
            ans+= RtoI[s.substr(i,1)];
            i--;
        }
        if(i==0) ans+= RtoI[s.substr(i,1)];
        return ans;
    }
};
 
