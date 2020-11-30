//// list 带头双向循环的链表, 可以针对性解决vector的缺陷，也就是说vector和list是两个互补形式存在的容器 
//#include <iostream>
////#include <list>
////#include <vector>
//using namespace std;
//
////void test1()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////
////	list<int> copy(lt1);
////	list<int> lt2;
////	lt2 = lt1;
////
////	// 迭代器
////	list<int>::iterator it1 = lt1.begin();
////	while (it1 != lt1.end())
////	{
////		cout << *it1 << " ";
////		++it1;
////	}
////	cout << endl;
////
////	for (auto e : lt2)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	for (auto e : copy)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////}
////
////void PrintList(const list<int>& lt)
////{
////	list<int>::const_iterator it = lt.begin();
////	while (it != lt.end())
////	{
////		// *it = 1;  // 不能修改
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////}
////
////void test2()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	list<int>::reverse_iterator rit1 = lt1.rbegin();
////	while (rit1 != lt1.rend())
////	{
////		cout << *rit1 << " ";
////		++rit1;
////	}
////	cout << endl;
////
////	PrintList(lt1);
////}
////
////void test3()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.pop_back();
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.push_front(-1);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.pop_front();
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////}
////
////void test4()
////{
////	// list支持任意位置O(1)的插入删除
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	// [)
////	list<int>::iterator pos = find(lt1.begin(), lt1.end(), 2);
////	if (pos != lt1.end())
////	{
////		lt1.insert(pos, 20);
////	}
////
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.erase(pos);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	//vector<int> v;
////	//v.push_back(1);
////	//v.push_back(2);
////	//v.push_back(3);
////	//v.push_back(4);
////	//vector<int>::iterator vpos = find(v.begin(), v.end(), 2);
////	//if (vpos != v.end())
////	//{
////	//	cout << "找到了" << endl;
////	//}
////}
////
////void test5()
////{
////	// list支持任意位置O(1)的插入删除
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	lt1.push_back(5);
////	lt1.push_back(6);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	list<int>::iterator it1 = lt1.begin();
////	/*while (it1 != lt1.end())
////	{
////		if (*it1 % 2 == 0)
////		{
////			it1 = lt1.erase(it1);
////		}
////		else
////		{
////			++it1;
////		}
////	}*/
////
////	while (it1 != lt1.end())
////	{
////		if (*it1 % 2 == 0)
////		{
////			lt1.erase(it1++);
////		}
////		else
////		{
////			it1++;
////		}
////	}
////
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	// vector insest 迭代器会失效 (增容)
////	// list insert迭代器是否会失效？ 不会
////}
//
//namespace zyf
//{
//	template<class T>
//	struct __list_node
//	{
//		__list_node<T>* _prev;
//		__list_node<T>* _next;
//		T _data;
//
//		__list_node(const T& data = T())
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(data)
//		{}
//	};
//
//	template<class T, class Ref, class Ptr>
//	struct __list_iterator
//	{
//		typedef __list_iterator<T, Ref, Ptr> Self;
//		typedef __list_node<T> node;
//		node* _node;
//
//		__list_iterator(node* node)
//			:_node(node)
//		{}
//
//		//链表的迭代的核心还是节点的指针
//		//但是封装在类，可以通过运算符去控制++ * 等行为
//		//T& operator*()
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//
//		// T* operator->()
//		Ptr operator->()
//		{
//			return &_node->_data;
//		}
//
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//		Self operator++(int)
//		{
//			__list_iterator<T> tmp(*this);
//			_node = _node->_next;
//			return tmp;
//		}
//
//		Self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//
//		Self operator--(int)
//		{
//			Self tmp(*this);
//			_node = _node->_prev;
//			return tmp;
//		}
//
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//
//		bool operator==(const Self& it)
//		{
//			return _node == it._node;
//		}
//	};
//
//	template<class T>
//	class list
//	{
//		typedef __list_node<T> node;
//	public:
//		typedef __list_iterator<T, T&, T*> iterator;
//		typedef __list_iterator<T, const T&, const T*>  const_iterator; // const迭代器如何实现？和普通迭代器哪不一样？
//
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//
//		iterator end()
//		{
//			return iterator(_head);
//		}
//
//		const_iterator begin() const
//		{
//			return const_iterator(_head->_next);
//		}
//
//		const_iterator end() const
//		{
//			return const_iterator(_head);
//		}
//
//		list()
//		{
//			_head = new node;
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		list(const list<int>& lt);
//		list<T>& operator=(const list<int>& lt);
//
//		~list()
//		{
//			clear();
//			delete _head;
//			_head = nullptr;
//		}
//
//		void clear()
//		{
//			iterator it = begin();
//			while (it != end())
//			{
//				iterator next = it;
//				++next;
//
//				delete it._node;
//
//				it = next;
//			}
//
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		void push_back(const T& x)
//		{
//			node* newnode = new node(x);
//			node* tail = _head->_prev;
//
//			tail->_next = newnode;
//			newnode->_prev = tail;
//			newnode->_next = _head;
//			_head->_prev = newnode;
//		}
//
//		void pop_back();
//		void push_front(const T& x);
//		void pop_front();
//		void insert(iterator pos, const T& x);
//		void erase(iterator pos);
//	private:
//		node* _head;
//	};
//
//	void test_list1()
//	{
//		list<int> lt;
//		lt.push_back(1);
//		lt.push_back(2);
//		lt.push_back(3);
//		lt.push_back(4);
//
//		list<int>::iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			*it *= 2;
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	struct A
//	{
//		A(int a1 = 0, int a2 = 0)
//			:_a1(a1)
//			, _a2(a2)
//		{}
//
//		int _a1;
//		int _a2;
//	};
//
//	void test_list2()
//	{
//		/*int* p1 = new int;
//		cout << *p1 << endl;
//		A* p2 = new A(1,2);
//		cout << p2->_a1 << endl;
//		cout << p2->_a2 << endl;*/
//
//		list<A> lt;
//		lt.push_back(A(1, 2));
//		lt.push_back(A(10, 20));
//		lt.push_back(A(100, 200));
//		list<A>::iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			//cout << *it << " ";
//			cout << it->_a1 << ":" << it->_a2 << endl;
//			++it;
//		}
//		cout << endl;
//	}
//
//	void PrintList(const list<int>& lt)
//	{
//		list<int>::const_iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			//*it = 2;
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	void test_list3()
//	{
//		list<int> lt;
//		lt.push_back(1);
//		lt.push_back(2);
//		lt.push_back(3);
//		lt.push_back(4);
//
//		PrintList(lt);
//
//		lt.clear();
//		PrintList(lt);
//	}
//}
//
////int main()
////{
////	test1();
////	test2();
////	test3();
////	test4();
////	test5();
////	system("pause");
////	return 0;
////}
//
//int main() {
//	zyf::test_list1();
//	zyf::test_list2();
//	zyf::test_list3();
//	system("pause");
//	return 0;
//}
//// list 带头双向循环的链表, 可以针对性解决vector的缺陷，也就是说vector和list是两个互补形式存在的容器 
//#include <iostream>
////#include <list>
////#include <vector>
//using namespace std;
//
////void test1()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////
////	list<int> copy(lt1);
////	list<int> lt2;
////	lt2 = lt1;
////
////	// 迭代器
////	list<int>::iterator it1 = lt1.begin();
////	while (it1 != lt1.end())
////	{
////		cout << *it1 << " ";
////		++it1;
////	}
////	cout << endl;
////
////	for (auto e : lt2)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	for (auto e : copy)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////}
////
////void PrintList(const list<int>& lt)
////{
////	list<int>::const_iterator it = lt.begin();
////	while (it != lt.end())
////	{
////		// *it = 1;  // 不能修改
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////}
////
////void test2()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	list<int>::reverse_iterator rit1 = lt1.rbegin();
////	while (rit1 != lt1.rend())
////	{
////		cout << *rit1 << " ";
////		++rit1;
////	}
////	cout << endl;
////
////	PrintList(lt1);
////}
////
////void test3()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.pop_back();
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.push_front(-1);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.pop_front();
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////}
////
////void test4()
////{
////	// list支持任意位置O(1)的插入删除
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	// [)
////	list<int>::iterator pos = find(lt1.begin(), lt1.end(), 2);
////	if (pos != lt1.end())
////	{
////		lt1.insert(pos, 20);
////	}
////
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.erase(pos);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	//vector<int> v;
////	//v.push_back(1);
////	//v.push_back(2);
////	//v.push_back(3);
////	//v.push_back(4);
////	//vector<int>::iterator vpos = find(v.begin(), v.end(), 2);
////	//if (vpos != v.end())
////	//{
////	//	cout << "找到了" << endl;
////	//}
////}
////
////void test5()
////{
////	// list支持任意位置O(1)的插入删除
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	lt1.push_back(5);
////	lt1.push_back(6);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	list<int>::iterator it1 = lt1.begin();
////	/*while (it1 != lt1.end())
////	{
////		if (*it1 % 2 == 0)
////		{
////			it1 = lt1.erase(it1);
////		}
////		else
////		{
////			++it1;
////		}
////	}*/
////
////	while (it1 != lt1.end())
////	{
////		if (*it1 % 2 == 0)
////		{
////			lt1.erase(it1++);
////		}
////		else
////		{
////			it1++;
////		}
////	}
////
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	// vector insest 迭代器会失效 (增容)
////	// list insert迭代器是否会失效？ 不会
////}
//
//namespace zyf
//{
//	template<class T>
//	struct __list_node
//	{
//		__list_node<T>* _prev;
//		__list_node<T>* _next;
//		T _data;
//
//		__list_node(const T& data = T())
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(data)
//		{}
//	};
//
//	template<class T, class Ref, class Ptr>
//	struct __list_iterator
//	{
//		typedef __list_iterator<T, Ref, Ptr> Self;
//		typedef __list_node<T> node;
//		node* _node;
//
//		__list_iterator(node* node)
//			:_node(node)
//		{}
//
//		//链表的迭代的核心还是节点的指针
//		//但是封装在类，可以通过运算符去控制++ * 等行为
//		//T& operator*()
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//
//		// T* operator->()
//		Ptr operator->()
//		{
//			return &_node->_data;
//		}
//
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//		Self operator++(int)
//		{
//			__list_iterator<T> tmp(*this);
//			_node = _node->_next;
//			return tmp;
//		}
//
//		Self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//
//		Self operator--(int)
//		{
//			Self tmp(*this);
//			_node = _node->_prev;
//			return tmp;
//		}
//
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//
//		bool operator==(const Self& it)
//		{
//			return _node == it._node;
//		}
//	};
//
//	template<class T>
//	class list
//	{
//		typedef __list_node<T> node;
//	public:
//		typedef __list_iterator<T, T&, T*> iterator;
//		typedef __list_iterator<T, const T&, const T*>  const_iterator; // const迭代器如何实现？和普通迭代器哪不一样？
//
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//
//		iterator end()
//		{
//			return iterator(_head);
//		}
//
//		const_iterator begin() const
//		{
//			return const_iterator(_head->_next);
//		}
//
//		const_iterator end() const
//		{
//			return const_iterator(_head);
//		}
//
//		list()
//		{
//			_head = new node;
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		list(const list<int>& lt);
//		list<T>& operator=(const list<int>& lt);
//
//		~list()
//		{
//			clear();
//			delete _head;
//			_head = nullptr;
//		}
//
//		void clear()
//		{
//			iterator it = begin();
//			while (it != end())
//			{
//				iterator next = it;
//				++next;
//
//				delete it._node;
//
//				it = next;
//			}
//
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		void push_back(const T& x)
//		{
//			node* newnode = new node(x);
//			node* tail = _head->_prev;
//
//			tail->_next = newnode;
//			newnode->_prev = tail;
//			newnode->_next = _head;
//			_head->_prev = newnode;
//		}
//
//		void pop_back();
//		void push_front(const T& x);
//		void pop_front();
//		void insert(iterator pos, const T& x);
//		void erase(iterator pos);
//	private:
//		node* _head;
//	};
//
//	void test_list1()
//	{
//		list<int> lt;
//		lt.push_back(1);
//		lt.push_back(2);
//		lt.push_back(3);
//		lt.push_back(4);
//
//		list<int>::iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			*it *= 2;
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	struct A
//	{
//		A(int a1 = 0, int a2 = 0)
//			:_a1(a1)
//			, _a2(a2)
//		{}
//
//		int _a1;
//		int _a2;
//	};
//
//	void test_list2()
//	{
//		/*int* p1 = new int;
//		cout << *p1 << endl;
//		A* p2 = new A(1,2);
//		cout << p2->_a1 << endl;
//		cout << p2->_a2 << endl;*/
//
//		list<A> lt;
//		lt.push_back(A(1, 2));
//		lt.push_back(A(10, 20));
//		lt.push_back(A(100, 200));
//		list<A>::iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			//cout << *it << " ";
//			cout << it->_a1 << ":" << it->_a2 << endl;
//			++it;
//		}
//		cout << endl;
//	}
//
//	void PrintList(const list<int>& lt)
//	{
//		list<int>::const_iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			//*it = 2;
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	void test_list3()
//	{
//		list<int> lt;
//		lt.push_back(1);
//		lt.push_back(2);
//		lt.push_back(3);
//		lt.push_back(4);
//
//		PrintList(lt);
//
//		lt.clear();
//		PrintList(lt);
//	}
//}
//
////int main()
////{
////	test1();
////	test2();
////	test3();
////	test4();
////	test5();
////	system("pause");
////	return 0;
////}
//
//int main() {
//	zyf::test_list1();
//	zyf::test_list2();
//	zyf::test_list3();
//	system("pause");
//	return 0;
//}
//// list 带头双向循环的链表, 可以针对性解决vector的缺陷，也就是说vector和list是两个互补形式存在的容器 
//#include <iostream>
////#include <list>
////#include <vector>
//using namespace std;
//
////void test1()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////
////	list<int> copy(lt1);
////	list<int> lt2;
////	lt2 = lt1;
////
////	// 迭代器
////	list<int>::iterator it1 = lt1.begin();
////	while (it1 != lt1.end())
////	{
////		cout << *it1 << " ";
////		++it1;
////	}
////	cout << endl;
////
////	for (auto e : lt2)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	for (auto e : copy)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////}
////
////void PrintList(const list<int>& lt)
////{
////	list<int>::const_iterator it = lt.begin();
////	while (it != lt.end())
////	{
////		// *it = 1;  // 不能修改
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////}
////
////void test2()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	list<int>::reverse_iterator rit1 = lt1.rbegin();
////	while (rit1 != lt1.rend())
////	{
////		cout << *rit1 << " ";
////		++rit1;
////	}
////	cout << endl;
////
////	PrintList(lt1);
////}
////
////void test3()
////{
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.pop_back();
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.push_front(-1);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.pop_front();
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////}
////
////void test4()
////{
////	// list支持任意位置O(1)的插入删除
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	// [)
////	list<int>::iterator pos = find(lt1.begin(), lt1.end(), 2);
////	if (pos != lt1.end())
////	{
////		lt1.insert(pos, 20);
////	}
////
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	lt1.erase(pos);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	//vector<int> v;
////	//v.push_back(1);
////	//v.push_back(2);
////	//v.push_back(3);
////	//v.push_back(4);
////	//vector<int>::iterator vpos = find(v.begin(), v.end(), 2);
////	//if (vpos != v.end())
////	//{
////	//	cout << "找到了" << endl;
////	//}
////}
////
////void test5()
////{
////	// list支持任意位置O(1)的插入删除
////	list<int> lt1;
////	lt1.push_back(1);
////	lt1.push_back(2);
////	lt1.push_back(3);
////	lt1.push_back(4);
////	lt1.push_back(5);
////	lt1.push_back(6);
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	list<int>::iterator it1 = lt1.begin();
////	/*while (it1 != lt1.end())
////	{
////		if (*it1 % 2 == 0)
////		{
////			it1 = lt1.erase(it1);
////		}
////		else
////		{
////			++it1;
////		}
////	}*/
////
////	while (it1 != lt1.end())
////	{
////		if (*it1 % 2 == 0)
////		{
////			lt1.erase(it1++);
////		}
////		else
////		{
////			it1++;
////		}
////	}
////
////	for (auto e : lt1)
////	{
////		cout << e << " ";
////	}
////	cout << endl;
////
////	// vector insest 迭代器会失效 (增容)
////	// list insert迭代器是否会失效？ 不会
////}
//
//namespace zyf
//{
//	template<class T>
//	struct __list_node
//	{
//		__list_node<T>* _prev;
//		__list_node<T>* _next;
//		T _data;
//
//		__list_node(const T& data = T())
//			:_next(nullptr)
//			, _prev(nullptr)
//			, _data(data)
//		{}
//	};
//
//	template<class T, class Ref, class Ptr>
//	struct __list_iterator
//	{
//		typedef __list_iterator<T, Ref, Ptr> Self;
//		typedef __list_node<T> node;
//		node* _node;
//
//		__list_iterator(node* node)
//			:_node(node)
//		{}
//
//		//链表的迭代的核心还是节点的指针
//		//但是封装在类，可以通过运算符去控制++ * 等行为
//		//T& operator*()
//		Ref operator*()
//		{
//			return _node->_data;
//		}
//
//		// T* operator->()
//		Ptr operator->()
//		{
//			return &_node->_data;
//		}
//
//		Self& operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//		Self operator++(int)
//		{
//			__list_iterator<T> tmp(*this);
//			_node = _node->_next;
//			return tmp;
//		}
//
//		Self& operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//
//		Self operator--(int)
//		{
//			Self tmp(*this);
//			_node = _node->_prev;
//			return tmp;
//		}
//
//		bool operator!=(const Self& it)
//		{
//			return _node != it._node;
//		}
//
//		bool operator==(const Self& it)
//		{
//			return _node == it._node;
//		}
//	};
//
//	template<class T>
//	class list
//	{
//		typedef __list_node<T> node;
//	public:
//		typedef __list_iterator<T, T&, T*> iterator;
//		typedef __list_iterator<T, const T&, const T*>  const_iterator; // const迭代器如何实现？和普通迭代器哪不一样？
//
//		iterator begin()
//		{
//			return iterator(_head->_next);
//		}
//
//		iterator end()
//		{
//			return iterator(_head);
//		}
//
//		const_iterator begin() const
//		{
//			return const_iterator(_head->_next);
//		}
//
//		const_iterator end() const
//		{
//			return const_iterator(_head);
//		}
//
//		list()
//		{
//			_head = new node;
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		list(const list<int>& lt);
//		list<T>& operator=(const list<int>& lt);
//
//		~list()
//		{
//			clear();
//			delete _head;
//			_head = nullptr;
//		}
//
//		void clear()
//		{
//			iterator it = begin();
//			while (it != end())
//			{
//				iterator next = it;
//				++next;
//
//				delete it._node;
//
//				it = next;
//			}
//
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		void push_back(const T& x)
//		{
//			node* newnode = new node(x);
//			node* tail = _head->_prev;
//
//			tail->_next = newnode;
//			newnode->_prev = tail;
//			newnode->_next = _head;
//			_head->_prev = newnode;
//		}
//
//		void pop_back();
//		void push_front(const T& x);
//		void pop_front();
//		void insert(iterator pos, const T& x);
//		void erase(iterator pos);
//	private:
//		node* _head;
//	};
//
//	void test_list1()
//	{
//		list<int> lt;
//		lt.push_back(1);
//		lt.push_back(2);
//		lt.push_back(3);
//		lt.push_back(4);
//
//		list<int>::iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			*it *= 2;
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	struct A
//	{
//		A(int a1 = 0, int a2 = 0)
//			:_a1(a1)
//			, _a2(a2)
//		{}
//
//		int _a1;
//		int _a2;
//	};
//
//	void test_list2()
//	{
//		/*int* p1 = new int;
//		cout << *p1 << endl;
//		A* p2 = new A(1,2);
//		cout << p2->_a1 << endl;
//		cout << p2->_a2 << endl;*/
//
//		list<A> lt;
//		lt.push_back(A(1, 2));
//		lt.push_back(A(10, 20));
//		lt.push_back(A(100, 200));
//		list<A>::iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			//cout << *it << " ";
//			cout << it->_a1 << ":" << it->_a2 << endl;
//			++it;
//		}
//		cout << endl;
//	}
//
//	void PrintList(const list<int>& lt)
//	{
//		list<int>::const_iterator it = lt.begin();
//		while (it != lt.end())
//		{
//			//*it = 2;
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	void test_list3()
//	{
//		list<int> lt;
//		lt.push_back(1);
//		lt.push_back(2);
//		lt.push_back(3);
//		lt.push_back(4);
//
//		PrintList(lt);
//
//		lt.clear();
//		PrintList(lt);
//	}
//}
//
////int main()
////{
////	test1();
////	test2();
////	test3();
////	test4();
////	test5();
////	system("pause");
////	return 0;
////}
//
//int main() {
//	zyf::test_list1();
//	zyf::test_list2();
//	zyf::test_list3();
//	system("pause");
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio> 
int n, step = 0;
void move(char A, char B) {
	step++;
	printf("%c TO %c\n", A, B);
}
void hanoi(int x, char A, char B, char C) {
	if (x == 1) {
		move(A, C);
		return;
	}
	hanoi(x - 1, A, C, B);
	move(A, C);
	hanoi(x - 1, B, A, C);
}
class solution {
	public int DFS(Map<Integer, Employee> info, int id) {
		//累加当前员工和直接下属的值
		int curImportance = info.get(id).importance;
		for (int subId : info.get(id).subordinates)(
			curImportance += DFs(info, subId);
	}
	return curImportance;
}
public int getImportance(List<Employee> employees, int id)
Map<Integer, Employee> info = new HashMap<>();
for (Employee cur : employees) {
	info nut(eun :
}
int main() { 
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	printf("%d\n", step);
	return 0;
}