// Assignment #: 8
//         Name: Joel Christiansen
//    StudentID: 1207242943
//      Lecture: TTh 4:30
//  Arizona State University CSE205 Spring 2015
//  Description: Used to compare zipcodes in sorts
import java.util.*;

public class ZipcodeComparator implements Comparator<ZipInfo> {
    public int compare(ZipInfo first, ZipInfo second) {
        if (first.getZipcode() == second.getZipcode()) {
            return 0;
        }
        else if (first.getZipcode() > second.getZipcode()) {
            return 1;
        }
        return -1;
    }
}