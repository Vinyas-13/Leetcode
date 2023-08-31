//Time Complexity: O(N*log(log(n)))
//Space Complexity: O(N)
class Solution {
public:
    int countPrimes(int n) {
    vector<int>seive(n+1,1);// vector to mark if number is prime or not
    int prime=0;
    for(int i=2;i<=sqrt(n);i++) // check from 2 to sqrt(n)
    {
        if(!seive[i])continue; //if marked 0,continue
        for(int j=i*i;j<n;j=j+i) //mark all multiple of i starting from i*i as 0
        {
            seive[j]=0;
        }
    }
        
    for(int i=2;i<n;i++)//count number of set values
    {
        if(seive[i])prime++;
    }
    return prime;   
    }
};