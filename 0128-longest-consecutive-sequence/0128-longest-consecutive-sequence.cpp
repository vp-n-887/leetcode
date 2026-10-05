class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

         unordered_set<int> s;

       for(int x: nums)
       {
        s.insert(x);
       } 
       
         int longest=0;

       for(int num:s)
       {
        if(s.find(num-1)==s.end())
        {
            int x=num;
            int count=1;
            while(s.find(x+1)!=s.end())
            {
                count++;
                x++;
            }

            longest=max(count,longest);
        }
       }

       return longest;
    }
};