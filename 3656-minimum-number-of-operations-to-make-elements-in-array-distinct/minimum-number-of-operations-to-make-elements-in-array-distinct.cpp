class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int n=v.size(); 
        unordered_map<int,int>frq; 
        for(int i=n-1;i>=0;--i){
            if(frq[v[i]]){
                return ((i+3)/3); 
            }
            frq[v[i]]++;
        }
        return 0;
        
    }
};