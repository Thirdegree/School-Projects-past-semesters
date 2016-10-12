package cse360assign1;

import cse360assign2.OrderedIntList;

public class Tester {
	
	public static void main(String[] args) {
        OrderedIntList test = new OrderedIntList();
        test.print();
        test.insert(5);
        test.print();
        test.insert(2);
        test.print();
        test.insert(8);
        test.print();
        test.insert(3);
        test.print();
        test.insert(6);
        test.insert(4);
        test.insert(3);
        test.insert(3);
        test.insert(100);
        test.insert(324);
        test.insert(23);
        test.insert(12);
        test.insert(25);
        test.print();
    }
}
