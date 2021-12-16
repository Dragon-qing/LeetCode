"""
# Definition for a Node.

"""
import collections
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        arr = [root]
        while len(arr):
            size = len(arr)
            for i in range(size):
                t = arr.pop(0)
                if i < size-1:
                    t.next = arr[0]
                if t.left:
                    arr.append(t.left)
                if t.right:
                    arr.append(t.right)
        return root


