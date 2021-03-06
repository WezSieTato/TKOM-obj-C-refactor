#ifndef MACROSTEST_H
#define MACROSTEST_H

#include "implementation.h"
#include "interface.h"

#define COMPARE_STRING(a, b) QCOMPARE(QString((a).c_str()), QString(b))

#define QTRUE( a ) QCOMPARE(a, true)
#define QFALSE( a ) QCOMPARE(a, false)

#endif // MACROSTEST_H
