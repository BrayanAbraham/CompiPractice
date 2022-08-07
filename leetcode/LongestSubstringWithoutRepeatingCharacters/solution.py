class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLength = 0
        counts = {}
        left = right = 0

        while right < len(s):
            if not(s[right] in counts.keys()):
                counts[s[right]] = 1
            else:
                counts[s[right]] += 1

            while counts[s[right]] > 1:
                counts[s[left]] -= 1
                left += 1

            maxLength = max(maxLength, right - left + 1)
            right += 1

        return maxLength


if __name__ == "__main__":
    obj = Solution()
    print(obj.lengthOfLongestSubstring("abcabcbb"))
    print(obj.lengthOfLongestSubstring("bbbbb"))
    print(obj.lengthOfLongestSubstring("pwwkew"))
