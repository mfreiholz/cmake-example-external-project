#ifndef LIB1API_HEADER
#define LIB1API_HEADER

#ifdef WIN32
  #define LIB1_API __declspec(dllexport)
#else
  #define LIB1_API
#endif

LIB1_API void lib1func();

#endif