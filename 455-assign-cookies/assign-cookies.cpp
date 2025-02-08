class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());

        sort(s.begin(), s.end());
        int t= 0, i =0, j =0;
        for(i; i<g.size() && j<s.size(); ){
            if(s[j]>=g[i]){
                t++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return t;
    }
};