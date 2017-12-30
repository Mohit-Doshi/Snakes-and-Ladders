//snakes and ladders
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<time.h>
#include<stdlib.h>
/*extern void ladder1();
extern void ladder2();
extern void snek1();
extern void snek2();
extern void snek3();
extern void numbering();
int main()
{
int i=0,j=0,k=5;
int gd = DETECT,gm;
/*void ladder1();
void ladder2();
void snek1();
void snek2();
void snek3();
void numbering(); 
cout<<"Spaec Teddy";
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
getch(); */

int dice()
{
srand(time(NULL));
return(rand()%6 + 1);
}
int snakedemote[3][3] = {{49,11},{62,19},{99,80}}, ladderpromote[3][3] = {{2,38},{28,84},{51,67}};//global declarations. Shift to private class
int demote(int check)
{
 for(int i = 0;i < 3;i++)
 {
  if(check == snakedemote[i][0])
   return snakedemote[i][1];
 }
}

int promote(int check)
{
 for(int i =0;i < 3;i++)
 {
  if(check == ladderpromote[i][0])
   return ladderpromote[i][1];
 }
}

int main()
{
initwindow(960,720);
readimagefile("1to100-2.jpg",0,0,getmaxx(),getmaxy());//fills the entire screen with the image
putpixel(5, 4, 7);
char ch;
int n; 
cout<<"Enter the number of players(max. 5).\n";
cin>>n;
int arr[n];
int count = 0;
for(int i = 0;i < n;i++)//setting initial positions
 arr[i] = 1;
 
while((count <= n) && (n > 0))//master loop
{
for(int i = 0;i < n;i++)//submaster loop
{
if(arr[i] >= 100)
{
cout<<"Player "<<i+1<<" has finished the game.\n";
count++;
continue;
}      
cout<<"Enter r to roll.\n";
cin>>ch;

if(ch == 'r')
{//start of if
int roll = dice();
arr[i] = arr[i] + roll;
cout<<"Player "<<i+1<<" rolled a "<<roll<<". Player "<<i+1<<" is now at position "<<arr[i]<<endl;
 if(arr[i] == 49 || arr[i] == 62 || arr[i] == 99)
 {
  cout<<"SNAKE!!!";
  arr[i] = demote(arr[i]);
  cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl;
 }
 if(arr[i] == 2 || arr[i] == 28 || arr[i] == 51)
 {
  cout<<"LADDER!!!";
  arr[i] = promote(arr[i]);
  cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl;
 }

while(roll == 6)//checking for six
{
cout<<"Rolling die a second time.\n"; 
cin>>ch;
if (ch == 'r')
{
roll = dice();//bonus roll
}
arr[i] = arr[i] + roll;
cout<<"Player "<<i+1<<" rolled a "<<roll<<". Player "<<i+1<<"is now at position "<<arr[i]<<endl;
}//end of while
}//end of if
}//end of submaster loop
}//end of master loop
system("pause");
}
 









