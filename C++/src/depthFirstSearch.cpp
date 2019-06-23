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
    Sample Output (Depth First):    ["A", "B", "E", "F", "I", "J", "C", "D", "G", "K", "H"]

    Sample Output (Breaadth First): ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"]
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

        // O(v + e) time where v=verticies & e=edges time | O(v) space
        vector<string> breadthFirstSearch(vector<string>* array){
            Node* currentNode;
            std::queue<Node*> myQueue;
            myQueue.emplace(this);

            while (!myQueue.empty()){
                currentNode = myQueue.front();
                myQueue.pop();

                array->push_back(currentNode->name);
                for(auto node : currentNode->children){
                    myQueue.emplace(node);
                }
            }
            return *array;
        }
};

int main(){

    Node test("A"); //Root
    test.addChild("B")->addChild("C")->addChild("D"); // Level 1

    test.children[0]->addChild("E")->addChild("F"); // Level 2
    test.children[2]->addChild("G")->addChild("H");

    test.children[0]->children[1]->addChild("I")->addChild("J"); // Level 3
    test.children[2]->children[0]->addChild("K");

    vector<string>* result = new vector<string>();

    cout << "Depth First Search   : ";
    printVector(test.depthFirstSearch(result));
    
    result->clear();

    cout << "Breadth First Search : ";
    printVector(test.breadthFirstSearch(result));
    return 1;
}