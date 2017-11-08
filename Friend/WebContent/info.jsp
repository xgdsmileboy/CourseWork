<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>
<%@ page import="com.pku.main.Friend"%>
<%@ page import="com.pku.entity.Person"%>
<!DOCTYPE HTML>
<html>
<%
	String email = (String) session.getAttribute("User");
	Boolean logged = false;
	String userName = "";

	Person p = new Person();
	if (email != null) {
		logged = true;
		p = Friend.getPerson(email);
	}

	if (email != null) {
		logged = true;
	} else {
%>

<script type="text/javascript">
	window.location = "index.jsp";
</script>
<%
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

/* Apply these styles only when #preview-pane has
   been placed within the Jcrop widget */
.jcrop-holder #preview-pane {
	display: block;
	position: absolute;
	z-index: 2000;
	top: 10px;
	right: -280px;
	padding: 6px;
	border: 1px rgba(0, 0, 0, .4) solid;
	background-color: white;
	-webkit-border-radius: 6px;
	-moz-border-radius: 6px;
	border-radius: 6px;
	-webkit-box-shadow: 1px 1px 5px 2px rgba(0, 0, 0, 0.2);
	-moz-box-shadow: 1px 1px 5px 2px rgba(0, 0, 0, 0.2);
	box-shadow: 1px 1px 5px 2px rgba(0, 0, 0, 0.2);
}

/* The Javascript code will set the aspect ratio of the crop
   area based on the size of the thumbnail preview,
   specified here */
#preview-pane .preview-container {
	width: 250px;
	height: 170px;
	overflow: hidden;
}
</style>

<link rel="stylesheet" type="text/css" href="css/bootstrap.css">
<link rel="stylesheet" type="text/css" href="css/messenger.css">
<link rel="stylesheet" type="text/css" href="css/jquery.Jcrop.min.css">
<link rel="stylesheet" type="text/css"
	href="css/bootstrap-datetimepicker.min.css">
</head>
<body>
	<div class="navbar navbar-default navbar-fixed-top"
		style="background-color: #B5B5B5" role="navigation">
		<div class="container">
			<div class="navbar-header">
				<a href="index.jsp" class="navbar-brand" style="color: white">Friend</a>
			</div>
			<div class="navbar-collapse collapse">
				<input type="hidden" id="iflogin" />

				<ul class="nav navbar-nav navbar-right">

					<%
						String str = "";
						if (logged == false) {

							str += "<li><a href=\"javascript:void(0)\" data-toggle=\"modal\" data-target=\"#loginModal\" style=\"color:white\">Login</a></li>";

							out.print(str);
						} else {
							String text = email;
							if (p.getNick() != null)
								text = p.getNick();
							str += "<li><a href=\"info.jsp\" class=\"userbutton\" style=\"color:white\">"
									+ "<span class=\"glyphicon glyphicon-user\"></span>" + " " + text + "</a></li>";

							out.print(str);
						}
					%>
				</ul>
			</div>
			<!--/.nav-collapse -->
		</div>
	</div>

	<div class="container" style="margin-bottom: 30px">
		<div class="col-md-10 col-md-offset-1">
			<form role="form">
				<div class="form-group">
					<label for="nick"> nick name </label> <input type="text"
						class="form-control" id="nick"
						placeholder="Please input nick name">
				</div>


				<div class="form-group">
					<label for="birthday"> Birthday </label>
					<div class="input-group date form_date col-md-5" data-date=""
						data-date-format="dd MM yyyy" data-link-field="dtp_input2"
						data-link-format="yyyy-mm-dd">
						<input class="form-control" size="16" type="text" value=""
							id="birthday" readonly> <span class="input-group-addon"><span
							class="glyphicon glyphicon-remove"></span></span> <span
							class="input-group-addon"><span
							class="glyphicon glyphicon-calendar"></span></span>
					</div>
					<input type="hidden" id="dtp_input2" value="" /><br />
				</div>

				<div class="form-group">
					<label for="school"> School </label> <input type="text"
						class="form-control" id="school"
						placeholder="Please input your school">
				</div>

				<div class="form-group">
					<label for="head"> Avatar </label>
					<div id="currenthead" class="hide">
						<label>Current avatar</label> <img src="" width="200px" />
					</div>

					<input type="file" id="head" name="head">
					<span class="help-block"></span>
				</div>
				<div class="hide" id="avatar" style="padding: 10px 0px 20px">
					<img alt="" src="" id="target" />
					<div id="preview-pane" width="90px" height="90px">
						<div class="preview-container">
							<img src="" id="preview" class="jcrop-preview" alt="Preview" />
						</div>
					</div>
				</div>
				<div class="text-center">
					<button type="button" id="updatebtn" class="btn btn-primary">
						Update</button>
				</div>
			</form>
		</div>
	</div>

	<script src="js/jquery.js"></script>
	<script src="js/jquery.Jcrop.js"></script>
	<script src="js/bootstrap.min.js"></script>
	<script src="js/ajaxfileupload.js"></script>
	<script src="js/bootstrap-datetimepicker.js"></script>
	<script src="js/bootstrap-datetimepicker.zh-CN.js"></script>
	<script src="script/info.js"></script>
</body>


</html>