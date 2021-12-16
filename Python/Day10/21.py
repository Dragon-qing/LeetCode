# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        l1 = list1
        l2 = list2
        re = ListNode(0)
        rear = re
        while l1 and l2:
            if l1.val < l2.val:
                newNode = ListNode(l1.val)
                l1 = l1.next
            else:
                newNode = ListNode(l2.val)
                l2 = l2.next
            rear.next = newNode
            rear = rear.next
        if l1:
            while l1:
                rear.next = ListNode(l1.val)
                rear = rear.next
                l1 = l1.next
        if l2:
            while l2:
                rear.next = ListNode(l2.val)
                rear = rear.next
                l2 = l2.next
        return re.next
