package com.pku.servlet;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.FileItemIterator;
import org.apache.commons.fileupload.FileItemStream;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import org.apache.commons.fileupload.util.Streams;

import net.sf.json.JSONObject;

public class UploadServlet extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html;charset=utf-8");
		

		String realDir = request.getSession().getServletContext().getRealPath(
				"");

		String basePath = request.getScheme() + "://" + request.getServerName()
				+ ":" + request.getServerPort() + request.getContextPath()
				+ "/";


		String filePath = "userfiles";
		String realPath = realDir + "\\" + filePath;
		String pattern = "[.]jpg|png|gif$";
		String backword = "success";
		File dir = new File(realPath);
		if (!dir.isDirectory())
			dir.mkdir();
		
		
		String email = (String)request.getSession().getAttribute("User");
		String realFileName;
		if(email==null)
		{
			PrintWriter pw = response.getWriter();
			pw.write("{\"info\":\"未登陆\"}");
			pw.flush();
			pw.close();
		}
		else
		{
			System.out.println("Start upload......");
			realPath +="\\";
			dir = new File(realPath+email);
			if (!dir.isDirectory())
				dir.mkdir();
			try {
				if (ServletFileUpload.isMultipartContent(request)) {
					DiskFileItemFactory dff = new DiskFileItemFactory();	
					dff.setRepository(dir);
					dff.setSizeThreshold(1024000);
					ServletFileUpload sfu = new ServletFileUpload(dff);
					sfu.setSizeMax(1024*1024*2);   //文件最大为2M
					FileItemIterator fii = sfu.getItemIterator(request);
					String title = "";
					String url = "";
					String fileName = "";
					realFileName = "";
					int k = 0;
					while (fii.hasNext()) {
						FileItemStream fis = fii.next();
						try {
							if (!fis.isFormField() && fis.getName().length() > 0) {
								fileName = fis.getName();
	
								Pattern reg = Pattern.compile(pattern);
								Matcher matcher = reg.matcher(fileName);
								if (!matcher.find()) {
									backword = "格式不匹配";
									break;
								}
								if(fis.getFieldName().equals("head"))
								{
									realFileName = "head_model"
											+ fileName.substring(fileName
													.lastIndexOf("."), fileName
													.length());
									url = realPath +email+ "\\" + realFileName;
								}
								if(fis.getFieldName().equals("statusimg"))
								{
									realFileName = (int) (System.currentTimeMillis()/1000)
											+ fileName.substring(fileName
													.lastIndexOf("."), fileName
													.length());
									url = realPath +email+ "\\" + realFileName;
								}
								
								BufferedInputStream in = new BufferedInputStream(
										fis.openStream());
	
								FileOutputStream a = new FileOutputStream(new File(
										url));
	
								BufferedOutputStream output = new BufferedOutputStream(
										a);
								Streams.copy(in, output, true);
	
							} else {
								
							}
	
						} catch (Exception e) {
							backword = "异常错误";
							
						}
						
							
						
					}
					System.out.println(basePath+"userfiles\\"+email+"\\"+realFileName);
					PrintWriter pw = response.getWriter();
					JSONObject j = new JSONObject();
					j.put("info", backword);
					j.put("url", "userfiles\\"+email+"\\"+realFileName);
					pw.write(j.toString());
					pw.flush();
					pw.close();
	
				}
			} catch (Exception ee) {
				ee.printStackTrace();
			}
		}
	}

}
