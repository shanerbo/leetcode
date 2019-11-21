class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        if(nums.empty()){
            return res;
        }
        unordered_map<int, int> map;
        map[nums[0]] = 0;
        for(int i = 1; i < nums.size(); ++i){
            nums[i] = nums[i] + nums[i-1];
            if(map.count(nums[i]) > 0){
                map[nums[i]] = i>=map[nums[i]]? map[nums[i]] : i;
            }else{
                map[nums[i]] = i;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            int target = nums[i] - k;
            if(nums[i] == k){
                res = max(res, i+1);
            }
            if(map.count(target)>0 && map[target] < i){
                res = max(res, i - map[target]);
            }
        }
        return res;
    }
};