/*
   tqueue.h
*/

#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>

namespace fsu
{
  template < typename T >
  class TQueue
  {
  public:
    TQueue();                         // default constructor
    TQueue(const TQueue&);            // copy constructor
    ~TQueue();                        // destructor
    TQueue& operator=(const TQueue&); // assignment operator

    void Push(const T& t);  // push t onto queue
    T Pop();                // pop queue and return removed element; error if queue is empty
    T& Front();             // return front element of queue; error if queue is empty
    const T& Front() const; // const version
    size_t Size() const;    // return number of elements in queue
    int Empty() const;      // return 1 if queue is empty, 0 if not empty
    void Clear();           // make the queue empty
    void Display (std::ostream& os, char ofc = '\0') const; // output contents through os

  private:
    class Link
    {
      Link (const T& t) : element_(t), nextLink_(0) {}
      T element_;
      Link* nextLink_;
      friend class TQueue<T>;
    };
    
    Link* firstLink_;
    Link* lastLink_;
  };
  
  template < typename T >
  std::ostream& operator<<(std::ostream& os, const TQueue<T>& S)
  {
    S.Display(os, '\0');
    return os;
  }

  template < typename T >
  TQueue<T>::TQueue() : firstLink_(0), lastLink_(0)
  {
  }

  template < typename T >
  TQueue<T>::TQueue(const TQueue<T>& q) : firstLink_(0), lastLink_(0)
  {
    Link* linkPtr = q.firstLink_;

    while (linkPtr != 0)
    {
      Push(linkPtr->element_);
      linkPtr = linkPtr->nextLink_;
    }
  }

  template < typename T >
  TQueue<T>::~TQueue()
  {
    Clear();
  }

  template < typename T >
  TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
  {
    if (this != &q)
    {
      Link* linkPtr = q.firstLink_;
      
	  Clear();

	  while (linkPtr != 0)
      {
        Push(linkPtr->element_);
        linkPtr = linkPtr->nextLink_;
      }
    }
  
    return *this;
  }

  template < typename T >
  void TQueue<T>::Push(const T& t)
  {
    Link* newLink = new Link(t);

    if (newLink == 0)
    {
		std::cerr << "** TQueue error: unable to allocate memory for Push()" << std::endl;
		exit(EXIT_FAILURE);
    }

    if (lastLink_ == 0)
      firstLink_ = newLink;
    else
      lastLink_->nextLink_ = newLink;

    lastLink_ = newLink;
  }

  template < typename T >
  T TQueue<T>::Pop()
  {
    Link* tempLink;
    T element;

    if (Empty())
    {
      std::cerr << "** TQueue error: Pop() called on Empty Queue" << std::endl;
      exit(EXIT_FAILURE);
    }

    tempLink = firstLink_;
    element = tempLink->element_;
    firstLink_ = firstLink_->nextLink_;

    if (firstLink_ == 0)
      lastLink_ = 0;

    delete tempLink;
    return element;
  }

  template < typename T >
  T& TQueue<T>::Front()
  {
    if (Empty())
    {
      std::cerr << "** TQueue error: Front() called on Empty Queue" << std::endl;
      exit(EXIT_FAILURE);
    }

    return firstLink_->element_;
  }

  template < typename T >
  const T& TQueue<T>::Front() const
  {
    if (Empty())
    {
      std::cerr << "** TQueue error: Front() called on Empty Queue" << std::endl;
      exit(EXIT_FAILURE);
    }

    return firstLink_->element_;
  }

  template < typename T >
  size_t TQueue<T>::Size() const
  {
    Link* linkPtr = firstLink_;
    size_t size = 0;

    while (linkPtr != 0)
    {
      size++;
      linkPtr = linkPtr->nextLink_;
    }

    return size;
  }

  template < typename T >
  int TQueue<T>::Empty() const
  {
    if (firstLink_ == 0)
      return 1;
    else
      return 0;
  }

  template < typename T >
  void TQueue<T>::Clear()
  {
    Link* tempLink;

    while (firstLink_ != 0)
    {
      tempLink = firstLink_;
      firstLink_ = firstLink_->nextLink_;
      delete tempLink;
    }

    lastLink_ = 0;
  }

  template < typename T >
  void TQueue<T>::Display(std::ostream& os, char ofc) const
  {
    Link *linkPtr = firstLink_;

    if (ofc == '\0')
      while (linkPtr != 0)
      {
        os << linkPtr->element_;
        linkPtr = linkPtr->nextLink_;
      }
    else
      while (linkPtr != 0)
      {
        os << linkPtr->element_ << ofc;
        linkPtr = linkPtr->nextLink_;
      }
  }
}

#endif
