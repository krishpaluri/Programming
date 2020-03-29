
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i=0,j=0;
        unordered_map<char,int> umap;
        if(s.size() == 0)
            return 0;
        int maxlen = 0,len=0;
        while(i<s.size() && j < s.size())
        {
            if(umap.find(s[j]) == umap.end())
            {
                umap[s[j]] = j;
            }
            else
            {
                int temp = umap[s[j]];
                umap[s[j]] = j;
                if(temp >= i)
                {
                   i = temp+1;
                   j++;
                    continue;
                }
            }

            j++;
            maxlen = maxlen > (j-i) ? maxlen : (j-i);

        }
        return maxlen;

    }
};
