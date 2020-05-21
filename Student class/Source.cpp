#include <iostream>
#include <fstream>
using namespace std;
class Student
{
private:
	char *name;
	int *marks;
	int age;
	float avgMark;
	int size;
	int number;
	void CalcAvMar()
	{
		float aver = 0;
		for (int i = 0; i < size; i++)
		{
			aver = aver + marks[i];
		}
		aver = aver / size;
		avgMark = aver;
	}
public:
	void AddMArk(int _mark)
	{
		int *temp = new int[size+1];
		for (int i = 0; i < size; i++)
			{ temp[i] = marks[i]; }
		temp[size] = _mark;
		size = size + 1;
		delete[] marks;
		marks = temp;
		CalcAvMar();
	}
	Student()
	{
		cout << "Constructor default " << endl;
		name = nullptr;
		SetName("No name");
		age = 0;
		marks = 0;
		number = 0;
		avgMark = 0;
		size = 0;
	}
	Student(const char* _name, int _age) : Student()
	{
		cout << "Constructor parametrized)" << endl;
		name = nullptr;
		SetName(_name);
		setAge(_age);
		number = 0;
		avgMark = 0;
		size = 0;
	}
	void setAge(int _age)
	{
		if (_age >= 0 && _age <= 146)
			{ age = _age; }
	}
	void SetName(const char* _name)
	{
		if (name != nullptr)
			{ delete[] name; }
		int size = strlen(_name) + 1;
		name = new char[size];
		strcpy_s(name, size, _name);
	}
	void Print() const
	{
		if (name != nullptr)
			{ cout << "NAME: " << name << endl; }
		cout << "Age: " << age << endl;
		cout << "Marks:";
		for (int i = 0; i < size; i++)
		{
			if ((size - i) == 1)   
				{ cout << marks[i] << " "; }
			else   
				{ cout << marks[i] << ", "; }
		}
		cout << "\nAverage mark: " << avgMark << endl;
	}
	void Save() const
	{
		ofstream fout;
		fout.open("Saves.txt", ios_base::app);
		bool isOpen = fout.is_open();
		if (isOpen == true)
		{
			// cout << "Fout Opened" << endl;
			ofstream rewrite("Saves.txt");
			rewrite.write("", 0);
			rewrite.close();
			fout << name << endl;
			fout << age << endl;
			fout << size << endl;
				for (int i = 0; i < size; i++)
				{ fout << marks[i] << endl; }
			fout << avgMark << endl;
		}
		else
		{ cout << "File not find" << endl; }
		fout.close();
	}
	void Load()
	{
		ifstream fin;
		fin.open("Saves.txt");
		bool isOpen = fin.is_open();
		if (isOpen == true)
		{
			// cout << "Fin Opened" << endl;
				fin >> name >> age;
				fin >> size;
				marks = new int[size];
				for (int i = 0; i < size; i++)
				{ fin >> marks[i]; }
				fin >> avgMark;
		}
		else
		{
			cout << "File not find" << endl;
		}
		fin.close(); 
	}
	~Student()
	{
		delete[] name;
		delete[] marks;
		name = nullptr;
		marks = nullptr;
	}
};

int main() {
	Student st1("Oleg",23);
	st1.AddMArk(8);
	st1.AddMArk(9);
	st1.Print();
	st1.Save();
	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	/*
	Student st2;
	st2.Load();
	st2.Print();
	*/

	system("pause");
	return 0;
}