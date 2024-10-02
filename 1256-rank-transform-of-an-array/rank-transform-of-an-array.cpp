class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int>rankMap;
        vector<int>uniqueArr = arr;
        sort(uniqueArr.begin(), uniqueArr.end());
        uniqueArr.erase(unique(uniqueArr.begin(), uniqueArr.end()), uniqueArr.end());
        for(int i = 0; i<uniqueArr.size(); ++i){
            rankMap[uniqueArr[i]] = i +1;

        }
        vector<int>result;
        for(int num: arr){
            result.push_back(rankMap[num]);

        }
        return result;
    }
};