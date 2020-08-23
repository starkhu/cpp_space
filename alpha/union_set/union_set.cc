#include <iostream>

class UnionSet {
 public:
  UnionSet(const int& len): len_(len) {}
  ~UnionSet () {
   if (union_set_ != nullptr) {
     delete [] union_set_;
     union_set_ = nullptr;
   }
  }

  void  makeSet() {
     union_set_ = new int[len_];
     for (int i = 0; i < len_; i++) {
       union_set_[i] = i;
     }
  }
  
  void union_op(int x, int y) {
    //TODO(check)
    if (std::max(x, y) > len_-1) {
       std::cout << "input is invalid" << std::endl;
    }  
    if (union_set_[x] != union_set_[y]) {
      union_set_[y] = union_set_[x];
    }
  }
  
  int find_op(int target) {
    // TODO(check)
    int father = union_set_[target];
    if (father == target)
      return target;
    while (father != union_set_[father]) {
     father = union_set_[father];
    }
    return father;
  }

  int find1_op(int target) {
    // TODO(check)
    int father = union_set_[target];
    if (father == target)
      return target;
    return find1_op(father);
  }

  int find2_op(int target) {
    // TODO(check)
    int father = union_set_[target];
    if (father == target)
      return target;
    return union_set_[father] = find2_op(father);
  }

  int num_unicom() {
    int num_unicom = 0;
    for (int i = 0; i < len_; i++) {
      if (union_set_[i] == i) {
        num_unicom++;
      }
    }
    return num_unicom;
  }

 private:
  const int& len_;
  int* union_set_;
};

int main() {
   const int num_village = 5;
   const int num_path = 3;
   int path[num_path][2] = {{0,1}, {2,3}, {1,4}};
   
   UnionSet u_set(num_village);
   u_set.makeSet();
   
   for (int i = 0; i < num_path; i++) {
     u_set.union_op(path[i][0], path[i][1]);
   }

   for (int i = 0; i < num_village; i++) {
     std::cout << "the root of village " << i << " is: "
               << u_set.find_op(i) << std::endl;
     std::cout << "the root of village " << i << " is: "
               << u_set.find1_op(i) << std::endl;
     std::cout << "the root of village " << i << " is: "
               << u_set.find2_op(i) << std::endl;
   }

   // num of unicom component
   std::cout << "num of unicom component is: " << u_set.num_unicom() << std::endl;

   return 0;
}
