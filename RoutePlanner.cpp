#include "RoutePlanner.hpp"

Node* makeNode(Star& data){
    Node* ptr = new Node();

    if(ptr != NULL){
        ptr->star.gal_x = data.gal_x;
        ptr->star.gal_y = data.gal_y;
        ptr->star.gal_z = data.gal_z;
        ptr->star.luminocity = data.luminocity;
    }

    return ptr;
}

int insertAtFront(Node** list, Star& insert){
    Node* pMem = makeNode(insert);
    int success = 0;

    if(pMem != NULL){
        pMem->pNext = *list;
        *list = pMem;
        success = 1;
    }
    return success;
}

int insertAtEnd(Node** list, Star& insert) {
    Node* pMem = makeNode(insert), * pCur = *list, * pPrev = NULL;
    int success = 0;

    if (pMem != NULL) {
        
        while (pCur != NULL) {
            pPrev = pCur;
            pCur = pCur->pNext;
        }
        if (*list == NULL) {//if list is empty
            *list = pMem;
        }
        else {
            pPrev->pNext = pMem;
            pMem->pNext = NULL;
            
        }
        success = 1;
    }
    return success;
}

void printList(Node* list){
    Node* pCur = list;

    while(pCur != NULL){
        std::cout << pCur->star.gal_x << ", " << pCur->star.gal_y << ", " << pCur->star.gal_z << std::endl;
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
    double minDistance = 3000.0, testDistance = 0.0;
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
            testDistance = getDistance(origin, starArr[i]);
            if (testDistance < minDistance) {//If the distance to this star is shorter than the shortest checked so far
                minDistance = testDistance;
                bestStar = &starArr[i];
            }
        }
        isValidStar = 0;
    }
    return bestStar;
}

Node* makeRoute(Star& start, Star& end, Star starArr[]) {
    Node* list = NULL;
    int direction[3] = { 0, 0, 0 };
    Star* current = &start, * prevStar = NULL;

    insertAtFront(&list, start);

    do {
        prevStar = current;
        //First check directions (can't just do at beginning, what if we pass it on one axis?)
        if (end.gal_x > current->gal_x) {//If moving in positive x
            direction[0] = 1;
        }
        if (end.gal_y > current->gal_y) {//If moving in positive y
            direction[1] = 1;
        }
        if (end.gal_z > current->gal_z) {//If moving in positive z
            direction[1] = 1;
        }

        current = findStarInDirection(starArr, *current, direction);

        if (getDistance(*prevStar, *current) > getDistance(*prevStar, end)) {
            current = &end;
        }

        insertAtEnd(&list, *current);
        //Reset direction array
        direction[0] = 0;
        direction[1] = 0;
        direction[2] = 0;
    } while (end.gal_x != current->gal_x && end.gal_y != current->gal_y && end.gal_z != current->gal_z);

    return list;
}