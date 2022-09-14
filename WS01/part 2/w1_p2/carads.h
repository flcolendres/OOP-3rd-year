#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>
extern double g_taxrate;
extern double g_discount;
namespace sdds
{
   class Cars
   {
      char* car_brand{};
      char* car_model{};
      unsigned int car_year{};
      double car_price{};
      char car_status{};
      bool car_promo{};
   public:
      operator bool() const;
      Cars();
      Cars& operator=(const Cars& c);
      ~Cars();
      std::istream& read(std::istream& is);
      std::ostream& display(bool reset);
      char getStatus();
   };
   void listArgs(int argc, char* argv[]);
   extern std::istream& operator>>(std::istream& is, Cars& car);
   extern void operator>>(const Cars& car1, Cars& car2);
}
#endif