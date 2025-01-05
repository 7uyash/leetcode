class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> pre_sum(n+1, 0);

        for(auto& shift: shifts){
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];

            pre_sum[start] += (dir == 0 ? -1 : 1);
            pre_sum[end+1] += (dir == 0 ? 1 : -1);
        }


        for(int i=1; i<=n; i++){
            pre_sum[i] += pre_sum[i-1];
        }

        string ans = "";
        for(int i=0; i<n; i++){
            ans += 'a' + ((s[i] - 'a' + pre_sum[i])%26 + 26)%26;
        }

        return ans;
    }
};