#include <iostream>
using namespace std;
class LL{
public:
    double value;
    LL * next;
};

class Sarlist{
    public:
    long int size;
    LL* First;
    Sarlist()
    {
        size =0;
        First= nullptr;
    }
    ~Sarlist()
    {
        LL* p,*q;
        p=First;
        while(p!= nullptr)
        {
            q=p->next;
            delete p;
            p=q;
        }
    }
    long int Size()
    {
        return size;
    }
        bool empty()
    {
        if(First == nullptr)
            return true;
        else
            return false;
    }
    LL* Insert_First(double x)
    {
        LL * p;
        p=new LL;
        p->value=x;
        p->next=First;
        First =p;
        size++;
        return p;
    }
    void Delete_First(void)
    {
        LL * p;
        p=First;
        First =First->next;
        size--;
        delete p;
    }

    void print()
    {
        LL *p;
        p=First;
        while(p!= nullptr)
        {
            cout<<p->value<<",";
            p=p->next;
        }

    }
};

    LL* Insert_First(LL* First,double x)
    {
        LL * p;
        p=new LL;
        p->value=x;
        p->next=First;
//        First =p;
   //     size++;
        return p;
    }
    void print(LL *first)
    {
        LL *p;
        p=first;
        while(p!= nullptr)
        {
            cout<<p->value<<",";
            p=p->next;
        }
    }

int main()
{
    Sarlist A;
    LL *first=nullptr;
    first=Insert_First(first, 5);
    print(first);
    cout<<"\n Print-1\n ";
    A.print();
    A.Insert_First(21);
    A.Insert_First(55);
    A.Insert_First(22);
    cout<<"\n Print-2\n ";
    A.print();
    A.Delete_First();
    cout<<"\n Print-3\n ";
    A.print();

    return 0;
}
