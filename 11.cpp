#include<stdio.h>
#include<string.h>
#include<conio.h>
#define NUM 50
struct work
{
	char gonghao[10];    //����
	char name[10];      //����
	float gwsalary;     //��λ����
	float xjsalary;     // н������
	float zwsalary;     //ְ�����
	float jxsalary;     //��Ч����
	float yfsalary;     //Ӧ������
	float tax;          //��������˰
	float real_salary;  //ʵ������
}zggz[NUM],newemp;

//�������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�

struct work* read()
{
	FILE *fp;    //����һ���ļ�ָ��
    int n=0;    //��¼ְ����
    if((fp=fopen("gz.dat","rb"))==NULL)      //��һ���������ļ�
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return 0;
    }
	else
	{
		for(int i=0;!feof(fp);i++)
		{   
			fread(&zggz[i],sizeof(struct work),1,fp);
			n++;
		}
		fclose(fp);
		printf("\nְ���������ݶ�ȡ���,����%d��\n",n);
	}
	printf("\n��������������˵�\n");
	getch();
}

//��zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�

void write()
{
	FILE *fp;
	int n=0;    //�����ļ�ְ����
    if((fp=fopen("gx.dat","rb"))==NULL)      //��һ���������ļ�
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }
	else
	{
		for(int i=0;!feof(fp);i++)
		{
			fwrite(&zggz[i],sizeof(struct work),1,fp);
			n++;
		}
		fclose(fp);
	}
	printf("\n��������������˵�\n");
	getch();
}

//���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼

void find()
{
	FILE *fp;
	int i;
	char gonghao[10];
	if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }
	printf("����ְ�����ţ�\n");
	scanf("%s",gonghao);
	for(i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].gonghao,gonghao)) break;
	if(feof(fp))
    {
        printf("\t���޴���\n");
        printf("\n��������������˵�\n");
		getch();
    }
     printf("����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������\n");
	 for(i=0;i<NUM;i++)
     printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].tax,zggz[i].real_salary);
       fclose(fp);
	   printf("\n��������������˵�\n");
	   getch();
}

//��ʾ����ְ���ļ�¼

void list()
{
     FILE *fp;
	 int i;
     if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }
     printf("����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].tax,zggz[i].real_salary);
	 }
    fclose(fp);
	printf("\n��������������˵�\n");
	getch();
}

//ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��

void modify()
{
     FILE *fp;
     int i;
     char gonghao[10];
     if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return;
    }
     printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",gonghao);
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].gonghao,gonghao)) break;
     if(feof(fp))
     {
          printf("\tû��%sְ���ŵ�ְ��\n",gonghao);
          printf("\n��������������˵�\n");
		  getch();
     }
     printf("����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
         printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].tax,zggz[i].real_salary);
     }
	printf("�����ʽ:����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������ <Enter>\n");
    printf("��%d����¼:",i+1);
    scanf("%s%s%s%d%f%f%f%f%f",newemp.gonghao,newemp.name,newemp.gwsalary,&newemp.xjsalary,
               &newemp.zwsalary,&newemp.jxsalary,&newemp.yfsalary,&newemp.tax,&newemp.real_salary);//��ȡ�µ�ְ����
    fseek(fp,-(long)sizeof(struct work),SEEK_CUR);  //�ļ�ָ��ָ����޸ĵļ�¼��ͷ
    fwrite(&newemp,sizeof(struct work),1,fp);  //��newemp���ǵ�ǰ��¼
    printf("�޸ĺ�:\n");
    fseek(fp,0,SEEK_SET);        //��ʾ�޸ĺ���ļ�����
    printf("����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].tax,zggz[i].real_salary);
    }
    fclose(fp);
	printf("\n��������������˵�\n");
	getch();
}

//ɾ��ָ������ְ���ļ�¼

void del()

{
     FILE *fp;
     int i,j,n;
     char number[5];
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
         printf("\nCannot open file\n");
		 printf("\n��������������˵�\n");
		 getch();
         return;
      }
     printf("ɾ��ǰ:\n");
     printf("����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������:\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*nΪgz�ļ��м�¼��*/
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].tax,zggz[i].real_salary);
    }
     printf("Ҫɾ����ְ����:");
     scanf("%s",number);
     for(i=0;(strcmp(zggz[i].gonghao,number)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\tû��%sְ���ŵ�ְ��\n",number);
          printf("\n��������������˵�\n");
		  getch();
         return;
     }
     fclose(fp);
     fp=fopen("gz.dat","w+");
     if(n==1)  /*һ����¼�Ѿ�ɾ����*/
     {
           fclose(fp);
           printf("\n��������������˵�\n");
		 getch();
         return;
     }
     for(j=0;j<i;j++)
        fwrite(&zggz[j],sizeof(struct work),1,fp);
     for(j=i+1;j<n;j++)
         fwrite(&zggz[j],sizeof(struct work),1,fp);
     printf("ɾ����:\n");
     fseek(fp,0,SEEK_SET);
      printf("����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*nΪgz�ļ��м�¼��*/
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].tax,zggz[i].real_salary);
    }
       fclose(fp);
	   printf("\n��������������˵�\n");
	getch();
}

//��ӹ��ʼ�¼���ṹ����zggzĩβ

void add()
{
      FILE *fp;
      int n;
      if((fp=fopen("gz.dat","ab+"))==NULL)
      {
          printf("\nCannot open file\n");
          printf("\n��������������˵�\n");
		 getch();
         return;
      }
      printf("Ҫ��ӵ�ְ������:");
      scanf("%d",n);
      for(int i=0;i<n;i++) 
      { 
          printf("�����ʽ:����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������   <Enter>\n");
         printf("��Ӽ�¼:\n");
         scanf("%s%s%f%f%f%f%f%f%f",newemp.gonghao,newemp.name,&newemp.gwsalary,&newemp.xjsalary,
                   &newemp.zwsalary,&newemp.jxsalary,&newemp.yfsalary,&newemp.tax,&newemp.real_salary);
        fwrite(&newemp,sizeof(struct work),1,fp);   //����ְ����¼д���ļ�
      }
      fclose(fp);
	  printf("\n��������������˵�\n");
	getch();
}

//�����������˰

void grsds(float m)
{
	float x;      //ȫ��Ӧ��˰���ö�
	float y=0;    //ȫ��Ӧ��˰
	if(x<500)
		y+=x*0.05;
	else if(x<2000)
		y+=(x-500)*0.1;
	else if(x<5000)
		y+=(x-2000)*0.15;
	else if(x<20000)
		y+=(x-5000)*0.2;
	else if(x<40000)
		y+=(x-20000)*0.25;
	else if(x<60000)
		y+=(x-40000)*0.3;
	else if(x<80000)
		y+=(x-60000)*0.35;
	else if(x<100000)
		y+=(x-80000)*0.4;
	else(x>100000);
		y+=(x-100000)*0.45;
}

int main()
{
	int a;
	char ch;
	struct work* p;//����һ���ṹָ��
	p=read();
	printf("1.��ѯְ�����ʼ�¼\n");
	printf("2.�޸�ְ�����ʼ�¼\n");
	printf("3.���ְ�����ʼ�¼\n");
	printf("4.ɾ��ְ�����ʼ�¼\n");
	printf("5.����ְ�����ʼ�¼\n");
	printf("6.���ְ�����ʼ�¼\n");
	printf("7.�˳�ְ�����ʼ�¼\n");
	printf("����������ѡ��(1~7):\n");
	scanf("%d",&a);
	if(a<1||a>7)
	{
		printf("����������ֲ���1~7������������:\n");
		getch();
	}
	else
	{
		switch(a)
		{
			case 1: find();
				break;
			case 2: modify();
				break;
			case 3: add();
				break;
			case 4: del();
				break;
			case 5: write();
				break;
			case 6: list();
				break;
			case 7: printf("��ӭʹ��!\n");
				break;
		}
	}
	return 0;
}
