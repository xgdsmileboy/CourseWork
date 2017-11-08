package com.pku.db;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Vector;

import org.neo4j.graphdb.GraphDatabaseService;
import org.neo4j.graphdb.Node;
import org.neo4j.graphdb.Transaction;
import org.neo4j.graphdb.factory.GraphDatabaseFactory;
import org.neo4j.graphdb.index.Index;
import org.neo4j.kernel.impl.util.FileUtils;

import com.pku.entity.Person;
import com.pku.entity.Status;
import com.pku.main.Friend;


public class Database {
	private static final String DB_PATH = "/Users/Jiajun/Documents/friends.db";
	private GraphDatabaseService graphDB;
	private Index<Node> nodeIndex;
	private static Database db = new Database();
	
	public static Database getInstance(){
		return db;
	}
	public Database(){
		clearDB(); 
		createDB();
		System.out.println("Database loaded.....");
	}
	public Transaction beginTx(){
		return graphDB.beginTx();
	}
	
	public GraphDatabaseService getGraphDB() {
		return graphDB;
	}
	public Index<Node> getNodeIndex() {
		return nodeIndex;
	}
	public Node createNode(){
		return graphDB.createNode();
	}
	
	public void clearDB() {
		try {
			FileUtils.deleteRecursively(new File(DB_PATH));
		}
		catch(IOException e) {
			throw new RuntimeException(e);
		}
	}
	private void createDB() {
		graphDB = new GraphDatabaseFactory().newEmbeddedDatabase(DB_PATH);
		
		registerShutdownHook(graphDB);
		
		Transaction tx = graphDB.beginTx();
		try {
			nodeIndex = graphDB.index().forNodes("nodes");
			tx.success();
		}
		finally {
			tx.close();
		}
	}
	

	public void initDB(){
		
		Transaction tx = graphDB.beginTx();
		try {
			//clearDB();
			String temp = "";
			String[] S;
			Person p = new Person();
			Status s = new Status();
			
			try
			{
			FileReader fr = new FileReader("/Users/Jiajun/Documents/Vertex.txt");
			BufferedReader br = new BufferedReader(fr);
			FileReader fr2 = new FileReader("/Users/Jiajun/Documents/Edge.txt");
			BufferedReader br2 = new BufferedReader(fr2);
			Vector<String> PeopleSave = new Vector<String>();
			int i = 0;
			boolean Skip = false;
			int StatusCounter = 1;
			
			temp = br.readLine();
			while(temp!=null && temp.length()!=0){
				
				System.out.println(temp);
				
				Skip = false;
				for (i=0;i<temp.length();i++)
				{
					if (temp.charAt(i)<0 && temp.charAt(i)>127)
					{
						Skip = true;
						break;
					}
				}
				if (Skip){continue;}
				S = temp.split(",");
				
				for(String sr : S){
					System.out.println(sr);
				}
				
				PeopleSave.add(S[0]);
				Friend.register(S[0]+"@pku.edu.cn", "123456");
				p = new Person(S[0]+"@pku.edu.cn",S[0],S[1], null, "Peking University");
				Friend.setUserInfo(p);
				s = new Status(S[2],StatusCounter++,null,S[0]+"@pku.edu.cn");
				Friend.postStatus(s);
				s = new Status(S[3],StatusCounter++,null,S[0]+"@pku.edu.cn");
				Friend.postStatus(s);
				temp=br.readLine();
			}
			
			temp = br2.readLine();
			while(temp!=null && temp.length()!=0){
				Skip = false;
				for (i=0;i<temp.length();i++)
				{
					if (temp.charAt(i)<0 && temp.charAt(i)>127)
					{
						Skip = true;
						break;
					}
				}
				if (Skip){continue;}
				S = temp.split(",");
				if (PeopleSave.contains(S[0]) && PeopleSave.contains(S[1]))
				{
					Friend.makeFriends(S[0]+"@pku.edu.cn", S[1]+"@pku.edu.cn");
				}
				temp = br2.readLine();
			}

            br.close();
            br2.close();
			}
			catch(Exception e)
			{
				System.out.println("init failed");
				e.printStackTrace();
			}
			
			tx.success();
		}
		finally {
			tx.close();
		}
	}


	private static void registerShutdownHook(final GraphDatabaseService graphDB) {
		Runtime.getRuntime().addShutdownHook(new Thread() {
			@Override
			public void run() {
				graphDB.shutdown();
			}
		});
	}
	public void shutdown() {
		graphDB.shutdown();
	}
	public static void main(String args[]){
		Database db = Database.getInstance();
		db.initDB();
	}

}
