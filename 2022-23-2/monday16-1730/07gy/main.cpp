#include <iostream>

class vector
{
public:
  vector()
  {
    _capacity = 1;
    _size = 0;
    _items = new int[1];
  }

  vector(const vector& other)
  {
    _items = new int[other._capacity];
    _size = other._size;
    _capacity = other._capacity;

    for (int i = 0; i < _size; ++i)
      _items[i] = other._items[i];
  }

  ~vector()
  {
    delete[] _items;
  }

  int capacity() { return _capacity; }
  int size() { return _size; }

  void push_back(int item)
  {
    if (_size == _capacity)
    {
      int* newItems = new int[2 * _capacity];

      for (int i = 0; i < _size; ++i)
        newItems[i] = _items[i];

      _capacity *= 2;
      delete[] _items;
      _items = newItems;
    }

    _items[_size] = item;
    ++_size;
  }

  int at(int idx) { return _items[idx]; }
  int operator[](int idx) { return _items[idx]; }
  
  vector& operator=(const vector& other)
  {
    delete[] _items;
    _items = new int[other._capacity];
    _size = other._size;
    _capacity = other._capacity;

    for (int i = 0; i < _size; ++i)
      _items[i] = other._items[i];

    return *this;
  }

private:
  int _capacity;
  int _size;
  int* _items;
};

void print(const vector& x)
{
  // x.push_back(42);
  for (int i = 0; i < x.size(); ++i)
    std::cout << x[i] << std::endl;
}

void print(const int& x) { std::cout << x; }

int main()
{
  int a, b, c;
  vector v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << std::endl;

  std::cout << "Kapacitás: " << v.capacity() << std::endl;
}
