class Solution
{
#define pii pair<int, int>
#define pip pair<int, pii>

    bool isValid(int &x, int &y, int &m, int &n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        // Step 1: Initialize variables
        set<int> sorted_queries(queries.begin(), queries.end());
        unordered_map<int, int> query_count;
        priority_queue<pip, vector<pip>, greater<pip>> minheap;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> dir = {-1, 0, 1, 0, -1};

        // Start BFS from top-left corner
        minheap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        int count = 0;

        // Step 2: Process each query using greedy approach
        for (auto query : sorted_queries)
        {
            while (!minheap.empty())
            {
                pip curr = minheap.top();
                int val = curr.first;
                int x = curr.second.first;
                int y = curr.second.second;

                // If value is >= query, break
                if (val >= query)
                    break;

                minheap.pop();
                count++;

                // Explore neighbors
                for (int i = 0; i < 4; i++)
                {
                    int newX = x + dir[i];
                    int newY = y + dir[i + 1];

                    if (isValid(newX, newY, m, n) && !visited[newX][newY])
                    {
                        visited[newX][newY] = true;
                        minheap.push({grid[newX][newY], {newX, newY}});
                    }
                }
            }
            query_count[query] = count;
        }

        // Step 3: Build result using original query order
        vector<int> answer;
        for (auto query : queries)
        {
            answer.push_back(query_count[query]);
        }

        return answer;
    }
};