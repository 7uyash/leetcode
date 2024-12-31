class Solution {
public:
    int get_ans(vector<int>& days, vector<int>& costs,int i,int validity,vector<vector<int>>&dp){
    if(i>=days.size()) return 0;
    if (dp[i][validity]!=-1) return dp[i][validity];
    int ans=0;
    if(validity<days[i]){
    ans=min({costs[0]+get_ans(days,costs,i+1,days[i]+1-1,dp),
    costs[1]+get_ans(days,costs,i+1,days[i]+7-1,dp),costs[2]+get_ans(days,costs,i+1,days[i]+30-1,dp)});
    }
    else ans=get_ans(days,costs,i+1,validity,dp);
    return dp[i][validity]=ans;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>>dp(366,vector<int>(396,-1));
        return get_ans(days,costs,0,0,dp);
    }
};