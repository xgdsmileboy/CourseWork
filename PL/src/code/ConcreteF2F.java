package code;

public class ConcreteF2F implements F2FContainer{

	@Override
	public FContainer f(FContainer fContainer) {
		return new ConcreteF(fContainer);
	}

}
