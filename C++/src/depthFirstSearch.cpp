/*
    Depth-First Search Algorithm

    You are given a node that has a name and an array of optional children Nodes. When put together, Nodes form a simple
    tree-like structure.

    Implement the DepthFirstSearch method on the Node class, which takes in an empty array, traverses the tree using the
    Depth-First Search approach (specifically traversing the tree from left to right), stores all of the Node's names in the
    input array and returns it.

    Sample Input:
                    A
                /   |   \
               B    C    D
              / \       / \
             E   F     G   H
                / \     \
               I   J     K
    Sample Output: ["A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"]
*/
#include "utils.h"
using namespace std;
class Node{
    public:
        string name;
        vector<Node*> children;

        Node(string n){
            name = n;
        }

        Node* addChild(string name){
            Node* child = new Node(name);
            children.push_back(child);
            return this;
        }

        vector<string> depthFirstSearch(vector<string>* array){
            array->push_back(name);
            for(int i = 0; i<children.size(); i++){
                children.at(i)->depthFirstSearch(array);
            }
            return *array;
        }
    

};