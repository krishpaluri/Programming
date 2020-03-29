class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int anag[strs.size()] = {0};

        vector<string> str_sorted = strs;

        for(int i=0;i<str_sorted.size();i++)
        {
            sort(str_sorted[i].begin(),str_sorted[i].end());

        }
        for(int i=0;i<strs.size();i++)
        {
            if(anag[i] == 1)
                 continue;
            vector<string> ans1;
            ans1.push_back(strs[i]);
            for(int j=i+1;j<strs.size();j++)
            {
                if(anag[j] == 1)
                    continue;
                if(str_sorted[i] == str_sorted[j])
                {
                    anag[j] = 1;
                    anag[i] = 1;
                    ans1.push_back(strs[j]);
                }
            }
            ans.push_back(ans1);

        }
        return ans;

    }
};
