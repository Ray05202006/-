#include <stdio.h>

int main(){

	int a[5]={2,7,4,8,1},i,j,temp;
	int len_a = sizeof(a)/sizeof(int);
	for(i=len_a;i>0;i--){
		for(j=0;j+1<i;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	for(i=0;i<len_a;i++){
			printf("%d ",a[i]);
		}
} 
