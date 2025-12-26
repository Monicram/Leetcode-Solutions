// Palindrome Number
// https://leetcode.com/problems/palindrome-number/

class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x;
        int rev = 0;
        while (temp != 0) {
            rev = rev * 10 + temp % 10;
            temp = temp / 10;
        }
        return rev == x;
    }
}
