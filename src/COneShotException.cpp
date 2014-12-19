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

#include <COneShotException.h>


COneShotException::COneShotException(std::string reason)
  : CException("OneShot"),
  m_reason(reason)
{}

COneShotException::COneShotException(std::string context, std::string reason)
  : CException(context),
  m_reason(reason)
{}


const char* COneShotException::ReasonText() const
{
  return m_reason.c_str();
}
