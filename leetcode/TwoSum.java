package leetcode;

import java.util.HashMap;

class TwoSum{
    public static void main(String[] args) {
        int[] nums = { 3, 3 };
        int target = 6;

        TwoSum object = new TwoSum();

        int[] result = object.twoSum(nums, target);

        System.out.println(result[0]);
        System.out.println(result[1]);
    }

    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] result = { -1, -1 };


        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i);
        }

        for (int i = 0; i < nums.length; i++) {
            int key = target - nums[i];
            if (map.containsKey(key) && map.get(key) != i) {
                result[0] = i;
                result[1] = map.get(key);
                break;
            }
        }

        return result;
    }
}