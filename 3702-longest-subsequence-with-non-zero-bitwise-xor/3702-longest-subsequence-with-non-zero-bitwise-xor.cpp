class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        bool nozero=false;

        for(int i:nums)
        {
            x=x^i;

            if(i!=0){nozero=true;}
        }

        if (x != 0) {
            return nums.size();
        }

        if (nozero) {
            return nums.size() - 1;
        }

        return 0;
    }
};