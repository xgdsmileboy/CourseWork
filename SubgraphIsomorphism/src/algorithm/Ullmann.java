package algorithm;

import java.util.List;

import structs.Graph;
import structs.Vertex;
import sun.tools.jar.resources.jar;
/**
 * Algorithm class
 * This is the core class include the core algorithm of sub-graph isomorphism query
 * Ullmann Algorithm with refinement
 * @author Jiajun
 *
 */
public class Ullmann {
	/*
	 * a graph in the data base
	 */
	Graph graph;
	/*
	 * a graph to be queried
	 */
	Graph query;
	/**
	 * constructor
	 * @param graph: a graph in database
	 * @param query: a graph to be queried
	 */
	public Ullmann(Graph graph, Graph query){
		this.graph = graph;
		this.query = query;
	}
	/**
	 * refinement, if current matching matrix contains at least one row that contains no '1'
	 * the matching can terminate
	 * @param M0
	 * @return
	 */
	private boolean refinement(int[][] M0){
		int[][] MA = query.getMatrix();
		int[][] MB = graph.getMatrix();
		
		for(int i = 0; i < MA.length; i++){
			for(int j = 0; j < MB.length; j++){
				if(M0[i][j] == 1){
					if(!fullFillRefine(i, j, MA, MB, M0)){
						M0[i][j] = 0;
					}
				}
			}
		}
		
		for(int i = 0; i < MA.length; i++){
			int sum = 0;
			for(int j = 0; j < MB.length; j++){
				sum += M0[i][j];
			}
			if(sum == 0){
				return false;
			}
		}
		
		return true;
	}
	/**
	 * refinement, judging the '1' in the M0 whether can be fulfilled
	 * @param row: the row of the '1'
	 * @param col: the column of the '1'
	 * @param MA: the matrix of queried graph
	 * @param MB: the matrix of a graph in database
	 * @param M0: the matching matrix
	 * @return
	 */
	private boolean fullFillRefine(int row, int col, int[][] MA, int[][] MB, int[][] M0){
		boolean flag = true;
		if(row < MA.length && col < MB.length){
			for(int i = 0; i < MA.length; i++){
				if(MA[row][i] == 1){
					int j;
					for(j = 0; j < MB.length; j++){
						if(M0[i][j] * MB[j][col] == 1 && graph.getEdgeLabel(j, col).equals(query.getEdgeLabel(row, i))){
							break;
						}
					}
					if(j == MB.length){
						return false;
					}
				}
			}
		}
		return flag;
	}
	/**
	 * compute matching matrix M0 using Ullmann Algorithm
	 * @return
	 */
	private int[][] computeM0(){
		List<Vertex> query_vertex_list = query.getVerList();
		List<Vertex> vertex_list = graph.getVerList();
		int n = query_vertex_list.size();
		int m = vertex_list.size();
		int[][] M0 = new int[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(query_vertex_list.get(i).getLabel().equals(vertex_list.get(j).getLabel())
						&& query.getDegree(i) <= graph.getDegree(j)){
					M0[i][j] = 1;
				}else{
					M0[i][j] = 0;
				}
			}
		}
		return M0;
	}
	/**
	 * verifying the current matching M0 using the following expression
	 * M0*(M0*MB)'
	 * @param M0: matching matrix
	 * @return
	 */
	private boolean verifying(int[][] M0){
		int[][] MA = query.getMatrix();
		int[][] MB = graph.getMatrix();
		int row = MA.length;
		int col = MB.length;
		
		int[][] TM = new int[col][row];
		for(int i = 0; i < row; i ++){
			for(int j = 0; j < col; j++){
				int temp = 0;
				for(int k = 0; k < col; k++){
					temp += M0[i][k] * MB[k][j];
				}
				TM[j][i] = temp;
			}
		}
		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < row; j++){
				int temp = 0;
				for(int k = 0; k < col; k++){
					temp += M0[i][k]*TM[k][j];
				}
				if(MA[i][j] == 1 && temp == 0){
					return false;
				}
			}
		}
		
		return true;
	}
	/**
	 * judging the given place whether can be set to '1'
	 * condition: there exists no '1' in the same column of the previous rows
	 * @param row: the row of the place
	 * @param col: the column of the place
	 * @param enumM0: the matrix to be judged
	 * @return
	 */
	public boolean canplace(int row, int col, int[][] enumM0){
		for(int i = 0; i < row; i++){
			if(enumM0[i][col] == 1){
				return false;
			}
		}
		return true;
	}
	/**
	 * enumerate all possible matching matrix M0' recursively
	 * @param row: the row of the matching matrix to be considered
	 * @param M0: the original matching matrix which contains all the matching message
	 * @param enumM0: current M0'
	 * @return
	 */
	public boolean enumerateAllPossibleM0(int row, int[][] M0, int[][] enumM0){
		
		if(row == M0.length){
			return verifying(M0);
		}
		
		int columns = M0[0].length;
		for(int i = 0; i < columns; i++){
			if(M0[row][i] == 1 && canplace(row, i, enumM0)){
				enumM0[row][i] = 1;
				
				for(int cy = i + 1; cy < columns; cy ++){
					enumM0[row][cy] = 0;
				}
				
				int[][] itorM0 = deepClone(enumM0);
				
				if(refinement(itorM0) && enumerateAllPossibleM0(row+1, M0, itorM0)){
					return true;
				}
				enumM0[row][i] = 0;
			}
		}
		
		return false;
	}
	/**
	 * copy a matrix 
	 * @param mat: the matrix to be copied
	 * @return
	 */
	private int[][] deepClone(int[][] mat){
		int row = mat.length;
		int col = mat[0].length;
		int[][] copy = new int[row][col];
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				copy[i][j] = mat[i][j];
			}
		}
		return copy;
	}
	/**
	 * judging the {@link #query} is isomorphism with {@link #graph}} or not
	 * @return
	 */
	public boolean isIsomorphism(){
		
		int[][] M0 = computeM0();
		
		if(!refinement(M0)){
			return false;
		}
		
		int[][] enumM0 = deepClone(M0);
		
		if(enumerateAllPossibleM0(0, M0, enumM0)){
			return true;
		}
		
		return false;
	}
	
}
