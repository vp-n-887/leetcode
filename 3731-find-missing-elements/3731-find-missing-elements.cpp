#include<vector>
#include<climits>
class Solution {
public:
   vector<int> v;

    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int min=nums[0];
        int max=nums[nums.size()-1];

       for(int x=min+1;x<max;x++)
       {
        if(!binary_search(nums.begin(),nums.end(),x)){v.push_back(x);}
       }
        return v;
        
    }
};