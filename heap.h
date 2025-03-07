#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
int m_;
void sort_up();
void sort_down(int i);
std::vector<T> heap_;
PComparator c_;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c){

}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  heap_.push_back(item);
  sort_up();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  std::swap(heap_[0], heap_[heap_.size() - 1]);
  heap_.pop_back();
  sort_down(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return heap_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
 return heap_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::sort_up(){
  int i = heap_.size() - 1;
    while (i > 0) {
        if (c_(heap_[i], heap_[(i - 1)/m_])) {
            std::swap(heap_[i], heap_[(i - 1)/m_]);
            i = (i - 1)/m_;
        } else {
            break;
        }
    }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::sort_down(int i){
  if ((i*m_ + 1) >= heap_.size()){
    return;
  }
  int ex = i;
  for (int j = i*m_ + 1; j < std::min(i*m_ + 1 + m_, (int)heap_.size()); j++){
    if (c_(heap_[j], heap_[ex])){
      ex = j;
    }
  }
  if (ex != i){
    std::swap(heap_[i], heap_[ex]);
    sort_down(ex);
  }
}



#endif

