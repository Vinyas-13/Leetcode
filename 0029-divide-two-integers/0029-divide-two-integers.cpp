//Time Complexity: O(log (dividend))
//Space Complexity: O(1)
//Intuition: We are trying to make divisor <=dividend here
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==INT_MIN && divisor==-1) 
            return INT_MAX;
        
        if (dividend==INT_MIN && divisor==1)
            return INT_MIN;  
        
        int sign=1;
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0))sign=-1;
        
        long dup_dividend=labs(dividend);
        long dup_divisor=labs(divisor);
        int quotient=0;

        for(int i=31;i>=0;i--) //start from MSB of divisor
        {
            long temp=dup_divisor<<(long)i;//eg 8<<31 == 8*(2^31)
            if(temp<=dup_dividend) //if temp is less then dividend 
            {
                dup_dividend-=temp;//subtract temp from dividend
                quotient+=1<<i; //store quotient=1*(2^i)
            }
            
        }
        quotient=sign*quotient;
        return quotient;
        
    }
};