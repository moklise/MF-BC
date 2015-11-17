#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

// input directed graph G = (V, E)
// data
// output betweenness Cb[v] for all v ㅌ V
void MSBetweennessCentrality(int** graph, int SIZE, int opt)
{
	float *Cb;
	Cb = new float[SIZE];
	for(int i = 0 ; i < SIZE ; i++ )
	{
		Cb[i] = 0.0;
	}
	
	for(int s = 0 ; s < SIZE ; s++)
	{
		vector<int> *predecessor;
		predecessor = new vector<int>[SIZE];
		queue<int>  Q;
		stack<int>  S;
		float		dependencyOfSource[SIZE];
		int			dist[SIZE];
		int			numOfShortPaths[SIZE];
		
		for(int i = 0 ; i < SIZE ; i++)
		{
			dist[i] = INT_MAX;
			numOfShortPaths[i] = 0;
			predecessor[i].clear();
		}
		dist[s] = 0;
		numOfShortPaths[s] = 1;
		Q.push(s);
		
		while( !Q.empty() )
		{
			int v = Q.front();
			Q.pop();
			S.push(v);
			
			int w;
			for(int i = 0;  i < SIZE ; i++ )
			{
				if( graph[v][i] > 0 ) //  w = v의 이웃 /* vertex w such that ( v, e) ㅌ E */
				{
					w = i;
					if( dist[w] == INT_MAX ) // path discovery
					{
						dist[w] = dist[v] + 1;
//						dist[w] = dist[v] + graph[v][w];
						Q.push(w);
					}
					if( dist[w] == dist[v] + 1 ) // path counting
//					if( dist[w] == dist[v] + graph[v][w] )
					{
						numOfShortPaths[w] = numOfShortPaths[w] + numOfShortPaths[v];
						predecessor[w].push_back(v);
					}
				}
			}
		}
		
		
		// accumulation
		
		for( int i = 0 ; i < SIZE ; i++ ) dependencyOfSource[i] = 0;
		
		while( !S.empty() )
		{
			int w = S.top();
			S.pop();
			
			
			for( vector<int>::iterator iter = predecessor[w].begin(); iter != predecessor[w].end() ; iter++ )
			{
				int v = *iter;
				dependencyOfSource[v] = dependencyOfSource[v] + ((float)numOfShortPaths[v] / (float)numOfShortPaths[w]) * (1 + dependencyOfSource[w] );
			}
			
			if( w != s) Cb[w] = Cb[w] + dependencyOfSource[w];
		}
		
		delete [] predecessor;			
	}
	
	if(opt % 2 ){
		for(int i = 0 ; i < SIZE ; i++)
			Cb[i] /= 2;
	}
	
	cout << fixed;
	cout.precision( 1 );
	for(int i = 0 ; i < SIZE ; i++)
		cout<< i + 1 << " : " << Cb[i] << endl;;

	delete [] Cb;

}