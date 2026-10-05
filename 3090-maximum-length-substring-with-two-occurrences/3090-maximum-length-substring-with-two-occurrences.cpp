#include<climits>
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
      
        int len=0;
        int freq[26]={0};//array to storr the frequncy of each letters

       for(int right=0;right<s.size();right++)
       {
            freq[s[right]-'a']++;

            while(freq[s[right]-'a']>2)
            {
                freq[s[left]-'a']--;
                left++;
            }

           // int curr_len=right-left+1;
            len=max(len,right-left+1);
       }

       return len;
    }
};