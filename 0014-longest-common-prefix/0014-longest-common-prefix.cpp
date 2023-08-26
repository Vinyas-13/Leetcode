//Time Complexity->O(N*LogN)+O(LCP)
//Space Complexity->O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end()); //sort the vector
        string str1=strs[0]; //1st string
        string str2=strs[strs.size()-1]; //last string
        
        int lcp=0;
        for(int i=0;i<str1.length();i++) //find the common prefix for first and last string
        {
            if(str1[i]==str2[i])lcp++;
            else break;
        }
        
        return (lcp==0?"":str1.substr(0,lcp));
    }
};