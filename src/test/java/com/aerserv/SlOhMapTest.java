package com.aerserv;

import java.util.HashSet;
import static org.junit.Assert.*;

import com.aerserv.offheapmap.SlOhMap;
import org.junit.Test;


/**
 */
public class SlOhMapTest
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public SlOhMapTest()
    {
    }

    /**
     * Tests put and get
     */
    @Test
    public void testGet()
    {
        SlOhMap m = new SlOhMap();
        m.put("a", 1);
        m.put("b", 2);
        m.put("a", 3);

        assertEquals(3, m.get("a"));
        m.free();
    }

    @Test
    public void testSize() {

        SlOhMap m = new SlOhMap();
        m.put("a", 1);
        m.put("a", 2);
        m.put("b", 3);
        assertEquals(2, m.size());
    }

    @Test
    public void testContains() {

        SlOhMap m = new SlOhMap();
        m.put("a", 1);
        m.put("a", 2);
        m.put("b", 3);
        assertEquals(true, m.contains("a"));
        assertEquals(false, m.contains("z"));
    }

    @Test
    public void testNullGet() {

        SlOhMap m = new SlOhMap();
        m.put("a", 1);
        m.put("a", 2);
        m.put("b", 3);
        assertEquals(Long.MAX_VALUE, m.get("z"));
    }

    @Test
    public void testIterate() {

        HashSet<Long> stuff = new HashSet<>();
        SlOhMap m = new SlOhMap();
        for (long i=0; i < 10; i++) {
            String kv = String.valueOf(i);
            m.put(kv, i);
            stuff.add(i);
        }

        long it = m.newIterator();
        while(m.hasNext(it)) {

            long tv = m.getValueAtItr(it);
            assertEquals(true, stuff.contains(tv));
            stuff.remove(tv);
            m.next(it);
        }

        assertEquals(0, stuff.size());

        m.freeItr(it);
        m.free();

    }
}
