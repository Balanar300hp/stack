#include "stdafx.h"
#include <cstdlib>
#include <memory>
#include <iostream>

using namespace std;




template<typename T>
class stack {
public:
	stack();
	stack(stack const & sqr);
	~stack();
	size_t count() const;
	T pop();
	void push(T const & value);
	//void print();
	stack & operator=(stack const & sqr);
	void swap(stack & sqr);
private:
	T * array_;
	size_t array_size_;
	size_t count_;
	
};

template<typename T>//конструктор по умолчанию 
inline stack<T>::stack() : count_(0) {}

template<typename T>//деструктор
inline stack<T>::~stack() {
	delete[] array_;
}

template<typename T>//возврат кол-ва эл-ов в стэке
inline size_t stack<T>::count() const {
	return count_;
}

template<typename T>//добавление элемента в стэк 
inline void stack<T>::push(T const & value) {
	if (count_ == array_size_)
	{
		array_size_ *= 2;
		T * bal = new T[array_size_];
		memcpy(bal, array_, array_size_ * sizeof(T));
		delete[] array_;

		array_ = bal;
		delete[] bal;
	}
	array_[count_] = value;
	++count_;

}

template<typename T>
inline T stack<T>::pop() {//удаление элементов из стэка
	assert(count_ > 0);
	return array_[--count_];
}

/*template <typename T>//вывод стэка
inline void stack<T>::print() {
	for (size_t i(0); i < count_; i++)
		cout << array_[i] << endl;
}*/


template<typename T>//конструктор копирования
inline stack<T>::stack(stack const & sqr) : array_size_(sqr.array_size_),
count_(sqr.count_) {
	array_ = new T[array_size_];
	for (size_t i(0); i < count_; ++i) {
		array_[i] = sqr.array_[i];
	}
}

template<class T>// оператор присваивания 
inline stack<T> & stack<T>::operator=(stack const & sqr)  {
	assert(this != &sqr);
		(stack(sqr)).swap(*this);
	return *this;
}

template<typename T> 
inline void stack<T>::swap(stack & sqr) {
swap(sqr.array_size_, array_size_);
swap(sqr.array_, array_);
swap(sqr.count_, count_);
}

int main() {
	stack <int> obj;

	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);



	
	system("pause");
	return 0;



}
