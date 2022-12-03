// Name: Francis Lloyd Colendres
// Seneca Student ID: 145498200
// Seneca email: flcolendres@myseneca.ca
// Date of completion: December 03, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Workstation.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{
   // string& file is the list of stations that are active...
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
   {
      Utilities ut;
      string fullStr, currStr, nextStr;
      size_t pos = 0;
      bool more = false;
      ifstream f(file);

      while (!f.eof())
      {
         pos = 0;
         ut.setDelimiter('|');
         getline(f, fullStr);
         currStr = ut.extractToken(fullStr, pos, more);
         ut.setDelimiter('\n');
         nextStr = ut.extractToken(fullStr, pos, more);
         for_each(stations.begin(), stations.end(), [&](Workstation* s)
            {
               if (s->getItemName() == currStr)
               {
                  m_activeLine.push_back(s);

                  for_each(stations.begin(), stations.end(), [&](Workstation* s2)
                     {
                        if (s2->getItemName() == nextStr)
                           m_activeLine[m_activeLine.size() - 1]->setNextStation(s2);
                     });
               }
            });
      }
      // search for the firstStation
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* elem)
         {
            bool valid = true;
            for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* elem2)
               {
                  if (elem == elem2->getNextStation())
                     valid = false;
               });
            if (valid)
               m_firstStation = elem;
         });
      m_cntCustomerOrder = g_pending.size();
   }
   void LineManager::reorderStations()
   {
      std::vector<Workstation*> temp_activeLine;
      temp_activeLine.push_back(m_firstStation);
      temp_activeLine.push_back(m_firstStation->getNextStation());
      for (size_t i = temp_activeLine.size() - 1; i < m_activeLine.size(); i++)
      {
         if (temp_activeLine[i]->getNextStation())
            temp_activeLine.push_back(temp_activeLine[i]->getNextStation());
      }
      m_activeLine = std::move(temp_activeLine);
   }
   bool LineManager::run(std::ostream& os)
   {
      //keeps track of the current iteration number(use a local variable)
      static size_t num = 0;
      os << "Line Manager Iteration: " << ++num << endl;
      if (!g_pending.empty())
      {
         *m_firstStation += (std::move(g_pending.front()));
         g_pending.pop_front();
      }
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {ws->fill(os); });
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {ws->attemptToMoveOrder(); });
      return m_cntCustomerOrder == (g_completed.size() + g_incomplete.size());
   }

   void LineManager::display(std::ostream& os) const
   {
      for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {ws->display(os); });
   }

}
