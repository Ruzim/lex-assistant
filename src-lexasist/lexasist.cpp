//====================================================================================================
// Name        : lexasist.cpp
// Author      : rui
// Version     : 1.0
// Copyright   : This code may be freely distributed for non-commercial purposes only
// Description : Lex Asistance in C++
//			   	 The tiles are stored in tiles.txt, edit this file before each run.
//				 The dictionary used is dictionary.txt downloaded online
//				 (may be replaced by your own dictionary).
//				 When executed, the code will list the top 10 longest words which can be composed with
//				 the letters on the tiles.
//				 More words will be saved in the files pool{0-4}.txt.
//====================================================================================================

#include <iostream>
#include "Lex.h"
using namespace std;

int main() {
	Lex *lex = new Lex();
	cout << "\t ***********************************" << endl;
	cout << "\t  !!! Help Lex out of the books !!! " << endl;
	cout << "\t ***********************************" << endl;
	lex->prepare();
	lex->compare();
	lex->sort_pools();
	lex->display();
	lex->output_pools();
	return 0;
}
