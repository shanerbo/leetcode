/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 *
 * https://leetcode.com/problems/critical-connections-in-a-network/description/
 *
 * algorithms
 * Hard (45.88%)
 * Likes:    167
 * Dislikes: 19
 * Total Accepted:    6.6K
 * Total Submissions: 14.1K
 * Testcase Example:  '4\n[[0,1],[1,2],[2,0],[1,3]]'
 *
 * There are n servers numbered from 0 to n-1 connected by undirected
 * server-to-server connections forming a network where connections[i] = [a, b]
 * represents a connection between servers a and b. Any server can reach any
 * other server directly or indirectly through the network.
 * 
 * A critical connection is a connection that, if removed, will make some
 * server unable to reach some other server.
 * 
 * Return all critical connections in the network in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
 * Output: [[1,3]]
 * Explanation: [[3,1]] is also accepted.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * n-1 <= connections.length <= 10^5
 * connections[i][0] != connections[i][1]
 * There are no repeated connections.
 * 
 * 
 */

// @lc code=start
class Solution {

  private:
    typedef unordered_map<int, vector<int>> Graph;
    vector<vector<int>> ret;
    int time = 0;
    void dfs(Graph &graph, vector<int> &low, vector<int> &disc, vector<bool> &visited, vector<int> &parent, int from) {
        ++time;
        low[from] = time;
        disc[from] = time;
        visited[from] = true;
        for (auto &to : graph[from]) {
            if (!visited[to]) { // if the vertex has been visited, skip it;
                parent[to] = from;
                dfs(graph, low, disc, visited, parent, to);
                low[from] = min(low[from], low[to]); // low[to] will become smaller if there is a cycle;
                if (low[to] > disc[from]) {
                    if (to > from) {
                        ret.push_back({from, to});
                    } else {
                        ret.push_back({to, from});
                    }
                }
            } else {
                if (parent[from] != to) {
                    low[from] = min(disc[to], low[from]);
                }
            }
        }
    };

  public:
    vector<vector<int>>
    criticalConnections(int n, vector<vector<int>> &connections) {
        Graph graph;
        for (auto &connection : connections) {
            graph[connection[0]].push_back(connection[1]); // 0->1, 0->2 0:{1, 2, ...}
            graph[connection[1]].push_back(connection[0]); // 1->0; 1->2 1:{0, 2, ...}
        }
        vector<bool> visited(n, false);
        vector<int> low(n, 0);     // lowest vertex it can reach;
        vector<int> disc(n, 0);    // times of discover;
        vector<int> parent(n, -1); // parent of each vertex;
        for (int from = 0; from < n; ++from) {
            if (visited[from]) {
                continue; // this vertex has been visited no need to DFS it
            } else {
                dfs(graph, low, disc, visited, parent, from);
            }
        }
        return ret;
    }
};
// @lc code=end
