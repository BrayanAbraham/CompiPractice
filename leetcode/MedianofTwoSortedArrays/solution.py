import sys
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        left = (len(nums1)+len(nums2)+1)//2
        right = (len(nums1)+len(nums2)+2)//2
        leftMid = self.__findKthNumber(nums1, 0, nums2, 0, left)
        rightMid = self.__findKthNumber(nums1, 0, nums2, 0, right)
        return (leftMid + rightMid)/2

    def __findKthNumber(self, nums1: List[int], n1: int, nums2: List[int], n2: int, k: int) -> int:
        if n1 > len(nums1)-1:
            return nums2[n2+k-1]
        if n2 > len(nums2)-1:
            return nums1[n1+k-1]
        if k == 1:
            return min(nums1[n1], nums2[n2])

        amid = bmid = sys.maxsize
        if(n1+k//2-1 < len(nums1)):
            amid = nums1[n1+k//2-1]
        if(n2+k//2-1 < len(nums2)):
            bmid = nums2[n2+k//2-1]

        if amid < bmid:
            return self.__findKthNumber(nums1, n1+k//2, nums2, n2, k-k//2)
        else:
            return self.__findKthNumber(nums1, n1, nums2, n2+k//2, k-k//2)


if __name__ == "__main__":
    obj = Solution()
    print(obj.findMedianSortedArrays([1, 4, 6, 7, 9], [2, 3, 5, 8, 10]))
