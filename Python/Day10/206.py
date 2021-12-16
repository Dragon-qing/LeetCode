# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    # 迭代
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        curr = head.next
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        return prev
    # 递归
    def reverseList2(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        re = self.reverseList2(head.next)
        head.next.next = head
        head.next = None
        return re
