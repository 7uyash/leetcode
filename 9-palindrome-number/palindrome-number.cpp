class Solution {
public:
    bool isPalindrome(long long number) {
     
        if(number<0){
            return false;
        }
        long long reversedNumber = 0, remainder, originalNumber = number;
     
        while(number!=0){
            remainder = number % 10;
            reversedNumber = reversedNumber * 10 + remainder;
            number /= 10;
        }

        if(originalNumber==reversedNumber){
            return true;
        }
        return false;
    }
};