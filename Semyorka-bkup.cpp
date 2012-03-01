//Begin- Includes
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
//#include"mouse.h"
//End- Includes

//Begin- Types
class colorC
		{
				unsigned int R,G,B;
				char hex[6];
				int hextoint(char);
				unsigned int red();
				unsigned int blue();
				unsigned int green();
		public:
				colorC();
				colorC(char []);
				void setColor(char []);
				unsigned int getColor();
				char* hexValue();
		};
int colorC::hextoint(char a)
		{
		unsigned int tmp;
		if(isdigit(a)) tmp=(a-48);
		else if(isalpha(a)) tmp=(tolower(a)-87);
		else tmp=0;
		return tmp;
		}
colorC::colorC()
		{
		R=255,G=255,B=255;
		strcpy(hex,"ffffff");
		}
colorC::colorC(char temp[])
		{
		strcpy(hex,temp);
		R=hextoint(hex[0])*16+hextoint(hex[1]);
		G=hextoint(hex[2])*16+hextoint(hex[3]);
		B=hextoint(hex[4])*16+hextoint(hex[5]);
		}
void colorC::setColor(char temp[])
		{
		strcpy(hex,temp);
		R=hextoint(hex[0])*16+hextoint(hex[1]);
		G=hextoint(hex[2])*16+hextoint(hex[3]);
		B=hextoint(hex[4])*16+hextoint(hex[5]);
		}
unsigned int colorC::red()
		{
		return R;
		}
unsigned int colorC::blue()
		{
		return B;
		}
unsigned int colorC::green()
		{
		return G;
		}
char* colorC::hexValue()
		{
		return hex;
		}
unsigned int colorC::getColor()
		{
		float r=R/255;
		float g=G/255;
		float b=B/255;
		int c;
		if(r==1&&g==0&&b==0) c=RED;
		else if(r==0&&g==1&&b==0) c=GREEN;
		else if(r==0&&g==0&&b==1) c=BLUE;
		else if(r==1&&g==1&&b==0) c=YELLOW;
		else if(r==1&&g==0&&b==1) c=MAGENTA;
		else if(r==0&&g==1&&b==1) c=CYAN;
		else if(r==1&&g==1&&b==1) c=WHITE;
		else if(r==0&&g==0&&b==0) c=BLACK;
		else if(r==g&&g==b&&b>=0.5&&b<1) c=LIGHTGRAY;
		else if(r==g&&g==b&&b<=0.5&&b>0) c=DARKGRAY;
		else if(r<1&&r>=0.5&&g==0&&b==0) c=LIGHTRED;
		else if(g<1&&g>=0.5&&r==0&&b==0) c=LIGHTGREEN;
		else if(b<1&&b>=0.5&&g==0&&r==0) c=LIGHTBLUE;
		else if(r<1&&r>=0.5&&g==0&&b<1&&b>=0.5) c=LIGHTMAGENTA;
		else if(g<1&&g>=0.5&&r==0&&b<1&&b>=0.5) c=LIGHTCYAN;
		else if(r<1&&r>=0.5&&g<=0.5&&g>0&&b<=0.5&&b>0) c=BROWN;
		else c=WHITE;
		return c;
		}
//-------------------------------------------//
class fontC
		{
				unsigned int s;
				char f[24];
		public:
				colorC color;
				fontC();
				fontC(colorC , unsigned int, char []);
				void setFontColor(char []);
				void setFontSize(unsigned int);
				void setFontFace(char []);
				unsigned int size();
				char* face();
		};
fontC::fontC()
		{
		colorC c1("ffffff");
		color=c1;
		s=4;
		strcpy(f,"serif");
		}
fontC::fontC(colorC c1, unsigned int s1, char f1[24])
		{
		strcpy(f,f1);
		color=c1;
		//s=(s1%8);
		s=s1;
		}
void fontC::setFontColor(char c1[])
		{
		color.setColor(c1);
		}
void fontC::setFontSize(unsigned int s1)
		{
		//s=(s1%8);
		s=s1;
		}
void fontC::setFontFace(char f1[24])
		{
		strcpy(f,f1);
		}
unsigned int fontC::size()
		{
		return s;
		}
char* fontC::face()
		{
		return f;
		}
//-------------------------------------------//
class borderC
		{
				unsigned int s;
		public:
				colorC color;
				borderC();
				borderC(unsigned int , colorC );
				void setBorderWidth(unsigned int);
				void setBorderColor(char []);
				unsigned int size();
		};
borderC::borderC()
		{
		s=1;
		colorC c1("ffffff");
		color=c1;
		}
borderC::borderC(unsigned int s1, colorC c1)
		{
		s=s1;
		color=c1;
		}
void borderC::setBorderWidth(unsigned int s1)
		{
		s=s1;
		}
void borderC::setBorderColor(char c1[])
		{
		color.setColor(c1);
		}
unsigned int borderC::size()
		{
		return s;
		}
//-------------------------------------------//
class opC
		{
				unsigned int r;
				unsigned int c;
		public:
				opC();
				opC(unsigned int);
				void incChild(unsigned int);
				void incRank(int);
				unsigned int children();
				unsigned int rank();
		};
opC::opC()
		{
		r=0;
		c=0;
		}
opC::opC(unsigned int r1)
		{
		c=0;
		r=r1;
		}
void opC::incChild(unsigned int c1=1)
		{
		c+=c1;
		}
void opC::incRank(int r1=1)
		{
		r+=r1;
		}
unsigned int opC::children()
		{
		return c;
		}
unsigned int opC::rank()
		{
		return r;
		}
//-------------------------------------------//
class metaC
		{
				char i[20];
				char h[60];
		public:
		  
				metaC();
				metaC(char [],char []);
				void setId(char []);
				void setHref(char []);
				char* id();
				char* href();
		};
metaC::metaC()
		{
		i[0]='\0';
		h[0]='\0';
		}
metaC::metaC(char i1[],char h1[])
		{
		strcpy(i,i1);
		strcpy(h,h1);
		}
char* metaC::id()
		{
		return i;
		}
char* metaC::href()
		{
		return h;
		}
void metaC::setId(char i1[])
		{
		strcpy(i,i1);
		}
void metaC::setHref(char h1[])
		{
		strcpy(h,h1);
		}
 
//-------------------------------------------//
 
class generalC
		{
				char n[20];
				char s;
		public:
				generalC();
				generalC(char []);
				char* name();
				void setName(char []);
				void setSupported(char);
				unsigned int isSupported();
		};
generalC::generalC()
		{
		n[0]='\0';
		s='N';
		}
generalC::generalC(char n1[])
		{
		strcpy(n,n1);
		s='Y';
		}
char* generalC::name()
		{
		return n;
		}
void generalC::setName(char n1[])
		{
		strcpy(n,n1);
		s='y';
		}
void generalC::setSupported(char s1='Y')
		{
		s=s1;
		}
unsigned int generalC::isSupported()
		{
		unsigned int flag=0;
		if(s=='y'||s=='Y')
				{
				flag=1;
				}
		return flag;
		}
 
//-------------------------------------------//
class contentC
		{
				char tmp[20];
				fstream file;
		public:
				contentC();
				char* name();
				~contentC();
				void insert(char []);
				void insertChar(char);
				void clear();
				char* read();
				void reset(unsigned int);
				char readChar();
		};
contentC::contentC()
		{
		unsigned int r= random(9000)+1000;
		char s[20];
		itoa(r,s,10);
		strcpy(tmp,s);
		strcat(tmp,".txt");
		file.open(tmp,ios::in|ios::out);
		}
char* contentC::name()
		{
		return tmp;
		}
contentC::~contentC()
		{
		file.close();
		unlink(tmp);
		}
void contentC::insert(char line[80])
		{
		file<<line;
		}
void contentC::insertChar(char ch)
		{
		file<<ch;
		}
void contentC::clear()
		{
		file.clear();
		}
char* contentC::read()
		{
		char line[80];
		file.getline(line,80);
		return line;
		}
void contentC::reset(unsigned int ctr=0)
		{
		file.seekp(ctr);
		}
char contentC::readChar()
		{
		char ch;
		file.get(ch);
		return ch;
		}
//End- Types

//Begin- Elements
class style
		{
		protected:
				unsigned int h,w,t,l;
		public:
				colorC color,background;
				fontC font;
				borderC border;
				unsigned int height();
				unsigned int width();
				unsigned int top();
				unsigned int left();
				void setHeight(unsigned int);
				void setWidth(unsigned int);
				void setTop(unsigned int);
				void setLeft(unsigned int);
		};
void style::setHeight(unsigned int h1)
		{
		h=h1;
		}
void style::setWidth(unsigned int w1)
		{
		w=w1;
		}
void style::setTop(unsigned int t1)
		{
		t=t1;
		}
void style::setLeft(unsigned int l1)
		{
		l=l1;
		}
unsigned int style::height()
		{
		return h;
		}
unsigned int style::width()
		{
		return w;
		}
unsigned int style::top()
		{
		return t;
		}
unsigned int style::left()
		{
		return l;
		}
//-------------------------------------------//
class element: public style
		{
				char s;
		public:
				element *link;							//for q
				generalC general;						//name and support
				metaC meta;								//id & href
				opC op;									//rank & child
				contentC content;
				void setStyled(char);
				void displayProp();
				unsigned int isStyled();
				//element();
		};
void element::setStyled(char s1)
		{
		s=s1;
		}
unsigned int element::isStyled()
		{
		unsigned int flag=0;
		if(s=='y'||s=='Y')
				{
				flag=1;
				}
		return flag;
		}

void element::displayProp()
		{
		cout<<"---------------------------------\n"
			<<"PROPERTIES - "<<general.name()<<endl
			<<"---------------------------------\n"
			<<"Pointer: "<<link<<endl
			<<"Name: "<<general.name()<<endl
			<<"Support: "<<(general.isSupported())//?'Y':'N'<<endl
			<<"ID: "<<meta.id()<<endl
			<<"href: "<<meta.href()<<endl
			<<"Style: "<<(isStyled())//?'Y':'N'<<endl
			<<"---------------------------------\n"
			<<"\tHeight: "<<height()<<endl
			<<"\tWidth: "<<width()<<endl
			<<"\tTop: "<<top()<<endl
			<<"\tLeft: "<<left()<<endl
			<<"\tColor: #"<<color.hexValue()<<endl
			<<"\tBackground Color: #"<<background.hexValue()<<endl
			<<"\tFont Face: "<<font.face()<<endl
			<<"\tFont Size: "<<font.size()<<endl
			<<"\tFont Color: #"<<font.color.hexValue()<<endl
			<<"\tBorder Size: "<<border.size()<<endl
			<<"\tBorder Color: #"<<border.color.hexValue()<<endl
			<<"---------------------------------\n";
		}
 
//-------------------------------------------//
class queueC
		{
				element *Front, *Rear;
		public:
				element* insert();
				void removeLast();
				unsigned int count();
				element* process();
				void test();
 
				queueC();
				~queueC();
		};
element* queueC::insert()
		{
		element *T=new element;
		//Read element properties into T
		T->link=NULL;
		if(Rear==NULL)
				{
				Front=T;
				Rear=T;
				}
		else
				{
				Rear->link=T;
				Rear=T;
				}
		return Rear;
		}
		  
void queueC::removeLast()
		{
		if(Front!=NULL)
				{
				element *T=Front;
				Front=Front->link;
				delete T;
				if(Front==NULL) Rear=NULL;
				}
		}
 
unsigned int queueC::count()
		{
		unsigned int ctr;
		element *T=Front;
		while(T!=NULL)
				{
				ctr++;
				T=T->link;
				}
		return ctr;
		}
 
element* queueC::process()
		{
		element* tmp;
		if(Front!=NULL)
				{
				element *T=Front;
				Front=Front->link;
				tmp=T;
				//Process element
				delete T;
				if(Front==NULL) Rear=NULL;
				}
		return tmp;
		}
 
queueC::queueC()
		{
		Front=NULL;
		Rear=NULL;
		}

queueC::~queueC()
		{
		while(Front!=NULL)
				{
				element *T=Front;
				Front=Front->link;
				delete T;
				}
		}

void queueC::test()
		{
		element *T=Front;
		while(T!=NULL)
				{
				T->displayProp();
				T=T->link;
				}
		}
//End- Elements
//Begin- Parser

char statusMessage[180];
void setGeneral(element*, char []);				//correct
unsigned int isSupported(char []);				//correct
void readContent(fstream &, element*);			//correct
char* getToken(fstream &, char, unsigned int);	//correct
void parse(char [], queueC &);					//correct
void readElement(fstream &, element*);			//correct
void readStyle(fstream &, element*);			//correct


unsigned int isSupported(char name[])
		{
		unsigned int flag=0,i;
		char list[15][80]={"html","head","body","title","br","h1","h2","h3","h4","h5","h6","span","p","a","div"};
		for(i=0;i<3;i++)
				{
				if(!strcmpi(name,list[i])) flag=1;		//Not Supported. Unstyled.
				}
		for(i=3;i<5;i++)
				{
				if(!strcmpi(name,list[i])) flag=2;		//Supported. Unstyled.
				}
		for(i=5;i<15;i++)
				{
				if(!strcmpi(name,list[i])) flag=3;		//Supported. Styled.
				}
		return flag;
		}

void setGeneral(element* T, char tmp[])
		{
		T->general.setName(tmp);
		switch(isSupported(tmp))
				{
				case 1:
						T->general.setSupported('N');
						T->setStyled('N');
						break;
				case 2:
						T->general.setSupported('Y');
						T->setStyled('N');
						break;
				case 3:
						T->general.setSupported('Y');
						T->setStyled('Y');
						break;
				default:
						break;
				}
		}

void readContent(fstream &file, element* T)
		{
		char c='\0';
		while(c!='<')
				{
				file.get(c);
				if(c!='<')
						T->content.insertChar(c);
				else
						file.seekg(-sizeof(c));
				}
		}

char* getToken(fstream &file, char c1, unsigned int s=0)
		{
		char tmp[100];
		char c;
		int i=-1;
		for(int ctr=1;ctr<=s;ctr++) file.seekg(sizeof(c));
		while(c!=c1&&c!='>')
				{
				file.get(c);
				if(c!=c1&&c!='>')
						{
						++i;
						tmp[i]=c;
						}
				else if(c=='>')
						file.seekg(-sizeof(c));
				}
		tmp[i]='\0';
		return tmp;
		}

void readElement(fstream &file, element* T)
		{
		if(T==NULL)
				{
				return;
				}

		char tmp[100];					//read token
		char c='\0';					//read char

		strcpy(tmp,getToken(file,' '));	//read name
		setGeneral(T,tmp);				//read gen prop

		while(c!='>')
				{
				file.get(c);

				if(c=='>')
						{
						file.seekg(-sizeof(c));
						return;
						}

				strcpy(tmp,getToken(file,' '));
				if(strcmpi(tmp,"id=\"")==0)
						{
						T->meta.setId(getToken(file,'\"'));
						}
				else if(strcmpi(tmp,"href=\"")==0)
						{
						T->meta.setHref(getToken(file,'\"'));
						}
				else if(strcmpi(tmp,"style=\"")==0)
						{
						readStyle(file,T);
						}
				}
		}

void readStyle(fstream &file, element* T)
		{
		int a;
		char tmp[100];

		while(c!='\"')
				{
				file.get(c);
				if(c=='\"')
						{
						return;
						//file.seekg(-sizeof(c));
						}
				strcpy(tmp,getToken(file,':'));
				if(strcmpi(tmp,"height")==0)
						{
						a=atoi(getToken(file,';'));
						T->setHeight(a);
						}
				else if(strcmpi(tmp,"width")==0)
						{
						a=atoi(getToken(file,';'));
						T->setWidth(a);
						}
				else if(strcmpi(tmp,"top")==0)
						{
						a=atoi(getToken(file,';'));
						T->setTop(a);
						}
				else if(strcmpi(tmp,"left")==0)
						{
						a=atoi(getToken(file,';'));
						T->setLeft(a);
						}
				else if(strcmpi(tmp,"color")==0)
						{
						T->color.setColor(getToken(file,';',1));
						}
				else if(strcmpi(tmp,"background")==0)
						{
						T->background.setColor(getToken(file,';',1));
						}
				else if(strcmpi(tmp,"border-color")==0)
						{
						T->border.setBorderColor(getToken(file,';',1));
						}
				else if(strcmpi(tmp,"border-width")==0)
						{
						a=atoi(getToken(file,';'));
						T->border.setBorderWidth(a);
						}
				else if(strcmpi(tmp,"font-size")==0)
						{
						a=atoi(getToken(file,';'));
						T->font.setFontSize(a);
						}
				else if(strcmpi(tmp,"font-face")==0)
						{
						T->font.setFontFace(getToken(file,';'));
						}
				else if(strcmpi(tmp,"font-color")==0)
						{
						T->font.setFontColor(getToken(file,';',1));
						}
				}
		}

void parse(char filename[], queueC &q)
		{
//<types>
		int flag=-1, rank=0;				//counters
		char c;							//char read
		char tmp[100];					//store tokens

		element *T=NULL;				//element pointer

		fstream file;					//html file
//</types>

//<fopen>
		int i=0,j=0;
		char ext[4];					//Read File Extension
		while(filename[i]!='.')++i;
		++i;
		while(filename[i]!='\0'&&j<4)
				{
				ext[j]=tmp[i];
				j++;
				i++;
				}
		if(strcmpi(ext,"html")!=0||strcmpi(ext,"htm")!=0)
				{
				//cout<<"problem\n";
				strcpy(statusMessage,"Invalid File");
				return;
				}
		file.open(filename,ios::in);
		if(file.good()==0)				//To check
				{
				//cout<<"problem\n";
				strcpy(statusMessage,"Invalid File");
				return;
				}
//</fopen>

		while(!file.eof())
				{
				file.get(c);
				switch(c)
						{
						case '<':
								file.get(c);
								if(c=='/')
										{
										flag=0;
										getToken(file,'>');
										break;
										}
								else
										{
										file.seekg(-sizeof(c));
										flag=1;
										rank++;
										T=q.insert();
										readElement(file,T);
										T->op.incRank(rank-(T->op.rank()));
										}
								break;
						case '>':
								if(flag==1&&T!=NULL)
										{
										readContent(file,T);
										}
								else if(flag==0)
										{
										rank--;
										}
								break;
						default:
								file.get(c);
								break;
						}
				}
		}
//End- Parser

//Begin- Printer
unsigned int xmax,ymax;
void displayChrome();
void welcome();
void farewell();
void splashScreen();
void printer(queueC q);

void splashScreen()
		{
		clrscr();
		cout<<"About:SPUTNIK!\n";
		delay(5000);
		clrscr();
		gotoxy(11,12);
		cout<<"SPUTNIK 0.0.1b\n";
		delay(5000);
		clrscr();
		}

void welcome()
		{
		setcolor(1);
		setbkcolor(11);
		setfillstyle(0,1);
		clearviewport();
		rectangle(10,10,630,470);
		settextstyle(0,0,3);
		outtextxy(140,360,"Please fasten your seatbelts!");
		outtextxy(140,360,"SPUTNIK 0.0.1b");
		settextstyle(0,0,1);
		outtextxy(80, 450, "Developers: Ila Gokarn, Grace Khanuja, Diwank Singh");
		}

void farewell()
		{
		setcolor(1);
		setbkcolor(11);
		setfillstyle(0,1);
		clearviewport();
		rectangle(10,10,630,470);
		settextstyle(0,0,3);
		outtextxy(140,360,"Mind the parachute!");
		outtextxy(140,360,"SPUTNIK 0.0.1b");
		settextstyle(0,0,1);
		outtextxy(80, 450, "Developers: Ila Gokarn, Grace Khanuja, Diwank Singh");
		}

void displayChrome()
		{
		setcolor(1);
		setbkcolor(11);
		setfillstyle(0,1);
		clearviewport();
		rectangle(10,10,630,470);
		rectangle(60,280,120,310);
		rectangle(520,280,580,310);
		outtextxy(140,360,"Ship's on sail, Cap'n!");
		}

//End- Printer

//Begin- Main
void main()
		{
		clrscr();
		/*
		TESTS
		colorC c("ffffff");
		cout<<c.red()<<c.blue()<<c.green();
		contentC content;
		content.insertChar('a');
		content.reset();
		charch=content.readChar();
		cout<<ch<<endl;
		queueC queue;
		parse("sample.htm",queue);
		queue.test();
		circle(330,180,100);
		rectangle (10,30,500,400);
		ellipse(100,150,0,360,100,50);
		arc(120,160,300,90,70);
		line(100,50,100,400);
		getch();
		*/

		splashScreen();
		int gd=DETECT, gm, exit=0, mx, my, click;
		initgraph(&gd, &gm, "c:/tc/bgi ");
		welcome();
		displayChrome();
		mouseshow();
		do
				{
				mouseposi(mx,my,click);
				if(click==1)
						{
						delay(500);
						if(((mx>520)&&(mx<580))&&((my>280)&&(my<310)))
								{
								exit=1;
								}
						//if(((mx>60)&&(mx<120))&&((my>280)&&(my<310)))
								//{
								//Do something!
								//}
						}
				}
		while(exit==0);
		farewell();
		closegraph();
		restorecrtmode();
		getch();
		}
//End- Main