// Assignment #: 8
//         Name: Joel Christiansen
//    StudentID: 1207242943
//      Lecture: TTh 4:30
//  Arizona State University CSE205 Spring 2015
//  Description: used to compare city/state in ZipInfo
import java.util.*;

public class CityStateComparator implements Comparator<ZipInfo> {
    public int compare(ZipInfo first, ZipInfo second) {
        int comp = first.getState().compareTo(second.getState());
        if (comp == 0) {
            return first.getCity().compareTo(second.getCity());
        }
        return comp;
    }
}