//
//  MSMaximumFlow.h
//  msModule
//
//  Created by 박민석 on 2015. 11. 3..
//  Copyright © 2015년 박민석. All rights reserved.
//

#ifndef MSMaximumFlow_h
#define MSMaximumFlow_h

//BFS

bool BFS(int** rGraph, int s, int t, int parent[], int SIZE);
int MSMaximumFlow(int **Graph, int s, int t, int SIZE, int opt);

#endif /* MSMaximumFlow_h */
