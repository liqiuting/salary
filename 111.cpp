#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define TURE 1
int n = 0;   //全局变量标记当前录入职工个数

/*函数声明*/
void read(struct work zggz[]);
void write(struct work zggz[]);
void find(struct work zggz[]);
void list(struct work zggz[]);
void modify(struct work zggz[]);
void del(struct work zggz[]);
void add(struct work zggz[]);
float grsds(float m);

struct work   /*声明职工工资结构体数组*/
{
	char number[10];    //工号
	char name[10];      //姓名
	float gwsalary;     //岗位工资
	float xjsalary;     //薪级工资
	float zwsalary;     //职务津贴
	float jxsalary;     //绩效工资
	float yfsalary;     //应发工资
	float grsds;        //个人所得税
	float real_salary;  //实发工资
};

void main()
{
	int a;
	struct work zg[100];
	read(zg);

	while (TURE)
	{
		system("cls");    //清屏命令

		printf("\n");
		printf("        ###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n");
		printf("\n");
		printf("        请选择(1-7):                                                    \n");
		printf("        ================================================================\n");
		printf("        |            1. 查询职工工资记录                               |\n");
		printf("        |            2. 修改职工工资记录                               |\n");
		printf("        |            3. 添加职工工资记录                               |\n");
		printf("        |            4. 删除职工工资记录                               |\n");
		printf("        |            5. 保存职工工资记录                               |\n");
		printf("        |            6. 浏览职工工资记录                               |\n");
		printf("        |            7. 退出职工工资记录                               |\n");
		printf("        ================================================================\n");
		printf("\n");

		printf("        你的选择是:");
		scanf("%d",&a);

		if (a<1||a>7)
		{
			printf("您输入的数字不是1~7，按任意键返回重新选择");
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
				case 7: printf("\n\t欢迎使用!\n");
					return;
					break;
			}

		}

	}

	system("pause");
	return;

}


/***************************************************************************

   从数据文件中读取职工工资数据、初始化职工工资结构体数组
   并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。

****************************************************************************/

void read(struct work zggz[])
{
	FILE *fp;    //定义文件指针
	struct work z;

    if ((fp = fopen("gz.dat","rb")) == NULL)      //打开一个二进制文件
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
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
		printf("\n\t职工工资数据读取完毕,共有%d人\n",n);
		printf("\n\t5秒后继续");
		Sleep(5000);//延时5秒
}

/**************将zggz结构体数组中的记录保存到gz.dat数据文件中。**************/

void write(struct work zggz[])
{
	FILE *fp;    
	int i;    

    if ((fp = fopen("gz.dat","wb")) == NULL)     
	{
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return;
    }

	if(n == 0)
	{
		printf("\t没有联系人可读");
	}

	//写入数据

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
		printf("\t\t\n共写入%d个人的数据\n",n);	
		printf("\n");
		getch();
		return;
}

/***********************根据工号查询相应职工的工资记录*************************/

void find(struct work zggz[])
{
	int i;               //记录员工位置
	int j;               //记录员工位置
	int flag = 0;       //记录员工有没有存在
	char gonghao[10];  //接收工号字符数组

	printf("\n");
	printf("输入需要查询的职工工号：");
	scanf("%s",gonghao);
	printf("\n");

    //遍历结构体数组，查找有无该工号的员工，若有flag=1,反之flag=0
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
			printf("工号\t\t%s\n",zggz[i].number);
			printf("姓名\t\t%s\n",zggz[i].name);
			printf("岗位工资 \t%f\n",zggz[i].gwsalary);
			printf("薪级工资 \t%f\n",zggz[i].xjsalary);
			printf("职务津贴 \t%f\n",zggz[i].zwsalary);
			printf("绩效工资 \t%f\n",zggz[i].jxsalary);
			printf("应发工资 \t%f\n",zggz[i].yfsalary);
			printf("个人所得税\t%f\n",zggz[i].grsds);
			printf("实发工资 \t%f\n",zggz[i].real_salary);

			for(j = i + 1;j < n;j++)
			{
				if (strcmp(zggz[j].number,gonghao) == 0)
				{
					printf("\n");
					printf("工号\t\t%s\n",zggz[j].number);
					printf("姓名\t\t%s\n",zggz[j].name);
					printf("岗位工资 \t%f\n",zggz[j].gwsalary);
					printf("薪级工资 \t%f\n",zggz[j].xjsalary);
					printf("职务津贴 \t%f\n",zggz[j].zwsalary);
					printf("绩效工资 \t%f\n",zggz[j].jxsalary);
					printf("应发工资 \t%f\n",zggz[j].yfsalary);
					printf("个人所得税\t%f\n",zggz[j].grsds);
					printf("实发工资 \t%f\n",zggz[j].real_salary);
				}
			}
			
		}

		else
		{
			printf("\t查无此人\n");
		}

	   printf("\n");
	   printf("\n按任意键返回主菜单\n");
	   getch();
	   return;
}

/*******************************显示所用职工的记录********************************/

void list(struct work zggz[])
{
	printf("\n");
    printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
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
	printf("\n按任意键继续\n");
	getch();
	return;

}

/****************************************************************************

    指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。

*****************************************************************************/

void modify(struct work zggz[])
{
     int i;
	 int k;   //标记是否修改员工
     char gonghao[10];

	 printf("\n");
     printf("要修改的职工号:");
     scanf("%s",gonghao);
	 printf("\n");

     for (i = 0;i<n;i++)   //如果找到了就执行下面语句 ,找不到直接回主界面
	 {
		 if (strcmp(zggz[i].number,gonghao) == 0)
		 {
			 printf("\n该员工原本信息为:\n");
			 printf("\n");
			 printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
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

			 printf("\n输入新职工工号:"); //输入职工编号
			 scanf("%s",zggz[i].number);
			 printf("\n输入新职工姓名:"); //输入职工姓名
			 scanf("%s",zggz[i].name);
			 printf("输入职工的工资信息\n");
			 printf("------------------------------\n");
			 printf("\n岗位工资: ");
			 scanf("%f",&zggz[i].gwsalary);
			 printf("\n薪级工资: ");
			 scanf("%f",&zggz[i].xjsalary);
			 printf("\n职务津贴: ");
			 scanf("%f",&zggz[i].zwsalary);
			 printf("\n绩效工资: ");
			 scanf("%f",&zggz[i].jxsalary);

			 zggz[i].yfsalary = zggz[i].gwsalary + zggz[i].xjsalary + zggz[i].zwsalary + zggz[i].jxsalary;
			 zggz[i].grsds = grsds(zggz[i].yfsalary);
			 zggz[i].real_salary = zggz[i].yfsalary - zggz[i].grsds;
			
			 k=i;			
		 }
	 }

	 printf("\n修改后的信息:\n");
	 printf("\n");
	 printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
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
	 
	 printf("\n按任意键返回主菜单\n");
	 getch();
	 return;
}

/*******************************删除指定工号职工的记录*******************************/

void del(struct work zggz[])
{
     FILE *fp;
	 int i;
	 int k;
	 int flag=0;         //标记有没有该员工
     char gonghao[10];   //需要删除的员工编号

     if ((fp=fopen("gz.dat","rb+")) == NULL)
     {
         printf("\nCannot open file\n");
		 printf("\n按任意键返回主菜单\n");
		 getch();
         return;
      }

	 printf("\n");
     printf("删除前员工信息如下:\n");
	 list(zggz);     //调用浏览函数


	 printf("\n");
     printf("要删除的职工号:");
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
		 printf("\n确实要修改此人信息请按1；不修改请按0: ");
		 scanf("%d",&k);
		 printf("\n");

		 if (k == 1)
		 {
			 for (int j = i;j<n;j++)
			 {
				 zggz[j] = zggz[j+1];
			 }
			 n = n-1;
			 write(zggz);    //调用write函数
			 printf("删除后员工信息如下:\n");
			 list(zggz);
		 }
		 else if (k == 0)
		 {
			 printf("\n按任意键返回主菜单\n");
			 getch();
		 }
	
	 }
	 else
	 {
		 printf("\t没有%s职工号的职工\n",gonghao);
	 }

     fclose(fp);

}

/*************************添加工资记录到结构数组zggz末尾****************************/

void add(struct work zggz[])
{
	FILE *fp;
	struct work Z;
	int i;
	int flag=0;         //标记有没有该员工

	if ((fp = fopen("gz.dat","rb+")) == NULL)
    {
         printf("\nCannot open file\n");
		 printf("\n按任意键返回主菜单\n");
		 getch();
         return;
     }

	 printf("\n输入新职工工号:");    //输入职工编号
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
		 printf("此人已存在\n");
	 }
	 else
	 {
		 printf("\n输入新职工姓名:");    //输入职工姓名
		 scanf("%s",Z.name);
		 printf("输入职工的工资信息\n");
		 printf("------------------------------\n");
		 printf("\n岗位工资: ");
		 scanf("%f",&Z.gwsalary);
		 printf("\n薪级工资: ");
		 scanf("%f",&Z.xjsalary);
		 printf("\n职务津贴: ");
		 scanf("%f",&Z.zwsalary);
		 printf("\n绩效工资: ");
		 scanf("%f",&Z.jxsalary);

		 Z.yfsalary = Z.gwsalary + Z.xjsalary + Z.zwsalary + Z.jxsalary;
		 Z.grsds = grsds(Z.yfsalary);
		 Z.real_salary = Z.yfsalary - Z.grsds;
	 
		 zggz[n] = Z;
		 n++;
		 printf("\n员工信息已经添加\n");
		 write(zggz);
	 }
	 
	 fclose(fp);
	 printf("\n按任意键返回主菜单\n");
	 getch();
     return;
}

/******************************计算个人所得税********************************/

float grsds(float m)
{
	float x;       //全月应纳税所得额
	float y = 0;    //全月应纳税
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