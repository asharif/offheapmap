#include "utils.hpp"
/**
 * Helper function to copy java jstring to cpp string
 */
string copy_jstring(JNIEnv *env, jstring v) {

    //get the key as utf str
    const char *vc = env->GetStringUTFChars(v, nullptr);
    //use the cpp string copy constructor to make a copy of the char*
    string vcpp = string(vc);
    // and let jvm free original
    env->ReleaseStringUTFChars(v, vc);

    return vcpp;

}