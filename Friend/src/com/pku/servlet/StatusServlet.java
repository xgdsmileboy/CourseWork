package com.pku.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Vector;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.pku.entity.Status;
import com.pku.main.Friend;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

public class StatusServlet extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");

		String email = (String) request.getSession().getAttribute("User");
		String method = request.getParameter("method");
		PrintWriter pw = response.getWriter();
		if("add".equals(method)){
			
			String imgurl = (String) request.getParameter("statusimgpath");
			System.out.println("imgurl"+imgurl);
			Status s = new Status();
			s.setEmail(email);
			s.setContent(request.getParameter("content"));
			s.setCreateat((int) (System.currentTimeMillis()/1000));
			
			s.setImage(imgurl);
			
			JSONObject j = new JSONObject();
			
			if(Friend.postStatus(s)){
				j.put("info", "success");
			}else j.put("info", "failure");
			
			pw.write(j.toString());
			pw.flush();
			pw.close();
		}else{
			Vector<Status> status = null;
			String owner = request.getParameter("owner");
			if(owner==null)
				status = Friend.getStatus(email);
			else
				status = Friend.getSingleStatus(owner);
			
			JSONArray array = new JSONArray();
			for (int i = 0; i < status.size(); i++) {
				JSONObject j = JSONObject.fromObject(status.get(i));
				array.add(j);
			}
			pw.write(array.toString());
			pw.flush();
			pw.close();
		}

	}

}
