class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>arr;
        vector<int>num= nums;
        int s = num.size();
        for(int i = 0; i<s; i++){
            for(int j = i+1;j<s; j++ ){
                int a = num[j];
                if(num[i]==a){
                    arr.push_back(a);
                }
            }
        }
        return arr;
    }
};