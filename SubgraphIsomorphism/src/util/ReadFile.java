package util;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import structs.Edge;
import structs.Graph;
import structs.Vertex;
/**
 * function class, read source file and convert the input data to graph structure
 * @author Jiajun
 *
 */
public class ReadFile {
	/**
	 * construct the graph structure from given file path
	 * @param fileName
	 * @return
	 */
	public static List<Graph> Read(String fileName){
		List graphList = new ArrayList<Graph>();
		
		BufferedReader br = null;
		
		try {
			br = new BufferedReader(new FileReader(fileName));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		String line = null;
		try {
			line = br.readLine().trim();
			while(line != null){
				if(line.trim().length() == 0){
					line = br.readLine().trim();
					continue;
				}
				if(line.startsWith("t")){
					String str[] = line.split(" ");
					int index = Integer.parseInt(str[2]);
					List<Vertex> vList = new ArrayList();
					List<Edge> eList = new ArrayList();
					while((line = br.readLine()) != null && line.trim().length() > 0){
						String tokens[] = line.split(" ");
						if(line.startsWith("v")){
							if(tokens.length != 3){
								System.out.println("Read data error! #ReadFile.java @34 : data format error.");
								continue;
							}
							vList.add(new Vertex(Integer.parseInt(tokens[1]), tokens[2]));
							
						}else if(line.startsWith("e")){
							if(tokens.length != 4){
								System.out.println("Read data error! #ReadFile.java @34 : data format error.");
								continue;
							}
							eList.add(new Edge(Integer.parseInt(tokens[1]), Integer.parseInt(tokens[2]), tokens[3]));
							
						}else if(line.startsWith("t")){
							break;
						} else {
							System.out.println("Read data error! #ReadFile.java @41 : UNKNOWN DATA");
							System.err.println(">>> "+line);
						}
					}
					if(vList.size() > 0){
						graphList.add(new Graph(index, vList, eList));
					}
				}
			}
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return graphList;
	}
}
