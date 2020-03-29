class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        if(nums.size() <= 1)
            return nums.size();
        for(int i=1;i<nums.size();i++)
        {
            if(nums[j] == nums[i])
            {
                continue;
            }
            nums[++j] = nums[i];

        }
        return j+1;
    }
};
