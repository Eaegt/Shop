#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

//база данных

int userSize = 2;
bool isAdmin = false;
std::string* loginArr = new std::string[userSize]{ "Admin","user1" };
std::string* passArr = new std::string[userSize]{ "Admin","123" };

//-----------------------------------------------------------------
// Склад
int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
double* priceArr = new double[size];
int* countArr = new int[size];


//Функции

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
				std::cout << "1 - Использовать готовый склад\n2 - Создать свой склад\nВвод: ";
				Getline(choose);
				if (choose == "1")
				{
					//готовый склад админ
					CreateStorage();
					ShowAdminMenu();
					break;
				}
				else if (choose == "2")
				{
					// динамический склад админ
					// ShowAdminMenu();
					break;
				}
				else
				{
					std::system("cls");
					std::cout << "Ошибка ввода\n\n";
				}
			}
		}
		else
		{
			//готовый склад. Продавец
			CreateStorage();
			// меню
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
		std::cout << "Введите логин: ";
		Getline(login);
		std::cout << "Введите пароль: ";
		Getline(pass);
		if (login == loginArr[0] && pass == passArr[0])
		{
			isAdmin = true;
			std::cout << "Пользователь" << loginArr[0] << " - Добро пожаловать!\nСтатус: Админ\n\n";
			return true;
		}

		for (int i = 1; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				isAdmin = false;
				std::cout << "Пользователь" << loginArr[i] << " - Добро пожаловать!\nСтатус: Продавец\n\n";
				return true;
			}
		}
		std::system("cls");
		std::cout << "Неправильный логин или пароль\n\n";
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
		std::cout << "1) Начать продажу\n";
		std::cout << "2) Показать склад\n";
		std::cout << "3) Пополнить склад\n";
		std::cout << "4) Списание товара\n";
		std::cout << "5) Изменение цены\n";
		std::cout << "6) Изменение склада\n";
		std::cout << "7) Изменение персонала\n";
		std::cout << "8) Отчёт о прибыли\n";
		std::cout << "0) Закрыть смену\n";
		std::cout << "Ввод: ";
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
		std::cout << "ID\t" << std::left << std::setw(25) << "Название товара\t" << "Цена\t" << "Кол-во\n";
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
		std::cout << "Пополнить товар?\n1) Да\n2) Выход\nВвод: ";
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
			std::cout << "\n\nОшибка ввода\n\n";
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


