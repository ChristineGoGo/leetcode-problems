import java.util.HashMap;
import java.util.Map;
/*
    Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, 
    return the day number of the year.

 

    Example 1:

    Input: date = "2019-01-09"
    Output: 9
    Explanation: Given date is the 9th day of the year in 2019.
    Example 2:

    Input: date = "2019-02-10"
    Output: 41
    

    Constraints:

    date.length == 10
    date[4] == date[7] == '-', and all other date[i]'s are digits
    date represents a calendar date between Jan 1st, 1900 and Dec 31st, 2019.
*/

/*
 *  APPROACH: Create an array with all the months of the year
 * and the number of days in that month
 * Use all loop starting from month 1 adding all the days.
 */


public class dayOfTheYear_1154 {
    public static int dayOfYear(String date) {
        String y = date.substring(0, 4);
        int year = Integer.parseInt(y);

        String m = date.substring(5, 7);
        int months = Integer.parseInt(m);

    
        String s = date.substring(8, 10);
        int days = Integer.parseInt(s);

        boolean leap = false;

        int totalDays = 0;

        Map<Integer, Integer> map = new HashMap<>();
        map.put(1, 31);
        map.put(2, 28);
        map.put(3, 31);
        map.put(4, 30);
        map.put(5, 31);
        map.put(6, 30);
        map.put(7, 31);
        map.put(8, 31);
        map.put(9, 30);
        map.put(10, 31);
        map.put(11, 30);
        map.put(12, 31);
        // determine if leap year
        if (year % 4 == 0) {
            leap = true;
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    leap = true;
                } else {
                    leap = false;
                }
            }
        }
        
        // adjust the days in February if leap year
        if (leap) {
            map.put(2, 29);
        }

        // find the total days
        for (int i = 1; i < months; i++) {
            totalDays += map.get(i);
        }
        return totalDays + days;
    }
    public static void main(String[] args) {
        System.out.println(dayOfYear("2019-02-10"));
    }
    
}
