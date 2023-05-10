//直接看的题解


class Solution {

private:
    vector <pair<int,int>> fremap;
    vector<vector<int>> result;
    vector<int> tmpqresult;


public:
    void getcomb(int pos, int target){
        //如果target为0，说明此时满足序列，加入到结果
        if(target == 0){
            result.push_back(tmpqresult);
            return;
        }
        //不满足序列，直接结束
       if (pos == fremap.size() || target < fremap[pos].first) {
            return;
        }
        //不加入此元素的递归
        getcomb(pos+1,target);
        //确定能加入此元素的最大数量，min(fremap[pos].second,target/fremap[pos].first)
        int Max_size = min(fremap[pos].second,target/fremap[pos].first);
        //每次加入一个元素的递归
        for(int i = 1;i <= Max_size;i++){
            tmpqresult.push_back(fremap[pos].first);
            getcomb(pos+1,target-i*fremap[pos].first);
        }
        //进行回溯
        for(int i = 1;i <= Max_size;i++){
            tmpqresult.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); //进行排序
        for(int cand : candidates){ //根据排序做一个(unique_num,num_size)的映射，进行剪枝
            //初始化fremap
            if(fremap.size() == 0 || cand != fremap.back().first){
                fremap.push_back({cand,1});
            }else{
                fremap.back().second++;
            }
        }
        getcomb(0,target);
        return result;
    }
};

