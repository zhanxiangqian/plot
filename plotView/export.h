  #include <QtCore/QtGlobal>

  #if defined(PLOTVIEW_LIBRARY)
  #  define PLOTVIEW_EXPORT Q_DECL_EXPORT
  #else
  #  define PLOTVIEW_EXPORT Q_DECL_IMPORT
  #endif