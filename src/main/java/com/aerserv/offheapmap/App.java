package com.aerserv.offheapmap;

import java.util.HashMap;
import java.util.Map;

/**
 * A test app to test the offheap map
 */
public class App 
{
    
    private static String var = "0000000000";
    public static void main( String[] args )
    {

        if(args[0].equals("0")) {
            fail();
        } else if(args[0].equals("1")) {
            success();
        } else if(args[0].equals("2")) {
            offHeapIterate();
        } else if(args[0].equals("3")) {
            bigOnHeapIterate();
        } else if(args[0].equals("4")) {
            bigOffHeapMapIterate();
        } else if(args[0].equals("5")) {
            testSize();
        } else if(args[0].equals("6")) {
            testRemove();
        } else if(args[0].equals("7")) {
            put2x();
        } else if(args[0].equals("8")) {
            testOnceExportMap();
        } else if(args[0].equals("9")) {
            testFree();
        } else if(args[0].equals("10")) {
            testPutFree();
        } else {
            System.err.println("Exactly one argument is needed.  1 for success test and 0 for fail test");
        }
        
    }

    public static void testFree() {

        SsOhMap m = new SsOhMap();
        m.free();
    }

    public static void testPutFree() {

        SsOhMap m = new SsOhMap();
        m.put("foo", "bar");
        m.free();
    }



    /**
     * If starting jvm with -Xmx1m this should die hard as it tries to put it in 
     * the java heap
     */
    public static void fail() {

        HashMap<String, String> m = new HashMap<>();
        for (int i=0; i < 10000000; i++) {
            m.put(String.valueOf(i), var);
        }
    }

    /**
     * This guy goes off jvm heap so it should work great with -Xmx1m
     */
    public static void success() {

        SsOhMap m = new SsOhMap();
        for (int i=0; i < 10000000; i++) {
            m.put(String.valueOf(i), var);
        }

        System.out.println( m.get("4") );
        m.free();
    }

    /**
     * This one tests the iterator
     */
    public static void offHeapIterate(){

        SsOhMap m = new SsOhMap();
        for (int i=0; i < 10; i++) {
            String kv = String.valueOf(i);
            m.put(kv, kv);
        }

        long it = m.newIterator();
        while(m.hasNext(it)) {

            String tv = m.getValueAtItr(it);
            m.next(it);
            System.out.println(tv);
        }

        m.freeItr(it);
        m.free();

    }

    /**
     * Test size
     */
     public static void testSize() {

        SsOhMap m = new SsOhMap();
        for (int i=0; i < 10; i++) {
            String kv = String.valueOf(i);
            m.put(kv, kv);
        }

        System.out.println(m.size());

    }

    /**
     * Test remove
     */
     public static void testRemove() {

        SsOhMap m = new SsOhMap();
        for (int i=0; i < 10; i++) {
            String kv = String.valueOf(i);
            m.put(kv, kv);
        }

        m.remove(String.valueOf(9));
        m.remove(String.valueOf(-55));

        System.out.println(m.size());

    }

    /**
     * Regular map iterate for comparison
     */
     public static void bigOnHeapIterate() {

        HashMap<String, String> m = new HashMap<>();
        for (int i=0; i < 10000000; i++) {
            m.put(String.valueOf(i), var);
        }

        for(Map.Entry<String, String> e : m.entrySet()) {

            System.out.println(e.getValue());
        }
    }

    /**
     * Big heap iterate for comparison
     */
    public static void bigOffHeapMapIterate(){

        SsOhMap m = new SsOhMap();
        for (int i=0; i < 10000000; i++) {
            m.put(String.valueOf(i), var);
        }

        long it = m.newIterator();
        while(m.hasNext(it)) {

            String v = m.getValueAtItr(it);
            System.out.println(v);
            m.next(it);
        }
        m.freeItr(it);
        m.free();

    }

    public static void put2x(){

        SsOhMap m = new SsOhMap();
        m.put("foo", "1");
        m.put("foo", "2");
        System.out.println(m.get("foo"));
    }

    public static void testOnceExportMap() {

        SlOhMap a = new SlOhMap();
        SdOhMap b = new SdOhMap();
        SsOhMap c = new SsOhMap();

    }

}
