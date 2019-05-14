'''
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
'''


# Do not edit the class below except for
# the insert, contains, and remove methods.
# Feel free to add new properties and methods
# to the class.
class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    #Iterative solution:
    # Average - O(log(n) time & O(1) space
    # Worst   - O(n)     time & O(1) space
    def insert(self, value):
        currentNode = self
        while True:
            if value < currentNode.value:
                if currentNode.left is None:
                    currentNode.left = BST(value)
                    break
                else:
                    currentNode = currentNode.left
            else:
                if currentNode.right is None:
                    currentNode.right = BST(value)
                    break
                else:
                    currentNode = currentNode.right
        return self
    
    # Recursive solution
    # Average - O(log(n) time & log(n) space
    # Worst   - O(n)     time & O(1)   space
    def insertRecursive(self, value):
        if value < self.value:
            if self.left is None:
                self.left = BST(value)
            else:
                self.left.insertRecursive(value)
        else:
            if self.right is None:
                self.right = BST(value)
            else:
                self.right.insertRecursive(value)
        return self


    #Iterative solution:
    # Average - O(log(n) time & O(1) space
    # Worst   - O(n)     time & O(1) space
    def contains(self, value):
        currentNode = self
        while currentNode is not None:
            if currentNode.value == value:
                return True
            elif value < currentNode.value:
                currentNode = currentNode.left
            else:
                currentNode = currentNode.right
        return False

    # Recursive solution
    # Average - O(log(n) time & log(n) space
    # Worst   - O(n)     time & O(1)   space
    def containsRecursive(self, value):
        if value < self.value:
            if self.left is None:
                return False
            else:
                self.left.containsRecursive(value)
        elif value >= self.value:
            if self.right is None:
                return False
            else:
                self.right.containsRecursive(value)
        else:
            return True

    def remove(self, value, parentNode = None):
        currentNode = self
        while currentNode is not None:
            if value < currentNode.value:
                parentNode = currentNode
                currentNode = currentNode.left
            elif value >= currentNode.value:
                parentNode = currentNode
                currentNode = currentNode.right
            else:
                if currentNode.left is not None and currentNode.right is not None:
                    currentNode.value = currentNode.right.getMinValue()
                    currentNode.right.remove(currentNode.value, currentNode)
                elif parentNode is None:
                    # we are removing the root node
                    if currentNode.left is not None:
                        currentNode.value = currentNode.left.value
                        currentNode.right = currentNode.left.right
                        currentNode.left = currentNode.left.left
                    elif currentNode.right is not None:
                        currentNode.value = currentNode.right.value
                        currentNode.left = currentNode.right.left
                        currentNode.right = currentNode.left.left
                    else:
                        currentNode.value = None
                elif parentNode.left == currentNode:
                    parentNode.left = currentNode.left if currentNode.left is not None else currentNode.right
                elif parentNode.right == currentNode:
                    parentNode.right = currentNode.left if currentNode.left is not None else currentNode.right
                break
        return self
    
    def getMinValue(self):
        currentNode = self
        while currentNode is not None:
            currentNode = currentNode.left
        return currentNode.value