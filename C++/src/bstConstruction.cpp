/*
BST CONSTRUCTION
    Write a Binary Search Tree (BST) class. The class should have a "value" property set to be an
    intger, as well as "left" and "right" properties, both of which should point to either None (null)
    value or to another BST.

    A node is set to be a BST node if and only if it satisfies the BST property:
        - it's value is strictly greater than the values of every node to its left
        - it's value is less than or equal to the values of every node to its right
        - both of the childred are either BST nodes themselves or Node (null) values.
    
    The BST class should support insertion, searching and removal of values.
    The removal method should only remove the first instance of the target value.
*/

#include "utils.h"

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {

    public:
        int value;
        BST* left;
        BST* right;

    BST(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }

    // Recursive solution 
    // Average: O(log(n)) time & O(log(n)) space
    // Worst:   O(n) time & (On) space
    ///TODO: Could implement as recursive solution where we could save spaces
    BST& insert(int val) {
        if(val < value){
            if(left == nullptr){
                left = new BST(val);
            }
            else{
                left->insert(val);
            }
        }
        else{
            if(right == nullptr){
                right = new BST(val);
            }
            else{
                right->insert(val);
            }
        }
        return *this;
    }

    bool contains(int val){
        if(val < value){
            if(left == nullptr){
                return false;
            }
            else{
                left->contains(val);
            }
        }
        else if(val > value){
            if(right ==nullptr){
                return false;
            }
            else{
                right->contains(val);
            }
        }
        else{
            return true;
        }
    }

    BST& Remove(int val, BST* parent = nullptr) {
        if(val < value){
            if(left != nullptr){
                left->Remove(val, this);
            }
        }
        else if(val >= value){
            if(right != nullptr){
                right->Remove(val, this);
            }
        }
        else{
            if(left != nullptr && right != nullptr){
                value = right->getMinValue();
                right->Remove(value, this);
            }
            else if(parent == nullptr){
                if(left != nullptr){
                    value = left->value;
                    right = left->right;
                    left = left->left;
                }
                else if(right != nullptr){
                    value = right->value;
                    left = right->left;
                    right = right->right;
                }
                else{
                    value = 0; //We are removing the only available node
                }
            }
            else if(parent->left == this){
                parent->left = left != nullptr ? left : right;
            }
            else if(parent->right == this){
                parent->right = left != nullptr ? left : right;
            }
        }
        return *this;
    }

    int getMinValue(){
        if(left == nullptr){
            return value;
        }
        else{
            left->getMinValue();
        }
    }
};

vector<int> inOrderTraverse(BST* tree, vector<int> array){
    if(tree->left != nullptr){
        array = inOrderTraverse(tree->left, array);
    }
    array.push_back(tree->value);
    if(tree->right != nullptr){
        array = inOrderTraverse(tree->right, array);
    }
    return array;
}

int main(){
    BST tmp(10);
    tmp.insert(5).insert(15).insert(5).insert(2).insert(14).insert(22);

    bool testPassed = true;
    testPassed &= (tmp.left->value == 5);
    testPassed &= (tmp.right->right->value == 22);
    testPassed &= (tmp.right->left->value == 14);
    testPassed &= (tmp.left->left->left == nullptr);
    testPassed &= tmp.contains(15);

    vector<int> exptected = {2,5,5, 10,14,15,22};
    testPassed &= (inOrderTraverse(&tmp, {}) == exptected);

    cout << "TEST 1 --> ";
    if(tmp.left->value == 5){
        cout << "PASSED\n";
    }
    else{
        cout << "FAILED!  EXPECTED: 5 GOT: " << tmp.left->value << endl;
    }
    

    cout << "TEST 2 --> ";
    if(tmp.right->right->value == 22){
        cout << "PASSED\n";
    }
    else{
        cout << "FAILED!  EXPECTED: 22 GOT: " << tmp.right->right->value << endl;
    }


    cout << "TEST 3 --> ";
    if(tmp.right->left->value == 14){
        cout << "PASSED\n";
    }
    else{
        cout << "FAILED!  EXPECTED: 14 GOT: " << tmp.right->left->value << endl;
    }


    cout << "TEST 4 --> ";
    if(tmp.left->left->left == nullptr){
        cout << "PASSED\n";
    }
    else{
        cout << "FAILED!  EXPECTED: Null value GOT: " << tmp.left->left->left->value << endl;
    }


    cout << "TEST 5 --> ";
    if(tmp.contains(15)){
        cout << "PASSED\n";
    }
    else{
        cout << "FAILED!  EXPECTED: TRUE GOT: FALSE" << endl;
    }


    cout << "TEST 6 --> ";
    if(inOrderTraverse(&tmp, {}) == exptected){
        cout << "PASSED\n";
    }
    else{
        cout << "FAILED!  EXPECTED: ";
        printVector(exptected);
        cout << " GOT: ";
        printVector(inOrderTraverse(&tmp, {}));
        cout << endl;
    }


    if(testPassed){
        cout << "good BST tree" << endl;
    }
    else{
        cout << "Bad BST tree" << endl;
    }
    
}