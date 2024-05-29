class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while(s.size()!=1){
            int n = s.size();
            if(s[n-1] == '0') s.pop_back();
            else{
                int j = n-1;
                while(j >= 0 && s[j]=='1'){
                    s[j] = '0';
                    j--;
                }
                if(j < 0 ) s.insert(0 ,1,'1');
                else s[j] = '1';
            }
            count++;
        }
        return count;     
    }   
};

 


