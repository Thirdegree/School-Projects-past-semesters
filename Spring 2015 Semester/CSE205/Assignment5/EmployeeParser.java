// Assignment #: 5
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: Parses a string and returns an Employee

public class EmployeeParser {
    public static Employee parseStringToEmployee(String lineToParse) {
        String[] info = lineToParse.split("/");

        //could also be a case statement, but that seems excessive
        if (info[0].equalsIgnoreCase("Volunteer"))
            return volunteer(info);

        if (info[0].equalsIgnoreCase("PartTime"))
            return partTime(info);

        if (info[0].equalsIgnoreCase("FullTime"))
            return fullTime(info);

        //If this happens, someone put in a bad line on the input file.
        System.out.println("Bad input format. No Employee added.");
        return null;
    }

    //priavte methods purely for neatness sake.
    private static Employee volunteer(String[] parseInfo) {
        return new Volunteer(parseInfo[1], parseInfo[2], parseInfo[3]);
    }

    private static Employee partTime(String[] parseInfo) {
        return new PartTime(parseInfo[1], parseInfo[2], parseInfo[3], 
                        Double.parseDouble(parseInfo[4]), 
                        Integer.parseInt(parseInfo[5]));
    }

    private static Employee fullTime(String[] parseInfo) {
        return new FullTime(parseInfo[1], parseInfo[2], parseInfo[3], 
                        Double.parseDouble(parseInfo[4]), 
                        Double.parseDouble(parseInfo[5]));
    }
}