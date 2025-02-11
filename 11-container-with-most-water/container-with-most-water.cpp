class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx = 0, curr= 0, l = 0;
        int r = height.size()-1;
        while(l<=r){
            curr = min(height[l], height[r])*(r-l);
            mx = max(curr, mx);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return mx;
    }
};