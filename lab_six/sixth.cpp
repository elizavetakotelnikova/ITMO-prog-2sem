#ifndef LAB_SIXTH_SIXTH_H
#define LAB_SIXTH_SIXTH_H
#include <iostream>
struct Node {
    int data;
    Node *next;
    explicit Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

template<class T>
class Queue {
public: class Iterator: public std::iterator<std::bidirectional_iterator_tag, T> {
        private: T* ptr;
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
    Node *head = nullptr, *tail = nullptr;
public:
    void Enqueue(int value) {
        Node *new_node = new Node(value);
        if (this->tail == nullptr) {
            this->head = this->tail = new_node;
            return;
        }
        this->tail->next = new_node;
        this->tail = new_node;
    }
    void Dequeue() {
        if (this->head == nullptr)
            return;
        Node *for_delete = this->head;
        std::cout << this->head->data << '\n';
        this->head = this->head->next;
        if (this->head == NULL)
            this->tail = NULL;
        delete (for_delete);
    }
    Iterator begin() {
        return Iterator(&head->data);
    }
    Iterator end() {
        return Iterator(&tail->data);
    }
};


template <class Iterator, class UnaryPredicate>
bool All_of(Iterator first_iterator, Iterator end_iterator, UnaryPredicate predicate) {
    while (first_iterator != end_iterator) {
        if (predicate(*first_iterator) == false) {
            return false;
        }
        first_iterator++;
    }
    return true;
}

template <class Iterator, class UnaryPredicate>
bool One_of(Iterator first_iterator, Iterator end_iterator, UnaryPredicate predicate) {
    int counter = 0;
    while (first_iterator != end_iterator) {
        if (predicate(*first_iterator) == true) {
            counter++;
        }
        if (counter > 1) {
            return false;
        }
        first_iterator++;
    }
    if (counter == 1) {
        return true;
    }
    return false;
}

template <class Iterator, class T>
Iterator Find_backwards(Iterator first_iterator, Iterator end_iterator, const T &value) {
    while (end_iterator != first_iterator) {
        end_iterator--;
        if (*end_iterator == value) {
            return end_iterator;
        }
    }
    return first_iterator;
}

#endif
