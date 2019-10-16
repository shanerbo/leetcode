int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
#define cost 2
  private:
    vector<int> set;
    int ret;
    int edges = 0;
    void Set(int n) {
        for (int i = 0; i < n; ++i) {
            this->set.push_back(i);
        }
    }

    void Union(vector<int> &a) {
        int u = Find(a[0] - 1);
        int v = Find(a[1] - 1);
        if (u != v) {
            set[u] = set[v];
            ret += a[cost];
            edges++;
        }
    }

    int Find(int a) {
        int ogA = a;
        while (a != set[a]) {
            a = set[a]; // find the true set number
        }
        set[ogA] = set[a];
        return set[ogA];
    }

    bool validEdge(vector<int> &a) {
        return Find(a[0] - 1) != Find(a[1] - 1);
    }

  public:
    int minimumCost(int N, vector<vector<int>> &connections) {
        if (N == 0) {
            return 0;
        } else if (connections.size() < 1) {
            return 0;
        } else {
            Set(N);
            auto cmp = [](vector<int> a, vector<int> b) {
                return a[cost] < b[cost];
            };
            sort(connections.begin(), connections.end(), cmp);
            for (auto &connection : connections) {
                if (validEdge(connection)) {
                    Union(connection);
                }
            }
        }
        if (edges != N - 1) {
            return -1;
        }
        return ret;
    }
};