#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
char game[30][90]={' '};
enum option{off,on};
enum level{beginner=1,mediocre,advanced};
struct player
 {
 char name[80];
 option sound;
 option roof;
 level speed;
 level difficulty;
 unsigned int score;
 int locat;
 player()
  {strcpy(name,"Pilot");
  sound =on;
  roof=off;
  speed=mediocre;
  difficulty =mediocre;
  locat =15;
  score =0;
  }
 void reset()
  {strcpy(name,"Pilot");
  roof=off;
  sound =on;
  speed=mediocre;
  difficulty =mediocre;
  locat =15;
  score =0;
  }
 };
struct obstruction
 {unsigned int size;
 unsigned int start;
 int pos;
 obstruction()
  {size=0;
  start=0;
  pos=80;
  }
 void reset()
  {do
    {size=random(16);
    }while(size<4);
   //size=random(12);                //use random(12) instead
  start=random(24-size);
  pos=80;
  }
 };
void menu(int& mode)
 {
 nosound();
 mode=1;
 char ch='e';
 clrscr();
 cout<<"Helicopter\n"
     <<"(P)lay\n"
     <<"(A)bout\n"
     <<"(E)xit\n"
     <<"\tHit appropriate Key: ";
 ch=getche();
 switch(ch)
  {case 'P':
  case 'p':clrscr();
       cout<<"Mode\n"
	   <<"(1) Player\n"
	   <<"(2) Player\n"
	   <<"\tHit appropriate Key: ";
      do
      {
       mode=getch();
      }while(mode!=49&&mode!=50);
      mode-=48;
      cout<<mode<<endl;
     // cin>>mode;
       break;
  case 'a':
  case 'A':clrscr();
       cout<<"Details\n"
	   <<"Welcome to Helicopter!!\n"
	   <<"This game has been designed as a part of my Computer Applications Project.\n"
	   <<"In the game you are the pilot of a quadricopter in Pandora and you have to save your crew from the flying rocks. Go ahead try your luck...\n"
	   <<"The controls are as follows:/n"
	   <<"Use arrow Keys for Navigation [Up] key for moving your copter upwards and [Down] key for maving it downwards\n"
	   <<"Simple ain't it? For those of you who can't handle the difficulty.. just type in your name as {dIWANK} or {Diwank}.\n";
       getch();
       menu(mode);
       break;
  case 'e':
  case 'E':exit(1);
       break;
  default:menu(mode);
  }
 }
void printer(player pl1)
 {clrscr();
 for(int i=0;i<24;i++)
  {for(int j=0;j<80;j++)
    {cout<<game[i][j];
    }
  }
 cout<<pl1.name<<"\tScore: "<<pl1.score;
 }
void options(player& pl1)
 {char ch='\0';int s,d,p,h;
 char option[2][15]={"Off","On"};
 char level[3][25]={"Beginner","Mediocre","Advanced"};
 clrscr();
 cout<<"\nOptions\n"
     <<"Enter name: ";
 gets(pl1.name);
 clrscr();
 do{clrscr();
    s=pl1.sound;
    d=pl1.difficulty;
    p=pl1.speed;
    h=pl1.roof;
    cout<<"\nSettings: "<<pl1.name;
    cout<<"\nS(p)eed:\t"<<level[p-1];
    cout<<"\n(D)ifficulty:   "<<level[d-1]
    <<"\n(S)ound:\t"<<option[s]
    <<"\n(H)it Roof:\t"<<option[h]
    <<"\n\tHit appropriate Key: ";
    ch=getche();
    switch(ch)
      {case 's':
      case 'S':pl1.sound=(!pl1.sound);
	   break;
      case 'h':
      case 'H':pl1.roof=(!pl1.roof);
	   break;
      case 'p':
      case 'P':pl1.speed=(pl1.speed==3)?1:pl1.speed+1;
	   break;
      case 'd':
      case 'D':pl1.difficulty=(pl1.difficulty==3)?1:pl1.difficulty+1;
	   break;
      case 'e':
      case 'E':exit(0);
      }
    }while(ch!='\r');
  }
void obstructor(obstruction obs1)
 {char ch='*';
 obs1.pos=(obs1.pos>=79)?79:obs1.pos;
 for(int i=obs1.start;(i<(obs1.start+obs1.size))&&obs1.size>0;i++)
    {
     if(obs1.pos>=0)
       {game[i][obs1.pos]=ch;
    game[i][obs1.pos+1]=' ';
    game[i][obs1.pos-1]=ch;
       }
     else{game[i][obs1.pos]=' ';
      game[i][obs1.pos+1]=' ';
      }
    }
 }
void play(player& pl1)
 {
 int i=1;
 char key=' ';
 obstruction obs1,obs2,tmp;
 obs1.reset();
 do{
    do{delay(3360/(pl1.speed*80));                //check speed
       for(int w=0;w<26;w++){for(int x=0;x<82;x++){game[w][x]=' ';}}
       game[pl1.locat][0]='#';
       obstructor(obs1);
       obstructor(obs2);

       printer(pl1);
       if(pl1.sound)
    {sound(120*(random(3)+1+(i%3)));}
       if(obs1.pos==(80-(10*(6-pl1.difficulty))))
    {obs2.reset();}
       else if(obs1.pos==1)
    {tmp=obs1;
    obs1=obs2;
    obs2=obs1;
    obs2.reset();
    }
       obs1.pos--;obs2.pos--;
       i+=(!strcmp(pl1.name,"Diwank"))?10:1;
       pl1.score=i/10;
       }while(kbhit()==0&&game[pl1.locat+1][0]==' '&&game[pl1.locat-1][0]==' ');
       if(kbhit()!=0||!strcmp(pl1.name,"dIWANK"))
       {
    key=getch();
    if(key==0)
      {key=getch();
      if(key==72)pl1.locat--;
      else if(key==80)pl1.locat++;
      if(!pl1.roof)
        {pl1.locat=(pl1.locat<1)?22:pl1.locat;
         pl1.locat=(pl1.locat>22)?1:pl1.locat;
	}
      for(int j=0;j<24;j++){game[j][0]=' ';}
      }
    else if(key=='e'||key=='E')exit(0);}
   }while(key!='\r'&&game[pl1.locat+1][0]==' '&&game[pl1.locat-1][0]==' ');
 
 }
void main()
 {
 randomize();
 textmode(C80);
 char ch;
 int mode=1;
 player pl1,pl2,tmp;
 do{
   menu(mode);
   for(int i=1;i<=mode;i++)
      {options(pl1);
      for(int w=0;w<26;w++){for(int x=0;x<82;x++){game[w][x]=' ';}}
      play(pl1);
      //if(mode==2)
    tmp=pl1;
    pl1=pl2;pl1.reset();
    pl2=tmp;
    
      }
   cout<<"\nScoreboard\n"
       <<pl2.name<<setw(10)<<pl2.score<<endl;
   if(mode==2)
     {cout<<pl1.name<<setw(10)<<pl1.score<<endl;
     cout<<((pl2.score>pl1.score)?pl2.name:pl1.name)<<"  Wins!\n";
     }
   cout<<"\nHit n to exit: ";
   cin>>ch;
   //ch=getche();
   }while(ch!='n'||ch!='N');
   nosound();
 }