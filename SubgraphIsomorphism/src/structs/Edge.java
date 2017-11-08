package structs;

/**
 * graph edge class, include the id of start and end vertex, also the label of the edge is included.
 * @author Jiajun
 *
 */
public class Edge {
	/*
	 * the start vertex id of the edge
	 */
	private int start;
	/*
	 * the end vertex id of the edge
	 */
	private int end;
	/*
	 * the label of the edge
	 */
	private String label;
	/**
	 * constructor
	 * @param start: the id of the start vertex of the edge
	 * @param end: the id of the end vertex of the edge
	 * @param label: the label of the edge
	 */
	public Edge(int start, int end, String label){
		this.start = start;
		this.end = end;
		this.label = label;
	}
	/**
	 * get the id of the start vertex of the edge
	 * @return
	 */
	public int getStart() {
		return start;
	}
	/**
	 * set the id of the start vertex of the edge
	 * @param start
	 */
	public void setStart(int start) {
		this.start = start;
	}
	/**
	 * get the id of the end vertex of the edge
	 * @return
	 */
	public int getEnd() {
		return end;
	}
	/**
	 * set the id of the end vertex of the edge
	 * @param end
	 */
	public void setEnd(int end) {
		this.end = end;
	}
	/**
	 * get the label of the edge
	 * @return
	 */
	public String getLabel() {
		return label;
	}
	/**
	 * set the label of the edge
	 * @param label
	 */
	public void setLabel(String label) {
		this.label = label;
	}
	/**
	 * judging the given vertexes' id of start and end whether equal to this's (with no directions)
	 * TRUE if the start id equals to this start id and the end id equals to this end id
	 * TRUE if the start id equals to this end id and the end id equals to this start id
	 * @param start
	 * @param end
	 * @return
	 */
	public boolean isEqual(int start, int end){
		if((this.start == start && this.end == end) || (this.end == start && this.start == end)){
			return true;
		}
		return false;
	}

	@Override
	public String toString() {
		return "Edge [start=" + start + ", end=" + end + ", label=" + label + "]";
	}
	
}
