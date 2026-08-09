class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int s5 = 0,s10=0,s20=0;
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                s5++;
            }
             else if (bills[i] == 10) {
                if (s5 >= 1) {
                    s10++;
                    s5--;
                } else {
                    return false;
                    // break;
                }
            } 
            else if (bills[i] == 20) {
                if(s5>=1 && s10>=1)  {
                    s5--;
                    s10--;
                    s20++;
                }
                else if(s5>=3) {
                    s20++;
                    s5-=3;    
                }
                else return false;
            }
        }
        return true;
    }
};