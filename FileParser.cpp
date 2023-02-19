#include "FileParser.hpp"

int fillArr(std::fstream& infile, Star starArr[300]) {
	std::string line;
	std::string doubleStr;
	char* tok;
	char strArr[50];
	int count = 1;
	starArr[0].gal_x = 0, starArr[0].gal_y = 0, starArr[0].gal_z = 0, starArr[0].luminocity = 6000;

	while (!infile.eof()) {
		std::getline(infile, line, '\n');
		strcpy(strArr, line.c_str());
			for (int i = 0; i < 4; i++) {
				if (i == 0) {
					tok = strtok(strArr, ",");
					doubleStr = doubleStr + tok;
					starArr[count].gal_x = std::stod(doubleStr);
				}
				else if (i == 1) {
					tok = strtok(NULL, ",");
					doubleStr = doubleStr + tok;
					starArr[count].gal_y = std::stod(doubleStr);
				}
				else if (i == 2) {
					tok = strtok(NULL, ",");
					doubleStr = doubleStr + tok;
					starArr[count].gal_z = std::stod(doubleStr);
				}
				else if (i == 3) {
					tok = strtok(NULL, ",");
					doubleStr = doubleStr + tok;
					starArr[count].luminocity = std::stod(doubleStr);
				}
				doubleStr = "";

			}
			count++;
	}



	return count;
}
