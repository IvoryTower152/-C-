#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    //获取数量
    int nums;
    cin >> nums;
    vector<string> targets;
    //十六进制转八进制处理
    for (int i = 0; i < nums; i++){
        string source;
        cin >> source;
        int sum = 0;
        for (int j = 0; j < source.length(); j++){
            if (source[j] >= '0' && source[j] <= '9'){
                sum = sum * 16 + (source[j] - '0');
            }
            else if (source[j] >= 'A' && source[j] <= 'F'){
                sum = sum * 16 + (source[j] - 'A' + 10);
            }
        }
        vector<int> result;
        while(sum > 0){
            result.push_back(sum % 8);
            sum = sum / 8;
        }
        string target = "";
        for (int j = result.size()-1; j >= 0; j--){
            target += ('0' + result[j]);
        }
        targets.push_back(target);
    }
    for (int i = 0; i < nums; i++){
        cout << targets[i] << endl；
        //if (i != nums-1) cout << endl;
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
