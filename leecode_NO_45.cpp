//第一次解题思路
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int begin = 0;
        int end = 1;
        while(end < nums.size()){
            int max_step = 0;
            for(int i = begin;i < end;i++){
                max_step = max(max_step,i + nums[i]);
            }
            begin = end;
            end = max_step + 1;
            res++;
        }
        return res;
    }
};