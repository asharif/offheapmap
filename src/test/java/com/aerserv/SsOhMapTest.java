package com.aerserv;

import java.util.HashSet;
import static org.junit.Assert.*;
import com.aerserv.offheapmap.SsOhMap;
import org.junit.Test;


/**
 */
public class SsOhMapTest
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public SsOhMapTest()
    {
    }

    /**
     * Tests put and get
     */
    @Test
    public void testGet()
    {
        SsOhMap m = new SsOhMap();
        m.put("a", "1");
        m.put("b", "2");
        m.put("a", "3");

        assertEquals("3", m.get("a"));
        m.free();
    }

    @Test
    public void testSize() {

        SsOhMap m = new SsOhMap();
        m.put("a", "1");
        m.put("a", "2");
        m.put("b", "3");
        assertEquals(2, m.size());
    }

    @Test
    public void testContains() {

        SsOhMap m = new SsOhMap();
        m.put("a", "1");
        m.put("a", "2");
        m.put("b", "3");
        assertEquals(true, m.contains("a"));
        assertEquals(false, m.contains("z"));
    }

    @Test
    public void testNullGet() {

        SsOhMap m = new SsOhMap();
        m.put("a", "1");
        m.put("a", "2");
        m.put("b", "3");
        assertEquals(null, m.get("z"));
    }

    @Test
    public void testIterate() {

        HashSet<String> stuff = new HashSet<>();
        SsOhMap m = new SsOhMap();
        for (int i=0; i < 10; i++) {
            String kv = String.valueOf(i);
            m.put(kv, kv);
            stuff.add(kv);
        }

        long it = m.newIterator();
        while(m.hasNext(it)) {

            String tv = m.getValueAtItr(it);
            assertEquals(true, stuff.contains(tv));
            stuff.remove(tv);
            m.next(it);
        }

        assertEquals(0, stuff.size());

        m.freeItr(it);
        m.free();

    }
}
