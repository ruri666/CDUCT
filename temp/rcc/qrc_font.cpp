/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.15.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

  // F:/Qt Widgets/core_base/qrc/font/pe-icon-set-weather.ttf
  
  
    // F:/Qt Widgets/core_base/qrc/font/fontawesome-webfont.ttf
  
  
    // F:/Qt Widgets/core_base/qrc/font/iconfont.ttf
  
  
  
static const unsigned char qt_resource_data[402588] = { 'Q', 'R', 'C', '_', 'D', 'A', 'T', 'A' };

static const unsigned char qt_resource_name[] = {
  // font
  0x0,0x4,
  0x0,0x6,0xd6,0x54,
  0x0,0x66,
  0x0,0x6f,0x0,0x6e,0x0,0x74,
    // pe-icon-set-weather.ttf
  0x0,0x17,
  0xb,0x6f,0x12,0x26,
  0x0,0x70,
  0x0,0x65,0x0,0x2d,0x0,0x69,0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x2d,0x0,0x73,0x0,0x65,0x0,0x74,0x0,0x2d,0x0,0x77,0x0,0x65,0x0,0x61,0x0,0x74,0x0,0x68,
  0x0,0x65,0x0,0x72,0x0,0x2e,0x0,0x74,0x0,0x74,0x0,0x66,
    // fontawesome-webfont.ttf
  0x0,0x17,
  0x6,0xd5,0xef,0xa6,
  0x0,0x66,
  0x0,0x6f,0x0,0x6e,0x0,0x74,0x0,0x61,0x0,0x77,0x0,0x65,0x0,0x73,0x0,0x6f,0x0,0x6d,0x0,0x65,0x0,0x2d,0x0,0x77,0x0,0x65,0x0,0x62,0x0,0x66,0x0,0x6f,
  0x0,0x6e,0x0,0x74,0x0,0x2e,0x0,0x74,0x0,0x74,0x0,0x66,
    // iconfont.ttf
  0x0,0xc,
  0xb,0xa3,0x92,0x6,
  0x0,0x69,
  0x0,0x63,0x0,0x6f,0x0,0x6e,0x0,0x66,0x0,0x6f,0x0,0x6e,0x0,0x74,0x0,0x2e,0x0,0x74,0x0,0x74,0x0,0x66,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/font
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x3,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/font/fontawesome-webfont.ttf
  0x0,0x0,0x0,0x42,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x1,0x3e,0x4,
0x0,0x0,0x1,0x8d,0xa,0xfa,0x7,0xc4,
  // :/font/pe-icon-set-weather.ttf
  0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x8d,0xa,0xfa,0x7,0xcd,
  // :/font/iconfont.ttf
  0x0,0x0,0x0,0x76,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x3,0xc4,0xb4,
0x0,0x0,0x1,0x8d,0xa,0xfa,0x7,0xca,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_font)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_font)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_font)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_font)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_font)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_font)(); }
   } dummy;
}
