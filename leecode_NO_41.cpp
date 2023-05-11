//参考题解中的第六种解题法 使用栈解决问题

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> stack; //初始化栈对象
        int sum; //雨水总数
        int curr = 0; //当前pos
        while(curr < height.size()){
            while(!stack.empty() && height[curr] > height[stack.back()]){ //当前大于栈顶，循环入栈
                int tmphight = height[stack.back()]; //取出栈顶
                stack.pop_back();
                if(stack.empty()){
                    break;
                }else{
                    int min_size = min(height[curr], height[stack.back()]); //计算新雨水数目 （最小墙-取出墙）*宽度
                    sum += (min_size - tmphight)*(curr - stack.back() -1);
                }
            }
            stack.push_back(curr); //作为新栈顶
            curr++;
        }

        return sum;

    }
};