class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int l = 0, r = 1;
        int count = 0;

        while (r < (n + (k - 1))){
            if (colors[r % n] == colors[(r - 1) % n]){
                l = r;
            }

            if (r - l + 1 > k)
                l++;

            if (r - l + 1 == k)
                count++;

            r++;
        }
        return count;
    }
};