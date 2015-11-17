//
//  mapAdvanced.cpp
//  Algorithm
//
//  Created by 박민석 on 2015. 11. 3..
//  Copyright © 2015년 박민석. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


//int** MSInputToMatrix(int opt)
pair<int**, int> MSInputToMatrix(int opt)
{
	
	map<int, vector<int>> adjacentMap;
	map<pair<int, int>, int> weightMap;
	int **Matrix;
	int size = 0;
	int inputA = 0, inputB = 0;
	int inputC = 0; // Weight
	
	/* map 으로 입력 받는 곳 */
	
	while( 1 )
	{
		cout<< "Type (A, B) :";
		cin >> inputA
		>> inputB;
		
		if(inputA == -1 || inputB == -1) break;
		else
		{
			if(opt > 2)
			{
				cin >> inputC;
			}
			
			size = max(size, max( inputA, inputB));
			
			if(adjacentMap[inputA].end() == \
			   find(adjacentMap[inputA].begin(), adjacentMap[inputA].end(), inputB))
			{
				adjacentMap[inputA].push_back(inputB);
			
				if( opt > 1 )
				{
					weightMap[pair<int, int>(inputA, inputB)] = inputC;
					if( opt % 2 ) weightMap[pair<int, int>(inputB, inputA)] = inputC;
				}
				
				if (opt % 2){
					adjacentMap[inputB].push_back(inputA);
				}
			}
			
		}
	}
	
	
	cout << "adjacentMap's Size is " << size << endl;
	
	/* map 의 Adjacent List 나타내 주는 곳 */
	
	map<int, vector<int>>::iterator iter;
	
	for( iter = adjacentMap.begin() ; iter != adjacentMap.end() ; iter++ )
	{
		cout << iter->first << " | ";
		for(int i = 0 ; i < iter->second.size() ; i++ )
		{
			cout << iter->second[i] << " ";
		}
		cout << endl;
		
	}
	
	/* map 의 Adjacent List To Matrix 하는 곳*/
	/* Matrix  */
	
	Matrix = new int*[size];
	
	for( int i = 0 ; i < size ; i++ )
	{
		Matrix[i] = new int[size];
		memset(Matrix[i],0,sizeof(sizeof(int)*size));
	}
	
	// 숫자로 대입
	
	
	for(map<int, vector<int>>::iterator iter = adjacentMap.begin() ; iter != adjacentMap.end() ; iter++)
		for(int i = 0 ; i < iter->second.size() ; i++)
			if( opt > 2)
			{
				Matrix[(iter->first)-1][(iter->second[i])-1] = \
				weightMap[pair<int, int>(iter->first, iter->second[i])];
			}
			else
			{
				Matrix[(iter->first)-1][(iter->second[i])-1] = 1;
			}

	// Adjacent List 는 1부터 시작
	// |
	// |	<- Adjacent List - 1
	// V
	// Matrix 는 0부터 시작
	
	
	/* Matrix 출력 */
	
	for(int i = 0 ; i < size ; i++ )
	{
		for(int j = 0 ; j < size; j++)
		{
			cout << "[" << Matrix[i][j] << "]";
		}
		
		cout << endl;
	}
	
	pair<int**, int> sender = make_pair(Matrix, size);
	
	return sender;
}