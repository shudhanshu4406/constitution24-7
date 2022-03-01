#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>




	  //1. move()     00
	  //2. reglog()   00
	  //3. reg()      00
	  //4. login()    00
	  //5. afterreglog() 00
	  //6. ask() //
	  //7. feedback() //
	  //8. news()     //
	  //9. welcome()
	  //10. loading()
	  //11. about()     00
	  //12. popupnc()   00
	  //13. popipinv()  00
	  //14. popupquit() 00
	  //15. decide(struct reg) 00
	  //16. submit(struct reg) 00
	  //17. popupinvreg()      00
	  //18. popupsuccess()     00
	  //19. lgin(struct lgg()  00
	  //20. popupsuccesslgin() 00
	  //21. popupinvusername() 00
	  //22. popupyourpass(char password[]) 00
	  //23. findpass(struct lgg)           00
	  //24. forgpass()      00
	  //25. adminlgin()     00
	  //26. popupsuccesslginadmin()     00
	  //27. popupinvadmin()             00
	  //28. admin()   00
	  //29. popupquit2()   00
	  //30. commingsoon()  00
	  //31. doyousubmit(struct upart r)  00
	  //32. artwrite(struct upart s)     00
	  //33. userartread()                00





struct reg{
char n1[15],n2[15],un[20],pas[15];
}n,m,p;

struct lgg{
char username[15],password[15];
}lg1,lg2,lg3;


struct upart{
int a,hour,min,day,month,year;
char t[2000],art[10000];
};








//move()


void move(int*x,int*y,int*b)
{
union REGS in,o;
in.x.ax=3;
int86(0x33,&in,&o);
*x=o.x.cx;
*y=o.x.dx;
*b=o.x.bx;
}


void reglog(void);

void reg(void);
void login(void);
void popupinv(void);
void popupnc(void);
void popupquit(void);
void decide(struct reg);
void submit(struct reg);
void popupinvreg();
void popupsuccess();
void lgin(struct lgg);
void popupsuccesslgin();
void forgpass();
void popupinvusername();
void popupyourpass(char password[]);
void findpass(struct lgg);
void about();
void afterreglog();
void adminlgin();
void popupsuccesslginadmin();
void popupinvadmin();
void admin();
void popupquit2();
void commingsoon();
void doyousubmit(struct upart s);
void adminwriteart();
void artwrite(struct upart s);
void userartread();





// void adminwriteart()


void adminwriteart()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
char ch;
struct upart f,q;
time_t now;
struct tm*tm_now;
struct date today;
FILE *fp;
//initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{   cleardevice();
popupnc();
}


setbkcolor(BLUE);
setcolor(WHITE);
setlinestyle(0,0,3);
setfillstyle(SOLID_FILL,8);
rectangle(20,0,619,30);
rectangle(580,5,609,25);
rectangle(30,5,59,25);
floodfill(67,10,WHITE);
setfillstyle(SOLID_FILL,4);
floodfill(590,10,WHITE);
floodfill(37,8,WHITE);
setcolor(YELLOW);
setlinestyle(0,0,3);
//line(20,50,619,50);
//line(20,50,20,460);
//line(20,460,619,460);
//line(619,50,619,460);
settextstyle(1,0,1);
outtextxy(590,3,"X");
outtextxy(40,4,"0");
outtextxy(250,3,"WRITE ARTICLE");
setlinestyle(0,0,3);
settextstyle(12,0,4);
setcolor(RED);
outtextxy(265,50,"ENTER TITLE:");
setcolor(WHITE);
line(1,70,640,70);
line(1,150,640,150); // title total 51200 characters
setcolor(RED);

outtextxy(260,170,"ENTER ARTICLE :");
setcolor(WHITE);
line(1,190,640,190);
line(1,400,640,400); // article total 134,400 characters
setfillstyle(SOLID_FILL,WHITE);
floodfill(53,125,WHITE);
floodfill(53,225,WHITE);
setcolor(7);
rectangle(250,420,380,450);   // submit button
setfillstyle(SOLID_FILL,YELLOW);
floodfill(270,440,7);
settextstyle(0,0,2);
setcolor(RED);
outtextxy(268,428,"SUBMIT");
setcolor(WHITE);
settextstyle(1,0,2);
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
//setcolor(WHITE);
setfillstyle(1,12);
if(b==1)
{
for(x1=582;x1<609;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
//rectangle(581,5,609,25);
floodfill(590,10,WHITE);           //back
delay(500);
fflush(stdin);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
admin();
}
for(x1=31;x1<59;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{  sound(150);
delay(100);
nosound();                       //exit
floodfill(36,10,WHITE);
delay(500);
exit(0);
}
for(x1=255;x1<375;x1++)
for(y1=425;y1<445;y1++)    //submit
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(270,440,7);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
//doyousubmit(q);
}
for(x1=1;x1<640;x1++)
for(y1=70;y1<150;y1++)
if(x==x1&&y==y1)
{
settextstyle(0,0,1);
setcolor(BLUE);
outtextxy(1,80,"I");
settextstyle(1,0,3);        //title
gotoxy(1,6);
gets(q.t);
ch=getch();
if(ch==13)
goto ARTICLE;
}
for(y1=1;y1<640;y1++)
for(x1=190;x1<395;x1++)
if(x==x1&&y==y1)
{
ARTICLE:
settextstyle(0,0,1);
setcolor(BLUE);
outtextxy(1,200,"I");
settextstyle(1,0,3);
gotoxy(1,13);
gets(q.art);
ch=getch();                      //article
if(ch==13)
{i.x.ax=2;
int86(0x33,&i,&o);
now=time(NULL);
tm_now=localtime(&now);
getdate(&today);
q.hour=tm_now->tm_hour;
q.min=tm_now->tm_min;
q.day=today.da_day;
q.month=today.da_mon;
q.year=today.da_year;


cleardevice();
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(BLACK);
setcolor(WHITE);
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
popupnc();
}

setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(200,170,"DO YOU WANT TO SUBMIT");
rectangle(220,230,280,260);
rectangle(340,230,400,260);
setfillstyle(1,8);
floodfill(225,235,WHITE);
floodfill(345,235,WHITE);
outtextxy(232,232,"YES");
outtextxy(358,232,"NO");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=225;x1<=275;x1++)
for(y1=235;y1<=255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();                      // yes
floodfill(235,245,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
fp=fopen("art3.txt","a+");
if(fp==NULL)
{
q.a=1;
fwrite(&q,sizeof(q),1,fp);
fclose(fp);
}
else
{
while(fread(&f,sizeof(f),1,fp)>0)
{
if(feof(fp))
{

fclose(fp);
break;
}
else
{
	q.a=f.a;
}
}
q.a=q.a+1;
fwrite(&q,sizeof(q),1,fp);
}
//fclose(fp);
cleardevice();
adminwriteart();
}

//artwrite(n1);
}
for(x1=340;x1<400;x1++)
for(y1=230;y1<260;y1++)
if(x==x1&&y==y1)
{                                   //no
sound(150);
delay(100);
nosound();
floodfill(355,240,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminwriteart();
}
for(x1=480;x1<510;x1++)
for(y1=105;y1<125;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(500,115,WHITE);         //X
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminwriteart();
}
}

//getch();
}



getch();
}

}
}

//getch();
}




//doyousubmit(struct upart r)



/*void doyousubmit(struct upart s)
{
union REGS i,o;
struct upart f;
//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
FILE *fp;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(BLACK);
setcolor(WHITE);
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
popupnc();
}

setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(200,170,"DO YOU WANT TO SUBMIT");
rectangle(220,230,280,260);
rectangle(340,230,400,260);
setfillstyle(1,8);
floodfill(225,235,WHITE);
floodfill(345,235,WHITE);
outtextxy(232,232,"YES");
outtextxy(358,232,"NO");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=225;x1<=275;x1++)
for(y1=235;y1<=255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();                      // yes
floodfill(235,245,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
fp=fopen("art2.txt","a+");
if(fp==NULL)
{
s.a=1;
fwrite(&s,sizeof(s),1,fp);
fclose(fp);
}
else
{
while(fread(&f,sizeof(f),1,fp)>0)
{
if(feof(fp))
{

fclose(fp);
break;
}
else
{
s.a=f.a;
}
}
s.a=s.a+1;
fwrite(&s,sizeof(s),1,fp);
}
//fclose(fp);
cleardevice();
adminwriteart();
}

//artwrite(n1);
}
for(x1=340;x1<400;x1++)
for(y1=230;y1<260;y1++)
if(x==x1&&y==y1)
{                                   //no
sound(150);
delay(100);
nosound();
floodfill(355,240,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminwriteart();
}
for(x1=480;x1<510;x1++)
for(y1=105;y1<125;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(500,115,WHITE);         //X
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminwriteart();
}
}

//getch();
}  */



//artwrite(struct upart s)



/*void artwrite(struct upart s)
{
FILE *fp;
time_t now;
struct upart f;

//struct date dt;
cleardevice();
//getdate(&dt);


fp=fopen("art2.txt","a+");
if(fp==NULL)
{
s.a=1;
fwrite(&s,sizeof(s),1,fp);
fclose(fp);
}
else
{
while(fread(&f,sizeof(f),1,fp)>0)
{
if(feof(fp))
{

fclose(fp);
break;
}
else
{
s.a=f.a;
}
}
s.a=s.a+1;
fwrite(&s,sizeof(s),1,fp);
}
//fclose(fp);
cleardevice();
adminwriteart();
}*/


//userartread()



void userartread()
{
int j,p,i,k,l,m,ww;
char ch;
FILE *fp;
textbackground(WHITE);
textcolor(RED);
struct upart n1,m1;
clrscr();
fp=fopen("art3.txt","a+");

while(fread(&m1,sizeof(m1),1,fp)>0)
{

if(feof(fp))
{
fclose(fp);
break;}
else
{
n1.day=m1.day;
n1.month=m1.month;
n1.year=m1.year;
n1.hour=m1.hour;
n1.min=m1.min;
n1.a=m1.a;
for(i=0;m1.t[i]!='\0';i++)
n1.t[i]=m1.t[i];
n1.t[i]='\0';
for(i=0;m1.art[i]!='\0';i++)
n1.art[i]=m1.art[i];
n1.art[i]='\0';

}
}
PREVNEXT:
ww=n1.a;
// border
textcolor(BLACK);

for(i=1;i<81;i++)
{
gotoxy(i,1);
cprintf("%c",220);
}
for(i=1;i<81;i++)
{
gotoxy(i,24);
cprintf("%c",220);
}
for(j=1;j<26;j++)
{
gotoxy(2,j);                     //border
cprintf("%c",219);
}
for(j=1;j<26;j++)
{
gotoxy(79,j);
cprintf("%c",219);
}
textcolor(RED+BLINK);
gotoxy(4,2);
cprintf("0");
gotoxy(77,2);
cprintf("X");
gotoxy(4,23);
cprintf("PREVIOUS : P");
gotoxy(70,23);
cprintf("NEXT : N");

textcolor(0);
gotoxy(36,3);
cprintf("TITLE:");
gotoxy(42,3);
cprintf("%d",n1.a);
textcolor(YELLOW);
gotoxy(69,3);
cprintf("%d/%d/%d",n1.day,n1.month,n1.year);
gotoxy(71,4);
cprintf("%d:%d",n1.hour,n1.min);


// arrangement
textcolor(8);

i=0;
p=5;
gotoxy(34,p);
while(i<strlen(n1.t))
{                                    //arrangement        title
cprintf("%c",n1.t[i]);
i++;
m=wherex();
if(m==46)
{ p++;
gotoxy(34,p);
}
}
textcolor(0);
gotoxy(36,p+2);
cprintf("ARTICLE:");
textcolor(8);
i=0;
k=p+4;
gotoxy(5,k);
while(i<strlen(n1.art))
{                                    //arrangement     article
cprintf("%c",n1.art[i]);
i++;
m=wherex();
if(m==78)
{ k++;
gotoxy(5,k);
}
}
textcolor(RED+BLINK);
gotoxy(4,25);
cprintf("ENTER:");
ch=getch();
if((ch==88)||(ch==120))
{
int gd=DETECT,gm ;
clrscr();
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 cleardevice();
afterreglog();
}
else if(ch==0)
{
exit(0);
}
else if(ch==80||ch==112)
{
ww--;
fp=fopen("art3.txt","a+");
while(fread(&m1,sizeof(m1),1,fp)>0)
{
if(m1.a==ww)
{
n1.day=m1.day;
n1.month=m1.month;
n1.year=m1.year;
n1.hour=m1.hour;
n1.min=m1.min;
n1.a=m1.a;
for(i=0;m1.t[i]!='\0';i++)
n1.t[i]=m1.t[i];
n1.t[i]='\0';
for(i=0;m1.art[i]!='\0';i++)
n1.art[i]=m1.art[i];
n1.art[i]='\0';
fclose(fp);
clrscr();
goto PREVNEXT;
}
}

}
else if(ch==78||ch==110)
{
ww++;
fp=fopen("art3.txt","a+");
while(fread(&m1,sizeof(m1),1,fp)>0)
{
if(m1.a==ww)
{
n1.day=m1.day;
n1.month=m1.month;
n1.year=m1.year;
n1.hour=m1.hour;
n1.min=m1.min;

n1.a=m1.a;
for(i=0;m1.t[i]!='\0';i++)
n1.t[i]=m1.t[i];
n1.t[i]='\0';
for(i=0;m1.art[i]!='\0';i++)
n1.art[i]=m1.art[i];
n1.art[i]='\0';
fclose(fp);
clrscr();
goto PREVNEXT;
}}}

getch();

}






// popupquit2();

void popupquit2()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
cleardevice();
//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}
fflush(stdin);



setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(200,170,"DO YOU WANT TO QUIT");
rectangle(220,230,280,260);
rectangle(340,230,400,260);
setfillstyle(1,8);
floodfill(225,235,WHITE);
floodfill(345,235,WHITE);
outtextxy(232,232,"YES");
outtextxy(358,232,"NO");
i.x.ax=1;
int86(0x33,&i,&o);

while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=225;x1<=275;x1++)
for(y1=235;y1<=255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(235,245,WHITE);
delay(500);
exit(0);
}
for(x1=340;x1<400;x1++)
for(y1=230;y1<260;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(355,240,WHITE);
delay(500);
fflush(stdin);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
admin();
//closegraph();
//delay(1000);
//getch();
}
for(x1=480;x1<510;x1++)
for(y1=105;y1<125;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(500,115,WHITE);
delay(500);
fflush(stdin);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
admin();
delay(1000);
//closegraph();
//getch();
}
}
}
//closegraph();
}







//decide();

void decide(struct reg m)
{
union REGS i,o;
if((m.n1[0]=='\0')||(m.n2[0]=='\0')||(m.un[0]=='\0')||(m.pas[0]=='\0'))
{
cleardevice();
//printf("%s",n2);
i.x.ax=2;
int86(0x33,&i,&o);
popupinvreg();
}
else
{ i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
submit(m);
}
//getch();

}




//about()


void about()
{
union REGS i,o;
//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
char ch;
cleardevice();
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{ cleardevice();
popupnc();
}


//initgraph(&gd,&gm,"c:\\tc\\bgi");
setbkcolor(BLUE);
setlinestyle(0,0,3);
setfillstyle(SOLID_FILL,8);
rectangle(20,0,619,30);
rectangle(580,5,609,25);
rectangle(30,5,59,25);
floodfill(67,10,WHITE);
setfillstyle(SOLID_FILL,4);
floodfill(590,10,WHITE);
floodfill(37,8,WHITE);
setcolor(YELLOW);
setlinestyle(0,0,3);
line(20,50,619,50);
line(20,50,20,460);
line(20,460,619,460);
line(619,50,619,460);
settextstyle(1,0,1);
outtextxy(590,3,"X");
outtextxy(40,4,"0");
outtextxy(260,3,"ABOUT ?");
setlinestyle(0,0,3);
//line(200,50,200,460);
settextstyle(0,0,1);
setcolor(WHITE);
outtextxy(45,70,"* Constitution 24*7 is an application where people can share their ");
outtextxy(60,85,"problems and can have a satisfactory answer with the power of cons-");
outtextxy(50,100,"-titution from the behind committee.");
outtextxy(45,125,"* This project is introduced to aware people with the constitution");
outtextxy(60,140,"so that they can fight against the atrocities.");
outtextxy(45,165,"* Main purpose of this concept is to provide a ray of hope to those");
outtextxy(60,180,"people who stuck in a complex situation and feel darkness in all path");
outtextxy(60,195,"and feel no other way is left.");
outtextxy(45,220,"* This approach is an initiative against atrocities on women,children");
outtextxy(60,235,"and on the poor people.");
outtextxy(45,260,"* This project makes people aware with the latest news and contribute");
outtextxy(60,275,"towards eduction of India.");
outtextxy(45,300,"* This concept plays an important role in getting the people of the ");
outtextxy(60,315,"country on the right path.");
outtextxy(45,340,"* This concept can play an important role in removing some of the ");
outtextxy(60,355,"critical problems of the country like poverty, crime, unemployment ,");
outtextxy(45,395,"* This is in progress prototype of our idea of Constitution 24*7,some");
outtextxy(60,410,"of the options will be open with it's new update.");
outtextxy(60,370," and persecution of people, etc.");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
//setcolor(WHITE);
setfillstyle(1,12);
if(b==1)
{
for(x1=582;x1<609;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(590,10,WHITE);
delay(500);
fflush(stdin);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}
for(x1=31;x1<59;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{  sound(150);
delay(100);
nosound();
floodfill(36,10,WHITE);
delay(500);
exit(0);
}
}
}

//getch();
}






//submit()



void submit(struct reg p)
{
union REGS i,o;
FILE *log;
log=fopen("login.txt","a");
//char password[15],username[20];
fwrite(&p,sizeof(p),1,log);
fclose(log);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
popupsuccess();
//clrscr();

}










//reglog()       register, login,about,quit

void reglog()
{
union REGS in,o;
int gd=DETECT,gm,i,j,x,y,x1,y1,b ;
//cleardevice();
in.x.ax=0;
int86(0x33,&in,&o);
if(o.x.ax==0)
{cleardevice();
popupnc();
}

initgraph(&gd,&gm,"c:\\tc\\bgi");
setcolor(YELLOW);
line(312,20,312,460);
setfillstyle(9,RED);
floodfill(320,30,YELLOW);
setcolor(WHITE);
setfillstyle(1,DARKGRAY);
settextstyle(7,0,2);
setlinestyle(0,0,3);
rectangle(108,50,246,100);
floodfill(110,60,WHITE);
outtextxy(120,60,"REGISTER");
rectangle(108,150,246,200);
floodfill(200,160,WHITE);
outtextxy(138,160,"LOGIN");
rectangle(108,250,246,300);
floodfill(200,260,WHITE);
outtextxy(138,260,"ABOUT");
rectangle(108,350,246,400);
floodfill(200,360,WHITE);
outtextxy(148,360,"QUIT");
setcolor(YELLOW);
setlinestyle(0,0,3);
setfillstyle(9,7);
line(0,0,0,700);
line(639,0,639,700);
line(0,0,639,0);
line(0,480,639,480);
line(20,20,20,460);
line(619,20,619,460);
line(20,20,619,20);
line(20,460,619,460);
line(0,0,20,20);
line(639,0,619,20);
line(0,480,20,460);
line(639,480,619,460);
setfillstyle(1,8);
floodfill(10,50,YELLOW);
floodfill(630,60,YELLOW);
setfillstyle(1,7);
floodfill(30,10,YELLOW);
floodfill(30,470,YELLOW);
setfillstyle(9,1);


floodfill(322,60,YELLOW);
setcolor(15);
settextstyle(4,0,4);
outtextxy(332,50,"SELECT OPTION");
rectangle(332,150,600,200);
setfillstyle(9,BROWN);
floodfill(340,160,WHITE);
rectangle(332,200,600,250);
setfillstyle(1,WHITE);
floodfill(340,210,WHITE);
rectangle(332,250,600,300);
setfillstyle(9,LIGHTGREEN);
floodfill(340,260,WHITE);
setcolor(8);
setfillstyle(1,8);
circle(466,225,25);
floodfill(467,228,8);
settextstyle(4,0,3);
setcolor(15);
outtextxy(335,350,"CONSTITUTION 24*7");

in.x.ax=1;
int86(0x33,&in,&o);
while(!kbhit())
{
move(&x,&y,&b);
if(b==1)
{
setfillstyle(2,13);
for(x1=112;x1<245;x1++)
for(y1=51;y1<99;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(200,60,WHITE);
delay(500);
in.x.ax=2;
int86(0x33,&in,&o);
cleardevice();
reg();
}
for(x1=112;x1<245;x1++)
for(y1=151;y1<199;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(200,160,WHITE);
delay(500);
in.x.ax=2;
int86(0x33,&in,&o);
cleardevice();
login();
}
for(x1=112;x1<245;x1++)
for(y1=252;y1<298;y1++)
if(x==x1&&y==y1)
{sound(150);
delay(100);
nosound();
floodfill(200,260,WHITE);
delay(500);
in.x.ax=2;
int86(0x33,&in,&o);
cleardevice();
about();
}
for(x1=112;x1<245;x1++)
for(y1=351;y1<399;y1++)
if(x==x1&&y==y1)
{sound(150);
delay(100);
nosound();
floodfill(200,360,WHITE);
delay(500);
in.x.ax=2;
int86(0x33,&in,&o);
cleardevice();
popupquit();
}
}
}
//getch();
}








//reg()   register

void reg()
{
union REGS i,o;
//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
char ch;
n.n1[0]='\0',n.n2[0]='\0',n.un[0]='\0',n.pas[0]='\0';
//initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{cleardevice();
popupnc();
}

setbkcolor(BLUE);
setfillstyle(SOLID_FILL,8);
setlinestyle(0,0,3);
rectangle(20,0,619,30);
rectangle(580,5,609,25);
rectangle(30,5,59,25);
floodfill(70,17,WHITE);
setfillstyle(1,4);
floodfill(585,7,WHITE);
floodfill(35,7,WHITE);
setcolor(YELLOW);
setlinestyle(0,0,3);
line(20,50,619,50);
line(20,50,20,460);
line(20,460,619,460);
line(619,50,619,460);
settextstyle(1,0,1);
outtextxy(590,3,"X");
outtextxy(40,4,"0");
outtextxy(295,3,"REGISTER");
setlinestyle(1,0,3);
line(200,50,200,460);

setlinestyle(0,0,3);
setfillstyle(SOLID_FILL,WHITE);
setcolor(WHITE);
rectangle(220,70,589,100);
rectangle(220,120,589,150);
rectangle(220,170,589,200);
rectangle(220,220,589,250);
floodfill(230,80,WHITE);
floodfill(230,130,WHITE);
floodfill(230,180,WHITE);
floodfill(230,230,WHITE);
setcolor(7);
setfillstyle(SOLID_FILL,YELLOW);
rectangle(335,332,455,367);
floodfill(340,340,7);
setcolor(RED);
settextstyle(0,0,2);
outtextxy(351,345,"SUBMIT");
settextstyle(1,0,2);
setcolor(7);
outtextxy(40,70,"FIRST NAME :");
outtextxy(40,120,"LAST NAME :");
outtextxy(40,170,"USERNAME  :");
outtextxy(40,220,"PASSWORD  :");
settextstyle(1,0,1);
outtextxy(30,430,"BY SHUDHANSHU");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setcolor(WHITE);
setfillstyle(1,12);
if(b==1)
{
for(x1=582;x1<609;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{ sound(150);
delay(100);
nosound();
//rectangle(581,5,609,25);
floodfill(595,15,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}
for(x1=31;x1<59;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
//rectangle(30,5,59,25);
floodfill(43,15,WHITE);
delay(500);
exit(0);
}
for(x1=336;x1<455;x1++)
for(y1=332;y1<367;y1++)
if(x==x1&&y==y1)
{ sound(150);
delay(100);
nosound();

floodfill(345,345,7);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
decide(n);
}
for(x1=225;x1<554;x1++)
for(y1=75;y1<95;y1++)
if(x==x1&&y==y1)
{
setcolor(BLUE+BLINK);
outtextxy(225,78,"I");
gotoxy(29,6);
gets(n.n1);
ch=getch();
if(ch==13)
goto NEXT1;
}
for(x1=225;x1<554;x1++)
for(y1=125;y1<145;y1++)
if(x==x1&&y==y1)
{    NEXT1:
setcolor(BLUE+BLINK);
outtextxy(225,122,"I");
gotoxy(29,9);
gets(n.n2);
ch=getch();
if(ch==13)
goto NEXT2;
}
for(x1=225;x1<554;x1++)
for(y1=175;y1<196;y1++)
if(x==x1&&y==y1)
{          NEXT2:
setcolor(BLUE+BLINK);
outtextxy(225,172,"I");
gotoxy(29,12);
gets(n.un);
ch=getch();
if(ch==13)
goto NEXT3;
}
for(x1=225;x1<554;x1++)
for(y1=225;y1<245;y1++)
if(x==x1&&y==y1)
{         NEXT3:
setcolor(BLUE+BLINK);
outtextxy(225,221,"I");
gotoxy(29,15);
gets(n.pas);
ch=getch();
{
if(ch==13)
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
decide(n);
}
}
}
}
//getch();

}



  //login()  login page  caLL popupnc




void login()
{
union REGS i,o;
//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
char ch;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{   cleardevice();
popupnc();
}


setbkcolor(BLUE);
setlinestyle(0,0,3);
setfillstyle(SOLID_FILL,8);
rectangle(20,0,619,30);
rectangle(580,5,609,25);
rectangle(30,5,59,25);
floodfill(67,10,WHITE);
setfillstyle(SOLID_FILL,4);
floodfill(590,10,WHITE);
floodfill(37,8,WHITE);
setcolor(YELLOW);
setlinestyle(0,0,3);
line(20,50,619,50);
line(20,50,20,460);
line(20,460,619,460);
line(619,50,619,460);
settextstyle(1,0,1);
outtextxy(590,3,"X");
outtextxy(40,4,"0");
outtextxy(295,3,"LOGIN");
setlinestyle(0,0,3);
//line(200,50,200,460);
settextstyle(1,0,3);
setcolor(WHITE);
outtextxy(200,70,"ENTER USERNAME :");
rectangle(50,120,589,150);
outtextxy(200,170,"ENTER PASSWORD :");
rectangle(50,220,589,250);
setfillstyle(SOLID_FILL,WHITE);
floodfill(53,125,WHITE);
floodfill(53,225,WHITE);
setcolor(7);
rectangle(220,300,380,340);
rectangle(190,370,410,410);
setfillstyle(1,YELLOW);
floodfill(225,330,7);
setfillstyle(1,8);
floodfill(195,375,7);
settextstyle(0,0,2);
setcolor(RED);
outtextxy(255,312,"SUBMIT");
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(210,377,"FORGOT PASSWORD");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
//setcolor(WHITE);
setfillstyle(1,12);
if(b==1)
{
for(x1=582;x1<609;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
//rectangle(581,5,609,25);
floodfill(590,10,WHITE);
delay(500);
fflush(stdin);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}
for(x1=31;x1<59;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{  sound(150);
delay(100);
nosound();
//rectangle(30,5,59,25);
floodfill(36,10,WHITE);
delay(500);
exit(0);
}
for(x1=230;x1<375;x1++)
for(y1=305;y1<350;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(345,325,7);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
lgin(lg1);
}
for(x1=195;x1<405;x1++)
for(y1=365;y1<405;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(205,375,7);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
forgpass();
}

for(x1=55;x1<584;x1++)
for(y1=125;y1<145;y1++)
if(x==x1&&y==y1)
{
settextstyle(0,0,2);
setcolor(BLUE);
outtextxy(55,130,"I");
settextstyle(1,0,3);
gotoxy(8,9);
gets(lg1.username);
ch=getch();
if(ch==13)
goto LOGIN;
}
for(y1=225;y1<245;y1++)
for(x1=55;x1<584;x1++)
if(x==x1&&y==y1)
{
LOGIN:
settextstyle(0,0,2);
setcolor(BLUE);
outtextxy(55,225,"I");
settextstyle(1,0,3);
gotoxy(8,15);
gets(lg1.password);
ch=getch();
if(ch==13)
{
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
lgin(lg1);
//getch();
}
}

}
}

//getch();
}




//popupinv()      invalid username and password




void popupinv()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}

setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(150,170,"INVALID USERNAME OR PASSWORD");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(292,232,"O K");
i.x.ax=1;
int86(0x33,&i,&o);

while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
login();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
login();
}
}
}
//getch();
}



//popupnc()  mouse not connected



void popupnc()
{
union REGS i,o;

//int gd=DETECT,gm ;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}

setbkcolor(BLACK);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(200,170,"MOUSE NOT CONNECTED");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(292,232,"O K");
i.x.ax=1;
int86(0x33,&i,&o);

getch();
}













//popupquit()    do you want to quit yes or no



void popupquit()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}

setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(200,170,"DO YOU WANT TO QUIT");
rectangle(220,230,280,260);
rectangle(340,230,400,260);
setfillstyle(1,8);
floodfill(225,235,WHITE);
floodfill(345,235,WHITE);
outtextxy(232,232,"YES");
outtextxy(358,232,"NO");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=225;x1<=275;x1++)
for(y1=235;y1<=255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(235,245,WHITE);
delay(500);
exit(0);
}
for(x1=340;x1<400;x1++)
for(y1=230;y1<260;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(355,240,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}
for(x1=480;x1<510;x1++)
for(y1=105;y1<125;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(500,115,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}
}
}
//getch();
}





//popupinvreg()


void popupinvreg()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b ;
cleardevice();
//initgraph(&gd,&gm,"c:\\tc\\bgi");
 i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}


setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(150,170,"INVALID DETAILS, RE-ENTER");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(292,232,"O K");

i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reg();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reg();
}
}
}
//getch();
}






//popupsuccess()

	   void popupsuccess()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b ;
//cleardevice();
    setbkcolor(BLACK);
setcolor(WHITE);
//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}
//i.x.ax=2;
//int86(0x33,&i,&o);
 // delay(500);

setlinestyle(0,0,3);

rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,GREEN);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setfillstyle(1,BLUE);
floodfill(130,160,WHITE);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(188,170,"REGISTERED SUCCESSFULLY");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(285,232,"NEXT");

i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
afterreglog();
}
}
}
//getch();
}



//popupsuccesslgin()

 void popupsuccesslgin()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b ;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}

setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,GREEN);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setfillstyle(1,BLUE);
floodfill(130,160,WHITE);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(188,170,"LOGGED IN SUCCESSFULLY");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(285,232,"NEXT");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
afterreglog();
}
}
}
//getch();
}



//lgin(struct lgg lg2)


void lgin(struct lgg lg2)
{
union REGS i,o;
int k=0;
FILE *log;
cleardevice();
log=fopen("login.txt","a+");
while(fread(&p,sizeof(p),1,log)>0)
{
if(strcmp(lg2.username,p.un)==0&&strcmp(lg2.password,p.pas)==0)
{
fclose(log);
k=1;
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();

popupsuccesslgin();
//clrscr();

}
}
if(k!=1)
{
fclose(log);
k=0;
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
popupinv();
//clrscr();
}
//fclose(log);
//getch();
}



//forgpass();


void forgpass()
{
union REGS i,o;
//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
char ch;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}


setbkcolor(BLUE);
setcolor(WHITE);
setlinestyle(0,0,3);
setfillstyle(SOLID_FILL,8);
rectangle(20,0,619,30);
rectangle(580,5,609,25);
rectangle(30,5,59,25);
floodfill(67,10,WHITE);
setfillstyle(SOLID_FILL,4);
floodfill(590,10,WHITE);
floodfill(37,8,WHITE);
setcolor(YELLOW);
setlinestyle(0,0,3);
line(20,50,619,50);
line(20,50,20,460);
line(20,460,619,460);
line(619,50,619,460);
settextstyle(1,0,1);
outtextxy(590,3,"X");
outtextxy(40,4,"0");
outtextxy(230,3,"FORGOT PASSWORD");
setlinestyle(0,0,3);
settextstyle(1,0,3);
setcolor(WHITE);
outtextxy(200,70,"ENTER USERNAME :");
rectangle(50,120,589,150);
setfillstyle(SOLID_FILL,WHITE);
floodfill(53,125,WHITE);
setcolor(7);
rectangle(220,300,380,340);
setfillstyle(1,YELLOW);
floodfill(225,330,7);
settextstyle(0,0,2);
setcolor(RED);
outtextxy(255,312,"SUBMIT");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=582;x1<609;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(590,10,WHITE);
delay(500);
fflush(stdin);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
login();
}
for(x1=31;x1<59;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{  sound(150);
delay(100);
nosound();
floodfill(36,10,WHITE);
delay(500);
exit(0);
}
for(x1=230;x1<375;x1++)
for(y1=305;y1<350;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(345,325,7);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
findpass(lg3);
}

for(x1=55;x1<584;x1++)
for(y1=125;y1<145;y1++)
if(x==x1&&y==y1)
{
settextstyle(0,0,2);
setcolor(BLUE);
outtextxy(55,130,"I");
settextstyle(1,0,3);
gotoxy(8,9);
gets(lg3.username);
ch=getch();
if(ch==13)
findpass(lg3);
}
}
}
//getch();
}




//findpass(struct lgg lg2)


void findpass(struct lgg lg2)
{
union REGS in,o;
int k=0,i;
FILE *log;
char pp[15];
//clrscr();
log=fopen("login.txt","a+");
while(fread(&p,sizeof(p),1,log)>0)
{
if(strcmp(lg2.username,p.un)==0)
{
k=1;
for(i=0;p.pas[i]!='\0';i++)
pp[i]=p.pas[i];
pp[i]='\0';
fclose(log);
popupyourpass(pp);

}
}
if(k!=1)
{
fclose(log);
k=0;
in.x.ax=2;
int86(0x33,&in,&o);
cleardevice();
popupinvusername();
}
}



//popupinvusername()



void popupinvusername()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}

setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(150,170,"USERNAME NOT FOUND,RE-ENTER");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(292,232,"O K");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
forgpass();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
forgpass();
}
}
}
//getch();
}





//popupyourpass()




void popupyourpass(char password[])
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b ;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
popupnc();
}

setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,GREEN);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setfillstyle(1,BLUE);
floodfill(130,160,WHITE);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(188,170,"YOUR PASSWORD IS :");
outtextxy(188,200,password);
//sprintf("PASSWORD :","%s", password);
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(292,232,"O K");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
login();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
login();
}
}
}
//getch();
}



//afterreglog()

void afterreglog()
{
union REGS i,o;
//int gd=DETECT,gm;
int k,j,x,y,x1,y1,b ;
cleardevice();
//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}

setbkcolor(BLACK);
setcolor(0);
setlinestyle(0,0,3);
setcolor(BLUE);
rectangle(30,30,610,450);
rectangle(60,60,580,420);
rectangle(90,90,550,390);
setfillstyle(7,BROWN);
floodfill(25,25,BLUE);
setfillstyle(7,WHITE);
floodfill(45,45,BLUE);
setfillstyle(7,GREEN);
floodfill(85,85,BLUE);
setfillstyle(1,BLUE);
floodfill(100,100,BLUE);


setcolor(BLACK);
//setlinestyle(0,0,2);
fflush(stdin);
rectangle(160,130,300,160);
rectangle(160,220,300,250);
rectangle(160,320,300,350);
rectangle(340,130,480,160);
rectangle(340,220,480,250);
rectangle(340,320,480,350);

rectangle(30,5,59,25);
rectangle(580,5,609,25);

setfillstyle(1,YELLOW);
floodfill(165,135,BLACK);
floodfill(165,225,BLACK);
floodfill(165,325,BLACK);
floodfill(385,135,BLACK);
floodfill(385,225,BLACK);
floodfill(385,325,BLACK);
setfillstyle(SOLID_FILL,WHITE);
floodfill(40,10,BLACK);
floodfill(600,20,BLACK);
setcolor(BLACK);
settextstyle(12,0,1);
outtextxy(195,140,"ASK QUES");
outtextxy(166,230,"TRENDING ARTICLE");
outtextxy(170,330,"NEWS OF THE DAY");
outtextxy(365,140,"ADMIN LOGIN");
outtextxy(375,230,"FEEDBACK");
outtextxy(360,330,"CHAT WITH US");
setcolor(RED);
settextstyle(1,0,1);
outtextxy(590,3,"X");
outtextxy(40,4,"0");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setcolor(WHITE);
setfillstyle(1,12);
if(b==1)
{
for(x1=165;x1<295;x1++)
for(y1=135;y1<155;y1++)
if(x==x1&&y==y1)
{ sound(150);
delay(100);
nosound();
//rectangle(581,5,609,25);
floodfill(170,140,BLACK);
delay(500);
//i.x.ax=2;
//int86(0x33,&i,&o);
//cleardevice();
//goto
}
for(x1=165;x1<295;x1++)
for(y1=225;y1<245;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
//rectangle(30,5,59,25);
floodfill(170,225,BLACK);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
closegraph();
userartread();
}
for(x1=165;x1<295;x1++)
for(y1=325;y1<345;y1++)
if(x==x1&&y==y1)
{ sound(150);
delay(100);
nosound();

floodfill(170,325,BLACK);
delay(500);
//i.x.ax=2;
//int86(0x33,&i,&o);
//cleardevice();
//goto
}
for(x1=345;x1<475;x1++)
for(y1=135;y1<155;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();

floodfill(350,140,BLACK);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminlgin();
}
for(x1=345;x1<475;x1++)
for(y1=225;y1<245;y1++)
if(x==x1&&y==y1)
{         sound(150);
delay(100);
nosound();

floodfill(350,230,BLACK);
delay(500);
//i.x.ax=2;
//int86(0x33,&i,&o);
//cleardevice();
//goto
}
for(x1=345;x1<475;x1++)
for(y1=325;y1<345;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();

floodfill(350,330,BLACK);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
commingsoon();
}
for(x1=32;x1<58;x1++)
for(y1=8;y1<21;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();

floodfill(40,10,BLACK);
delay(500);
exit(0);
}
for(x1=585;x1<604;x1++)
for(y1=8;y1<21;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();

floodfill(600,20,BLACK);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
reglog();
}

}
}
//getch();

}




//adminlgin()


void adminlgin()
{
union REGS in,o;
//int gd=DETECT,gm;
int x,y,b,x1,y1 ;
char ch,u[11]="shudhanshu",p[10]="thecoders",username[15],password[15];
cleardevice();
//initgraph(&gd,&gm,"c:\\tc\\bgi");
  in.x.ax=0;
int86(0x33,&in,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}


setbkcolor(BLUE);
setcolor(WHITE);
setlinestyle(0,0,3);
setfillstyle(SOLID_FILL,8);
rectangle(20,0,619,30);
rectangle(580,5,609,25);
rectangle(30,5,59,25);
floodfill(67,10,WHITE);
setfillstyle(SOLID_FILL,4);
floodfill(590,10,WHITE);
floodfill(37,8,WHITE);
setcolor(YELLOW);
setlinestyle(0,0,3);
line(20,50,619,50);
line(20,50,20,460);
line(20,460,619,460);
line(619,50,619,460);
settextstyle(1,0,1);
outtextxy(590,3,"X");
outtextxy(40,4,"0");
outtextxy(250,3,"ADMIN LOGIN");
setlinestyle(0,0,3);
//line(200,50,200,460);
settextstyle(1,0,3);
setcolor(WHITE);
outtextxy(200,70,"ENTER USERNAME :");
rectangle(50,120,589,150);
outtextxy(200,170,"ENTER PASSWORD :");
rectangle(50,220,589,250);
setfillstyle(SOLID_FILL,WHITE);
floodfill(53,125,WHITE);
floodfill(53,225,WHITE);
setcolor(7);
rectangle(220,300,380,340);
//rectangle(190,370,410,410);
setfillstyle(1,YELLOW);
floodfill(225,330,7);
//setfillstyle(1,8);
//floodfill(195,375,7);
settextstyle(0,0,2);
setcolor(RED);
outtextxy(255,312,"SUBMIT");
//setcolor(WHITE);
//settextstyle(1,0,2);
//outtextxy(210,377,"FORGOT PASSWORD");
in.x.ax=1;
int86(0x33,&in,&o);
while(!kbhit())
{
move(&x,&y,&b);
//setcolor(WHITE);
setfillstyle(1,12);
if(b==1)
{
for(x1=582;x1<609;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
//rectangle(581,5,609,25);
floodfill(590,10,WHITE);
delay(500);
fflush(stdin);
in.x.ax=2;
int86(0x33,&in,&o);           //back
cleardevice();
afterreglog();
}
for(x1=31;x1<59;x1++)
for(y1=5;y1<25;y1++)
if(x==x1&&y==y1)
{  sound(150);
delay(100);
nosound();
//rectangle(30,5,59,25);
floodfill(36,10,WHITE);
delay(500);
exit(0);
}
for(x1=230;x1<375;x1++)
for(y1=305;y1<350;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(345,325,7);
delay(500);
//cleardevice();
if(strcmp(username,u)==0&&strcmp(password,p)==0)
{
in.x.ax=2;
int86(0x33,&in,&o);
cleardevice();
popupsuccesslginadmin();
}
else
{
in.x.ax=2;
int86(0x33,&in,&o);
  cleardevice();
popupinvadmin();
 }
}
for(x1=55;x1<584;x1++)
for(y1=125;y1<145;y1++)
if(x==x1&&y==y1)
{
settextstyle(0,0,2);
setcolor(BLUE);
outtextxy(55,130,"I");
settextstyle(1,0,3);
gotoxy(8,9);
gets(username);
ch=getch();
if(ch==13)
goto LOGIN;
}
for(y1=225;y1<245;y1++)
for(x1=55;x1<584;x1++)
if(x==x1&&y==y1)
{
LOGIN:
settextstyle(0,0,2);
setcolor(BLUE);
outtextxy(55,225,"I");
settextstyle(1,0,3);
gotoxy(8,15);
gets(password);
ch=getch();
if(ch==13)
{
if(strcmp(username,u)==0&&strcmp(password,p)==0)
{
in.x.ax=2;
int86(0x33,&in,&o);
   cleardevice();
popupsuccesslginadmin();
}
else
{
in.x.ax=2;
int86(0x33,&in,&o);
 cleardevice();
popupinvadmin();
 }
}
//getch();
}

}
}

//getch();
}



//popupinvadmin()



void popupinvadmin()
{
union REGS i,o;

//int gd=DETECT,gm ;
int x,y,x1,y1,b;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{
cleardevice();
popupnc();
}

setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,BLUE);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(150,170,"INVALID USERNAME OR PASSWORD");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(292,232,"O K");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminlgin();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminlgin();
}
}
}
//getch();
}




//popupsuccesslginadmin()



void popupsuccesslginadmin()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b ;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{ cleardevice();
popupnc();
}

setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,GREEN);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setfillstyle(1,BLUE);
floodfill(130,160,WHITE);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(188,170,"LOGGED IN SUCCESSFULLY");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(285,232,"NEXT");

i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminlgin();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
admin();
}
}
}
//getch();
}




//admin();



void admin()
{

union REGS i,o;
//int gd=DETECT,gm,
int k,j,x,y,x1,y1,b ;
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{cleardevice();
popupnc();
}


cleardevice();
//initgraph(&gd,&gm,"c:\\tc\\bgi");
setfillstyle(9,RED);
//setbkcolor(RED);
setcolor(YELLOW);
setfillstyle(1,DARKGRAY);

setlinestyle(0,0,3);
setfillstyle(9,7);
line(0,0,0,700);
line(639,0,639,700);
line(0,0,639,0);
line(0,480,639,480);
line(20,20,20,460);
line(619,20,619,460);
line(20,20,619,20);
line(20,460,619,460);
line(0,0,20,20);
line(639,0,619,20);
line(0,480,20,460);
line(639,480,619,460);
setfillstyle(9,LIGHTGREEN);
floodfill(10,50,YELLOW);
floodfill(630,60,YELLOW);
setfillstyle(9,GREEN);
floodfill(30,10,YELLOW);
floodfill(30,470,YELLOW);
setfillstyle(9,4);
//line(312,20,312,460);

floodfill(322,60,YELLOW);
setcolor(15);
settextstyle(4,0,4);
outtextxy(332,50,"SELECT OPTION");
rectangle(400,150,500,200);
setfillstyle(1,8);
floodfill(405,160,WHITE);
//rectangle(332,200,600,250);
//setfillstyle(1,WHITE);
//floodfill(340,210,WHITE);
rectangle(400,250,500,300);
setfillstyle(1,8);
floodfill(405,260,WHITE);
setcolor(8);
setfillstyle(1,8);
//circle(466,225,25);
//floodfill(467,228,8);
settextstyle(4,0,3);
setcolor(15);
outtextxy(410,350,"ADMIN");
settextstyle(12,0,2);
setlinestyle(0,0,3);
rectangle(108,50,246,100);
floodfill(110,60,WHITE);

outtextxy(140,70,"FEEDBACKS");
rectangle(108,150,246,200);
floodfill(200,160,WHITE);
outtextxy(130,170,"UPLOAD NEWS");
rectangle(108,250,246,300);
floodfill(200,260,WHITE);
outtextxy(120,270,"UPLOAD ARTICLE");
rectangle(108,350,246,400);
floodfill(200,360,WHITE);
outtextxy(148,370,"ANSWER");
outtextxy(435,170,"BACK");
outtextxy(435,270,"QUIT");
setcolor(YELLOW);

i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
if(b==1)
{
setfillstyle(2,13);
for(x1=112;x1<245;x1++)
for(y1=51;y1<99;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(200,60,WHITE);
delay(500);
//i.x.ax=2;
//int86(0x33,&i,&o);
//cleardevice();
//goto
}
for(x1=112;x1<245;x1++)
for(y1=151;y1<199;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(200,160,WHITE);
delay(500);
//i.x.ax=2;
//int86(0x33,&i,&o);
//cleardevice();
//goto
}
for(x1=112;x1<245;x1++)
for(y1=252;y1<298;y1++)
if(x==x1&&y==y1)
{sound(150);
delay(100);
nosound();
floodfill(200,260,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminwriteart();
}
for(x1=112;x1<245;x1++)
for(y1=351;y1<399;y1++)
if(x==x1&&y==y1)
{sound(150);
delay(100);
nosound();
floodfill(200,360,WHITE);
delay(500);
//i.x.ax=2;
//int86(0x33,&i,&o);
//cleardevice();
//goto
}
for(x1=405;x1<495;x1++)
for(y1=155;y1<195;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(410,160,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
adminlgin();
}
for(x1=405;x1<495;x1++)
for(y1=255;y1<295;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(410,260,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
popupquit2();
}
}
}
}








//commingsoon();


void commingsoon()
{
union REGS i,o;

//int gd=DETECT,gm;
int x,y,x1,y1,b ;
cleardevice();

//initgraph(&gd,&gm,"c:\\tc\\bgi");
i.x.ax=0;
int86(0x33,&i,&o);
if(o.x.ax==0)
{cleardevice();
popupnc();
}


setbkcolor(BLACK);
setcolor(WHITE);
setlinestyle(0,0,3);
rectangle(100,100,532,330);
rectangle(100,100,532,130);
setfillstyle(1,YELLOW);
floodfill(110,140,WHITE);
setfillstyle(1,8);
floodfill(110,110,WHITE);
rectangle(480,105,510,125);
setfillstyle(1,RED);
floodfill(483,107,WHITE);
setcolor(YELLOW);
settextstyle(1,0,1);
outtextxy(490,103,"X");
delay(500);
setcolor(WHITE);
rectangle(120,150,512,310);
setfillstyle(1,BLUE);
floodfill(130,160,WHITE);
setcolor(WHITE);
settextstyle(1,0,2);
outtextxy(245,170,"COMING SOON");
rectangle(280,230,340,260);
setfillstyle(1,8);
floodfill(285,235,WHITE);
outtextxy(292,232,"O K");
i.x.ax=1;
int86(0x33,&i,&o);
while(!kbhit())
{
move(&x,&y,&b);
setfillstyle(1,12);
if(b==1)
{
for(x1=485;x1<505;x1++)
for(y1=110;y1<120;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(485,110,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
afterreglog();
}
for(x1=285;x1<335;x1++)
for(y1=235;y1<255;y1++)
if(x==x1&&y==y1)
{
sound(150);
delay(100);
nosound();
floodfill(285,235,WHITE);
delay(500);
i.x.ax=2;
int86(0x33,&i,&o);
cleardevice();
afterreglog();
}
}
}
//getch();
}

