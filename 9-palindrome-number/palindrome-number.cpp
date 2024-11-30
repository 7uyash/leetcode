class Solution {
public:
    bool isPalindrome(int x) {
        long temp = 0;
        long original = x;
        while(x > 0){
            long rm = x%10;
            temp = temp*10 + rm;
            x/=10;
        }
        return temp == original;
    }
};