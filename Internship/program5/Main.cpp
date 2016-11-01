#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <iostream>
using namespace std;
struct Info
{
	long num;
	char name[20];
	char sex[3];
	char phone[20];
};
Info info[200];
int n;
void showMenu();
void addInfo();
int seekInfo(long nu);
void editInfo();
void delInfo();
void showInfo();
void saveInfo();
bool hasInfo();
void wait();
//void readFromBin();
void main()
{
	int choice;
	while(1)
	{
		system("cls");
        showMenu();
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:addInfo();break;
		case 2:editInfo();break;
		case 3:delInfo();break;
		case 4:showInfo();break;
		case 5:saveInfo();break;
		case 6:
			system("cls");
			printf("    员工信息管理系统->版权信息\n");
			printf("+--------------------------------------------+\n");
			printf("|2016 CopyRight By Anapopo All Right Reserved|\n");
			printf("+--------------------------------------------+\n");
			wait();
			break;
		}
		if(choice==0)
			break;
	}
}
void showMenu()
{
	printf("    员工信息管理系统\n");
	printf("-------------------------\n");
	printf("    1- 增加员工信息\n");
	printf("    2- 修改员工信息\n");
	printf("    3- 删除员工信息\n");
	printf("    4- 显示员工信息\n");
	printf("    5- 保存员工信息\n");
	printf("    6- 系统版权信息\n");
	printf("    0- 退出\n");
	printf("-------------------------\n");
	printf("[Info]请选择<0-6>:");
}
void addInfo()
{
	long number;
	int s;
	system("cls");
	printf("    员工信息管理系统->添加员工信息\n");
	printf("--------------------------------------\n");
	cout<<"[1/4]请输入编号:";
	scanf("%ld",&number);
	if(seekInfo(number) != -1)
	{
		cout<<"[Error]该编号已存在!";
		wait();
		return;
	}
	info[n].num=number;
	cout<<"[2/4]请输入姓名:";
	scanf("%s",info[n].name);
	cout<<"-------------------------"<<endl;
	cout<<"    1- 男"<<endl;
	cout<<"    2- 女"<<endl;
	cout<<"[3/4]请输入性别<1-2>:";
	scanf("%d",&s);
	strcpy(info[n].sex, (s==1?"男":"女"));
	cout<<"-------------------------"<<endl;
	cout<<"[4/4]请输入电话:";
	scanf("%s",info[n].phone);
    n++;
	printf("\n");
	printf("[Success]添加员工信息成功！\n");
	cout<<"[Info]当前员工总数["<<n<<"]个"<<endl;
	wait();
}
int seekInfo(long nu)
{
	for(int i=0;i<n;i++)
	{
		if(info[i].num==nu)
			return i;
	}
	return -1;
}
void editInfo()
{	
	long number;
	system("cls");
	printf("    员工信息管理系统->编辑员工信息\n");
	printf("--------------------------------------\n");
	cout<<"[Info]请输入编号:";
	cin>>number;
	int find = seekInfo(number);
	if(find == -1)
	{
		cout<<"[Error]此编号不存在!"<<endl;
		wait();
		return;
	}
	while(1){
		system("cls");
		int choose;
		cout<<"    原有信息"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"Num: "<<info[find].num<<endl;
		cout<<"Name: "<<info[find].name<<endl;
		cout<<"Sex: "<<info[find].sex<<endl;
		cout<<"Phone: "<<info[find].phone<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"    1- Name"<<endl;
		cout<<"    2- Sex"<<endl;
		cout<<"    3- Phone"<<endl;
		cout<<"    0- Exit"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"[Info]请选择要修改的项目<0-3>:";
		cin>>choose;
		switch(choose){
			case 1:
				cout<<"[Info]请输入新姓名:";
				cin>>info[find].name;
				cout<<"[Success]姓名修改成功！";
				break;
			case 2:
				int sex;
				cout<<"-------------------------"<<endl;
				cout<<"    1- 男"<<endl;
				cout<<"    2- 女"<<endl;
				cout<<"[Info]请输入新性别<1-2>:";
				cin>>sex;
				strcpy(info[find].sex, (sex == 1 ? "男" : "女"));
				cout<<"[Success]性别修改成功！";
				break;
			case 3:
				cout<<"[Info]请输入新电话:";
				cin>>info[find].phone;
				cout<<"[Success]电话修改成功！";
				break;

		}
		if(choose == 0) break;
	}
	cout<<"[Info]按任意键返回上级菜单…"<<endl;
	getchar();getchar();
	return;
}
//HERE IT IS
void delInfo()
{
	long number;
	int choose;
	system("cls");
	printf("    员工信息管理系统->删除员工信息\n");
	printf("--------------------------------------\n");
	cout<<"[Info]请输入编号:";
	cin>>number;
	int find = seekInfo(number);
	if(find == -1)
	{
		cout<<"[Error]该编号不存在!"<<endl;
		wait();
		return;
	}
	system("cls");
	cout<<"    原有信息"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"Num: "<<info[find].num<<endl;
	cout<<"Name: "<<info[find].name<<endl;
	cout<<"Sex: "<<info[find].sex<<endl;
	cout<<"Phone: "<<info[find].phone<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"    1- 删除"<<endl;
	cout<<"    2- 放弃"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"[Info]请选择<1-2>:"<<endl;
	cin>>choose;
	switch(choose){
		case 1:
			for(int i=find;i<n;i++) info[i] = info[i+1];
			n--;
			cout<<"[Success]员工信息删除成功！"<<endl;
			break;
		case 2:break;
	}
	wait();
	return;
}

void showInfo()
{	
	int choose;
	system("cls");
	printf("    员工信息管理系统->显示员工信息\n");
	printf("--------------------------------------\n");
	cout<<"    1- 按编号由小到大"<<endl;
	cout<<"    2- 按编号由大到小"<<endl;
	cout<<"[Info]请选择排序方式<1-2>:";
	cin>>choose;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(choose == 1 ? info[j].num > info[j+1].num : info[j].num < info[j+1].num)
			{	
				Info tmp = info[j];
				info[j] = info[j+1];
				info[j+1] = tmp;
			}
		}
	}
	
	
	system("cls");
	cout<<"       员工信息一览表"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"| 编号 | 姓名 | 性别 | 电话    |"<<endl;
	cout<<"+------------------------------+"<<endl;
	for(int i=0;i<n;i++)
		printf("  %ld | %s | %s | %s\n",info[i].num,info[i].name,info[i].sex,info[i].phone);
	cout<<"+------------------------------+"<<endl;
	if(n == 0) printf("[Error]未检测到任何员工信息.\n");
	wait();
}
void saveInfo()
{	
	int choose;
	FILE *file;
	system("cls");
	printf("    员工信息管理系统->保存员工信息\n");
	printf("-----------------------------------\n");
	cout<<"    1- 文本"<<endl;
	cout<<"    2- 二进制"<<endl;
	cout<<"[Info]请选择文件保存形式:";
	cin>>choose;
	switch(choose){
		case 1:
			file = fopen("C:/Users/user/Desktop/workers.txt", "a");
			if(file != NULL && hasInfo()){
				for(int i=0;i<n;i++)
					fprintf(file, "{\n    Num:%ld\n    Name:%s\n    Sex:%s\n    Phone:%s\n}\n", info[i].num, info[i].name, info[i].sex, info[i].phone);
			}
			cout<<"[Success]文件已保存至C:/Users/user/Desktop/workers.txt"<<endl;
			fclose(file);
			break;

		case 2:
			//cout<<"sizeof(Info):"<<sizeof(Info)<<endl;
			file = fopen("C:/Users/user/Desktop/workers.bin", "w");
			fwrite(info, sizeof(Info), n, file);
			cout<<"[Success]文件已保存至C:/Users/user/Desktop/workers.bin"<<endl;
			fclose(file);
			break;
	}
	
	wait();
}
/*
void readFromBin()
{	
	int num;
	FILE *file;
	//char *path = "C:/Users/user/Desktop/workers.bin";
	//cout<<"请输入二进制文件路径："<<endl;
	//cin>>path;
	file = fopen("C:/Users/user/Desktop/workers.txt", "r");
	
	fseek(file, 0, SEEK_SET);
	fseek(file, 0, SEEK_END);
	long bytes = ftell(file);
	cout<<"sizeof(file):"<<bytes<<endl;
	if(file != NULL){
		fread(info, sizeof(Info), bytes/sizeof(Info), file);
		n = bytes/sizeof(Info);
		cout<<"成功？";
	}
	for(int i=0;i<n;i++){
		printf("{\n    Num:%ld\n    Name:%s\n    Sex:%s\n    Phone:%s\n}\n", info[i].num, info[i].name, info[i].sex, info[i].phone);
	}
	cout<<"n:"<<n<<endl;
	wait();
}
*/
bool hasInfo()
{
	return n!=0 ? true : false;
}

void wait()
{
	cout<<"[Info]按任意键返回主菜单…"<<endl;
	getchar();getchar();
}