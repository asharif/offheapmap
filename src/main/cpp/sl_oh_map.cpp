#include "com_aerserv_offheapmap_SlOhMap.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include "utils.hpp"
#include <limits>

using namespace std;

/**
 * Helper function to copy java jstring to cpp string
 */
typedef unordered_map<string, int64_t> sl_map;

extern "C" {

    /**
     * Creates a new std::map<string, string> on the heap and returns the pointer to it
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SlOhMap_newMap (JNIEnv *env, jobject o) {

        sl_map *m = new sl_map();
        return (int64_t)m;
    }

    /**
     * Puts value into map at location k
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SlOhMap_put(JNIEnv *env, jobject o, jlong jmptr, jstring k, jlong v) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr;
        
        //make copies of the k, v
        string kc = copy_jstring(env, k);
        (*m)[move(kc)] = move((int64_t)v);
        
    }

    /**
     * Returns the v associated with the key k out of the map
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SlOhMap_get(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr;
        string kc = copy_jstring(env, k);

        jlong jv = INT64_MAX;
        if(m->find(kc) != m->end()) {

            jv = (*m)[kc];
        } 

        return jv;

    }

    /**
     * Returns true if map contains key
     */
    JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SlOhMap_contains(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr;
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
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SlOhMap_remove(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr;
        string kc = copy_jstring(env, k);

        if(m->find(kc) != m->end()) {

            m->erase(kc);
        } 

    }

    /**
     * Gets a pointer to the iterator.  You call this you better call the associated free
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SlOhMap_newIterator(JNIEnv *env, jobject o, jlong jmptr) {

        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr; 

        sl_map::iterator *it = new sl_map::iterator();
        (*it) = m->begin();

        return (int64_t) it;

    }

    /**
     * Checks to see if there is more in the map
     */
    JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SlOhMap_hasNext(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr; 
        sl_map::iterator *it = (sl_map::iterator*) jit;

        bool result = true;
        if((*it) == m->end()) {
            result = false;
        }

        return result;
    }

    /**
     * Increments the iterator
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SlOhMap_next(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        sl_map::iterator *it = (sl_map::iterator*) jit;
        (*it)++;
    }

    /**
     * Gets the key at the iterator
     */
    JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SlOhMap_getKeyAtItr(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        sl_map::iterator *it = (sl_map::iterator*) jit;
        jstring result = env->NewStringUTF((*it)->first.c_str());

        return result;

    }

    /**
     * Gets the value at the iterator
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SlOhMap_getValueAtItr(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        sl_map::iterator *it = (sl_map::iterator*) jit;
        jlong result = (*it)->second;

        return result;
    }

    /**
     * Gets the size of the map
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SlOhMap_size(JNIEnv *env, jobject o, jlong jmptr) {

        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr;
        return (jlong)m->size();

    }

    /**
     * Frees the iterator
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SlOhMap_freeItr(JNIEnv *env, jobject o, jlong jit) {

        sl_map::iterator *it = (sl_map::iterator*) jit;
        delete it;
    }

    /**
     * Frees the memory associated with the map
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SlOhMap_free(JNIEnv *env, jobject o, jlong jmptr) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        sl_map *m = (sl_map*) cmptr;
        delete m;
    }

}


