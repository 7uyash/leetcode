class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start^goal;
        int count = 0;

        while(diff){
            count += diff & 1;
            diff>>=1;

        }
        return count;
    }
};