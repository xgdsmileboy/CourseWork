<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="com.pku.main.Friend" %>
<%@ page import="com.pku.entity.Person" %>
<!DOCTYPE HTML>
<html>
	<%
		String email = (String) session.getAttribute("User");
		String owner = request.getParameter("email");
		Boolean logged = false;
		String userName = "";
		Person p = new Person();
		if (email != null) {
			logged = true;
			p = Friend.getPerson(email);
		}
		Person powner = new Person();
		if(owner!=null){
			powner = Friend.getPerson(owner);
		}
	%>
	<head>
		<link rel="shortcut icon" href="images/favicon.ico" />
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<title>Friend</title>
		<style type="text/css">
body {
	padding-top: 70px;
}

.center-block {
	display: block;
	margin-left: auto;
	margin-right: auto;
}

.tab-pane {
	padding-top: 30px;
}

.buttons button {
	margin-top: 10px;
}
.statustime{
	float:right;
}


#statusimgbtn1{ position:absolute; z-index:100; margin-left:-180px; font-size:60px;opacity:0;filter:alpha(opacity=0); margin-top:-5px;} 

</style>

		<link rel="stylesheet" type="text/css" href="css/bootstrap.css">
		<link rel="stylesheet" type="text/css" href="css/messenger.css">
		<link rel="stylesheet" type="text/css"
			href="css/messenger-theme-flat.css">
	</head>
	<body>
		<input type="hidden" id="owner" value="<%=request.getParameter("email") %>"/>
		
		<div class="navbar navbar-default navbar-fixed-top"
			style="background-color: #B5B5B5" role="navigation">
			<div class="container">
				<div class="navbar-header">
				<a href="index.jsp" class="navbar-brand" style="color:white">Friend</a>
				</div>
				<div class="navbar-collapse collapse">
					<input type="hidden" id="iflogin" />

					<ul class="nav navbar-nav navbar-right">
						<%
							String str = "";
							if (logged == false) {
								str += "<li><a href=\"javascript:void(0)\" data-toggle=\"modal\"data-target=\"#registryModal\" style=\"color: white\"> Register </a></li>";
								str += "<li><a href=\"javascript:void(0)\" data-toggle=\"modal\" data-target=\"#loginModal\" style=\"color:white\">Login</a></li>";

								out.print(str);
							} else {
								String text = p.getNick();
								if(text==null) text = email; 
								str += "<li><a href=\"info.jsp\" class=\"userbutton\" style=\"color:white\">"
										+ "<span class=\"glyphicon glyphicon-user\"></span>"
										+ " " + text + "</a></li>";
								str += "<li><a href=\"javascript:void(0)\" class=\"logout\" style=\"color:white\">Logout</a></li>";
								out.print(str);
							}
						%>
					</ul>
				</div>
				<!--/.nav-collapse -->
			</div>
		</div>

		<%
			if (logged == true) {
		%>

		<div class="container" id="welcome">
			<div class="tabbale col-md-9 col-md-offset-1">
				
				<h3><span style="color:red"><%=powner.getNick() %></span>' Events</h3>
				<div id="statuscontainer">
					<div class="panel panel-default hide status">
					  <div class="panel-heading">
					    <h3 class="panel-title"></h3>
					  </div>
					  <div class="panel-body">
					  </div>
					</div>
				</div>
				
			</div>

			<div class="col-md-2">
				
				<div class="list-group" id="friendslist">
					<a class="list-group-item list-group-item-info disabled">Friends</a>
				</div>
				
				<div class="list-group recoommend-list" id="friendsrecomend">
					<a class="list-group-item list-group-item-info disabled">Recommendation</a>
				</div>

			</div>
		</div>
		<%
			} else {
		%>
		<script>window.location.href="index.jsp";</script>

		<%
			}
		%>




		

		<div class="modal fade" id="loginModal" tabindex="-1" role="dialog"
			aria-labelledby="myModalLabel2" aria-hidden="true">
			<div class="modal-dialog">
				<div class="modal-content">
					<div class="modal-header" style="background-color: #B5B5B5">
						<button type="button" class="close" data-dismiss="modal"
							aria-hidden="true">
							&times;
						</button>
						<h4 class="modal-title" id="myModalLabel2" style="color: white">
							Login
						</h4>
					</div>
					<div class="modal-body">

						<form class="form-horizontal" action="./login" method="post"
							role="form">

							<div class="form-group">
								<label for="lemail" class="col-md-2 control-label">
									Email
								</label>
								<div class="col-md-6">
									<input type="text" class="form-control" id="lemail"
										placeholder="">
								</div>
							</div>

							<div class="form-group">
								<label for="lpassword" class="col-md-2 control-label">
									Password
								</label>
								<div class="col-md-6">
									<input type="password" class="form-control" id="lpassword"
										placeholder="">
								</div>
							</div>


						</form>

					</div>
					<div class="modal-footer">
						<button type="button" class="btn btn-success" data-dismiss="modal"
							data-toggle="modal" data-target="#registryModal">
							Register
						</button>
						<button type="submit" class="btn btn-danger" id="loginbutton"
							data-loading-text="Login...">
							Login
						</button>
					</div>
				</div>
				<!-- /.modal-content -->
			</div>
			<!-- /.modal-dialog -->
		</div>
		<!-- /.modal -->
		
		
		
	<div class="modal fade" id="registryModal" tabindex="-1" role="dialog"
			aria-labelledby="myModalLabel" aria-hidden="true">
			<div class="modal-dialog">
				<div class="modal-content">
					<div class="modal-header" style="background-color: #B5B5B5">
						<button type="button" class="close" data-dismiss="modal"
							aria-hidden="true">
							&times;
						</button>
						<h4 class="modal-title" id="myModalLabel" style="color: white">
							Register
						</h4>
					</div>
					<div class="modal-body" >

						<form class="form-horizontal" action="./registry" method="post"
							role="form">

							<div class="form-group">
								<label for="remail" class="col-md-2 control-label">
									Email
								</label>
								<div class="col-md-6">
									<input type="text" class="form-control" id="remail"
										placeholder="">
								</div>
							</div>

							<div class="form-group">
								<label for="rpassword" class="col-md-2 control-label">
								  Password
								</label>
								<div class="col-md-6">
									<input type="password" class="form-control" id="rpassword"
										placeholder="">
								</div>
							</div>

							<div class="form-group">
								<label for="rpassword2" class="col-md-2 control-label">
									Confirm
								</label>
								<div class="col-md-6">
									<input type="password" class="form-control" id="rpassword2"
										placeholder="">
								</div>
							</div>


						</form>
					</div>
					<div class="modal-footer">
						<button type="button" class="btn btn-success"  data-dismiss="modal">
							Close
						</button>
						<button type="submit"  class="btn btn-danger" id="registrybutton"
							data-loading-text="Register...">
							Register
						</button>
					</div>
				</div>
				<!-- /.modal-content -->
			</div>
			<!-- /.modal-dialog -->
		</div>
		<!-- /.modal -->




		<script src="js/jquery.js"></script>
		<script src="js/bootstrap.min.js"></script>
		<script src="js/ajaxfileupload.js"></script>
		<script src="js/messenger.min.js"></script>
		<script src="script/homepage.js"></script>
		<%
			if (logged) {
				out.print("<script>load();</script>");
			}
		%>

	</body>

</html>
