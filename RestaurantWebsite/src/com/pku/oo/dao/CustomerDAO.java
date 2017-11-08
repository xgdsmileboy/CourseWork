package com.pku.oo.dao;

import java.sql.Connection;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import com.pku.oo.bean.Customer;
import com.pku.oo.util.ConnectionFactory;

public class CustomerDAO {

	public int addCustomer(Customer cus) {
		int count = 0;
		Connection con = null;
		PreparedStatement pstmt = null;

		try {
			con = ConnectionFactory.CreateConnection();
			pstmt = con.prepareStatement("INSERT into customer  values(?,?,?,?,?,?,?,?)");

			pstmt.setString(1, cus.getId());
			pstmt.setString(2, cus.getName());
			pstmt.setString(3, cus.getAddress());
			pstmt.setString(4, cus.getZip());
			pstmt.setString(5, cus.getLandmark());
			pstmt.setLong(6, cus.getCellnumber());
			pstmt.setString(7, cus.getEmail());

			count = pstmt.executeUpdate();
			System.out.println(count);

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			if (con != null)
				try {
					con.close();
					if (pstmt != null)
						pstmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

		}

		return count;
	}

	public Customer viewCustomer(String id) {
		Customer c = null;
		Connection con = null;
		PreparedStatement pstmt = null;
		ResultSet rs = null;

		try {
			con = ConnectionFactory.CreateConnection();
			pstmt = con.prepareStatement("select * from customer where user_id=?");

			pstmt.setString(1, id);
			rs = pstmt.executeQuery();
			boolean b = rs.next();
			if (!b)
				return new Customer("DEFAULT", "NONE", "Not available", "000000", "None", 1234567890,
						"notreal@nowhere.org");
			String name = rs.getString("username");
			String add = rs.getString("address");
			String zip = rs.getString("zip");
			String ln = rs.getString("landmark");
			long no = rs.getLong("cellnumber");
			String mail = rs.getString("email");
			// String name= rs.getString("name");

			c = new Customer(id, name, add, zip, ln, no, mail);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {

			try {
				if (con != null)
					con.close();
				if (pstmt != null)
					pstmt.close();
				if (rs != null)
					rs.close();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
		return c;
	}

	public int updateCustomer(Customer cus) {
		int count = 0;
		Connection con = null;
		PreparedStatement pstmt = null;
		try {
			con = ConnectionFactory.CreateConnection();
			pstmt = con.prepareStatement(
					"UPDATE customer set username=?,  address=?,  zipcode=?,  landmark=?, cellnumber=?, email=? where user_id = ?");
			pstmt.setString(1, cus.getName());
			pstmt.setString(2, cus.getAddress());
			pstmt.setString(3, cus.getZip());
			pstmt.setString(4, cus.getLandmark());
			pstmt.setLong(5, cus.getCellnumber());
			pstmt.setString(6, cus.getEmail());
			pstmt.setString(7, cus.getId());
			count = pstmt.executeUpdate();
			System.out.println(count);

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			if (con != null)
				try {
					con.close();
					if (pstmt != null)
						pstmt.close();
				} catch (SQLException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

		}
		return count;
	}

}
