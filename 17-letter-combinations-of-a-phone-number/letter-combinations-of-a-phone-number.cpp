class Solution {  
public:  
    std::vector<std::string> letterCombinations(std::string digits) {  
      
        std::unordered_map<char, std::string> mapping = {  
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},  
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}  
        };  
        
        std::vector<std::string> result; 
        if (digits.empty()) return result; 
        
        std::string currentCombination; 
        backtrack(result, mapping, digits, currentCombination, 0);  
        return result;  
    }  

private:  
    void backtrack(std::vector<std::string>& result,   
                   const std::unordered_map<char, std::string>& mapping,  
                   const std::string& digits,   
                   std::string& currentCombination,   
                   int index) {  
        if (index == digits.size()) {  
            result.push_back(currentCombination); 
            return;  
        }  
        
        char digit = digits[index];  

       
        if (mapping.find(digit) == mapping.end()) {  
            return;
        }  

        const std::string& letters = mapping.at(digit);  
        
        for (char letter : letters) {  
            currentCombination.push_back(letter);  
            backtrack(result, mapping, digits, currentCombination, index + 1);  
            currentCombination.pop_back();   
        }  
    }  
};