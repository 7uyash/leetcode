class Solution 
{
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        long x = 0, mi = 0, mx = 0;

        for (int d : differences) 
        {
            x += d;
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return max((int)(upper - lower - (mx - mi) + 1), 0);
    }
};