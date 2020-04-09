#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct{
	char no[20];       
	char name[20];   
	int grade;        
}Student;

typedef struct{
	Student elem[MAXSIZE];
	int last;    
}SeqList;

int Locate(SeqList *L,Student e)   
{     
    int i;
    for(i=0;i<L->last+1;i++)
	{
		if(!strcmp(L->elem[i].name,e.name)) 
		return i+1;  
    }
    return 0;
}

int InsList(SeqList *L,int i,Student e)   
{ 
	int k;
	if(i<1||(i>L->last+2))
	{
		return 0;
	}
	for(k=L->last;k>=i-1;k--) 
	L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;
	L->last++;
	return 1;
}

int DelList(SeqList *L,int i)  
{      
	int k;
	if(i<1||i>L->last+1)
	return 0;
	for(k=i;k<=L->last;k++) 
	{
		L->elem[k-1]=L->elem[k]; 
	}
	L->last--;
	return 1;
}

int main()
{
	int i,x,a,temp,select,sum=0,c;
	SeqList L;
	Student m,e;
	printf("1. 输入学生信息\n");
	printf("2. 输出学生信息\n");
	printf("3. 根据姓名进行查找\n");
	printf("4. 插入\n");
	printf("5. 删除\n");
	printf("6. 退出\n");
	printf("\n"); 
	while(select)
	{
		printf("请选择你要操作的选项:");
		scanf("%d",&select);
		printf("\n");
		switch(select)
		{
			case 1:
				
			    printf("请输入学生的数量："); 
			    scanf("%d",&x);
			    printf("\n");
			    sum=x; 
			    for(i=0;i<x;i++)
			    {
			    	printf("第%d位学生信息\n",i+1);
			    	printf("\n");
				    printf("学号：");
				    scanf("%s",L.elem[i].no);
				    printf("\n");
				    printf("姓名：");
				    scanf("%s",L.elem[i].name);
				    printf("\n");
				    printf("成绩：");
				    scanf("%d",&L.elem[i].grade);
				    printf("\n");
			    } 
			    L.last=x;
			    printf("\n");
			    break;
			    
			case 2:
				
			    printf("所有学生的相关信息为：\n\n");
			    for(i=0;i<L.last;i++)
			    {
			    	printf("学号：%s 姓名：%s 成绩：%d\n\n",L.elem[i].no,L.elem[i].name,L.elem[i].grade);
				}
				printf("\n");
				break;
				 
			case 3:
				
			    printf("请输入你要查找的学生姓名：");
			    scanf("%s",e.name);
			    temp=Locate(&L,e);
			    if(temp!=0)
			    printf("学号：%s 成绩：%d\n\n",L.elem[temp-1].no,L.elem[temp-1].grade);
			    else
			    printf("查找失败！\n\n");
			    break;
			    
			
			    
			case 4:
				
				printf("请输入你要插入的位置：");
				scanf("%d",&a);
				printf("请输入插入学生信息：\n");
				printf("学号：");
				scanf("%s",m.no);
				printf("姓名：");
				scanf("%s",m.name);
				printf("成绩：");                                                                                
				scanf("%d",&m.grade);
				if(InsList(&L,a,m))
				{
					sum++;
					printf("插入成功！\n\n"); 
				}
				else
				    printf("插入失败！\n\n");
				break;
				
			case 5:
				
				printf("请输入要删除学生的位置：");
			    scanf("%d",&c);
			    if(DelList(&L,c))
			    {
			    	sum--;
			    	printf("删除成功!\n\n");
				}
			    else
			        printf("删除失败！\n\n");
			    break;
			
			
			case 6:
			    {
			    	printf("\n退出系统成功！请按任意键结束！\n");
			    	exit(0);
				}
				break; 		
		} 
	}
	return 0;
} 
