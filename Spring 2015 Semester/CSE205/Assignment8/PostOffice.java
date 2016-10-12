// Assignment #: 8
//         Name: Joel Christiansen
//    StudentID: 1207242943
//      Lecture: TTh 4:30
//  Arizona State University CSE205 Spring 2015
//  Description: basically a featurefull list of ZipInfos
import java.io.*;
import java.util.*;

public class PostOffice implements Serializable {
    private ArrayList<ZipInfo> zipcodeList;
    private static final long serialVersionUID = 2L;

    public PostOffice() {
        zipcodeList = new ArrayList<ZipInfo>();
    }

    public int zipcodeExists(int zip) {
        for (int i=0;i<zipcodeList.size();i++) {
            if (zipcodeList.get(i).getZipcode() == zip) {
                return i;
            }
        }
        return -1;
    }

    public int cityStateExists(String city, String state) {
        for (int i=0;i<zipcodeList.size();i++) {
            ZipInfo current = zipcodeList.get(i);
            if (current.getCity().equals(city) && current.getState().equals(state)) {
                return i;
            }
        }
        return -1;
    }

    public boolean addZipInfo(String city, String state, int zip) {
        if (cityStateExists(city, state) == -1) {
            zipcodeList.add(new ZipInfo(city, state, zip));
            return true;
        }
        return false;
    }

    public boolean removeZipcode(int zip) {
        int index = zipcodeExists(zip);
        if (index != -1) {
            zipcodeList.remove(index);
            return true;
        } 
        return false;
    }

    public boolean removeCityState(String city, String state) {
        int index = cityStateExists(city, state);
        if (index != -1) {
            zipcodeList.remove(index);
            return true;
        }
        return false;
    }

    public void sortByZipcode() {
        Sorts.sort(zipcodeList, new ZipcodeComparator());
    }

    public void sortByCityState() {
        Sorts.sort(zipcodeList, new CityStateComparator());
    }

    public String listZipCode() {
        String t = "\n";
        for (int i=0;i<zipcodeList.size();i++) {
            t += zipcodeList.get(i).toString();
        }
        if (t.equals("\n")) {
            return "\nno zipcode\n\n";
        }
        return t+"\n";
    }

    public void closePostOffice() {
        zipcodeList.clear();
    }
}