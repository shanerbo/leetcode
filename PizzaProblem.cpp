typedef vector<tuple<int, int, int>> Coupons;
typedef vector<int> Pizzas;
typedef unordered_map<int, Coupons> Map;
class PizzaProblem {
  private:
    void find(Pizzas &pizzas, Coupons &coupons, Map &map, int start, int obtain, int cost, int total, int used, int &res) {
        if (obtain >= total) {
            res = min(res, cost);
            return;
        }
        int left = total - obtain;
        int canUseCoupon = false;
        for (int i = left; i >= 0; --i) {
            if (map.count(i) > 0) {
                for (int j = 0; j < map[i].size(); ++j) {
                    if (get<2>(map[i][j]) == 0) {
                        canUseCoupon = true;
                        break;
                    }
                }
                if (canUseCoupon) {
                    break;
                }
            }
        }
        if (used == coupons.size() || !canUseCoupon) {
            for (int i = start; i < pizzas.size(); ++i) {
                cost += pizzas[i];
                // cout<<pizzas[i]<<endl;
            }
            res = min(res, cost);
            return;
        }

        if (canUseCoupon) {
            int purchased = 0;
            int sum = 0;
            for (int i = start; i < total; ++i) {
                sum += pizzas[i];
                if (map.count(++purchased) > 0) {
                    int size = map[purchased].size();
                    for (int p = size - 1; p >= 0; --p) {
                        if (get<2>(map[purchased][p]) == 0) {
                            int freePizzas = get<1>(map[purchased][p]);
                            get<2>(map[purchased][p]) = 1;
                            // cout<<"purchased: "<< purchased << " get "<< freePizzas<< endl;
                            find(pizzas, coupons, map, i + freePizzas + 1, obtain + purchased + freePizzas, sum + cost, total, used + 1, res);
                            get<2>(map[purchased][p]) = 0;
                        }
                    }
                }
            }
        }
        return;
    };

  public:
    int miniCost(vector<int> &pizzas, vector<tuple<int, int, int>> coupons) {
        Map map;
        int res = INT_MAX;
        auto cmp = [](tuple<int, int, int> a, tuple<int, int, int> b) {
            return get<1>(a) < get<1>(b);
        };
        sort(coupons.begin(), coupons.end(), cmp);
        for (auto const &c : coupons) {
            map[get<0>(c)].push_back(c);
        }
        sort(pizzas.rbegin(), pizzas.rend());
        find(pizzas, coupons, map, 0, 0, 0, pizzas.size(), 0, res);
        return res == INT_MAX ? -1 : res;
    };
};

Coupons convert(vector<int> buy, vector<int> free) {
    Coupons coupons;
    for (int i = 0; i < buy.size(); ++i) {
        coupons.push_back(make_tuple(buy[i], free[i], 0));
    }
    return coupons;
}

int main() {
    auto pizzaProblem = new PizzaProblem();
    int res;
    Pizzas pizzas = {};
    Coupons coupons = {};
    vector<int> buy = {};
    vector<int> free = {};
    //     sanity test
    res = pizzaProblem->miniCost(pizzas, coupons);
    cout << "Correct answer: 0, our answer: " << res << endl;

    //     dummy test
    pizzas = {11, 14, 22, 5, 3, 19};
    buy = {1, 2, 2, 3};
    free = {1, 1, 2, 2};
    coupons = convert(buy, free);
    res = pizzaProblem->miniCost(pizzas, coupons);
    cout << "Correct answer: 46, our answer: " << res << endl;

    //     Web test 1
    pizzas = {70, 10, 60, 60, 30, 100, 60, 40, 60, 20};
    buy = {1, 2, 1, 1};
    free = {1, 1, 1, 0};
    coupons = convert(buy, free);
    res = pizzaProblem->miniCost(pizzas, coupons);
    cout << "Correct answer: 340, our answer: " << res << endl;

    //     Web test 2
    pizzas = {10, 15, 20, 15};
    buy = {1, 2, 2, 8, 3, 1, 4};
    free = {1, 1, 2, 9, 1, 0, 1};
    coupons = convert(buy, free);
    res = pizzaProblem->miniCost(pizzas, coupons);
    cout << "Correct answer: 35, our answer: " << res << endl;

    // test 10
    pizzas = {46, 45, 39, 41, 24, 30, 20, 49, 27, 40, 29, 29, 42, 45, 43};
    buy = {11, 14, 11, 9, 9, 9, 14, 12, 12, 13, 10, 7, 15, 7, 12, 12, 10, 8, 11, 14, 13, 9, 13, 14, 10, 15, 11, 15, 14, 14};
    free = {5, 6, 8, 10, 8, 8, 6, 8, 9, 9, 7, 9, 8, 8, 10, 6, 9, 8, 5, 8, 5, 5, 8, 9, 5, 5, 7, 5, 6, 5};
    coupons = convert(buy, free);
    res = pizzaProblem->miniCost(pizzas, coupons);
    cout << "Correct answer: 311, our answer: " << res << endl;

    // test 12
    pizzas = {48, 39, 41, 18, 39, 37, 42, 38, 31, 26, 39, 37, 31, 43, 43, 19, 25, 30, 49, 12, 22, 47, 46, 50, 40};
    buy = {15, 20, 18, 18, 12, 13, 15, 19, 10, 20, 13, 20, 19, 19, 20, 17, 10, 11, 14, 16, 13, 14, 11, 10, 19, 18, 11, 14, 12, 20};
    free = {8, 6, 7, 9, 8, 6, 7, 6, 5, 9, 6, 8, 6, 5, 10, 7, 8, 10, 10, 9, 10, 8, 8, 10, 10, 9, 6, 7, 9, 7};
    coupons = convert(buy, free);
    res = pizzaProblem->miniCost(pizzas, coupons);
    cout << "Correct answer: 470, our answer: " << res << endl;
}