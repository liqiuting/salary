#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define TURE 1
int n = 0;   //ȫ�ֱ�����ǵ�ǰ¼��ְ������

/*��������*/
void read(struct work zggz[]);
void write(struct work zggz[]);
void find(struct work zggz[]);
void list(struct work zggz[]);
void modify(struct work zggz[]);
void del(struct work zggz[]);
void add(struct work zggz[]);
float grsds(float m);

struct work   /*����ְ�����ʽṹ������*/
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

void main()
{
	int a;
	struct work zg[100];
	read(zg);

	while (TURE)
	{
		system("cls");    //��������

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

		if (a<1||a>7)
		{
			printf("����������ֲ���1~7�����������������ѡ��");
			getch();
		}
	
		else
		{
			switch (a)
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
				case 7: printf("\n\t��ӭʹ��!\n");
					return;
					break;
			}

		}

	}

	system("pause");
	return;

}


/***************************************************************************

   �������ļ��ж�ȡְ���������ݡ���ʼ��ְ�����ʽṹ������
   ��ͳ�Ƶ�ǰ�����ļ���ְ������������ְ����������ȫ�ֱ���n�У��Ա���������ʹ�á�

****************************************************************************/

void read(struct work zggz[])
{
	FILE *fp;    //�����ļ�ָ��
	struct work z;

    if ((fp = fopen("gz.dat","rb")) == NULL)      //��һ���������ļ�
    {
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return;
    }
	
	while (!feof(fp))
	{
		fscanf(fp,"%s\t",z.number);
		fscanf(fp,"%s\t",z.name);
		fscanf(fp,"%f\t",&z.gwsalary);
		fscanf(fp,"%f\t",&z.xjsalary);
		fscanf(fp,"%f\t",&z.zwsalary);
		fscanf(fp,"%f\t",&z.jxsalary);
		fscanf(fp,"%f\t",&z.yfsalary);
		fscanf(fp,"%f\t",&z.grsds);
		fscanf(fp,"%f\n",&z.real_salary);
		zggz[n]=z;
		n++;
	}

		fclose(fp);
		printf("\n\tְ���������ݶ�ȡ���,����%d��\n",n);
		printf("\n\t5������");
		Sleep(5000);//��ʱ5��
}

/**************��zggz�ṹ�������еļ�¼���浽gz.dat�����ļ��С�**************/

void write(struct work zggz[])
{
	FILE *fp;    
	int i;    

    if ((fp = fopen("gz.dat","wb")) == NULL)     
	{
        printf("\nCannot open file\n");
		printf("\n��������������˵�\n");
		getch();
        return;
    }

	if(n == 0)
	{
		printf("\tû����ϵ�˿ɶ�");
	}

	//д������

	for (i = 0;i<n;i++)
	{
		fprintf(fp,"%s\t",zggz[i].number);
		fprintf(fp,"%s\t",zggz[i].name);
		fprintf(fp,"%f\t",zggz[i].gwsalary);
		fprintf(fp,"%f\t",zggz[i].xjsalary);
		fprintf(fp,"%f\t",zggz[i].zwsalary);
		fprintf(fp,"%f\t",zggz[i].jxsalary);
		fprintf(fp,"%f\t",zggz[i].yfsalary);
		fprintf(fp,"%f\t",zggz[i].grsds);
		fprintf(fp,"%f\n",zggz[i].real_salary);
	}

		fclose(fp);
		printf("\t\t\n��д��%d���˵�����\n",n);	
		printf("\n");
		getch();
		return;
}

/***********************���ݹ��Ų�ѯ��Ӧְ���Ĺ��ʼ�¼*************************/

void find(struct work zggz[])
{
	int i;               //��¼Ա��λ��
	int j;               //��¼Ա��λ��
	int flag = 0;       //��¼Ա����û�д���
	char gonghao[10];  //���չ����ַ�����

	printf("\n");
	printf("������Ҫ��ѯ��ְ�����ţ�");
	scanf("%s",gonghao);
	printf("\n");

    //�����ṹ�����飬�������޸ù��ŵ�Ա��������flag=1,��֮flag=0
	for(i = 0;i<n;i++)
	{
		if (strcmp(zggz[i].number,gonghao) == 0)
		{
			flag = 1;
			break;
		}
	}
		if (flag)
		{
			printf("����\t\t%s\n",zggz[i].number);
			printf("����\t\t%s\n",zggz[i].name);
			printf("��λ���� \t%f\n",zggz[i].gwsalary);
			printf("н������ \t%f\n",zggz[i].xjsalary);
			printf("ְ����� \t%f\n",zggz[i].zwsalary);
			printf("��Ч���� \t%f\n",zggz[i].jxsalary);
			printf("Ӧ������ \t%f\n",zggz[i].yfsalary);
			printf("��������˰\t%f\n",zggz[i].grsds);
			printf("ʵ������ \t%f\n",zggz[i].real_salary);

			for(j = i + 1;j < n;j++)
			{
				if (strcmp(zggz[j].number,gonghao) == 0)
				{
					printf("\n");
					printf("����\t\t%s\n",zggz[j].number);
					printf("����\t\t%s\n",zggz[j].name);
					printf("��λ���� \t%f\n",zggz[j].gwsalary);
					printf("н������ \t%f\n",zggz[j].xjsalary);
					printf("ְ����� \t%f\n",zggz[j].zwsalary);
					printf("��Ч���� \t%f\n",zggz[j].jxsalary);
					printf("Ӧ������ \t%f\n",zggz[j].yfsalary);
					printf("��������˰\t%f\n",zggz[j].grsds);
					printf("ʵ������ \t%f\n",zggz[j].real_salary);
				}
			}
			
		}

		else
		{
			printf("\t���޴���\n");
		}

	   printf("\n");
	   printf("\n��������������˵�\n");
	   getch();
	   return;
}

/*******************************��ʾ����ְ���ļ�¼********************************/

void list(struct work zggz[])
{
	printf("\n");
    printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
	printf("\n");

    for (int i = 0;i<n;i++)
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

	printf("\n");
	printf("\n�����������\n");
	getch();
	return;

}

/****************************************************************************

    ָ�����ţ��޸ĸ�ְ���Ĺ��ʼ�¼������Ҫ����grsds()���������������˰��

*****************************************************************************/

void modify(struct work zggz[])
{
     int i;
	 int k;   //����Ƿ��޸�Ա��
     char gonghao[10];

	 printf("\n");
     printf("Ҫ�޸ĵ�ְ����:");
     scanf("%s",gonghao);
	 printf("\n");

     for (i = 0;i<n;i++)   //����ҵ��˾�ִ��������� ,�Ҳ���ֱ�ӻ�������
	 {
		 if (strcmp(zggz[i].number,gonghao) == 0)
		 {
			 printf("\n��Ա��ԭ����ϢΪ:\n");
			 printf("\n");
			 printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
			 printf("\n");
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

			 zggz[i].yfsalary = zggz[i].gwsalary + zggz[i].xjsalary + zggz[i].zwsalary + zggz[i].jxsalary;
			 zggz[i].grsds = grsds(zggz[i].yfsalary);
			 zggz[i].real_salary = zggz[i].yfsalary - zggz[i].grsds;
			
			 k=i;			
		 }
	 }

	 printf("\n�޸ĺ����Ϣ:\n");
	 printf("\n");
	 printf("����\t����\t��λ����\tн������\tְ�����\t��Ч����\tӦ������\t��������˰\tʵ������\n");
	 printf("%s\t",zggz[k].number);
	 printf("%s\t",zggz[k].name);
	 printf("%f\t",zggz[k].gwsalary);
	 printf("%f\t",zggz[k].xjsalary);
	 printf("%f\t",zggz[k].zwsalary);
	 printf("%f\t",zggz[k].jxsalary);
	 printf("%f\t",zggz[k].yfsalary);
	 printf("%f\t",zggz[k].grsds);
	 printf("%f\t",zggz[k].real_salary);
	 printf("\n");
	 
	 printf("\n��������������˵�\n");
	 getch();
	 return;
}

/*******************************ɾ��ָ������ְ���ļ�¼*******************************/

void del(struct work zggz[])
{
     FILE *fp;
	 int i;
	 int k;
	 int flag=0;         //�����û�и�Ա��
     char gonghao[10];   //��Ҫɾ����Ա�����

     if ((fp=fopen("gz.dat","rb+")) == NULL)
     {
         printf("\nCannot open file\n");
		 printf("\n��������������˵�\n");
		 getch();
         return;
      }

	 printf("\n");
     printf("ɾ��ǰԱ����Ϣ����:\n");
	 list(zggz);     //�����������


	 printf("\n");
     printf("Ҫɾ����ְ����:");
     scanf("%s",gonghao);
	 printf("\n");

	 for (i=0;i<n;i++)
	 {
		 if (strcmp(zggz[i].number,gonghao) == 0)
		 {
			 flag = 1;
			 break;
		 }
	 }
	 
	 if (flag)
	 {
		 printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1�����޸��밴0: ");
		 scanf("%d",&k);
		 printf("\n");

		 if (k == 1)
		 {
			 for (int j = i;j<n;j++)
			 {
				 zggz[j] = zggz[j+1];
			 }
			 n = n-1;
			 write(zggz);    //����write����
			 printf("ɾ����Ա����Ϣ����:\n");
			 list(zggz);
		 }
		 else if (k == 0)
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

/*************************��ӹ��ʼ�¼���ṹ����zggzĩβ****************************/

void add(struct work zggz[])
{
	FILE *fp;
	struct work Z;
	int i;
	int flag=0;         //�����û�и�Ա��

	if ((fp = fopen("gz.dat","rb+")) == NULL)
    {
         printf("\nCannot open file\n");
		 printf("\n��������������˵�\n");
		 getch();
         return;
     }

	 printf("\n������ְ������:");    //����ְ�����
	 scanf("%s",Z.number);

	 for (i=0;i<n;i++)
	 {
		 if (strcmp(zggz[i].number,Z.number) == 0)
		 {
			 flag = 1;
			 break;
		 }
	 }

	 if (flag)
	 {
		 printf("\n");
		 printf("�����Ѵ���\n");
	 }
	 else
	 {
		 printf("\n������ְ������:");    //����ְ������
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

		 Z.yfsalary = Z.gwsalary + Z.xjsalary + Z.zwsalary + Z.jxsalary;
		 Z.grsds = grsds(Z.yfsalary);
		 Z.real_salary = Z.yfsalary - Z.grsds;
	 
		 zggz[n] = Z;
		 n++;
		 printf("\nԱ����Ϣ�Ѿ����\n");
		 write(zggz);
	 }
	 
	 fclose(fp);
	 printf("\n��������������˵�\n");
	 getch();
     return;
}

/******************************�����������˰********************************/

float grsds(float m)
{
	float x;       //ȫ��Ӧ��˰���ö�
	float y = 0;    //ȫ��Ӧ��˰
	x = m;

	if (x<500) 
		y = y + float(x*0.05);
	else if (x<2000) 
		y = y + float(500*0.05 + (x-500)*0.1);
	else if (x<5000) 
		y = y + float(500*0.05 + 1500*0.1 + (x-2000)*0.15);
	else if (x<20000) 
		y = y + float(500*0.05 + 1500*0.1 + 3000*0.15 + (x-5000)*0.2);
	else if (x<40000) 
		y = y + float(500*0.05 + 1500*0.1 + 3000*0.15+15000*0.2 + (x-20000)*0.25);
	else if (x<60000) 
		y = y + float(500*0.05 + 1500*0.1 + 3000*0.15 + 15000*0.2 + 20000*0.25 + (x-40000)*0.3);
	else if (x<80000) 
		y = y + float(500*0.05 + 1500*0.1 + 3000*0.15 + 15000*0.2 + 20000*0.25 + 20000*0.3 + (x-60000)*0.35);
	else if (x<100000) 
		y = y + float(500*0.05 + 1500*0.1 + 3000*0.15 + 15000*0.2 + 20000*0.25 + 20000*0.3 + 20000*0.35 + (x-80000)*0.4);
	else 
		y = y + float(500*0.05 + 1500*0.1 + 3000*0.15 + 15000*0.2 + 20000*0.25 + 20000*0.3 + 20000*0.35 + 20000*0.4 + (x-100000)*0.45);

		return y;
}