class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();  
        int S = 0, C = 0;   
        for (char c : s) {  
            if (c == '[') {  
                S++;  
            } else {  
                if (S > 0) {  
                    S--;  
                } else {  
                    C++;  
                }  
            }  
        }   
        return (C + 1) / 2;
    }
};