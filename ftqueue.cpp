/*
   ftqueue.cpp
*/

#include <iostream>
#include <tqueue.h>

typedef char ValueType;
const char* vT = "char";
const char ofc = ',';

void DisplayMenu();

template < typename T >
void CopyTest(fsu::TQueue<T> q)
{
  std::cout << "CopyTest:" << std::endl;
  std::cout << "Copied object   size: " << q.Size() << std::endl;
  std::cout << "            contents: " << q << std::endl;
}

template < typename T >
void AssignTest(const fsu::TQueue<T>& q)
{
  fsu::TQueue<T> q1;
  q1 = q;
  std::cout << "AssignTest:" << std::endl;
  std::cout << "Original object size: " << q.Size() << std::endl;
  std::cout << "            contents: " << q << std::endl;
  std::cout << "Assignee object size: " << q1.Size() << std::endl;
  std::cout << "            contents: " << q1 << std::endl;
}

int main()
{
  fsu::TQueue<ValueType> q;
  ValueType Tval;
  char option;

  std::cout << "This is a TQueue < " << vT << " > test program" << std::endl;
  DisplayMenu();

  do
  {
    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
    std::cin >> option;

    switch (option)
    {
    case '+':
      std::cin >> Tval;
      q.Push(Tval);
      break;
    case '-':
      if (!q.Empty())
        q.Pop();
      else
        std::cout << "Queue is empty" << std::endl;
      break;
    case 'c': case 'C':
      q.Clear();
      break;
    case 'f': case 'F':
      if (!q.Empty())
        std::cout << "Front of Queue: " << q.Front() << std::endl;
      else
        std::cout << "Queue is empty" << std::endl;
      break;
    case 'e': case 'E':
      std::cout << "Queue is ";
      if (!q.Empty())
        std::cout << "not ";
      std::cout << "empty" << std::endl;
      break;
    case 's': case 'S':
      std::cout << "Queue size     = " << q.Size() << std::endl;
      break;
    case '=':
      CopyTest(q);
      AssignTest(q);
      break;
    case 'd': case 'D':
      std::cout << "Queue contents:   " << q << std::endl;
      break;
    case 'm': case 'M':
      DisplayMenu();
      break;
    case 'q': case 'Q':
      break;
    default:
      std::cout << "** Unrecognized command -- please try again." << std::endl;
    }

  } while (option != 'q' && option != 'Q');

  std::cout << std::endl;
  std::cout << "Have a nice day." << std::endl;
  return 0;
}

void DisplayMenu()
{
  std::cout << "Push(Tval)  .............  +" << std::endl;
  std::cout << "Pop()  ..................  -" << std::endl;
  std::cout << "Clear()  ................  C" << std::endl;
  std::cout << "Front()  ................  F" << std::endl;
  std::cout << "Empty()  ................  E" << std::endl;
  std::cout << "Size()  .................  S" << std::endl;
  std::cout << "assign & copy test  .....  =" << std::endl;
  std::cout << "Display entire queue  ...  D" << std::endl;
  std::cout << "Display this menu  ......  M" << std::endl;
}
