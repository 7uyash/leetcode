class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(const auto& interval : intervals){
            if(!minHeap.empty() && interval[0]>minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(interval[1]);
        }
        return minHeap.size();
    }
};