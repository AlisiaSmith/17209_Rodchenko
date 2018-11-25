// RAII
// Resource acquisition is initialization
// Захват ресурса - это инициализация

//    ^^^^^^^^^^^^^^
//    ||||||||||||||
// Управление ресурсами

#include<stdlib.h>

struct A
{
};

struct SmartPtrData
{
  size_t counter = 0u; //unsigned
  A * ptr = nullptr;

bool operator==(const SmartPtrData& tmp) {  return (counter == tmp.counter) && (ptr == tmp.ptr);  }
};
// умный указатель
// по-желанию: template <class T>
class SmartPointer
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
    if(*this == other) return *this;

    if(spdata)
      if( 1 == spdata->counter)
      {
          delete spdata->ptr;
          delete spdata;
      }
        else spdata->counter--;
  //  this.~SmartPointer();

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
    if (!spdata)
    {
      spdata = new SmartPtrData;
      spdata->counter = 1u;
    }
    else       delete spdata->ptr;
    spdata->ptr = other;
  } // освободить старый ресурс, захватить новый

  SmartPtrData& operator*() { return *spdata; }
  SmartPtrData* operator->() { return spdata; }
  //operator*, operator ->

  bool operator==(const SmartPointer& tmp) const {  return spdata == tmp.spdata;  }


private:
  SmartPtrData *spdata = nullptr;
};

int main ()
{
//  std::ifstream f("input.txt", "r");
//  SmartPointer sp(new int);
//  SmartPointer sp2 = sp;
  // вар 1. Разрушающее копирование, уже реалиован нами, есть в библиотеке (std::auto_ptr), но запрещен к использованию
  // вар 2. Глобальная хэш-таблица хранит флажки на каждый ресурс
  // вар 3. флажок хранить прямо на месте (std::shared_ptr) + нюансы
  // вар 4. base::linked_ptr (chromium)
  // вар 5. счетчик ссылок хранить прямо в объекте (boost::intrusive_ptr, refcoun... in chromium)
  // вар 6. запретить копирование
  // вар 7. запретить копирование, но разрешить перемещение (std::unique_ptr)
  // std::move(sp) ???

  return 0;
}
