package leetcode;

public class MaximizetheTopmostElementAfterKMoves {
    public static void main(String[] args) {
        MaximizetheTopmostElementAfterKMoves obj = new MaximizetheTopmostElementAfterKMoves();
        int[] nums = { 5, 2, 2, 4, 0, 6 };
        System.out.println(obj.maximumTop(nums, 10));
        System.out.println(obj.maximumTop(nums, 6));
        System.out.println(obj.maximumTop(nums, 5));
        System.out.println(obj.maximumTop(nums, 4));
    }

    public int maximumTop(int[] nums, int k) {
        if (nums.length == 1) {
            if (k % 2 == 0) {
                return nums[0];
            } else {
                return -1;
            }
        }
        int maximum = Integer.MIN_VALUE;
        int upperLimit = k > nums.length ? nums.length : k == nums.length ? nums.length - 1 : k - 1;

        for (int i = 0; i < upperLimit; i++) {
            maximum = Math.max(nums[i], maximum);
        }

        if (k < nums.length) {
            maximum = Math.max(maximum, nums[k]);
        }

        return maximum;
    }
}
