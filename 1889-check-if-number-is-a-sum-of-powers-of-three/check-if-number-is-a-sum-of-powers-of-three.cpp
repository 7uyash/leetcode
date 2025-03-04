class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3==0 || n%3==1 ){
                n/=3;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};