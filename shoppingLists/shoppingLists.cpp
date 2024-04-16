#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>
#include <chrono>
void palindromeCheck(std::string test);

class PersonalDevice
{
protected:
	std::string deviceNameModel;
	float devicePrice;
public:
	PersonalDevice()
	{

	}

	PersonalDevice(std::string devnm, float devPrice)
	{
		deviceNameModel = devnm;
		devicePrice = devPrice;
	}
	void GetPersonalDeviceInfo()
	{
		std::cout << "Device name and model: " << deviceNameModel << '\n'
				  << "Price as of new: " << devicePrice << std::endl;
	}
	std::string getDeviceName()
	{
		return this->deviceNameModel;
	}
	std::string reversePDName(std::string deviceNameModel)
	{
		std::string result;
		for (int i = deviceNameModel.length()-1; i >= 0; i--)
		{
			result += deviceNameModel[i];
		}
		return result;
	}
};
class MainWorkDevice : PersonalDevice
{
protected:
	std::string name;
	int cores;
	int threads;
	float minFreq;
	float maxFreq;
	int ramCap;
public:
	MainWorkDevice()
	{

	}

	MainWorkDevice(std::string nume, int nuclee, int threaduri, float minF, float maxF, int ram)
	{
		name = nume;
		cores = nuclee;
		threads = threaduri;
		minFreq = minF;
		maxFreq = maxF;
		ramCap = ram;

	}
	std::string getMachineName()
	{
		return this->name;
	}
	void isHigherEndOrNot()
	{
		if (cores >= 8 && ramCap >= 16)
		{
			std::cout << "This machine '" << name << "' is a higher end model." << std::endl;
		}
		else
		{
			std::cout << "This machine '" << name << "' is a lower end model." << std::endl;
		}
	}
};
class Being
{
protected:
	std::string type;	//human// animal
	std::string name;
	int limbs;
	int age;
	std::string favorite_food;
public:
	Being()
	{

	}

	Being(std::string tip, std::string nume, int membre, int varsta, std::string favFood)
	{
		type = tip;
		name = nume;
		limbs = membre;
		age = varsta;
		favorite_food = favFood;
	}

	void printInfo()
	{
		std::cout << "Type: " << type << '\n'
			<< "Name: " << name << '\n'
			<< "Limbs: " << limbs << '\n'
			<< "Age: " << age << '\n'
			<< "Favorite food: " << favorite_food << std::endl;
	}
};
class Person : protected Being
{
protected:
	PersonalDevice pDevice;
	MainWorkDevice mwd;

public:
	Person(std::string type, std::string name, int limbs, int age, std::string favFood, PersonalDevice pd, MainWorkDevice mworkd)  :  Being(type, name, limbs, age, favFood)
	{
		pDevice = pd;
		mwd = mworkd;
	}
	void printInfo()
	{
		std::cout << "Type: " << type << '\n'
			<< "Name: " << name << '\n'
			<< "Limbs: " << limbs << '\n'
			<< "Age: " << age << '\n'
			<< "Favorite food: " << favorite_food << '\n';
		pDevice.GetPersonalDeviceInfo();
		mwd.isHigherEndOrNot();
	}
	//void 
};


int main()
{
	Being animal1("Mamifer", "Iepure", 4, 2, "morcov");
	animal1.printInfo();
	Sleep(3000);
	system("cls");
	PersonalDevice pd1("Samsung Galaxy S23 Ultra", 1299.99);
	Person p1("Human", "Stefan", 4, 25, "Pizza", pd1, MainWorkDevice("Amd ryzen 9 7950x", 16, 32, 3.5, 5.7, 32));
	p1.printInfo();
	Sleep(10000);
	//std::cout << pd1.reversePDName(pd1.getDeviceName());

	system("cls");
	PersonalDevice pdStef("Samsung Galaxy S23 Fan Edition", 599.99);
	MainWorkDevice MwdStef("Intel i5- 10265U", 4, 8, 2.4, 4.5, 16);
	Person p2("Human", "Stefania", 4, 22, "Pasta", pdStef, MwdStef);
	p2.printInfo();
	palindromeCheck("MAdam");








}
void palindromeCheck(std::string test)
{

	char a = '0';
	char arr[26];
	char arrLowercase[26];
	
	for (int i = 0; i < 26; i++)
	{
		arr[i] = i + 65;
		arrLowercase[i] = i + 97;
	}

	for (int i = 0; i < test.length() / 2; i++)
	{
		for (int j = test.length() - 1; j >= test.length() / 2; j--)
		{
			a = test[i];
			for (int k = 0; k < 26; k++)
			{
				if (a == arr[k])
				{
					a = arrLowercase[k];
					test[i] = a;
					break;
				}
			}
				if (test[i] == test[j])
				{
					i++;
					continue;
				}
				else
				{
					std::cout << "String is not palindrome";
					break;
				}
		}
	}
	std::cout << "The parameter string is a palindrome";
}