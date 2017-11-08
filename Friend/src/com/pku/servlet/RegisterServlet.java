package com.pku.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.pku.main.Friend;

public class RegisterServlet extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");

		String email = request.getParameter("email");
		String password = request.getParameter("password");
		


		int register = Friend.register(email, password);
		String json = null;// = "{\"info\":\"time_out\"}";
		
		System.out.println("register");

		System.out.println(email+" ** "+password+"  "+register);
		System.out.println("D");
		switch(register){
			case 1:
				HttpSession hs = request.getSession();
				hs.setAttribute("User", email);
				json = "{\"info\":\""+register+"\"}";
				//response.sendRedirect("/Campus/index.jsp");
			break;
			default:
				json = "{\"info\":\""+register+"\"}";
		}
		PrintWriter pw = response.getWriter();
		pw.write(json);
		pw.flush();
		pw.close();
	}

}
