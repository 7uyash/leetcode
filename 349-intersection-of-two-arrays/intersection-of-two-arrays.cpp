class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1(nums1.begin(), nums1.end());
        
        unordered_set<int>intersection_set;

        for(int num: nums2){
            if(set1.find(num) != set1.end()){
                intersection_set.insert(num);
            }
        }
        return vector<int>(intersection_set.begin(), intersection_set.end());
    }
};