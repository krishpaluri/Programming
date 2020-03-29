class Solution {
public:
    int trap(vector<int>& height) {

        int len = height.size();
        if(len == 0)
            return 0;
        int LM[len], RM[len];
        int max,ans=0;
        LM[0] = -1;
        max=height[0];
        for(int i=1;i< len;i++)
        {
            LM[i] = max;
            if(max < height[i])
            {
                max = height[i];
            }
        }

        max = height[len-1];
        RM[len-1] = -1;
        for(int i=len-2;i>=0;i--)
        {
            RM[i] = max;
            if(max < height[i])
            {
                max = height[i];
            }
        }

        for(int i=0;i<len;i++)
        {
            if(RM[i] > height[i] && LM[i] > height[i])
            {
                ans += min(LM[i],RM[i]) -height[i];
            }
        }
        return ans;
    }
};
