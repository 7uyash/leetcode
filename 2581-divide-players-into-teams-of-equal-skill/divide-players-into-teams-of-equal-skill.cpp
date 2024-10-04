class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        long long totalSkill = 0;
        int n = skill.size();
        int targetSum = skill[0] + skill[n - 1];


        for (int i = 0; i < n / 2; ++i) {
            int currentSum = skill[i] + skill[n - 1 - i];
            if (currentSum != targetSum) {
                return -1;
            }
            totalSkill += static_cast<long long>(skill[i]) * skill[n - 1 - i];
        }

        
        return totalSkill;
    }
};