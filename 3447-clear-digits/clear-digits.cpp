class Solution {
public:
    string clearDigits(string s) {
        string st;
        for(auto i : s){
            if(i>='0' && i<='9'){
                if(!st.empty()){
                    st.pop_back();
                }
            }else{
                st.push_back(i);
            }
        }
        return st;
    }
};