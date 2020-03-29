class Solution {
public:
    int m,n;
    bool safe(int i,int j)
    {
        if(i<0 || j>=n || i>=m || j<0)
        {
            return false;
        }
        return true;
    }
    void dfs(vector<vector<int>> &visited,vector<vector<char>>& grid,int i,int j)
    {

        if(visited[i][j] == 1)
        {
            return;
        }

        if(grid[i][j] == '0')
            return;
        visited[i][j] = 1;
        if(safe(i-1,j) && visited[i-1][j] == 0)
           dfs(visited,grid,i-1,j) ;
        if(safe(i,j+1) && visited[i][j+1] == 0)
            dfs(visited,grid,i,j+1) ;
        if(safe(i+1,j) && visited[i+1][j] == 0)
            dfs(visited,grid,i+1,j) ;
        if(safe(i,j-1) && visited[i][j-1] == 0)
            dfs(visited,grid,i,j-1);

    }

    int numIslands(vector<vector<char>>& grid) {

        vector<vector<int>> visited;

        if(grid.size() ==0)
            return 0;
        for(int i=0;i<grid.size();i++)
        {
            vector<int> temp;
            for(int j=0;j<grid[0].size();j++)
            {
                temp.push_back(0);
            }
            visited.push_back(temp);
        }
        m = grid.size();
        n =grid[0].size();
        int islands =0;
        // connected components
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '1' and visited[i][j] == 0)
                {
                    dfs(visited,grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
