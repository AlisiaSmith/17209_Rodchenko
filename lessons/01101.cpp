#include<iostream>

//������� ����� 
class Base
{
public:
	Base (int i) : i(i) {}
	void f()
	{
		std::cout << "Base::f()" << std::endl;
	}

protected:
	int i = 0;
	void d()
	{
		std::cout << "Base::d()" << std::endl;
	}
};

// ����� ���������
class Derived : public Base {
public:
	Derived() : Base(1005000) {} //���������� ��-�� ������� ������������� ����
	void g() {
		d(); // legal
		i = 1;
	}

};

//����������� ������� - �������� ������������ 
void f() {}
void f(int i) {}

//int main()
//{
//	//Base k; //unlegal
//	Base s(100500); //legal
//	//Derived t;
//	////t.d(); // unlegal
//	//Derived m; // legal
//	//m.g(); // legal
//
//	f();
//	f(8);
//
//	return 0;
// }