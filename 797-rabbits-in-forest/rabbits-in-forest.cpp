class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(int &x:answers) mp[x]++;

        int ans=0;
        for(auto &it:mp){
            int x=it.first;
            int count=it.second;

            int groupSize=x+1;
            int groups=ceil((double)count/groupSize);

            ans+=groups*groupSize;
        }
        return ans;
    }
};