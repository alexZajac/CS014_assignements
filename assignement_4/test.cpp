#include "MyTree.h"

//Testing (you must implement yours for the perfomance studies)
main() {

  MyTree *t = new MyTree();
  t->insert(1, "1");
  t->insert(2, "2");
  t->insert(3, "3");
  t->insert(4, "4");
  t->insert(5, "5");
  t->insert(6, "6");
  t->insert(7, "7");
  t->preorder();
  t->makeBST();
  cout << endl;
  t->preorder();
  system("pause");
}
