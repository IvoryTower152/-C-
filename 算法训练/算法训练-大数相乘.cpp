#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Multiply(string& a, string& b, string& result);

int main(){
    string a, b;
    cin >> a >> b;
    string result;
    Multiply(a, b, result);
    cout << result << endl;
    return 0;
}

void Multiply(string& a, string& b, string& result){
    vector<int> a_list(a.length(), 0);
    vector<int> b_list(b.length(), 0);
    //转换
    for(int i=0, j=a.length()-1; i<a.length(); i++){
        a_list[i] = a[j]-'0';
        j--;
    }
    for(int i=0, j=b.length()-1; i<b.length(); i++){
        b_list[i] = b[j]-'0';
        j--;
    }
    //逐位相乘
    vector< vector<int> > matrix;
    for(int i=0; i<b.length(); i++){
        vector<int> temp;
        int next = 0;
        for(int j=0; j<a.length(); j++){
            int cur = a_list[j] * b_list[i] + next;
            temp.push_back(cur%10);
            next = cur/10;
        }
        if (next != 0) temp.push_back(next);
        matrix.push_back(temp);
    }
    //相加
    vector<int> ans = matrix[0];
    int check = 0;
    for(int i=1; i<matrix.size(); i++){
        int next = 0;
        vector<int> ans_temp;
        for(int j=0; j<=check; j++) ans_temp.push_back(ans[j]);
        for(int m=check+1, n=0; n<matrix[i].size();){
            int ans_ = 0;
            if(m<ans.size()){
                ans_ += ans[m];
                m++;
            }
            if(n<matrix[i].size()){
                ans_ += matrix[i][n];
                n++;
            }
            ans_ += next;
            ans_temp.push_back(ans_%10);
            next = ans_/10;
        }
        if (next != 0) ans_temp.push_back(next);
        ans = ans_temp;
        check++;
    }
    result="";
    for(int i=ans.size()-1; i>=0; i--) result += ('0' + ans[i]);
    return;
}

/*
问题描述：
当两个比较大的整数相乘时，可能会出现数据溢出的情形
为避免溢出，可以采用字符串的方法来实现两个大数之间的乘法
具体来说，首先以字符串的形式输入两个整数，每个整数的长度不会超过10位，然后把它们相乘的结果存储在另一个字符串中(不超过20位)
最后把这个字符串打印出来

输入格式：2个以空格分隔的10位字符串
输出格式：2数相乘结果

输入：62773417 12345678
输出：774980393241726

该题只要模拟好两数相乘的过程即可
*/