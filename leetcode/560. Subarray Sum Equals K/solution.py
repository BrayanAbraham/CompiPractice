class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        
        sums = []
        sum_map = {}

        sums.append(0)
        sum_map[0] = 1

        for i in range(len(nums)):
            sum = sums[i] + nums[i]
            sums.append(sum)
            sum_map[sum] = 1 if not(sum in sum_map) else sum_map[sum] + 1
            
        counter = 0

        for i in sums:
            diff = k + i

            sum_map[i] -= 1

            if diff in sum_map:
                counter += sum_map[diff]
            
        
        return counter