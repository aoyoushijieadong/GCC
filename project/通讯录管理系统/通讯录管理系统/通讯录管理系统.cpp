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
	cout << "**** 1�������ϵ�� ****" << endl;
	cout << "**** 2����ʾ��ϵ�� ****" << endl;
	cout << "**** 3��ɾ����ϵ�� ****" << endl;
	cout << "**** 4��������ϵ�� ****" << endl;
	cout << "**** 5���޸���ϵ�� ****" << endl;
	cout << "**** 6�������ϵ�� ****" << endl;
	cout << "**** 0���˳�ͨѶ¼ ****" << endl;
}

void AddPerson(struct Addressbooks * abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�����ϵ������" << endl;
		return;
	}
	else
	{
		//��ϵ������
		string name;
		cout << "��������ϵ������:" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//��ϵ������
		cout << "��������ϵ�����䣺" << endl;
		int age = 0;
		while (true)
		{
			
			cin >> age;
			if (age > 0 && age < 200)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			while (getchar() != '\n');//�����������ݲ����������ݵĻ�����Ҫ���������е��������
			cout << "�����䲻����ʵ�ʣ�����������" << endl;
		}

		//��ϵ�����Ա�
		cout << "��������ϵ���Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1  || sex == 2)
			{
				if (sex == 1)
					abs->personArray[abs->m_Size].m_Sex = "��";
				else
					abs->personArray[abs->m_Size].m_Sex = "Ů";
				break;
			}
			while (getchar() != '\n');
			cout << "�Ա�������������������" << endl;
		}

		//��ϵ���ֻ�����
		cout << "��������ϵ���ֻ��ţ�" << endl;
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
			cout << "����������������������" << endl;
		}

		//��ϵ��סַ
		cout << "��������ϵ��סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Add = address;

		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
		return;
	}
	for (int i = 0; i < abs->m_Size; i++)
	{
		cout << "������" << abs->personArray[i].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[i].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[i].m_Age << "\t";
		cout << "�ֻ��ţ�" << abs->personArray[i].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[i].m_Add << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ����ͨѶ¼�е�λ��
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
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�ֻ��ţ�" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Add << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//��ϵ������
		string name;
		cout << "��������ϵ������:" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//��ϵ������
		cout << "��������ϵ�����䣺" << endl;
		int age = 0;
		while (true)
		{

			cin >> age;
			if (age > 0 && age < 200)
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			while (getchar() != '\n');//�����������ݲ����������ݵĻ�����Ҫ���������е��������
			cout << "�����䲻����ʵ�ʣ�����������" << endl;
		}

		//��ϵ�����Ա�
		cout << "��������ϵ���Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex == 1 ? "��" : "Ů";
				/*if (sex == 1)
					abs->personArray[ret].m_Sex = "��";
				else
					abs->personArray[ret].m_Sex = "Ů";*/
				break;
			}
			while (getchar() != '\n');
			cout << "�Ա�������������������" << endl;
		}

		//��ϵ���ֻ�����
		cout << "��������ϵ���ֻ��ţ�" << endl;
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
			cout << "����������������������" << endl;
		}

		//��ϵ��סַ
		cout << "��������ϵ��סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Add = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");

}

//���ͨѶ¼
void empty(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "�ɹ����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	//��ʼ��ͨѶ¼
	struct Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		//ϵͳ�˵�
		showMenu();
		//ѡ��ϵͳ����
		cout << "��ѡ���ܣ�";
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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default :
			cout << "��������������������루ֻ��ѡ��0-6��" << endl;
		}
	}
	
	
}