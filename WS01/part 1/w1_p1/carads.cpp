#include <iostream>
#include "carads.h"
using namespace sdds;
using namespace std;
void sdds::listArgs(int argc, char* argv[])
{
   cout << "Command Line:" << endl;
   cout << "--------------------------" << endl;
   for (int i{ 0 }; i < argc; i++)
      cout << "  " << i + 1 << ": " << argv[i] << endl;
   cout << "--------------------------" << endl << endl;
}
Cars::Cars()
{

}
istream& Cars::read(std::istream& is)
{
   if (!is.bad())
   {
      //<Order Tag>,<Car Brand>,<Car Model>,<Year>,<Price>,<Discount status>
      is.get(car_status);
      is.ignore(1000, ',');
      is.clear();
      is.getline(car_brand, 11, ',');
      is.getline(car_model, 16, ',');
      is >> car_year;
      is.ignore(1000, ',');
      is >> car_price;
      is.ignore(1000, ',');
      is.get() == 'Y' ? car_promo = true : car_promo = false;
      is.ignore(1000, '\n');
   }
   return is;
}

ostream& Cars::display(bool reset)
{
   static int counter{};
   if (reset)
      counter = 0;
   if (car_brand[0] != '\0')
   {
      cout.setf(ios::left);
      cout.width(2);
      cout << ++counter << ". ";
      cout.width(10);
      cout << car_brand << "| ";
      cout.width(15);
      cout << car_model << "| ";
      cout << car_year << " |";
      cout.setf(ios::fixed);
      cout.precision(2);
      cout.setf(ios::right);
      cout.width(12);
      cout << car_price + (car_price * g_taxrate) << "|";
      if (car_promo)
      {
         cout.width(12);
         cout << (car_price + (car_price * g_taxrate)) - ((car_price + (car_price * g_taxrate)) * g_discount);
      }
      cout.unsetf(ios::right);
      cout << "\n";
   }
   return cout;
}
char Cars::getStatus()
{
   return car_status;
}
//COUNTER.Brand | Model | Year | Price w / Tax | Special Price

