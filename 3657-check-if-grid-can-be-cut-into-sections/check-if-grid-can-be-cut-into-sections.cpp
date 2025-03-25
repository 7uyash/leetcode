class Solution {
private:
    int count(vector<vector<int>>& ivs){
        int c=0,p=-1;
        for(int i=0;i<ivs.size();i++){
            int st=ivs[i][0],ed=ivs[i][1];
            if(p<=st){
                c++;
                p=ed;
            }
            else{
                p=max(ed,p);
            }
        }
        return c;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;
        for(const auto& i:rectangles){
            x.push_back({i[0],i[2]});
            y.push_back({i[1],i[3]});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        return max(count(x),count(y))>=3;
    }
};