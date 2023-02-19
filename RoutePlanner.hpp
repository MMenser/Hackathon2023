#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

#define ARR_SIZE 300

struct Star
{
	std::string name;
	double gal_x;
	double gal_y;
	double gal_z;
	double mass_kg;
	double luminocity;
};

struct Node {
	Star star;
	Node* pNext;
};

//Makes a node and initializes it with the input data
Node* makeNode(Star& data);

//Inserts a node at the beginning of the list
int insertAtFront(Node** list, Star& insert);

//Inserts a node at the end of the list
int insertAtEnd(Node** list, Star& insert);

//Prints the list
void printList(Node* list);

//Finds the distance (in light years) between two stars
double getDistance(Star& first, Star& second);

//Finds the nearest star in a direction determined by the input array
//Precondition: input array should be an array of size 3, where [0] = x, [1] = y, and [2] = z, 1 for positive, 0 for negative
Star* findStarInDirection(Star starArr[], Star& origin, int direction[]);

//Finds a route using short jumps to eventually go from start to end
Node* makeRoute(Star& start, Star& end, Star starArr[]);