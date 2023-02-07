#include <stdio.h>

int main(){
	int array[5]={9,7,1,3,5},i,j,min,temp;
	int arr_len=sizeof(array)/sizeof(int);
	
	for(i=0;i<arr_len-1;i++){
		min=i;
		for(j=i;j<arr_len;j++){
			if(array[j]<array[min]){
				min=j;
			}
		}
		temp=array[i];
		array[i]=array[min];
		array[min]=temp;
	}
	for(i=0;i<arr_len;i++){
			printf("%d ",array[i]);
		}
}
