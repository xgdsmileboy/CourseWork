package com.pku.oo.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ConnectionFactory {

	public static Connection CreateConnection() {
		Connection con = null;
		try {
			Class.forName(Constant.DRIVER);
			con = DriverManager.getConnection(Constant.DBURL, Constant.DBUSERNAME, Constant.DBUSERPASSWORD);
		} catch (ClassNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return con;

	}
	
	public static void main(String[] args) {
		Connection conn = ConnectionFactory.CreateConnection();
		try {
			PreparedStatement psmt = conn.prepareStatement("select * from admin where admin_id =1 and admin_password='000000'");
//			psmt.setInt(1, 1);
//			psmt.setString(2, "000000");
			ResultSet rs = psmt.executeQuery();
			while(rs.next()){
				int id = rs.getInt("admin_id");
				String pass = rs.getString("admin_password");
				System.out.println(id+" "+pass);
			}
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		try {
			conn.close();
		} catch (SQLException e) {
			if(conn != null){
				try {
					conn.close();
				} catch (SQLException e1) {
					e1.printStackTrace();
				}
			}
		}
		
	}
	
}