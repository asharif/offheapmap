#ifndef LIBOFFHEAPMAP_UTILS
#define LIBOFFHEAPMAP_UTILS

#include <jni.h>
#include <string>

using namespace std;
/**
 * Helper function to copy java jstring to cpp string
 */
string copy_jstring(JNIEnv *env, jstring v);

#endif