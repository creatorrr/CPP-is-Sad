#include<iostream.h>
#include<conio.h>
#include<math.h>
/**
*@author:Diwank Singh Tomer
*http://in.linkedin.com/meetdagod
*print a circle without using graphic.h
*save text as circle.cpp
*run it in Turbo C++ or CMD or any other C++ compiler
*/
void main()
    {clrscr();
    cout<<"Program to draw an empty circle."<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Input desired diameter:";
    int a=0;
    cin>>a;
    if(a%2!=0){a=a+1;}
    cout<<"Enter character to print.:";
    char ch;
    cin>>ch;
    cout<<"--------------------"<<endl;
    char circle[100][100];
    int b=a/2;
    double y=0;
    double z=0;
    int r=0;
    int Y=0;
    int Z=0;
    for(int s=0;s<=a;s++)
        {for(int t=0;t<=a;t++)
            {circle[s][t]=32;
            }
        }
    circle[b][b]=79;
    double m=0;
    for(int i=0;i<a;i++)   //calcualtes circle coordinates by equation to circle
        {
        m=abs(i*i-2*b*i);
        y=(b+sqrt(m));
        z=(b-sqrt(m));
        Y=floor(y+0.5);
        Z=floor(z+0.5);
        circle[i][Y]=ch;
        circle[i][Z]=ch;
        }
    for(int p=0;p<=a;p++)
        {for(int q=0;q<=a;q++)
            {cout<<circle[p][q]<<" ";  //add or remove spaces to correct shape!
            }cout<<endl;
        }getch();
    }
