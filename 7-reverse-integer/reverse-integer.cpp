class Solution {
public:
    int reverse(long long int num) {
        bool flag = false;
        if(num<0){
            flag = true;
            num = -num;
        }long long int result = 0;
        while(num>0){
           long long int rem = num%10;
            long long int temp = result*10 + rem;
            if((temp-rem)/10 != result){
                return 0;
            }
            result = temp;
            num = num/10;
        }
        if(flag) result = - result;
        if(result>INT_MAX || result<INT_MIN){
            return 0;
        }
        return result;
    }
};