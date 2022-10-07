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
		T data;             //�������� ����
		Node* next;         //����. ����
		Node* previe;       //����. ����
		Node(T data = T(), Node* previe = nullptr, Node* next = nullptr) //�����������
		{
			this->data = data;
			this->previe = previe;
			this->next = next;
		}
		friend std::ostream& operator << (std::ostream& os, const Node& at) //����� �� �������� �������� ���� ������
		{
			os << at.data;
			return os;
		}
	};
public:
	Node<T>* head; //�������� ���� ������
	Node<T>* tail; //��������� ���� ������
	int count;

	LinkedList()  //�����������
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
		
	
	}
	LinkedList(LinkedList& list)    //����������� ����������� 
	{
		Clear();
		Node<T>* current = list.head;
		while (current != nullptr)
		{
			AddTail(current->data);
			current = current->next;

		}

	}

	LinkedList(initializer_list<T> list) // ����������� ������������� {*,*,*...} 
	{
		typename initializer_list<T>::iterator i;
		for (i = list.begin(); i != list.end(); ++i)
		{
			AddTail(*i);

		}
	}
	
	
	~LinkedList();   // ���������� 

	LinkedList<T> operator + (const LinkedList<T>&);	// ���������� ��������� + , ��������������� ��� ������ 

	LinkedList<T>& operator = (const LinkedList<T>&); //���������� ��������� = , ������������ ������������ 

	T& operator [](const int index); //�������� ������� �� ������� (�� �������� �������) 

	Node<T>* Search(int); //����� ������ �������� ������ 

	void Print(); //����� ������ � ������� 

	void Add(const T&, int); //����� ���������� �������� � ������ 

	void AddTail(T); //����� ���������� �������� � ����� ������ 

	void AddHead(T); //����� ���������� �������� � ������ ������ 

	int GetCount();//����� ��������� ������� ������ 

	T& GetHead(); //����� ��������� ������� �������� ������ 

	T& GetTail();//����� ��������� ���������� �������� ������ 

	void Delete(int); //����� �������� �������� �� ������ 

	void Clear(); //����� ������� ������ 



	///******���������*******(�� ��������)
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
/// ���������� ��������� + , ��������������� ��� ������ 
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
/// ���������� ��������� = , ������������ ������������ 
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
/// �������� ������� �� ������� (�� �������� �������) 
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
			cout << "������ �������� �� ��������� ��������� �� 0 �� " << count - 1 << endl;
		}
	}
	else
	{
		cout << "������ ����!" << endl;
	}


}

/// <summary>
/// ����� ������ ������ � ������� 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void LinkedList<T>::Print()
{
	if (head != nullptr)
	{
		setlocale(LC_ALL, "");
		cout << "������ ���������:";
		Node<T>* current = head;
		for (int i = 0; i < count; i++)
		{
			cout << *current << "\t";
			current = current->next;
		}

		cout << "\n ����������� ��������� � ������: " << count << endl;
	}
	else
	{
		cout << "������ ����!" << endl;
	}

}

/// <summary>
/// ����� ���������� �������� � ����� ������ 
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
/// ����� ���������� �������� � ������ ������ 
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
/// ����� ��������� ������� ������ 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
int LinkedList<T>::GetCount()
{
	return count;
}

/// <summary>
/// ����� ��������� ������� �������� ������ 
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
		cout << "������ ����!" << endl;

	}
}

/// <summary>
/// ����� ��������� ���������� �������� ������ 
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
		cout << "������ ����!" << endl;

	}
}

/// <summary>
/// ����� �������� �������� �� ������ 
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
/// ����� ������� ������ 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void LinkedList<T>::Clear()
{
	while (count != 0) Delete(0);

	head = tail = nullptr;
	count = 0;
	//cout << "������ ������!" << endl;
}

/// <summary>
/// ���������� 
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
LinkedList<T>::~LinkedList()
{
	Clear();
}

/// <summary>
/// ����� ���������� �������� � ������ 
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
		cout << "������ �� ��������� ��������� �� 0 �� " << count << endl;
	}



}

/// <summary>
/// ����� ������ ���� ������ 
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
			cout << "������ �������� �� ��������� ��������� �� 0 �� " << count - 1 << endl;
			return nullptr;
		}
	}
	else
	{
		cout << "������ ����!" << endl;
		return nullptr;
	}
}


