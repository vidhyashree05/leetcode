class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(101, 0.0);
        row[0] = poured;

        for (int r = 0; r < query_row; r++) {
            vector<double> nextRow(101, 0.0);

            for (int i = 0; i <= r; i++) {
                if (row[i] > 1.0) {
                    double overflow = (row[i] - 1.0) / 2.0;
                    nextRow[i] += overflow;
                    nextRow[i + 1] += overflow;
                }
            }

            row = nextRow;
        }

        return min(1.0, row[query_glass]);
    }
};
