class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1= s1.length(), len2= s2.length();
        if(len1>len2){
            return false;
        }
        vector<int>count1(26, 0);
        vector<int>count2(26, 0);

        for(char c : s1){
            count1[c-'a']++;
        }
        for(int i = 0; i<len1; i++){
            count2[s2[i]-'a']++;

        }
        if(count1==count2){
            return true;
        }
        for(int i = len1; i<len2; i++){
            count2[s2[i]-'a']++;
            count2[s2[i-len1]-'a']--;
            if(count1==count2){
                return true;
            }
        
        }
    return false;
    }
};