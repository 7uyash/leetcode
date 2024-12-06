class Solution {
public:
    string sortSentence(string s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        while(iss>>word){
            words.push_back(word);
        }
        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.back()<b.back();
        });
        string res;
        for(const auto &w : words){
            res += w.substr(0, w.size()-1) + " ";
        }
        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
};