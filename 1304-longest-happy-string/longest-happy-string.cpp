class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result;
        vector<pair<int,char>>counts = {{a, 'a'}, {b,'b'}, {c,'c'}};
        while(true){
            sort(counts.rbegin(), counts.rend());
            int maxCount = counts[0].first;
            int maxChar = counts[0].second;

            if(maxCount ==0) break;
            if(result.size()>=2 && result[result.size()-1]==maxChar && result[result.size()-2]==maxChar){
                if(counts[1].first ==0) break;
                result += counts[1].second;
                counts[1].first--;

            }else{
                result += maxChar;
                counts[0].first--;
            }
        }
        return result;
    }
};