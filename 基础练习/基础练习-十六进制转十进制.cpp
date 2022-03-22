#include <iostream>
#include <string>

using namespace std;

int main(){
    string source;
    cin >> source;
    long long target = 0;
    for (int i = 0; i < source.length(); i++){
        if (source[i] >= '0' && source[i] <= '9'){
            target = target * 16 + (source[i] - '0');
        }
        else{
            target = target * 16 + (source[i] - 'A' + 10);
        }
    }
    cout << target;
    return 0;
}

/*
问题描述：
从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出
注：十六进制数中的10-15分别用大写的英文字母A、B、C、D、E、F表示

样例输入：
FFFF

样例输出：
65535
*/