public class SerialPrimes {

	public static boolean isPrime(long num) {
		//returns whether 2*num+1 is prime

		num = 2*num  + 1;
		int limit = (int) Math.sqrt(num);
		for(long i=2; i<=limit; i++) {
			if(num % i == 0)
				return false;
		}
		return true;
	}
	
	private static int pCount;
	
	public static void main(String args[]) {
		long start = System.currentTimeMillis();

		pCount = 0;         //number of odd primes found 
		for(int i=1; i < 999999; i++)
			if(isPrime(i))
				pCount++;

		long end = System.currentTimeMillis();

		System.out.println(pCount + " primes found");
		System.out.println("Elapsed time: " + (end-start) + " ms");
	}
}
