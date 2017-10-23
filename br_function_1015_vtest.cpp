#include <stdio.h>
#include<stdlib.h>
#include <string.h>
int main(void)
{

	char HEXBr2[8]={'0'};/*??���T�w*//*store input value without 0x*/
	char header[3]="0x";/*0x��header*/
	char oxtanswer[11]="hello";
	int  BINARRAY[32]={0};
	int  BINARRAY_REVERSE[32]={0};
	int  BINARRAY2hex_answer[8]={0};
	int  qarr[8]={0};
    int HEXBr3[8]={0};/* transfer  input value char 2 int */
	unsigned long int HEXBr4[8]={0};
	int j=0;/*for count*/
	int i=0;/*for count*/
	int k=0;/*for count*/
	unsigned long int num1=0;/*atoi function*/
    int m=0;/*for binary array reverse*/
    int n=0;/*FOR 16�i����2�i��ǦC*/
    int r=1;/*FOR 16�i����2�i��ǦC*/
    char tr='0';/*for int 2 char*/
    int a=0;/*for check final hex �ǦC*/
    int res=0;/*for final reverse*/
    int BRans=0;
    int binsum=0;
    int binans=0;
    int hex2bin=0;/*FOR 16�i����2�i��ǦC*/
    int bin2hex=0;/*FOR 2�i����16�i��ǦC*/
    int p=0;/*FOR 16�i����2�i��ǦC*/
    int num=0;/*for count*/
	char *ptr;/*������J�j�p�ɨϥΪ��ʺA�}�C*/
	char *arr;/*�T�{��J�j�p�᪺�ʺA�}�C*/ 
	int *BINARRAY2hex_ans;/**final HEX ARRAY�ʺA�}�C*/
	int *hexarr;
	char *HEXBr;
	char *Br_final;
	int size=20;/*�w�]�j�p*/
	ptr = (char *)calloc(size,sizeof(char));/*calloc��l�ư}�C��ȧ���0*/
	printf("type HEX number\n");/*��J�n��br��ƪ��Ʀr*/
	for(i=0;i<size;i++)
	{

		scanf("%c",&ptr[i]);/*prtAry[i] �����A���M�O�@�Ӧr������ char*�A ���O�b C �y�������\�{���]�p�̥Φr���}�C char[] ���y�k�Ӧs��*/
		num++;
		if(ptr[i]=='\n')
		{
			size=num;
			if(ptr[0]!='0')
			{
				printf("input == 1 or 2 or 3\n");
				size=8;
				ptr[0]=ptr[0];
				for(k=1;k<7;k++)
				{
				
				  ptr[k]='0';
				}
				printf("%d\n",size);
				break;
			}				
		}
		
	}
	printf("arr size=%d\n",size);
	arr = (char *)calloc(size,sizeof(char));
	/*�T�{��J�Ȫ����T�j�p*/
	for(j=0;j<size;j++)
	{
		arr[j]=ptr[j];
		printf("arr[%d]=%c\n",j,arr[j]);
	}
	printf("check\n");
	printf("ptr = %s\n",ptr);
	printf("arr = %s\n",arr);/*input value*/
	/*remove 0x & add 0 in order to complite 8 bits*/
	j=(size-2);
	hexarr = (int *)calloc(8,sizeof(int));/*hexarr�}�C�x�s��J��(int��)*/
	printf("j=%d\n",j);
	for(i=0;i<8;i++)
	{	
		if(ptr[1]=='x')
		{
		
			HEXBr2[i]=arr[j];/*�q�̫�@�Ӷ}�l���ȩҥH�Oj--*/
			if(j<=1)
			{
				printf("qq=0");
				HEXBr2[i]='0';
			}
			j--;
		}
		if(ptr[1]!='x')
		{
			HEXBr2[i]=arr[i];
		
		}
			
		printf("HEXBr2[%d]=%c\n",i,HEXBr2[i]);
		BRans=HEXBr2[i]-'0';
		printf("%d\n",	BRans);
		if(HEXBr2[i]=='a' or HEXBr2[i]=='A')
		{
			BRans=10;
		}
		if(HEXBr2[i]=='b' or HEXBr2[i]=='B')
		{
		if(HEXBr2[i]=='c' or HEXBr2[i]=='C')
		{
			BRans=12;
		}
		if(HEXBr2[i]=='d' or HEXBr2[i]=='D')
		{
			BRans=13;
		}
		if(HEXBr2[i]=='e' or HEXBr2[i]=='E')
		{
			BRans=14;
		}
		if(HEXBr2[i]=='f' or HEXBr2[i]=='F')
		{
			BRans=15;
		}
		hexarr[i]=BRans;
	
		printf("hexarr[%d]=%d\n",i,hexarr[i]);
		
	}
	free(ptr);
	free(arr);
	/*midify*/ 
	printf("check input value(int mode)\n");
	for(i=0;i<8;i++)
	{
		printf("hexarr[%d]=%d\n",i,hexarr[i]);
		qarr[i]=hexarr[i];/*qarr�ǦC��hexarr�@��*/
	}
	free(hexarr);

	/*16�i����2�i��ǦC*/
	printf("check HEX	2	DEC\n");
//	printf("check HEXBr3[%d]=%d\n",0,HEXBr3[0]);
	for(i=0;i<8;i++)
	{
		printf("HEXBr3[%d]=%d\n",i,qarr[i]);
		printf("trans HEX 2 BIN\n");
		hex2bin=qarr[i];
		for(k=p;k<(p+4);k++)
		{
			BINARRAY[k]=hex2bin%2;
			hex2bin=hex2bin/2;
			printf("BINARRAY[%d]=%d\n",k,BINARRAY[k]);
			
		}
		p=p+4;
	}
	/*����*/
	printf("binary reverse\n");
	for(j=31;j>=0;j--)
 	{
 		
	 	BINARRAY_REVERSE[m]=(BINARRAY[j]);
		printf("BINARRAY_REVERSE [%d]=%d\n",m,BINARRAY_REVERSE[m]);
		m++;	
	}
	/*16�i����2�i�� �৹�N�����פF*/
	printf("trans BINARRAY_REVERSE 2 HEX\n");
	for(i=0;i<8;i++)
	{
		binans=0;
		r=1;
		for(j=n;j<(n+4);j++)
		{	
			binsum=0;
			printf("n=%d\n",n);
			printf("BINARRAY_REVERSE[%d]=%d\n",j,BINARRAY_REVERSE[j]);
			printf("r=%d\n",r);
			binsum=(BINARRAY_REVERSE[j]*r);
			printf("binsum=%d\n",binsum);
			r=r*2;
			binans=binans+binsum;
			
		}
		n=n+4;
		BINARRAY2hex_answer[i]=binans;
		printf("BINARRAY2hex_answer [%d]=%d\n",i,BINARRAY2hex_answer[i]);
		/*�h������=0�����D*/
	}	
	/*�ץ��h�l��0*/ /*��0*/
	printf("final check\n");
	size=8;
	num=0;
	BINARRAY2hex_ans = (int *)calloc(size,sizeof(int));
	HEXBr = (char *)calloc(size,sizeof(char));
	for(i=0;i<8;i++)
	{
		printf("BINARRAY2hex_answer[%d]=%d\n",i,BINARRAY2hex_answer[i]);
	}
	for(j=0;j<size;j++)
	{
		BINARRAY2hex_ans[j]=BINARRAY2hex_answer[j];
		printf("BINARRAY2hex_ans[%d]=%d\n",j,BINARRAY2hex_ans[j]);
		num++;
		printf("BINARRAY2hex_answer[%d]qq=%d\n",j,BINARRAY2hex_answer[j]);
		if(BINARRAY2hex_answer[j]!=0 && BINARRAY2hex_answer[j+1]==0)
		{
			size=num;
		//	if(BINARRAY2hex_answer[7]!=0 &&BINARRAY2hex_answer[0]==0)
		//	{	
		//		printf("qq\n");
		//		size=8;
				
		//	}
		}
	
		//printf("BINARRAY2hex_ans[%d]=%d\n",j,BINARRAY2hex_ans[j]);
		tr=BINARRAY2hex_ans[j]+'0';
		if(BINARRAY2hex_ans[j]==10)
		{
			tr='a';
		}
		if(BINARRAY2hex_ans[j]==11)
		{
			tr='b';
		}
		if(BINARRAY2hex_ans[j]==12)
		{
			tr='c';
		}
		if(BINARRAY2hex_ans[j]==13)
		{
			tr='d';
		}
		if(BINARRAY2hex_ans[j]==14)
		{
			tr='e';
		}
		if(BINARRAY2hex_ans[j]==15)
		{
			tr='f';
		}
		HEXBr[j]=tr;
		printf("HEXBr[%d]=%c\n",j,HEXBr[j]);	
	}
	free(BINARRAY2hex_ans);
	Br_final = (char *)calloc(size,sizeof(char));
	res=(size-1);
	for(k=0;k<size;k++)
 	{
 		
	 	Br_final[res]=(HEXBr[k]);
		printf("Br_final[%d]=%c\n",res,Br_final[res]);	
		res--;
	}
	free(HEXBr);
//	printf("HEXBr[%d]=%c\n",6,HEXBr[6]);
	/*�[�Wheader*/
	if(Br_final[0]=='1' or Br_final[0]=='2' or Br_final[0]=='3'or Br_final[0]=='4')
	{
		printf("final = %s\n",Br_final);
	}
	else
	{
		
		sprintf(oxtanswer, "%s%s", header, Br_final);
		printf("final = %s",oxtanswer);
	}
	system("pause");
	return 0;
}
