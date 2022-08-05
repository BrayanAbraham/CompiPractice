package leetcode;

import java.util.HashMap;

public class LongestSubstringWithoutRepeatingCharacters {
    public static void main(String[] args) {
        String s = "abcabcbb";
        LongestSubstringWithoutRepeatingCharacters object = new LongestSubstringWithoutRepeatingCharacters();
        System.out.println(object.lengthOfLongestSubstring(s));
        s = "bbbbbb";
        System.out.println(object.lengthOfLongestSubstring(s));
        s = "pwwkew";
        System.out.println(object.lengthOfLongestSubstring(s));
    }

    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        int maxLength = 0;
        int right = 0;
        int left = 0;

        while (right < s.length()) {
            char rightCh = s.charAt(right);

            while (map.containsKey(rightCh) && map.get(rightCh) > 0) {
                char leftCh = s.charAt(left);
                map.put(leftCh, 0);
                left++;
            }

            map.put(rightCh, 1);
            maxLength = Math.max(maxLength, (right - left + 1));
            right++;
        }

        return maxLength;
    }
}
