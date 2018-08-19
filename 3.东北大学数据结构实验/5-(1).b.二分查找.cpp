#include<iostream>
using namespace std;

template <class T>
T *partition(T *low, T *high)
{
    high--;
    T middle = *low;
    while(low < high)
    {
        while(low < high&&*high >= middle) high--;
        *low = *high;
        while(low < high&&*low <= middle) low++;
        *high = *low;
    }
    *low = middle;
    return low;
}

template <class T>

void qsort(T *st, T *en)
{
    if(st < en)
    {
        T *middle = partition(st, en);
        qsort(st, middle);
        qsort(middle+1, en);
    }
}

template <class T>

int bsearch(T *st, T *en, T des)
{
    T *ori = st;
    int ans = -1;
    while(st < en)
    {
        T *mid = st + (en-st)/2;
        if((*mid > des&&*st > des)||(*mid < des&& *st < des))
            st = mid;
        else
            en = mid;
        if(*mid == des)
        {
            ans = mid - ori;
            break;
        }
    }
    return ans;
}


int main(void)
{
    //初始化数组
    int num[10] = {2, 5, 3, 4, 9, 6, 7, 1, 0, 8};
    //数组元素排序
    qsort(num, num+10);
    for(int i = 0;i < 10;i++)
    {
        cout << num[i] << ' ';
    }
    cout << endl;


    //初始化数组
    char ch[10] = {'a', 'n', 'e', 's', 'd', 't', 'f', 'c', 'o', 'p'};
    //数组元素排序
    qsort(ch, ch+10);
    for(int i = 0;i < 10;i++)
        cout << ch[i] << ' ';
    cout << endl;


    return 0;
}
