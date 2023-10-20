//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sumOfNum(int num)
    {
        int rem=0;
        int ans=0;
        while(num>0)
        {
            rem=num%10;
            ans=ans*10+rem;
            num=num/10;
        }
        
        return ans;
    }
    
    int isPossible(int N, int arr[]) {
        long long diviBy3=0;
        for(int i=0;i<N;i++)
        {
            diviBy3+=sumOfNum(arr[i]);
        }
        
        return diviBy3%3==0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends