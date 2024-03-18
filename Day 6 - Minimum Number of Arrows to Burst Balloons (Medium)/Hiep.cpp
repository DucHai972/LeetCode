class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int endPos = points[0][1];
        int arrows = 1;

        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > endPos) {
                arrows++;
                endPos = points[i][1];
            }
        }
            return arrows;
    }
};
