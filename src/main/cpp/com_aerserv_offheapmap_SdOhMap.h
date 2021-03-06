/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_aerserv_offheapmap_SdOhMap */

#ifndef _Included_com_aerserv_offheapmap_SdOhMap
#define _Included_com_aerserv_offheapmap_SdOhMap
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    newMap
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SdOhMap_newMap
  (JNIEnv *, jobject);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    put
 * Signature: (JLjava/lang/String;D)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_put
  (JNIEnv *, jobject, jlong, jstring, jdouble);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    get
 * Signature: (JLjava/lang/String;)D
 */
JNIEXPORT jdouble JNICALL Java_com_aerserv_offheapmap_SdOhMap_get
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    contains
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SdOhMap_contains
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    remove
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_remove
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    newIterator
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SdOhMap_newIterator
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    hasNext
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SdOhMap_hasNext
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    next
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_next
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    getKeyAtItr
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SdOhMap_getKeyAtItr
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    getValueAtItr
 * Signature: (JJ)D
 */
JNIEXPORT jdouble JNICALL Java_com_aerserv_offheapmap_SdOhMap_getValueAtItr
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    size
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SdOhMap_size
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    free
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_free
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_aerserv_offheapmap_SdOhMap
 * Method:    freeItr
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_freeItr
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
