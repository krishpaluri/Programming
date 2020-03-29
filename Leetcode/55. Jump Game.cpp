class Solution {
public:
    vector<int> dp;
    int len;
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)
            return true;
        for(int i=0;i<nums.size();i++)
            dp.push_back(-1);
        len = nums.size();

       for(int i=len-2;i>=0;i--)
       {
           int val = min(i + nums[i], len- 1) ;
           for(int j=i+1;j<=val;j++)
           {
                   if(j == len-1 || dp[j] == 1)
                   {

                       dp[i] = 1;
                       break;
                   }
           }
       }
        return dp[0]==1;

    }
};
