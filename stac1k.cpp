#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>
class stack
{
public:
	stack();
	stack(const stack&);
	auto count() const noexcept->size_t;
	auto push(T const &)->void;
	auto pop()->T;
	auto top() const->T&;
	~stack();
	auto operator=(const stack&tmp)->stack&;
	auto print()->void;
	
private:
	auto mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T*;
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>//копирование и выделение памяти 
inline auto stack<T>::mem_copy(size_t count_m, size_t array_size_m, const T * tmp)->T* {
	T *mass = new T[array_size_m];
	copy(tmp,tmp+count_m,mass);
	return mass;
}


template <typename T>//освобождение памяти
inline stack<T>::~stack()
{
	delete[] array_;
}

template <typename T>//конструктор по умолчанию
inline stack<T>::stack() :count_(0),array_size_(0),array_(nullptr){};

template <typename T>//вставка элемента в стэк 
inline auto stack<T>::push(T const &val)->void {
	if (array_ == nullptr) {
		array_ = new T[1];
		array_[0] = val;
		count_++; array_size_++;
	}
	else {
		if (count_ == array_size_) {
			array_size_ *= 2;
			T *tmp = mem_copy(count_,array_size_,array_);
			delete[] array_;
			array_ = tmp;

		}
		array_[count_] = val;
		count_++;
	
	}
}

template <typename T>//конструктор копирования
inline stack<T>::stack(const stack&tmp) :count_(tmp.count_), array_size_(tmp.array_size_), array_(copy(tmp.count_, tmp.array_size, tmp.array_)) {};

template <typename T>//перегрузка оператора присваивания 
inline auto stack<T>::operator=(const stack&tmp)->stack& {
	if (this != &tmp) {
		delete[] array_; 
		count_ = tmp.count_;
		array_size_ = tmp.array_size_;
		array_ = new T[array_size_];
		copy(tmp.array_, tmp.array_ + count_, array_);
	}
	return *this;
}

template <typename T>// вывод стэка
inline auto stack<T>::print()->void {
	for (size_t i(0); i < count_; i++) cout << array_[i] << endl; 
}

template <typename T>//возвращаем count_
inline auto stack<T>::count() const noexcept->size_t {
	return count_;
}

template <typename T>// уменьшение count_ 
inline auto stack<T>::pop()->T {
	if (count_ == 0) throw logic_error("Empty!");
	return --count_;
}

template <typename T>//удаление элемента
inline auto stack<T>::top() const->T& {
	if (count_ == 0) throw logic_error("Empty!");
	cout << "Cou1" << array_[count_] << endl;
	return array_[count_];

}

/*int main() {
	stack <int> obj;
	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.print();
	cout << "1" << obj.count() << endl;
	obj.pop();
	cout << "2" << obj.count() << endl;
	obj.top();
	obj.print();
	system("pause");
	return 0;
}*/
