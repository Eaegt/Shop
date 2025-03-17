#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

//���� ������

int userSize = 2;
bool isAdmin = false;
std::string* loginArr = new std::string[userSize]{ "Admin","user1" };
std::string* passArr = new std::string[userSize]{ "Admin","123" };

//-----------------------------------------------------------------
// �����
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
double* priceArr = new double[size];
int* countArr = new int[size];


//�������

void Start();
bool Login();
void Getline(std::string& stringName);
void CreateStorage();
void ShowAdminMenu();
void ShowStorage(int mode = 0);
void RefillProduct();

template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dynamicArr[]);

int main()
{
	Start();
	delete[] loginArr;
	delete[] passArr;
	delete[] idArr;
	delete[] nameArr;
	delete[] priceArr;
	delete[] countArr;
	return 0;
}

void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\n\n\t\t\t Black tires\n\n";
	if (Login())
	{
		if (isAdmin == true)
		{
			std::string choose;
			while (true)
			{
				std::cout << "1 - ������������ ������� �����\n2 - ������� ���� �����\n����: ";
				Getline(choose);
				if (choose == "1")
				{
					//������� ����� �����
					CreateStorage();
					ShowAdminMenu();
					break;
				}
				else if (choose == "2")
				{
					// ������������ ����� �����
					// ShowAdminMenu();
					break;
				}
				else
				{
					std::system("cls");
					std::cout << "������ �����\n\n";
				}
			}
		}
		else
		{
			//������� �����. ��������
			CreateStorage();
			// ����
		}
	}
	else
	{
		std::cerr << "Login Err\n";
	}
}

bool Login()
{
	std::string login, pass;
	while (true)
	{
		std::cout << "������� �����: ";
		Getline(login);
		std::cout << "������� ������: ";
		Getline(pass);
		if (login == loginArr[0] && pass == passArr[0])
		{
			isAdmin = true;
			std::cout << "������������" << loginArr[0] << " - ����� ����������!\n������: �����\n\n";
			return true;
		}

		for (int i = 1; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				isAdmin = false;
				std::cout << "������������" << loginArr[i] << " - ����� ����������!\n������: ��������\n\n";
				return true;
			}
		}
		std::system("cls");
		std::cout << "������������ ����� ��� ������\n\n";
		if (Login())
		{

		}
	}
}

void Getline(std::string& stringName)
{
	std::getline(std::cin, stringName, '\n');
}

void CreateStorage()
{
	const int staticSize = 10;
	int id[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[staticSize]
	{
		"Pirelli Powergy", "Yokohama bluEarth-Es",
		"Cordiant Sport 3", "Sailun ATREZZO",
		"Prelli Scorpion", "Triangle Group TR646",
		"Hankook Ventus Prime 4", "Yokohama lce Guard",
		"Nokian Tyres", "Tunga Nordway"
	};
	double price[staticSize]{ 16053.7, 31083.4, 4532.1, 9377.6, 17256.8, 28327.2, 14830.4, 12102.3, 12729.9, 8256.7 };
	int count[staticSize]{ 13,15,9,18,27,19,9,22,16,6 };
	FillArray(id, idArr);
	FillArray(name, nameArr);
	FillArray(count, countArr);
	FillArray(price, priceArr);
	ShowStorage();

}

void ShowAdminMenu()
{
	std::string choose;

	while (true)
	{
		system("cls");
		std::cout << "1) ������ �������\n";
		std::cout << "2) �������� �����\n";
		std::cout << "3) ��������� �����\n";
		std::cout << "4) �������� ������\n";
		std::cout << "5) ��������� ����\n";
		std::cout << "6) ��������� ������\n";
		std::cout << "7) ��������� ���������\n";
		std::cout << "8) ����� � �������\n";
		std::cout << "0) ������� �����\n";
		std::cout << "����: ";
		Getline(choose);
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

			break;
		}
		else
		{

		}

	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "�������� ������\t" << "����\t" << "���-��\n";
		for (int i = 0; i < size; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(25) << nameArr[i] << "\t" << priceArr[i] << "\t" << countArr[i] << "\n";
		}
		std::cout << "\n\n";
	}


	system("pause");
}

void RefillProduct()
{
	std::string choose;
	while (true)
	{
		system("cls");
		std::cout << "��������� �����?\n1) ��\n2) �����\n����: ";
		Getline(choose);
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			break;
		}
		else
		{
			std::cout << "\n\n������ �����\n\n";
			Sleep(1000);
		}
	}
}

template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dynamicArr[])
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}


