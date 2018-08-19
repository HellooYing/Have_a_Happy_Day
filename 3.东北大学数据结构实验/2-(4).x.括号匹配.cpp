#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string leftparenthese = "([{<";//�����������б�
    string rightparenthese = ")]}>";//�����������б�
    stack<char> parenthese;
    string str;
    cin >> str;
    int flag = -1;
    for (int i = 0; i < str.length(); i++)
    {
        if (leftparenthese.find(str[i]) != string::npos)//������ֱ����ջ
            parenthese.push(str[i]);
        else if (rightparenthese.find(str[i]) != string::npos)//�������������
        {
            //����Ƿ���ջ��ջ������ƥ��
            if (!parenthese.empty() && leftparenthese.find(parenthese.top()) == rightparenthese.find(str[i]))
                parenthese.pop();//���ƥ����ɾ��ջ������
            else//��ƥ�����ǲ��˳�ѭ��
            {
                flag = i;
                break;
            }
        }
    }
    //���ݱȽϽ���ж��Ƿ�ƥ��
    if (!parenthese.empty() || flag >= 0)
        cout << "��ƥ��" << endl;
    else
        cout << "ƥ��" << endl;
    return 0;
}

