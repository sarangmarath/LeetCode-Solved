class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false; 
        int n = x;
        int rem, rev = 0;

        while (n > 0) {
            rem = n % 10;
            rev = (rev * 10) + rem;
            n = n / 10;
        }

        return x == rev;
    }
}