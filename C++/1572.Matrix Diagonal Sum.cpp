#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    int l = 0, r = mat.size() - 1;
    if (mat.size() == 0) {
      return 0;
    }
    int sum = 0;
    for (int i = 0; i < mat.size(); i++, l++, r--) {
      sum += l == r ? mat[i][l] : (mat[i][l] + mat[i][r]);
    }
    return sum;
  }
};