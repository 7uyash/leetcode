class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            string pfx_sfx = words[i];
            for (int j = i + 1; j < n; j++) {
                string ck = words[j];
                if (ck.find(pfx_sfx) == 0 &&
                    (ck.rfind(pfx_sfx)) == ck.length() - pfx_sfx.length())
                    count++;
            }
        }
        return count;
    }
};