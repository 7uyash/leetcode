class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divCount = 0;
        int nonDiv = 0;
        for(int i = 1; i<=n; i++){
            if(i%m==0){
                divCount+=i;
            }else{
                nonDiv+=i;
            }
        }
        return nonDiv-divCount;
    }
};