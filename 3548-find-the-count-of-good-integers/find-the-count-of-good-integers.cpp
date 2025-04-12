class Solution {
public:
    long long fact[11];
    set<vector<int>>st;

    long long countGoodIntegers(int n, int k) {
        preComputeFact();
        string s;
        for (int i = 0; i < n; i++) {
            s += '0';
        }
        return helper(0,n,k,s);
    }
    long long helper(int index, int n, int k, string& s) {

        if (index >= (n / 2 + 1)) {
            long long temp = stoll(s);
            if(temp % k !=0){
                return 0;
            }
            vector<int> freq(10, 0);
            for (auto digit : s) {
                freq[digit - '0']++;
            }
            if(st.count(freq)){
                return 0;
            }
            st.insert(freq);
            long long count = fact[n];

            for (auto f : freq) {
                count /= fact[f];
            }
            if(freq[0] == 0){
                return count;
            }

            //now fix 0 at 1st position and calculate all invalid 


            freq[0]--;
            long long invalid = fact[n-1];

            for (auto f : freq) {
                invalid /= fact[f];
            }
            return count - invalid;
        }

        long long count = 0;

        for (char digit = '0'; digit <= '9'; digit++) {
            if (index == 0 && digit == '0'){
                    continue;
                }
            s[index] = s[n - 1 - index] = digit;
            count += helper(index + 1, n, k, s);
        }

        return count;
    }
    void preComputeFact() {
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i <= 10; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }
};