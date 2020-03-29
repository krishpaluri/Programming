// Below solution is leading to Time Limit exceeded need to optimize
// Cases failing 2 out of 315

class Solution {
public:

    static bool cmp1(vector<int> a,vector<int> b)
    {
        return a[0] == b[0] && a[1] == b[1];
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > ans;

        unordered_map<int, vector< pair<int,int> > > umap;

        unordered_map< int, pair<int,int>> tri;

        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
            {
                umap[nums[i] + nums[j]].push_back(make_pair(i,j));
            }

        for(int i=0;i<nums.size();i++)
        {
            if(umap.find(nums[i]*-1) != umap.end())
            {
                for (auto const &x : umap[nums[i] * -1])
                {
                    vector<int> temp;
                    if(x.first <= i)
                        continue;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[x.first]);
                    temp.push_back(nums[x.second]);
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
            }
        }
      sort(ans.begin(),ans.end());

       auto last = std::unique(ans.begin(),ans.end(),cmp1);
       ans.erase(last, ans.end());
        return ans;
    }
};
