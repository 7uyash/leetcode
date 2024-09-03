class Solution {
public:
    int getLucky(string s, int k) {
        string converted = "";
        for(char ch : s){
            int value = ch - 'a' +1;
            converted += to_string(value);

        }
        int result = 0;
        for(char ch : converted){
            result += ch -'0';
        }
        for(int i = 1; i<k; ++i){
            int temp =0;
            while(result>0){
                temp += result % 10;
                result /= 10;
            }
            result = temp;
        }
        return result;
    }
};