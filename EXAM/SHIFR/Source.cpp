#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

string lib;



string encrypt(string str, string key)
{
	int length = 0;
	int* arr = new int[length];
	int temp, temp1, temp2;
	string encryptText, newKey;
	for (int i = 0, j = 0; i < str.length(); i++, j++)
	{
		if (j == key.length()) j = 0;
		newKey += key[j];
	}
	cout << newKey << endl;

	for (int i = 0; i < str.length(); i++) // perviy cikl po strochke
	{
		for (int j = 0; j < lib.length(); j++) // vtoroi po alfavitu
		{
			if ((char)str[i] == lib[j]) // naxodim bukkvu v alphavite
			{
				temp1 = j;
			}
		}
		for (int j = 0; j < lib.length(); j++) // vtoroi po alfavitu
		{
			if ((char)newKey[i] == lib[j]) // naxodim bukkvu v alphavite
			{
				temp2 = j;
			}
		}
		temp = (temp1 + temp2) % lib.length();
		encryptText += lib[temp];
	}
	cout << encryptText << endl;
	return encryptText;
}

string decrypt(string str, string key)
{
	int length = 0;
	int* arr = new int[length];
	int temp, temp1, temp2;
	string encryptText, newKey;
	for (int i = 0, j = 0; i < str.length(); i++, j++)
	{
		if (j == key.length()) j = 0;
		newKey += key[j];
	}
	cout << newKey << endl;

	for (int i = 0; i < str.length() - 2; i++) // perviy cikl po strochke
	{
		for (int j = 0; j < lib.length(); j++) // vtoroi po alfavitu
		{
			if ((char)str[i] == lib[j]) // naxodim bukkvu v alphavite
			{
				temp1 = j;
			}
		}
		for (int j = 0; j < lib.length(); j++) // vtoroi po alfavitu
		{
			if ((char)newKey[i] == lib[j]) // naxodim bukkvu v alphavite
			{
				temp2 = j;
			}
		}
		temp = temp1 - temp2;
		if (temp < 0)
		{
			temp += lib.length();
		}
		else
		{
			temp = (temp1 - temp2) % lib.length();
		}
		encryptText += lib[temp];
	}
	cout << encryptText << endl;
	return encryptText;
}

string readFromFile(string filename)
{
	string text;
	ifstream fileIn;    //read
	fileIn.open(filename);
	if (fileIn.fail())
	{
		cout << "Error opening file!\a";
		return "error";
	}
	while (!fileIn.eof())
	{
		string line;
		getline(fileIn, line);
		text += line + '\n';
	}
	fileIn.close();
	return text;
}

string writeInFile(string filename, string text)
{
	ofstream fileOut; //write
	fileOut.open(filename);
	if (fileOut.fail())
	{
		cout << "Error opening file!\a";
		return "error";
	}
	fileOut << text;
	fileOut.close();
}

string makeLib()
{

	for (int i = 33; i < 47; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 65; i < 91; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 97; i <= 122; i++) //маленькие буквы
	{
		lib += (char)i;
	}
	for (int i = 48; i <= 57; i++) //цифры
	{
		lib += (char)i;
	}
	for (int i = 192; i < 224; i++) //большие буквы
	{
		lib += (char)i;
	}
	for (int i = 224; i < 256; i++) //большие буквы
	{
		lib += (char)i;
	}
	lib += (char)32;
	lib += '\n';
	return lib;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	string fileNameText = "text.txt";
	string fileNameEncrypt = "en.txt";
	string fileNameDecrypt = "de.txt";
	makeLib();

	//cout << makeLib() << endl;
	while (true)
	{
		//шифрование
		string str, key;
		cout << "¬ведите ключ";
		cin >> key;
		str = readFromFile(fileNameText);
		cout << str;

		writeInFile(fileNameEncrypt, encrypt(str, key));

		system("pause");

		//дешифрование
		str = readFromFile(fileNameEncrypt);
		writeInFile(fileNameDecrypt, decrypt(str, key));

		system("pause");
	}



	return 0;
}