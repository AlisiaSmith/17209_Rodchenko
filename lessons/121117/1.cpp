// RAII
// Resource acquisition is initialization
// Захват ресурса - это инициализация

//    ^^^^^^^^^^^^^^
//    ||||||||||||||
// Управление ресурсами

void f()
{
  throw 1;
}

void g()
{
  f();
}

struct A
{
};

struct SmartPtrData
{
  size_t counter = 0u; //unsigned
  A * ptr = nullptr;
}

// умный указатель
// по-желанию: template <class T>
Class SmartPointer
{
public:

  SmartPointer() {} // к-р по-умолчанию


  ~SmartPointer() {
    if(nullptr != spdata)
      if( 1 == spdata->counter)
      {
        delete spdata->ptr;
        delete spdata;
        return;
      }
      --spdata->counter;
  } // деструктор


  SmartPointer(A *a)
  {
    spdata = new SmartPtrData;
    spdata->counter++;
    spdata->ptr = a;
  } // к-р захватывает ресурс


  SmartPointer(const SmartPointer& other)
  {
    if(!other.spdata) return;
    spdata = other.spdata;
    spdata->counter++;
  } // к-р копирования


  SmartPointer& operator=(const SmartPointer& other)
  {
    if(other == *this) return *this;

    //if(this->spdata)
    //  if( 1 == spdata->counter)
    //  {
    //      delete spdata->ptr;
    //      delete spdata;
    //  }
    //    else spdata->counter --;
    this.~SmartPointer();

    spdata = other.spdata;
    spdata->counter++;
    return *this;
  } // оп-я присваивания
  // можно сделать по-желанию поддержание семантики перемещения

  A* get() const
  {
    if(spdata) return spdata->ptr;
    return nullptr;
  } // получение укзателя


  void reset(A * other)
  {
    delete spdata->ptr;
    spdata->ptr = other;
  } // освободить старый ресурс, захватить новый

  //operator*, operator ->

private:
  SmartPtrData * spdata = nullptr;
}

int main ()
{
//  std::ifstream f("input.txt", "r");
  SmartPointer sp(new int);
  SmartPointer sp2 = sp;
  // вар 1. Разрушающее копирование, уже реалиован нами, есть в библиотеке (std::auto_ptr), но запрещен к использованию
  // вар 2. Глобальная хэш-таблица хранит флажки на каждый ресурс
  // вар 3. флажок хранить прямо на месте (std::shared_ptr) + нюансы
  // вар 4. base::linked_ptr (chromium)
  // вар 5. счетчик ссылок хранить прямо в объекте (boost::intrusive_ptr, refcoun... in chromium)
  // вар 6. запретить копирование
  // вар 7. запретить копирование, но разрешить перемещение (std::unique_ptr)
  // std::move(sp) ???


  g();

  return 0;
}
