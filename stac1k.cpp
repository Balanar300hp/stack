#include "stdafx.h"
#include <cstdlib>
#include <memory>
#include <iostream>

using namespace std;

template<typename T>
class stack;

template<typename T>
ostream & operator<<(ostream & output, stack<T> & stack);




template<typename T>
class stack {
public:
	stack();
	stack(stack const & sqr);
	~stack();
	auto count() const noexcept->size_t;
	auto pop()->T;
	auto push(T const & value)->void;
	auto operator=(stack const & sqr)->stack &;
	auto swap(stack & sqr)->void;
	auto top()->T &;
	friend ostream & operator<< <>(ostream & output, stack<T> const & stack);//перегрузка вывода стэка
private:
	T * array_;
	size_t array_size_;
	size_t count_;

};

---------------------------------------------------------------------------------------------------------------------------

//Описание методов класса 

template<typename T>//конструктор по умолчанию 
inline stack<T>::stack() : count_(0) {}

template<typename T>//конструктор копирования
inline stack<T>::stack(stack const & sqr) : array_size_(sqr.array_size_),
count_(sqr.count_) {
	array_ = new T[array_size_];
	for (size_t i(0); i < count_; ++i) {
		array_[i] = sqr.array_[i];
	}
}


template<typename T>//деструктор
inline stack<T>::~stack() {
	count_ = 0;
	delete[] array_;
}

template<typename T>//возврат кол-ва эл-ов в стэке
inline auto stack<T>::count() const noexcept->size_t{
	return count_;
}

template<typename T>//добавление элемента в стэк 
inline auto stack<T>::push(T const & value)->void {
	if (count_ == array_size_)
	{
		array_size_ *= 2;
		T * bal = new T[array_size_];
		copy(array_, array_size_ + array_, bal
		);
		delete[] array_;

		array_ = bal;
		delete[] bal;
	}
	array_[count_] = value;
	++count_;

}

template <typename T>
auto stack<T>::top()->T& {//удаление элемента из стэка 
	//проверка на пустоту
	if (count_ == 0) throw logic_error("Empty!");
	//верхний элемент возвращается в качестве результата
	return array[count - 1];
}

template<typename T>
inline auto stack<T>::pop()->T {//уменьшение размера стэка 
	if (count_ == 0) throw logic_error("Empty!");
	return --count_;
}





template<class T>// оператор присваивания 
inline stack<T> & stack<T>::operator=(stack const & sqr) {
	if (this != &sqr) {
		(stack(sqr)).swap(*this);
	}
	return *this;
}

template <typename T>
ostream & operator<<(ostream & output, stack<T> const & stack) {
	for (size_t i(0); i < stack.count_; ++i) {
		output << stack.array_[i] << " ";
	}
	output << endl;
	return output;
}

template<typename T>
inline auto stack<T>::swap(stack & sqr)->void {
	swap(sqr.array_size_, array_size_);
	swap(sqr.array_, array_);
	swap(sqr.count_, count_);
}

/*int main() {
	stack <int> obj;

	obj.push(1);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.top();
	obj.pop();




	system("pause");
	return 0;
}*/
