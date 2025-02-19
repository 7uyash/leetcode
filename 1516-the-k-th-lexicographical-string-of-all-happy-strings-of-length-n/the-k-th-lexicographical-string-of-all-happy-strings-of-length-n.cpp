class Solution {
public:

    int k_, m;
    string ans = "";
    void f(string &s){
        if(s.size()==m){
            k_--;
            if(k_==0){
                ans = s;
                return ;
            }
            return ;
        }
        for(char c = 'a'; c<='c'; c++){
            if(s.size()>0 && s.back()==c){
                continue;
            }
            s.push_back(c);
            f(s);
            s.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        m = n;
        k_ = k;
        string s = "";
        f(s);
        return ans;
    }
};