class CloudFrontCache {
  private:
    vector<int> sum;
    vector<int> root;

  public:
    CloudFrontCache(int n, vector<vector<int>> &nums) {
        for (int i = 0; i < n; ++i) {
            root.push_back(i);
            sum.push_back(1);
        }
        for (const auto &num : nums) {
            combine(num[0], num[1]);
        }
    }

    /*
  * find x's root
  */
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return find(root[x]);
    }

    /*
  * insert a, b nodes into union
  */
    void combine(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a < root_b) {
            root[root_b] = root_a;
            sum[root_a] += sum[root_b];
        } else {
            root[root_a] = root_b;
            sum[root_b] += sum[root_a];
        }
    }

    int get_cost() {
        int cost = 0;
        for (size_t i = 0; i < sum.size(); ++i) {
            if (i == root[i]) {
                cost += static_cast<int>(ceil(sqrt(sum[i])));
            }
        }
        return cost;
    }
};

int main() {
    vector<vector<int>> arr = {{0, 2}, {1, 2}};
    CloudFrontCache cache(4, arr);
    auto cost = cache.get_cost();
    cout << cost << endl;
}