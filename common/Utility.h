//
// Created by mobiuschen on 19/6/2017.
// Copyright (c) 2017 ___FULLUSERNAME___. All rights reserved.
//

#pragma once

#include <stdio.h>


inline const char *LogFileNameAndFunction(const char *fileName)
{
    int len = (int) strlen(fileName);
    int count = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (fileName[i] == '\\' || fileName[i] == '/')
        {
            if (++count) return fileName + i + 1;
        }
    }
    return fileName;
}


#if defined(_MSC_VER)
#define DO_WHILE_MACRO_BEGIN do {
#define DO_WHILE_MACRO_END(value)       \
  __pragma(warning(push))               \
  __pragma(warning(disable:4127))       \
} while (value)                         \
__pragma(warning(disable:4127))
#else //APPLE or Linux
#define DO_WHILE_MACRO_BEGIN do {
#define DO_WHILE_MACRO_END(value) } while (value)
#endif //OS


#define PROCESS_ERROR(condition)        \
  DO_WHILE_MACRO_BEGIN                  \
    auto macroRet = (condition);        \
    if (!macroRet)                      \
      goto Exit0;                       \
  DO_WHILE_MACRO_END(false)


#define PROCESS_SUCCESS(condition)      \
  DO_WHILE_MACRO_BEGIN                  \
    auto macroRet = (condition);        \
    if (macroRet)                       \
        goto Exit1;                     \
  DO_WHILE_MACRO_END(false)

#define LOG_PROCESS_ERROR(condition)    \
  DO_WHILE_MACRO_BEGIN                  \
    auto macroRet = (condition);        \
    if (!macroRet) {                     \
      printf("LOG_PROCESS_ERROR(%s) at File %s(%d) Function %s\n", #condition, __FILE__, __LINE__, __FUNCTION__);  \
      goto Exit0;                       \
    }                                   \
  DO_WHILE_MACRO_END(false)
