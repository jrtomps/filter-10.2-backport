#include "CFileDataSink.h"
#include <CRingItem.h>
#include <DataFormat.h>
#include <io.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <iostream>

/**! Construct from a file descriptor
* Ownership of this file descriptor is transferred to the
* this object. Write operations on the file descriptor must 
* be permissible or an exception is thrown.
*
* \param a file descriptor to define the sink
* \throw std::string
*/
CFileDataSink::CFileDataSink(int fd)
    : m_fd(fd)
{
  if (!isWritable()) {
    throw std::string("CFileDataSink::CFileDataSink(int) file descriptor is not write only");
  }

}


/**! Construct from a file name
* Obtains a file descriptor given a valid pathname. If file doesn't exist
* a new file is opened with RDWR permissions. If the file 
* doesn't exist, it is created with read/write permissions. 
*
* \param a file descriptor to define the sink
*
* \throw int on failure opening file
* \throw std::string if file is not writable
*/
CFileDataSink::CFileDataSink(std::string fname)
    : m_fd(-1)
{

  // Open or create if the file doesn't exist
  m_fd = open(fname.c_str(),O_RDWR | O_CREAT, S_IRUSR | S_IWUSR );
  // check to see if failed
  if (m_fd==-1) {
    std::string errmsg("CFileDataSink::CFileDataSink(std::string)");
    errmsg += " failed to open file ";
    errmsg += fname;
    throw CErrnoException(errmsg);
  }

  if (!isWritable()) {
    throw std::string("CFileDataSink::CFileDataSink(std::string) file descriptor is not write only");
  }
  
}

/**! Close file
* 
* If the file descriptor does not refer to STDOUT_FILENO and
* and it points to a valid file, then close it.
*
* 
*/
CFileDataSink::~CFileDataSink()
{

  // Can't close stdout
  if (m_fd!=STDOUT_FILENO && m_fd>0) {
    close(m_fd);

  }

}


/**! Write ring item to the sink
*
* Writes the data to the file. This delegates the writing to
* a static function io::writeData(int,void*,int).
*
* \param item refers to a CRingItem that contains the data
*
*
* \throw CErrnoException when io failure
*
*/
void CFileDataSink::putItem(const CRingItem& item)
{
    // Get the underlying structure containing the state 
    const RingItem* pItem = const_cast<CRingItem&>(item).getItemPointer();

    // Set up variable for writing it to stream
    size_t nbytes = pItem->s_header.s_size;
    const char* pBuffer = reinterpret_cast<const char*>(pItem);

    try {
        // This next function can throw an int
        io::writeData(m_fd,pBuffer,nbytes);

    } catch (int errno) {
      std::string errmsg("CFileDataSink::putItem(const CRingItem&)"); 
      errmsg += " : IO failure! ";
      errmsg += strerror(errno);
      throw CErrnoException(errmsg);
    }
}


/**! Check if write operates are allowed on file
*
* \throw CErrnoException if fcntl failed while checking
*/
bool CFileDataSink::isWritable() 
{
  // Get the status flags of the file
  int status = fcntl(m_fd,F_GETFL);

  if (status<0) {
    std::string errmsg ("CFileDataSink::isWritable()");
    errmsg += " failed checking file status flags";
    throw CErrnoException(errmsg);
  }; 

  // Check if we can write
  return ( (status&O_WRONLY)!=0 || (status&O_RDWR)!=0 );
   
}
