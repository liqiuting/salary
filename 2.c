#include<stdio.h>
#include<conio.h>
#define n
struct work
{
	char num[10];  //����
	char name[10];  //����
	float gwsalary;  //��λ����
	float xjsalary;  // н������
	float zwsalary;  //ְ�����
	float jxsalary;  //��Ч����
	float yfsalary;  //Ӧ������
	float tax;  //��������˰
	float real_salary;  //ʵ������
};

//�������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ�����鲢ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�

void read()
{
	FILE *fp;
    if(!f1)
	{ 
		cout<<"Cannot open output file\n";
		w=0;
		abort();
	}
    n=0;
    for(int i=0;!feof(f1);i++)
    {   
        f1.read((char*) &zggz1[i],sizeof(zggz1[i]));
        n++;
    }
    n=n-1;
	f1.close();
}

//��zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�

void write()
{
	ofstream f2("gx.dat",ios::binary);
	if(!f2)
	{ 
		cout<<"Cannot open output file\n";
		abort();
	}
	for(int i=0;i<n;i++)
		f2.write((char*) &zggz1[i],sizeof(zggz1[i]));
	f2.close();
}

//���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼

void find()
{
	FILE *fp;
	char gonghao[10]; 
	cout<<"����ְ�����ţ�";
	cin>>gonghao;
	for(i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].num,gonghao)) break;
	if(feof(fp))
    {
        printf("\t���޴���\n");
        exit(2);
    }
     cout<<"����   ����   ��λ����   н������   ְ�����   ��Ч����   Ӧ������   ��������˰   ʵ������"<<endl;
     cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
       fclose(fp);
}

//��ʾ����ְ���ļ�¼

void list()
{
     int i;
     FILE *fp;
     if((fp=fopen("gx.dat","r"))==NULL)
     {     
         printf("���ܴ�gx�ļ�\n");
         exit(0);
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

}

//ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��

void grsds()
{
	
}
int main()
{
	int a;
	struct zggz*p;
	p=read();
	cout<<"1.��ѯ"<<endl
		<<"2.�޸�"<<endl
		<<"3.���"<<endl
		<<"4.ɾ��"<<endl
		<<"5.����"<<endl
		<<"6.���"<<endl
		<<"7.�˳�"<<endl;
	cout<<"����������ѡ��(1~7)��";
	cin>>a;
	if(a<1||a>7)
	{
		cout<<"����������ֲ���1~7�����������룺";
	}
	else
	{
		switch(a)
		{
			case 1:
				find();
				break;
			case 2:
				modify();
				break;
			case 3:
				add();
				break;
			case 4:
				del();
				break;
			case 5:
				write();
				break;
			case 6:
				list();
				break;
			case 7:
				cout<<"лл����ӭ�´ι���!";
				break;
		}
	}
	return 0;
}
