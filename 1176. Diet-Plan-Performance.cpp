class Solution {
  public:
    int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper) {
        int res = 0;
        if (calories.empty()) {
            return res;
        }
        for (int i = 1; i < calories.size(); ++i) {
            calories[i] += calories[i - 1];
        }
        for (int i = k - 1; i < calories.size(); ++i) {
            if (i - k < 0) {
                int cal = calories[i];
                if (cal < lower) {
                    res--;
                } else if (cal > upper) {
                    res++;
                }
                continue;
            }
            int cal = calories[i] - calories[i - k];
            if (cal < lower) {
                res--;
            } else if (cal > upper) {
                res++;
            }
        }
        return res;
    }
};