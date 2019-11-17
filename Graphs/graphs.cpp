//============================================================================
// Name        : graphs.cpp
// Author      : Paluri Sai Krishna
// Version     :
// Copyright   : Your copyright notice
// Description : Graphs Problem
//============================================================================

#include "graph_proc.h"
int main()
{
	Graph g(6);

    g.addEdge(0,5);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.addEdge(0,1);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(0,2);

    //g.BFSTraversal(0);
    g.DFSTraversal(0);
    //g.BFS(0);
    //cout<<endl;
    //g.DFS(0);
    cout<< (g.getisCycle()?"true":"false");
    return 0;
}
