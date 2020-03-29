class Solution {
public:
        map<int,vector<int>> adj;
    bool visited[1000000] ;
    bool resStack[1000000];
    bool iscycle = false;
    vector<int> ans;
    void dfs(int v)
    {
        if(iscycle)
            return;
        if(visited[v] == false)
        {
            visited[v] =true;
            resStack[v] =true;

            if(adj.find(v) != adj.end())
            for(int i=0;i<adj[v].size();i++)
            {
                if(resStack[adj[v][i]] == true)
                {
                    iscycle = true;
                    return;
                }
                dfs(adj[v][i]);
            }
            ans.push_back(v);
        }
        resStack[v] =false;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //visited = new bool(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            vector<int> temp;
            visited[i] = false;
            resStack[i] = false;
        }

        // prepare adj matrix
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i] == false)
                dfs(i);
            if(iscycle)
            {
                ans.clear();
                return ans;
            }
        }
        return ans;
    }

};
