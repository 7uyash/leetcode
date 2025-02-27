class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        long long int n=arr.size(),ans=0,cnt=0,last=0;
        for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                 long long int sum=arr[i]+arr[j];
                 cnt=2;
                 last=arr[j];
                 while(binary_search(arr.begin(),arr.end(),sum)){
                     long long int temp=sum;
                     sum=last+sum;
                     last=temp;
                     cnt++;
                 }
                 ans=max(ans,cnt);

             }
        }
        return  ans==2?0:ans;
    }
};