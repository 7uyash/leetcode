class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=1,right=n-1,c,mid;
        while (left<right){
            mid=(left+right)/2;
            c=0;
            for(int i=0;i<n;i++)
                if(nums[i]<=mid)
                    c++;
            if (c>mid)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};