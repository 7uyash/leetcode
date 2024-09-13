class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n= arr.size();
        vector<int>prefixXOR(n+1, 0);
        for(int i = 1; i<=n ; ++i){
            prefixXOR[i]= prefixXOR[i-1]^arr[i-1];

        }
        vector<int> answer;
        for(const auto& query : queries){
            int left = query[0], right = query[1];

            answer.push_back(prefixXOR[right+1]^prefixXOR[left]);

        }
        return answer;
    }
};