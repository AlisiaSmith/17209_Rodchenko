struct Object{};

//std::auto_ptr

class SmartPointer{
public: 
	SmartPointer(Object *o) : o_(o) {}
	~SmartPointer() { delete o_; }
	//SmartPointer & operator=(const SmartPointer) = delete;
	SmartPointer(SmartPointer other){ // sp2 = sp
		o_ = other.o_;
		other.o_ = nillptr;
	}
	SmartPointer & operator=(SmartPointer other){ // sp2 = sp3
		if (&other != this)
		{
			delete o_;
		o_ = other.o_;
		other.o_ = nillptr;
		}
		return *this;
	}

private:
	Object *o_;
}

int main()
{
	//Object * o = new Object();
	//���� ������ ������ ����
	SmartPointer sp(new Object());
	// ��. ������������� ��������
	/SmartPointer sp2 = sp; //������, ��������� �����������

	SmartPointer sp3(new Object());
	sp2 = sp3;
}

