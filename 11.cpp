#include<stdio.h>
#include<conio.h>
using namespace std;
#define n 50;
struct work
{
	char gonghao[10];       //����
	char name[10];      //����
	float gwsalary;     //��λ����
	float xjsalary;     // н������
	float zwsalary;     //ְ�����
	float jxsalary;     //��Ч����
	float yfsalary;     //Ӧ������
	float tax;          //��������˰
	float real_salary;  //ʵ������
}zggz[n],newemp;

//�������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�

void read()
{
	FILE *fp;
     int n=0;    //��¼ְ����
    if((fp=fopen("gx.dat","rb"))==NULL)      //��һ���������ļ�
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }

	else
	{
		for(i=0;!feof(fp);i++)
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
	char gonghao[10];
	if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }
	cout<<"����ְ�����ţ�";
	cin>>gonghao;
	for(int i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].gonghao,gonghao)) break;
	if(feof(fp))
    {
        printf("\t���޴���\n");
        exit(1);
    }
     cout<<"����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������"<<endl;
	 for(int i=0;i<n;i++)
     cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
       fclose(fp);
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
     cout<<"����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
			  <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		      <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
	 }
    fclose(fp);
}

//ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��

void modify()
{
     FILE *fp;
     int i,j;
     char gonghao[10];
     if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }
     printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",gonghao);
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].number,gonghao)) break;
     if(feof(fp))
     {
          printf("\tû��%sְ���ŵ�ְ��\n",gonghao);
          exit(1);
     }
     cout<<"����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
			  <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
			  <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
     }
    printf("�����ʽ:����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������ <Enter>\n");
    printf("��%d����¼:",i+1);
    scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,newemp.sex,&newemp.age,
               &newemp.wage1,&newemp.wage2,&newemp.funds,&newemp.WATERfee,&newemp.TAXfee);//��ȡ�µ�ְ����¼
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;
    fseek(fp,-(long)sizeof(struct work),SEEK_CUR);  //�ļ�ָ��ָ����޸ĵļ�¼��ͷ
     fwrite(&newemp,sizeof(struct work),1,fp);  //��newemp���ǵ�ǰ��¼
     printf(" �޸ĺ�:\n");
    fseek(fp,0,SEEK_SET);        //��ʾ�޸ĺ���ļ�����
     cout<<"����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
    }
    fclose(fp);
}

//ɾ��ָ������ְ���ļ�¼

void del()

{
     FILE *fp;
     int i,j,n;
     char number[5];
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
         printf("���ܴ�gx�ļ�\n");
         exit(1);
      }
     printf("ɾ��ǰ:\n");
     printf("����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������:\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*nΪgz�ļ��м�¼��*/
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
    }
     printf("Ҫɾ����ְ����:");
     scanf("%s",number);
     for(i=0;(strcmp(zggz[i].num,number)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\tû��%sְ���ŵ�ְ��\n",number);
          exit(2);
     }
     fclose(fp);
     fp=fopen("gz.dat","w+");
     if(n==1)  /*һ����¼�Ѿ�ɾ����*/
     {
           fclose(fp);
           exit(3);
     }
     for(j=0;j<i;j++)
        fwrite(&emp[j],sizeof(struct work),1,fp);
     for(j=i+1;j<n;j++)
         fwrite(&emp[j],sizeof(struct work),1,fp);
     printf("ɾ����:\n");
     fseek(fp,0,SEEK_SET);
      cout<<"����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*nΪgz�ļ��м�¼��*/
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
    }
       fclose(fp);
}

//��ӹ��ʼ�¼���ṹ����zggzĩβ

void add()
{
      FILE *fp;
      int n,i,j;
      if((fp=fopen("gx.dat","ab+"))==NULL)
      {
          printf("���ܴ�gx�ļ�\n");
           exit(0);
      }
    printf("Ҫ��ӵ�ְ������:");
      scanf("%d",&n);
      for(i=0;i<n;i++) 
      { 
          printf("�����ʽ:����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������   <Enter>\n");
         printf("׷�Ӽ�¼:\n");
         scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,newemp.sex,&newemp.age,
                   &newemp.wage1,&newemp.wage2,&newemp.funds,&newemp.WATERfee,&newemp.TAXfee);
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;//��ȡһ���µ�ְ����¼
        fwrite(&newemp,sizeof(struct work),1,fp);   //����ְ����¼д���ļ�
      }
      fclose(fp);
}

//�����������˰

void grsds()
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
	else(x>100000)
		y+=(x-100000)*0.45;
}

int main()
{
	int a;
	char ch;
	struct zggz*p;
	p=read();
	cout<<"1.��ѯְ�����ʼ�¼"<<endl
		<<"2.�޸�ְ�����ʼ�¼"<<endl
		<<"3.���ְ�����ʼ�¼"<<endl
		<<"4.ɾ��ְ�����ʼ�¼"<<endl
		<<"5.����ְ�����ʼ�¼"<<endl
		<<"6.���ְ�����ʼ�¼"<<endl
		<<"7.�˳�ְ�����ʼ�¼"<<endl;
	cout<<"����������ѡ��(1~7)��";
	cin>>a;
	if(a<1||a>7)
	{
		cout<<"����������ֲ���1~7�����������룺";
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
			case 7: cout<<"лл����ӭ�´ι���!";
				break;
		}
	}
	return 0;
}
