package com.aerserv.offheapmap;

/**
 * A wrapper for a native map instance.  Allows for arbitrary large maps that are not limited to
 * JVM heap size or GC issues. It's a string->string map
 */
public class SsOhMap {

    static {

        NLibLoader.loadLibIfNotLoaded();
        
    }

    private long mPtr;

    public SsOhMap(){

        mPtr = newMap();
    }

    /**
     * Creates a new off java heap, but on native heap map (std::map)
     */
    private native long newMap();

    /**
     * Puts the k,v pair into the map
     */
    private native void put(long mPtr, String k, String v);

    /**
     * Gets the value associated with the key k
     */
    private native String get(long mPtr, String k);

    /**
     * Returns true if the map contains a value associated with the key k
     */
    private native boolean contains(long mPtr, String k);

    /**
     * Removes key k.  Does nothing if k doesn't exist
     */
    private native void remove(long mPtr, String k);

    /**
     * Gets a new iterator
     */
    private native long newIterator(long mPtr);

    /**
     * Returns true if the given iterator has more
     */
    private native boolean hasNext(long mPtr, long itr);

    /**
     * Increments the iterator
     */
    private native void next(long mPtr, long itr);

    /**
     * Gets key at iterator
     */
    private native String getKeyAtItr(long mPtr, long itr);

    /**
     * Gets value at iterator
     */
    private native String getValueAtItr(long mPtr, long itr);

    /**
     * Gets the value of the map
     */
    private native long size(long mPtr);

    /**
     * Releases memory.  This needs to be called to not have a memory leak
     */
    private native void free(long mPtr); 

    /**
     * Puts the k,v pair into the map
     */
    public void put(String k, String v) {

        put(this.mPtr, k, v);

    }

    /**
     * Gets the value associated with the key k
     */
    public String get(String k) {

        return get(this.mPtr, k);
    }

    /**
     * Returns true if the map contains a value associated with the key k
     */
    public boolean contains(String k) {
        
        return contains(this.mPtr, k);
    }

    /**
     * Removes key k.  Does nothing if k doesn't exist
     */
    public void remove(String k) {

        remove(this.mPtr, k);
    }

    /**
     * Gets a new iterator
     */
    public long newIterator() {

        return newIterator(this.mPtr);

    }

    /**
     * Returns true if the given iterator has more
     */
    public boolean hasNext(long itr) {

        return hasNext(this.mPtr, itr);

    }

    /**
     * Increments the iterator
     */
    public void next(long itr) {

        next(this.mPtr, itr);

    }

    /**
     * Gets key at iterator
     */
    public String getKeyAtItr(long itr) {

        return getKeyAtItr(this.mPtr, itr);
    }

    /**
     * Gets value at iterator. 
     */
    public String getValueAtItr(long itr) {

        return getValueAtItr(this.mPtr, itr);

    }

    /**
     * Gets the size of the map
     */
    public long size() {

        return size(this.mPtr);
    }

    /**
     * Releases memory for iterator.  This needs to be called to not have a memory leak
     */
    public native void freeItr(long itr);

    /**
     * Releases memory.  This needs to be called to not have a memory leak
     */
    public void free() {

        free(this.mPtr);
    }

}