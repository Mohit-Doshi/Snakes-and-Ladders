#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

struct var
{
 int nt, ns, nl;
};
int prx[100] = {18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18,18,114,210,306,402,498,594,690,786,882,882,786,690,594,498,402,306,210,114,18};
int pry[100] = {716,716,716,716,716,716,716,716,716,716,639,639,639,639,639,639,639,639,639,639,562,562,562,562,562,562,562,562,562,562,485,485,485,485,485,485,485,485,485,485,408,408,408,408,408,408,408,408,408,408,331,331,331,331,331,331,331,331,331,331,254,254,254,254,254,254,254,254,254,254,177,177,177,177,177,177,177,177,177,177,100,100,100,100,100,100,100,100,100,100,23,23,23,23,23,23,23,23,23,23};
int snakedemote[3][3] = {{49,11},{62,19},{99,80}}, ladderpromote[3][3] = {{2,38},{28,84},{51,67}};//global declarations. 
class fnmidf
{
public:
	void Rules()
    {
    fstream robj;
	robj.open("GameRules.dat", ios::in|ios::binary);
	char arr[5][100];
	for(int i = 0; i < 5;i++)
	{
	 robj.read((char*)&arr[i], sizeof(arr[i]));
	}
	for(int i = 0; i < 5;i++)
	 cout<<arr[i]<<endl;
	 
	robj.close();
    }
    int Report(int p)
    {
     double fsp[p];
     var ro[p];
     fstream objrep;
     objrep.open("PlayerRep.dat", ios::in|ios::binary);
     cout<<"Player reports:-\n\n";
     for(int i = 0;i < p;i++)
     {
      objrep.read((char*)&ro[i], sizeof(ro[i]));
      cout<<"Player "<<(i+1)<<endl;
      cout<<"Total number of turns/moves : "<<ro[i].nt<<endl;
      cout<<"Total number of snakes encountered : "<<ro[i].ns<<endl;
      cout<<"Total number of ladders encountered : "<<ro[i].nl<<endl;
      fsp[i] = (1000/ro[i].nt) + ro[i].nl - ro[i].ns;
	  cout<<"Final score of Player "<<(i+1)<<" : "<<(int)fsp[i]<<endl<<endl;  
     }
     objrep.close();
     if(p == 1)
      return 1;
     else
      {
      	if(fsp[0] == fsp[1])
      	 return 0;
      	else
      	if(fsp[0]>fsp[1])
      	 return 1;
      	else 
      	 return 2;
	  }
    }
}dob;
     
class fcf
{
public:
	int dice(var sobj[], int ss)
	    {
	    srand(time(NULL));
	    sobj[ss].nt += 1;
	    return(rand()%6 + 1);//returns a value between 1 and 6.
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
	
	int checkhundred(int chk[], int pos)
	    {
	    	if(chk[pos] >= 100)
	    	 {
	    	 	chk[pos] = 100;
	    	 	return 1;
	    	 }
	    	else
	    	    return 0;
	    }
	    
	void pixelputter(int ap[], int i)
		{
		 readimagefile("1to100-2.jpg",0,0,getmaxx(),getmaxy());//fills the entire screen with the image
		 for(int c = 0; c <= (i-1); c++)
		 {
		  
		 if(c == 1)//only if there are two players
		  {
		   setcolor(BLUE);
		   if(ap[c] >= 100)
		    circle(prx[100-1]-10,pry[100-1],5);
		   else
		    circle((prx[ap[c]-1]-10),(pry[ap[c]-1]), 5);
		   break;
		  } 
		  setcolor(RED);
		  if(ap[c] >= 100)
		   circle(prx[100-1],pry[100-1],5);
		  else
		  circle(prx[ap[c]-1], pry[ap[c]-1], 5);
		 }
		}
}cmm;


int confclick()
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
    }//end of confclick()



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
if(confclick())//super if
{
  cleardevice();
  readimagefile("1to100-2.jpg",0,0,getmaxx(),getmaxy());//fills the entire screen with the image
  circle(360,360,10);
  char ch;
  int n, roll, count = 0, flag = 0, wr= 0;
 
        cout<<"Enter y to display the rules and n to not display them.\n";
        cin>>ch;
        if(ch == 'y' || ch == 'Y')
         dob.Rules();//calling Rules()
    cout<<"Enter the number of players(max. 2).\n";
    cin>>n;
    if (n>2)//Size check 
      n=2;
  int arr[n];
  int fin[n];//1 if finished, 0 if not.
  var va[n];//structure array object for counting number of turns, snakes and ladders encountered
        
		for(int i = 0;i < n;i++)//setting initial positions
        {
         arr[i] = 1;
         fin[i] = 0;
         va[i].nt = 0;
         va[i].ns = 0;
         va[i].nl = 0;
        }//done setting initial positions
        
  while((n > 0) && (flag < n))//master loop. 
        {
        for(int i = 0;i < n;i++)//submaster loop
        {
         if(arr[i] >= 100)
         {
          arr[i] = 100;
          cout<<"Player "<<i+1<<" has finished the game.\n\n";
          continue;
         }
         
         if(arr[i] < 100 && arr[i] > 0)//outer if
         {
	        cout<<"Enter r to roll. Entering anything else will forfeit your turn.\n";
	        cout<<"Player "<<(i+1)<<" : ";
	        cin>>ch;
	        
        if(ch == 'r')//start of inner if
        {
                roll = cmm.dice(va, i);
                arr[i] = arr[i] + roll;
                va[i].nt++;
                fin[i] = cmm.checkhundred(arr, i);
                cmm.pixelputter(arr, n);
                cout<<"Player "<<i+1<<" rolled a "<<roll<<".\n";
                if(fin[i] == 1)
                    {
                    cout<<"Player "<<i+1<<" has finished the game.\n\n";
                    arr[i] = 100;
                    continue;
                    }  
                cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl<<endl;  
                             if(arr[i] == 49 || arr[i] == 62 || arr[i] == 99)//snake condition
                             {
                              cout<<"SNAKE!!!";
                              va[i].ns++;
                              arr[i] = cmm.demote(arr[i]);
                              cmm.pixelputter(arr,n);
                              cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl<<endl;
                             }
                             if(arr[i] == 2 || arr[i] == 28 || arr[i] == 51)//ladder condition
                             {
                              cout<<"LADDER!!!";
                              va[i].nl++;
                              arr[i] = cmm.promote(arr[i]);
                              cmm.pixelputter(arr,n);
                              cout<<"Player "<<i+1<<" is now at position "<<arr[i]<<endl<<endl;
                             }
                while(roll == 6)//checking for six
                        {
                        cout<<"Rolling die a second time. Enter r to roll.\n";
						cout<<"Player "<<(i+1)<<" : ";
						cin>>ch;
                        if (ch == 'r')
                            {
                            roll = cmm.dice(va, i);//bonus roll
                            }
                        arr[i] = arr[i] + roll;
                        fin[i] = cmm.checkhundred(arr, i);
                        cmm.pixelputter(arr,n);
                        cout<<"Player "<<i+1<<" rolled a "<<roll<<".";
                        if(fin[i] == 1)
                            {
                            cout<<"Player "<<i+1<<" has finished the game.\n\n";
                            arr[i] = 100;
                            continue;
                            }
                        cout<<" Player "<<i+1<<" is now at position "<<arr[i]<<endl<<endl;
                        }//end of checking for six
                        ch = ' ';
                        
        }//end of inner if
        }//end of outer if
        roll = 0;
        }//end of submaster loop
        flag = 0;
        for(int i = 0;i < n;i++)
                        {
                        if(arr[i] >= 100)
                         flag += 1;
                        if(flag == n)
                         break;
                         }
         
         
  }//end of master loop
  
  fstream repoj;
  repoj.open("PlayerRep.dat", ios::out|ios::binary);
  for(int i = 0; i < n;i++)
   repoj.write((char*)&va[i], sizeof(va[i]));
  repoj.close();
  wr = dob.Report(n);
  if(wr != 0)
   cout<<"\nThe Winner is Player "<<wr<<".\n";
  else
   cout<<"\nThe game is tied.\n";
                

		  
}//end of super if
system("pause");

}//end of main()    
