package code;

public class Main {

    public static void main(String args[]) {     
        //instance a fix function
        F2FContainer f2fContainer = new ConcreteF2F();
        //store fix function
        YCombinator yCombinator = new YCombinator(f2fContainer);
        //apply the fix function to the specific f function
        FContainer fContainer = yCombinator.fix();
        //invoke
        System.out.println(fContainer.f(5));
  }
	
}
