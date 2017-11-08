package com.pku.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.pku.main.Friend;


public class LoginServlet extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");

		String email = request.getParameter("email");
		String password = request.getParameter("password");
		
		
		int login = Friend.login(email, password);
		System.out.println("Login:"+email+" result:"+login);
		String json = null;// = "{\"info\":\"time_out\"}";
		switch(login){
			case 1:
				HttpSession hs = request.getSession();
				hs.setAttribute("User", email);
			default:
				json = "{\"info\":\""+login+"\"}";
				PrintWriter pw = response.getWriter();
				pw.write(json);
				pw.flush();
				pw.close();
		}
	}

}
