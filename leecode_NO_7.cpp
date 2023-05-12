/* 第一次自己解题思路：
1.判断整数X的正负，将负整数X转换成为正整数处理
2.对于正整数做 X%10操作得到余数（mid），将之前结果result * 10 + mid得到最新结果，再将X÷10得到新一轮输入，指到X≤10
3.剩余结果做处理，输出结果。
4.对于超过int限制的数提前进行判断，例如 在执行result * 10 + mid前判断 result是否<2的30次方
ps(有如下的坑)：
1.对于末尾为0的X数需要单独处理，直接将X/10
2.将负整数转换成为正整数时，也需要进行判断 */

//第一次实现代码：
class Solution {
public:
    int reverse(int x) {
        int old_int = x;
        int mid_int = 0;
        int new_int = 0;

        while(mid_int == 0 && old_int != 0){
        mid_int = old_int % 10;
        if(mid_int == 0){
            old_int = old_int / 10;
        }
        }
        if(old_int > 0){
            while(old_int >= 10){
                mid_int = old_int % 10;
                new_int = mid_int + new_int * 10;
                old_int = old_int / 10;
                if(new_int > (2147483647 / 10)){
                    return 0;
                }
            }
            new_int = old_int + new_int * 10;
            if(new_int > 2147483647){
                    return 0;
            }
        }else{
            if(old_int <= -2147483648){
                return 0;
            }
            old_int = old_int * (-1);
            while(old_int >= 10){
                mid_int = old_int % 10;
                new_int = mid_int + new_int * 10;
                old_int = old_int / 10;
                if(new_int > (2147483648 / 10)){
                    return 0;
                }
            }
            new_int = old_int + + new_int * 10;
            if(new_int > 2147483648){
                    return 0;
            }
            new_int = new_int * (-1);
        }
        return new_int;
    }
};

/* 第二次解题思路（看解题）：
看了题解之后发现，之前的代码高度冗杂，主要存在一下三个问题
1.正负数的处理方式可以合并，负数%10的结果还是对应余数
2.最后一位的结果可以和普通过程合并
3.判断移除条件可以直接合并为temp > (INT_MAX) / 10 || temp < (-INT_MAX - 1) / 10) && x != 0 */

//第二次代码实现：
class Solution {
public:
    int reverse(int x) {
       int res = 0;
       int temp = 0;
       while(x != 0) {
            temp = res * 10 + x % 10;
            x = x / 10;
            if((temp > (INT_MAX) / 10 || temp < (-INT_MAX - 1) / 10) && x != 0){
                return 0;
            }
            res = temp;
       }
       return res; 
    }
};

/* 第三次解题思路有（自己思考）
看题目的第一感觉是转换成字符串然后反转，溢出判断比较字符串就可以，之后有空尝试一下。
 */