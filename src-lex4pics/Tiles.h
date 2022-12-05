/*
 * Tiles.h
 *
 *  Created on: Jan 25, 2012
 *      Author: rui
 */

#ifndef TILES_H_
#define TILES_H_

#include <iostream>
#include <fstream>
#include <string>
//using namespace std;
using namespace std;

class Tiles {
private:
	int num_tiles;
	string tiles_str;
public:
	Tiles();
	virtual ~Tiles();
	int get_num_tiles();
	string get_tiles_str();
	void set_tiles_str();
};

#endif /* TILES_H_ */
