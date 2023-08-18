class Solution {
public:
    int reverse(int x) {
        int ans=0,rem=0;
        while(x!=0)
        {
            if(ans>INT32_MAX/10 || ans<INT32_MIN/10)
            return 0;

           rem=x%10;
           ans=ans*10+rem;
           x=x/10; 
        }

        return ans;
    }
};