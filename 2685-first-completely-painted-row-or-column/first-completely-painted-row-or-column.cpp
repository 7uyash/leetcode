class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    
    // Map to store the position of each element in the matrix
    // Key: Matrix value, Value: Linear index (row * cols + col)
    unordered_map<int, int> positionMap;
    
    // Vectors to keep track of the count of marked elements in each row and column
    vector<int> rowCount(rows, 0), colCount(cols, 0);

    // Populate the positionMap with the position of each element in the matrix
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            positionMap[mat[r][c]] = r * cols + c; // Store linear index
        }
    }

    // Iterate through the elements in the `arr` vector to simulate marking the elements
    for (int i = 0; i < arr.size(); i++) {
        int val = arr[i]; // Current value to mark

        // Retrieve the row and column of the current value using the positionMap
        int row = positionMap[val] / cols; // Extract row index from linear index
        int col = positionMap[val] % cols; // Extract column index from linear index

        // Increment the count of marked elements for the corresponding row and column
        if (++rowCount[row] == cols || ++colCount[col] == rows) {
            // If the current row or column is completely marked, return the current index
            return i;
        }
    }

    // If no row or column gets completely marked, return -1
    return -1;
}
};