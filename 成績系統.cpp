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

    printf("請輸入班級人數:\n");
    int len;
    scanf("%d",&len);
    int num[len];
    int score1[len],score2[len],score3[len];
    int sum[len];
    int input,i,j;
	int n,sub;
	//平均 
	float avg_num[len],avg_CH,avg_MT,avg_EN;

    //排序
    int min;//最小位置
    int max; 
   
    //搜尋
    int key;
    int ans,mid;
   
    printf("請輸入每位同學國英數成績\n");
    for(i=0;i<len;i++){
        num[i]=i+1;
        printf("%d號同學國文",i+1);
        scanf("%d",&score1[i]);
        printf("%d號同學英文",i+1);
        scanf("%d",&score2[i]);
        printf("%d號同學數學",i+1);
        scanf("%d",&score3[i]);
        sum[i]=score1[i]+score2[i]+score3[i];
        avg_num[i]=((float)score1[i]+(float)score2[i]+(float)score3[i])/3;
    }
    
    while(1){
        printf("1:按照座號排\n");
        printf("2:按照總分排\n");
        printf("3:查詢成績\n");
        printf("4:平均值\n");
        printf("5:調分\n");
        printf("請輸入選擇\n");
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
            printf("座號\t國文\t數學\t英文\t總分\n");        
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
            printf("座號\t國文\t數學\t英文\t總分\t排名\n");
            for(i=0;i<len;i++){
                printf("%d\t%d\t%d\t%d\t%d\t%d\n",num[i],score1[i],score2[i],score3[i],sum[i],i+1);
            }
        }
		else if(input==3){
            ans=-1;//每次都重設，下次沒查到才不會用上次的答案
            printf("請輸入查詢座號號碼\n");
            scanf("%d",&key);
			for(i=0;i<len;i++){
				if(num[i]==key){
					ans=i;
				}
			}
            if(ans==-1){
                printf("沒有找到");
            }else{
                printf("座號\t國文\t數學\t英文\t總分\n");        
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
			printf("座號\t國文\t數學\t英文\t平均\n");
            for(i=0;i<len;i++){
                printf("%d\t%d\t%d\t%d\t%.2f\n",num[i],score1[i],score2[i],score3[i],avg_num[i],i+1);
            }
            printf("平均\t%.2f\t%.2f\t%.2f\n",avg_CH,avg_EN,avg_MT);
		}
		else if(input==5){
    		printf("Who?\n");
    		scanf("%d",&n);
    		printf("Which?\t1.國文 2.英文 3.數學\n");
    		scanf("%d",&sub);
    		if(sub==1){
    			printf("%d號同學目前國文是%d分\t要改成幾分?\n",n,score1[n-1]);
    			scanf("%d",&score1[n-1]);
			}
			else if(sub==2){
				printf("%d號同學目前英文是%d分\t要改成幾分?\n",n,score2[n-1]);
    			scanf("%d",&score2[n-1]);
			}
			else if(sub==3){
				printf("%d號同學目前數學是%d分\t要改成幾分?\n",n,score3[n-1]);
    			scanf("%d",&score3[n-1]);
			}		
		}
    }
}
