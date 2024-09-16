class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        bool minutes[1440] = {false};

        for(const auto& time : timePoints){
            int hour = stoi(time.substr(0, 2));
            int min = stoi(time.substr(3, 2));
            int totalMin = hour *60 + min;
            if(minutes[totalMin]) return 0;
            minutes[totalMin]= true;
        }
        int prevT =  -1;
        int firstT = -1;
        int minDiff = INT_MAX;
        for(int i =0; i<1440; i++){
            if(minutes[i]){
                if(firstT == -1){
                    firstT = i;
                }
                if(prevT != -1){
                    minDiff = min(minDiff, i-prevT);

                }
                prevT = i;
            }
        }
        if(prevT != -1){
            minDiff = min(minDiff, (1440-prevT+firstT));

        }
        return minDiff;
    }
};