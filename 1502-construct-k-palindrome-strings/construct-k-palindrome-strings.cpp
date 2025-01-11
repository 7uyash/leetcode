class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)
        {
            return false;

        }
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
         for(auto i:mp)
        {
            cout<<i.first<<""<<i.second;
             cout<<endl;
        }
        int c=0;
        for(auto &i:mp)
        {
            
            if((i.second)%2!=0)
            c++;


        }
        cout<<c<<"";
        return c>k?false:true;
    }
};