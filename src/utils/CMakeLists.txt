# Required to generate MOC
target_sources(
  shotup
  PRIVATE abstractlogger.h
          filenamehandler.h
          screengrabber.h
          systemnotification.h
          valuehandler.h
          strfparse.h
)

target_sources(
  shotup
  PRIVATE abstractlogger.cpp
          filenamehandler.cpp
          screengrabber.cpp
          confighandler.cpp
          systemnotification.cpp
          valuehandler.cpp
          screenshotsaver.cpp
          globalvalues.cpp
          desktopfileparse.cpp
          desktopinfo.cpp
          pathinfo.cpp
          colorutils.cpp
          history.cpp
          strfparse.cpp
)

IF (UNIX AND NOT APPLE)
target_sources(
  shotup
  PRIVATE request.h
          request.cpp
)
ENDIF()

IF (WIN32)
  target_sources(
    shotup
    PRIVATE winlnkfileparse.cpp
  )
ENDIF()
