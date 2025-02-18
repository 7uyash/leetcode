class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";

        stack<int> st;
        int cnt = 1;

        for (int i = 0; i <= n; i++) {
            st.push(cnt);
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    int num = st.top();
                    st.pop();
                    ans.push_back(num + '0');
                }
            }
            cnt++;
        }

        return ans;
    }
};