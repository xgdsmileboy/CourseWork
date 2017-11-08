package code;

public class ConcreteF implements FContainer{
	// This is used to store the next 'f' function, say as f' in (fix f = f fix f')
	private FContainer fContainer;
	
	public ConcreteF(FContainer fContainer) {
		this.fContainer = fContainer;
	}
	
	@Override
	public int f(int param) {
		if(param <= 0){
			return 1;
		} else {
			return param * fContainer.f(param - 1);
		}
	}

}
