class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>q;
        for(int i:nums){
            q.push(i);
        }
        int operations=0;
        while(q.top()<k){
            long long x=q.top();
            q.pop();
            long long y=q.top();
            q.pop();
            long long new_elem = x*2+y;
            q.push(new_elem);
            operations++;
        }
        return operations;
    }
};