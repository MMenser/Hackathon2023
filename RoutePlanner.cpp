#include "RoutePlanner.hpp"

Node* makeNode(Star& data){
    Node* ptr = new Node();

    if(ptr != NULL){
        ptr->star.name = data.name;
        ptr->star.gal_x = data.gal_x;
        ptr->star.gal_x = data.gal_y;
        ptr->star.gal_x = data.gal_z;
        ptr->star.luminocity = data.luminocity;
    }

    return ptr;
}

int insertStarAtFront(Node** list, Star& insert){
    Node* pMem = makeNode(insert);
    int success = 0;

    if(pMem != NULL){
        pMem->pNext = *list;
        *list = pMem;
        success = 1;
    }
    return success;
}

void printList(Node* list){
    Node* pCur = list;

    while(pCur != NULL){
        std::cout << pCur->star.name << " -> ";
        pCur = pCur->pNext;
    }
}

double getDistance(Star& first, Star& second) {
    double x2 = 0.0, y2 = 0.0, z2 = 0.0, distance = 0.0;

    x2 = pow(second.gal_x - first.gal_x, 2);
    y2 = pow(second.gal_y - first.gal_y, 2);
    z2 = pow(second.gal_z - first.gal_z, 2);

    distance = sqrt(x2 + y2 + z2);
    return distance;
}

Star* findStarInDirection(Star starArr[], Star& origin, int direction[]) {
    int isValidStar = 0; //Needs to be 3 for the star to actually be valid
    double minDistance = 0.0, testDistance = 0.0;
    Star* bestStar = NULL;

    for (int i = 0; i < ARR_SIZE; i++) {
        if (direction[0]) {//Going in positive x direction
            if (starArr[i].gal_x > origin.gal_x) {
                isValidStar++;
            }
        }
        else {//Going in negative z direction
            if (starArr[i].gal_x < origin.gal_x) {
                isValidStar++;
            }
        }

        if (direction[1]) {//Going in positive y direction
            if (starArr[i].gal_y > origin.gal_y) {
                isValidStar++;
            }
        }
        else {//Going in negative z direction
            if (starArr[i].gal_y < origin.gal_y) {
                isValidStar++;
            }
        }

        if (direction[2]) {//Going in positive z direction
            if (starArr[i].gal_z > origin.gal_z) {
                isValidStar++;
            }
        }
        else {//Going in negative z direction
            if (starArr[i].gal_z < origin.gal_z) {
                isValidStar++;
            }
        }

        if (isValidStar == 3) {//If this star is in the right direction
            testDistance = getDistance(origin, starArr[i]) < minDistance;
            if (testDistance < minDistance) {//If the distance to this star is shorter than the shortest checked so far
                minDistance = testDistance;
                *bestStar = starArr[i];
            }
        }
        isValidStar = 0;
    }
    return bestStar;
}

Node* makeRoute(Star& start, Star& end) {
    Node* list = NULL;
}