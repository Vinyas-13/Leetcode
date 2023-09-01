//Time complexity – O(N)
//Auxiliary Space – O(1)
class Solution {
public:
    int romanToInt(string s) {
       map<char,int> roman;
       roman['I']=1;
       roman['V']=5;
       roman['X']=10;
       roman['L']=50;
       roman['C']=100;
       roman['D']=500;
       roman['M']=1000;
       
       int intAns=0;
       for(int i=0;i<s.length();i++)
       {
           if(roman[s[i]]<roman[s[i+1]])//If present_value < next_value...eg IV => 5-1 => 4
           {
               intAns+=roman[s[i+1]]-roman[s[i]];
               i++;
               continue;
           }
           intAns+=roman[s[i]];
       }
       return intAns;
    }
};