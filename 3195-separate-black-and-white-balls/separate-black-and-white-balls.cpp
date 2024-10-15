class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        long long blackCount = 0;

        for(char c: s){
            if ( c== '1'){
                blackCount++;
            }else{
                count += blackCount;
            }
        }
        return count;
    }
};