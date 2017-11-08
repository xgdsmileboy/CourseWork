package structs;
/**
 * graph vertex class, include vertex id, vertex label and necessary operations on them
 * @author Jiajun
 *
 */
public class Vertex {
	/*
	 * vertex id
	 */
	private int id;
	/*
	 * vertex label
	 */
	private String label;
	/**
	 * constructor
	 * @param id: vertex id
	 * @param label: vertex label
	 */
	public Vertex(int id, String label){
		this.id = id;
		this.label = label;
	}
	/**
	 * get the vertex id of the vertex
	 * @return
	 */
	public int getId() {
		return id;
	}
	/**
	 * set the vertex id
	 * @param id
	 */
	public void setId(int id) {
		this.id = id;
	}
	/**
	 * get vertex label
	 * @return
	 */
	public String getLabel() {
		return label;
	}
	/**
	 * set vertex label
	 * @param label
	 */
	public void setLabel(String label) {
		this.label = label;
	}
	@Override
	public String toString() {
		return "Vertex [id=" + id + ", label=" + label + "]";
	}

}
