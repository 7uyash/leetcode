class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
    if (s.empty()) {
        res.push_back(vector<string>());
        return res;
    }
    for (int i = 0; i < s.size(); i++) {
        if (isPalindrome(s, 0, i)) {
            string str = s.substr(0, i + 1);
            if (i == s.size() - 1) {
                res.push_back(vector<string>{str});
            } else {
                vector<vector<string>> subRes = partition(s.substr(i + 1));
                for (auto &subVec : subRes) {
                    subVec.insert(subVec.begin(), str);
                    res.push_back(subVec);
                }
            }
        }
    }
    return res;
}

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
};