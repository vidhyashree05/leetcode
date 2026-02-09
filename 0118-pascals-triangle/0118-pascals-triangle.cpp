class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        // Loop for each row
        for (int i = 0; i < numRows; i++) {

            // Create row with (i + 1) elements, all initialized to 1
            vector<int> row(i + 1, 1);

            // Fill middle elements
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }

            // Add row to triangle
            triangle.push_back(row);
        }

        return triangle;
    }
};
