package com.pku.entity;

public class Person {
	private String email;
	private String nick;
	private String birthday;
	private String head;
	private String school;

	public Person() {
	}

	public Person(String email, String nick, String birthday, String head,
			String school) {
		super();
		this.email = email;
		this.nick = nick;
		this.birthday = birthday;
		this.head = head;
		this.school = school;
	}

	public String getNick() {
		return nick;
	}

	public void setNick(String nick) {
		this.nick = nick;
	}

	public String getBirthday() {
		return birthday;
	}

	public void setBirthday(String birthday) {
		this.birthday = birthday;
	}

	public String getHead() {
		return head;
	}

	public void setHead(String head) {
		this.head = head;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public void setSchool(String school) {
		this.school = school;
	}

	public String getSchool() {
		return school;
	}

}
