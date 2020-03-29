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

        if(grid[i][j] == 'X')
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

    void solve(vector<vector<char>>& grid) {

        vector<vector<int>> visited;

        if(grid.size() ==0)
            return ;
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

        //rotate around border
        // top border
        for(int i=0;i<n;i++)
        {
            if(grid[0][i] == 'O' and visited[0][i] == 0)
            dfs(visited,grid,0,i);
        }

        // right border
        for(int i=1;i<m;i++)
        {
            if(grid[i][n-1] == 'O' and visited[i][n-1] == 0)
            dfs(visited,grid,i,n-1);
        }

        //bottom border
        for(int i=0;i<n-1;i++)
        {
            if(grid[m-1][i] == 'O' and visited[m-1][i] == 0)
            dfs(visited,grid,m-1,i);
        }
        // left border
        for(int i=1;i<m-1;i++)
        {
            if(grid[i][0] == 'O' and visited[i][0] == 0)
            dfs(visited,grid,i,0);
        }

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i != m-1 && i != 0 && j!=0 && j != n-1 && visited[i][j] == 0)
                {
                    grid[i][j] = 'X';
                }

            }
        }
        return;
    }
};
