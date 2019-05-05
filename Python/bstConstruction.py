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

    def insert(self, value):
        if value >= self.value:
            if self.right is None:
                self.right = BST(value)
            else:
                self.insert(self.right, value)
        else:
            if self.left is None:
                self.left = BST(value)
            else:
                insert(self.left, value)
        return self

    def contains(self, value):
        if self is None:
            return False

        if self.value == value:
            return True
        else:
            if value < self.value:
                return self.contains(self.left, value)
            else:
                return self.contains(self.right, value)

    def remove(self, value):
        # Write your code here.
        # Do not edit the return statement of this method.
        return self