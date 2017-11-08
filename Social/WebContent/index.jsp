<!DOCTYPE html>
<html style="height:100%"><head>
	<title>Login Social Network</title>
	<meta name="keywords" content="">
	<meta name="description" content="">
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	
	<link href="css/font-awesome.min.css" rel="stylesheet" type="text/css">
	<link href="css/bootstrap.min.css" rel="stylesheet" type="text/css">
	<link href="css/bootstrap-theme.min.css" rel="stylesheet" type="text/css">
	<link href="css/bootstrap-social.css" rel="stylesheet" type="text/css">	
	<link href="css/templatemo_style.css" rel="stylesheet" type="text/css">	
</head>
<script language="javascript">
	function check(form){
		if (form.name.value==""){
			alert("user name cannot be null");
			form.name.focus();
			return false;
		}
		if (form.pwd.value==""){
			alert("password cannot be null");
			form.pwd.focus();
			return false;
		}
	}
</script>
<body background="images/background.jpg" style="background-size:cover;height:100%;">
	<div class="container">
		<div class="col-md-12" align="center">			
			<form id = "form1" class="form-horizontal templatemo-login-form-2" role="form" action="account?action=login" method="post">
				<div class="row">
					<div class="col-md-12">
						<h1>Login</h1>
					</div>
				</div>
				<div class="row">
					<div class="templatemo-one-signin col-md-6">
				        <div class="form-group">
				          <div class="col-md-12">		          	
				            <label for="username" class="control-label">username</label>
				            <div class="templatemo-input-icon-container">
				            	<i class="fa fa-user"></i>
				            	<input type="text" class="form-control" id="name" name="name" placeholder="">
				            </div>		            		            		            
				          </div>              
				        </div>
				        <div class="form-group">
				          <div class="col-md-12">
				            <label for="password" class="control-label">password</label>
				            <div class="templatemo-input-icon-container">
				            	<i class="fa fa-lock"></i>
				            	<input type="password" class="form-control" id="pwd" name="pwd" placeholder="">
				            </div>
				          </div>
				        </div>
				        <div class="form-group">
				          <div class="col-md-12">
				            <div class="checkbox">
				                <label>
				                  <input type="checkbox">Auto login next time.</label>
				            </div>
				          </div>
				        </div>
				        <div class="form-group">
				          <div class="col-md-12">
				            <input type="submit" value="Login" class="btn btn-warning" onclick="return check(form1)">
				          </div>
				        </div>
				        <div class="form-group">
				          	<div class="col-md-12">
				        		<a href="register.jsp" class="text-center">Register</a>
				       	 	</div>
				    	</div>
					</div>
					   
				</div>				 	
		      </form>		      		      
		</div>
	</div>

</body></html>