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

        << "*1 ����ͼ            *" << std::endl

        << "*2 ����ͼ            *" << std::endl

        << "*0 ����              *" << std::endl

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
                cout << "�����붥����:";
                cin >> n;
                cout<<"���������������"<<endl;
                for(k=0;k<n;k++)
                {
                    cout<<"����"<<k+1<<":";
                    cin>> content[k];
                    du[k]=0;
                }
                for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        cout << "����"<<content[i]<<"�붥��"<<content[j]<<"�Ƿ�����?(1/0):"<<endl;
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
                            cout<<"����"<<content[i]<<"�붥��"<<content[j]<<"����"<<endl;
                        }

                    }
                    cout <<"����"<<content[i]<<"�Ķ���Ϊ"<< du[i]<<endl<<endl<<endl;
                }
                system("pause");
                break;
            case 2 :
                cout << "�����붥����:";
                cin >> n;
                cout<<"���������������"<<endl;
                for(k=0;k<n;k++)
                {
                    cout<<"����"<<k+1<<":";
                    cin>> content[k];
                    du[k]=0;
                }
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(i!=j)
                        {
                        cout << "�Ƿ�����Զ���"<<content[i]<<"Ϊ���,����"<<content[j]<<"Ϊ�յ�ı�?(1/0):"<<endl;
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
                        cout<<"�����Զ���"<<content[i]<<"Ϊ���,����"<<content[j]<<"Ϊ�յ�ı�"<<endl;
                    }
                }
                cout <<"����"<<content[i]<<"�Ķ���Ϊ"<< du[i]<<endl<<endl<<endl;
                }
                system("pause");
                break;
            case 0 :
                return 0;
        }
    }
}
