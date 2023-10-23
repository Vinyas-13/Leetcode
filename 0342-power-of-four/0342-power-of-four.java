class Solution {
    public boolean isPowerOfFour(int n) {
       if((n&(n-1))==0 && (n-1)%3==0)return true; // eg.16 can be written as power of 2, also 15%3==0
       return false; 
    }
}