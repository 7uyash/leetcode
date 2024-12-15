class Solution {
public:
   // Function to pass ratio improvement cal. krne k liye 
double getDelta(int pass, int total) {
    return (double)(pass + 1) / (total + 1) - (double)pass / total;
}

double maxAverageRatio(vector<vector<int>>& classes, int k) {
    priority_queue<pair<double, pair<int, int>>> pq;

          int pass , total ;
    for(int i =0 ; i<classes.size();i++){
            int pass = classes[i][0];
            int total = classes[i][1];
    // yha pr sab me 1 add krke unka increasing ratio kitna hai vo aur pair store kr diye 
           pq.push({getDelta(pass,total),{pass,total}}) ;
    }

    // abb assign krenge extra wale ko 
        while(k--){
            // top wal me increment jyda hoga iske pass and total value ko increse krenge 
            int pass = pq.top().second.first ; 
            int total  =  pq.top().second.second ; 
            pass++ ;
            total++ ; 
            // top ko remove krke new increment ratio wala value re-insert krenge 
            pq.pop();
            pq.push({getDelta(pass,total),{pass,total}}) ; 

        }

        double avg = 0.0 ; 
        while(!pq.empty()){
            int pass = pq.top().second.first ; 
            int total  =  pq.top().second.second ; 
            avg += (double)pass / total ;    // double value k liye type caste kiye hai 
            pq.pop() ;  
        }
        return avg/classes.size() ; 
    }
};