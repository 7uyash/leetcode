class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(size_t i = 1; i<s.length(); ++i){
            score += abs(s[i]- s[i-1]);

        }return score;
    }
};