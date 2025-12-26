// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
    public int myAtoi(String s) {
        int i = 0, sign = 1, num = 0;

        // Skip leading spaces
        while (i < s.length() && s.charAt(i) == ' ') {
            i++;
        }

        // Handle sign
        if (i < s.length() && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            if (s.charAt(i) == '-') sign = -1;
            i++;
        }

        // Convert digits to number
        while (i < s.length() && Character.isDigit(s.charAt(i))) {
            int d = s.charAt(i) - '0';

            // Check for overflow
            if (num > (Integer.MAX_VALUE - d) / 10) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            num = num * 10 + d;
            i++;
        }

        return num * sign;
    }
}
