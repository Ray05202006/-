#include <stdio.h> 

int main(){
	
	int array[9]={3,8,2,9,1,6,5,4,7};
	int key=1;
	int ans=-1;
	int i;
	
	for(i=0;i<9;i++){
		if(array[i]==key){
			ans=i;
		}
	}
	if(ans==-1){
		printf("沒有找到");
	}else{
		printf("資料在%d",ans);
	}
		
}
