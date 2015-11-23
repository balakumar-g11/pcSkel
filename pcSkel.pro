INCLUDEPATH += /usr/include/pcl-1.7
INCLUDEPATH += /usr/include/eigen3
INCLUDEPATH += /usr/include/vtk-5.10

LIBS += \
    -lboost_system \
    -lboost_thread \
    -lpcl \
    -lpcl_common \
    -lpcl_io \
    -lpcl_visualization \
    -lvtkCommon \
    -lvtkFiltering \
    -lvtkRendering

SOURCES += \
    main.cpp \
    filereader.cpp \
    visualizer.cpp

HEADERS += \
    filereader.hpp \
    visualizer.hpp
