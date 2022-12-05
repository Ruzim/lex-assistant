//============================================================================
// Name        : lex4pics.cpp
// Author      : R. Yan
// Version     :
// Copyright   : Your copyright notice
// Description : thanks to lex's help on playing a game 4 pics 1 word
//============================================================================

#include <iostream>
#include "Lex.h"
using namespace std;

int main() {
	Lex *lex = new Lex();
	cout << "\t ***********************************" << endl;
	cout << "\t     !!!    4 PICS 1 LEX    !!! " 	 << endl; 
	cout << "\t ***********************************" << endl;
	lex->input();
	lex->prepare();
	lex->compare();
	lex->sort_pools();
	lex->display();
	lex->output_pools();
	return 0;
}
