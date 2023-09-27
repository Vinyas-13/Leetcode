class Solution {
public:
    bool isPossible(vector<int> &position,int m,int mid)
    {
        int noOfBalls=1;
        int lastBall=position[0];
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-lastBall>=mid)
            {
            noOfBalls++;
            lastBall=position[i];
            }
        }
        if(noOfBalls>=m)return true;
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low=1;
        int high=position.back()-position[0];//max distnace

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(position,m,mid))
            {
                low=mid+1;//check for greater distance
            }
            else high=mid-1;
        }  
        return high;//high ends in opposite polarity
        }   
};