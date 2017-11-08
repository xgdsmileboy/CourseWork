package com.pku.servlet;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.http.HttpServlet;

import org.neo4j.graphdb.Transaction;

import com.pku.db.Database;
import com.pku.main.Friend;

public class InitServlet extends HttpServlet implements ServletContextListener{
		//服务器关闭时执行
		public void contextDestroyed(ServletContextEvent arg0) {
		//	Database.getInstance().shutdown();
		}
		//服务器启动时执行
		public void contextInitialized(ServletContextEvent arg0) {
			Database db = Database.getInstance();
			db.initDB();
			
		}

}
