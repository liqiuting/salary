#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int n=0; //ȫ�ֱ�����ǵ�ǰ¼��ְ������
struct work
{
	char number[10];    //����
	char name[10];      //����
	float gwsalary;     //��λ����
	float xjsalary;     //н������
	float zwsalary;     //ְ�����
	float jxsalary;     //��Ч����
	float yfsalary;     //Ӧ������
	float grsds;        //��������˰
	float real_salary;  //ʵ������
};

/***************************************************************************

�������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ������
��ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�

****************************************************************************/

int read(struct work zggz[])
{
	FILE *fp;    //�����ļ�ָ��
	struct work z;

    if((fp=fopen("gx.dat","rb"))==NULL)      //��һ���������ļ�
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return 0;
    }
	
		while(!feof(fp))
	{
		fscanf(fp,"%s",z.number);
		fscanf(fp,"%s",z.name);
		fscanf(fp,"%f",&z.gwsalary);
		fscanf(fp,"%f",&z.xjsalary);
		fscanf(fp,"%f",&z.zwsalary);
		fscanf(fp,"%f",&z.jxsalary);
		fscanf(fp,"%f",&z.yfsalary);
		fscanf(fp,"%f",&z.grsds);
		fscanf(fp,"%f",&z.real_salary);
		zggz[n]=z;
		n++;
	}

		fclose(fp);
		printf("\nְ���������ݶ�ȡ���,����%d��\n",n);
		return n;
}

/**************��zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�**************/

void write(struct work zggz[])
{
	FILE *fp;    
	int i;    

    if((fp=fopen("gx.dat","wb"))==NULL)     
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
		fprintf(fp,"%s",zggz[i].number);
		fprintf(fp,"%s",zggz[i].name);
		fprintf(fp,"%f",zggz[i].gwsalary);
		fprintf(fp,"%f",zggz[i].xjsalary);
		fprintf(fp,"%f",zggz[i].zwsalary);
		fprintf(fp,"%f",zggz[i].jxsalary);
		fprintf(fp,"%f",zggz[i].yfsalary);
		fprintf(fp,"%f",zggz[i].grsds);
		fprintf(fp,"%f",zggz[i].real_salary);
	}

		fclose(fp);
		printf("\n��д��%d���˵�����\n",n);
		printf("\n");
}

/***********************���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼*************************/

void find(struct work zggz[])
{
	FILE *fp;
	int i;//��¼Ա��λ��
	int flag=0;//��¼Ա����û�д���
	char gonghao[10];  //���չ����ַ�����

	if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\n�ļ�û��ְ����¼\n");
		printf("\n��������������˵�\n");
		getch();
        return ;
    }

	printf("������Ҫ��ѯ��ְ�����ţ�\n");
	scanf("%s",gonghao);

    //�����ṹ�����飬�������޸ù��ŵ�Ա��������flag=1,��֮flag=0
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].number,gonghao)==0)
		{
			flag=1;
			break;
		}
	}
		if(flag)
		{
			printf("���� %s\n",zggz[i].number);
			printf("���� %s\n",zggz[i].name);
			printf("��λ���� %f\n",zggz[i].gwsalary);
			printf("н������ %f\n",zggz[i].xjsalary);
			printf("ְ����� %f\n",zggz[i].zwsalary);
			printf("��Ч���� %f\n",zggz[i].jxsalary);
			printf("Ӧ������ %f\n",zggz[i].yfsalary);
			printf("��������˰ %f\n",zggz[i].grsds);
			printf("ʵ������ %f\n",zggz[i].real_salary);
			
		}

		else
		{
			printf("\t���޴���\n");
		}

       fclose(fp);
	   printf("\n");
}

/*******************************��ʾ����ְ���ļ�¼********************************/

void list(struct work zggz[])
{
    printf("����    ����    ��λ����    н������    ְ�����    ��Ч����    Ӧ������    ��������˰    ʵ������\n");
    for(int i=0;i<n;i++)
    {
		printf("%s\t",zggz[i].number);
		printf("%s\t",zggz[i].name);
		printf("%f\t",zggz[i].gwsalary);
		printf("%f\t",zggz[i].xjsalary);
		printf("%f\t",zggz[i].zwsalary);
		printf("%f\t",zggz[i].jxsalary);
		printf("%f\t",zggz[i].yfsalary);
		printf("%f\t",zggz[i].grsds);
		printf("%f\t",zggz[i].real_salary);
		printf("\n");
	}

}

/****************************************************************************

ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��

*****************************************************************************/

void modify(struct work zggz[])
{
     FILE *fp;
     int i;
	 int k;//����޸�Ա��
     char gonghao[10];

     if((fp=fopen("gx.dat","rb+"))==NULL)
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return;
    }

     printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",gonghao);

     for(i=0;i<n;i++)//����ҵ��˾�ִ��������� ,�Ҳ���ֱ�ӻ�������
	 {
		 if(strcmp(zggz[i].number,gonghao)==0)
		 {
			 printf("\n������ְ������:"); //����ְ�����
			 scanf("%s",zggz[i].number);
			 printf("\n������ְ������:"); //����ְ������
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
			 zggz[i].real_salary=zggz[i].yfsalary-zggz[i].grsds;
			 fprintf(fp,"%s %s %f %f %f %f %f %f %f",zggz[i].number,zggz[i].name,zggz[i].gwsalary,
				zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
				zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
			 k=i;
		 }
	 }

     fclose(fp);
	 printf("\n��������������˵�\n");
	 getch();
}

/*******************************ɾ��ָ������ְ���ļ�¼*******************************/

void del(struct work zggz[])
{
     FILE *fp;
	 int i;
	 int k;
	 int flag=0;//�����û�и�Ա��
     char gonghao[10];//��Ҫɾ����Ա�����

     if((fp=fopen("gx.dat","rb+"))==NULL)
     {
         printf("\nCannot open file\n");
		 printf("\n��������������˵�\n");
		 getch();
         return;
      }

     printf("ɾ��ǰԱ����Ϣ����:\n");
	 list(zggz);//�����������
	 printf("\n");

     printf("Ҫɾ����ְ����:");
     scanf("%s",gonghao);

	 for(i=0;i<n;i++)
	 {
		 if(strcmp(zggz[i].number,gonghao)==0)
		 {
			 flag=1;
			 break;
		 }
	 }
	 
	 if(flag)
	 {
		 printf("/nȷʵҪ�޸Ĵ�����Ϣ�밴1�����޸��밴0\n");
		 scanf("%d",&k);
		 if(k==1)
		 {
			 for(int j=i;j<n;j++)
			 {
				 zggz[j]=zggz[j+1];
			 }
			 n=n-1;
			 write(zggz);
			 printf("ɾ����Ա����Ϣ����:\n");
			 list(zggz);
		 }
		 else if(k==0)
		 {
			 printf("\n��������������˵�\n");
			 getch();
		 }
	
	 }
	 else
	 {
		 printf("\tû��%sְ���ŵ�ְ��\n",gonghao);
	 }

     fclose(fp);
}

/******************************�����������˰********************************/

float grsds(float x)
{
	float y=0;    //ȫ��Ӧ��˰
	if(x<500)
		y+=float(x*0.05);
	else if(x>=500&&x<2000)
		y+=float((x-500)*0.1);
	else if(x>=2000&&x<5000)
		y+=float((x-2000)*0.15);
	else if(x<20000)
		y+=float((x-5000)*0.2);
	else if(x<40000)
		y+=float((x-20000)*0.25);
	else if(x<60000)
		y+=float((x-40000)*0.3);
	else if(x<80000)
		y+=float((x-60000)*0.35);
	else if(x<100000)
		y+=float((x-80000)*0.4);
	else(x>100000);
		y+=float((x-100000)*0.45);
		return 0;
}

/*********************��ӹ��ʼ�¼���ṹ����zggzĩβ************************/

void add(struct work zggz[])
{
	FILE *fp;
	struct work Z;

	if((fp=fopen("gx.dat","rb+"))==NULL)
    {
         printf("\nCannot open file\n");
		 printf("\n��������������˵�\n");
		 getch();
         return;
     }

	 printf("\n������ְ������:"); //����ְ�����
	 scanf("%s",Z.number);
	 printf("\n������ְ������:"); //����ְ������
	 scanf("%s",Z.name);
	 printf("����ְ���Ĺ�����Ϣ\n");
	 printf("------------------------------\n");
	 printf("\n��λ����: ");
	 scanf("%f",&Z.gwsalary);
	 printf("\nн������: ");
	 scanf("%f",&Z.xjsalary);
	 printf("\nְ�����: ");
	 scanf("%f",&Z.zwsalary);
	 printf("\n��Ч����: ");
	 scanf("%f",&Z.jxsalary);
	 Z.yfsalary=Z.gwsalary+Z.xjsalary+Z.zwsalary+Z.jxsalary;
	 Z.grsds=grsds(Z.yfsalary);
	 Z.real_salary=Z.yfsalary-Z.grsds;
	 zggz[n]=Z;
	 n++;
	 printf("\nԱ����Ϣ�Ѿ����\n");
	 write(zggz);
	 fclose(fp);
}

int main()
{
	int a;
	int b;
	struct work zg[100];
	b=read(zg);

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
		printf("����������ֲ���1~7�������������");
		getch();
	}
	
	else
	{
		switch(a)
		{
			case 1: find(zg);
				break;
			case 2: modify(zg);
				break;
			case 3: add(zg);
				break;
			case 4: del(zg);
				break;
			case 5: write(zg);
				break;
			case 6: list(zg);
				break;
			case 7: printf("��ӭʹ��!\n");
				break;
		}
	}
	system("pause");
	return 0;
}
