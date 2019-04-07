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

};
int main()
{
	struct process_data a[6];
	int i;
	for(i=0;i<6;i++)
	{
		printf("enter the process id,arrival time ,priority,burst time ");
		scanf("%d %d %d",&a[i].Pid,&a[i].Priority,&a[i].A_time,&a[i].B_time);
	}
	struct process_data temp;
int j;
for (i=0;i<9;i++)
{
	for(j=0;j<9-i;j++)
	{
		if(a[j].A_time<a[j+1].A_time)
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
	
}
	//sorted according to the arrival time and then apply rr using priroirty
}
