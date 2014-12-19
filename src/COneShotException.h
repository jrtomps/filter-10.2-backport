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

#ifndef CONESHOTEXCEPTION_H
#define CONESHOTEXCEPTION_H

#include <Exception.h>

/**! An exception for OneShotHandler errors
*
* This class will be thrown by the COneShotHandler to recognize
* that an invalid or erroneous state change update is occurring.
* It derives from CException to make it catchable by any exception
* handler that is looking to find any nscldaq-type exception. 
*/
class COneShotException : public CException
{
  private:
    std::string m_reason;  
    std::string m_context;  

  public:
    COneShotException(std::string reason);
    COneShotException(std::string context, std::string reason);

    virtual const char* ReasonText() const;
};

#endif
