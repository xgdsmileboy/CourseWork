package com.pku.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.pku.entity.Person;
import com.pku.main.Friend;
import com.pku.tools.ImageCutter;

import net.sf.json.JSONObject;

public class UserInfoServlet extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		
		String email = (String)request.getSession().getAttribute("User");
		int method = Integer.parseInt(request.getParameter("method"));
		System.out.println("*******method*****"+method);
		
		PrintWriter pw = response.getWriter();
		if(method == 1){//获取用户信息
			Person p = Friend.getUserInfo(email);
			JSONObject j = JSONObject.fromObject(p);
			pw.write(j.toString());
			pw.flush();
			pw.close();
		}else if (method == 2){//更新用户信息
			String back = "failure";
			try{
				Person p = new Person();
				System.out.println("*****update*******");
				Boolean b = Boolean.parseBoolean(request.getParameter("imageupload"));
				System.out.println("*****b*******"+b);
				if(b){
					String head_original = (String)request.getParameter("url");
		
					Double x = Double.parseDouble(request.getParameter("x"));
					Double y = Double.parseDouble(request.getParameter("y"));
					Double x2 = Double.parseDouble(request.getParameter("x2"));
					Double y2 = Double.parseDouble(request.getParameter("y2"));
					
					String realDir = request.getSession().getServletContext().getRealPath(
					"");
					String path = realDir+"\\"+ head_original;
					String ext = path.substring(path.lastIndexOf("."));
					
					String headPath = realDir+"\\userfiles\\"+email+"\\head"+ext;
					
					ImageCutter o = new ImageCutter(path, x.intValue(), y.intValue(), x2.intValue()-x.intValue(), y2.intValue()-y.intValue());
					o.setSubpath(headPath);
					o.cut();
					p.setHead("userfiles\\"+email+"\\head"+ext);
				}	
				p.setBirthday(request.getParameter("birthday"));
				p.setNick(request.getParameter("nick"));
				p.setSchool(request.getParameter("school"));
				p.setEmail(email);
				
				System.out.println(JSONObject.fromObject(p).toString());
				
				boolean result = Friend.setUserInfo(p);
				if(result) back = "success";
			}catch(Exception e){
				e.printStackTrace();
			}	
			JSONObject j = new JSONObject();
			j.put("info", back);
			pw.write(j.toString());
			pw.flush();
			pw.close();
		}
		
		
	}

}
