class Solution {
public:
    int find_lr(vector<int>&ar,int maxi,vector<int>&heights,vector<int>&st){
    int l=0,h=ar.size()-1;
    int ans=heights.size();
    while(l<=h){
        int m=l+(h-l)/2;
           // cout<<"m= "<<m<<" mv= "<<heights[m]<<" maxi= "<<maxi<<endl;
        if(heights[st[m]]>=maxi){
            ans=m;
            l=m+1;
        }
        else h=m-1;        
    }
      // cout<<"maxi= "<<maxi<<" ans= "<<ans<<endl;
    return ans;
}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& fake_queries) {
         // let's first of all make the every pair of query as smaller to larger!
        for(auto&v:fake_queries){
            if(v[0]>v[1])swap(v[0],v[1]);
        }
        // after this we will sort the query in the decreasing form of the ending values, menas from 9 to 6 to 3 to 2...
        // but as we are sorting we should also remember thier indexes so that we can put thier ans on valid indexes.
        // so we will make our own query 
        vector<vector<int>>queries;
        int n=fake_queries.size();vector<int>ans(n);
        for(int i=0;i<n;i++){
            int a=fake_queries[i][0],b=fake_queries[i][1];
            queries.push_back({a,b,i});
        }
        sort(queries.begin(),queries.end(),[&](auto&a,auto&b){
            if(a[1]>b[1])return 1;
            return 0;
        });
        // for(auto&v:queries){
        //     cout<<v[0]<<" "<<v[1]<<" -> ";
        // }cout<<endl;

        // after this we will maintain a monotonnic stack in the form of vector, where we will be managaing the vector from the end
        // so that each operation is handled from the back in just O(1).
        vector<int>st;
        int last_traversal=heights.size();
        for(int i=0;i<n;i++){
            int cst=queries[i][0];
            int cend=queries[i][1];
            int indx_of_query=queries[i][2];
            int maxi=max(heights[cst],heights[cend]);
            while(last_traversal>cend+1){
                // menas we have to travese our monotonic stack till here!
                last_traversal--;
                int val=heights[last_traversal];
                while(st.size()>0&&val>=heights[st[st.size()-1]])st.pop_back();
                st.push_back(last_traversal);
            }
            // for(auto&x:st)cout<<heights[x]<<" ";cout<<endl;
            // remember the case where the b point's value is itself greater than a's value -> so just take the b
            int mini=heights[cend]>heights[cst]?cend:heights.size();
            if(cst==cend)mini=cst;
            // also check in the monotonic stack through binary search
            int indx2=find_lr(st,maxi+1,heights,st);
            if(indx2!=heights.size())indx2=st[indx2];
            // cout<<"indx2= "<<indx2<<endl;
            mini=min(mini,indx2);
            if(mini==heights.size())mini=-1;
            ans[indx_of_query]=mini;
        }
        return ans;
    }
};