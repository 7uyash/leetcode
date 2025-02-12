class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int>a;
        for(int i: nums){
            a[i]++;
        }
        int ans = 0;
        for(auto i : a){
            if(i.second>1){
                ans = i.first;
                break;
            }


        }
        return ans;
    }
};