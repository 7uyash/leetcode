class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        while(n > 1){
            int count = 1;
            string s ="";
            for(int i = 0 ; i <= ans.size() - 1; i++){
                if(ans[i] == ans[i+1])count++;
                else {
                    s.push_back('0' + count);
                    s.push_back(ans[i]);
                    count = 1;
                }
            }
            ans = s;
            n--;
        }
        return ans;
    }
};