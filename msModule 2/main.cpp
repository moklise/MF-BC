//
//  main.cpp
//  msModule
//
//  Created by 박민석 on 2015. 11. 2..
//  Copyright © 2015년 박민석. All rights reserved.
//

#include <iostream>
#include "MSInputToMatrix.h"
#include "MSMaximumFlow.h"
#include "MSBetweennessCentrality.h"
using namespace std;

// opt.
//1. Direction : n Weight : n
//2. Direction : y Weight : n
//3. Direction : n Weight : y
//4. Direction : y Weight : y
// MaximumFlow : y, y : 4
// BetweennessC: x, x : 1

int main(int argc, const char * argv[]) {
	pair<int**, int> graphSet;
	int opt;
	
	cout << ".OPTION" << endl;
//	cout << "1. Direction / 2. Weight" << endl;
	cout << "1. Direction : n Weight : n \n2. Direction : y Weight : n \n3. Direction : n Weight : y \n4. Direction : y Weight : y" << endl;
	cout << "노드는 반드시 1부터" << endl;
	cin  >> opt;
	
	if(opt > 4 || opt < 1)
	{
		cout << "Invald!" << endl;
		exit(1);
	}
	
	graphSet = MSInputToMatrix(opt);
	
	cout << graphSet.first
		 << " "
		 << graphSet.second
		 << endl;

//	for(int i = 0 ; i < graphSet.second ; i++)
//	{
//		for(int j = 0 ; j < graphSet.second ; j++)
//			cout << "[" << graphSet.first[i][j] << "]";
//		cout << endl;
//	} 
	
	int MFS, MFT;
	cout << "Type S - T :" << endl;
	cin >> MFS
		>> MFT;
	
	cout << MSMaximumFlow(graphSet.first, MFS-1, MFT-1, graphSet.second, opt) << endl;
	MSBetweennessCentrality(graphSet.first, graphSet.second, opt);
	// first 
	delete graphSet.first;

	return 0;
}
