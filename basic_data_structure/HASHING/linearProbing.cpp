/**
 * Linear Probing hash, implemented during CS104
 * Winter 2020.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class linearProbingHashTable {
private:
  vector<int>* table;
  vector<int>* shuffled;
  int size;
  bool isRandomShuffled;

  bool canInsert(int index) {
    return table->at(index) == -1;
  }

  void linearProbingInsert(int value) {
    int index = value % this->size;

    if (this->canInsert(index)) this->table->at(index) = value;
    else {
      bool inserted = false;
      for (; index < (int)this->size; ++index) {
        if (this->canInsert(index)) {
          this->table->at(index) = value;
          inserted = true;
          break;
        }
      }

      if (!inserted) {
        for (index = 0; index < (int)this->size; ++index) {
          if (this->canInsert(index)) {
            this->table->at(index) = value;
            inserted = true;
            break;
          }
        }
      }
    }
  }

  void randomLinearProblingInsert(int value) {
    int index = value % this->size;

    if (this->canInsert(index)) this->table->at(index) = value;
    else {
      for (int i = 0; i < this->size; ++i) {
        index = (index + this->shuffled->at(i)) % this->size;

        if (this->canInsert(index)) {
          this->table->at(index) = value;
          break;
        }
      }
    }
  }

public:
  linearProbingHashTable(int size, bool isRandomShuffled) {
    this->size = size;
    this->isRandomShuffled = isRandomShuffled;
    table = new vector<int>(size, -1);
    shuffled = new vector<int>(size, 0);

    if (this->isRandomShuffled) {
      for (int i = 0; i < size; ++i) shuffled->at(i) = i;
      random_shuffle(shuffled->begin(), shuffled->end());
    }
  }

  void insert(int value) {
    if (this->isRandomShuffled) this->randomLinearProblingInsert(value);
    else this->linearProbingInsert(value);
  }

  void print() {
    for (int i = 0; i < this->size; ++i) cout << this->table->at(i) << ' ';
    cout << endl;
  }
};

int main() {
  freopen("values.txt", "r+", stdin);
  freopen("linear.txt", "w+", stdout);

  int m, n; cin >> m >> n;

  linearProbingHashTable* hash = new linearProbingHashTable(m, 1);
  for (int i = 1; i <= n; ++i) {
    int u; cin >> u;
    hash->insert(u);
  }

  hash->print();

  delete hash;

  return 0;
}
