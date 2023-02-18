
#include <iostream>
#include <cstdlib>

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
	Star star;
	Node* pNext;
};

//Finds a route using short jumps to eventually go from start to end
Node* makeRoute(Star& start, Star& end);

//Makes a node and initializes it with the input data
Node* makeNode(Star& data);

//Inserts a star at the beginning of the list
int insertStarAtFront(Star** list, Star& insert);

//Prints the list
void printList(Star& list);