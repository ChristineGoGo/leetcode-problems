import java.util.ArrayList;
/*

    Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

    For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
    

    Example 1:

    Input: columnNumber = 1
    Output: "A"
    Example 2:

    Input: columnNumber = 28
    Output: "AB"
    Example 3:

    Input: columnNumber = 701
    Output: "ZY"
    

    Constraints:

    1 <= columnNumber <= 231 - 1
*/
public class excelSheetColumnTitle_168 {
    public String convertToTitle(int columnNumber) {
        ArrayList<String> lst = new ArrayList<>();
        String res = ""; 

        while (columnNumber > 0) {
            columnNumber--;
            int rem = columnNumber % 26;
            int test = 65 + rem;
            char c = (char) test;
            // System.out.println(c);
            res += c;
            lst.add(res);

            columnNumber /= 26;
            res = "";
        }

        // Collections.reverse(lst);
        // System.out.println(lst);

        String result = "";

        for (int i = lst.size() - 1; i >= 0; i--) {
            result += lst.get(i);
        }
        return result;
        
    }
    
}
