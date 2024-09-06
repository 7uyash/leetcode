class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = (m+n)* mean;
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = totalSum - currentSum;
        if(missingSum<n || missingSum>6*n){
            return {};
        }
        vector<int>missing(n, missingSum/n);
        int remainder = missingSum%n;
        for(int i =0; i<remainder; ++i){
            missing[i]++;
        }
        return missing;
    }
};