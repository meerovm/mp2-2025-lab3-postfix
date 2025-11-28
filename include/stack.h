// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память
#include <algorithm>
template<typename T>
class Stack {
private:
	size_t sz;
	size_t c;
	T* p;
public:
	Stack(size_t s = 1) : c(0), sz(std::max(s, (size_t) 1)), p(new T[sz]) {}
	~Stack() { 
		delete [] p;
		p = nullptr;
	}
	void Push(const T& e) {
		if (c < sz) {
			p[c++] = e;
		}
		else {
			int sz_n = sz*2;
			T* q = new T[sz_n];
			std::copy(p, p + c, q);
			q[c++] = e;
			delete[] p;
			p = q;
			sz = sz_n;
		}
	}
	T Pop() {
		if (!IsEmpty()) {
			c--;
			return p[c];
		}
		throw std::out_of_range("Stack is empty");
	};
	T Check() {
		if (!IsEmpty()) {
			return p[c - 1];
		}
		throw std::out_of_range("Stack is empty");
	};
	bool IsEmpty() { return (c == 0); };
	size_t CheckSize() { return c; };
	void Clear() {
		delete[] p;
		p = new T[1];
		c = 0;
		sz = 1;
	}
};
