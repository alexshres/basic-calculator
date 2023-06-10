#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>

namespace basic_calculator {
    template<class T>
    class Stack {
    public:
        static const std::size_t CAPACITY = 50;

        Stack() { used = 0; }

        void push(const T &val);

        T pop();

        bool is_empty() const { return (used == 0); }

        std::size_t size() const { return used; }

    private:
        std::size_t used;
        T data[CAPACITY];

    };

    template<class T>
    void Stack<T>::push(const T &val) {
        data[used] = val;
        ++used;
    }

    template<class T>
    T Stack<T>::pop() {
        T return_val = data[used - 1];
        --used;

        return return_val;
    }
}


#endif //STACK_H
