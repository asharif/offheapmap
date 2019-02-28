#include "com_aerserv_offheapmap_SsOhMap.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include "utils.hpp"

using namespace std;

typedef unordered_map<string, string> ss_map;

extern "C" {

    /**
     * Creates a new std::map<string, string> on the heap and returns the pointer to it
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SsOhMap_newMap (JNIEnv *env, jobject o) {

        ss_map *m = new ss_map();
        return (int64_t)m;
    }

    /**
     * Puts value into map at location k
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_put(JNIEnv *env, jobject o, jlong jmptr, jstring k, jstring v) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr;
        
        //make copies of the k, v
        string kc = copy_jstring(env, k);
        string vc = copy_jstring(env, v);
        (*m)[move(kc)] = move(vc);
        
    }

    /**
     * Returns the v associated with the key k out of the map
     */
    JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SsOhMap_get(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr;
        string kc = copy_jstring(env, k);

        jstring jv = nullptr;
        if(m->find(kc) != m->end()) {

            string *v = &(*m)[kc];
            jv = env->NewStringUTF((*v).c_str());
        } 

        return jv;

    }

    /**
     * Returns true if map contains key
     */
    JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SsOhMap_contains(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr;
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
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_remove(JNIEnv *env, jobject o, jlong jmptr, jstring k) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr;
        string kc = copy_jstring(env, k);

        if(m->find(kc) != m->end()) {

            m->erase(kc);
        } 

    }

    /**
     * Gets a pointer to the iterator.  You call this you better call the associated free
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SsOhMap_newIterator(JNIEnv *env, jobject o, jlong jmptr) {

        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr; 

        ss_map::iterator *it = new ss_map::iterator();
        (*it) = m->begin();

        return (int64_t) it;

    }

    /**
     * Checks to see if there is more in the map
     */
    JNIEXPORT jboolean JNICALL Java_com_aerserv_offheapmap_SsOhMap_hasNext(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr; 
        ss_map::iterator *it = (ss_map::iterator*) jit;

        bool result = true;
        if((*it) == m->end()) {
            result = false;
        }

        return result;
    }

    /**
     * Increments the iterator
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_next(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        ss_map::iterator *it = (ss_map::iterator*) jit;
        (*it)++;
    }

    /**
     * Gets the key at the iterator
     */
    JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SsOhMap_getKeyAtItr(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        ss_map::iterator *it = (ss_map::iterator*) jit;
        jstring result = env->NewStringUTF((*it)->first.c_str());

        return result;

    }

    /**
     * Gets the value at the iterator
     */
    JNIEXPORT jstring JNICALL Java_com_aerserv_offheapmap_SsOhMap_getValueAtItr(JNIEnv *env, jobject o, jlong jmptr, jlong jit) {

        ss_map::iterator *it = (ss_map::iterator*) jit;
        jstring result = env->NewStringUTF((*it)->second.c_str());

        return result;
    }

    /**
     * Gets the size of the map
     */
    JNIEXPORT jlong JNICALL Java_com_aerserv_offheapmap_SsOhMap_size(JNIEnv *env, jobject o, jlong jmptr) {

        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr;
        return (jlong)m->size();

    }

    /**
     * Frees the iterator
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_freeItr(JNIEnv *env, jobject o, jlong jit) {

        ss_map::iterator *it = (ss_map::iterator*) jit;
        delete it;
    }

    /**
     * Frees the memory associated with the map
     */
    JNIEXPORT void JNICALL Java_com_aerserv_offheapmap_SsOhMap_free(JNIEnv *env, jobject o, jlong jmptr) {

        //get the map
        int64_t cmptr = (int64_t)jmptr;
        ss_map *m = (ss_map*) cmptr;
        delete m;
    }

}

