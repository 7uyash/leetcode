class Solution {
public:
int mini1,mini2;
int node1,node2;
int ans;
bool f;
int dfs(int node,vector<vector<int>>&adj,unordered_map<int,vector<int>>&mp,unordered_map<int,int>&ht,int prnt){
    // Height of the current node will be max_child's height +1
    for(auto&child:adj[node]){
        if(child==prnt)continue;
        int cht=dfs(child,adj,mp,ht,node);//child ht
        ht[node]=max(ht[node],cht+1);
        mp[node].push_back(cht);
    }
    return ht[node]=max(1,ht[node]);
}
void make_it_correct_BAY(int node,vector<vector<int>>&adj,unordered_map<int,vector<int>>&mp,unordered_map<int,int>&ht,int prnt){
    // cout<<"node= "<<node<<" prnt= "<<prnt<<" ht= "<<ht[node]<<endl;
    // Now let's see the prrnt children ht's table.
    // and try to update out
    if(prnt!=-1){
        int maxi=0;bool f1=0;
        for(int&x:mp[prnt]){
             // cout<<"cht= "<<x<<" ";
            if(x==ht[node]&&!f1){f1=1;continue;}
            maxi=max(maxi,x);
        }
         //  cout<<"maxi= "<<maxi<<endl;
        maxi++;
        mp[node].push_back(maxi);
        ht[node]=max(ht[node],maxi+1);
        
    }
    // decinding for whose tree we have to chk or maintain
        if(!f){
            if(ht[node]<mini1){
                mini1=ht[node];
                node1=node;
            }
        }
        else{
            if(ht[node]<mini2){
                mini2=ht[node];
                node2=node;
            }
        }

        // deciding the diameter of this node. -> which is max child ht1+2
        int maxi2=0;int maxi=0;
        for(int&x:mp[node]){
            if(x>maxi){
                maxi2=maxi;
                maxi=x;
            }
            else {maxi2=max(maxi2,x);}
        }
        ans=max(ans,maxi+maxi2);
    // do this same for all it's child also
    for(int&x:adj[node]){
        if(x!=prnt){
            make_it_correct_BAY(x,adj,mp,ht,node);
        }
    }
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        ans=0;
        // so let's do it !
        // let's first of all , we find out heights of tree and then real heights
        // Creating Graphs
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>>adj(n),adj2(m+n);
        for(auto&v:edges1){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        for(auto&v:edges2){
            adj2[v[0]+n].push_back(v[1]+n);
            adj2[v[1]+n].push_back(v[0]+n);
        }
        // let's now find out the height of every node as of like we do in tree
        // We will take a map for storing the heights of child of the crnt node
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>ht;
        // we will store 2nd tree nodes in negative
        // LET'S TRAVERSE THE TREES!
        // We can take any node as the root node as -> which ever u select diameter of the tree will be same
        // so let's take it 0 for the simplicity
        dfs(0,adj,mp,ht,-1);
        dfs(n,adj2,mp,ht,-1);
        // now let's make thier ht's value -> RIGHT! as this is Graph BAY!
        mini1=mini2=INT_MAX;
        f=0;ans=0;
        make_it_correct_BAY(0,adj,mp,ht,-1);f=1;
        make_it_correct_BAY(n,adj2,mp,ht,-1);
        // taking the nodes from tree1 and tree2 which are having least height
        // debugging
        // for(int i=0;i<n;i++){
        //     cout<<"node= "<<i<<endl;
        //     for(int &x:mp[i])cout<<x<<" ";
        //     cout<<endl;
        // }cout<<endl;
        // for(int i=n;i<n+m;i++){
        //     cout<<"node= "<<i<<endl;
        //     for(int &x:mp[i])cout<<x<<" ";cout<<endl;
        // }cout<<endl;
        // cout<<"====="<<endl;

         cout<<"mini1= "<<mini1<<" 2= "<<mini2<<" n1= "<<node1<<" 2= "<<node2<<endl;
        ans=max(ans,ht[node1]+ht[node2]-1);
        return ans;
    }
};