package com.pku.oo.util;

public class QueryConstants {

	// Admin Queries
	public static final String A_LOGIN = "select * from admin where admin_id=? AND admin_password=?";

	// Menu Queries
	public static final String M_ADD = "insert into menu values (?,?,?,?)";
	public static final String M_UPDATE = "UPDATE menu set description =?, price=? where item=?";
	public static final String M_VIEW = ("select category,item, description, price  from menu where item=?");
	public static final String M_DELETE = ("DELETE FROM menu WHERE item=?");
	public static final String M_VIEWALL = ("SELECT * FROM menu");

	public static final String C_ADD = "insert into registers values(?,?)";

	public static final String FIND_PASSWORD = "SELECT password FROM registers WHERE username = ?";
	public static final String CC_INSERT = "INSERT INTO credit_card VALUES (?,?,?,?,?,?,?)";

	// Orders Queries
	public static final String O_INSERT = "insert into orders values (?,?,?,?,?,?,?,?)";
	public static final String O_SELECT = "SELECT * FROM orders WHERE order_id=?";
	public static final String O_SELECTORDER = "select * from orders order by= ?";
	public static final String O_GETALL_FRONT = "select * from orders INNER JOIN customer "
			+ "ON orders.user_id = customer.user_id ORDER BY ";
	public static final String O_GETALL_BACK = " ASC";
	public static final String O_SELECT_ORDER_CUSTOMER = "SELECT * FROM orders WHERE user_id=?";
	public static final String O_DELETE = "delete from orders where orders_id=?";
	public static final String O_UPDATE = "UPDATE orders set pament_type =?, deli_address=?, quantity=? where order_id=?";
	public static final String O_SELECT_ONE = "select * from orders where order_id=?";

	// Generate Bill
	public static final String GENERATE = "SELECT * FROM " + "orders O, customer R "
			+ "WHERE O.user_id=R.user_id AND O.order_id=?";
}
