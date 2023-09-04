#include<stdio.h>
#include<conio.h>
int main()
{
	int bt[20],wt[20],tat[20],i,n;
	float wtavg,tatavg;
	printf("Enter the no.of processes:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter burst time for process -- %d ",i);
		scanf("%d",&bt[i]);
	}
	wt[1]=wtavg=0;
	tat[1]=tatavg=bt[1];
	for(i=2;i<=n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=bt[i]+wt[i];
		wtavg+=wt[i];
		tatavg+=tat[i];
	}
	printf("\nProcess\t\tbrusttime\twaitingtime\tturnaroundtime");
	for(i=1;i<=n;i++){
	
		printf("\np%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]);
	}
	printf("\nThe avearge waiting time is %f",(wtavg/n));
	printf("\nThe average turnaround time is %f",(tatavg/n));
}
