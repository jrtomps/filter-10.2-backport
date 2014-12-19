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

#include <CMediatorException.h>


CMediatorException::CMediatorException(std::string reason)
  : CException("Mediator"),
  m_reason(reason)
{}

CMediatorException::CMediatorException(std::string context, std::string reason)
  : CException(context),
  m_reason(reason)
{}


const char* CMediatorException::ReasonText() const
{
  return m_reason.c_str();
}
