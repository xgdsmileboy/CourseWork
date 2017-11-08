package com.pku.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.neo4j.graphdb.Node;

import com.pku.config.Config;
import com.pku.entity.Person;
import com.pku.main.Friend;

public class FriendServlet extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");

		String email = (String) request.getSession().getAttribute("User");
		
		Integer method = Integer.parseInt(request.getParameter("method"));
		
		if(method==0){//º”‘ÿ∫√”—
			String owner = request.getParameter("owner");
			List<Person> list = null;
			
			if(owner==null)
				list = Friend.getFriends(email);
			else{
				System.out.println("Homepage:"+owner);
				list = Friend.getFriends(owner);
			}
			
			JSONArray array = new JSONArray();
			for (int i = 0; i < list.size(); i++) {
				JSONObject j = JSONObject.fromObject(list.get(i));
				array.add(j);
			}
	
			PrintWriter pw = response.getWriter();
			pw.write(array.toString());
			pw.flush();
			pw.close();
		}else if(method == 1){//À—À˜∫√”—
			String nick = (String) request.getParameter("nick");
			
			System.out.println("nick:"+nick+"   email:"+email);
			
			List<Person> list = Friend.PersonSearch(nick,email);
			
			JSONArray array = new JSONArray();
			for (int i = 0; i < list.size(); i++) {
				JSONObject j = JSONObject.fromObject(list.get(i));
				array.add(j);
			}
			PrintWriter pw = response.getWriter();
			pw.write(array.toString());
			System.out.println(array.toString());
			pw.flush();
			pw.close();
			
		}else if(method == 2){
			String femail = (String) request.getParameter("email");
			
			System.out.println("   femail:"+femail);
			Friend.makeFriends(email, femail);
			
			JSONObject j = new JSONObject();
			j.put("info", "success");
			PrintWriter pw = response.getWriter();
			pw.write(j.toString());
			pw.flush();
			pw.close();
			
		}

	}

}
