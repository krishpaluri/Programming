/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {

        // Basic idea is to buld graph and do bfs with beginword as root
        // As BFS is used for shortest distance between two nodes in unweighted graph
        // Add behinword to list
        wordlist.push_back(beginWord);

        //declare graph
        unordered_map<string,vector<string>> graph;

        int len = wordlist.size(), wlen = beginWord.length();


        unordered_map<string,int> level,visited;

        //Build Graph
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                int k=0,cnt=0;
                while(k<wlen)
                {
                    if(wordlist[i][k] == wordlist[j][k])
                    {
                        cnt++;
                    }
                    k++;
                }
                // If words differ by one char add a edge
                if(cnt == wlen-1)
                {
                    //add to grpah
                    // Not a digraph
                    graph[wordlist[i]].push_back(wordlist[j]);
                    graph[wordlist[j]].push_back(wordlist[i]);
                }

            }
            visited[wordlist[i]]  = 0;
        }

        // Simple Breadth First Search

        queue<string> bfs;
        visited[beginWord] = 1;
        bfs.push(beginWord);
        level[beginWord] = 1;
        while(!bfs.empty())
        {
            string s = bfs.front();
            bfs.pop();

            if(s.compare(endWord) == 0)
                return level[s];
            for(int i=0;i<graph[s].size();i++)
            {
                if(visited[graph[s][i]] == 0)
                {
                    bfs.push(graph[s][i]);
                    visited[graph[s][i]] = 1;
                    cout<<graph[s][i]<<" ";
                    level[graph[s][i]] = level[s] +1;
                }

            }

        }

        return 0;



        }
};
