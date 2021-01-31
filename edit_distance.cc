#include<iostream>
#include<string>

using std::string;

int MinOfThree (int n1, int n2, int n3) {
  int min = n1 < n2 ? n1 : n2;
  min = min < n3 ? min : n3;
  return min;
}

int EditDistance(const string src_str, const string dst_str){
  int src_len = src_str.size();
  int dst_len = dst_str.size();
  std::cout << "src_str: " << src_str << ", dst_str: " << dst_str << std::endl;
  std::cout << "src_len: " << src_len << ", dst_len: " << dst_len << std::endl;
  
  if (src_len == 0) return dst_len;
  if (dst_len == 0) return src_len;

  int distance = 0;
  // for(int i=src_len; i>0; i--) {
  //   for (int j=dst_len; j>0; j--) {
      int cost = src_str[src_len-1] == dst_str[dst_len-1] ? 0 : 1;
      distance = MinOfThree(EditDistance(src_str.substr(0, src_len-1), dst_str)+1,
                            EditDistance(src_str, dst_str.substr(0, dst_len-1))+1,
			    EditDistance(src_str.substr(0, src_len-1), dst_str.substr(0, dst_len-1))+cost);
  //   }
  // }
  return distance;
}

int main() {
  string src_str = "apple";
  string dst_str = "pplll";
  std::cout << "edit_distance between appl and apply is: " << EditDistance(src_str, dst_str) << std::endl;
}
