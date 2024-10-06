class Solution {  
public:  
    bool areSentencesSimilar(const string& sentence1, const string& sentence2) {  
        vector<string> words1, words2;  
        splitSentence(sentence1, words1);  
        splitSentence(sentence2, words2);  
        
        int len1 = words1.size();  
        int len2 = words2.size();  
   
        if (len1 > len2) {  
            return areSentencesSimilar(sentence2, sentence1);  
        }  
        
        
        int prefix_count = 0;  
        while (prefix_count < len1 && words1[prefix_count] == words2[prefix_count]) {  
            prefix_count++;  
        }  
        
        int suffix_count = 0;  
        while (suffix_count < len1 - prefix_count &&   
               words1[len1 - 1 - suffix_count] == words2[len2 - 1 - suffix_count]) {  
            suffix_count++;  
        }  
        
              return (prefix_count + suffix_count >= len1) && (prefix_count + suffix_count <= len2);  
    }  

private:  
    void splitSentence(const string& sentence, vector<string>& words) {  
        stringstream ss(sentence);  
        string word;  
        while (ss >> word) {  
            words.push_back(word);  
        }  
    }  
};