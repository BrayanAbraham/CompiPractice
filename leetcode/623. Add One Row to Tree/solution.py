# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def addOneRow(self, root: TreeNode | None, val: int, depth: int) -> TreeNode | None:
        if root == None:
            return None
        
        if depth == 1:
            return TreeNode(val, root)
        
        if depth == 2:
            newLNode = TreeNode(val, left=root.left)
            newRNode = TreeNode(val, right=root.right)
            root.left = newLNode
            root.right = newRNode

            return root
        
        root.left = self.addOneRow(root.left, val, depth - 1)
        root.right = self.addOneRow(root.right, val, depth - 1)

        return root