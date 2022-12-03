#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
   GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
      GeneratingList<EmployeeWage> activeEmp;
      const std::string err = "*** Employees salaray range is not valid";
      // TODO: Add your code here to build a list of employees
      //         using raw pointers
      for (size_t i = 0; i < emp.size(); i++)
      {
         for (size_t j = 0; j < sal.size(); j++)
         {
            if (emp[i].id == sal[j].id)
            {
               EmployeeWage* temp = new EmployeeWage(emp[i].id, sal[j].salary);
               temp->name = emp[i].name;
               try
               {
                  temp->rangeValidator();
               }
               catch (...)
               {
                  delete temp;
                  temp = nullptr;
               }
               if (activeEmp.validSin(sal[j].id) && temp)
               {
                  activeEmp += temp;
                  delete temp;
               }
               else
               {
                  delete temp;
                  throw(err);
               }
            }
         }
      }
      return activeEmp;
   }


   GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
      GeneratingList<EmployeeWage> activeEmp;
      // TODO: Add your code here to build a list of employees
      //         using smart pointers
      const std::string err = "*** Employees salaray range is not valid";
      for (size_t i = 0; i < emp.size(); i++)
      {
         for (size_t j = 0; j < sal.size(); j++)
         {
            if (emp[i].id == sal[j].id)
            {
               std::unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].id, sal[j].salary));
               temp->name = emp[i].name;
               try
               {
                  temp->rangeValidator();
               }
               catch (...)
               {
                  temp = nullptr;
               }
               if (activeEmp.validSin(sal[j].id) && temp)
                  activeEmp += temp;
               else
                  throw(err);
            }
         }
      }
      return activeEmp;
   }
}