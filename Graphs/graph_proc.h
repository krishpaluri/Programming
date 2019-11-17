#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
private:
	vector< vector<int> > AdjList;
	int edges;
	int vertices;
	bool isCycle;
public:
	int getedges()
	{
		return this->edges;
	}

	int getVertices()
	{
		return this->vertices;
	}

	bool getisCycle()
	{
		return this->isCycle;
	}
	Graph(int vertices)
    {
		this->isCycle  = false;
		vector<int> temp;
		this->vertices = vertices;
		this->edges = 0;
		for(int i=0;i<=vertices;i++)
		{
			this->AdjList.push_back(temp);
		}
    }

	void addEdge(int a,int b)
	{
		//Undirected Graph
		AdjList[a].push_back(b);
		AdjList[b].push_back(a);
		this->edges++;
	}

	void BFSTraversal(int vertice);
	void DFSTraversal(int vertice);
};



void Graph::BFSTraversal(int vertice)
{
	queue<int> Que;
	Que.push(vertice);
	int visited[this->vertices + 1] = {0};
	visited[vertice] = 1;
	while(!Que.empty())
	{
		int top_ele = Que.front();
		Que.pop();
		cout<<top_ele<<" ";
		for(int i=0;i<this->AdjList[top_ele].size();i++)
		{
			if(visited[this->AdjList[top_ele][i]] == 0)
			{
				Que.push(this->AdjList[top_ele][i]);
				visited[this->AdjList[top_ele][i]] =1;
			}
		}
	}

}

void Graph::DFSTraversal(int vertice)
{
	stack<int> st;
	st.push(vertice);
	int visited[this->vertices + 1] = {0};
	visited[vertice] = 1;
	int from_edge = -1;
	while(!st.empty())
	{
		int top_ele = st.top();
		st.pop();
		cout<<top_ele<<" ";

		for(int i=this->AdjList[top_ele].size()-1;i>=0;i--)
		{
			if(visited[this->AdjList[top_ele][i]] == 0)
			{
				st.push(this->AdjList[top_ele][i]);
				visited[this->AdjList[top_ele][i]] =1;
			}
			else if(this->AdjList[top_ele][i] != from_edge)
			{
				this->isCycle = true;
			}

		}
		from_edge = top_ele;
	}

}
