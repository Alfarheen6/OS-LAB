#include<stdio.h>
int main(){
	int bt[20],p[20],tat[20],wt[20],n,i,k,t,max,j,ct[20];
	float wtavg=0,tatavg=0,temp=0;
	printf("Enter no.of processes:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter burst time for process %d ",i);
		scanf("%d",&bt[i]);
		ct[i]=bt[i];
   }
   printf("Enter time slice :");
   scanf("%d",&t);
   max=bt[1];
   for(i=2;i<=n;i++){
   	   if(max<bt[i]){
   	   	   
		   max=bt[i];
	    }
   }
   for(j=1;j<=(max/t)+1;j++){
   	  for(i=1;i<=n;i++){
   	  	    if(bt[i]!=0) {
   	  	    	if(bt[i]<=t){
   	  	            tat[i]=	temp+bt[i];
					temp=temp+bt[i];
					bt[i]=0;	
			   }
			   else{
			   	   bt[i]=bt[i]-t;
			   	   temp=temp+t;
			   }
		   }
		}
   }
   for(i=1;i<=n;i++){
   	  wt[i]=tat[i]-ct[i];
   	  wtavg+=wt[i];
   	  tatavg+=tat[i];
   }
   printf("\nProcess\t\tbrusttime\twaitingtime\tturnaroundtime");
	for(i=1;i<=n;i++){
	
		printf("\np%d\t\t%d\t\t%d\t\t%d",i,ct[i],wt[i],tat[i]);
	}
	printf("\nThe avearge waiting time is %f",(wtavg/n));
	printf("\nThe average turnaround time is %f",(tatavg/n));
}
   
