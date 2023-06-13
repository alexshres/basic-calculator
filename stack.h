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

        T peek() const { return data[used - 1]; }

        void print() const;

    private:
        std::size_t used;
        T data[CAPACITY];

    };

    template<class T>
    void Stack<T>::push(const T &val) {
        if (is_empty())
            data[0] = val;
        else {
            data[used] = val;
        }

        ++used;
    }

    template<class T>
    T Stack<T>::pop() {
        T return_val = data[used - 1];
        --used;

        return return_val;
    }

    template<class T>
    void Stack<T>::print() const {
        assert(used > 0);


        for (std::size_t i = 0; i < used; ++i) {
            std::cout << data[used - 1 - i] << std::endl;
        }

        return;
    }
}


#endif //STACK_H
