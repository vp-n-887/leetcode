class Solution {
public:

    bool ispresent(int x,vector<int>& nums){
        for(int i:nums){if(x==i)return true;}
        return false;}
    
    int missingInteger(vector<int>& nums) {

        int sum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
             if(nums[i]==nums[i-1]+1)
             {sum=sum+nums[i];}
             else
             {break;}
        }

        
        while(ispresent(sum,nums))
        {
            sum++;
        }

        return sum;

    }
    
};