#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>



using namespace std;

typedef struct star {
	double x, y, z, massKG, lum;
} Star;

class DataParser
{

};


int fillArr(fstream& infile, Star starArr[300]);