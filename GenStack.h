#ifndef _GENSTACK_H_
#define _GENSTACK_H_

#include <memory>

using namespace std;

template <class T>
class GenStack {
 public:
  // Constructs new empty GenStack
  GenStack() {
    array_size_ = 4096;
    data_ =  unique_ptr<T[]>(new T [array_size_]);
    top_ = 0;
  };
  // destructor
  ~GenStack() {}
  // pushes an item atop the stack
  void Push(T item);
  // removes and returns the top item
  T Pop();
  // returns the size of the stack
  int Size();

 private:
  int top_; // index to put next item
  int array_size_; // size of internal data array
  unique_ptr<T[]> data_; // internal data array
};

template <class T>
void GenStack<T>::Push(T item) {
    // if top is equal to array size, move data to a 
    // new array that is twice as large
    if (top_ == array_size_) {
        unique_ptr<T[]> new_data(new T [array_size_ * 2]);
        for (int i = 0; i < array_size_; i++)
            new_data[i] = data_[i];
        array_size_ = array_size_ * 2;
        data_ = move(new_data);
    }
    data_[top_] = item;
    top_++;
}

template <class T>
T GenStack<T>::Pop() {
    if (top_ == 0) {
        throw "Stack is empty!";
    }
    top_--;
    return data_[top_];
}

template <class T>
int GenStack<T>::Size() {
    return top_;
}

// int main() {
//     GenStack<int> stack;
//     for (int i = 0; i < 5000; i++)
//         // test push
//         stack.Push(i);
//     // test size
//     cout << stack.Size() << endl;
//     for (int i = 0; i < 5000; i++)
//         // test pop
//         stack.Pop();
//     cout << stack.Size() << endl;
//     try {
//         // test exception if stack empty
//         stack.Pop();
//     } catch (char const* msg) {
//         cerr << msg << endl;
//     }
// }

#endif  // _GENSTACK_H_