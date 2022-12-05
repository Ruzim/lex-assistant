/*
 * Tiles.cpp
 *
 *  Created on: Jan 25, 2012
 *      Author: rui
 */

#include "Tiles.h"

Tiles::Tiles() {
	// TODO Auto-generated constructor stub

}

Tiles::~Tiles() {
	// TODO Auto-generated destructor stub
}

int Tiles::get_num_tiles(){
	return num_tiles;
}

string Tiles::get_tiles_str(){
	return tiles_str;
}

void Tiles::set_tiles_str(){
	//const string tilefilename = "tiles.txt";
	ifstream infile;
	infile.open("tiles.txt", ios::in);
	if (! infile){
		cerr<<"open tiles error!"<<endl;
		//exit(1);
	}
	infile>>tiles_str;
	num_tiles = tiles_str.length();
	cout<<"Number of tiles =   "<<num_tiles<<endl;
	cout<<"Tiles:   "<<tiles_str<<endl;

	infile.close();
}
