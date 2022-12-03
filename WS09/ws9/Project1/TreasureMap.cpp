// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

// Francis Lloyd Colendres
// Workshop 9
// November 27, 2022
// OOP-345

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include <future>
#include "TreasureMap.h"

namespace sdds {

   size_t digForTreasure(const std::string& str, char mark) {
      size_t cnt = 0;
      for (auto& x : str) {
         if (x == mark) {
            cnt++;
         }
      }
      return cnt;
   }

   TreasureMap::TreasureMap(const char* filename) {
      std::fstream fin(filename);
      if (fin) {
         fin >> rows;
         fin.ignore();
         map = new std::string[rows];
         size_t idx = 0;
         while (fin) {
            getline(fin, map[idx]);
            idx++;
         }
         colSize = map[0].length();
      }
      else {
         throw std::string(filename) + " cannot be opened";
      }
   }

   TreasureMap::~TreasureMap() {
      delete[] map;
   }

   std::ostream& TreasureMap::display(std::ostream& os) const {
      if (map) {
         for (size_t i = 0; i < rows; ++i) {
            os << map[i] << std::endl;
         }
      }
      else
         os << "The map is empty!" << std::endl;
      return os;
   }

   void TreasureMap::enscribe(const char* filename) {
      // Binary write
      if (map) {
         // TODO: Open a binary file stream to the filename and
         //         then write the row number to the binary file 
         //         then each of the rows of the map.
         //       If the file cannot be open, raise an exception to
         //         inform the client.
         std::ofstream outbinfile(filename, std::ios::binary);
         outbinfile.write((char*)&rows, sizeof(size_t));
         outbinfile.write((char*)&colSize, sizeof(size_t));
         for (auto i = 0u; i < rows; ++i)
         {
            outbinfile.write(map[i].c_str(), map[i].length());
         }
         // END TODO
      }
      else {
         throw std::string("Treasure map is empty!");
      }
   }

   void TreasureMap::recall(const char* filename) {
      // Binary read
      // TODO: Open a binary file stream to the filename
      //         and read from it to populate the current object.
      //       The first 4 bytes of the file will be the number of rows
      //         for the map followed another 4 bytes for the colSize
      //         of each row in the map.
      //       Afterwards is each row of the map itself.
      //       If the file cannot be open, raise an exception to inform
      //         the client.
      std::ifstream inbinfile(filename, std::ios::binary);
      if (!inbinfile) { throw("Cannot open file."); };
      inbinfile.read((char*)&rows, sizeof(size_t));
      inbinfile.read((char*)&colSize, sizeof(size_t));
      delete[] map;
      map = new std::string[rows];
      for (auto i = 0u; i < rows; ++i)
      {
         map[i].resize(colSize);
         inbinfile.read((char*)&map[i][0], colSize);
      }

      // END TODO
   }

   void TreasureMap::clear() {
      delete[] map;
      map = nullptr;
      rows = 0;
      colSize = 0;
   }

   size_t TreasureMap::findTreasure(char mark) {
      size_t count = 0;
      // TODO: For part 2, comment this "for" loop and write the multihreaded version.
      //for (size_t i = 0; i < rows; ++i) {
      //   count += digForTreasure(map[i], mark);
      //}
      std::string str1;
      std::string str2;
      std::string str3;
      std::string str4;
      for (size_t i = 0; i <= rows; ++i) // divide the map into 4 separate strings.
      {
         switch (i)
         {
         case 0:
            for (size_t j = i, k = 0; k < (rows / 4); ++j, ++k)
            {
               str1 += map[j];
               i = j;
            }
            break;
         case 2:
            for (size_t j = i, k = 0; k < (rows / 4); ++j, ++k)
            {
               str2 += map[j];
               i = j;
            }
            break;
         case 4:
            for (size_t j = i, k = 0; k < (rows / 4); ++j, ++k)
            {
               str3 += map[j];
               i = j;
            }
            break;
         case 7:
            for (size_t j = i, k = 0; k < (rows / 4); ++j, ++k)
            {
               str4 += map[j];
               i = j;
            }
            break;
         }
      }

      // Create a bind function for dig for treasure
      //auto bound_foo = bind(foo, placeholders::_1, 5)
      auto b1 = std::bind(digForTreasure, str1, mark);
      auto b2 = std::bind(digForTreasure, str2, mark);
      auto b3 = std::bind(digForTreasure, str3, mark);
      auto b4 = std::bind(digForTreasure, str4, mark);
      // Create packaged task with the bound function inside.
      //packaged_task<int(const string&) pt2(bound_foo); // correct
      std::packaged_task<size_t(const std::string&)> pt1(b1);
      std::packaged_task<size_t(const std::string&)> pt2(b2);
      std::packaged_task<size_t(const std::string&)> pt3(b3);
      std::packaged_task<size_t(const std::string&)> pt4(b4);
      // Associate the packaged task with futures
      auto f1 = pt1.get_future();
      auto f2 = pt2.get_future();
      auto f3 = pt3.get_future();
      auto f4 = pt4.get_future();
      std::thread t1(std::move(pt1), str1);
      std::thread t2(std::move(pt2), str2);
      std::thread t3(std::move(pt3), str3);
      std::thread t4(std::move(pt4), str4);
      count = f1.get() + f2.get() + f3.get() + f4.get();
      t1.join();
      t2.join();
      t3.join();
      t4.join();
      return count;
   }
}