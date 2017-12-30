#include<iostream>
#include<stdio.h>
using namespace std;
int dice()
{
return 5;
}
int main()
{
int n;
cout<<"Enter the number of players(max. 5).\n";
cin>>n;
int arr[n];
int count = 0;
for(int i = 0;i < n;i++)//setting initial positions
{
arr[i] = 1;
} 
while(count <= n)//master loop
{
for(int i = 0;i < n;i++)//submaster loop
{
if(arr[i] >= 100)
{
cout<<"Player "<<i+1<<" has finished the game.\n";
count++;
continue;
}      
int roll = dice();
arr[i] = arr[i] + roll;
cout<<"Player "<<i+1<<" rolled a "<<roll<<". Player "<<i+1<<" is now at position "<<arr[i]<<endl;
while(roll == 6)//checking for six
{
cout<<"Rolling die a second time.\n"; 
roll = dice();//bonus roll
arr[i] = arr[i] + roll;
cout<<"Player "<<i+1<<" rolled a "<<roll<<". Player "<<i+1<<"is now at position "<<arr[i]<<endl;
}//end of while
}
}
system("pause");
}
