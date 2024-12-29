class Solution {
public:
    
    int mod= 1e9+7;
    
    int recur(vector<string>& words, string& target, int i, int j, vector<vector<int>> &dp, map<pair<char,int>, int>& charatidxfreq)
    {
        if(j== target.size()) return 1;
        
        if(i== words[0].size()) return 0; //Base cases
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long ways=0;
        
        if(charatidxfreq[{target[j],i}]!=0) // Now this operation becomes O(1)
        {
            ways+= recur(words,target,i+1,j+1,dp, charatidxfreq);
            ways%= mod;
            ways*= (charatidxfreq[{target[j],i}]%mod); //find ways and the multiply by frequency
            ways%= mod;
        }
        
        ways+= recur(words,target,i+1,j,dp, charatidxfreq);
        ways%= mod;
        
        return dp[i][j]= ways%mod;
        
    }
    
    int numWays(vector<string>& words, string target) {
        
        int n= words[0].size();
        int m= target.size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        unordered_map<int, set<char>> idxTochar;
        
        map<pair<char,int>, int> charatidxfreq;
        
        for(auto word: words)
        {
            for(int i=0;i<word.size();i++)
            {   
                charatidxfreq[{word[i],i}]++;
            }
        }
        
        return recur(words,target,0,0, dp, charatidxfreq);
    }
};