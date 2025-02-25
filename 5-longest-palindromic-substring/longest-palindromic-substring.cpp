class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        for(int i=0;i<s.size();i++){
            string x;
            x+=s[i];
            if(x.size()>str.size()){
                str=x;
            }
            for(int j=i+1;j<s.size();j++){
                x+=s[j];
                bool ok=true;
                int l=0,r=x.size()-1;
                while(l<r){
                    if(x[l]!=x[r]){
                        ok=false;
                        break;
                    }
                    l++,r--;
                }
                if(ok==true){
                    if(x.size()>str.size()){
                        str=x;
                    }
                }
            }
        }
        return str;
    }
};