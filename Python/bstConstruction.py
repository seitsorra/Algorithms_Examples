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
    #   - O(log(N) time and O(1) space
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
                if parentNode is None:
                    # we are removing the root node
                    pass
                elif currentNode.right is None and currentNode.left is None:
                    # This is a leaf node so we are good to simply remove it
                    if currentNode.value < parentNode.value:
                        parentNode.left = None
                    else:
                        parentNode.right = None
                    break
                else:
                    # Need to make sure we maintain the BST rules when removing a non-leaf node
                    pass
        return self