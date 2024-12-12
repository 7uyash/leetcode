class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        while (k-- > 0) {
            int maxGifts = maxHeap.top(); 
            maxHeap.pop(); 
            maxHeap.push(static_cast<int>(sqrt(maxGifts))); 
        }
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }
        
        return totalGifts;
    }
};