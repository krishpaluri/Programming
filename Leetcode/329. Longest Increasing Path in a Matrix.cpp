class Solution {
public:
    vector<vector<int>> dp;
    int maxlen = 0;
    int M,N;
    bool safe(int i,int j)
    {
        if(i<0 || i>M-1 || j<0 || j>N-1)
        {
            return false;
        }
        return true;
    }
    int dfs(vector<vector<int>>& matrix, int i,int j,int pre)
    {
        if(pre >= matrix[i][j])
        {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int r1=0,l1=0,t1=0,b1=0;
        if(safe(i+1,j))
        {
            r1 = dfs(matrix,i+1,j,matrix[i][j]);
        }
        if(safe(i-1,j))
        {
            l1 = dfs(matrix,i-1,j,matrix[i][j]);
        }
        if(safe(i,j-1))
        {
            t1 = dfs(matrix,i,j-1,matrix[i][j]);
        }
        if(safe(i,j+1))
        {
            b1 = dfs(matrix,i,j+1,matrix[i][j]);
        }
        int locmax = max(r1,max(l1,max(t1,b1))) +1;
        if(maxlen < locmax)
        {
            maxlen = locmax;
        }
        dp[i][j] = locmax;
        return locmax;
    }
    void resetdp()
    {
        for(int i=0;i<=M;i++)
        {
            vector<int> temp;
            for(int j=0;j<=N;j++)
            {
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        M = matrix.size();

        if(M == 0)
            return 0;
        N = matrix[0].size();
        resetdp();
        int m;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                m = dfs(matrix,i,j,INT_MIN);
            }
        }

        return maxlen;
    }
};
