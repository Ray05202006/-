#include <stdio.h>

/*
	3
	80 50 40
	60 50 70
	20 90 40
	
	
*/

void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main(){

    printf("�п�J�Z�ŤH��:\n");
    int len;
    scanf("%d",&len);
    int num[len];
    int score1[len],score2[len],score3[len];
    int sum[len];
    int input,i,j;
	int n,sub;
	//���� 
	float avg_num[len],avg_CH,avg_MT,avg_EN;

    //�Ƨ�
    int min;//�̤p��m
    int max; 
   
    //�j�M
    int key;
    int ans,mid;
   
    printf("�п�J�C��P�ǰ�^�Ʀ��Z\n");
    for(i=0;i<len;i++){
        num[i]=i+1;
        printf("%d���P�ǰ��",i+1);
        scanf("%d",&score1[i]);
        printf("%d���P�ǭ^��",i+1);
        scanf("%d",&score2[i]);
        printf("%d���P�Ǽƾ�",i+1);
        scanf("%d",&score3[i]);
        sum[i]=score1[i]+score2[i]+score3[i];
        avg_num[i]=((float)score1[i]+(float)score2[i]+(float)score3[i])/3;
    }
    
    while(1){
        printf("1:���Ӯy����\n");
        printf("2:�����`����\n");
        printf("3:�d�ߦ��Z\n");
        printf("4:������\n");
        printf("5:�դ�\n");
        printf("�п�J���\n");
        scanf("%d",&input);    
        if(input==1){
            for(i=0;i<len-1;i++){
                min=i;
                for(j=i;j<len;j++){
                    if(num[j]<num[min]){
                        min=j;
                    }
                }
                swap(&sum[i],&sum[min]);
                swap(&num[i],&num[min]);
				swap(&score1[i],&score1[min]);
				swap(&score2[i],&score2[min]);
				swap(&score3[i],&score3[min]);
            }
            printf("�y��\t���\t�ƾ�\t�^��\t�`��\n");        
            for(i=0;i<len;i++){
                    printf("%d\t%d\t%d\t%d\t%d\n",num[i],score1[i],score2[i],score3[i],sum[i]);
            }
        }
		else if(input==2){
            for(i=0;i<len-1;i++){
                max=i;
                for(j=i;j<len;j++){
                    if(sum[j]>sum[max]){
                        max=j;
                    }
                }
                swap(&sum[i],&sum[max]);
				swap(&num[i],&num[max]);
				swap(&score1[i],&score1[max]);
				swap(&score2[i],&score2[max]);
				swap(&score3[i],&score3[max]);
            }
            printf("�y��\t���\t�ƾ�\t�^��\t�`��\t�ƦW\n");
            for(i=0;i<len;i++){
                printf("%d\t%d\t%d\t%d\t%d\t%d\n",num[i],score1[i],score2[i],score3[i],sum[i],i+1);
            }
        }
		else if(input==3){
            ans=-1;//�C�������]�A�U���S�d��~���|�ΤW��������
            printf("�п�J�d�߮y�����X\n");
            scanf("%d",&key);
			for(i=0;i<len;i++){
				if(num[i]==key){
					ans=i;
				}
			}
            if(ans==-1){
                printf("�S�����");
            }else{
                printf("�y��\t���\t�ƾ�\t�^��\t�`��\n");        
                printf("%d\t%d\t%d\t%d\t%d\n",num[ans],score1[ans],score2[ans],score3[ans],sum[ans]);
            }
        }
        else if(input==4){
        	avg_CH=0,avg_MT=0,avg_EN=0;
			for(i=0;i<len;i++){
				avg_CH+=score1[i];
				avg_EN+=score2[i];
				avg_MT+=score3[i];
			}
			avg_CH/=len;
			avg_EN/=len;
			avg_MT/=len;
			printf("�y��\t���\t�ƾ�\t�^��\t����\n");
            for(i=0;i<len;i++){
                printf("%d\t%d\t%d\t%d\t%.2f\n",num[i],score1[i],score2[i],score3[i],avg_num[i],i+1);
            }
            printf("����\t%.2f\t%.2f\t%.2f\n",avg_CH,avg_EN,avg_MT);
		}
		else if(input==5){
    		printf("Who?\n");
    		scanf("%d",&n);
    		printf("Which?\t1.��� 2.�^�� 3.�ƾ�\n");
    		scanf("%d",&sub);
    		if(sub==1){
    			printf("%d���P�ǥثe���O%d��\t�n�令�X��?\n",n,score1[n-1]);
    			scanf("%d",&score1[n-1]);
			}
			else if(sub==2){
				printf("%d���P�ǥثe�^��O%d��\t�n�令�X��?\n",n,score2[n-1]);
    			scanf("%d",&score2[n-1]);
			}
			else if(sub==3){
				printf("%d���P�ǥثe�ƾǬO%d��\t�n�令�X��?\n",n,score3[n-1]);
    			scanf("%d",&score3[n-1]);
			}		
		}
    }
}
