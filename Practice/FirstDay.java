import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class FirstDay {


	public static String output = "";

	public static void main(String[] args) {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		final int cases;
		try {
			cases = 1;

			Solver solver = new Solver();
			for (int i = 0; i < cases; i++) {				
				solver.solve(br.readLine());
			}

		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println(output);
	}

}

class Solver {
	public void solve(String input) {					
		FirstDay.output.concat(input);	
		System.out.print("Hello " + input + " I'm Ralph!");
	}

}