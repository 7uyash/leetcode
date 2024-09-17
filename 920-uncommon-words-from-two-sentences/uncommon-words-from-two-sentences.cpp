class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int>wordCount;
        auto countWords = [&](const string&sentence){
            stringstream ss(sentence);
            string word;
            while(ss>>word){
                wordCount[word]++;
            }
        };
        countWords(s1);
        countWords(s2);
        vector<string>result;

        for(const auto& wc : wordCount){
            if(wc.second == 1){
                result.push_back(wc.first);
            }
        }
        return result;
    }
};