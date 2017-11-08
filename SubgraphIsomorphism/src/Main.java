import java.util.ArrayList;

import algorithm.Ullmann;
import structs.Edge;
import structs.Graph;
import structs.Vertex;

public class Main {
	
	public static void main(String args[]){
		
		ArrayList<Vertex> vertices = new ArrayList<>();
		vertices.add(new Vertex(1, ""));
		vertices.add(new Vertex(2, ""));
		vertices.add(new Vertex(3, ""));
		vertices.add(new Vertex(4, ""));
		vertices.add(new Vertex(5, ""));
		vertices.add(new Vertex(6, ""));
		vertices.add(new Vertex(7, ""));
		ArrayList<Edge> edges = new ArrayList<>();
		edges.add(new Edge(0, 1, ""));
		edges.add(new Edge(0, 2, ""));
		edges.add(new Edge(0, 4, ""));
		edges.add(new Edge(1, 2, ""));
		edges.add(new Edge(1, 5, ""));
		edges.add(new Edge(2, 3, ""));
		edges.add(new Edge(2, 4, ""));
		edges.add(new Edge(3, 4, ""));
		edges.add(new Edge(4, 6, ""));
		edges.add(new Edge(5, 6, ""));
		Graph graph = new Graph(0, vertices, edges);
		ArrayList<Vertex> vertices1 = new ArrayList<>();
		vertices1.add(new Vertex(1, ""));
		vertices1.add(new Vertex(2, ""));
		vertices1.add(new Vertex(3, ""));
		vertices1.add(new Vertex(4, ""));
		vertices1.add(new Vertex(5, ""));
		ArrayList<Edge> edges1 = new ArrayList<>();
		edges1.add(new Edge(0,1,""));
		edges1.add(new Edge(0,4,""));
		edges1.add(new Edge(1,2,""));
		edges1.add(new Edge(1,3,""));
		edges1.add(new Edge(2,3,""));
		edges1.add(new Edge(2,4,""));
		edges1.add(new Edge(3,4,""));
		Graph subGraph = new Graph(1, vertices1, edges1);
		Ullmann ullmann = new Ullmann(graph, subGraph);
		System.out.println(ullmann.isIsomorphism());
		
//		//query file
//		String queryFileName = Configure.q4file;
//		//result file
//		String resultFileName = "result_"+queryFileName;
//		//read graph database
//		List<Graph> graphDBList = ReadFile.Read(Configure.DBfile);
//		//read queried graph
//		List<Graph> queryList = ReadFile.Read(Configure.queryPath+queryFileName);
//		
//		File result = new File(Configure.resultpath+resultFileName);
//		if(!result.exists()){
//			try {
//				result.createNewFile();
//			} catch (IOException e) {
//				e.printStackTrace();
//			}
//		}
//		
//		BufferedWriter bw = null;
//		try {
//			bw = new BufferedWriter(new FileWriter(result));
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
//		int index = 1;
//		long t_start = System.currentTimeMillis();
//		int a = queryList.size();
//		for(Graph query : queryList){
//			int dbsize = graphDBList.size();
//			for(int i = 0; i < dbsize; i++){
//				Graph g = graphDBList.get(i);
//				Ullmann u = new Ullmann(g, query);
//				if(u.isIsomorphism()){
//					try {
////						bw.write(index++ +" : "+query.getId()+" -> "+g.getId()+"\n");
//						bw.write("==================="+ index++ +"=====================\n");
//						
//						bw.write("+++++++++++ source graph +++++++++++++\n");
//						bw.write(g.toString());
//						bw.write("+++++++++++ query graph +++++++++++++\n");
//						bw.write(query.toString());
//						
//						bw.write("========================================\n");
//					} catch (IOException e) {
//						e.printStackTrace();
//					}
//				}
//			}
//			System.out.println(a--);
//		}
//		long t_end =System.currentTimeMillis();
//		
//		try {
//			bw.write("\n\n Total Time : "+(t_end-t_start)+"ms.\n\n");
//		} catch (IOException e1) {
//			e1.printStackTrace();
//		}
//		
//		try {
//			bw.close();
//		} catch (IOException e) {
//			e.printStackTrace();
//		}
		

	}
}
