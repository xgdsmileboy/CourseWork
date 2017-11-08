package structs;

import java.util.List;
/**
 * the graph class, include the graph index, the list of vertex, the list of edge
 * and the matrix of the edge with no directions, in other words, if there exist
 * an edge from the a(vertex) to b(vertex), there will be an edge from b to a added
 * into the matrix, it is to say the matrix is symmetrical
 * @author Jiajun
 *
 */
public class Graph {
	/*
	 * the id of the graph
	 */
	private int id;
	/*
	 * the list of the graph's vertexes
	 */
	private List<Vertex> verList;
	/*
	 * the list of the graph's edges
	 */
	private List<Edge> edgeList;
	/*
	 * the matrix of the edge, which is symmetrical
	 */
	private int[][] matrix;
	/**
	 * constructor
	 * @param id: the index of the graph
	 * @param vList: the list of the graph's vertexes
	 * @param eList: the list of the graph's edges
	 */
	public Graph(int id, List<Vertex> vList, List<Edge> eList){
		this.id = id;
		this.verList = vList;
		this.edgeList = eList;
		computeMatrix();
	}
	/**
	 * compute the matrix of the edges
	 */
	private void computeMatrix(){
		int v = verList.size();
		matrix = new int[v][v];
		for(Edge e : edgeList){
			int start = e.getStart();
			int end = e.getEnd();
			//NOTE: the matrix is symmetrical
			matrix[start][end] = 1;
			matrix[end][start] = 1;
		}
	}
	/**
	 * get the number of the vertexes
	 * @return
	 */
	public int getVertexCount(){
		return this.verList.size();
	}
	/**
	 * get the number of the edges
	 * @return
	 */
	public int getEdgeCount(){
		return this.edgeList.size();
	}
	/**
	 * get the vertexes of the graph
	 * @return
	 */
	public List<Vertex> getVerList() {
		return verList;
	}
	/**
	 * set the vertexes of the graph
	 * @param verList
	 */
	public void setVerList(List<Vertex> verList) {
		this.verList = verList;
	}
	/**
	 * get the edges of the graph
	 * @return
	 */
	public List<Edge> getEdgeList() {
		return edgeList;
	}
	/**
	 * get the id of the graph
	 * @return
	 */
	public int getId(){
		return this.id;
	}
	/**
	 * set the edge list of the graph
	 * @param edgeList
	 */
	public void setEdgeList(List<Edge> edgeList) {
		this.edgeList = edgeList;
	}
	/**
	 * get the edge matrix of the graph
	 * @return
	 */
	public int[][] getMatrix() {
		return matrix;
	}
	/**
	 * get the degree of the given vertex's number
	 * include in degrees and out degrees
	 * @param number
	 * @return
	 */
	public int getDegree(int number){
		if(number > verList.size()){
			return 0;
		}
		int degree = 0;
		int v = verList.size();
		for(int i = 0; i < v; i++){
			degree += matrix[number][i];
		}
		return degree;
	}
	/**
	 * get the label of the given edge's start and end vertexes' id
	 * @param start
	 * @param end
	 * @return "NO" if there exits no such an edge
	 */
	public String getEdgeLabel(int start, int end){
		String label = "NO";
		if(start < verList.size() && end < verList.size()){
			if(matrix[start][end] == 0){
				return label;
			}
			for(Edge e : edgeList){
				if(e.isEqual(start, end)){
					label = e.getLabel();
				}
			}
		}
		
		return label;
	}
	
	@Override
	public String toString() {
		return "Graph [\n\nverList=\n" + verList + "\n\nedgeList=\n" + edgeList + "\n]\n\n";
	}
	

}
