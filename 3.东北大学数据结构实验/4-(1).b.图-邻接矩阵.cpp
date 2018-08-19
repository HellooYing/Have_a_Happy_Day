#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    while(1)
    {
        system("Cls");
        std::cout

        << "**********************" << std::endl

        << "*1 无向图            *" << std::endl

        << "*2 有向图            *" << std::endl

        << "*0 结束              *" << std::endl

        << "**********************" << std::endl

        << std::endl;
        int input;
        char content[20];
        int a,b,c,n,i,j,k;
        int wtf[20][20],du[20];
        for(a=0;a<20;a++)
        {
            for(b=0;b<20;b++)
            {
                wtf[a][b]=0;
            }
        }
        cin >> input;
        switch(input)
        {
            case 1 :
                cout << "请输入顶点数:";
                cin >> n;
                cout<<"请输入各顶点名称"<<endl;
                for(k=0;k<n;k++)
                {
                    cout<<"顶点"<<k+1<<":";
                    cin>> content[k];
                    du[k]=0;
                }
                for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        cout << "顶点"<<content[i]<<"与顶点"<<content[j]<<"是否相邻?(1/0):"<<endl;
                        cin >> wtf[i][j];
                        wtf[j][i]=wtf[i][j];
                    }
                }

                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(wtf[i][j]==1)
                        {
                            du[i]++;
                            cout<<"顶点"<<content[i]<<"与顶点"<<content[j]<<"相邻"<<endl;
                        }

                    }
                    cout <<"顶点"<<content[i]<<"的度数为"<< du[i]<<endl<<endl<<endl;
                }
                system("pause");
                break;
            case 2 :
                cout << "请输入顶点数:";
                cin >> n;
                cout<<"请输入各顶点名称"<<endl;
                for(k=0;k<n;k++)
                {
                    cout<<"顶点"<<k+1<<":";
                    cin>> content[k];
                    du[k]=0;
                }
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(i!=j)
                        {
                        cout << "是否存在以顶点"<<content[i]<<"为起点,顶点"<<content[j]<<"为终点的边?(1/0):"<<endl;
                        cin >> wtf[i][j];
                        }
                    }
                }

                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(wtf[i][j]==1)
                        {
                            du[i]++;
                            du[j]++;
                        }

                    }
                }
                for(i=0;i<n;i++)
                {
                for(j=0;j<n;j++)
                {
                    if(wtf[i][j]==1)
                    {
                        cout<<"存在以顶点"<<content[i]<<"为起点,顶点"<<content[j]<<"为终点的边"<<endl;
                    }
                }
                cout <<"顶点"<<content[i]<<"的度数为"<< du[i]<<endl<<endl<<endl;
                }
                system("pause");
                break;
            case 0 :
                return 0;
        }
    }
}
