#ifndef LIB2API_HEADER
#define LIB2API_HEADER

#ifdef WIN32
  #define LIB2_API __declspec(dllexport)
#else
  #define LIB2_API
#endif

LIB2_API void lib2func();

#endif