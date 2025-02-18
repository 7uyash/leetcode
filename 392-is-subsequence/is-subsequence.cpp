class Solution {
public:
    bool isSubsequence(string s, string t) {
         int n = s.size();
         int p = t.size();
         int i =0 , j =0;

        while(i<n && j<p){
            if(s[i] == t[j]){
                i++, j++;  
            } else{
                j++;
            }
        
        }
        if(i==n) {
            return true;
        }
        return false;
    }   
};