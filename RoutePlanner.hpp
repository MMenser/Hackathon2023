
#include <iostream>

struct Star
{
	std::string name;
	double gal_x;
	double gal_y;
	double gal_z;
	double mass_kg;
	double luminocity;
};

class DataParser
{

};

struct Node {
	std::string name;
	Star star;
	Node* pNext;
};

Node* makeRoute(Star& start, Star& end);