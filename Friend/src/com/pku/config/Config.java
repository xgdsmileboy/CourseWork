package com.pku.config;

import org.neo4j.graphdb.RelationshipType;

public class Config {
	public static final String PASSWORD_KEY = "password";
	//PERSON property key
    public static final String PRIMARY_KEY = "email";
    public static final String HEAD_KEY = "head";
    public static final String BIRTHDAY_KEY = "birthday";
    public static final String NICK_KEY = "nick";
    public static final String SCHOOL_KEY = "school";
    //STATUS property key
    public static final String CREATEAT_KEY = "createat";
    public static final String CONTENT_KEY = "content";
    public static final String IMAGE_KEY = "image";
    
    
	public static enum RelTypes implements RelationshipType {
		FRIEND,
		STATUS,
		NEXT
	}
	

}
