class Solution {
public:
    string intToBinary(int n) {
        string binary = "";
        while (n > 0) {
            binary = (n % 2 == 0 ? "0" : "1") + binary;
            n /= 2;
        }
        return binary.empty() ? "0" : binary;
    }
    int minimizeXor(int num1, int num2) {
        string a = intToBinary(num1);
        string b = intToBinary(num2);
        int x=0;
        for(int i=0;i<b.length();i++){
            if(b[i]=='1'){
                x++;
            }
        }
        string s="";
        for(int i=0;i<a.length();i++){
            if(a[i]=='1' && x>0){
                s+='1';
                x--;
            }else{
                s+='0';
            }
        }
        int i=s.length()-1;
        while(x>0){
            if(i<s.length()){
                if(s[i]=='0'){
                    s[i] = '1';
                    x--;
                }
                i--;
            }else{
                s='1'+s;
                x--;
            }
        }
        int res=0;
        int j=0;
        for(int i=s.length()-1; i>=0; i--){
            res+= (s[i]-'0')*(pow(2,j));
            j++;
        }
        return res;
    }
};