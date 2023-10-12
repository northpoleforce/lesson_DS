#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int t; cin >> t;  //多组数据
    string str;
    while (t--) {
        cin >> str;
        int len = str.size();  //输入表达式，求其长度
        string num = "";
        stack <char> s_op;  //运算符栈
        stack <string> s_num;  //操作数栈
        
        //求波兰式，从右往左扫描
        for (int i = len-1; i >= 0; --i) {
            if (str[i] >= '0' && str[i] <= '9') {
                //取出当前完整的数字
                for (int j = i; j >= 0; --j) {
                    if (str[j] < '0' || str[j] > '9') {
                        i = j+1;
                        break;
                    }
                    num = str[j]+num;
                    if (j == 0) i = j;
                }
                //把数字压进操作数栈
                s_num.push(num);
                num = "";
            } else {
                //如果不是数字，那就是运算符
                //从右到左扫描，遇到)时就是一组括号的开始，直接压进运算符栈
                if (str[i] == ')')
                    s_op.push(str[i]);
                //遇到(时就是一组括号的结束，就要把这组括号里面的运算符压进操作数栈
                else if (str[i] == '(') {
                    while (s_op.top() != ')') {
                        //把字符转成字符串后压入操作数栈
                        string tmp;
                        tmp = s_op.top();
                        s_num.push(tmp);
                        s_op.pop();
                    }
                    s_op.pop();
                }
                //如果运算符栈是空的话，就直接压进去
                else if (s_op.empty())
                    s_op.push(str[i]);
                //如果遇到*/，直接压进去
                else if (str[i] == '*' || str[i] == '/') {
                    s_op.push(str[i]);
                }
                //如果遇到+-，把*/压入操作数栈，然后再压入运算符栈
                else {
                    while (!s_op.empty() && (s_op.top() == '*' || s_op.top() == '/') ) {
                        string tmp;
                        tmp = s_op.top();
                        s_num.push(tmp);
                        s_op.pop();
                    }
                    s_op.push(str[i]);
                }
            }
        }
        //处理完表达式后运算符栈里的压入操作数栈
        while (!s_op.empty()) {
            string tmp;
            tmp = s_op.top();
            s_num.push(tmp);
            s_op.pop();
        }
        //把操作数栈里的出栈输出
        bool first = true;
        while (!s_num.empty()) {
            if (first) {
                first = false;
                cout << s_num.top();
            } else
                cout << " " << s_num.top();
            
            s_num.pop();
        }
        cout << "\n";


        for (int i = 0; i < len; ++i) {
            //如果是数字，直接输出
            if (str[i] >= '0' && str[i] <= '9') {
                for (int j = i; j < len; ++j) {
                    if (str[j] < '0' || str[j] > '9') {
                        i = j-1;
                        break;
                    }
                    num += str[j];
                    if (j+1 == len) i = len;
                }
                cout << num << " ";
                num = "";
            } else {
                //如果不是数字
                //遇到(，直接压入运算符栈
                if (str[i] == '(')
                    s_op.push(str[i]);
                //遇到)，寻找到(前，把所有的出栈输出
                else if (str[i] == ')') {
                    while (s_op.top() != '(') {
                        cout << s_op.top() << " ";
                        s_op.pop();
                    }
                    s_op.pop();
                }
                //如果运算符栈是空栈，直接压入
                else if (s_op.empty())
                    s_op.push(str[i]);
                //遇到*/，把运算符栈顶的*/输出后再压入
                else if (str[i] == '*' || str[i] == '/') {
                    while (!s_op.empty() && (s_op.top() == '*' || s_op.top() == '/')) {
                        cout << s_op.top() << " ";
                        s_op.pop();
                    }
                    s_op.push(str[i]);
                }
                //遇到+-，把运算符栈顶的+-*/输出后再压入
                else {
                    while (!s_op.empty() && s_op.top() != '(') {
                        cout << s_op.top() << " ";
                        s_op.pop();
                    }
                    s_op.push(str[i]);
                }
            }
        }
        //处理完表达式后把运算符栈里的出栈输出
        while (!s_op.empty()) {
            if (s_op.size() == 1)
                cout << s_op.top();
            else
                cout << s_op.top() << " ";
            s_op.pop();
        }
        cout << "\n";
        if (t) cout << "\n";
    }

    return 0;
}