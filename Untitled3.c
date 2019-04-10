#include<stdio.h>
#include<conio.h>
struct process_data
{
	int Num;
	int Pid;  //Process Id
	int A_time; //Process Arrival Time
	int B_time; //Process Burst Time
	int Priority; //Process Priority
	int F_time; //Process Finish Time
	int t_time; //Process Remaining  Time During Execution
	int W_time; //Waiting Time
	int S_time; //Process start Time
	int Res_time;
	int status;

};
int main()
 {
   int n,awt,atat,i,tq;
 
  
 
   printf("Enter the number of process : ");
   scanf("%d",&n);
   struct process_data a[n],x;
   printf("Enter time quantum");
   scanf("%d",&tq);
   printf("\n\t Enter burst time : time priorities : Arrival time  \n");
 
   for(i=0;i<n;i++)
    {
      
      printf("\n Process %d ",i+1);
      
      scanf("%d %d %d",&a[i].B_time,&a[i].Priority,&a[i].A_time);
	  a[i].Pid=i+1;
    }
 
//sorting on the basis of priority
int j;
  for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
     {
       if(a[i].Priority>a[j].Priority)
       {
     x=a[i];
     a[i]=a[j];
     a[i]=x;
     
      }
      
   }
}
a[i].W_time=0;
awt=0;
a[0].t_time=a[0].B_time;
atat=a[0].t_time;
for(i=1;i<n;i++)
 {
 	if(tq<n || tq>n) {
	 
   a[i].W_time=a[i-1].t_time;
   awt+=a[i].W_time;
   a[i].t_time=a[i].W_time+a[i].B_time;
   atat+=a[i].t_time;
	 }
 }
 
 //Gantt chrat
 printf("\n");
 printf("Gantt chart\n");
 for(i=0;i<n;i++)
 {
 	printf("P %d ",a[i].Pid);
 }
//Displaying the process
 
printf("\n\nProcess \t Burst Time \t Wait Time \t Turn Around Time   Priority \tArrival time \n");
for(i=0;i<n;i++){
printf("\n  %d",a[i].Pid); printf("\t\t %d",a[i].B_time); printf("\t\t %d",a[i].W_time); printf("\t\t %d",a[i].t_time); 
printf("\t\t %d",a[i].Priority); printf("\t\t %d",a[i].A_time);

}
int num=105/15;
printf("\n cpu utilization rate %d",num);
awt/=n;
atat/=n;
printf("\n Average Wait Time : %d ",awt);
printf("\n Average Turn Around Time : %d",atat);


getch();
}
