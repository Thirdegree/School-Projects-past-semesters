package cse360assign2;

import java.util.Arrays;

/** Assignment 2, CSE 360 Intro to Software Engineering
 * 
 * @author Joel Christiansen
 * @version Feb 8, 2016
 */

public class OrderedIntList {
	
	
	
	private int[] array;  // array
    private int counter = 0; // counter


    /** A list of Integers in ascending order, containing 10 values. 
	 * 
	 */
    OrderedIntList()
    {
        array = new int[10];
    }
    
    /** A list of Integers in ascending order
     * 
     * @param size The size of the new array.
     */
    OrderedIntList( int size ) {
    	array = new int[ size ];
    }

    
    /** Inserts a non-duplicate value into the list.
     * 
     * @param value	The value to be inserted.
     */
    public void insert( int value ) {
        int insertAt = 0; 
        
        //Finds the location the new value should be inserted
        for (int index = 0; index < counter; index++) {
            if (value > array[ index ]) {
                insertAt++;
            } else {
                continue;
            }
        }

        
        if (array[ insertAt ] != value) {
        	//shifts the appropriate values in the array.
        	for (int index = counter; index > insertAt; index--) { 
        		if (index < 10) {
        			array[ index ] = array[ index - 1 ];
        		}
        	}
        	
        	array[ insertAt ] = value;
        	counter++;
        	if (counter == size()) {
        		array = Arrays.copyOf( array, ( int ) ( size() + size() * 0.5 ));
        	}
        }
    }

    /**
     * @return The size of the array.
     */
    public int size() {
    	return array.length; 
    }
    
    /**
     * @return The number of items in the array.
     */
    public int length() {
    	return counter; 
    }

    /** Calls the recursive implementation.
     * 
     * @param value The value searched for.
     * @return The index of the value, or -1 if it does not exist.
     */
    private int binSearch( int value ) {
    	return binSearch( value, 0, length() - 1 );
    }
    /**
     * Recursive implementation of binSearch.
     * 
     * @param value The value being searched for.
     * @param l the leftmost index of the recursion.
     * @param r the rightmost index of the recursion.
     * @return The index of the value, or -1 if it does not exist.
     */
    private int binSearch( int value, int l, int r)  {
    	int mid = ( r - l ) / 2;
    	
    	if (r < l) {
    		return -1;
    	}
    	
    	if (array[ mid ] > value) {
    		return binSearch(value, mid + 1, r);
    	} else if (array[ mid ] < value) {
    		return binSearch(value, l, mid - 1);
    	} else {
    		return mid;
    	}
    }
    
    /** Deletes key from array.
     * 
     * @param key The value to be deleted.
     */
    public void delete(int key) {
    	int index = binSearch(key);
    	if (index == -1) {} // You can't delete something that isn't there.
    	else {
    		int i;
    		for (i = index; i < counter - 1; i++) {
    			array[ i ] = array[ i + 1 ];
    		}
    		if (i == counter - 1) {
    			array[ i ] = 0;
    		}
    		counter--;
    		
    	}
    	if (counter < size() / 2) {
			array = Arrays.copyOf(array, ( int ) (size() - size() * 0.4));
		}
    }
    
    /**
     * Stylized print command.
     * @return toString of array.
     */
    public String toString() {
    	int index;
    	String returnString = "";
    	for (index = 0; index < counter - 1; index++) {
            returnString += (array[ index ] + " ");
        }
    	if (index == counter - 1) {
    		returnString += (array[ index ]);
    	}
    	return returnString;
    }
}
