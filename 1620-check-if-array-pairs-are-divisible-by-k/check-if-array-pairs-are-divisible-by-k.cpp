class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int>remainderCount;
        for(int num : arr){
            int remainder = ((num%k)+k)%k;
            remainderCount[remainder]++;
        }

        for(int i = 0; i<=k/2; ++i){
            if(i==0){
                if(remainderCount[i]%2 != 0){
                    return false;
                }
            }else if (i ==k-i){
                if(remainderCount[i]%2 != 0){
                    return false;
                }
            }else{
                if(remainderCount[i]!=remainderCount[k-i]){
                    return false;
                }
            }
        }
        return true;
    }
};