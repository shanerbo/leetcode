/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (36.63%)
 * Likes:    1289
 * Dislikes: 92
 * Total Accepted:    181K
 * Total Submissions: 493.5K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, return
 * the ordering of courses you should take to finish all courses.
 * 
 * There may be multiple correct orders, you just need to return one of them.
 * If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished   
 * course 0. So the correct course order is [0,1] .
 * 
 * Example 2:
 * 
 * 
 * Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,1,2,3] or [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both     
 * ⁠            courses 1 and 2. Both courses 1 and 2 should be taken after you
 * finished course 0. 
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3] .
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // [1, 0] means you have to take 0 before taking 1, 0->1 this is topological sort
        // so we have to generate a graph that contains all directed edges
        // we need two map to store 1 for from to to 1 for to to from
        vector<int> res;
        if (prerequisites.size() < 1) {
            for (int i = 0; i < numCourses; ++i) {
                res.push_back(i);
            }
            return res;
        }
        unordered_map<int, vector<int>> graph;
        vector<int> incoming(numCourses, 0);
        for (auto const &preq : prerequisites) {
            graph[preq[1]].push_back(preq[0]); // {to: {node to reach}}
            incoming[preq[0]]++;
        }
        vector<int> sort;
        queue<int> toSearch;
        for (int i = 0; i < incoming.size(); ++i) {
            if (incoming[i] == 0) {
                toSearch.push(i); // which node does not have incoming edge
            }
        }
        while (!toSearch.empty()) {
            auto from = toSearch.front();
            sort.push_back(from);
            toSearch.pop();
            for (auto const &node : graph[from]) {
                incoming[node]--; //remove the edge
                if (incoming[node] == 0) {
                    toSearch.push(node);
                }
            }
        }
        for (auto const &edge : incoming) {
            if (edge != 0) {
                return vector<int>();
            }
        }
        return sort;
    }
};
// @lc code=end
