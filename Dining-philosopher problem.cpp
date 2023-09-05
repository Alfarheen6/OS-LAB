#include <stdio.h>
#include <stdlib.h>
void one();
void two();
int  tph,howhung,philname[10],status[10],hu[10];
int main(){
	int i,choice;
	printf("Enter total number of philosophers");
	scanf("%d",&tph);
	for(i=0;i<tph;i++){
		philname[i]=(i+1);
		status[i]=1;
	}
	printf("Enter how many are hungry");
	scanf("%d",&howhung);
	if(tph==howhung){
		printf("All are hungry \n Dead lock");
		printf("exiting");
	}
	else{
		for(i=0;i<howhung;i++){
			printf("Enter philosopher %d position",i+1);
			scanf("%d",&hu[i]);
			status[hu[i]]=2;
		}
	do{
		printf("1.only one can eat \t 2.two can eat \t 3.exit " );
		printf("Enter your choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:one();
			       break;
			case 2:two();
			       break;
			case 3:exit(0);
			       break;
			default:printf("Invalid option");
		}
	}while(1);
}
	return 0;	
}
void one(){
	int pos=0,i,x;
	printf("Allow one philisopher to eat at atime");
	for(i=0;i<howhung;i++,pos++){
		printf("p%d are assigned to eat",philname[hu[pos]]);
		for(x=pos;x<howhung;x++){
			printf("p%d is waiting",philname[hu[x]]);
		}
	}
}
void two(){
	int s=0,i,j,t,r,x;
	printf("Allow to philosophers to eat at a same time");
	for(i=0;i<howhung;i++){
		for(j=i+1;j<howhung;j++){
			if(abs(hu[i]-hu[j])>1 && abs(hu[i]-hu[j])!=4 ){
				printf("\n combination %d",s+1);
				t=hu[i];
				r=hu[j];
				s=s+1;
				printf("p%d and p%d are granted to eat",philname[hu[i],philname[hu[j]]]);
			}
			for(x=0;x<howhung;x++){
				if(hu[x]!=t && hu[x]!=r){
					printf("p%d is waiting",philname[hu[x]]);
				}
			}
		}
	}
}
