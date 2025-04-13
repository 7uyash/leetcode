class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2, odd = n / 2;
        return (power(5, even) * power(4, odd)) % mod;
    }

    long long power(int a, long long b) {
        if (b == 0)
            return 1;
        long long x = power(a, b / 2);
        if (b % 2 == 0)
            return (x * x) % mod;
        else
            return (((a * x) % mod) * x) % mod;
    }
};