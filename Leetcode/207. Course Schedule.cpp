class Solution {
public:
    map<int,vector<int>> adj;
    bool visited[1000000] ;
    bool resStack[1000000];
    bool iscycle = false;
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
        }
        resStack[v] =false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        map<int, vector<int>>::iterator itr;
        for(itr=adj.begin();itr != adj.end();itr++)
        {
            cout<<itr->first<<" "<<endl;
            if(visited[itr->first] == false)
                dfs(itr->first);
            if(iscycle)
                return false;
        }
        return true;
    }
};
