#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <windows.h>
#include <stdio.h>



using namespace std;



int choice, num, numFlat;



class Human
{
	char* surname;
	char* name;
	char* gender;
	int age;



public:
	Human(char* humanSurname, char* humanName, int choice, int num)
	{
		setName(humanSurname, humanName);
		setGender(choice);
		setAge(num);
	};
	Human()
	{
		surname = new char[8];
		strcpy(surname, "Unknown");
		name = new char[8];
		strcpy(name, "Unnamed");
		gender = new char[10];
		strcpy(gender, "Indefined");
		age = 0;
	}



	void setName(const char* humanSurname, const char* humanName)
	{
		int lenSN = strlen(humanSurname);
		int lenN = strlen(humanName);
		if (lenN == 0)
		{
			name = new char[8];
			strcpy(name, "Unnamed");
			return;
		}
		name = new char[lenN + 1];
		for (int i = 0; i <= lenN; i++)
		{
			name[i] = humanName[i];
		}



		if (lenSN == 0)
		{
			surname = new char[8];
			strcpy(surname, "Unknown");
			return;
		}
		surname = new char[lenSN + 1];
		for (int i = 0; i <= lenSN; i++)
		{
			surname[i] = humanSurname[i];
		}
	}
	void setGender(int choice)
	{
		const char* gen;
		if (choice == 1)
		{
			gen = { "Male" };
		}
		else if (choice == 2)
		{
			gen = { "Female" };
		}
		else
		{
			gen = { "Indefined" };
		}
		int len = strlen(gen);
		gender = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			gender[i] = gen[i];
		}
	}
	void setAge(int num)
	{
		if (num >= 0 && num <= 100)
		{
			age = num;
		}
		else
		{
			age = 0;
		}
	}



	char* getSurname() const
	{
		return surname;
	}
	char* getName() const
	{
		return name;
	}
	const char* getGender() const
	{
		return gender;
	}
	int getAge() const
	{
		return age;
	}



	void printHuman() const
	{
		cout << "\nФамилия и имя жильца:\t" << surname << " " << name << endl;
		cout << "Пол жильца:\t" << gender << endl;
		cout << "Возраст жильца:\t" << age << endl;
	}



	~Human()
	{
		cout << "Human destructor work\n";
	}
};



//-------------------------------------------------------------------------------



class Flat
{
public:
	int numCitizen;// Количество жителей в квартире
	Human* numHumanInFlat{ nullptr };



	Flat()
	{
		setNumSitiz();
	}



	Flat(int numCitizen)
	{
		numHumanInFlat = new Human[numCitizen];
		setHumansInFlat();
	}



	void setNumSitiz()
	{
		int numCitiz;
		cout << "Введите количество жильцов в квартире (от 1 до 5): ";
		cin >> numCitiz;
		if (numCitiz >= 0 && numCitiz <= 5)// Условное ограничение
		{
			numCitizen = numCitiz;
		}
		else
		{
			numCitizen = 0;
		}
		numHumanInFlat = new Human[numCitiz];
	}
	void setHumansInFlat()
	{
		for (int i = 0; i < numCitizen; i++)
		{
			char name[24];
			char surname[24];
			cout << "\nВведите фамилию и имя жильца: ";
			cin >> surname >> name;
			cout << "Введите пол жильца: 1 - мужской, 2 - женский. ";
			cin >> choice;
			cout << "Введите возраст жильца: ";
			cin >> num;
			numHumanInFlat[i] = Human(surname, name, choice, num);
		}
	}



	int getNumSitiz() const
	{
		return numCitizen;
	}
	void printFlat() const
	{
		cout << "\nКоличество жильцов в квартире:\t" << numCitizen << endl;
		if (numCitizen > 0)
		{
			for (int i = 0; i < numCitizen; i++)
			{
				numHumanInFlat[i].printHuman();
			}
		}
	}
	~Flat()
	{
		cout << "Flat destructor work\n";
		if (numHumanInFlat != nullptr)
		{
			delete[]numHumanInFlat;
		}
	}
};



//-------------------------------------------------------------------------------



class House
{
	static const int sizeHouse = 6;// количество квартир в доме
	Flat allFlat[sizeHouse];
public:
	House()
	{
		cout << "Constructor default work\n";
	}



	void setFlat(int num)
	{
		if (num >= 1 && num <= sizeHouse)
		{
			allFlat[num - 1].setNumSitiz();
			allFlat[num - 1].setHumansInFlat();
		}
	}



	void printNumFlat(int numFlat) const
	{
		cout << "\n\tКвартира номер " << numFlat << ": ";
		allFlat[numFlat - 1].printFlat();
	}



	void printHouse() const
	{
		for (int i = 0; i < sizeHouse; i++)
		{
			cout << "\n\tКвартира номер " << i + 1 << ": ";
			allFlat[i].printFlat();
		}
		cout << endl;
	}
	~House()
	{
		cout << "House destructor work\n";
	}
};



//-------------------------------------------------------------------------------



int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int numFlat;



	House house;
	house.printHouse();
	cout << endl;
	cout << "Enter number of flat: ";
	cin >> numFlat;
	house.setFlat(numFlat);
	house.printHouse();
	return 0;
}