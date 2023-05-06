#include <cstdlib>
#include <iostream>

#include "BSTree.hpp"

int main(int argc, char** argv)
{
  BSTree<int> tree;
  for(int i = 0; i != 10; ++i) 
  { 
    tree.insert(std::rand(), tree.getRoot()); 
  }
  tree.print(tree.getRoot());
  system("pause");
}
