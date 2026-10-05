#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       unordered_map<int,int> mp; 

       for(int i=0;i<nums.size();i++)
       {
        int complement=target-nums[i];

        if(mp.find(complement)!=mp.end())
        {
            return {mp[complement],i};
        }

        mp[nums[i]]=i;
       }

        return {};
       









       /*vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
        for(int j=i+1;j<nums.size();j++)
        {if(nums[i]+nums[j]==target) {res.push_back(i);res.push_back(j);return res;}
        }
        }
    return res;*/
    }   
};