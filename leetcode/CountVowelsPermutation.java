package leetcode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class CountVowelsPermutation {
    public HashMap<Character, ArrayList<Character>> charmaps;

    public CountVowelsPermutation() {
        this.charmaps = new HashMap<>();
        Character[] aMap = { 'e', 'i', 'u' };
        this.charmaps.put('a', new ArrayList<>(Arrays.asList(aMap)));
        Character[] eMap = { 'a', 'i' };
        this.charmaps.put('e', new ArrayList<>(Arrays.asList(eMap)));
        Character[] iMap = { 'e', 'o' };
        this.charmaps.put('i', new ArrayList<>(Arrays.asList(iMap)));
        Character[] oMap = { 'i' };
        this.charmaps.put('o', new ArrayList<>(Arrays.asList(oMap)));
        Character[] uMap = { 'i', 'o' };
        this.charmaps.put('u', new ArrayList<>(Arrays.asList(uMap)));
    }

    public static void main(String[] args) {
        CountVowelsPermutation obj = new CountVowelsPermutation();
        System.out.println(obj.countVowelPermutation(1));
        System.out.println(obj.countVowelPermutation(2));
        System.out.println(obj.countVowelPermutation(5));
        System.out.println(obj.countVowelPermutation(144));
    }

    public int countVowelPermutation(int n) {
        int dp[][] = new int[5][n];
        String vowels = "aeiou";

        for (int i = 0; i < 5; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < vowels.length(); j++) {
                dp[j][i] = 0;
                for (Character c : this.charmaps.get(vowels.charAt(j))) {
                    dp[j][i] = (dp[j][i] + dp[vowels.indexOf(c)][i - 1]) % 1000000007;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < 5; i++) {
            result = (result + dp[i][n - 1]) % 1000000007;
        }

        return result;
    }

}
