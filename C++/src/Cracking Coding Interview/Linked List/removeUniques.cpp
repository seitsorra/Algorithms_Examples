#include "MyLinkList.h"
#include <stack>
using namespace std;

int main()
{

  MyLinkList<int> *myList = new MyLinkList<int>();
  myList->push_back(1);
  myList->push_back(2);
  myList->push_back(2);
  myList->push_back(3);
  myList->push_back(3);
  myList->push_back(4);
  myList->push_back(4);
  myList->push_back(5);
  myList->printList();

  myList->removeUnique_usingDataBuffer();
  myList->removeKthLastRecursive(2);

  for (auto it = myList->begin(); it != myList->end(); ++it)
  {
    cout << *it << endl;
  }

  cout << "Removing second node without access to head\n";
  myList->removeInMiddle();

  for (auto it = myList->begin(); it != myList->end(); ++it)
  {
    cout << *it << endl;
  }

  delete myList;
  myList = new MyLinkList<int>();
  myList->push_back(9);
  myList->push_back(32);
  myList->push_back(2);
  myList->push_front(8);
  myList->push_front(1);
  myList->push_front(7);
  myList->push_back(5);
  cout << "Before partition : ";
  myList->printList();
  myList->partitionAroundNum(5);
  cout << "After  partition : ";
  myList->printList();
  delete myList;

  int a = 2111111111;
  cout << a << endl;

  float b = a;
  cout << "float : " << b << endl;
  a = (int)b;
  cout << a << endl;

  return 1;
}