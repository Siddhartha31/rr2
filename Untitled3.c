#include<stdio.h> 
 struct process_data
{
	int Num;
	int Pid;  //Process Id
	int A_time; //Process Arrival Time
	int B_time; //Process Burst Time
	int Priority; //Process Priority
	int F_time; //Process Finish Time
	int R_time; //Process Remaining  Time During Execution
	int W_time; //Waiting Time
	int S_time; //Process start Time
	int Res_time;
	int status;

};
int main() 
{ 
 
  int cnt,j,n,time,remain_process,flag=0,tq; 
  int w_time=0,t_time=0,arrivaltime[10],bursttime[10],remaintime[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  struct process_data a[n];
  remain_process=n; 
  for(cnt=0;cnt<n;cnt++) 
  { a[cnt].Pid=cnt+1;
    printf("Enter Arrival Time ,Burst Time  ,prirority  for Process Process Number %d :",cnt+1); 
    scanf("%d",&a[cnt].A_time); 
    scanf("%d",&a[cnt].B_time); 
    scanf("%d",&a[cnt].Priority);
    a[cnt].R_time=a[cnt].B_time; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&tq); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time|\t Arrival Time\n\n"); 
  for(time=0,cnt=0;remain_process!=0;) 
  { 
    if( a[cnt].R_time<=tq &&  a[cnt].R_time>0) 
    { 
      time+= a[cnt].R_time; 
      a[cnt].R_time=0; 
      flag=1; 
    } 
    else if( a[cnt].R_time>0) 
    { 
       a[cnt].R_time-=tq; 
      time+=tq; 
    } 
    if( a[cnt].R_time==0 && flag==1) 
    { 
      remain_process--; 
      printf("P[%d]\t|\t%d\t|\t%d\t %d\n",cnt+1,time-a[cnt].A_time,time-a[cnt].A_time-a[cnt].B_time,a[cnt].A_time); 
      w_time+=time-a[cnt].A_time-a[cnt].B_time; 
      t_time+=time-a[cnt].A_time; 
      flag=0; 
    } 
    if(cnt==n-1) 
      cnt=0; 
    else if(a[cnt+1].A_time<=time) 
      cnt++; 
    else 
      cnt=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",w_time*1.0/n); 
  printf("Avg Turnaround Time = %f",t_time*1.0/n); 
  
  return 0; 
}
