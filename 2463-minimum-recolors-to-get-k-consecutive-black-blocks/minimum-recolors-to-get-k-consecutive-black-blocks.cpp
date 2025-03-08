class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), b = 0, Max;

        for(int i = 0; i < k; i++){
            if(blocks[i] == 'B'){
                b++;
            }
        }

        Max = b;

        for(int i = 0; i < n - k; i++){
            if(blocks[i] == 'B'){
                b--;
            }
            if(blocks[i + k] == 'B'){
                b++;
            }

            Max = max(Max, b);

            if(Max >= k){
                return 0;
            }
        }

        return k - Max;
    }
};