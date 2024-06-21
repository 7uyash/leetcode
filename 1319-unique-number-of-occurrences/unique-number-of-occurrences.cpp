class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrence_count;
    for (int value : arr) {
        occurrence_count[value]++;
    }

    
        unordered_set<int> count_set;
    for (const auto& pair : occurrence_count) {
        if (count_set.find(pair.second) != count_set.end()) {
            return false; 
        }
        count_set.insert(pair.second);
    }

    return true;
        
    }
};