class Solution {
  public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        if (str1.length() != str2.length()) {
            return false;
        }
        unordered_map<char, char> map;
        for (int i = 0; i < str1.length(); ++i) {
            if (map.count(str1[i]) > 0 && map[str1[i]] != str2[i]) {
                return false;
            }
            map[str1[i]] = str2[i];
        }
        return set(str2.begin(), str2.end()).size() < 26;
    }
};