package leetcode.LongestPalindromicSubstring;

public class Solution {
    private int start;
    private int length;

    public static void main(String[] args) {
        Solution obj = new Solution();
        System.out.println(obj.longestPalindrome("babad"));
        System.out.println(obj.longestPalindrome("cbbd"));
        System.out.println(obj.longestPalindrome("geegkforgeeks"));
    }

    public String longestPalindrome(String s) {
        this.start = 0;
        this.length = 1;

        for (int i = 0; i < s.length(); i++) {
            this.extend(s, i, i);
            this.extend(s, i, i + 1);
        }

        return s.substring(this.start, this.start + this.length);
    }

    private void extend(String s, int i, int j) {
        while (i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            i--;
            j++;
        }
        if (this.length < j - i - 1) {
            this.start = i + 1;
            this.length = j - i - 1;
        }
    }
}
