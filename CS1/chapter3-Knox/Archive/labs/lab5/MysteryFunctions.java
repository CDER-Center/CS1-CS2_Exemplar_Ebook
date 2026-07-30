import java.util.Arrays;
import java.util.NoSuchElementException;

// This was the code that created the functinons
// for you to figure out what they do with tests

public class MysteryFunctions {

    // Sum of even numbers in an array
    public static int mystery01(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] % 2 == 0)
            {
                sum += nums[i];
            }
        }
        return sum;
    }

   

    // Sum of odd numbers in an array
    public static int mystery02(int[] nums) {
        // do this without filter
        int sum = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] % 2 != 0)
            {
                sum += nums[i];
            }
        }
        return sum;
    }

    // Product of all numbers in an array
    public static int mystery03(int[] nums) {
        int product = 1;
        for (int i = 0; i < nums.length; i++)
        {
            product *= nums[i];
        }
        return product;
    }

    // Count of numbers greater than 10
    public static int mystery04(int[] nums) {
        // do without filter
        int count = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] > 10)
            {
                count++;
            }
        }
        return count;
    }

    // Sum of squares of all numbers in an array
    public static int mystery05(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++)
        {
            sum += nums[i] * nums[i];
        }
        return sum;
    }

    // Maximum number in an array
    public static int mystery06(int[] nums) {
        if (nums.length == 0)
        {
            throw new NoSuchElementException("Array is empty");
        }
        int max = nums[0];
        for (int i = 1; i < nums.length; i++)
        {
            if (nums[i] > max)
            {
                max = nums[i];
            }
        }
        return max;
    }

    // Sum of numbers greater than a given parameter
    public static int mystery07(int[] nums, int param) {
        
        int sum = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] > param)
            {
                sum += nums[i];
            }
        }
        return sum;
    }

    // Count of numbers less than a given parameter
    public static int mystery08(int[] nums, int param) {
        int count = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] < param)
            {
                count++;
            }
        }
        return count;
    }

    // Sum of corresponding elements from two arrays
    public static int[] mystery09(int[] nums1, int[] nums2) 
    {
        if (nums1.length != nums2.length)
        {
            throw new IllegalArgumentException("Arrays must be of the same length");
        }
        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++)
        {
            result[i] = nums1[i] + nums2[i];
        }
        return result;

    }
    

    // Product of corresponding elements from two arrays
    public static int[] mystery10(int[] nums1, int[] nums2)
    {
        if (nums1.length != nums2.length)
        {
            throw new IllegalArgumentException("Arrays must be of the same length");
        }
        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++)
        {
            result[i] = nums1[i] * nums2[i];
        }
        return result;
    }

    // difference between corresponding elements from two arrays
    public static int[] mystery11(int[] nums1, int[] nums2)
    {
        if (nums1.length != nums2.length)
        {
            throw new IllegalArgumentException("Arrays must be of the same length");
        }
        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++)
        {
            result[i] = nums1[i] - nums2[i];
        }
        return result;
    }

    public static int[] mystery12(int[] nums1, int[] nums2)
    {
        int len1 = nums1.length;
        int len2 = nums2.length;
        if (len1 > len2)
        {
            int[] result = new int[len1];
            for (int i = 0; i < len1; i++)
            {
                if (i < len2)
                {
                    result[i] = nums1[i] + nums2[i];
                }
                else
                {
                    result[i] = nums1[i];
                }
            }
            return result;
        }
        
        int[] result = new int[len2];
        for (int i = 0; i < len2; i++)
        {
            if (i < len1)
            {
                result[i] = nums1[i] + nums2[i];
            }
            else
            {
                result[i] = nums2[i];
            }
        }
        return result;
    }

    public static String[] mystery13(String[] strings)
    {
        String[] result = new String[strings.length];
        for (int i = 0; i < strings.length; i++)
        {
            result[i] = strings[i].toUpperCase();
        }
        return result;
    }
}
