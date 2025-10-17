target_sources(shotup PRIVATE
    shotup.h
    shotupdaemon.h
    qguiappcurrentscreen.h
)

target_sources(shotup PRIVATE
    capturerequest.cpp
    shotup.cpp
    shotupdaemon.cpp
    qguiappcurrentscreen.cpp
)

if (UNIX AND NOT APPLE)
target_sources(shotup PRIVATE
    shotupdbusadapter.h
    shotupdbusadapter.cpp
)
endif ()

if (USE_KDSINGLEAPPLICATION)
if (NOT WIN32)
target_sources(shotup PRIVATE
    signaldaemon.h
    signaldaemon.cpp
)
endif ()
endif ()

if (WIN32)
    target_sources(shotup PRIVATE globalshortcutfilter.h globalshortcutfilter.cpp)
endif ()
