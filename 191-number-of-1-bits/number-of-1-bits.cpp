class Solution {
public:
int count =0;
    int hammingWeight(int n) {
        while(n!=0){
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};