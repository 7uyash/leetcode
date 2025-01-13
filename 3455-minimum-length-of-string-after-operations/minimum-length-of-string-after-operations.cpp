class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char , int> mp;
        for(auto i : s){
            mp[i]++;
        }
        int count = 0;
        for(auto it : mp){
            if(it.second & 1){
                count++;
            }
            else count += 2;
        }

        return count;
    }
};