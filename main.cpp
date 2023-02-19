
#include "ImageProcessor.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"
#include "RoutePlanner.hpp"
#include "FileParser.hpp"


int main(void)
{
	std::fstream infile;
	infile.open("Positions.csv", std::ios::in);

	Star starArr[300];
	int count = fillArr(infile, starArr);

	std::cout << starArr[0].name;

	return 0;
}
