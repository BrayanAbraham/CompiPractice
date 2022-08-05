package leetcode;

import java.util.ArrayList;

public class CombinationSum4 {
    int counter = 0;

    public static void main(String[] args) {
        CombinationSum4 obj = new CombinationSum4();
        int[] nums1 = { 1, 2, 3 };
        System.out.println(obj.combinationSum4(nums1, 32));
        System.out.println(obj.counter);
        // 181997601
        // 650543809
    }

    public int combinationSum4(int[] nums, int target) {
        ArrayList<Integer> list = new ArrayList<>(target + 1);
        list.add(1);

        for (int i = 1; i <= target; i++) {
            int value = 0;
            for (int num : nums) {
                if (i - num >= 0) {
                    value += list.get(i - num);
                }
            }
            list.add(value);
        }

        return list.get(target);
    }

}
