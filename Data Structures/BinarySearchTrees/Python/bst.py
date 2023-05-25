class TreeNode:
    value = None
    left = None
    right = None
    def __init__(self, newValue):
        self.value = newValue
        self.left = None
        self.right = None

    def insert(self, newValue):
        if newValue < self.value:
            if self.left is None:
                self.left = TreeNode(newValue)
            else:
                self.left.insert(newValue)
        else:
            if self.right is None:
                self.right = TreeNode(newValue)
            else:
                self.right.insert(newValue)

    def inOrder(self):
        if self.left is not None:
            self.left.inOrder()
        print(self.value, end= " ")
        if self.right is not None:
            self.right.inOrder()

    def postOrder(self):
        if self is None:
            return
        if self.left is not None:
            self.left.inOrder()
        if self.right is not None:
            self.right.inOrder()
        print(self.value,end=" ")

    def preOrder(self):
        if self is None:
            return
        print(self.value, end=" ")
        if self.left is not None:
            self.left.preOrder()
        if self.right is not None:
            self.right.preOrder()

    def checkBalancedHeight(self, height=0):
        if self is None: #trivial solution
            return 0, True
        
        leftHeight = 0
        leftBalanced = True
        rightHeight = 0 
        rightBalanced = True

        if self.left is not None:
            leftHeight, leftBalanced = self.left.checkBalancedHeight(height + 1)
        
        if self.right is not None:
            rightHeight, rightBalanced = self.right.checkBalancedHeight(height + 1)
        
        height = max(leftHeight, rightHeight) + 1
        isBalanced = abs(leftHeight - rightHeight) <= 1 and leftBalanced and rightBalanced

        return (height, isBalanced)
def main():
    list = [1,5,4,6,3,7]
    tree = TreeNode(2)
    for x in list:
        tree.insert(x)
    print("InOrder: " ,end=" ")
    tree.inOrder()
    print()
    print("PreOrder: " ,end=" ")
    tree.preOrder()
    print()
    print("PostOrder: " ,end=" ")
    tree.postOrder()
    print()
    print("Balanced: ",end=" ")
    print(tree.checkBalancedHeight())
main()
            