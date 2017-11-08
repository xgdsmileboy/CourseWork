package code;

public class YCombinator implements FContainer{
	//store the fix function
	private F2FContainer f2FContainer;
	
	public YCombinator(F2FContainer f2fContainer) {
		this.f2FContainer = f2fContainer;
	}
	
	public FContainer fix(){
		return this.f2FContainer.f(this);
	}
	
	@Override
	public int f(int param) {
		FContainer fContainer = f2FContainer.f(this);
		return fContainer.f(param);
	}

	
}
