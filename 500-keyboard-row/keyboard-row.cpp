class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char>row1 = {
            'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p','P', 'Q', 'W', 'E', 'R', 'T','Y', 'U', 'I', 'O', 'P'
        };
        unordered_set<char>row2 = {
            'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'       
        };
        unordered_set<char>row3 = {
            'Z', 'X', 'C', 'V', 'B', 'N', 'M', 'z', 'x', 'c', 'v', 'b', 'n', 'm'
        };
        vector<string>result;
        for(const auto & word: words){
            if(canBeTypes(word, row1)|| canBeTypes(word, row2)||canBeTypes(word, row3) ){
                result.push_back(word);
            }
        }
        return result;
    }

    private:
        bool canBeTypes(const string & word, const unordered_set<char>& row){
            for(char c : word){
                if(row.find(c)==row.end()){
                    return false;
                }
            }
            return true;
        }
};