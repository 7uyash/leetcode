class Solution {
public:
    bool solve(vector<int>&d , int zero){
        int prev = d[0]^zero;
        int first = prev;
        //store the first element to check for last element of derived
        //array :
        int n = d.size();
        for (int i=0;i<n-1;i++){
            prev = prev^d[i];
        }
        int temp = prev^d[0];
        if (d[n-1]==prev^first){
            return true;
        }
        return false;
    }
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size();
        int flag1 = solve(d,0);
        int flag2 = solve(d,1);
        if (flag1 || flag2){
            return true;
        }
        return false;
    }
};