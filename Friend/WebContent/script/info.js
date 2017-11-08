var jcrop_api,
    boundx,
    boundy,
    $preview = $('#preview-pane'),
    $pcnt = $('#preview-pane .preview-container'),
    $pimg = $('#preview-pane .preview-container img'),
    xsize = $pcnt.width(),
    ysize = $pcnt.height(),
    avatarnode,
    x,
    y,
    x2,
    y2,
    url,
    imgupload=false;

$(document).ready(function(){
	avatarnode = $("#avatar").clone().removeClass("hide");
	$("#test2").click(function(){
		upload();
	});
	$("#test").click(function(){
		alert("x:"+x+"y:"+y+"x2:"+x2+"y2:"+y2);
	});
	$("#updatebtn").click(function(){
		update();
	});
	$('.form_date').datetimepicker({
        language:  'zh-CN',
        weekStart: 1,
        todayBtn:  1,
		autoclose: 1,
		todayHighlight: 1,
		startView: 2,
		minView: 2,
		forceParse: 0
    });
	$("#head").live('change',function(){
		imgupload = true;
		upload();
	});
	
	$.ajax({
		type :"post",
		url : "./userInfo",
		dataType : "json",
		data : {
			method : 1,
		},
		success : function(json){
			for(var name in json)
			{
				if(name!='email'&&name!='head')
				{
					$("#"+name).val(json[name]+"");
				}
				if(json['head']!=''){
					$("#currenthead").removeClass("hide");
					$("#currenthead>img").attr({src:json['head']+ "?t=" + Math.random()});
				}
			}
		},
		error : function(json){
			alert("Network error！");
		}
		
	})
	
});
function updatePreview(c)
{
  if (parseInt(c.w) > 0)
  {
	  x=c.x;
	  y=c.y;
	  x2=c.x2;
	  y2=c.y2;
	  
    var rx = xsize / c.w;
    var ry = ysize / c.h;

    $pimg.css({
      width: Math.round(rx * boundx) + 'px',
      height: Math.round(ry * boundy) + 'px',
      marginLeft: '-' + Math.round(rx * c.x) + 'px',
      marginTop: '-' + Math.round(ry * c.y) + 'px'
    });
  }
};
function mycrop(){
	$('#target').Jcrop({
	  onChange: updatePreview,
	  onSelect: updatePreview,
	  aspectRatio: 1,
	  setSelect: [0,0,150,100],
	},function(){
	  // Use the API to get the real image size
	  var bounds = this.getBounds();
	  boundx = bounds[0];
	  boundy = bounds[1];
	  // Store the API in the jcrop_api variable
	  jcrop_api = this;
	
	  // Move the preview into the jcrop container for css positioning
	  $preview.appendTo(jcrop_api.ui.holder);
	});
};

function upload(){
	$.ajaxFileUpload({
        url:'./upload',            //需要链接到服务器地址
        secureuri:false,
        fileElementId:['head'],                         //文件选择框的id属性
        dataType: 'json',                                     //服务器返回的格式，可以是json
        success: function (json)             //相当于java中try语句块的用法
        {   
    	   $("#avatar").removeClass("hide");
    	   url = json['url'];
    	   var turl = url+ "?t=" + Math.random();
    	   $("#avatar img").attr({src:turl});
    	   mycrop();
    	   
        },
        error: function (json)   
        {
            alert("Network error");              
        }
      }
    );
};
function update(){
	if(imgupload&&typeof(x)=="undefined") alert("请描绘头像边框");
	else{
		$.ajax({
			type :"post",
			url : "./userInfo",
			dataType : "json",
			data : {
				method : 2,
				imageupload : imgupload,
				nick : $("#nick").val(),
				birthday : $("#birthday").val(),
				school : $("#school").val(),
				url : url,
				x : x,
				y : y,
				x2 : x2,
				y2 : y2
			},
			success : function(json){
				document.location.reload(); 
			},
			error : function(json){
				alert("Network error！");
			}
			
		});
	}
};