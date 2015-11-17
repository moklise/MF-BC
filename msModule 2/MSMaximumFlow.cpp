//
//  MSMaximumFlow.cpp
//  msModule
//
//  Created by 박민석 on 2015. 11. 2..
//  Copyright © 2015년 박민석. All rights reserved.
//

#include <iostream>
#include <climits>
#include <queue>

using namespace std;

#define V 6

//BFS

bool BFS(int** rGraph, int s, int t, int parent[], int SIZE)
{
	bool visited[SIZE];
	memset(visited, 0, sizeof(visited));
	
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		
		for(int v = 0 ; v < SIZE ; v++)
		{
			if(visited[v] == false && rGraph[u][v] > 0)
			{
				q.push(v);
				visited[v] = true;
				parent[v] = u;
			}
		}
		
	}
	
	return (visited[t] == true);
}

//FORDFULKERSON

int MSMaximumFlow(int **Graph, int s, int t, int SIZE, int opt)
{
	int u, v;
	int** rGraph;
	
	rGraph = new int*[SIZE];
	
	for(int i = 0 ; i < SIZE; i++)
		rGraph[i] = new int[SIZE];
	
	for(u = 0 ; u < SIZE; u++ )
		for( v = 0 ; v < SIZE ; v++ )
			rGraph[u][v] = Graph[u][v];
	
	int parent[SIZE];
	int MAX_FLOW = 0;
	
	while(BFS(rGraph, s, t, parent, SIZE))
	{
		int Path_Flow = INT_MAX;
		
		for( v=t;v!=s;v=parent[v])
		{
			u = parent[v];
			Path_Flow = min(Path_Flow, rGraph[u][v]);
		}
		
		for( v=t; v!=s; v=parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= Path_Flow;
			rGraph[v][u] += Path_Flow;
		}
		MAX_FLOW += Path_Flow;
	}
	
	cout << endl;

	/* 각 엣지 상태 출력 부 */
	
	bool** Arr = new bool* [SIZE];
	
	for(int i = 0 ; i < SIZE ; i++) Arr[i] = new bool [SIZE];
	
	for(int i = 0 ; i < SIZE ; i++ )
	{
		for(int j = 0 ; j < SIZE ; j++ )
		{
			if( ( rGraph[i][j] || rGraph[j][i] ) && (!Arr[i][j] && !Arr[j][i]) )
			{
				cout << i << "-" << j << " : " << rGraph[i][j] << " / " \
				<< rGraph[j][i] + rGraph[i][j] << endl;
				Arr[i][j] = true;
				Arr[j][i] = true;
				
			}
		}
	}
	
	cout << "Maximum Flow : ";
	
	return MAX_FLOW;
}

//int main(void)
//{
////	int graph[V][V] = {
////		{0, 16, 13, 0, 0, 0,},
////		{0, 0, 10, 12, 0, 0},
////		{0, 4, 0, 0, 14, 0},
////		{0, 0, 9, 0, 0, 20},
////		{0, 0, 0, 7, 0, 4},
////		{0, 0, 0, 0, 0, 0}
////	};
//	
////	cout << "The Maximum possible flow is " << MSMaximumFlow(graph, 0, 5) << endl;
//}
//
