package leetcode;

import java.util.ArrayList;
import java.util.List;

public class RestoreIpAddresses {
    public static void main(String[] args) {
        RestoreIpAddresses object = new RestoreIpAddresses();
        for (String string : object.restoreIpAddresses("25525511135")) {
            System.out.println(string);
        }
        for (String string : object.restoreIpAddresses("0000")) {
            System.out.println(string);
        }
        for (String string : object.restoreIpAddresses("101023")) {
            System.out.println(string);
        }
    }

    public List<String> restoreIpAddresses(String s) {
        ArrayList<String> list = new ArrayList<>();
        return this.restoreIpAddresses(s, 0, "", list);
    }

    public List<String> restoreIpAddresses(String s, Integer count, String current, ArrayList<String> result) {
        if (count == 4) {
            if (s.length() == 0) {
                result.add(current);
            }
            return result;
        } else if (s.length() == 0) {
            return result;
        }

        Integer index = 0;
        String ipBlock = s.substring(0, index + 1);
        while (ipBlock.length() > 0
                && (ipBlock.length() == 1 || (ipBlock.length() > 1 && ipBlock.charAt(0) != '0'))
                && Integer.parseInt(ipBlock) <= 255
                && index < s.length()) {
            String temp = index < (s.length() - 1) ? s.substring(index + 1) : "";
            String curr = ipBlock + (count < 3 ? "." : "");
            result = new ArrayList<String>(this.restoreIpAddresses(temp, count + 1, current + curr, result));
            index++;
            ipBlock = s.substring(0, Math.min(index + 1, s.length()));
        }

        return result;
    }
}
