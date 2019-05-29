// #include "stacktp1.h" 
// #include <iostream>

// template <class Type>
// Stack<Type>::Stack(int ss) {
//     stacksize = ss;
//     items = new Type[ss];
//     top = 0;
// }

// template <class Type>
// Stack<Type>::Stack(const Stack & st){
//     if(this != &st) {
//         stacksize = st.stacksize;
//         items = new Type[stacksize];
//         top = st.top;

//         //还需要将每个元素都赋值
//         if(st.top > 0) {
//             for(int i=0; i<st.top; i++) {
//                 items[i] = st.items[i];
//             }
//         }
//     }
// }

// template <class Type>
// Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st) {
//     if(this != &st) {
//         delete [] items;

//         stacksize = st.stacksize;
//         items = new Type[stacksize];
//         top = st.top;

//         //还需要将每个元素都赋值
//         if(st.top > 0) {
//             for(int i=0; i<st.top; i++) {
//                 items[i] = st.items[i];
//             }
//         }
//     }
//     return *this;
// }

// template <class Type>
// bool Stack<Type>::push(const Type & item) {
//     if(isfull()) {
//         std::cout << "Stack is full, push fail." << std::endl;
//         return false;
//     } else {
//         items[top++] = item;
//         return true;
//     }
// }

// template <class Type>
// bool Stack<Type>::pop(Type & item) {
//     if(isempty()) {
//         std::cout << "Stack is empty, pop fail." << std::endl;
//         return false;
//     } else {
//         item = items[--top];
//         return true;
//     }
// }
