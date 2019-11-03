/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Cut Off Trees for Golf Event
 *
 * https://leetcode.com/problems/cut-off-trees-for-golf-event/description/
 *
 * algorithms
 * Hard (32.68%)
 * Likes:    362
 * Dislikes: 210
 * Total Accepted:    21.8K
 * Total Submissions: 66.5K
 * Testcase Example:  '[[1,2,3],[0,0,4],[7,6,5]]'
 *
 * You are asked to cut off trees in a forest for a golf event. The forest is
 * represented as a non-negative 2D map, in this map:
 * 
 * 
 * 0 represents the obstacle can't be reached.
 * 1 represents the ground can be walked through.
 * The place with number bigger than 1 represents a tree can be walked through,
 * and this positive number represents the tree's height.
 * 
 * 
 * 
 * 
 * You are asked to cut off all the trees in this forest in the order of tree's
 * height - always cut off the tree with lowest height first. And after
 * cutting, the original place has the tree will become a grass (value 1).
 * 
 * You will start from the point (0, 0) and you should output the minimum steps
 * you need to walk to cut off all the trees. If you can't cut off all the
 * trees, output -1 in that situation.
 * 
 * You are guaranteed that no two trees have the same height and there is at
 * least one tree needs to be cut off.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * ⁠[1,2,3],
 * ⁠[0,0,4],
 * ⁠[7,6,5]
 * ]
 * Output: 6
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * ⁠[1,2,3],
 * ⁠[0,0,0],
 * ⁠[7,6,5]
 * ]
 * Output: -1
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 
 * [
 * ⁠[2,3,4],
 * ⁠[0,0,5],
 * ⁠[8,7,6]
 * ]
 * Output: 6
 * Explanation: You started from the point (0,0) and you can cut off the tree
 * in (0,0) directly without walking.
 * 
 * 
 * 
 * 
 * Hint: size of the given matrix will not exceed 50x50.
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int cutOffTree(vector<vector<int>> &forest) {
        auto cmp = [](vector<int> a, vector<int> b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < forest.size(); ++i) {
            auto bush = forest[i];
            for (int j = 0; j < bush.size(); ++j) {
                auto tree = bush[j];
                if (tree == 0) {
                    continue;
                }
                pq.push({tree, i, j});
            }
        }
        int res = 0, startX = 0, startY = 0;
        while (!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();
            int targetX = top[1];
            int targetY = top[2];
            vector<int> loc = {startX, startY, targetX, targetY};
            int steps = bfs(forest, loc);
            if (steps == -1) {
                return -1;
            }
            res += steps;
            startX = targetX, startY = targetY;
        }
        return res;
    }

    int bfs(vector<vector<int>> &forest, vector<int> &loc) {
        int startX = loc[0], startY = loc[1], targetX = loc[2], targetY = loc[3];
        if (startX == targetX && startY == targetY) {
            return 0;
        }

        queue<vector<int>> q;
        q.push({startX, startY});
        vector<vector<int>> visited(forest.size(), vector<int>(forest[0].size(), 0));
        visited[startX][startY] = 1;
        int step = 0;
        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                vector<int> cur = q.front();
                q.pop();
                int x = cur[0], y = cur[1];
                for (int j = 0; j < 4; ++j) {
                    int newX = x + dir[j][0];
                    int newY = y + dir[j][1];
                    if (newX >= 0 && newX < forest.size() && newY >= 0 && newY < forest[0].size() && forest[newX][newY] > 0 && visited[newX][newY] == 0) {
                        if (newX == targetX && newY == targetY) {
                            return step;
                        }
                        visited[newX][newY] = 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return -1;
    }
};