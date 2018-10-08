class Base {
public:
	Base(int size) { i = new int[size];}
	virtual ~Base(){ delete[] i;}
private:
	int * i;
};


class Derived : public Base
{
public:
	Derived(int size) : Base(size) { i = new int[size]; }
	~Derived(){ delete[] i; }

private:
	int * i;
};

int main(){
	Base *b = new Base(100);
	Base *d = new Derived(200);
	*b = *d;
	delete b;
	delete d;
}