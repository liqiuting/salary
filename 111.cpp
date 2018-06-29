#include<stdio.h>
#include<stdlib.h>  //处理杂乱
#include<string.h>
#include<conio.h>
#define NUM 50
int n=0; //全局变量标记当前录入职工个数
struct work
{
	char gonghao[10];    //工号
	char name[10];      //姓名
	float gwsalary;     //岗位工资
	float xjsalary;     // 薪级工资
	float zwsalary;     //职务津贴
	float jxsalary;     //绩效工资
	float yfsalary;     //应发工资
	float grsds;        //个人所得税
	float real_salary;  //实发工资
}newemp,zggz[NUM];

/***************************************************************************

从数据文件中读取职工工资数据、初始化职工工资结构体数组
并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。

*****************************************************************************/
struct work* read()
{
	FILE *fp;    //定义文件指针
  //  int n=0;    //记录职工数
    if((fp=fopen("gx.dat","rb"))==NULL)      //打开一个二进制文件
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
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
		printf("\n职工工资数据读取完毕,共有%d人\n",n);
	}
	printf("\n按任意键返回主菜单\n");
	getch();
}

//将zggz结构体数组中的记录保存到gz.dat数据文件中。

void write(struct work zggz[])
{
	FILE *fp;    
	int i;    //存入文件职工数
    if((fp=fopen("gz.dat","rb"))==NULL)     
	{
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return;
    }

	if(n==0)
	{
		printf("没有联系人可读");
	}

	//写入数据

	for(i=0;i<n;i++)
	{
		fprintf(fp,"工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
		fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		
	}
		printf("\n职工记录保存完毕\n");
		fclose(fp);
		printf("\n按任意键返回主菜单\n");
		getch();
		return;
}

/*****根据工号查询相应职工的工资记录*****/

void find(struct work zggz[])
{
	FILE *fp;
	int i;
	char gonghao[10];  //接收工号字符数组

	if((fp=fopen("gz.dat","rb"))==NULL)      
    {
        printf("\n文件没有职工记录\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return ;
    }

	printf("输入需要查询的职工工号：\n");
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
			printf("\t查无此人\n");
			
		}
		printf("\n按任意键返回主菜单\n");
			getch();
	}
     //printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
	 
       fclose(fp);
	  // printf("\n按任意键返回主菜单\n");
	  // getch();
	   
}

//显示所用职工的记录

void list(struct work zggz[])
{
     FILE *fp;
	 int i;
     if((fp=fopen("gz.dat","rb"))==NULL)
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return ;
    }
     printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
     for(i=0;i<n;i++)
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		 
	 }
    fclose(fp);
	//printf("\n按任意键返回主菜单\n");
	//getch();
}

/*****************************************************

指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。

******************************************************/
void modify(struct work zggz[])
{
     FILE *fp;
     int i;
     char gonghao[10];
     if((fp=fopen("gz.dat","wb+"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return;
    }
     printf("要修改的职工号:");
     scanf("%s",gonghao);
	 /*while(fread(&zggz,sizeof(zggz),1,fp)==1)
	 {
		 if(strcmp(gonghao,zggz.gonghao)==0)
		 {
			 printf("\n输入新职工工号:"); //输入职工编号
			 scanf("%s",zggz[i].gonghao);
			 printf("\n输入新职工姓名:"); //输入职工姓名
			 gets(zggz[i].name);
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
			 zggz[i].yfsalary=zggz[i].gwsalary+zggz[i].xjsalary+zggz[i].zwsalary+zggz[i].jxsalary;
			 zggz[i].real_salary=zggz[i].yfsalary-zggz[i].grsds;
			 fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
				zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
				zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		 }
	 }*/
     for(i=0;i<n;i++)//如果找到了就执行下面语句 ,找不到直接回主界面
	 {
		 if(strcmp(zggz[i].gonghao,gonghao)==0)
		 {
			 printf("\n输入新职工工号:"); //输入职工编号
			 scanf("%s",zggz[i].gonghao);
			 printf("\n输入新职工姓名:"); //输入职工姓名
			 gets(zggz[i].name);
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
			 zggz[i].yfsalary=zggz[i].gwsalary+zggz[i].xjsalary+zggz[i].zwsalary+zggz[i].jxsalary;
			 zggz[i].real_salary=zggz[i].yfsalary-zggz[i].grsds;
			 fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
				zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
				zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
		 }
	 }
    fclose(fp);
	printf("\n按任意键返回主菜单\n");
	getch();
}

//删除指定工号职工的记录

void del(struct work zggz[])
{
     FILE *fp;
     int i,j,n;
     char gonghao[5];
     if((fp=fopen("gz.dat","rb"))==NULL)
     {
         printf("\nCannot open file\n");
		 printf("\n按任意键返回主菜单\n");
		 getch();
         return;
      }
     printf("删除前:\n");
     printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资:\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*n为gz文件中记录数*/
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
    }
     printf("要删除的职工号:");
     scanf("%s",gonghao);
     for(i=0;(strcmp(zggz[i].gonghao,gonghao)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\t没有%s职工号的职工\n",gonghao);
          printf("\n按任意键返回主菜单\n");
		  getch();
         return;
     }
     fclose(fp);
     fp=fopen("gz.dat","w+");
     if(n==1)  /*一个记录已经删除了*/
     {
           fclose(fp);
           printf("\n按任意键返回主菜单\n");
		 getch();
         return;
     }
     for(j=0;j<i;j++)
        fwrite(&zggz[j],sizeof(struct work),1,fp);
     for(j=i+1;j<n;j++)
         fwrite(&zggz[j],sizeof(struct work),1,fp);
     printf("删除后:\n");
     fseek(fp,0,SEEK_SET);
      printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*n为gz文件中记录数*/
     {
          printf("%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
    }
       fclose(fp);
	   printf("\n按任意键返回主菜单\n");
	getch();
}

//计算个人所得税
float grsds(float x)
{
	float y=0;    //全月应纳税
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

//添加工资记录到结构数组zggz末尾

void add(struct work zggz[])
{
      FILE *fp;
      int j;
      if((fp=fopen("gz.dat","rb+"))==NULL)
      {
          printf("\nCannot open file\n");
          printf("\n按任意键返回主菜单\n");
		 getch();
         return;
      }
       printf("要添加的职工人数:");
       scanf("%d",&j);
       for(int i=n;i<n+j;i++) 
       { 
         printf("\n输入添加职工工号:"); //输入职工编号
			 scanf("%s",zggz[i].gonghao);
			 printf("\n输入添加职工姓名:"); //输入职工姓名
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
			 zggz[i].yfsalary=zggz[i].gwsalary+zggz[i].xjsalary+zggz[i].zwsalary+zggz[i].jxsalary;
			 zggz[i].grsds=grsds(zggz[i].yfsalary);
			 zggz[i].real_salary=zggz[i].yfsalary-zggz[i].grsds;

			 fprintf(fp,"%s%s%s%d%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,  //将该职工记录写入文件
				zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
				zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);

			 printf("%s%s%s%f%f%f%f%f%f",zggz[i].gonghao,zggz[i].name,zggz[i].gwsalary,   //输入该职工信息
			 zggz[i].xjsalary,zggz[i].zwsalary,zggz[i].jxsalary,
			 zggz[i].yfsalary,zggz[i].grsds,zggz[i].real_salary);
	   }
	    n=n+j;
      fclose(fp);
	  printf("\n按任意键返回主菜单\n");
	getch();
}



int main()
{
	system("cls"); //清屏命令
	int a;
	struct work* p;//声明一个结构指针
	p=read();

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
	if(a<1||a>7)
	{
		printf("您输入的数字不是1~7，按任意键返回:");
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
			case 7: printf("欢迎使用!\n");
				break;
		}
	}
	return 0;
}
