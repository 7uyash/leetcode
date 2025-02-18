class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxi = 0;
        unordered_set<int>mpp;
        for(int right = 0;right<s.size();right++){
            if(mpp.find(s[right]) != mpp.end()){
                while(left<right && mpp.find(s[right]) != mpp.end()){
                    mpp.erase(s[left]);
                    left++;
                }
            }
            mpp.insert(s[right]);
            maxi = max(maxi,right-left+1);
        }
    return maxi;
    }
};