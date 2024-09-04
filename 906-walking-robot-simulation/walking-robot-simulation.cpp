class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>>directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>>obstacleSet;
        for(const auto& obstacle : obstacles){
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }
        int x = 0, y = 0;
        int directionIndex = 0;
        int maxDistanceSquared = 0;

        for(int command : commands){
            if(command == -2){
                directionIndex = (directionIndex + 3)%4;

            }else if(command == -1){
                directionIndex = (directionIndex + 1)%4;
            }else{
                for(int step = 0; step<command; ++step){
                    int newX = x+directions[directionIndex].first;
                    int newY = y + directions[directionIndex].second;

                    if(obstacleSet.count({newX, newY})==0){
                        x = newX;
                        y = newY;

                        maxDistanceSquared = max(maxDistanceSquared, x*x + y*y);

                    }else{
                        break;
                    }
                }
            }
        }
        return maxDistanceSquared;
    }
};