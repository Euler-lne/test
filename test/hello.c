#include <stdio.h>
typedef struct character
{
	char ch;
	int n;
}CH;
//统计出这四类字符在文件中的数量
void tongji(FILE* p) {
	char ch;
	int a=0,b=0,c=0,d=0;
	ch = fgetc(p);
	while(ch!=EOF) {
		if(ch>='A'&&ch<='Z')
			++a;
		else if(ch>='a'&&ch<='z')
			++b;
		else if(ch>='0'&&ch<='9')
			++c;
		else
			++d;
		ch = fgetc(p);
	}
	printf("Task1:\n");
	printf("capital: %d\n",a);
	printf("lowercase: %d\n",b);
	printf("digit: %d\n",c);
	printf("others: %d\n",d);

	rewind(p);
}//任务一正确 
//统计文件行数
void hangshu(FILE* p) {
	char ch;
	int min=0,max=0,n=0,m=0;
	ch = fgetc(p);
	while(ch!=EOF) {
		if(ch!=10)
			++n;
		else {
			++m;
			if(min==0&&max==0) {//如果是第一行
				min=n;
				max=n;
			} else {
				if(n<min)
					min = n;
				else if(n>max)
					max = n;
			}
			n=0;
		}
		ch = fgetc(p);
	}
	printf("Task2:\n");
	printf("line: %d\n",m);
	printf("%d characters in max line.\n",max);
	printf("%d characters in min line.\n",min);
    
    rewind(p);
}//任务二正确 
//具体的大小写字母的统计信息函数
void jutixinxi(FILE* p)
{
	CH A[26];
	CH B[26]; 
	for(int t=0;t<=25;++t)
	{
		A[t].n=0;
		B[t].n=0;
	}
	char ch;
	int m=0,h=0;
	ch = fgetc(p);
	while(ch!=EOF) {
	    if(ch>='A'&&ch<='Z')
	    {
	     m=(int)(ch-65);
		 ++A[m].n;	
		}
		else if(ch>='a'&&ch<='z')
		{
	   	 
	     h=(int)(ch-97);
		 ++B[h].n;	
		 //printf("%d\n",B[25].n) ;
		}
		ch = fgetc(p);	
	}
	//开始输出 	
	printf("Task3:\n");
	if(m!=0)
	 {
	 printf("CAPITAL:\n");
	 //printf("%d\n",B[25].n) ;
	 for(int k=0;k<=25;++k)
	  {
	  	//printf("%d\n",B[25].n) ;
	  	if(A[k].n!=0)
	  	{
	  		printf("%c:%d\n",(char)(k+65),A[k].n);
		  }
		  }	
	 }
	if(h!=0)
	 {
	 printf("LOWERCASE:\n");
	 for(int l=0;l<=25;++l)
	  {
	  	if(B[l].n!=0)
	  	{	  		
	  		printf("%c:%d\n",(char)(l+97),B[l].n);
		  }
		  }	
	 }
 } 

int main(void) {
	FILE *fPtr;
	int n;
	fPtr=fopen("dict.dic","r");
	if(fPtr!=NULL) {
		//printf("已打开\n"); 
        scanf("%d",&n);
        if(n==1)
         tongji(fPtr);
        else if(n==2)
         hangshu(fPtr);
		else if(n==3)
		 jutixinxi(fPtr); 
	}
	else
	 printf("未打开"); 
	fclose(fPtr);
	
	return 0;
}