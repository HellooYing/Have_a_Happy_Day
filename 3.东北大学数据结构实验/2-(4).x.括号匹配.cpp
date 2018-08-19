#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string leftparenthese = "([{<";//保存左括号列表
    string rightparenthese = ")]}>";//保存右括号列表
    stack<char> parenthese;
    string str;
    cin >> str;
    int flag = -1;
    for (int i = 0; i < str.length(); i++)
    {
        if (leftparenthese.find(str[i]) != string::npos)//左括号直接入栈
            parenthese.push(str[i]);
        else if (rightparenthese.find(str[i]) != string::npos)//如果遇到右括号
        {
            //检查是否与栈顶栈顶符号匹配
            if (!parenthese.empty() && leftparenthese.find(parenthese.top()) == rightparenthese.find(str[i]))
                parenthese.pop();//如果匹配则删除栈顶符号
            else//不匹配则标记并退出循序
            {
                flag = i;
                break;
            }
        }
    }
    //根据比较结果判定是否匹配
    if (!parenthese.empty() || flag >= 0)
        cout << "不匹配" << endl;
    else
        cout << "匹配" << endl;
    return 0;
}

