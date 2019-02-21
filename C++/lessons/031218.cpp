#include<vector>
#include<list>
#include<map>
#include<forward_list>
#include<algorithm>
#include<iostream>
#include<itstream>

template <class It1, class It2>
void our_copy(It1 from,It1 to ,It2 where)
{
    while(from != to)
    {
        *where = *from;
        ++where; ++from;
    }
}

template<class T>
void our_advance(T& iter, int n, random_access_tag)
{
    iter += n;
}
template<class T>
void our_advance(T& iter, int n, random_access_tag)
{
    if( n > 0)
    {
        while(n-->0)
        {
            ++iter;
        }
    } else
    {
        while(n-->0)
        {
            --iter;
        }
    }
}

struct random_access_tag    {};

int main()
{
    std::vector<int> v = {6, 0, 3, 1, 7, 6, 9};
    std::vector<int>::iterator it_v = v.begin();
    std::vector<int>::iterator itr_v = v.rbegin(); // с конца

    std::list<int> l;
    std::list<int>::iterator it_l = l.begin();

    std::sort(l.begin(), l.end()); //doesn't have operator+,-
    std::sort(v.begin(), v.end());

    std::copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, ";"));

    our_copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, ";"));

    auto test_it = v.begin();
    std::advance(test_it, 3);


    std::forward_list<int> fl;
    std::forward_list<int>::iterator it_fl = fl.begin(); // doesn't have operator--
}
