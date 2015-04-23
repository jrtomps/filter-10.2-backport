
lib_LTLIBRARIES = libfilter.la

libfilter_la_SOURCES = CFileDataSink.cpp \
			CRingDataSink.cpp \
			CDataSinkFactory.cpp \
			CMediator.cpp  \
			CInfiniteMediator.cpp  \
			COneShotMediator.cpp  \
			CFilterMain.cpp \
			StringsToIntegers.cpp \
  		CCompositeFilter.cpp \
			CStdinDataSource.cpp \
			COneShotHandler.cpp \
			COneShotException.cpp 

nodist_libfilter_la_SOURCES = @srcdir@/filterargs.c

include_HEADERS = CFileDataSink.h \
			CRingDataSink.h \
			CDataSinkFactory.h \
			CMediator.h  \
			CInfiniteMediator.h  \
			COneShotMediator.h  \
			CFilterMain.h \
			StringsToIntegers.h \
			CFilter.h \
  		CCompositeFilter.h \
			CStdinDataSource.h \
			COneShotHandler.h \
			COneShotException.h  \
			filterargs.h

BUILT_SOURCES = @srcdir@/filterargs.c

libfilter_la_LDFLAGS = -version-info $(SOVERSION) \
											 -Wl,"-rpath-link=$(libdir)" 

@srcdir@/filterargs.c: @srcdir@/filterargs.ggo 
	$(GENGETOPT) < @srcdir@/filterargs.ggo \
		--output-dir=@srcdir@ --file=filterargs --unamed-opts="OPTIONS"

