class Solution {
public:
    bool winnerOfGame(string colors) {
        long long n=colors.length();
        long long a=0; //no of A which can be removed
        long long b=0; //no of B which can be removed
        
        for(long long i=0;i<n;i++)
        {
            char ch=colors[i]; //get the curr char
            long long j=i+1; //set j equal to next char
            while(j<n && colors[j]==ch)j++; //keep incrementing j untill we get new char
            j--;// decrease j by 1 to get range of consecutive same char
            
            if(ch=='A') a+=max(0ll,j-i-1ll); //calculate how many A or B can be removed from consecutive seq
            if(ch=='B') b+=max(0ll,j-i-1ll);
            
            i=j; //move to next char            
        }
        
        return a>b;  
    }
};