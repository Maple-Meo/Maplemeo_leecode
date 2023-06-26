class Solution {
public:
    void backselect(vector<vector<int>> &res,int first_num,vector<int>& output){
        //若first_num和nums.size()相等，说明已经填完
        if(first_num == output.size()){
            res.push_back(output);
            return;
        }
        
        for(int i = first_num;i<output.size();i++){
            swap(output[first_num],output[i]);
            backselect(res,first_num+1,output);
            swap(output[first_num],output[i]);
        }

    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backselect(res,0,nums);
        return res;
    }
};

