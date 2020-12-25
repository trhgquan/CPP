/**
 * Implementing a Heap Structure using vector,
 * Winter 2020.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<iostream>
#include<vector>

using namespace std;

template<class T>
class heap {
private:
  vector<T>* array;
  bool isMaxHeap;

  bool compare(T x, T y) {
    return ((isMaxHeap) ? (x > y) : (x < y));
  }
  int getParent(int position) {
    return (position - 1) / 2;
  }
  int getLeftChild(int position) {
    return 2 * position + 1;
  }
  int getRightChild(int position) {
    return this->getLeftChild(position) + 1;
  }
  void upHeap() {
    int thisPosition = this->array->size() - 1;

    while (thisPosition > 0) {
      int parentPosition = this->getParent(thisPosition);

      if (this->compare(this->array->at(thisPosition), this->array->at(parentPosition))) {
        swap(this->array->at(thisPosition), this->array->at(parentPosition));
        thisPosition = parentPosition;
      } else break;
    }
  }
  void downHeap(int index) {
    int leftPosition = this->getLeftChild(index);
    int rightPosition = this->getRightChild(index);

    int largest = index;

    if (leftPosition < (int)this->array->size() &&
        this->compare(this->array->at(leftPosition), this->array->at(largest)))
        largest = leftPosition;
    if (rightPosition < (int)this->array->size() &&
        this->compare(this->array->at(rightPosition), this->array->at(largest)))
        largest = rightPosition;

    if (largest != index) {
      swap(this->array->at(index), this->array->at(largest));
      downHeap(largest);
    }
  }

public:
  heap(bool isMaxHeap = true) {
    this->array = new vector<T>();
    this->isMaxHeap = isMaxHeap;
  }
  ~heap() {
    delete this->array;
  }
  T remove() {
    swap(this->array->back(), this->array->front());
    T result = this->array->back();
    this->array->pop_back();

    downHeap(0);

    return result;
  }
  T max() {
    return this->array->front();
  }
  void insert(T value) {
    this->array->push_back(value);
    upHeap();
  }
  void print() {
    for (int i = 0; i < (int)this->array->size(); ++i) cout << this->array->at(i) << ' ';
    cout << endl;
  }
};

int main() {
  freopen("priority.txt", "r+", stdin);
  heap<int>* h = new heap<int>();

  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int u; cin >> u;
    h->insert(u);
  }

  h->print();

  cout << "Max: " << h->max() << endl;
  cout << "Removing max.." << endl;
  h->remove(); h->print();
  cout << "Max: " << h->max() << endl;
  cout << "Removing max.." << endl;
  h->remove(); h->print();

  delete h;

  return 0;
}
