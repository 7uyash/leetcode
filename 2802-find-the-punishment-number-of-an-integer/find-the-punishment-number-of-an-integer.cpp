class Solution {
public:
bool flag = false;
void backtracking(string num, int start_idx, int cur_sum, int prev_interval, int target) {
        if (start_idx == num.size() - 1) {
            cur_sum += stoi(num.substr(prev_interval + 1, start_idx - prev_interval));
            if (cur_sum == target) {
                flag = true;
            }
            return;
        }
        backtracking(num, start_idx + 1, cur_sum + stoi(num.substr(prev_interval + 1, start_idx - prev_interval)), start_idx, target);
        backtracking(num, start_idx + 1, cur_sum, prev_interval, target);
    }
    bool can_split(int square, int i) {
        if ((square - i) % 9 != 0) {
            return false;
        }
        string num = to_string(square);
        backtracking(num, 0, 0, -1, i);
        if (flag) {
            return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int temp = i * i;
            flag = false; 
            if (can_split(temp, i)) {
                res += i * i;
            }
        }
        return res;
    }
};