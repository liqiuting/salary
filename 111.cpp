#include<stdio.h>
#include<stdlib.h>  //��������
#include<string.h>
#include<conio.h>
#define NUM 50
int n=0; //ȫ�ֱ�����ǵ�ǰ¼��ְ������
struct work
{
	char gonghao[10];    //����
	char name[10];      //����
	float gwsalary;     //��λ����
	float xjsalary;     // н������
	float zwsalary;     //ְ�����
	float jxsalary;     //��Ч����
	float yfsalary;     //Ӧ������
	float grsds;        //��������˰
	float real_salary;  //ʵ������
}newemp,zggz[NUM];

/***************************************************************************

�������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ������
��ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�

*****************************************************************************/
struct work* read()
{
	FILE *fp;    //�����ļ�ָ��
  //  int n=0;    //��¼ְ����
    if((fp=fopen("gx.dat","rb"))==NULL)      //��һ���������ļ�
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

void write(struct work zggz[])
{
	FILE *fp;    
	int i;    //�����ļ�ְ����
    if((fp=fopen("gz.dat","rb"))==NULL)     
	{
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return;
    }

	if(n==0)
	{
		printf("û����ϵ�˿ɶ�");
	}

	//д������

	for(i=0;i<n;i++)
	{
		fprintf(fp,"���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
		fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		
	}
		printf("\nְ����¼�������\n");
		fclose(fp);
		printf("\n��������������˵�\n");
		getch();
		return;
}

/*****���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼*****/

void find(struct work zggz[])
{
	FILE *fp;
	int i;
	char gonghao[10];  //���չ����ַ�����

	if((fp=fopen("gz.dat","rb"))==NULL)      
    {
        printf("\n�ļ�û��ְ����¼\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }

	printf("������Ҫ��ѯ��ְ�����ţ�\n");
	scanf("%s",gonghao);
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].gonghao,gonghao)==0)
		{
			printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		}
		else
		{
			printf("\t���޴���\n");
			
		}
		printf("\n��������������˵�\n");
			getch();
	}
     //printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
	 
       fclose(fp);
	  // printf("\n��������������˵�\n");
	  // getch();
	   
}

//��ʾ����ְ���ļ�¼

void list(struct work zggz[])
{
     FILE *fp;
	 int i;
     if((fp=fopen("gz.dat","rb"))==NULL)
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }
     printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
     for(i=0;i<n;i++)
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		 
	 }
    fclose(fp);
	//printf("\n��������������˵�\n");
	//getch();
}

/*****************************************************

ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��

******************************************************/
void modify(struct work zggz[])
{
     FILE *fp;
     int i;
     char gonghao[10];
     if((fp=fopen("gz.dat","wb+"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return;
    }
     printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",gonghao);
	 /*while(fread(&zggz,sizeof(zggz),1,fp)==1)
	 {
		 if(strcmp(gonghao,zggz.gonghao)==0)
		 {
			 printf("\n������ְ������:"); //����ְ�����
			 scanf("%s",zggz[i].gonghao);
			 printf("\n������ְ������:"); //����ְ������
			 gets(zggz[i].name);
			 printf("����ְ���Ĺ�����Ϣ\n");
			 printf("------------------------------\n");
			 printf("\n��λ����: ");
			 scanf("%f",&zggz[i].gwsalary);
			 printf("\nн������: ");
			 scanf("%f",&zggz[i].xjsalary);
			 printf("\nְ�����: ");
			 scanf("%f",&zggz[i].zwsalary);
			 printf("\n��Ч����: ");
			 scanf("%f",&zggz[i].jxsalary);
			 zggz[i].yfsalary=zggz[i].gwsalary+zggz[i].xjsalary+zggz[i].zwsalary+zggz[i].jxsalary;
			 zggz[i].real_salary=zggz[i].yfsalary-zggz[i].grsds;
			 fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
				zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
				zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		 }
	 }*/
     for(i=0;i<n;i++)//����ҵ��˾�ִ��������� ,�Ҳ���ֱ�ӻ�������
	 {
		 if(strcmp(zggz[i].gonghao,gonghao)==0)
		 {
			 printf("\n������ְ������:"); //����ְ�����
			 scanf("%s",zggz[i].gonghao);
			 printf("\n������ְ������:"); //����ְ������
			 gets(zggz[i].name);
			 printf("����ְ���Ĺ�����Ϣ\n");
			 printf("------------------------------\n");
			 printf("\n��λ����: ");
			 scanf("%f",&zggz[i].gwsalary);
			 printf("\nн������: ");
			 scanf("%f",&zggz[i].xjsalary);
			 printf("\nְ�����: ");
			 scanf("%f",&zggz[i].zwsalary);
			 printf("\n��Ч����: ");
			 scanf("%f",&zggz[i].jxsalary);
			 zggz[i].yfsalary=zggz[i].gwsalary+zggz[i].xjsalary+zggz[i].zwsalary+zggz[i].jxsalary;
			 zggz[i].real_salary=zggz[i].yfsalary-zggz[i].grsds;
			 fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
				zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
				zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		 }
	 }
    fclose(fp);
	printf("\n��������������˵�\n");
	getch();
}

//ɾ��ָ������ְ���ļ�¼

void del(struct work zggz[])
{
     FILE *fp;
     int i,j,n;
     char gonghao[5];
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
         printf("\nCannot open file\n");
		 printf("\n��������������˵�\n");
		 getch();
         return;
      }
     printf("ɾ��ǰ:\n");
     printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������:\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*nΪgz�ļ��м�¼��*/
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
    }
     printf("Ҫɾ����ְ����:");
     scanf("%s",gonghao);
     for(i=0;(strcmp(zggz[i].gonghao,gonghao)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\tû��%sְ���ŵ�ְ��\n",gonghao);
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
      printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*nΪgz�ļ��м�¼��*/
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
    }
       fclose(fp);
	   printf("\n��������������˵�\n");
	getch();
}

//�����������˰
float grsds(float x)
{
	float y=0;    //ȫ��Ӧ��˰
	if(x<500)
		y+=x*0.05;
	else if(x>=500&&x<2000)
		y+=(x-500)*0.1;
	else if(x>=2000&&x<5000)
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
		return 0;
}

//��ӹ��ʼ�¼���ṹ����zggzĩβ

void add(struct work zggz[])
{
      FILE *fp;
      int j;
      if((fp=fopen("gz.dat","rb+"))==NULL)
      {
          printf("\nCannot open file\n");
          printf("\n��������������˵�\n");
		 getch();
         return;
      }
       printf("Ҫ��ӵ�ְ������:");
       scanf("%d",&j);
       for(int i=n;i<n+j;i++) 
       { 
         printf("\n�������ְ������:"); //����ְ�����
			 scanf("%s",zggz[i].gonghao);
			 printf("\n�������ְ������:"); //����ְ������
			 scanf("%s",zggz[i].name);
			 printf("����ְ���Ĺ�����Ϣ\n");
			 printf("------------------------------\n");
			 printf("\n��λ����: ");
			 scanf("%f",&zggz[i].gwsalary);
			 printf("\nн������: ");
			 scanf("%f",&zggz[i].xjsalary);
			 printf("\nְ�����: ");
			 scanf("%f",&zggz[i].zwsalary);
			 printf("\n��Ч����: ");
			 scanf("%f",&zggz[i].jxsalary);
			 zggz[i].yfsalary=zggz[i].gwsalary+zggz[i].xjsalary+zggz[i].zwsalary+zggz[i].jxsalary;
			 zggz[i].grsds=grsds(zggz[i].yfsalary);
			 zggz[i].real_salary=zggz[i].yfsalary-zggz[i].grsds;

			 fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,  //����ְ����¼д���ļ�
				zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
				zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);

			 printf("%s%s%s%f%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,   //�����ְ����Ϣ
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
	   }
	    n=n+j;
      fclose(fp);
	  printf("\n��������������˵�\n");
	getch();
}



int main()
{
	system("cls"); //��������
	int a;
	struct work* p;//����һ���ṹָ��
	p=read();

	printf("\n");
	printf("        ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n");
	printf("\n");
	printf("        ��ѡ��(1-7):                                                    \n");
	printf("        ================================================================\n");
    printf("        |            1. ��ѯְ�����ʼ�¼                               |\n");
    printf("        |            2. �޸�ְ�����ʼ�¼                               |\n");
    printf("        |            3. ���ְ�����ʼ�¼                               |\n");
    printf("        |            4. ɾ��ְ�����ʼ�¼                               |\n");
    printf("        |            5. ����ְ�����ʼ�¼                               |\n");
    printf("        |            6. ���ְ�����ʼ�¼                               |\n");
    printf("        |            7. �˳�ְ�����ʼ�¼                               |\n");
    printf("        ================================================================\n");
	printf("\n");
	printf("        ���ѡ����:");
	scanf("%d",&a);
	if(a<1||a>7)
	{
		printf("����������ֲ���1~7�������������:");
		getch();
	}
	
	else
	{
		switch(a)
		{
			case 1: find(zggz);
				break;
			case 2: modify(zggz);
				break;
			case 3: add(zggz);
				break;
			case 4: del(zggz);
				break;
			case 5: write(zggz);
				break;
			case 6: list(zggz);
				break;
			case 7: printf("��ӭʹ��!\n");
				break;
		}
	}
	return 0;
}
