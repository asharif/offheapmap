/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_aerserv_offheapmap_SsOhMap */

#ifndef _Included_com_aerserv_offheapmap_SsOhMap
#define _Included_com_aerserv_offheapmap_SsOhMap
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    newMap
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SsOhMap_newMap
  (JNIEnv *, jobject);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    put
 * Signature: (JLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_put
  (JNIEnv *, jobject, jlong, jstring, jstring);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    get
 * Signature: (JLjava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SsOhMap_get
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    contains
 * Signature: (JLjava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SsOhMap_contains
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    remove
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_remove
  (JNIEnv *, jobject, jlong, jstring);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    newIterator
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SsOhMap_newIterator
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    hasNext
 * Signature: (JJ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SsOhMap_hasNext
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    next
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_next
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    getKeyAtItr
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SsOhMap_getKeyAtItr
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    getValueAtItr
 * Signature: (JJ)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SsOhMap_getValueAtItr
  (JNIEnv *, jobject, jlong, jlong);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    size
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SsOhMap_size
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    free
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_free
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_aerserv_offheapmap_SsOhMap
 * Method:    freeItr
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_freeItr
  (JNIEnv *, jobject, jlong);

#ifdef __cplusplus
}
#endif
#endif
