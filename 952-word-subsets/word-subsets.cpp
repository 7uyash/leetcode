class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>max_freq(26, 0);
        vector<string>res;
        for(auto word : words2){
            vector<int>freq(26, 0);
           for(int i = 0; i<word.size(); ++i){
               freq[word[i]-'a']++;
               max_freq[word[i]-'a'] = max(max_freq[word[i]-'a'],  freq[word[i]-'a']);
           } 
        }   

        for(auto word : words1){
            vector<int>freq(26, 0);
            for(int i = 0; i<word.size(); ++i){
                freq[word[i]-'a']++;
            }
            bool is_valid = true; 
            for(int i = 0; i<26; ++i){
                if(max_freq[i] > freq[i]){
                    is_valid = false;
                    break;
                }
            }
            if(is_valid)
                res.push_back(word);
        }  
        return res;
    }
};