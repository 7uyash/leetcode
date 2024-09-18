class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>strNums;
        for(int num : nums){
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b){
            return a+b>b+a;
        });
        if(strNums[0]=="0"){
            return "0";
        }
        string largestNum;
        for(const string& str : strNums){
            largestNum +=str;
        }
        return largestNum;
    }
};