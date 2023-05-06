#include <iostream>
#include <memory>

template <typename T>
class BSTree
{
  public:
    struct node
    {
      T data;
      std::unique_ptr<node> left;
      std::unique_ptr<node> right;
    };

    void insert(const T& data, std::unique_ptr<node>& cur);
    void print(std::unique_ptr<node>& cur);

    std::unique_ptr<BSTree<T>::node>& getRoot() { return root; }

  public:
    std::unique_ptr<node> root;
};

template <typename T>
using node = typename BSTree<T>::node;

template <typename T>
void BSTree<T>::insert(const T& data, std::unique_ptr<node>& cur)
{
  if(cur == nullptr)
    cur = std::move( std::unique_ptr<node>( new node{ data, nullptr, nullptr } ) );
  else if(data < cur->data)  
    insert(data, cur->left);
  else if(data > cur->data) 
    insert(data, cur->right);


    // cur-> left.reset(insert(data, cur->left ).release());
    // cur->right.reset(insert(data, cur->right).release());
  // return cur;
}

template <typename T>
void BSTree<T>::print(std::unique_ptr<node>& cur)
{
  if(cur != nullptr)
  {
    print(cur->left);
    std::cout << cur->data << std::endl;
    print(cur->right);
  }
}
