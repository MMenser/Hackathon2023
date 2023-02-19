
#include "ImageProcessor.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"
#include "RoutePlanner.hpp"
#include "FileParser.hpp"


int main(void)
{
	std::fstream infile;
	infile.open("Positions.csv", std::ios::in);

	Star starArr[ARR_SIZE];
	int count = fillArr(infile, starArr);

	Star sol;
	Star w406;

	sol.gal_x = 0.0;
	sol.gal_y = 0.0;
	sol.gal_z = 0.0;
	w406.gal_x = 9.131;
	w406.gal_y = -0.013;
	w406.gal_z = -42.396;

	Node* route = makeRoute(sol, w406, starArr);
	route;

	return 0;
}
