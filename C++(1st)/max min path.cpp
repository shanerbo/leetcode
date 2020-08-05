int maxScore(vector<vector<int>> &grid) {
    if (grid.size() < 1) {
        return 0;
    }
    auto dp = grid;
    int maxScore = INT_MIN;
    grid[0][0] = grid[grid.size() - 1][grid[0].size() - 1] = INT_MAX;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (i == 0) {
                if (j == 0)
                    continue;
                dp[i][j] = min(dp[i][j - 1], dp[i][j]);
            } else if (j == 0) {
                if (i == 0)
                    break;
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            } else {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i][j]);
                maxScore = max(maxScore, dp[i][j]);
            }
        }
    }
    return maxScore;
}