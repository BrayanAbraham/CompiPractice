package leetcode.MedianofTwoSortedArrays;

public class Solution {
    public static void main(String[] args) {
        int[] nums1 = { 1, 3 };
        int[] nums2 = { 2 };
        Solution object = new Solution();
        System.out.println(object.medianofTwoSortedArrays(nums1, nums2));
    }

    public double medianofTwoSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        return (double) (this.kthNumber(nums1, 0, nums2, 0, left) + this.kthNumber(nums1, 0, nums2, 0, right)) / 2;
    }

    private int kthNumber(int[] nums1, int n1, int[] nums2, int n2, int k) {
        if (n1 >= nums1.length)
            return nums2[n2 + k - 1];
        if (n2 >= nums2.length)
            return nums1[n1 + k - 1];
        if (k == 1)
            return Math.min(nums1[n1], nums2[n2]);

        int a = n1 + k / 2 - 1 < nums1.length ? nums1[n1 + k / 2 - 1] : Integer.MAX_VALUE;
        int b = n2 + k / 2 - 1 < nums2.length ? nums2[n2 + k / 2 - 1] : Integer.MAX_VALUE;

        return a < b ? this.kthNumber(nums1, n1 + k / 2, nums2, n2, k - k / 2)
                : this.kthNumber(nums1, n1, nums2, n2 + k / 2, k - k / 2);
    }
}
