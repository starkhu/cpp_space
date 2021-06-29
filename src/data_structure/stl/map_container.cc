#include<iostream>
#include<map>
#include<string>
#include<unordered_map>


struct stud {
  int id_;
  std::string name_;
  stud(int id, std::string name) {
    id_ = id;
    name_ = name;
  }
  bool operator==(stud& right_stud) {
    if (this->id_ == right_stud.id_ && this->name_ == right_stud.name_)
      return true;
    return false;
  }
};


template<typename T1, typename T2, typename T3>
void insertOp(T1& map_container, T2 key, T3 value) {
  auto ret = map_container.insert(std::make_pair(key, value));
  if (!ret.second) {
    std::cout << "insert operation is failed." << std::endl;
  } else {
    std::cout << "insert operation succeed." << std::endl;
  }
  std::cout << "first is " << ret.first->first << std::endl;
}

template<typename T1, typename T2, typename T3>
void searchValueOp (T1& map_container, T2 key, T3 value) {
   typename T1::iterator iter;
  for (iter = map_container.begin(); iter != map_container.end(); iter++) {
    if ( value == iter->second)
    std::cout << "found!!!!"<< std::endl;
  } 
}

void mapContainer() {
  std::map<int, stud> stud_list;
  insertOp(stud_list, 1, stud(1, "mike"));
  insertOp(stud_list, 2, stud(2, "jack"));
  stud_list.emplace(3, stud(3, "pony"));
  searchValueOp(stud_list, 1, stud(1, "mike"));
}

void unorderedMap() {
  std::map<int, stud> stud_list;
  insertOp(stud_list, 1, stud(1, "mike"));
  insertOp(stud_list, 2, stud(2, "jack"));
  // stud_list.emplace(stud_list, 3, 3, "pony");
  searchValueOp(stud_list, 1, stud(1, "mike"));
}

int map_container() {
  mapContainer();
  unorderedMap();
  return 0;
}
