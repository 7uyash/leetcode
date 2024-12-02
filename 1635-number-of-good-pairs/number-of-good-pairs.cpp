class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        vector<int>num = nums;
        int s = num.size();
        for(int i = 0; i<s; i++){
            int a = num[i];
            for(int j = i+1; j<s; j++){
                int b = num[j];
                if(num[i]==num[j]){
                    count++;
                }
            }
        }
        return count;
    }
};