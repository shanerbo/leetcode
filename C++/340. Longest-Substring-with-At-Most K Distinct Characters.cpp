class Solution {
  public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        if (s.length() == 0 || k == 0)
            return res;
        vector<int> dict(256, 0);
        int count = 0, l = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i]] == 0 && count < k) {
                count++;
            } else if (dict[s[i]] == 0 && count >= k) {
                while (--dict[s[l++]] > 0) {
                }
            }
            dict[s[i]]++;
            res = max(res, i - l + 1);
        }
        return res;
    }
};