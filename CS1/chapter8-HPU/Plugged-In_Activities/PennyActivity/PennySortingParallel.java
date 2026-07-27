
import java.util.*;
import java.util.concurrent.ForkJoinPool;

/*
The program demonstrates and times 3 levels of abstraction in parallel computing:
High-level (parallelSort) → easiest, fastest
Mid-level (streams) → expressive, flexible
Low-level (ForkJoin) → powerful, but complex
They all sort the same 1,000,000-element array, 
but they use different parallel strategies and abstractions.
 */
public class PennySortingParallel {

    public static void main(String[] args) {

        int[] pennyYears = new Random().ints(1_000_000, 1900, 2026).toArray();
        ForkJoinPool pool = new ForkJoinPool();

        for (int i = 1; i <= 5; i++) {

            // Copy SAME data for fair comparison
            int[] arr1 = Arrays.copyOf(pennyYears, pennyYears.length);
            int[] arr2 = Arrays.copyOf(pennyYears, pennyYears.length);
            int[] arr3 = Arrays.copyOf(pennyYears, pennyYears.length);

            /* 1. Parallel sort → data parallel sorting
            Data Parallelism (built-in, optimized)
            What it does:
            Splits the array into chunks
            Sorts chunks in parallel
            Merges results back together
             */
            long start1 = System.nanoTime();  //start time
            Arrays.parallelSort(arr1);
            long end1 = System.nanoTime();    //end time

            System.out.println("Parallel Sort - Oldest: " + arr1[0]);
            System.out.println("Time (ms): " + (end1 - start1) / 1000000.0); //calculate time and converts to milliseconds

            /* 2. Parallel stream → reduction
            Functional Parallelism (Stream API)
            What it does:
            Converts array → stream
            Marks stream as parallel
            Performs sorting across multiple threads
             */
            long start2 = System.nanoTime();
            int[] sortedArr2 = Arrays.stream(arr2)
                    .parallel()
                    .sorted()
                    .toArray();

            long end2 = System.nanoTime();

            System.out.println("Parallel Stream Sort - Oldest: " + sortedArr2[0]);
            System.out.println("Time (ms): " + (end2 - start2) / 1000000.0);

            /* 3. Fork/Join → task parallelism
            Task Parallelism (manual control)
            What it does:
            You explicitly define a parallel merge sort
            Breaks problem into recursive tasks
             */
            long start3 = System.nanoTime();
            pool.invoke(new ParallelMergeSort(arr3, 0, arr3.length - 1));
            long end3 = System.nanoTime();

            System.out.println("ForkJoin Sort - Oldest: " + arr3[0]);
            System.out.println("Time (ms): " + (end3 - start3) / 1000000.0);

            System.out.println("--------------------------------------------------");
        }
    }
}
