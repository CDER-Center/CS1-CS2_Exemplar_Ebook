import java.util.*;
import java.util.concurrent.*;

public class SumArray extends RecursiveTask<Integer> {
    int[] array;  //array to sum
    int hi;       //bounds on part to add
    int low;

    public SumArray(int[] array, int low, int hi) {
        this.array = array;
        this.low = low;
        this.hi = hi;
    }

    protected Integer compute(){
        if(hi - low < 100) {
            int ans = 0;
            for(int i=low; i < hi; i++)
                ans += array[i];
            return ans;
        }

        SumArray left = new SumArray(array, low, (hi+low)/2);
        SumArray right= new SumArray(array, (hi+low)/2, hi);
        left.fork();
        return right.compute() + left.join();
    }

    public static void main(String[] args) {
        int[] array = new int[1000];
        Random rand = new Random(System.currentTimeMillis());
        for(int i=0; i < array.length; i++)
            array[i] = rand.nextInt() % 10;

        int sum = 0;
        for(int i=0; i < array.length; i++)
            sum += array[i];
        System.out.println("serial sum: " + sum);

        sum = ForkJoinPool.commonPool().invoke(new SumArray(array, 0, array.length));
        System.out.println("fork-join sum: " + sum);
    }
}

