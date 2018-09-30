/*
   ftstack.h
*/

#include <iostream>
#include <tstack.h>

typedef char ValueType;
ValueType fill = ' ';
const size_t maxSize = 10;
const char* vT = "char";
const char ofc = ',';

void DisplayMenu();

template < typename T , size_t N >
void CopyTest(fsu::TStack<T,N> s)
{
  std::cout << "CopyTest:" << std::endl;
  std::cout << "Copied object   capacity: " << s.Capacity() << std::endl;
  std::cout << "                    size: " << s.Size() << std::endl;
  std::cout << "                contents: " << s << std::endl;
}

template < typename T , size_t N >
void AssignTest(const fsu::TStack<T,N>& s)
{
  fsu::TStack<T,N> s1;
  s1 = s;
  std::cout << "AssignTest:\n";
  std::cout << "Original object capacity: " << s.Capacity() << std::endl;
  std::cout << "                    size: " << s.Size() << std::endl;
  std::cout << "                contents: " << s << std::endl;
  std::cout << "Assignee object capacity: " << s1.Capacity() << std::endl;
  std::cout << "                    size: " << s1.Size() << std::endl;
  std::cout << "                contents: " << s1 << std::endl;
}

int main()
{
  fsu::TStack<ValueType, maxSize> s(fill);
  ValueType Tval;
  char option;

  std::cout << "This is a TStack < " << vT << " > test program" << std::endl;
  DisplayMenu();

  do
  {
    std::cout << "Enter [command][argument] ('M' for menu, 'Q' to quit): ";
    std::cin >> option;

    switch (option)
    {
    case '+':
      std::cin >> Tval;
      s.Push(Tval);
      break;
    case '-':
      if (!s.Empty())
        s.Pop();
      else
        std::cout << "Stack is empty" << std::endl;
      break;
    case 'c': case 'C':
      s.Clear();
      break;
    case 't': case 'T':
      if (!s.Empty())
        std::cout << "Top of Stack: " << s.Top() << std::endl;
      else
        std::cout << "Stack is empty" << std::endl;
      break;
    case 'e': case 'E':
      std::cout << "Stack is ";
      if (!s.Empty())
        std::cout << "not ";
      std::cout << "empty" << std::endl;
      break;
    case 's': case 'S':
      std::cout << "Stack size     = " << s.Size() << std::endl;
      std::cout << "Stack capacity = " << s.Capacity() << std::endl;
      break;
    case '=':
      CopyTest(s);
      AssignTest(s);
      break;
    case 'd': case 'D':
      std::cout << "Stack contents:   " << s << std::endl;
      break;
    case 'u': case 'U':
      s.Dump(std::cout, ofc);
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
  std::cout << "Top()  ..................  T" << std::endl;
  std::cout << "Empty()  ................  E" << std::endl;
  std::cout << "Size()  .................  S" << std::endl;
  std::cout << "assign & copy test  .....  =" << std::endl;
  std::cout << "Display entire stack  ...  D" << std::endl;
  std::cout << "Dump  ...................  U" << std::endl;
  std::cout << "Display this menu  ......  M" << std::endl;
}
