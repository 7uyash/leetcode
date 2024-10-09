class Solution {
public:
    int minAddToMakeValid(string s) {
        int op=0;
        int cs = 0;
        for(char c: s){
            if(c=='('){
                op++;
            }else if(c==')'){
                if(op>0){
                    op--;
                }else{
                    cs++;
                }
            }
        }
        return op + cs;
    }
};