#include<stdio.h>
#include<conio.h>
using namespace std;
#define n 50;
struct work
{
	char gonghao[10];       //工号
	char name[10];      //姓名
	float gwsalary;     //岗位工资
	float xjsalary;     // 薪级工资
	float zwsalary;     //职务津贴
	float jxsalary;     //绩效工资
	float yfsalary;     //应发工资
	float tax;          //个人所得税
	float real_salary;  //实发工资
}zggz[n],newemp;

//从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。

void read()
{
	FILE *fp;
     int n=0;    //记录职工数
    if((fp=fopen("gx.dat","rb"))==NULL)      //打开一个二进制文件
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
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
		printf("\n职工工资数据读取完毕,共有%d人\n",n);
	}
	printf("\n按任意键返回主菜单\n");
	getch();
}

//将zggz结构体数组中的记录保存到gz.dat数据文件中。

void write()
{
	FILE *fp;
	int n=0;    //存入文件职工数
    if((fp=fopen("gx.dat","rb"))==NULL)      //打开一个二进制文件
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
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
	printf("\n按任意键返回主菜单\n");
	getch();
}

//根据工号查询相应职工的工资记录

void find()
{
	FILE *fp;
	char gonghao[10];
	if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return ;
    }
	cout<<"输入职工工号：";
	cin>>gonghao;
	for(int i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].gonghao,gonghao)) break;
	if(feof(fp))
    {
        printf("\t查无此人\n");
        exit(1);
    }
     cout<<"工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资"<<endl;
	 for(int i=0;i<n;i++)
     cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
       fclose(fp);
}

//显示所用职工的记录

void list()
{
     FILE *fp;
	 int i;
     if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return ;
    }
     cout<<"工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
			  <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		      <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
	 }
    fclose(fp);
}

//指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。

void modify()
{
     FILE *fp;
     int i,j;
     char gonghao[10];
     if((fp=fopen("gx.dat","rb"))==NULL)      
    {
        printf("\nCannot open file\n");
		printf("\n按任意键返回主菜单\n");
		getch();
        return ;
    }
     printf("要修改的职工号:");
     scanf("%s",gonghao);
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].number,gonghao)) break;
     if(feof(fp))
     {
          printf("\t没有%s职工号的职工\n",gonghao);
          exit(1);
     }
     cout<<"工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
			  <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
			  <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
     }
    printf("输入格式:工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资 <Enter>\n");
    printf("第%d个记录:",i+1);
    scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,newemp.sex,&newemp.age,
               &newemp.wage1,&newemp.wage2,&newemp.funds,&newemp.WATERfee,&newemp.TAXfee);//获取新的职工记录
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;
    fseek(fp,-(long)sizeof(struct work),SEEK_CUR);  //文件指针指向该修改的记录开头
     fwrite(&newemp,sizeof(struct work),1,fp);  //用newemp覆盖当前记录
     printf(" 修改后:\n");
    fseek(fp,0,SEEK_SET);        //显示修改后的文件数据
     cout<<"工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
    }
    fclose(fp);
}

//删除指定工号职工的记录

void del()

{
     FILE *fp;
     int i,j,n;
     char number[5];
     if((fp=fopen("gx.dat","rb"))==NULL)
     {
         printf("不能打开gx文件\n");
         exit(1);
      }
     printf("删除前:\n");
     printf("工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资:\n");
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*n为gz文件中记录数*/
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
    }
     printf("要删除的职工号:");
     scanf("%s",number);
     for(i=0;(strcmp(zggz[i].num,number)!=0&&i<n);i++)
     if(i>=n)
     {
          printf("\t没有%s职工号的职工\n",number);
          exit(2);
     }
     fclose(fp);
     fp=fopen("gz.dat","w+");
     if(n==1)  /*一个记录已经删除了*/
     {
           fclose(fp);
           exit(3);
     }
     for(j=0;j<i;j++)
        fwrite(&emp[j],sizeof(struct work),1,fp);
     for(j=i+1;j<n;j++)
         fwrite(&emp[j],sizeof(struct work),1,fp);
     printf("删除后:\n");
     fseek(fp,0,SEEK_SET);
      cout<<"工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资"<<endl;
     for(i=0;fread(&zggz[i],sizeof(struct work),1,fp)!=0;i++)       /*n为gz文件中记录数*/
     {
          cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
    }
       fclose(fp);
}

//添加工资记录到结构数组zggz末尾

void add()
{
      FILE *fp;
      int n,i,j;
      if((fp=fopen("gx.dat","ab+"))==NULL)
      {
          printf("不能打开gx文件\n");
           exit(0);
      }
    printf("要添加的职工人数:");
      scanf("%d",&n);
      for(i=0;i<n;i++) 
      { 
          printf("输入格式:工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资   <Enter>\n");
         printf("追加记录:\n");
         scanf("%s%s%s%d%f%f%f%f%f",newemp.no,newemp.name,newemp.sex,&newemp.age,
                   &newemp.wage1,&newemp.wage2,&newemp.funds,&newemp.WATERfee,&newemp.TAXfee);
             newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;//获取一个新的职工记录
        fwrite(&newemp,sizeof(struct work),1,fp);   //将该职工记录写入文件
      }
      fclose(fp);
}

//计算个人所得税

void grsds()
{
	float x;      //全月应纳税所得额
	float y=0;    //全月应纳税
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
	cout<<"1.查询职工工资记录"<<endl
		<<"2.修改职工工资记录"<<endl
		<<"3.添加职工工资记录"<<endl
		<<"4.删除职工工资记录"<<endl
		<<"5.保存职工工资记录"<<endl
		<<"6.浏览职工工资记录"<<endl
		<<"7.退出职工工资记录"<<endl;
	cout<<"请输入您的选择(1~7)：";
	cin>>a;
	if(a<1||a>7)
	{
		cout<<"您输入的数字不是1~7，请重新输入：";
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
			case 7: cout<<"谢谢，欢迎下次光临!";
				break;
		}
	}
	return 0;
}
