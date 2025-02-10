class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand= 0;
        int count = 0;
        for(auto num: nums){
            if(count==0){
                cand = num;
            }
            count += (num== cand)?1: -1;
        }
        return cand;
    }
};