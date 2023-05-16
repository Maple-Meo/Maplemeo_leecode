//第一次想法，直接暴力给答案
class Solution {
public:
    string intToRoman(int num) {
        string Tmpstr;
        string Romanstr;
        int Tmpnum = num;
        while(Tmpnum>0){
            if(Tmpnum>=1000){
                Tmpstr = "M";
                Tmpnum -= 1000;
            }else if(Tmpnum>=900){
                Tmpstr = "CM";
                Tmpnum -= 900;
            }else if(Tmpnum>=500){
                Tmpstr = "D";
                Tmpnum -= 500;
            }else if(Tmpnum>=400){
                Tmpstr = "CD";
                Tmpnum -= 400;
            }else if(Tmpnum>=100){
                Tmpstr = "C";
                Tmpnum -= 100;
            }else if(Tmpnum>=90){
                Tmpstr = "XC";
                Tmpnum -= 90;
            }else if(Tmpnum>=50){
                Tmpstr = "L";
                Tmpnum -= 50;
            }else if(Tmpnum>=40){
                Tmpstr = "XL";
                Tmpnum -= 40;
            }else if(Tmpnum>=10){
                Tmpstr = "X";
                Tmpnum -= 10;
            }else if(Tmpnum>=9){
                Tmpstr = "IX";
                Tmpnum -= 9;
            }else if(Tmpnum>=5){
                Tmpstr = "V";
                Tmpnum -= 5;
            }else if(Tmpnum>=4){
                Tmpstr = "IV";
                Tmpnum -= 4;
            }else{
                string TmpI = "I";
                Tmpstr = TmpI;
                for(int i = 0;i < Tmpnum; i++){
                    Tmpstr = Tmpstr+TmpI;
                }
                Tmpnum = 0;
            }
            Romanstr = Romanstr+Tmpstr;
        }
        return Romanstr;
    }
};
//修改后，改用vector来存，速度更快
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string res = "";
        for (auto &r : roman) {
            while (num >= r.first) {
                res += r.second;
                num -= r.first;
            }
        }
        return res;
    }
};