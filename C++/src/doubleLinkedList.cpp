#include "utils.h"
using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int v){
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList{
public:
    Node* head;
    Node* tail;

    DoubleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void setHead(Node* node){
        // Empty list then simple copy node to head
        if(head == nullptr){
            head = tail = node;
        }
        else{
            Node* tmp = head;
            head = node;
            head->next = tmp->next;
        }
    }

    void setTail(Node* node){
        if(tail == nullptr){
            head = tail = node;
        }
        else{
            Node* tmp = tail;
            tail = node;
            tail->prev = tmp->prev;
        }
    }

    void insertBefore(Node* node, Node* nodeToInsert){
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        node->prev = nodeToInsert;
    }

    void insertAfter(Node* node, Node* nodeToInsert){
        nodeToInsert->prev = node;
        nodeToInsert->next = node->next;
        node->next = nodeToInsert;
    }

    void insertAtPosition(int position, Node* nodeToInsert){
        if(head == nullptr){
            if(position > 1){
                cout << "Invalid position requested (list is empty)" << position << endl;
                return;
            }
            head = tail = nodeToInsert;
        }
        else{
            Node* nodeAtPosition = head;
            for (int i = 1; i <= position; i++){
                if(nodeAtPosition->next != nullptr){
                    nodeAtPosition = nodeAtPosition->next;
                }
                else{
                    nodeAtPosition = nullptr;
                    break;
                }
            }
            if(nodeAtPosition != nullptr){
                insertBefore(nodeAtPosition, nodeToInsert);
            }
        }       
    }

    void remove(Node* node){
        if(head == node && tail == node){
            head = nullptr;
            tail = nullptr;
            delete node;
        }
        else if(head == node){
            head = head->next;
            head->prev = nullptr;
            delete node;
        }
        else if(tail == node){
            tail = tail->prev;
            tail->next = nullptr;
            delete node;
        }
        else{
            Node* tmp_prev = node->prev;
            Node* tmp_next = node->next;
            tmp_prev->next = tmp_next;
            tmp_next->prev = tmp_prev;
            delete node;
        }
    }
    void removeNodesWithValue(int value){
        Node* current = head;
        while (current != nullptr){
            if(current->value == value){
                current = current->next;
                this->remove(current);
                continue;
            }
            current = current->next;
        } 
    }

    bool containsNodeWithValue(int value){
        Node* current = head;
        while (current != nullptr){
            if(current->value == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }
};