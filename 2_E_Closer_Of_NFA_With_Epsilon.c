#include<stdio.h>
#include<string.h>
int main(){    
    int size,numTrans,i;
    printf("Enter the number of states: ");
    scanf("%d",&size);
	char states[100], arr1[100],arr2[100],arr3[100],temp[100];
	for(i=0;i<size;i++){
		printf("Enter name of state %d : ",i);
	    scanf("%1s",&states[i]);    
	}
	printf("Enter the number of Transitions: ");
	scanf("%d",&numTrans);
	printf("Enter the transition\n");		
	for(i=0;i<numTrans;i++){
		scanf("%1s",&arr1[i]);
		scanf("%1s",&arr2[i]);
		scanf("%1s",&arr3[i]);
	}
	for(i=0;i<size;i++){
		printf("E-closer for %c = {%c",states[i],states[i]);
		int j=0,k=0;
	    temp[0]=states[i];
	    temp[1]='\0';
		while(j<5){
			if(arr1[j]==temp[0] && arr2[j]=='e'){
				printf("%c",arr3[j]);
	            temp[0]=arr3[j];			  	
	        }	
			j++;
		}
		printf("}\n");
	}	
}
