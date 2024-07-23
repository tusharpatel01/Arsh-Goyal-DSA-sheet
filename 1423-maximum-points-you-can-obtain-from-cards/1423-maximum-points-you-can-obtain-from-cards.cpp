class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        for (int i = 0; i < k; i++) {
            total += cardPoints[i];
        }

        int max_points = total;

        for (int i = 0; i < k; i++) {
            total = total - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            max_points = max(max_points, total);
        }

        return max_points;
    }
};
