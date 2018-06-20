#include<stdio.h>
#include<conio.h>
#define n
struct work
{
	char num[10];  //工号
	char name[10];  //姓名
	float gwsalary;  //岗位工资
	float xjsalary;  // 薪级工资
	float zwsalary;  //职务津贴
	float jxsalary;  //绩效工资
	float yfsalary;  //应发工资
	float tax;  //个人所得税
	float real_salary;  //实发工资
};

//从数据文件中读取职工工资数据、初始化职工工资结构体数组并统计当前数据文件中职工人数，并将职工人数存在全局变量n中，以备其他函数使用。

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

//将zggz结构体数组中的记录保存到gz.dat数据文件中。

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

//根据工号查询相应职工的工资记录

void find()
{
	FILE *fp;
	char gonghao[10]; 
	cout<<"输入职工工号：";
	cin>>gonghao;
	for(i=0;fread(&zggz[i],sizeof(struct work),1,fp);i++)
		if(!strcmp(zggz[i].num,gonghao)) break;
	if(feof(fp))
    {
        printf("\t查无此人\n");
        exit(2);
    }
     cout<<"工号   姓名   岗位工资   薪级工资   职务津贴   绩效工资   应发工资   个人所得税   实发工资"<<endl;
     cout<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gwsalary<<" "
		 <<zggz[i].xjsalary<<" "<<zggz[i].zwsalary<<" "<<zggz[i].jxsalary<<" "
		 <<zggz[i].yfsalary<<" "<<zggz[i].tax<<" "<<zggz[i].real_salary<<" "<<endl;
       fclose(fp);
}

//显示所用职工的记录

void list()
{
     int i;
     FILE *fp;
     if((fp=fopen("gx.dat","r"))==NULL)
     {     
         printf("不能打开gx文件\n");
         exit(0);
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

}

//指定工号，修改该职工的工资记录，其中要调用grsds()函数计算个人所得税。

void grsds()
{
	
}
int main()
{
	int a;
	struct zggz*p;
	p=read();
	cout<<"1.查询"<<endl
		<<"2.修改"<<endl
		<<"3.添加"<<endl
		<<"4.删除"<<endl
		<<"5.保存"<<endl
		<<"6.浏览"<<endl
		<<"7.退出"<<endl;
	cout<<"请输入您的选择(1~7)：";
	cin>>a;
	if(a<1||a>7)
	{
		cout<<"您输入的数字不是1~7，请重新输入：";
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
				cout<<"谢谢，欢迎下次光临!";
				break;
		}
	}
	return 0;
}
