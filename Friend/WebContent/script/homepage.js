function trim(str)
{
	return str.replace(/(^\s*)|(\s*$)/g, "");
}
function getLocalTime(nS) {     
	   return new Date(parseInt(nS) * 1000).toLocaleString().replace(/:\d{1,2}$/,' ');     
	   }  
$(document).ready(function(){

	bindButtonFunction();
	
});

function bindButtonFunction()
{
	$("#statusimg").live('change',function(){
		upload();
	});
	
	$("#search").click(function(){
		search();
	});
	
	$(".myaddmsg").click(function(){
		$(this).next().show();
		$(this).hide();
	});
	
	$(".linktowelcome").click(function(){
		towelcomepage();
	});
	$("#loginbutton").click(function(){
		
		login();
	});
	$("#registrybutton").click(function(){
		
		registry();
	});
	$("#submitbutton").click(function(){
		
		update();
	});
	$(".userbutton").click(function(){
		$("#welcome").css('display','none');
		$("#userpage").css('display','block');
		
	});
	$(".logout").click(function(){
		logout();
	});
	$("#statusbtn").click(function(){
		poststatus();
	});
	$("#statusimgbtn").click(function(){
		updatestatusimg();
	});
	
}
function myalert(msg,sec,type)
{
	if(!sec) sec=3;
	if(!type) type='error';
	$.globalMessenger().post({
			message: msg,
			hideAfter: sec,
			type:type,
			showCloseButton:true,
			//id:'myerror',
			//singleton:true
	}
	);
}
function login()
{
	$("#loginbutton").button('loading');

	$.ajax({
		type :"post",
		url : "./login",
		dataType : "json",
		data : {
			email : $("#lemail").val(),
			password : $("#lpassword").val()
		},
		success : function(json){
			alert("login:"+json['info']);
			if(json['info']==-1){
				alert("user not exists");
			}else if(json['info']==-2){
				alert("database error");
			}else if(json['info']==0){
				alert("passsword error");
			}else document.location.reload(); 
			
			$("#loginbutton").button('reset');
		},
		error : function(xml){
			alert("Network error！");
			$("#loginbutton").button('reset');
		}
		
	});

	
}
function logout()
{
	$.ajax({
		type :"post",
		url : "./logout",
		success:function(){
			document.location.reload(); 
		},
	})
}
function registry()
{
	$("#registrybutton").button('loading');
	var flag = true;
	var email = trim($("#remail").val());
	var reg = /^([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+@([a-zA-Z0-9]+[_|\_|\.]?)*[a-zA-Z0-9]+\.[a-zA-Z]{2,3}$/;
	var msg = "";

	if(email=="")
	{
		msg += "Please input email ";
		flag = false;
	}
	else if(!reg.test(email))
	{
		msg += "invalid email format";
		flag = false;
	}
	var psw = $("#rpassword").val();
	var psw2 = $("#rpassword2").val();
	if(psw.length<6||psw.length>14)
	{
		msg += "the length of password should be 6-14  ";
		flag = false;
	}
	else if(psw!=psw2)
	{
		msg += "password not convergent ";
		flag = false;
	}

	
	if(flag)
	{
	
		$.ajax({
			type :"post",
			url : "./register",
			dataType : "json",
			data : {
				email : trim($("#remail").val()),
				password : $("#rpassword").val()
			},
			success : function(json){
				if(json['info']==-1){
					alert("Email exists");
				}else if(json['info']==-2){
					alert("database error");
				}else document.location.reload(); 
				$("#registrybutton").button('reset');
			},
			error : function(json){
				alert("Network error！");
				$("#registrybutton").button('reset');
			}
			
		})
	}
	else
	{
		alert(msg);
		$("#registrybutton").button('reset');
	}

}
function load(){
	$.ajax({
		type :"post",
		url : "./friend",
		dataType : "json",
		data : {
			method:0,
			owner:$("#owner").val(),
		},
		success : function(json){
			for(var i=0;i<json.length;i++){
				$("#friendslist").append('<a href="homepage.jsp?email='+json[i]['email']+"\" class=\"list-group-item list-group-item-warning\"><img width=\"30px\" class=\"person_head\" src=\""+json[i]['head']+"\"/>&nbsp;&nbsp;"+json[i]['nick']+"</a>");
			}
		},
		error : function(xml){
			alert("Network error！");
		}
		
	});
	
	$.ajax({
		type :"post",
		url : "./status",
		dataType : "json",
		data : {
			owner:$("#owner").val(),
		},
		success : function(json){
			for(var i=0;i<json.length;i++){
				var node = $(".status:first").clone().removeClass("hide");
				node.find(".panel-title").html(json[i]['poster']+'<span class="statustime">'+getLocalTime(json[i]['createat'])+'</span>');
				node.find(".panel-body").html('<p>'+json[i]['content']+'</p>');
				node.appendTo($("#statuscontainer"));
				if(json[i]['image']!=""){
					node.find(".panel-body").append('<img src="'+json[i]['image']+'"/>');
				}
				
			}
		},
		error : function(xml){
			alert("Network error！");
		}
		
	});
	
}
function poststatus(){
	//alert($("#content").val());
	$.ajax({
		type :"post",
		url : "./status",
		dataType : "json",
		data : {
			method : 'add',
			content : $("#content").val(),
			statusimgpath : $("#statusimgpath").val()
		},
		success : function(json){
			if(json['info']=="success"){
				document.location.reload();
			}
		},
		error : function(xml){
			alert("Network error！");
		}
		
	});
}

function search(){
	$.ajax({
		type :"post",
		url : "./friend",
		dataType : "json",
		data : {
			method:1,
			nick:$("#name").val(),
		},
		success : function(json){
			$("#searchfriendslist").empty();
			for(var i=0;i<json.length;i++){
				$("#searchfriendslist").append("<li class=\"list-group-item list-group-item-warning\"><img width=\"30px\" class=\"person_head\" src=\""+json[i]['head']+"\"/>&nbsp;&nbsp;"+json[i]['nick']+'<span class="glyphicon glyphicon-plus" style="float:right" onClick=makefriend(\''+json[i]['email']+'\');></span></li>');
			}
		},
		error : function(xml){
			alert("Network error！");
		}
		
	});
}
function makefriend(a){
	$.ajax({
		type :"post",
		url : "./friend",
		dataType : "json",
		data : {
			method:2,
			email:a,
		},
		success : function(json){
			alert(json['info']);
		},
		error : function(xml){
			alert("Network error！");
		}
		
	});
}
function upload(){
	$.ajaxFileUpload({
        url:'./upload',            //需要链接到服务器地址
        secureuri:false,
        fileElementId:['statusimg'],                         //文件选择框的id属性
        dataType: 'json',                                     //服务器返回的格式，可以是json
        success: function (json)             //相当于java中try语句块的用法
        {   
    	   var url = json['url'];
    	   $("#statusimgpath").val(url);
    	   $("#statusimgshow").attr({src:url+ "?t=" + Math.random()});
        },
        error: function (json)   
        {
            alert("Network error");              
        }
      }
    );
};
function updatestatusimg(){
		$("#statusimgdiv").show();
}

