class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        int sp=0, sc = nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            int temp = sp;
            sp = max(sc,sp);
            sc = temp + nums[i];
            
        }
        return max(sp,sc);
        
    }
};