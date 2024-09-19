class Solution {  
public:  
    vector<int> diffWaysToCompute(string expression) {  
        return compute(expression);  
    }  

private:  
    unordered_map<string, vector<int>> memo;  

    vector<int> compute(const string& expression) {  
      
        if (memo.find(expression) != memo.end()) {  
            return memo[expression];  
        }  
        
        vector<int> results;  
        
        for (int i = 0; i < expression.size(); ++i) {  
            char c = expression[i];  
      
            if (c == '+' || c == '-' || c == '*') {  
       
                string left = expression.substr(0, i);  
                string right = expression.substr(i + 1);  

                vector<int> leftResults = compute(left);  
                vector<int> rightResults = compute(right);  

                for (int leftNum : leftResults) {  
                    for (int rightNum : rightResults) {  
                        if (c == '+') {  
                            results.push_back(leftNum + rightNum);  
                        } else if (c == '-') {  
                            results.push_back(leftNum - rightNum);  
                        } else if (c == '*') {  
                            results.push_back(leftNum * rightNum);  
                        }  
                    }  
                }  
            }  
        }  
  
        if (results.empty()) {  
            results.push_back(stoi(expression));  
        }   
        memo[expression] = results;  
        return results;  
    }  
};  
