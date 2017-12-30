#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<time.h>
#include<stdlib.h>
#include<fstream.h>

int prx[100] = {18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18};
int pry[100] = {716,716,716,716,716,716,716,716,716,716,639,639,639,639,639,639,639,639,639,639,562,562,562,562,562,562,562,562,562,562,485,485,485,485,485,485,485,485,485,485,408,408,408,408,408,408,408,408,408,408,331,331,331,331,331,331,331,331,331,331,254,254,254,254,254,254,254,254,254,254,177,177,177,177,177,177,177,177,177,177,100,100,100,100,100,100,100,100,100,100,23,23,23,23,23,23,23,23,23,23};
int snakedemote[3][3] = {{49,11},{62,19},{99,80}}, ladderpromote[3][3] = {{2,38},{28,84},{51,67}};//global declarations. Shift to private class
struct var
{
 int nt, ns, nl;
};
struct ldbrd
{
 char nam[3];
 int fs;
};
class Rep
{
    public:
    void Report(var ro[], int p)//replace the inner variables with a single structure object that will 'read' from Report 
    {
     fstream wobj;
     wobj.open("Report.dat", ios::in | ios::binary);
     cout<<"Player reports:-\n";
     for(int i = 0;i < p;i++)
     {
      wobj.read((char*)&ro[i], sizeof(var));
      cout<<"\t\t\tPlayer 1"<<endl;
      cout<<"Total number of turns/moves : "<<ro[i].nt<<endl;
      cout<<"Total number of snakes encountered : "<<ro[i].ns<<endl;
      cout<<"Total number of ladders encountered : "<<ro[i].nl<<endl;  
     }
     wobj.close();
    }
};   
void Leaderboard(ldbrd l[], int size)
    {
     cout<<"\t\tLeaderboard\t\t\n";
     cout<<"Name\t\t\tScore\n";
     fstream lob;
     lob.open("Leaderboard.dat", ios::in|ios::binary);
     for(int i =0; i < size;i++)
     {
      lob.read((char*)&l[i], sizeof(ldbrd));
      cout<<l[i].nam<<"\t\t\t"<<l[i].fs<<endl;  
     }
     lob.close();
     }
     

int dice(var sobj[], int ss)
    {
    srand(time(NULL));
    sobj[ss].nt += 1;
    return(rand()%6 + 1);
    }


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

int checkhundred(int chk[], int pos, int &c)
    {
    	if(chk[pos] >= 100)
    	 {
    	 	chk[pos] = 100;
    	 	c++;
    	 	return 1;
    	 }
    	else
    	    return 0;
    }

void Rules(char rc)
    {
     cout<<"The rules are:-\n";
     ifstream obj("Rules.txt");
     while(obj.get(rc))
     {
     cout<<rc;
     }
     cout<<endl;
     obj.close();
    }

int uaskuget()
    {
    int a,b;
    while(1)//always true condition
    {
    if(ismouseclick(WM_LBUTTONDOWN))//super if
    {
     getmouseclick(WM_LBUTTONDOWN,a,b);
     clearmouseclick(WM_LBUTTONDOWN);
     if((a>=400&&a<=600)&&(b>=250&&b<= 300))//subsuper if
         {
         return 1;
         }
     else 
          return 0;
    }
    }//end of while
    }//end of uaskuget()

void pixelputter(int ap[], int i)
{
 
 //readimagefile("1to100-2.jpg",0,0,getmaxx(),getmaxy());//fills the entire screen with the image
 for(int c = 0; c < i; c++)
 {
  
  if(c == 1)//only if there are two players
  {
   setcolor(BLUE);
   if(ap[i] >= 100)
    circle(prx[100],pry[100],5);
   else
    circle((prx[ap[i]]-5),(pry[ap[i]] + 27), 5);
   break;
  } 
  setcolor(RED);
  if(ap[i] >= 100)
   circle(prx[100],pry[100],5);
  else
  circle(prx[ap[i]], pry[ap[i]], 5);
 }
}

int main()
{
        initwindow(960,720);
        int x=getmaxx(),y=getmaxy();//x = 959, y = 719
        setcolor(GREEN);
        settextstyle(5,0,7);
        outtextxy(50,0,"SNAKES AND LADDERS");
        setcolor(CYAN);
        rectangle(400, 250, 600, 300);
        settextstyle(1,0,5);
        setcolor(WHITE);
        outtextxy(405,255, "PLAY");
        //delay(5000);
if(uaskuget())//super if
{
  cleardevice();
  //delay(2000);
  readimagefile("1to100-2.jpg",0,0,getmaxx(),getmaxy());//fills the entire screen with the image
  //setcolor(BLUE);
  circle(360,360,10);
  //putpixel(5, 4, 7);
  char ch;
  int n, roll; 
        cout<<"Enter y to display the rules.\n";
        cin>>ch;
        if(ch == 'y')
         Rules(ch);
    cout<<"Enter the number of players(max. 2).\n";
    cin>>n;
    if (n>2)//Safety check 1
      n=2;
  int arr[n];
  int fin[n];//1 if finished, 0 if not.
  var va[n];
  double finscr[n];
  char finname[n][3];
  ldbrd li[n];
  int count = 0;
        for(int i = 0;i < n;i++)//setting initial positions
        {
         arr[i] = 1;
         fin[i] = 0;
         va[i].nt = 0;
         va[i].ns = 0;
         va[i].nl = 0;
        }//done setting initial positions
  while((count <= n) && (n > 0))//master loop. Cond.1 is INSUFFICIENT AND LACKING. SAD!
        {
        for(int i = 0;i < n;i++)//submaster loop
        {
        if(arr[i] != -1)//outer if
        {
        fin[i] = checkhundred(arr, i, count);
        if(fin[i] == 1)
            {
            cout<<"Player "<<i+1<<" has finished the game.\n";
            arr[i] = -1;
            continue;
            }      
        cout<<"Enter r to roll.\n";
        cin>>ch;
        
        if(ch == 'r')
        {//start of if
                roll = dice(va, i);//see if you can only send a reference variable instead.
                arr[i] = arr[i] + roll;
                fin[i] = checkhundred(arr, i, count);
                pixelputter(arr, n);
                cout<<"Player "<<i+1<<" rolled a "<<roll<<".\n";
                if(fin[i] == 1)
                    {
                    cout<<"Player "<<i+1<<" has finished the game.\n";
                    arr[i] = -1;
                    roll = 0;
                    continue;
                    }  
                cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl;  
                             if(arr[i] == 49 || arr[i] == 62 || arr[i] == 99)
                             {
                              cout<<"SNAKE!!!";
                              va[i].ns++;
                              arr[i] = demote(arr[i]);
                              pixelputter(arr,n);
                              cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl;
                             }
                             if(arr[i] == 2 || arr[i] == 28 || arr[i] == 51)
                             {
                              cout<<"LADDER!!!";
                              va[i].nl++;
                              arr[i] = promote(arr[i]);
                              pixelputter(arr,n);
                              cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl;
                             }
                while(roll == 6)//checking for six
                        {
                        cout<<"Rolling die a second time. Enter r to roll.\n"; 
                        cin>>ch;
                        if (ch == 'r')
                            {
                            roll = dice(va, i);//bonus roll
                            }
                        arr[i] = arr[i] + roll;
                        fin[i] = checkhundred(arr, i, count);
                        pixelputter(arr,n);
                        cout<<"Player "<<i+1<<" rolled a "<<roll<<".";
                        if(fin[i] == 1)
                            {
                            cout<<"Player "<<i+1<<" has finished the game.\n";
                            arr[i] = -1;
                            continue;
                        cout<<". Player "<<i+1<<" is now at position "<<arr[i]<<endl;
                        }//end of checking for six
        }//end of if
        }//end of outer if
        roll = 0;
        if(count == n)//Safety Check 2
        {
         break;
        }
        }//end of submaster loop
        
         
         
  }//end of master loop
  for(int a = 0;a < n;a++)//calculates final score
                finscr[a] = (1000/va[a].nt) + va[a].nl - va[a].ns;
                
        /*leaderboard stuff
        fstream lobj;
        lobj.open("Leaderboard.dat", ios::in | ios::binary);
        for(int a = 0;a < n;a++)
         lobj.read((char*)&li[a], sizeof(ldbrd));
        lobj.close();
        for(int a = 0;a < n;a++) 
         {
          for(int b = 0; b < n;b++)
          {
               if(finscr[b] > li[a].fs)
               {
                cout<<"Enter your name.\n";
                cin>>finname[b];//check
                li[a].fs = (int)finscr[b];
                strcpy(li[a].nam, finname[b]);//check
               }
          }
         }
        lobj.open("Leaderboard.dat", ios::in | ios::binary);
        for(int i = 0; i < n;i++)
         lobj.write((char*)&li[i], sizeof(ldbrd));
        lobj.close();
        //leaderboard stuff ends here    
        Leaderboard(li, n); */
}//end of super if
system("pause");
}
}//end of main()  
