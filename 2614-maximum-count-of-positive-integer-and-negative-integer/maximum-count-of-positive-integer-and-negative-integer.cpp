class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0, n = nums.size();
        int l = 0, h = n - 1;

        while(l <= h) {
            int mid = (l + h) / 2;
            if(nums[mid] < 0 && (mid + 1 == n || nums[mid + 1] >= 0)) {
                neg += (mid + 1);
                break;
            }
            if (nums[mid] >= 0) {
                h = mid - 1;
            }
            else l = mid + 1;
        }
        l = neg - 1, h = n - 1;
        while(l <= h) {
            int mid = (l + h) / 2;
            if(nums[mid] > 0 && (mid - 1 < 0 || nums[mid - 1] <= 0)) {
                pos += (n - mid);
                break;
            }
            if (nums[mid] <= 0) {
                l = mid + 1;
            }
            else h = mid - 1;
        }

        cout << neg << pos;
        return max(pos, neg);
    }
};