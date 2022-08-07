# Definition for singly-linked list.
from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def print(self):
        print(self.val, end="")
        if(self.next != None):
            print('->', end="")
            self.next.print()
        else:
            print()


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result = head = temp = None
        carry = 0

        while(l1 != None and l2 != None):
            res = l1.val + l2.val + carry
            carry = res//10
            res = res % 10

            if result == None:
                result = ListNode(res)
                head = result
            else:
                temp = ListNode(res)
                head.next = temp
                head = head.next

            l1 = l1.next
            l2 = l2.next

        while(l1 != None):
            res = l1.val + carry
            carry = res//10
            res = res % 10

            if result == None:
                result = ListNode(res)
                head = result
            else:
                temp = ListNode(res)
                head.next = temp
                head = head.next

            l1 = l1.next

        while(l2 != None):
            res = l2.val + carry
            carry = res//10
            res = res % 10

            if result == None:
                result = ListNode(res)
                head = result
            else:
                temp = ListNode(res)
                head.next = temp
                head = head.next

            l2 = l2.next

        if carry > 0:
            if result == None:
                result = ListNode(carry)
                head = result
            else:
                temp = ListNode(carry)
                head.next = temp
                head = head.next

        return result


def ListNodeFromList(nums=List[int]) -> ListNode:
    result = None
    for i in nums[::-1]:
        if result == None:
            result = ListNode(i)
        else:
            temp = ListNode(i)
            temp.next = result
            result = temp
    return result


if __name__ == "__main__":
    obj = Solution()
    obj.addTwoNumbers(ListNodeFromList(
        [2, 4, 3]), ListNodeFromList([5, 6, 4])).print()
    obj.addTwoNumbers(ListNodeFromList([0]), ListNodeFromList([0])).print()
    obj.addTwoNumbers(ListNodeFromList(
        [9, 9, 9, 9, 9, 9, 9]), ListNodeFromList([9, 9, 9, 9])).print()
