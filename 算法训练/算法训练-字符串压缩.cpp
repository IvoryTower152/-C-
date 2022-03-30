#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string source;
    //cin >> source;
    getline(cin, source);
    map<char, int> hash;
    string ans = "";
    for(int i=0; i<source.length(); i++){
        if(source[i]==' '){
            ans += source[i];
        }
        else{
            if(hash.find(source[i]) != hash.end()){
                hash[source[i]]++;
            }
            else{
                hash[source[i]] = 1;
            }

            if(hash[source[i]]==1 || hash[source[i]]==3 || hash[source[i]]==6) ans += source[i];
        }
    }
    cout << ans << endl;
    return 0;
}

/*
问题描述：
编写一个函数，输入一个字符串(只包含小写字母和空格，长度小于100)，然后根据如下规则对字符串进行压缩：
(1) 如果该字符串是空格，则保留该字符
(2) 如果该字符是第1次出现或第3次出现或第6次出现，则保留该字符
(3) 否则，删除该字符

样例输入：occurrence
样例输出：ocurenc
*/