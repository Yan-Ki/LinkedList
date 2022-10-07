// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include "linked-list.cpp"
using std::cin;
using std::cout;
using std::endl;


int main()
{
	setlocale(LC_ALL, "");
	cout << "Начало выполнения!" << endl;

	cout << "Initialization list1" << endl; //Создание списка
	LinkedList <int> list1;
	list1.Print();

	cout << "AddHead:" << endl;//Добавление в начало списка
	list1.AddHead(4);
	list1.Print();

	cout << "AddTail:" << endl; //Добавление в конец списка
	list1.AddTail(8);
	list1.Print();

	cout << "Add:" << endl;  //Добавление по индексу
	list1.Add(15, 2);
	list1.Add(16, 3);
	list1.Add(23, 4);
	list1.Add(42, 5);
	list1.Print();

	cout << "GetCount: " << list1.GetCount() << endl; //Получение длины списка

	cout << "GetHead: " << list1.GetHead() << endl; //Получение первого элемента

	cout << "GetTail: " << list1.GetTail() << endl; //Получение последнего элемента

	cout << "GetNodeIndex: " << list1[3] << endl; //Получение элемента по индексу

	cout << "Delete:" << endl; //Удаление элемента по индексу
	list1.Delete(1);
	list1.Print();

	cout << "Clear:" << endl; //Очистка списка
	list1.Clear();
	list1.Print();

	//*************************************
	list1.AddHead(4);
	list1.AddHead(4);

	cout << "initializer_list: list2 and list3 " << endl; //Инициализация list2 и list3
	LinkedList <int> list2 {8,8};
	LinkedList <int> list3 {15,15};
		
	list1.Print();
	list2.Print();
	list3.Print();

	cout << "operator + and operator = " << endl;
	list3 = list1 + list2;  // Перегрузки операторов + и =
	
	list3.Print();
		

		cout << "Конец выполнения!" << endl;
	return 0;


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
