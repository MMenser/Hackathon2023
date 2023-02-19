#include "RoutePlanner.hpp"

// Node* makeRoute(Star& start, Star& end) {
//     Node* 
// }

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

Star* findStarInDirection(Star& origin, int direction[]) {

}