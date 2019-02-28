package com.aerserv;

import java.util.HashSet;
import static org.junit.Assert.*;

import com.aerserv.offheapmap.SdOhMap;
import org.junit.Test;


/**
 */
public class SdOhMapTest
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public SdOhMapTest()
    {
    }

    /**
     * Tests put and get
     */
    @Test
    public void testGet()
    {
        SdOhMap m = new SdOhMap();
        m.put("a", 1.123);
        m.put("b", 2.123);
        m.put("a", 3.123);

        assertEquals(3.123, m.get("a"), 0.0000001);
        m.free();
    }

    @Test
    public void testSize() {

        SdOhMap m = new SdOhMap();
        m.put("a", 1.123);
        m.put("a", 2.123);
        m.put("b", 3.123);
        assertEquals(2, m.size());
    }

    @Test
    public void testContains() {

        SdOhMap m = new SdOhMap();
        m.put("a", 1.123);
        m.put("a", 2.123);
        m.put("b", 3.123);
        assertEquals(true, m.contains("a"));
        assertEquals(false, m.contains("z"));
    }

    @Test
    public void testNullGet() {

        SdOhMap m = new SdOhMap();
        m.put("a", 1.123);
        m.put("a", 2.123);
        m.put("b", 3.123);
        assertEquals(Long.MAX_VALUE, m.get("z"), 0.0000001);
    }

    @Test
    public void testIterate() {

        HashSet<Double> stuff = new HashSet<>();
        SdOhMap m = new SdOhMap();
        for (double i=0; i < 10; i++) {
            String kv = String.valueOf(i);
            m.put(kv, i);
            stuff.add(i);
        }

        long it = m.newIterator();
        while(m.hasNext(it)) {

            double tv = m.getValueAtItr(it);
            assertEquals(true, stuff.contains(tv));
            stuff.remove(tv);
            m.next(it);
        }

        assertEquals(0, stuff.size());

        m.freeItr(it);
        m.free();

    }
}
