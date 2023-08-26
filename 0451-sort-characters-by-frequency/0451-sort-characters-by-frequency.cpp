//TC-> 122 log(122) +O(n)
//SC-> O(123)

class Solution {
public:
    string frequencySort(string s) {
      vector<pair<int,char>>hash('z'+1);//hash vector to store <count,char>
      for(auto ch: s) //for every char in s,increment the count of char in hash
      {
          hash[ch]={hash[ch].first+1,ch};
      }

      sort(hash.begin(),hash.end()); //sort the vector on basis of count 
      string result="";

      for(auto it:hash)
      {
          result=string(it.first,it.second)+result; //constructor in string class-> string(int count,char ch) 
      }

      return result;

    }
};