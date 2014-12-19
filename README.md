filter-10.2-backport
====================

Backport of the NSCLDAQ 11.0 Filter Framework for 10.2 data.

To build this software, the user should execute the following operations.

1. Execute the autoreconf to build the configure script
  % autoreconf -i

2. Execute the configure script. The user should provide the proper prefix to compile with.
  
  % ./configure --prefix=/path/to/install

3. Make the package by providing in the CPPFLAGS the proper include directory to a 10.2-xxx installation. 
   For example if the current installation of NSCDLAQ 10.2-xxx is /usr/opt/nscldaq/10.2-xxx, then you would want to build as
   
   % make CPPFLAGS="-I/usr/opt/nscldaq/10.2-xxx/include"

4. Install by executing:
  
  % make install


