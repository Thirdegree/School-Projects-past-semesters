/** testing special comments */

class demo {
    private String str;
    private int num;

    Demo (String newStr, int val) {
        str = newStr;
        num = val;  
    }
}

Demo temp = new Demo(new String("Jan"), 25);

/*
Stack        |  Heap
             |    
             |    ____________________
             |    |  str |(1)|
             |    |      ____
             |    |  num |25|
new Str |(1)||    |___________________
    val |25| |
             | (1)| "Jan" |
             |
*/

public class Dummy {
    private int n1;
    private int n2;

    Dummy (int in) {
        set (in);
    }

    public int get1() {
        return n1;  
    }

    public int get2() {
        return n2;
    }

    public String toString() {
        return n1 + n2 + "";
    }

    public void set(int in) {
        n1 = in;
        n2 = in + 1;
    }
}

// IN ECLIPSE: New -> JUnit Test Case

import static org.junit.Assert.*;

public class DummyTest {
    @Test
    public void testDummy() {
        fail("Not yet implemented");
    }

    @Test
    public void testGet1() {
        fail("Not yet implemented");
    }

    @Test
    public void testGet2() {
        fail("Not yet implemented");
    }

    @Test
    public void testToString() {
        fail("Not yet implemented");
    }

    @Test
    public void testSet() {
        fail("Not yet implemented");
    }
}