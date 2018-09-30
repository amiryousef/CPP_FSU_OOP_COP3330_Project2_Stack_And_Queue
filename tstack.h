/*
   tstack.h
*/

#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>
#include <cstdlib>

namespace fsu
{
  template < typename T, size_t N = 100 >
  class TStack
  {
  public:
    TStack();                         // default constructor
    TStack(T fill);                   // puts "fill" in each slot of the underlying array
    TStack(const TStack&);            // copy constructor
    ~TStack();                        // destructor
    TStack& operator=(const TStack&); // assignment operator

    void Push(const T& t);   // push t onto stack; error if full
    T Pop();                 // pop stack and return removed element; error if stack is empty
    T& Top();                // return top element of stack; error if stack is empty
    const T& Top() const;    // const version
    size_t Size() const;     // return number of elements in stack
    size_t Capacity() const; // return storage capacity [maximum size] of stack
    int Empty() const;       // return 1/true if stack is empty, 0/false if not empty
    void Clear();            // make the stack empty
    void Display(std::ostream& os, char ofc = '\0') const; // output contents through os

    void Dump(std::ostream& os, char ofc = '\0') const;

  private:
    const size_t capacity_;  // = N = size of array   - fixed during life of stack
    T data_[N];              // array of T objects    - where T objects are stored
    size_t size_;            // current size of stack - dynamic during life of stack

  };
  
  template < typename T , size_t N >
  std::ostream& operator<<(std::ostream& os, const TStack<T,N>& S)
  {
    S.Display (os, '\0');
    return os;
  }

  template < typename T , size_t N >
  TStack<T,N>::TStack() : capacity_(N), size_(0)
  {
  }

  template < typename T , size_t N >
  TStack<T,N>::TStack(T fill) : capacity_(N), size_(0)
  {
    for (size_t i = 0; i < capacity_; i++)
      data_[i] = fill;
  }

  template < typename T , size_t N >
  TStack<T,N>::TStack(const TStack<T, N>& s) : capacity_(s.capacity_), size_(s.size_)
  {
    for (size_t i = 0; i < capacity_; i++)
      data_[i] = s.data_[i];
  }

  template < typename T , size_t N >
  TStack<T,N>::~TStack()
  {
  }

  template < typename T , size_t N >
  TStack<T,N>& TStack<T,N>::operator=(const TStack<T, N>& s)
  {
    if (this != &s)
    {
      size_ = s.size_;

      for (size_t i = 0; i < capacity_; i++)
        data_[i] = s.data_[i];
    }
  
    return *this;
  }

  template < typename T , size_t N >
  void TStack<T,N>::Push(const T& t)
  {
    if (size_ == capacity_)
      std::cerr << "** TStack error: Push called on full stack" << std::endl;
    else
      data_[size_++] = t;
  }

  template < typename T , size_t N >
  T TStack<T,N>::Pop()
  {
    if (size_ == 0)
    {
      std::cerr << "** TStack error: Pop() called on Empty Stack" << std::endl;
      exit(EXIT_FAILURE);
    }

    return data_[--size_];
  }

  template < typename T , size_t N >
  T& TStack<T,N>::Top()
  {
    if (size_ == 0)
    {
      std::cerr << "** TStack error: Top() called on Empty Stack" << std::endl;
      exit(EXIT_FAILURE);
    }

    return data_[size_ - 1];
  }

  template < typename T , size_t N >
  const T& TStack<T,N>::Top() const
  {
    if (size_ == 0)
    {
      std::cerr << "** TStack error: Top() called on Empty Stack" << std::endl;
      exit(EXIT_FAILURE);
    }

    return data_[size_ - 1];
  }

  template < typename T , size_t N >
  size_t TStack<T,N>::Size() const
  {
    return size_;
  }

  template < typename T , size_t N >
  size_t TStack<T,N>::Capacity() const
  {
    return capacity_;
  }

  template < typename T , size_t N >
  int TStack<T,N>::Empty() const
  {
    if (size_ == 0)
      return 1;
    else
      return 0;
  }

  template < typename T , size_t N >
  void TStack<T,N>::Clear()
  {
    size_ = 0;
  }

  template < typename T , size_t N >
  void TStack<T,N>::Display(std::ostream& os, char ofc) const
  {
    if (ofc == '\0')
      for (size_t i = 0; i < size_; i++)
        os << data_[i];
    else
      for (size_t i = 0; i < size_; i++)
        os << data_[i] << ofc;
  }

  template < typename T , size_t N >
  void TStack<T,N>::Dump(std::ostream& os, char ofc) const
  {
      os << "Capacity: " << capacity_ << std::endl;
      os << "Size:     " << size_ << std::endl;
      os << "Array:    [";
      
      if (ofc == '\0')
        for (size_t i = 0; i < capacity_; i++)
          os << data_[i];
      else
        for (size_t i = 0; i < capacity_; i++)
        {
          if (i != 0)
            os << ofc;
          
          os << data_[i];
        }

      os << "]" << std::endl;
      os << "Stack:    [";

      if (ofc == '\0')
        for (size_t i = 0; i < size_; i++)
          os << data_[i];
      else
        for (size_t i = 0; i < size_; i++)
        {
          if (i != 0)
            os << ofc;
          
          os << data_[i];
        }

      os << "]" << std::endl;
  }
}

#endif
