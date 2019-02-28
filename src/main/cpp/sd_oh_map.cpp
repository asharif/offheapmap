#include "com_aerserv_offheapmap_SdOhMap.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include "utils.hpp"
#include <limits>

using namespace std;

/**
 * Helper function to copy java jstring to cpp string
 */
typedef unordered_map<string, double> sd_map;

extern "C" {

    /**
     * Creates a new std::map<string, string> on the heap and returns the pointer to it
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SdOhMap_newMap (JNIEnv *env, jobject o) {

        sd_map *m = new sd_map();
        return (int64_t)m;
    }

    /**
     * Puts value into map at location k
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_put(JNIEnv *env, jobject o, jlong jmptr, jstring k, jdouble v) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr;
        
        //make copies of the k, v
        string kc = copy_jstring(env, k);
        (*m)[move(kc)] = move((double)v);
        
    }

    /**
     * Returns the v associated with the key k out of the map
     */
    JNIEXPORT jdouble JNICALL Java_com_aerserv_offheapmap_SdOhMap_get(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr;
        string kc = copy_jstring(env, k);

        double jv = INT64_MAX;
        if(m->find(kc) != m->end()) {

            jv = (*m)[kc];
        } 

        return jv;

    }

    /**
     * Returns true if map contains key
     */
    JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SdOhMap_contains(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr;
        string kc = copy_jstring(env, k);

        jboolean result = false;

        if(m->find(kc) != m->end()) {

            result = true;
        }

        return result;

    }

    /**
     * Removes a key from map and returns it.  Returns null if key doesn't exist
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_remove(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr;
        string kc = copy_jstring(env, k);

        if(m->find(kc) != m->end()) {

            m->erase(kc);
        } 

    }

    /**
     * Gets a pointer to the iterator.  You call this you better call the associated free
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SdOhMap_newIterator(JNIEnv *env, jobject o, jlong jmptr) {

        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr; 

        sd_map::iterator *it = new sd_map::iterator();
        (*it) = m->begin();

        return (int64_t) it;

    }

    /**
     * Checks to see if there is more in the map
     */
    JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SdOhMap_hasNext(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr; 
        sd_map::iterator *it = (sd_map::iterator*) jit;

        bool result = true;
        if((*it) == m->end()) {
            result = false;
        }

        return result;
    }

    /**
     * Increments the iterator
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_next(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        sd_map::iterator *it = (sd_map::iterator*) jit;
        (*it)++;
    }

    /**
     * Gets the key at the iterator
     */
    JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SdOhMap_getKeyAtItr(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        sd_map::iterator *it = (sd_map::iterator*) jit;
        jstring result = env->NewStringUTF((*it)->first.c_str());

        return result;

    }

    /**
     * Gets the value at the iterator
     */
    JNIEXPORT double JNICALL Java_com_aerserv_offheapmap_SdOhMap_getValueAtItr(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        sd_map::iterator *it = (sd_map::iterator*) jit;
        jlong result = (*it)->second;

        return result;
    }

    /**
     * Gets the size of the map
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SdOhMap_size(JNIEnv *env, jobject o, jlong jmptr) {

        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr;
        return (jlong)m->size();

    }

    /**
     * Frees the iterator
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_freeItr(JNIEnv *env, jobject o, jlong jit) {

        sd_map::iterator *it = (sd_map::iterator*) jit;
        delete it;
    }

    /**
     * Frees the memory associated with the map
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SdOhMap_free(JNIEnv *env, jobject o, jlong jmptr) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sd_map *m = (sd_map*) cmptr;
        delete m;
    }

}


