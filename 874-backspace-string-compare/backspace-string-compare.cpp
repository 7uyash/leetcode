class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char> st;
        for(char c : s){
            if(c=='#' && st.empty()) continue;
            else if(c=='#') st.pop();
            else st.push(c);
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }

        for(char c : t){
            if(c=='#' && st.empty()) continue;
            else if(c=='#') st.pop();
            else st.push(c);
        }
        t="";
        while(!st.empty()){
            t+=st.top();
            st.pop();
        }
        return s==t; 
    }
};