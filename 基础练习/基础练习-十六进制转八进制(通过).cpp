#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

/*
如果按照十六进制转换为十进制的传统思路，很容易发生int型溢出的情况(因为题中给出的十六进制长度上限为100000)
因此，转而使用string型来保留中间结果，同时将二进制作为中间媒介
十六进制1位相当于4位二进制，八进制1位相当于3位二进制，十六进制与八进制的转换具有规律性
*/

int main(){
    map<string, char> hash_8;
    map<char, string> hash_16;
    hash_8["000"] = '0';
    hash_8["001"] = '1';
    hash_8["010"] = '2';
    hash_8["011"] = '3';
    hash_8["100"] = '4';
    hash_8["101"] = '5';
    hash_8["110"] = '6';
    hash_8["111"] = '7';

    hash_16['0'] = "0000";
    hash_16['1'] = "0001";
    hash_16['2'] = "0010";
    hash_16['3'] = "0011";
    hash_16['4'] = "0100";
    hash_16['5'] = "0101";
    hash_16['6'] = "0110";
    hash_16['7'] = "0111";
    hash_16['8'] = "1000";
    hash_16['9'] = "1001";
    hash_16['A'] = "1010";
    hash_16['B'] = "1011";
    hash_16['C'] = "1100";
    hash_16['D'] = "1101";
    hash_16['E'] = "1110";
    hash_16['F'] = "1111";

    int nums;
    cin >> nums;
    vector<string> sources(nums);
    for (int i = 0; i < nums; i++) cin>>sources[i];
    vector<string> targets;
    for (int i = 0; i < nums; i++){
        string result = "";
        string target = "";
        //转为2进制string型
        for (int j = 0; j < sources[i].length(); j++) result += hash_16[sources[i][j]];
        //cout << result << endl;
        int need = 0;
        //补全位数，可以被3整除
        if (result.length() % 3 != 0) need = 3 - (result.length() % 3);
        for (int j = 0; j < need; j++){
            result = '0' + result;
        }
        for (int j = 0; j < result.length(); j += 3){
            string temp = "";
            temp = temp + result[j] + result[j+1] + result[j+2];
            target += hash_8[temp];
        }
        int index = 0;
        while(target[index] == '0') index++;
        target = target.substr(index, target.size()-index);
        targets.push_back(target);
    }
    for (int i = 0; i < targets.size(); i++){
        cout << targets[i] << endl;
    }
    return 0;
}

/*
问题描述：
给定n个十六进制正整数，输出它们对应的八进制数。

输入格式：
输入的第一行为一个正整数n; (1<=n<=10)
接下来n行，每行一个由0-9，大写字母A-F组成的字符串，表示要转换的十六进制正整数，每个十六进制数长度不超过100000;

输出格式：
输出n行，对应每行输入的八进制正整数

Note： 输入的十六进制数不会有前导0，比如012A; 输出的八进制数也不能有前导0;

输入样例：
2
39
123ABC

样例输出：
71
4435274
*/