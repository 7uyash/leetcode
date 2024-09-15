class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int>indexM;
        indexM[0]=-1;
        int bitM = 0;
        int maxL = 0;

        unordered_map<char, int>vowelB = {
            {'a', 1<<0},
            {'e', 1<<1},
            {'i', 1<<2},
            {'o', 1<<3},
            {'u', 1<<4}
        };
        for(int i = 0; i<s.length(); ++i){
            if(vowelB.find(s[i]) !=vowelB.end()){
                bitM ^= vowelB[s[i]];

            }
            if(indexM.find(bitM)!=indexM.end()){
                maxL = max(maxL, i-indexM[bitM]);

            }else{
                indexM[bitM]=i;
            }
        }
        return maxL;
    }
};