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
		printf("�S�����");
	}else{
		printf("��Ʀb%d",ans);
	}
		
}
