class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    int coin5 = 0, coin10 = 0;
        for (int bill : bills) 
        {
            if (bill == 5) coin5++;
            else if (bill == 10) 
            {
                if (coin5 == 0) 
                {
                    return false;
                }
                coin5--;
                coin10++;
            } 
            else 
            {
                if (coin10 > 0 && coin5 > 0) 
                {
                    coin10--;
                    coin5--;
                } 
                else if (coin5 >= 3) 
                {
                    coin5 -= 3;
                } 
                else return false;
            }
        }
        return true;
    }
};