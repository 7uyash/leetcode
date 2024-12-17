class Solution {  
public:  
    string repeatLimitedString(string s, int repeatLimit) {  
        map<char, int> charCount;  
        for (char c : s) {  
            charCount[c]++;  
        }  
        
        string result = "";  
        char lastChar = '\0';  

        while (!charCount.empty()) {  
            auto it = charCount.end();   
            --it;  

            char currentChar = it->first;  
            int currentFreq = it->second;  

            if (currentChar != lastChar) {  
                int addCount = min(repeatLimit, currentFreq);  
                result.append(addCount, currentChar);  
                
                if (currentFreq - addCount == 0) {  
                    charCount.erase(it);  
                } else {  
                    charCount[currentChar] -= addCount;  
                }  

                lastChar = currentChar;  
            } else {  
                if (charCount.size() == 1) {  
                    break;  
                }  
                
                auto nextIt = prev(it);  
                char nextChar = nextIt->first;  
                result.push_back(nextChar);  
                charCount[nextChar]--;  

                if (charCount[nextChar] == 0) {  
                    charCount.erase(nextIt);  
                }  

                lastChar = nextChar;  
            }  
        }  
        return result;  
    }  
};