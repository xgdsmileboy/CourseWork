<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<link rel= "stylesheet" type="text/css" href="<%=request.getContextPath()%>/css/Restaurant.css">
<title>Login Failed</title>
</head>
<body>

<div id ="templatemo_container">

	

	<div id="templatemo_topsection">Menu Management System</div>

	 <div id="templatemo_headersection"><img src="<%=request.getContextPath()%>/img/templatemo_header_photo.jpg" class="reflect rheight20 ropacity25" alt="templatemo.com" width="806" height="166"  /></div>
	
	<div id="templatemo_content_section">

	<center> <h1><marquee behavior="alternate" >User Login Fail. please try again.</marquee></h1></center>	</div>
	
	<a href = "<%=request.getContextPath()%>/Jsp/UserLogin.jsp">Login</a>
	<div id="templatemo_footer">
  </div>
	
</body>
</html>