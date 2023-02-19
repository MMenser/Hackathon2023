
#include "ImageProcessor.hpp"
#include "Libraries/bitmap/bitmap_image.hpp"
#include "RoutePlanner.hpp"
#include "FileParser.hpp"


int main(void)
{
	std::fstream infile;

	infile.open("Positions.csv", std::ios::in);

	Star starArr[189];
	int count = fillArr(infile, starArr);

	ImageProcessor ip(500, 500);

	ip.plotStarLocations(starArr, 189, 5, ip.white);

	ip.outputBMP("test");
	return 0;
}
