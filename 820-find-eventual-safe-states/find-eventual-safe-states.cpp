class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> rev(graph.size());


        for (int i = 0;i<graph.size();i++) {
            for (int b = 0;b<graph[i].size();b++) {
                rev[graph[i][b]].push_back(i);
            }
            
        }

        vector<int> marked(graph.size(),0);

        queue<int> bfs;

        for (int i = 0;i<graph.size();i++) {
            if (graph[i].size()==0) {
                for (int b = 0;b<rev[i].size();b++) {
                    bfs.push(rev[i][b]);
                }
                marked[i]=1;
            }
        }

        while (!bfs.empty()) {
            queue<int> temp;

            while (!bfs.empty()) {
                int i;

                for (i=0;i<graph[bfs.front()].size();i++) {
                    if (marked[graph[bfs.front()][i]]&&!marked[bfs.front()]) {
                        continue;
                    }

                    break;
                }

                if (i==graph[bfs.front()].size()||graph[bfs.front()].size()==0) {
                    marked[bfs.front()]=1;
                    for (int x = 0;x<rev[bfs.front()].size();x++) {
                        temp.push(rev[bfs.front()][x]);
                    } 
                }

                bfs.pop();
            }

            bfs = temp;
        }

        vector<int> res;


        for (int i = 0;i<marked.size();i++) {
            if (marked[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};