#include <stdio.h> 

int main(){
	
	int array[9]={1,2,3,4,5,6,7,8,9};
	int key=4,ans=-1,i,mid,L=0,R=9;
	
	while(L<=R){
		mid=(L+R)/2;
		if(array[mid]==key){
			ans=mid;
			break;
		}
		else if(array[mid]<key){
			L=mid+1;
		}
		else if(array[mid]>key){
			R=mid-1;
		}
	}
	if(ans==-1){
		printf("沒有找到");
	}else{
		printf("資料在%d",ans);
	}
}
