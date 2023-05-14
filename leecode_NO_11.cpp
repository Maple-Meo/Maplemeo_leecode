
//第一次code,时间复杂度超标了
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int box_height = 0;
        int box_width = 0;
        int tmp_box = 0;
        for(int i = 0;i<height.size()-1;i++){
            for(int j = i+1;j<height.size();j++){
                box_height = min(height[i],height[j]);
                box_width = j-i;
                tmp_box = box_width*box_height;
                if(tmp_box > max){
                    max = tmp_box;
                }

            }
        }
        return max;
    }
};

//改进一
class Solution {
public:
    int maxArea(vector<int>& height) {
        int box_max = 0;
        int tmp_box = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            tmp_box  = min(height[left],height[right])*(right - left);
            box_max = max(box_max,tmp_box);
            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return box_max;
        }
};
//改进二
class Solution {
public:
    int maxArea(vector<int>& height) {
        int box_max = 0;
        int tmp_box = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right){
            tmp_box  = min(height[left],height[right])*(right - left);
            box_max = box_max>tmp_box?box_max:tmp_box;
            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return box_max;
        }
};