class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        // 1. Save the exact coordinates of our target point
        int targetX = coordinates[k][0];
        int targetY = coordinates[k][1];

        // 2. Sort: Ascending X, Descending Y (Crucial for 2D LIS)
        sort(coordinates.begin(), coordinates.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) {
                     return a[1] > b[1];
                 }
                 return a[0] < b[0];
             });

        vector<int> v1, v2; // v1 is before target, v2 is after target

        // 3. Single pass to build both LIS arrays
        for (const auto& point : coordinates) {
            int x = point[0];
            int y = point[1];

            // Build LIS for valid points BEFORE the target
            if (x < targetX && y < targetY) {
                auto it = lower_bound(v1.begin(), v1.end(), y);
                if (it == v1.end()) {
                    v1.push_back(y);
                } else {
                    *it = y;
                }
            }
            // Build LIS for valid points AFTER the target
            else if (x > targetX && y > targetY) {
                auto it = lower_bound(v2.begin(), v2.end(), y);
                if (it == v2.end()) {
                    v2.push_back(y);
                } else {
                    *it = y;
                }
            }
        }

        // The total length is (max path before) + (target point itself) + (max
        // path after)
        return v1.size() + 1 + v2.size();
    }
};