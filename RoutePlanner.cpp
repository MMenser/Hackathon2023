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