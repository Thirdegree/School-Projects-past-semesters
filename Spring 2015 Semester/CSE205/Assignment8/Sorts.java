// Assignment #: 8
//         Name: Joel Christiansen
//    StudentID: 1207242943
//      Lecture: TTh 4:30
//  Arizona State University CSE205 Spring 2015
//  Description: insertion sort that uses a custom comparator or two
import java.util.*;

public class Sorts {

    //Damn languages with no REPL, this was a pain
    public static void sort(ArrayList<ZipInfo> objects, Comparator<ZipInfo> comp) {
        ZipInfo temp;


        for (int i = 0; i<objects.size();i++) {
            for (int j=0; j<i;j++) {
                if (i!=0 && comp.compare(objects.get(i), objects.get(j))<0) {
                    temp = objects.get(i);
                    objects.remove(i);
                    objects.add(j, temp);
                }

            }
        }
    }
}