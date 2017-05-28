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
         //�˴���Ϊ�˱�֤�ѿռ�ֻ��һ������ָ��ָ�����ԭ����ָ��Ҫ��NULL,��������ת������Ϊ������const�����޸�
        //ע�⣡�� ת���Ĳ�����Ȼ��SmartPointer<T>����������
        const_cast<SmartPointer<T>&>(obj).m_pointer=NULL;
    }
    SmartPointer<T>& operator=(const SmartPointer<T>& obj)
    {
        if(this!=&obj)
        {
            T* tmp = this->m_pointer;
              //�˴��Ƿ�Ӧ���ȱ��棬�Ͼ�����������Ļᴥ�������������п������쳣������������!!!!!!!!
            m_pointer=obj.m_pointer;
             //�˴���Ϊ�˱�֤�ѿռ�ֻ��һ������ָ��ָ�����ԭ����ָ��qingkong,��������ת������Ϊ������const�����޸�
            //ע�⣡�� ת���Ĳ�����Ȼ��SmartPointer<T>����������
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
