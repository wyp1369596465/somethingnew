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
	printf("1. ����ѧ����Ϣ\n");
	printf("2. ���ѧ����Ϣ\n");
	printf("3. �����������в���\n");
	printf("4. ����\n");
	printf("5. ɾ��\n");
	printf("6. �˳�\n");
	printf("\n"); 
	while(select)
	{
		printf("��ѡ����Ҫ������ѡ��:");
		scanf("%d",&select);
		printf("\n");
		switch(select)
		{
			case 1:
				
			    printf("������ѧ����������"); 
			    scanf("%d",&x);
			    printf("\n");
			    sum=x; 
			    for(i=0;i<x;i++)
			    {
			    	printf("��%dλѧ����Ϣ\n",i+1);
			    	printf("\n");
				    printf("ѧ�ţ�");
				    scanf("%s",L.elem[i].no);
				    printf("\n");
				    printf("������");
				    scanf("%s",L.elem[i].name);
				    printf("\n");
				    printf("�ɼ���");
				    scanf("%d",&L.elem[i].grade);
				    printf("\n");
			    } 
			    L.last=x;
			    printf("\n");
			    break;
			    
			case 2:
				
			    printf("����ѧ���������ϢΪ��\n\n");
			    for(i=0;i<L.last;i++)
			    {
			    	printf("ѧ�ţ�%s ������%s �ɼ���%d\n\n",L.elem[i].no,L.elem[i].name,L.elem[i].grade);
				}
				printf("\n");
				break;
				 
			case 3:
				
			    printf("��������Ҫ���ҵ�ѧ��������");
			    scanf("%s",e.name);
			    temp=Locate(&L,e);
			    if(temp!=0)
			    printf("ѧ�ţ�%s �ɼ���%d\n\n",L.elem[temp-1].no,L.elem[temp-1].grade);
			    else
			    printf("����ʧ�ܣ�\n\n");
			    break;
			    
			
			    
			case 4:
				
				printf("��������Ҫ�����λ�ã�");
				scanf("%d",&a);
				printf("���������ѧ����Ϣ��\n");
				printf("ѧ�ţ�");
				scanf("%s",m.no);
				printf("������");
				scanf("%s",m.name);
				printf("�ɼ���");                                                                                
				scanf("%d",&m.grade);
				if(InsList(&L,a,m))
				{
					sum++;
					printf("����ɹ���\n\n"); 
				}
				else
				    printf("����ʧ�ܣ�\n\n");
				break;
				
			case 5:
				
				printf("������Ҫɾ��ѧ����λ�ã�");
			    scanf("%d",&c);
			    if(DelList(&L,c))
			    {
			    	sum--;
			    	printf("ɾ���ɹ�!\n\n");
				}
			    else
			        printf("ɾ��ʧ�ܣ�\n\n");
			    break;
			
			
			case 6:
			    {
			    	printf("\n�˳�ϵͳ�ɹ����밴�����������\n");
			    	exit(0);
				}
				break; 		
		} 
	}
	return 0;
} 
