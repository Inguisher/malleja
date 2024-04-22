#ifndef PINCODE_GLOBAL_H
#define PINCODE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PINCODE_LIBRARY)
#  define PINCODE_EXPORT Q_DECL_EXPORT
#else
#  define PINCODE_EXPORT Q_DECL_IMPORT
#endif

#endif // PINCODE_GLOBAL_H
