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
	//sort according to the arrival time and then apply rr using priroirty
}
