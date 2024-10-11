class Solution {
public:
    int smallestChair(vector<vector<int>>& intervals, int target) {
       int total = intervals.size();
        
        vector<int> index(total);
        for (int i = 0; i < total; ++i) index[i] = i;

        sort(index.begin(), index.end(), [&intervals](int a, int b) {
            return intervals[a][0] < intervals[b][0];
        });

        priority_queue<int, vector<int>, greater<int>> availableSeats;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedSeats;

        for (int i = 0; i < total; ++i) availableSeats.push(i);

        for (int idx : index) {
            int arrivalTime = intervals[idx][0];
            int departureTime = intervals[idx][1];

            while (!occupiedSeats.empty() && occupiedSeats.top().first <= arrivalTime) {
                availableSeats.push(occupiedSeats.top().second);
                occupiedSeats.pop();
            }

            int chair = availableSeats.top();
            availableSeats.pop();

            if (idx == target) return chair;

            occupiedSeats.push({departureTime, chair});
        }

        return -1;
    }
};