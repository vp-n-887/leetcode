class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int s=nums.size();
        sort(nums.begin(),nums.end());

        int median;
        if((s%2)!=0){median=nums[s/2];}
        else{median=(nums[s/2]+nums[s/2-1])/2;}

        int move=0;

        for(int i=0;i<s;i++)
        {
            int r=nums[i]-median;
            if(r<0){r=-r;}
            move=move+r;
        }
        return move;
    }
};