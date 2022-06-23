#include <iostream>
#include <string>


using namespace std;

struct Time
{
	int hour;
	int minute;

};

struct Data
{
	int day;
	int month;
	Time planTime;
};

struct Task
{
	string name;
	int priority;
	string description;
	Data DateAndTime;



};
int length;
Task* tasks;
void addToAnd(Task*& arr, int& length, Task value) //cc���� �� ������ ����� �������� �� ������ , � ��������� �� ������ �������� ������ �������
{
	Task* newArray = new Task[length + 1];//�������� ������
	for (int i = 0; i < length; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[length] = value;
	delete[]arr; //������� ������ ������ �� ��������� ��������
	arr = newArray; //��������� ����� ��������� ������ �������
	length++;
}

void AddTask()
{
	Task task;

	cout << "Napishite nazvanie dela: ";
	cin >> task.name;
	cout << "Napishite prioritet dela(ot 1 do 3)(1 samoe vazhnoe, 2 sredney vazhnosti, 3 ne ochen vazhnoe: ";
	cin >> task.priority;
	cout << "Napishite opisanie dela: ";
	cin >> task.description;
	cout << "Napishite den kogda nuzhno sdelat delo: ";
	cin >> task.DateAndTime.day;
	cout << "Napishite mesyac kogda nuzhno sdelat delo: ";
	cin >> task.DateAndTime.month;
	cout << "Napishite chas kogda nuzhno sdelat delo: ";
	cin >> task.DateAndTime.planTime.hour;
	cout << "Napishite minutu kogda nuzhno sdelat delo: ";
	cin >> task.DateAndTime.planTime.minute;

	addToAnd(tasks, length, task);

}

void deleteByIndex(Task*& arr, int& length, int placeIndex) //cc���� �� ������ ����� �������� �� ������ , � ��������� �� ������ �������� ������ �������
{
	Task* newArray = new Task[length--];//�������� ������
	for (int i = 0, j = 0; i < length; i++, j++)
	{
		if (placeIndex == i)
		{
			j++;
		}
		newArray[i] = arr[j];
	}
	delete[]arr; //������� ������ ������ �� ��������� ��������
	arr = newArray; //��������� ����� ��������� ������ �������
}

int findIndexByName(Task*& arr, int& length, string name)
{

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].name == name) return i;

	}
	return -1;

}


void printTask(Task task)
{
	cout << task.name << "\t" << task.priority << "\t" << task.description << "\t" << task.DateAndTime.day << "\t" << task.DateAndTime.month << "\t" << task.DateAndTime.planTime.hour << ":" << task.DateAndTime.planTime.minute << endl;

}

int findTasksInMounth(Task*& arr, int& length, int mounth)
{

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].DateAndTime.month == mounth)
		{
			printTask(arr[i]); // dobavit na den poisk
		}

	}
	return -1;

}
int findTasksInDay(Task*& arr, int& length, int mounth)
{

	for (size_t i = 0; i < length; i++)
	{
		if (arr[i].DateAndTime.day == mounth)
		{
			printTask(arr[i]); // dobavit na den poisk
		}

	}
	return -1;

}

void editTask(Task& task)
{



	cout << "\n1-��������" << endl;
	cout << "2-����������" << endl;
	cout << "3-��������" << endl;
	cout << "4-����" << endl;
	cout << "������� ��� ��������: ";
	int par;
	cin >> par;

	switch (par)
	{
	case 1:

		cout << "������� ����� �������� ";
		cin >> task.name;

		break;
	case 2:
		cout << "������� ����� ��������� ";
		cin >> task.priority;
		break;

	case 3:
		cout << "������� ����� �������� ";
		cin >> task.description;

		break;
	case 4:

		cout << "������� ����� ���� ";
		cin >> task.DateAndTime.day;
		cin >> task.DateAndTime.month;
		break;


	default:
		break;
	}






}

void bubbleSortPrioryti(Task*& arr, int n) {
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].priority > arr[j + 1].priority)
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false) // dobavit data
			break;
	}
}

void sortByPriority(Task* arr, int length)
{
	bubbleSortPrioryti(tasks, length);
}
void bubbleSortMonth(Task*& arr, int n) {
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j].DateAndTime.month > arr[j + 1].DateAndTime.month)
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false) // dobavit data
			break;
	}
}

void sortByMonth(Task* arr, int length)
{
	bubbleSortMonth(tasks, length);
}


void vivodVsexDel()
{
	for (size_t i = 0; i < length; i++)
	{
		cout << "���:" << tasks[i].name << "\t" << "���������:" << tasks[i].priority << "\t" << "��������:" << tasks[i].description << "\t" << "����:" << tasks[i].DateAndTime.day << "\t" << "�����:" << tasks[i].DateAndTime.month << "\t" << "�����: " << tasks[i].DateAndTime.planTime.hour << ":" << tasks[i].DateAndTime.planTime.minute << endl;
	}
}

void menu()
{


	cout << "1. ���������� ���" << endl;
	cout << "2. �������� ���" << endl;
	cout << "3. �������������� ���" << endl;
	cout << "4. ����� ��� �� �����" << endl;
	cout << "5. ����������� ���" << endl;
	cout << "6. ����� ���� ���" << endl;


	int index, index1, index2, par, par1, par2, par3;
	string name, name1;

	cout << "������� ����� ����: " << endl;
	cin >> par;

	while (par < 1 || par > 6)
	{
		cout << "�� ��������, ��������� �������:";
		cin >> par;
	}


	switch (par)
	{

	case 1:
		AddTask();

		break;
	case 2:

		cout << "������� ���: ";
		cin >> name;
		index = findIndexByName(tasks, length, name);

		if (index != -1)
		{
			deleteByIndex(tasks, length, index);
			system("pause");
		}
		else
		{
			cout << "������ ����� ���!\n" << endl;
		}

		break;
	case 3:


		cout << "������� ��� �a��� ��� ��������������: ";
		cin >> name;
		index = findIndexByName(tasks, length, name);
		editTask(tasks[index]);
		break;




	case 4:


		cout << "������� ���:";
		cin >> name1;
		index1 = findIndexByName(tasks, length, name1);
		cout << "���:" << tasks[index1].name << "\t" << "���������:" << tasks[index1].priority << "\t" << "��������:" << tasks[index1].description << "\t" << "����:" << tasks[index1].DateAndTime.day << "\t" << "�����:" << tasks[index1].DateAndTime.month << "\t" << "�����: " << tasks[index1].DateAndTime.planTime.hour << ":" << tasks[index1].DateAndTime.planTime.minute << "\n" << endl;



		break;

	case 5:
		cout << "���������� ������ ��� ��:\n1.�� ����\n2.�� �����\n";
		cin >> par1;
		cout << "������� ��� ������:\n";
		cin >> par2;

		switch (par1)
		{

		case 1:
			findTasksInDay(tasks, length, par2);
			break;

		case 2:
			findTasksInMounth(tasks, length, par2);
			break;

		default:
			break;
		}



		break;

	case 6:

		cout << "1.�� �����������\n2.����������� �� ����������\n3.����������� �� ������ ����������\n";
		cin >> par3;


		switch (par3)
		{
		case 1:

			vivodVsexDel();
			break;
		case 2:
			sortByPriority(tasks, length);
			vivodVsexDel();
			break;
		case 3:
			sortByMonth(tasks, length);
			vivodVsexDel();
			break;
		default:
			break;
		}


	default:
		break;
	}


}



int main()
{
	setlocale(LC_ALL, "Russian");


	while (true)
	{
		menu();

	}






	return 0;
}