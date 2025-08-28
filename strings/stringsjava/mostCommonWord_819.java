package stringsjava;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class mostCommonWord_819 {
    public String mostCommonWord(String paragraph, String[] banned) {
        //APPROACH: Use a HashMap to count the frequency of the words
        // excluding the banned words

        Map<String, Integer> map = new HashMap<>();


        // remove special characters from the given paragraph string
        String mod = paragraph.replaceAll("[!?',;.]", " ");
        String mod1 = mod.replaceAll("  ", " ");
        // convert to an array
        String[] arr = mod1.split(" ");

        // add banned words into a set
        Set<String> s = new HashSet<>();
        s.addAll(Arrays.asList(banned));
        

        // add all words that are not banned to a hashmap
        for (String i: arr) {
            String current = i.toLowerCase();

            if (!s.contains(current)) {
                if (map.containsKey(current)) {
                    int currVal = map.get(current);
                    currVal++;
                    map.put(current, currVal);
                } else {
                    map.put(current, 1);
                }
            }
        }

        // find the most frequent word
        int mostFrequent = 0;
        String res = "";

        for(String i: map.keySet()) {
            // System.out.println(i);
            if (map.get(i) > mostFrequent) {
                mostFrequent = map.get(i);
                res = i;
            }
        }
        
        return res;
    }


    public static void main(String[] args) {
        String paragraph = "a, a, a, a, b,b,b,c, c";
        String modified = paragraph.replaceAll("[!?',;.]", " ");
        String modified1 = modified.replaceAll("  ", " ");
        String[] arr = modified1.split(" ");
        System.out.println(modified1);
        System.out.println(Arrays.toString(arr));
    }
    
}
