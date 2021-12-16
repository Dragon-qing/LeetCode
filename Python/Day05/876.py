# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        begin = head
        end = head
        count = 0
        while end is not None:
            end = end.next
            count += 1
            for i in range(count//2):
                begin = begin.next
        return begin


if __name__ == '__main__':
    node = ListNode()
    t = node
    print(id(node), id(t))
