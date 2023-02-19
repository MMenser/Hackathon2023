#pragma once

#include "RoutePlanner.hpp"
#include <fstream>
#include <cstring>
#include <iostream>

//Parses a file that has been filtered to only contain Stars with coords and mass, returns number of Stars
int fillArr(std::fstream& infile, Star starArr[300]);
