//graphics component
  /* Snake and Ladder Table */
#include<stdio.h> 
#include<graphics.h>
#include<iostream>
#include<conio.h>
using namespace std;
/*int main()
{
int i=0,j=0,k=5;
int gd = DETECT,gm;
void ladder1();
void ladder2();
void snek1();
void snek2();
void snek3();
void numbering();
initgraph(&gd,&gm,"c:\tc\bgi");
for(i=0;i<=360;i+=40)
for(j=0;j<=360;j+=40)
{
    setfillstyle(1,k);
  bar(50+j,30+i,90+j,70+i);
  k+=2;
}
ladder1();
ladder2();
snek1();
snek2();
snek3();
numbering();
getch();
} 
void ladder1()
{
int m,n;
for(m=0;m<=250;m+=250)
for(n=0;n<=m;n+=250)
{
setcolor(14);//yellow
line(53+m,57+n,55+m,55+n);
line(53+m,57+n,133+m,137+n);
line(55+m,55+n,135+m,135+n);
line(133+m,137+n,135+m,135+n);
setfillstyle(1,14);
floodfill(55+m,58+n,8);
line(68+m,42+n,70+m,40+n);
line(68+m,42+n,148+m,122+n);
line(70+m,40+n,150+m,120+n);
line(148+m,122+n,150+m,120+n);
floodfill(70+m,43+n,8);
line(65+m,65+n,78+m,52+n);
line(68+m,68+n,81+m,55+n);
floodfill(79+m,54+n,8);
line(75+m,75+n,88+m,62+n);
line(78+m,78+n,91+m,65+n);
floodfill(89+m,64+n,8);
line(85+m,85+n,98+m,72+n);
line(88+m,88+n,101+m,75+n);
floodfill(99+m,74+n,8);
line(95+m,95+n,108+m,82+n);
line(98+m,98+n,111+m,85+n);
floodfill(109+m,84+n,8);
line(105+m,105+n,118+m,92+n);
line(108+m,108+n,121+m,95+n);
floodfill(119+m,94+n,8);
line(115+m,115+n,128+m,102+n);
line(118+m,118+n,131+m,105+n);
floodfill(129+m,104+n,8);
line(125+m,125+n,138+m,112+n);
line(128+m,128+n,141+m,115+n);
floodfill(139+m,114+n,8);
}
}
void ladder2()
{
int p,q=0;
for(p=0;p<=180;p+=155)
{
line(100+p,330-q,140+p,290-q);
line(100+p,330-q,102+p,332-q);
line(102+p,332-q,142+p,292-q);
line(142+p,292-q,140+p,290-q);
floodfill(141+p,292-q,8);
line(115+p,345-q,155+p,305-q);
line(115+p,345-q,117+p,347-q);
line(117+p,347-q,157+p,307-q);
line(157+p,307-q,155+p,305-q);
floodfill(155+p,307-q,8);
line(112+p,322-q,125+p,335-q);
line(114+p,320-q,127+p,333-q);
floodfill(125+p,334-q,8);
line(122+p,312-q,135+p,325-q);
line(124+p,310-q,137+p,323-q);
floodfill(135+p,324-q,8);
line(132+p,302-q,145+p,315-q);
line(134+p,300-q,147+p,313-q);
floodfill(145+p,314-q,8);
q+=95;
}
}
void snek1()
{
int x,y=0,h=2;
for(x=0;x<=200;x+=125)
{
arc(120+x,110+y,10,85,60);
arc(258+x,85+y,190,240,80);
arc(112+x,118+y,10,80,60);
arc(250+x,93+y,190,290,80);
arc(275+x,100+y,250,270,70);
line(250+x,170+y,250+x,165+y);
line(250+x,165+y,230+x,160+y);
line(230+x,160+y,218+x,155+y);
line(130+x,50+y,115+x,47+y);
line(121+x,59+y,106+x,52+y);
line(106+x,52+y,114+x,48+y);
circle(114+x,52+y,1);
setfillstyle(1,h);
floodfill(116+x,52+y,8);
 y+=230;
 h+=8;
}
}
void snek2()
{
arc(130,220,150,180,40);
arc(130,220,180,253,40);
arc(105,328,273,80,70);
arc(143,220,150,180,40);
arc(143,215,180,230,40);
arc(112,328,265,50,75);
arc(80,354,45,72,115);
line(102,400,104,402);
line(102,400,107,399);
line(95,200,110,185);
line(110,185,109,200);
line(110,185,111,182);
circle(104,198,1);
setfillstyle(1,12);
floodfill(103,199,8);
}
void snek3()
{
arc(255,118,320,0,170);
arc(265,118,305,0,170);
line(384,229,361,260);
line(425,120,429,105);
line(428,105,435,120);
line(428,105,429,100);
circle(430,115,1);
setfillstyle(1,6);
floodfill(430,117,8);
}
void numbering()
{
outtextxy(50,393,"1    2    3    4    5    6    7    8    9    10");
outtextxy(50,363,"20   19   18   17   16   15   14   13   12   11");
outtextxy(50,333,"21   22   23   24   25   26   27   28   29   30");
outtextxy(50,303,"40   39   38   37   36   35   34   33   32   31");
outtextxy(50,273,"41        43   44   45        47   48        50");
outtextxy(50,243,"60        58   57   56   55        53   52     ");
outtextxy(50,213,"61   62   63   64        66   67   68   69     ");
outtextxy(50,183,"80   79             76   75   74   73        71");
outtextxy(50,153,"81        83   84   85   86   87        89   90");
outtextxy(50,123,"100  99   98   97   96   95   94   93   92   91");
//outtextxy(50, 93,"666  666  666  666  666  666  666  666  666  666");
setcolor(11);//neon green

//outtextxy(500,40,);
} */



