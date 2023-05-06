#include <memory>
#include <utility>

template <typename T>
class list
{
  public:
    struct node
    {
      std::unique_ptr<node> next;
      T data;
    };

    list() = default;
    ~list();

    void insert(const T& data) 
    {
      head = std::unique_ptr<node>( new node { std::move(head), data } );
    }
    // void insert(const T& data) { head = std::unique_ptr<node>(data, std::move(head)); }
    T front() { return head->data; }

  private:
    std::unique_ptr<node> head;
};

template <typename T>
list<T>::~list()
{
  // head = std::move(head->next);
  // <==>head.reset(head->next.release());
  while(head)
  {
    auto next = std::move(head->next);
    head = std::move(next);
  }
}
