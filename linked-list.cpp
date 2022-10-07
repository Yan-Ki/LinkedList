#include <iostream> 
#include <initializer_list>
using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

template <typename T>
class LinkedList
{

private:
	template <typename T>
	class Node
	{
	public:
		T data;             //Значение узла
		Node* next;         //След. узел
		Node* previe;       //Пред. узел
		Node(T data = T(), Node* previe = nullptr, Node* next = nullptr) //Конструктор
		{
			this->data = data;
			this->previe = previe;
			this->next = next;
		}
		friend std::ostream& operator << (std::ostream& os, const Node& at) //Вывод на консолль значение узла списка
		{
			os << at.data;
			return os;
		}
	};
public:
	Node<T>* head; //Головной узел списка
	Node<T>* tail; //Последний узел списка
	int count;

	LinkedList()  //Конструктор
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
		
	
	}
	LinkedList(LinkedList& list)    //Конструктор копирования 
	{
		Clear();
		Node<T>* current = list.head;
		while (current != nullptr)
		{
			AddTail(current->data);
			current = current->next;

		}

	}

	LinkedList(initializer_list<T> list) // Конструктор инициализации {*,*,*...} 
	{
		typename initializer_list<T>::iterator i;
		for (i = list.begin(); i != list.end(); ++i)
		{
			AddTail(*i);

		}
	}
	
	
	~LinkedList();   // Деструктор 

	LinkedList<T> operator + (const LinkedList<T>&);	// Перегрузка оператора + , конкатенирующий два списка 

	LinkedList<T>& operator = (const LinkedList<T>&); //Перегрузка оператора = , присваивание копированием 

	T& operator [](const int index); //Получить элемент по индексу (из заданной позиции) 

	Node<T>* Search(int); //Метод поиска элемента списка 

	void Print(); //Метод печати в консоль 

	void Add(const T&, int); //Метод добавления элемента в список 

	void AddTail(T); //Метод добавления элемента в конец списка 

	void AddHead(T); //Метод добавления элемента в начало списка 

	int GetCount();//Метод получения размера списка 

	T& GetHead(); //Метод получения первого элемента списка 

	T& GetTail();//Метод получения последнего элемента списка 

	void Delete(int); //Метод удаления элемента из списка 

	void Clear(); //Метод очистки списка 



	///******Итераторы*******(Не доделано)
	/*template <typename T>
	class Iterator
	{
		friend class LinkedList<T>;
	protected:
		LinkedList::Node<T>* INode;
		const LinkedList<T>* IListist;
	public:

		
		Iterator()
		{
			this->INodenode = nullptr;
			this->IListist = nullptr;
		}
		Iterator(const LinkedList<T>* list, LinkedList::Node<T>* node)

		{
			this->INodee = node;
			this->IList = list;
		}
		Iterator next() const
		{
			if (INode != nullptr)
				return Iterator(IListist, INode->next);
			return *this;
		}
		Iterator begin() const
		{
			return Iterator(this, head);
		}
		Iterator end() const
		{
			return Iterator(this, tail).next();
		}
		Iterator sort() const
		{

		}

	};*/
};

/// <summary>
/// Перегрузка оператора + , конкатенирующий два списка 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="list2"></param>
/// <returns></returns>
template<typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T>& list2)
{
	LinkedList<T> list3(*this);

	Node<T>* current = list2.head;
	while (current != nullptr)
	{
		list3.AddTail(current->data);
		current = current->next;
	}
	return list3;

}
/// <summary>
/// Перегрузка оператора = , присваивание копированием 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="list2"></param>
/// <returns></returns>
template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list2)
{

	Clear();
	Node<T>* current = list2.head;
	while (current != nullptr)
	{
		AddTail(current->data);
		current = current->next;

	}
	return *this;

}

/// <summary>
/// Получить элемент по индексу (из заданной позиции) 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="index"></param>
/// <returns></returns>
template<typename T>
T& LinkedList<T>::operator[](const int index)
{
	if (head != nullptr)
	{
		if (index >= 0 || index < count)
		{
			int counter = 0;
			Node<T>* current = head;
			while (current != nullptr)
			{
				if (counter == index)
				{
					return current->data;
				}
				current = current->next;
				counter++;
			}
		}
		else
		{
			cout << "Индекс элемента за пределами диапазона от 0 до " << count - 1 << endl;
		}
	}
	else
	{
		cout << "Список пуст!" << endl;
	}


}

/// <summary>
/// Метод печати списка в консоль 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void LinkedList<T>::Print()
{
	if (head != nullptr)
	{
		setlocale(LC_ALL, "");
		cout << "Список элементов:";
		Node<T>* current = head;
		for (int i = 0; i < count; i++)
		{
			cout << *current << "\t";
			current = current->next;
		}

		cout << "\n Колличество элементов в списке: " << count << endl;
	}
	else
	{
		cout << "Список пуст!" << endl;
	}

}

/// <summary>
/// Метод добавления элемента в конец списка 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
template<typename T>
void LinkedList<T>::AddTail(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		tail = head;
		count++;
	}
	else
	{
		if (count == 1)
		{
			tail = new Node<T>(data);
			head->next = tail;
			tail->previe = head;
			count++;
		}
		else
		{
			Node<T>* current = tail;
			tail = new Node<T>(data);
			current->next = tail;
			tail->previe = current;
			count++;
		}

	}
}
/// <summary>
/// Метод добавления элемента в начало списка 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
template<typename T>
void LinkedList<T>::AddHead(T data)
{

	if (head == nullptr)
	{
		head = new Node<T>(data);
		tail = head;
		count++;
	}
	else
	{
		if (count == 1)
		{
			head = new Node<T>(data);
			head->next = tail;
			tail->previe = head;
			count++;
		}
		else
		{
			Node<T>* current = head;
			head = new Node<T>(data);
			current->previe = head;
			head->next = current;
			count++;
		}

	}
}

/// <summary>
/// Метод получения размера списка 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
int LinkedList<T>::GetCount()
{
	return count;
}

/// <summary>
/// Метод получения первого элемента списка 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
T& LinkedList<T>::GetHead()
{
	if (head != nullptr)
	{
		return head->data;

	}
	else
	{
		cout << "Список пуст!" << endl;

	}
}

/// <summary>
/// Метод получения последнего элемента списка 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
T& LinkedList<T>::GetTail()
{
	if (head != nullptr)
	{
		return tail->data;

	}
	else
	{
		cout << "Список пуст!" << endl;

	}
}

/// <summary>
/// Метод удаления элемента из списка 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="index"></param>
template<typename T>
void LinkedList<T>::Delete(int index)
{
	Node<T>* current = Search(index);
	if (current != nullptr)
	{
		if (count >= 2)
		{
			if (index == 0)
			{
				head = head->next; delete current; count--;
			}
			else
			{
				if (index == count - 1)
				{
					tail = tail->previe; delete current; count--;
				}
				else
				{
					current->next->previe = current->previe;
					current->previe->next = current->next;
					count--;
					delete current;
				}

			}

		}
		else
		{
			delete current; head = tail = nullptr; count = 0;

		}

	}
	else
	{
		return;
	}


}

/// <summary>
/// Метод очистки списка 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void LinkedList<T>::Clear()
{
	while (count != 0) Delete(0);

	head = tail = nullptr;
	count = 0;
	//cout << "Список очищен!" << endl;
}

/// <summary>
/// Деструктор 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
LinkedList<T>::~LinkedList()
{
	Clear();
}

/// <summary>
/// Метод добавления элемента в список 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="data"></param>
/// <param name="index"></param>
template <typename T>
void LinkedList<T>::Add(const T& data, int index)
{
	if (index >= 0 && index <= count)
	{
		if (head == nullptr || index == 0)
		{
			AddHead(data);
		}
		else
		{
			if (index == count)
			{
				AddTail(data);
			}
			else
			{
				Node<T>* current = Search(index);
				Node<T>* nodeNew = new Node<T>(data);
				nodeNew->previe = current->previe;
				current->previe->next = nodeNew;
				current->previe = nodeNew;
				nodeNew->next = current;
				count++;

			}

		}

	}
	else
	{
		cout << "Индекс за пределами диапазона от 0 до " << count << endl;
	}



}

/// <summary>
/// Метод поиска узла списка 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="index"></param>
/// <returns></returns>
template <typename T>
LinkedList<T>::Node<T>* LinkedList<T>::Search(int index)
{
	if (head != nullptr)
	{
		if (index >= 0 && index < count)
		{
			int i = 0;
			Node<T>* current = head;
			while (current != nullptr)
			{
				if (i == index)
				{
					return current;
				}
				current = current->next;
				i++;
			}
		}
		else
		{
			cout << "Индекс элемента за пределами диапазона от 0 до " << count - 1 << endl;
			return nullptr;
		}
	}
	else
	{
		cout << "Список пуст!" << endl;
		return nullptr;
	}
}


