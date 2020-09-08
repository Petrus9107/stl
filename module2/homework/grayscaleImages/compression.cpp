#include "compression.hpp"
#include <algorithm>
#include <iostream>

#include <iterator>


namespace std {
  template <class T1, class T2>
    std::ostream& operator<<(std::ostream& out, const std::pair< T1, T2>& rhs)
    {
      out << "{" << static_cast<int>(rhs.first) << ", " << static_cast<int>(rhs.second) <<"} ";
      return out;
    }
}


compressed_bitmap compressGrayscale(bitmap& bitmap) {

  compressed_bitmap res;
  // //for
  // for (const auto& el : bitmap) {
  //   for (auto it = el.begin(), e = el.end(); it != e;) {
  //     const auto it2 =
  //         std::find_if(it, e, [&](const auto& x) { return x != *it; });
  //     res.emplace_back(*it, std::distance(it, it2));
  //     it = it2;
  //   }
  // }

  // return res;

  std::transform(bitmap.begin(), bitmap.end(), std::back_inserter(res), [&](std::array<uint8_t, width>& arr)
  {
    const auto it = std::find_if(arr.begin(), arr.end(), [](const auto& x) {return ;}); 
    return std::count(arr.begin(), arr.end(), )

  }
 );

  return res;


}

bitmap decompressGrayscale(const compressed_bitmap& map){

    bitmap tmpMap;
    auto it = tmpMap.front().begin();
//for
    for (auto& el : map){
        std::fill_n(it, el.second, el.first);
        std::advance(it, el.second);
    }
    return tmpMap;
}

void printCompressedVector(const compressed_bitmap& map) {
  std::copy(begin(map), end(map), std::ostream_iterator<std::pair<uint8_t,uint8_t>>(std::cout, " ")); 
  std::cout << "\n";
}

void printMap(const bitmap& map) {
  //copy
  for (const auto& el : map) {
      for (const auto&e :el){
        isprint(e) ? std::cout << e : std::cout << " ";
      }
    std::cout << "\n";
  }
}
