#include<iostream>
#include <windows.h>
using namespace std;
void quickSort(int a[],int,int);
int main()
{
    int array[]={23,36,21,34,56,5,11,14,1,98},k;
    int len=sizeof(array)/sizeof(int);
    cout<<"ԭʼ����:"<<endl;
    for(k=0;k<len;k++)
        cout<<array[k]<<",";
    cout<<endl;
    quickSort(array,0,len-1);
    cout<<"��������������:"<<endl;
    for(k=0;k<len;k++)
        cout<<array[k]<<",";
    cout<<endl;
    system("pause");
    return 0;
}

void quickSort(int s[], int l, int r)
{
    if (l< r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j]>= x) // ���������ҵ�һ��С��x����
                j--;
            if(i < j)
                s[i++] = s[j];
            while(i < j && s[i]< x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1); // �ݹ����
        quickSort(s, i + 1, r);
    }
}
