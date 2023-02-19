

int main(void)
{
	fstream infile;
	infile.open("Positions.csv", ios::in);

	Star starArr[300];
	int count = fillArr(infile, starArr);

	return 0;
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
