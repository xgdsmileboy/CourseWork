package com.pku.oo.service;

import com.pku.oo.bean.Customer;

public class UserNameGenerator {

	public static String GenerateUserName(Customer cust) {
		String ema = cust.getEmail().split("@")[0];
		long ber = cust.getCellnumber();
		// String zip = cust.getZip();
		return ema + ber;
	}
}
