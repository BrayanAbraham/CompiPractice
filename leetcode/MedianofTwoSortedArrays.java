package leetcode;

import java.util.Arrays;

public class MedianofTwoSortedArrays {
    public static void main(String[] args) {
        int[] nums1 = { 1, 3 };
        int[] nums2 = { 2 };
        MedianofTwoSortedArrays object = new MedianofTwoSortedArrays();
        System.out.println(object.medianofTwoSortedArrays(nums1, nums2));
    }

    public double medianofTwoSortedArrays(int[] nums1, int[] nums2) {
        int[] result = new int[nums1.length + nums2.length];
        System.arraycopy(nums1, 0, result, 0, nums1.length);
        System.arraycopy(nums2, 0, result, nums1.length, nums2.length);
        Arrays.sort(result);

        int index = result.length / 2;
        if (result.length % 2 == 0) {
            return (double)(result[index - 1] + result[index]) / 2;
        }

        return result[index];
    }
}
