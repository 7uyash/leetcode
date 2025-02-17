class Solution {
public:
    void backtracking(unordered_map<char, int>& freq, int& count){
        for(auto& [ch, val]: freq){
            if(val>0){
                count++;
                freq[ch]--;
                backtracking(freq, count);
                freq[ch]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char, int>freq;
        for(char ch: tiles){
            freq[ch]++;

        }
        int count = 0;
        backtracking(freq, count);
        return count;
    }
};