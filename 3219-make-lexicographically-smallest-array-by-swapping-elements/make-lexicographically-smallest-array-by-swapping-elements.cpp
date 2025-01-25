class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = int(nums.size());
        vector<int> a(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        int cnt=0;
        vector<queue<int>> vst(n);
        map<int,int> group;
        group[a[0]] = 0;
        vst[0].push(a[0]);
        for(int i=1; i<n; i++){
            if( a[i] - a[i-1] > limit ){
                cnt++;
            }
            
            group[a[i]] = cnt;
            vst[cnt].push(a[i]);
        }
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            ans[i] = vst[group[nums[i]]].front();
            vst[group[nums[i]]].pop();
        }
        return ans;
    }
};