/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int low=1;
        int high=mountainArr.length()-2;
        int peakInd=-1;
        int mid=-1;
        
        //find the peak element
        while(low<=high)
        {
            mid=(low+high)/2;
            int ele=mountainArr.get(mid);
            int ele_left=mountainArr.get(mid-1);
            int ele_right=mountainArr.get(mid+1);
            if(ele>=ele_left && ele<=ele_right) low=mid+1;
            else if(ele<ele_left && ele>ele_right) high=mid-1;
            else {peakInd=mid;break;}
        }
        
        //find in left half
        low=0;
        high=peakInd;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            int ele=mountainArr.get(mid);
            if(ele<target)low=mid+1;
            else if(ele>target)high=mid-1;
            else return mid ;
        }
        
        //find in right half
        low=peakInd+1;
        high=mountainArr.length()-1;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            int ele=mountainArr.get(mid);
            if(ele<target)high=mid-1;
            else if(ele>target)low=mid+1;
            else return mid ;
        }
        
        return-1;//if element doen't exists
    }
};