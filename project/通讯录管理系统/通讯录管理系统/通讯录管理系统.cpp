#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
struct Person
{
	string m_Name;
	string m_Sex;
	int m_Age;
	long long m_Phone;
	string m_Add;
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu()
{
	cout << "***********************" << endl;
	cout << "**** 1、添加联系人 ****" << endl;
	cout << "**** 2、显示联系人 ****" << endl;
	cout << "**** 3、删除联系人 ****" << endl;
	cout << "**** 4、查找联系人 ****" << endl;
	cout << "**** 5、修改联系人 ****" << endl;
	cout << "**** 6、清空联系人 ****" << endl;
	cout << "**** 0、退出通讯录 ****" << endl;
}

void AddPerson(struct Addressbooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录添加联系人已满" << endl;
		return;
	}
	else
	{
		//联系人姓名
		string name;
		cout << "请输入联系人姓名:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//联系人年龄
		cout << "请输入联系人年龄：" << endl;
		int age = 0;
		while (true)
		{
			
			cin >> age;
			if (age > 0 && age < 200)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			while (getchar() != '\n');//如果输入的数据不是整型数据的话，就要将缓存区中的内容清除
			cout << "此年龄不符合实际，请重新输入" << endl;
		}

		//联系人年性别
		cout << "请输入联系人性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1  || sex == 2)
			{
				if (sex == 1)
					abs->personArray[abs->m_Size].m_Sex = "男";
				else
					abs->personArray[abs->m_Size].m_Sex = "女";
				break;
			}
			while (getchar() != '\n');
			cout << "性别输入有误，请重新输入" << endl;
		}

		//联系人手机号码
		cout << "请输入联系人手机号：" << endl;
		long long num = 0;
		while (true)
		{
			cin >> num;
			if (num > 0)
			{
				abs->personArray[abs->m_Size].m_Phone = num;
				break;
			}
			while (getchar() != '\n');
			cout << "号码输入有误，请重新输入" << endl;
		}

		//联系人住址
		cout << "请输入联系人住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Add = address;

		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
		return;
	}
	for (int i = 0; i < abs->m_Size; i++)
	{
		cout << "姓名：" << abs->personArray[i].m_Name << "\t";
		cout << "性别：" << abs->personArray[i].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[i].m_Age << "\t";
		cout << "手机号：" << abs->personArray[i].m_Phone << "\t";
		cout << "住址：" << abs->personArray[i].m_Add << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人在通讯录中的位置
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks * abs)
{
	cout << "请输入想要删除的联系人：" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入想要查找的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "手机号：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Add << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入想要修改的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//联系人姓名
		string name;
		cout << "请输入联系人姓名:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//联系人年龄
		cout << "请输入联系人年龄：" << endl;
		int age = 0;
		while (true)
		{

			cin >> age;
			if (age > 0 && age < 200)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			while (getchar() != '\n');//如果输入的数据不是整型数据的话，就要将缓存区中的内容清除
			cout << "此年龄不符合实际，请重新输入" << endl;
		}

		//联系人年性别
		cout << "请输入联系人性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex == 1 ? "男" : "女";
				/*if (sex == 1)
					abs->personArray[ret].m_Sex = "男";
				else
					abs->personArray[ret].m_Sex = "女";*/
				break;
			}
			while (getchar() != '\n');
			cout << "性别输入有误，请重新输入" << endl;
		}

		//联系人手机号码
		cout << "请输入联系人手机号：" << endl;
		long long num = 0;
		while (true)
		{
			cin >> num;
			if (num > 0)
			{
				abs->personArray[ret].m_Phone = num;
				break;
			}
			while (getchar() != '\n');
			cout << "号码输入有误，请重新输入" << endl;
		}

		//联系人住址
		cout << "请输入联系人住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Add = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");

}

//清空通讯录
void empty(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "成功清空" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//初始化通讯录
	struct Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		//系统菜单
		showMenu();
		//选择系统功能
		cout << "请选择功能：";
		cin >> select;

		switch (select)
		{
		case 1:
			AddPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			empty(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default :
			cout << "序号输入有误，请重新输入（只能选择0-6）" << endl;
		}
	}
	
	
}