
import java.util.*;

/*
This program creates a one million element array of numbers between 1900 - 2026. 
It times how long it takes to sort a 1M array (it does not time the creation of the array)
If running only one trial, it is unreliable because of:
JVM warm-up
caching effects
For a proper benchmark: 
run multiple times
average results
do a warm-up run
 */
public class PennySortingSequential {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Example array of penny years (one million)
        int[] pennyYears = new Random().ints(1000000, 1900, 2026).toArray();
        long start = System.nanoTime();     //start time
        // Sort the array
        Arrays.sort(pennyYears);
        long end = System.nanoTime();       //end time
        long duration = end - start;

        System.out.println("Time (ms): " + duration / 1000000.0);  //converting time from nanoseconds to milliseconds. 1 millisecond (ms) = 1,000,000 nanoseconds

        int oldestPenny = pennyYears[0];
        System.out.println("Oldest penny is from the year: " + oldestPenny);
    }

}
