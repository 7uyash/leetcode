class Solution {
public:
    int minLength(string s) {
        string result;
        int n = s.length();

        for(int i = 0; i<n; ++i){
            result.push_back(s[i]);

            if(result.length()>=2){
                if((result[result.length()-1]=='B' && result[result.length()-2]=='A') || (result[result.length()-1]== 'D' && result[result.length()-2]=='C')){
                    result.pop_back();
                    result.pop_back();
                }
            }
        }
        return result.length();
    }
};