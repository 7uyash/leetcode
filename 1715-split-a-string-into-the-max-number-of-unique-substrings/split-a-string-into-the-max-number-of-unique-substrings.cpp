class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSub;
        return backtrack(s, 0, uniqueSub);

    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& uniqueSub){
        if(start == s.length()){
            return uniqueSub.size();
        }
        int maxC = 0;
        for(int end = start+1; end<= s.length(); ++end){
            string subStr = s.substr(start, end-start);
            if(uniqueSub.find(subStr)==uniqueSub.end()){
                uniqueSub.insert(subStr);
                maxC= max(maxC, backtrack(s, end, uniqueSub));
                uniqueSub.erase(subStr);
            }
        }
        return maxC;
        
    }
};