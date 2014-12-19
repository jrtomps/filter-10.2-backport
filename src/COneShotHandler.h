/*
    This software is Copyright by the Board of Trustees of Michigan
    State University (c) Copyright 2014.

    You may use this software under the terms of the GNU public license
    (GPL).  The terms of this license are described at:

     http://www.gnu.org/licenses/gpl.txt

     Author:
             Jeromy Tompkins
	     NSCL
	     Michigan State University
	     East Lansing, MI 48824-1321
*/



#ifndef STATECHANGEHANDLER_H
#define STATECHANGEHANDLER_H

#include <stdint.h>
#include <map>

class CRingItem;
class CRingStateChangeItem;

class COneShotHandler 
{
  private:
  unsigned int m_nExpectedSources;
  std::map<uint32_t,uint32_t> m_stateCounts;
  uint32_t m_cachedRunNo;
  bool     m_complete;

  public:
    COneShotHandler(unsigned int ntrans);

    void initialize(CRingStateChangeItem* item);

    void update(CRingItem* item);

    bool waitingForBegin() const;
    bool complete() const;

    void reset();

    uint32_t getCount(uint32_t key) const;

  private:
    bool validType(uint32_t type) const;
    void clearCounts();
    
    void updateState(CRingStateChangeItem* item);
};
#endif
