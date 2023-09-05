#include<stdio.h>
int main()
{
	int producer,choice,consumer,in=0,out=0,buff,buffer[10];
	buff=10;
	while(choice!=3){
		printf("\n1.producer \t 2.consumer \t 3.exit");
		printf("\nEnter your choice");
		scanf("%d",&choice);
		switch(choice){
			case 1: if(((in+1)%buff)==out){
				        printf("Buffer is full");
				    }
				    else{
				    	printf("Enter the value");
				    	scanf("%d",&producer);
				    	buffer[in]=producer;
				    	in=((in+1)%buff);
					}
				    break;
			case 2:if(in==out){
				        printf("Buffer is empty");
				    }
				    else{
				    	consumer=buffer[out];
				    	printf("Consumed value is %d ",consumer);
				    	out=(out+1)%buff;
					}
				    break;
	   }
	}
}
