#ifndef CONTAINER_H
#define CONTAINER_H


// Интерфейс
template<typename T>
class Container
{
public:
    // Виртуальные методы, будут реализованы далее
    virtual void insert(T value) = 0;
    virtual bool exists(T value) = 0;
    virtual void remove(T value) = 0;
    // Это потом заменим на перегруженный оператор <<
    virtual void print() = 0;

    // Виртуальный деструктор
    virtual ~Container();
};

template<typename T>
Container<T>::~Container(){};

#endif // CONTAINER_H
