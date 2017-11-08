package com.pku.servlet;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.http.HttpServlet;

import org.neo4j.graphdb.Transaction;

import com.pku.db.Database;
import com.pku.main.Friend;

public class InitServlet extends HttpServlet implements ServletContextListener{
		//�������ر�ʱִ��
		public void contextDestroyed(ServletContextEvent arg0) {
		//	Database.getInstance().shutdown();
		}
		//����������ʱִ��
		public void contextInitialized(ServletContextEvent arg0) {
			Database db = Database.getInstance();
			db.initDB();
			
		}

}
