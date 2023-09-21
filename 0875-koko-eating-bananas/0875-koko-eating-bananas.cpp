class Solution {
public:
    int maximum(vector<int>& piles)
    {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }
    
    long long totalHours(vector<int>& piles, int mid)
    {
        long long totalHrs=0;
        
        for(int i=0;i<piles.size();i++)
        {
            totalHrs+=ceil((double)(piles[i])/(double)(mid)); //calculates the ceil value of time required to eat bananas
        }
        return totalHrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maximum(piles);
        
        while(low<=high)
        {
            long long mid=(low+high)/2;
            long long totalHrs=totalHours(piles,mid);
            
            if(totalHrs<=h)// if totalHrs is less then required 
            {
                high=mid-1; //then to increase the hrs -> decrease the number of bananas/hrs 
            }
            else low=mid+1; 
        }
        
        return low;
    
    }
};