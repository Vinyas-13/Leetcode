class Solution {
public:
    bool minDaysReq(vector<int>& bloomDay,int m,int k,long mid)
    {
        int adjCount=0;
        long noOfBouquet=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid) //if blooming is possible increase cnt
            {
                adjCount++;
            }
            else //for anyelement blooming not possible 
            {
                noOfBouquet+=(adjCount/k); //count no of bouquet possible
                adjCount=0; //reset cnt to 0
            }
        }
        noOfBouquet+=(adjCount/k); // coz last consecutive might have missed
        
        if(noOfBouquet>=m)return true;
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(long(m)*long(k)>bloomDay.size())return -1;
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        for(int i=0;i<bloomDay.size();i++)
        {
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        
        int low=mini; 
        int high=maxi; 
        
        while(low<=high)
        {
            long mid=(low+high)/2; 
            if(minDaysReq(bloomDay,m,k,mid)) //if possible,eliminate right half
            {
                high=mid-1;
            }
            else low=mid+1;  //else eliminate left half
        }
        return low;
    }
};