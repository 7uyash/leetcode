class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>res;
    
        dfs(n, "",res);
        return res;
        
    }
    private:
        void dfs(int n, string curr, vector<string>& res){
            
            if(curr.size()==n){
                if(isValid(curr)){
                    res.push_back(curr);}
                return;
            }
    
                dfs(n, curr+"0", res);
                dfs(n, curr+"1", res);
        
               
        }
    bool isValid(string s){
        for(int i=0;i<s.size()-1; i++){
            if(s[i]=='0' && s[i+1]=='0'){
                return false;
            }
        }
            return true; 
        }
            
    
    
};