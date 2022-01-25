#ifndef __MAXHEAP_H_
#define __MAXHEAP_H_

#include<vector>
#include<iostream>

template<class T>
class MaxHeap {
  private:
    // contiene los elementos del heap
    std::vector<T> data; 
    // capacidad maxima del heap
    int maxSize;
    // tamaño actual del heap   
    int size;   

    int parent(int i);
    int left(int i);
    int right(int i);

  public:
    MaxHeap();
    MaxHeap(int capacity);
    ~MaxHeap();
    bool isEmpty();
    int getSize();
    int getCapacity();
    void setCapacity(int cap);
    void printMaxHeap();
    void push(T key);
    void heapify (int size, int i);
    T top();
    void pop();
};
template <class T> 
MaxHeap<T>::MaxHeap() {
  size = 0;
  maxSize = 0;
}
//Complexity O(1)
template <class T> 
MaxHeap<T>::MaxHeap(int capacity) {
    std::cout << "--->Creando un MaxHeap: " <<  this << std::endl;
    size = 0;
    maxSize = capacity;
    data.resize(maxSize);
}

//Complexity O(1)
template <class T> 
MaxHeap<T>::~MaxHeap() {
    std::cout << "--->Liberando memoria del MaxHeap: " <<  this << std::endl;
    data.clear();
}

//Complexity O(1)
template <class T> 
bool MaxHeap<T>::isEmpty() {
  return (size <= 0);
}

//Complexity O(1)
template <class T> 
int MaxHeap<T>::getSize() {
  return size;
}

//Complexity O(1)
template <class T> 
int MaxHeap<T>::getCapacity() {
  return maxSize;
}

//Complexity O(1)
template <class T> 
void MaxHeap<T>::setCapacity(int cap) {
  maxSize = cap;
  data.resize(maxSize);
}

//Complexity O(1)
template <class T> 
void MaxHeap<T>::printMaxHeap() {
  for (int i=0; i < size; i++)
    std::cout << data[i] << " ";
  std::cout << std::endl;
}

//Complexity O(1)
template <class T> 
int MaxHeap<T>::parent(int i) {
  return (i-1)/2; 
}

//Complexity O(1)
template <class T> 
int MaxHeap<T>::left(int i) {
  return (2*i + 1); 
}

//Complexity O(1)
template <class T> 
int MaxHeap<T>::right(int i) {
  return (2*i + 2);
}

//Complexity O(n)
template <class T> 
void MaxHeap<T>::push(T key) {
  if (size == maxSize) {
      std::cout << "Overflow: no se puede insertar la llave" << std::endl;
      return;
  }
  // Insertamos la nueva llave al final del vector
  int i = size;
  data[i] = key;
  size++;
  // Reparar las propiedades del max heap si son violadas
  while (i != 0 && data[parent(i)] < data[i]){
      std::swap(data[i], data[parent(i)]);
      i = parent(i);
  }
}

//Complexity O(n)
template <class T> 
T MaxHeap<T>::top() {
  T result;
  if (isEmpty()) {
      std::cout << "El MaxHeap está vacio" << std::endl;
      return result;
  }
  return data[0];
}

//heapify retrieved from: https://gist.github.com/rodolfomg/116ee67c62e1a08342bb1359c22ee03d and adapted 

//Complexity O(n)
template <class T>
void MaxHeap<T>::heapify (int size, int i) {
  int max_value = i;
  int left = this->left(i);
  int right = this->right(i);

  if (left < size && data[left] > data[max_value]) max_value = left;
  if (right < size && data[right] > data[max_value]) max_value = right;
  if (max_value != i) {
    std::swap(data[i], data[max_value]);
    heapify(size, max_value);
  }
}

//Complexity O(n)
template <class T>
void MaxHeap<T>::pop () {
  std::swap(data[0], data[this->size - 1]);
  heapify(this->size - 1, 0);
  this->size --;

  data[this->size];
}


#endif // __MAXHEAP_H_