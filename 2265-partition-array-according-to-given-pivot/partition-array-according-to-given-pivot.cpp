class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>arr(n,pivot);
        int k=0,l=n-1;
        for(int i=0;i<n;i++){
             int idx=n-1-i;
            if(pivot > nums[i]) arr[k++]=nums[i];
            if(pivot < nums[idx]) arr[l--]=nums[idx];
        }
        return arr;
    }
};