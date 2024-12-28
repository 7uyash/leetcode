class Solution {
public:
    vector<pair<int,int>> solve1(vector<int> &arr,int k,int n)
    {
        vector<pair<int,int>> temp(n,{0,0});
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr+=arr[i];
            if(i>=k-1)
            {
                if(i==0)
                {
                    temp[i].first=i;
                    temp[i].second=curr;
                }
                else 
                {
                    temp[i]=temp[i-1];
                    if(temp[i-1].second<curr)
                    {
                        temp[i].second=curr;
                        temp[i].first=i-k+1;
                    }
                }
                curr-=arr[i-k+1];
            }
        }
        return temp;
    }
    vector<pair<int,int>> solve2(vector<int> &arr,int k,int n)
    {
        vector<pair<int,int>> temp(n,{0,0});
        int curr=0;
        for(int i=n-1;i>=0;i--)
        {
            curr+=arr[i];
            if(i<=n-k)
            {
                if(i==n-1) 
                {
                    temp[i].first=i;
                    temp[i].second=curr;
                }
                else 
                {
                    temp[i]=temp[i+1];
                    if(temp[i+1].second<=curr)
                    {
                        temp[i].second=curr;
                        temp[i].first=i;
                    }
                }                
                curr-=arr[i+k-1];
            }
        }
        return temp;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<pair<int,int>> left=solve1(arr,k,n);
        vector<pair<int,int>> right=solve2(arr,k,n);
        // for(auto itr:left) cout<<itr.first<<" "<<itr.second<<" ";
        // cout<<endl;
        // for(auto itr:right) cout<<itr.first<<" "<<itr.second<<" ";
        // cout<<endl;
        int curr=0;
        vector<int> ans;
        int best_sum=0;
        for(int i=k;i<=n-k-1;i++)
        {
            curr+=arr[i];
            if(i>=(2*k-1))
            {
                int curr_sum=curr+left[i-k].second+right[i+1].second;
                if(curr_sum>best_sum)
                {
                    best_sum=curr_sum;
                    ans={left[i-k].first,i-k+1,right[i+1].first};
                }
                curr-=arr[i-k+1];
            }
        }
        return ans; 
    }
};