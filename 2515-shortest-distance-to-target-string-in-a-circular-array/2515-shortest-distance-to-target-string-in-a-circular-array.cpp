#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int right = (i - startIndex + n) % n;
                int left = (startIndex - i + n) % n;
                int dist = min(right, left);

                minDist = min(minDist, dist);
            }
        }

        return (minDist == INT_MAX) ? -1 : minDist;
    }
};