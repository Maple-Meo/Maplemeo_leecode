// 第一次code，想直接用long long进行存储，但是测试用例超出long llong长度，code失败
class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_size = num1.size();
        int num2_size = num2.size();
        long long ten1_size = 1;
        long long ten2_size = 1;
        long long add = 0;
        long long result = 0;
        for(int i = 0;i < num1.size();i++){
            for(int j = 0; j< num2.size();j++){
                add = (long long)(num1[num1_size - 1 - i] - '0') * (long long)(num2[num2_size - 1 - j] - '0') * ten1_size * ten2_size;
                result += add;
                ten2_size = 10*ten2_size;
            }
            ten2_size = 1;
            ten1_size = 10*ten1_size;
        }    
    string resultStr = to_string(result);
    return resultStr;
    }

};

//考虑用vector保存每一位,竖式乘法
class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_size = num1.size();
        int num2_size = num2.size();
        vector <int> mult_v(num1_size+num2_size,0);
        //如果有其中一个为0，结果为0
        if(num1[0]== '0' || num2[0]== '0')
        return "0";
        //竖式计算，得到每一位的大小
        for(int i = 0;i<num1_size;i++){
            for(int j = 0;j<num2_size;j++){
                int tmpans = (num1[num1_size-1-i] - '0') * (num2[num2_size-j-1] - '0');
                mult_v[i+j] += tmpans;
            }
        }
        //每一位每十进一，使每一位都小于十
        for(int i = 0;i<mult_v.size() -1;i++){
            int a = mult_v[i]/10;
            mult_v[i+1] += a;
            mult_v[i] = mult_v[i]%10;
        }
        //用string输出结果
        string ansStr;
        for(int i = 0;i<mult_v.size();i++){
            if(i == 0 && mult_v[mult_v.size()-1-i]==0){
                 continue;
            }
            ansStr = ansStr + to_string(mult_v[mult_v.size()-1-i]);
        }
        return ansStr;

    }
};