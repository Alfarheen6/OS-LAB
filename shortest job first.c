#include<stdio.h>
int main(){
	int bt[20],p[20],tat[20],wt[20],n,i,k,temp;
	float wtavg,tatavg;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter burst time for process %d ",i);
		scanf("%d",&bt[i]);
		p[i]=i;
	}
	for(i=1;i<=n;i++){
		for(k=i+1;k<=n;k++){
			if(bt[i]>bt[k]){
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;
			}
		}
	}
	wt[1]=wtavg=0;
	tat[1]=tatavg=bt[1];
	for(i=2;i<=n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=wt[i]+bt[i];
		tatavg+=tat[i];
		wtavg+=wt[i];
	}
	printf("\nProcess\t\tbrusttime\twaitingtime\tturnaroundtime");
	for(i=1;i<=n;i++){
	
		printf("\np%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	}
	printf("\nThe avearge waiting time is %f",(wtavg/n));
	printf("\nThe average turnaround time is %f",(tatavg/n));
	
}
