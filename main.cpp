#include "RoutePlanner.hpp"

int main(void)
{
  Node* list = NULL;

  Star test;
  Star test2;

  test.name = "First";
  test2.name = "Second";

  insertStarAtFront(&list, test2);
  insertStarAtFront(&list, test);

  printList(list);
  
  return 0;
}
