# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0, head)
        prev, now = dummy, head
        for i in range(n):
            now = now.next
        while now:
            prev = prev.next
            now = now.next
        prev.next = prev.next.next
        return dummy.next


if __name__ == '__main__':
    head = ListNode(1)

    sol = Solution()
    result = sol.removeNthFromEnd(head=head , n=1)
    while result:
        print(result.val)
        result = result.next

