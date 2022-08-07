from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numindex = {}

        for i in range(0, len(nums)):
            numindex[nums[i]] = i

        for i in range(0, len(nums)):
            rem = target - nums[i]
            if rem in numindex.keys() and numindex[rem] != i:
                return [i, numindex[rem]]

        return []


if __name__ == "__main__":
    obj = Solution()
    print(obj.twoSum([2, 7, 11, 15], 9))
    print(obj.twoSum([3, 2, 4], 6))
    print(obj.twoSum([3, 3], 6))
