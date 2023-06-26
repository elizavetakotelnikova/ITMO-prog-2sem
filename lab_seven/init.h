#ifndef LAB_SIXTH_WITHOUT_INIT_H
#define LAB_SIXTH_WITHOUT_INIT_H
#include <iostream>
#include <vector>
#include <iterator>

class WrongAction: public std::exception {
private: const char* msg;
public:
    WrongAction(const char* msg) {
        this->msg = msg;
    }
    const char* what() {
        return msg;
    }
};

template <class T>
class Buffer {
public: class Iterator: public std::iterator<std::bidirectional_iterator_tag, T> {
    private: T* ptr;
        size_t index_ = 0;
    public:
        Iterator() {
            ptr = nullptr;
        }
        Iterator(T* ptr) {
            this->ptr = ptr;
        }
        Iterator(const Iterator &b) {
            ptr = b.ptr;
        }
        T& operator*() const { return *ptr; }
        T* operator->() { return ptr; }

        Iterator& operator++() {
            ptr++;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator operator+ (std::iter_difference_t<T*> diff) {
            return (this->ptr + diff);
        };

        Iterator operator- (std::iter_difference_t<T*> diff) {
            return (this->ptr - diff);
        };

        Iterator operator+= (std::iter_difference_t<T*> diff) {
            ptr += diff;
            return *this;
        };

        Iterator operator-= (std::iter_difference_t<T*> diff) {
            ptr -= diff;
            return *this;
        };

        bool operator== (const Iterator& b) {
            return this->ptr == b.m_ptr;
        };

        bool operator!= (const Iterator& b) {
            return this->ptr != b.ptr;
        };

        double distance(const Iterator& b) {
            double diff = this->ptr - b->ptr;
            return diff;
        };
    };
private:
    size_t buffer_size;
    size_t last; //last is a position of a next element in the end
    size_t first; //first is a position of a first element
    size_t cur_size;
    T *arr;
public:
    Buffer(size_t size) {
        buffer_size = size;
        cur_size = 0;
        arr = new T[buffer_size];
        first = last = 0;
    }

    Buffer(size_t size, T value) {
        cur_size = size;
        buffer_size = size;
        arr = new T[buffer_size];
        for (int i = 0; i < buffer_size; i++) {
            arr[i] = value;
        }
        first = 0;
        last = buffer_size - 1;
    }

    T& operator[] (size_t N) {
        if (N >= buffer_size) {
            throw std::invalid_argument("N is more than max buffer_size");
        }
        if ((N >= last and N < first) or (N > first and N >= last)) {
            throw std::invalid_argument("There is no element with N index");
        }
        return arr[N];
    }

    void insert_back(double element) {
        arr[last] = element;
        last = (last + 1) % buffer_size;
        if (cur_size != buffer_size) {
            cur_size++;
        }
    }

    void pop_back() {
        if (cur_size == 0) {
            throw WrongAction("Buffer is empty at the moment, can not pop an element");
        }
        else {
            if (last == 0) {
                last = buffer_size - 1;
            }
            else {
                last--;
            }
        }
        cur_size--;
    }

    void insert_begin(double element) {
        if (first == 0) {
            first = buffer_size - 1;
        }
        else {
            first--;
        }
        arr[first] = element;
        if (cur_size != buffer_size) {
            cur_size++;
        }
    }

    void pop_beginnig() {
        if (cur_size == 0) {
            throw WrongAction("Buffer is empty at the moment, can not pop an element");
        }
        first = (first + 1) % buffer_size;
        cur_size--;
    }

    void insert_index(double element, int index) {
        int counter = 0;
        double pred = arr[index % buffer_size];
        double temp;
        for (int i = index; counter != last; i = (i + 1) % buffer_size) {
            temp = arr[(i + 1) % buffer_size];
            arr[(i + 1) % buffer_size] = pred;
            pred = temp;
            counter++;
        }
        arr[index] = element;
        if (cur_size != buffer_size) {
            cur_size++;
        }
        last++;
        last = last % buffer_size;
    };

    void pop_index(int index) {
        if (cur_size == 0) {
            std::cout << "Buffer is empty";
            return;
        }
        if ((index >= last and index < first) or (index > first and index >= last )) {
            throw std::invalid_argument("Out of current bounds, cannot be taken");
        }
        for (int i = index; i != last - 1; i = (i + 1) % buffer_size) {
            arr[i] = arr[(i + 1) % buffer_size];
        }
        if (last == 0) {
            last = buffer_size--;
        }
        else {
            last--;
        }
        cur_size--;
    }

    void resize(size_t new_size) {
        T *tmp = arr;
        arr = new T[new_size];
        for (int i = 0; i < buffer_size; i++) {
            arr[i] = tmp[i];
        }
        buffer_size = new_size;
        first = 0;
        last = new_size - 1;
    }

    void print() {
        int counter = 0;
        for (int i = first; counter != cur_size; i++) {
            std::cout << arr[i % buffer_size] << " ";
            counter++;
        }
    }

    Iterator begin() {
        return Iterator(&arr);
    }

    Iterator front_element() {
        return Iterator(&arr[first]);
    }

    Iterator back_element() {
        return Iterator(&arr[last - 1]);
    }
};
#endif //LAB_SIXTH_WITHOUT_LIMITATION_CPP_H
