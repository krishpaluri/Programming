class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;
        int maxsum = nums[0];
        int maxSumpre = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if((maxSumpre + nums[i]) < nums[i] )
            {
                maxSumpre = nums[i];
            }
            else
                maxSumpre = (maxSumpre + nums[i]);
            if(maxsum < maxSumpre)
                maxsum = maxSumpre;
        }
        return maxsum;
    }
};
