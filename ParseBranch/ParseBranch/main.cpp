#include "header.hpp"


int main(void)
{
	fstream infile;
	infile.open("C:\\Users\\mason\\OneDrive\\Documents\\GitHub\\Hackathon2023\\Positions.csv", ios::in);

	Star starArr[300];
	int count = fillArr(infile, starArr);
	double leftX = 0, rightX = 0, upY = 0, downY = 0;
	int x, y;

	char arr[580][958] = { 0 };

	for (int i = 0; i < count; i++) {
		x = (int)starArr[i].x;
		y = (int)starArr[i].y;
		arr[x][y] = 'X';
		/*if (i == 0) {
			leftX = starArr[i].x;
			downY = starArr[i].y;
		}
		if (starArr[i].x > rightX) {
			rightX = starArr[i].x;
		}
		if (starArr[i].y > upY) {
			upY = starArr[i].y;
		}
		if (starArr[i].x < leftX) {
			leftX = starArr[i].x;
		}
		if (starArr[i].y < downY) {
			downY = starArr[i].y;
		}
		*/
	}

	//std::cout << "Left X: " << leftX << "\tRightX: " << rightX << "\t\tUp Y: " << upY << "\tDown Y" << downY;

	

	return 0;
}

int fillArr(fstream& infile, Star starArr[300]) {
	std::string line;
	std::string doubleStr;
	char* tok;
	char strArr[50];
	int count = 0;

	while (!infile.eof()) {
		std::getline(infile, line, '\n');
		strcpy(strArr, line.c_str());
		if (line != "0,0,0") {
			for (int i = 0; i < 3; i++) {
				if (i == 0) {
					tok = strtok(strArr, ",");
					doubleStr = doubleStr + tok;
					starArr[count].x = std::stod(doubleStr);
				}
				else if (i == 1) {
					tok = strtok(NULL, ",");
					doubleStr = doubleStr + tok;
					starArr[count].y = std::stod(doubleStr);
				}
				else {
					tok = strtok(NULL, ",");
					doubleStr = doubleStr + tok;
					starArr[count].z = std::stod(doubleStr);
				}
				doubleStr = "";

			}
			count++;
		}
	}

	return count;
}