#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

template <typename It, typename T>
It find(It b, It e, const T& t)
{
  while (b != e)
  {
    if (*b == t)
      return b;

    ++b;
  }

  return b;
}

template <typename Cont, typename T>
typename Cont::const_iterator find(const Cont& v, const T& s)
{
  for (typename Cont::const_iterator p = v.begin(); p != v.end(); ++p)
    if (*p == s)
      return p;

  return v.end();
/*
  for (int i = 0; i < v.size(); ++i)
    if (v[i] == s)
      return &v[i];

  return NULL;
*/
}

bool beginsWithI(const std::string& s)
{
  return !s.empty() && s[0] == 'i';
}

int main()
{
  std::list<std::string> words;

  std::ifstream file("main.cpp");

  std::string word;
  while (file >> word)
    if (std::find(words.begin(), words.end(), word) == words.end())
      words.push_back(word);

  file.close();

  std::cout << "Az egyedi szavak száma: " << words.size() << std::endl;

  std::list<std::string>::iterator it =
    std::find_if(words.begin(), words.end(), beginsWithI);
}
