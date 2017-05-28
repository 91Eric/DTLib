#ifndef _SMARTPOINTER_H
#define _SMARTPOINTER_H

namespace DTLib
{
template<typename T>
class SmartPointer
{
protected:
    T* m_pointer;
public:
    SmartPointer(T* p=NULL)
    {
        m_pointer = p;
    }
    SmartPointer(const SmartPointer<T>& obj)  //kaobeigouzao chushi m_pointer jiushi null buxuyao delete duibi operator=
    {
        m_pointer=obj.m_pointer;
         //此处是为了保证堆空间只被一个智能指针指向，因此原对象指针要置NULL,首先类型转换，因为参数是const不能修改
        //注意！！ 转换的参数仍然是SmartPointer<T>并且是引用
        const_cast<SmartPointer<T>&>(obj).m_pointer=NULL;
    }
    SmartPointer<T>& operator=(const SmartPointer<T>& obj)
    {
        if(this!=&obj)
        {
            T* tmp = this->m_pointer;
              //此处是否应该先保存，毕竟如果是类对象的会触发析构函数，有可能有异常，后续待测试!!!!!!!!
            m_pointer=obj.m_pointer;
             //此处是为了保证堆空间只被一个智能指针指向，因此原对象指针qingkong,首先类型转换，因为参数是const不能修改
            //注意！！ 转换的参数仍然是SmartPointer<T>并且是引用
            delete tmp;
            const_cast<SmartPointer<T>&>(obj).m_pointer=NULL;
        }
        return *this;
    }

    T* operator ->()
    {
        return m_pointer;
    }
    T& operator *()
    {
        return *m_pointer;
    }
    bool isNull()
    {
        return m_pointer==NULL;
    }
    T* get()
    {
        return m_pointer;
    }
    ~SmartPointer()
    {
        delete m_pointer;
    }
};

}


#endif // SMARTPOINTER_H
