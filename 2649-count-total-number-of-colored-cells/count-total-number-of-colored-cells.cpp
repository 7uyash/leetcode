class Solution {
public:
    long long coloredCells(int n) {
        long long a = 2*(pow(n, 2) -n)+1;
        return a;
    }
};