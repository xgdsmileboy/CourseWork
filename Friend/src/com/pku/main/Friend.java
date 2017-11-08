package com.pku.main;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.Vector;

import org.neo4j.graphdb.Direction;
import org.neo4j.graphdb.Node;
import org.neo4j.graphdb.Path;
import org.neo4j.graphdb.Relationship;
import org.neo4j.graphdb.Transaction;
import org.neo4j.graphdb.index.Index;
import org.neo4j.graphdb.traversal.Evaluation;
import org.neo4j.graphdb.traversal.Evaluator;
import org.neo4j.graphdb.traversal.TraversalDescription;
import org.neo4j.graphdb.traversal.Traverser;
import org.neo4j.graphdb.traversal.Uniqueness;
import org.neo4j.kernel.Traversal;

import com.pku.config.Config;
import com.pku.db.Database;
import com.pku.entity.Person;
import com.pku.entity.Status;
public class Friend {
	private static Database db = Database.getInstance();
	
	/**
	 * @desc �û���¼
	 * @param email ��¼����
	 * @param password ��¼����
	 * @return -2���ݿ���� -1�û��������� 0�������   1��¼�ɹ�
	 */
	public static int login(String email,String password){
		//System.out.println("Campus login"+email);
		Transaction t = db.beginTx();
		try{
			Index<Node> index = db.getNodeIndex();
			Node n = index.get(Config.PRIMARY_KEY, email).getSingle();
			t.success();
			if(n!=null){
				String temp = (String) n.getProperty(Config.PASSWORD_KEY);
				if(password.equals(temp)) return 1;
				else return 0;
			}else return -1;
		}catch(Exception e){
			return -2;
		}finally{
			t.finish();
		}
		
	}
	/**
	 * @desc �û�ע��
	 * @param email ע������
	 * @param password ע������
	 * @return -2���ݿ���� -1�����Ѿ����� 1ע��ɹ�
	 */
	public static int register(String email,String password){
		Transaction t = db.beginTx();
		int result = -2;
		try{
			Index<Node> index = db.getNodeIndex();
			Node node = index.get(Config.PRIMARY_KEY, email).getSingle();
			if(node!=null) {
				result = -1;
			}
			else{
	            node = db.createNode();
	            node.setProperty( Config.PRIMARY_KEY, email );
	            node.setProperty(  Config.PASSWORD_KEY, password );
	            index.add(node,  Config.PRIMARY_KEY, node.getProperty(Config.PRIMARY_KEY));
	            result = 1;
			}
			t.success();
		}catch(Exception e){
		}
		finally{
			t.finish();
		}
		return result;
	}
	
	/**
	 * @desc ����email��ȡPerson����
	 * @param email Ŀ������
	 * @return Person����
	 */
	public static Person getPerson(String email){
		Transaction t = db.beginTx();
		Person p = new Person();
		try{
			Index<Node> index = db.getNodeIndex();
			Node person = index.get(Config.PRIMARY_KEY, email).getSingle();
			p = getPersonUsingNode(person);
		}finally{
			t.close();
		}
		return p;
	}
	
	/**
	 * @desc ��Ӻ���
	 * @param email1 ������
	 * @param email2 ������
	 */
	public static void makeFriends(String email1,String email2){
		Transaction t = db.beginTx();
		try{
			Index<Node> index = db.getNodeIndex();
			Node n1 = index.get(Config.PRIMARY_KEY, email1).getSingle();
			Node n2 = index.get(Config.PRIMARY_KEY, email2).getSingle();
			Relationship rel = n1.createRelationshipTo(n2, Config.RelTypes.FRIEND);
			t.success();
		}catch(Exception e){
			
		}finally{
			t.close();
		}
	}
	/**
	 * @desc ����һ���˵ĺ����б�
	 * @param email Ŀ������
	 * @return �����б�
	 */
	public static List<Person> getFriends(String email){
		ArrayList<Person> list = new ArrayList<Person>();
		TraversalDescription td = Traversal.description()
		.breadthFirst()
		.relationships(Config.RelTypes.FRIEND, Direction.OUTGOING)
		.evaluator(
				new Evaluator(){
					public Evaluation evaluate(Path path) {
						if(path.length()==0) return Evaluation.EXCLUDE_AND_CONTINUE;
						if(path.length()==1) return Evaluation.of(true, false);
						return null;
					}			
				}
				
		)
		.uniqueness(Uniqueness.NODE_GLOBAL);
		Transaction trans = db.beginTx();
		try{
			Node person = db.getNodeIndex().get(Config.PRIMARY_KEY, email).getSingle();
			Traverser t = td.traverse(person);
			for(Path friendPath:t){
				Node endNode = friendPath.endNode();
				Person p = getPersonUsingNode(endNode);
				list.add(p);
			}
			trans.success();
		}finally{
			trans.close();
		}
		return list;
	}
	
	/**
	 * @desc ����һ���˵�����״̬
	 * @param email Ŀ������
	 * @return ״̬�б�
	 */
	public static Vector<Status> getSingleStatus(String email){
		Transaction t = db.beginTx();
		Vector<Status> v = new Vector<Status>();
		try{

			Node person = db.getNodeIndex().get(Config.PRIMARY_KEY,email).getSingle();
			Iterator<Relationship> i = person.getRelationships(Direction.OUTGOING, Config.RelTypes.STATUS).iterator();
			if(i.hasNext()){
				TraversalDescription traversal = db.getGraphDB().traversalDescription().depthFirst().relationships(Config.RelTypes.NEXT);
				Traverser statuspath = traversal.traverse(i.next().getEndNode());
				for(Path p:statuspath){
					Node endNode = p.endNode();
					//��ȡ���е�Status������
					Status s = getStatusUsingNode(endNode);
					v.add(s);
				}
			}
			t.success();
		}finally{
			t.finish();
		}
		return v;
	}
	
	/**
	 * @desc ����һ���˵�����Ȧ
	 * @param email Ŀ������
	 * @return ״̬�б�
	 */
	public static Vector<Status> getStatus(String email){
		Transaction t = db.beginTx();
		Vector<Status> v = new Vector<Status>();
		try{
			Node person = db.getNodeIndex().get(Config.PRIMARY_KEY,email).getSingle();
			Iterator<Relationship> i = person.getRelationships(Direction.OUTGOING, Config.RelTypes.STATUS).iterator();
			Vector<Node> firstStatusNode = new Vector<Node>();//��ȡ�������ѵ�״̬�Լ��Լ���״̬�ĵ�һ���ڵ�
			if(i.hasNext()){
				firstStatusNode.add(i.next().getEndNode());
			}
			//Traversal
			TraversalDescription traversal = db.getGraphDB().traversalDescription().depthFirst().relationships(Config.RelTypes.NEXT);
			
			//�ҵ����е�����
			Iterator<Relationship> fi = person.getRelationships(Direction.OUTGOING, Config.RelTypes.FRIEND).iterator();
			while(fi.hasNext()){//����ÿһ�����ѽڵ�,����������״̬�ڵ�
				Node n = fi.next().getEndNode();
				Iterator<Relationship> itr = n.getRelationships(Direction.OUTGOING, Config.RelTypes.STATUS).iterator();
				if(itr.hasNext()){
					//System.out.println("Friend node added!");
					firstStatusNode.add(itr.next().getEndNode());
				}
			}
			
			//������������״̬�ڵ㣬��traverse
			for(int j=0;j<firstStatusNode.size();j++){
				Traverser statuspath = traversal.traverse(firstStatusNode.get(j));
				for(Path p:statuspath){
					Node endNode = p.endNode();
					//��ȡ���е�Status������
					Status s = getStatusUsingNode(endNode);
					v.add(s);
				}
			}
			t.success();
		}finally{
			t.close();
		}
		Comparator ct = new Comparator(){

			public int compare(Object arg0, Object arg1) {
				Status s1 = (Status) arg0;
				Status s2 = (Status) arg1;
				if(s1.getCreateat()>s2.getCreateat()) return -1;
				else if(s1.getCreateat()<s2.getCreateat()) return 1;
				else return 0;
			}
			
		};
		Collections.sort(v,ct);
		
		
		return v;
	}
	public static boolean postStatus(Status status){
		Transaction t = db.beginTx();
		try{
			Node person = db.getNodeIndex().get(Config.PRIMARY_KEY,status.getEmail()).getSingle();
			if(person!=null){
				Iterator<Relationship> i = person.getRelationships(Direction.OUTGOING, Config.RelTypes.STATUS).iterator();
				
				//�����½ڵ�
				Node newupdated = db.createNode();
				newupdated.setProperty(Config.CONTENT_KEY, status.getContent());
				newupdated.setProperty(Config.CREATEAT_KEY, status.getCreateat());
				newupdated.setProperty(Config.PRIMARY_KEY,status.getEmail());
				
				if(status.getImage()!=null)
					newupdated.setProperty(Config.IMAGE_KEY,status.getImage());
				
				if(i.hasNext()){
					Relationship r = i.next();//��״̬
					Node lastupdated = r.getEndNode();
					r.delete();
					
					
					person.createRelationshipTo(newupdated, Config.RelTypes.STATUS);
					newupdated.createRelationshipTo(lastupdated, Config.RelTypes.NEXT);
				}else{
					person.createRelationshipTo(newupdated, Config.RelTypes.STATUS);
				}
			}
			t.success();
			return true;
		}catch(Exception e){
			e.printStackTrace();
			return false;
		}finally{
		
			t.close();
		}
	}
	
	public static boolean setUserInfo(Person p){
		Transaction t = db.beginTx();
		try{
			Node person = db.getNodeIndex().get(Config.PRIMARY_KEY, p.getEmail()).getSingle();
			if(person!=null){
				person.setProperty(Config.NICK_KEY,p.getNick());
				person.setProperty(Config.BIRTHDAY_KEY, p.getBirthday());
				if(p.getHead()!=null)
				person.setProperty(Config.HEAD_KEY, p.getHead());
				person.setProperty(Config.SCHOOL_KEY, p.getSchool());
			}
			t.success();
			return true;
		}catch(Exception e){
			e.printStackTrace();
			return false;
		}finally{
			t.close();
		}
	}
	
	public static Person getUserInfo(String email){
		Transaction t = db.beginTx();
		Person p = null;
		try{
			Node person = db.getNodeIndex().get(Config.PRIMARY_KEY, email).getSingle();
			if(person!=null){
				p = new Person();
				if(person.hasProperty(Config.NICK_KEY))
				p.setNick((String)person.getProperty(Config.NICK_KEY));
				if(person.hasProperty(Config.BIRTHDAY_KEY))
				p.setBirthday((String)person.getProperty(Config.BIRTHDAY_KEY));
				if(person.hasProperty(Config.HEAD_KEY))
				p.setHead((String)person.getProperty(Config.HEAD_KEY));
				if(person.hasProperty(Config.SCHOOL_KEY))
				p.setSchool((String)person.getProperty(Config.SCHOOL_KEY));
				System.out.println("get user info successfully");
			}
			t.success();
		}finally{
			t.close();
		}
		return p;
	}
	
	private static Person getPersonUsingNode(Node person){
		Person p = new Person();
		//email
		p.setEmail((String)person.getProperty(Config.PRIMARY_KEY));
		//nick
		if(person.hasProperty(Config.NICK_KEY))
		p.setNick((String)person.getProperty(Config.NICK_KEY));
		//birth
		if(person.hasProperty(Config.BIRTHDAY_KEY))
		p.setBirthday((String)person.getProperty(Config.BIRTHDAY_KEY));
		//head
		if(person.hasProperty(Config.HEAD_KEY))
		p.setHead((String)person.getProperty(Config.HEAD_KEY));
		//school
		if(person.hasProperty(Config.SCHOOL_KEY))
		p.setSchool((String)person.getProperty(Config.SCHOOL_KEY));
		return p;
	}
	
	private static Status getStatusUsingNode(Node status){
		Status s = new Status();
		s.setContent((String) status.getProperty(Config.CONTENT_KEY));
		s.setCreateat((Integer) status.getProperty(Config.CREATEAT_KEY));
		String email = (String) status.getProperty(Config.PRIMARY_KEY);
		s.setEmail(email);
		if(status.hasProperty(Config.IMAGE_KEY))
			s.setImage((String) status.getProperty(Config.IMAGE_KEY));
		
		Index<Node> index = db.getNodeIndex();
		Node person = index.get(Config.PRIMARY_KEY, email).getSingle();
		s.setPoster(email);
		if(person.hasProperty(Config.NICK_KEY)){
			s.setPoster((String)person.getProperty(Config.NICK_KEY));
		}
		
		return s;
	}
	
	public static List<Person> PersonSearch(String NickName,String email){
		List<Person> _ret = new ArrayList<Person> ();
		Transaction t = db.beginTx();
		try{
			for (Node n : db.getGraphDB().getAllNodes())
			{
				if (n.hasProperty(Config.NICK_KEY))
				{
					if (n.getProperty(Config.NICK_KEY).toString().contains(NickName))
					{
						if(!email.equals(n.getProperty(Config.PRIMARY_KEY).toString()))
							_ret.add(getPersonUsingNode(n));
					}
				}
			}
			t.success();
		}finally{
			t.close();
		}
		return _ret;
	}



}
