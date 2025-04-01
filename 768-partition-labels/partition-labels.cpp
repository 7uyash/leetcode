class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> idx(26, vector<int> (2, -1));
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(idx[s[i]-'a'][0] == -1)idx[s[i]-'a'][0] = i;
            idx[s[i]-'a'][1] = i;
        }
        vector<int> ans;
        int si = 0, ei = 0;
        for(int i = 0; i < n; i++){
            if(i <= ei){
                ei = max(ei, idx[s[i]-'a'][1]);
            }
            else{
                ans.push_back(ei-si+1);
                si = i;
                ei = idx[s[i] - 'a'][1];
            }
        }
        ans.push_back(n-si);
        return ans;
    }
};