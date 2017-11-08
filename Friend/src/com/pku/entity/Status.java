package com.pku.entity;

public class Status {
	private String content;
	private int createat;
	private String image;
	private String email;//post by email
	private String poster;
	public Status(){
		
	}
	public Status(String content, int createat, String image, String email) {
		super();
		this.content = content;
		this.createat = createat;
		this.image = image;
		this.email = email;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	

	public String getImage() {
		return image;
	}
	public void setImage(String image) {
		this.image = image;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getEmail() {
		return email;
	}
	public void setCreateat(int createat) {
		this.createat = createat;
	}
	public int getCreateat() {
		return createat;
	}
	public void setPoster(String poster) {
		this.poster = poster;
	}
	public String getPoster() {
		return poster;
	}

}
