class Solution {
public:
    char findKthBit(int n, int k) {
        int len = (1<<n)-1;
        if(n==1) return '0';
        if(k==(len+1)/2){
            return '1';
        }
        if(k<(len+1)/2){
            return findKthBit(n-1, k);
        }else{
            int nK = len - k + 1;
            char bt = findKthBit(n-1, nK);
            return (bt == '0')?'1':'0';

        }
    }
};