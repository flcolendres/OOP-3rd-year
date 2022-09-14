#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>
extern double g_taxrate;
extern double g_discount;
namespace sdds 
{
   class Cars 
   {
      char car_brand[11]{};
      char car_model[16]{};
      unsigned int car_year{};
      double car_price{};
      char car_status{};
      bool car_promo{};
   public:
      Cars();
      std::istream& read(std::istream& is);
      std::ostream& display(bool reset);
      char getStatus();
   };
   void listArgs(int argc, char* argv[]);
}
#endif