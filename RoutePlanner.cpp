#include "RoutePlanner.hpp"

Node* makeRoute(Star& start, Star& end) {
    Node* 
}

Node* makeNode(Star& data){
    Node* ptr = (Node*)malloc(sizeof(Node));

    if(ptr != NULL){
        ptr->star.name = data.name;
        ptr->star.gal_x = data.gal_x;
        ptr->star.gal_x = data.gal_y;
        ptr->star.gal_x = data.gal_z;
        ptr->star.luminocity = data.luminocity;
    }

    return ptr;
}