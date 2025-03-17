class Solution {
public:
    int addDigits(int num) {
        int res = num;
        while(res>9){
            num =res;
            int temp = 0;
            while(num>0){
                temp +=num%10;
                num= num/10;
            }
            res = temp ;
        }
        return res;
    }
};