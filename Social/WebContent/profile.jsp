<%@ page contentType="text/html; charset=gbk" language="java"%>
<html xmlns="http://www.w3.org/1999/xhtml"><head>
<%@ page import="java.util.*"%>
<%@ page import="java.io.*"%>
<%@ page import="com.actionForm.*"%>
<%@ page import="com.core.*" %>
<%@ page import="com.dao.*" %>
<%@ page import="org.neo4j.graphdb.*" %>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>ͬ����-��������Ѷ���æЩʲô��</title>
<link href="styles/MyWB.css" type="text/css" rel="stylesheet">
<link href="styles/global.css" type="text/css" rel="stylesheet">
<script language="javascript">
<!--

window.onload = function(){
}
-->
</script>
</head>

<%
	String id = (String)session.getAttribute("id");
	String name = (String)session.getAttribute("name");
	if (id == null || "".equals(id)){
		response.sendRedirect("index.jsp");
	} 
	String qid = id;
	AccountDAO accountDAO = new AccountDAO();
	AccountForm account = accountDAO.getAccountForm(qid);
	Collection<String> friendList = accountDAO.getFriendList(qid);
	Collection<StatusForm> statuses = accountDAO.getPersonalStatuses(qid);
	Iterator<StatusForm> it = statuses.iterator();
	int statusCount = statuses.size();
/* 	System.out.println(form.getFavoriteActivity()); */
%>
<body>
<!-- ������ container�� ʼ-->
<div id="container">
    <!-- topDIV ��ʼ -->
    <div id="top">
      <!-- top���ֵ�LogoDIV -->
    	<div id="topLogo">
        	<!-- topLogo���ֵ�icoDIV -->
            <div id="topLogoIco"> <a href="mainpage.html"><img src="images/weblogo.jpg" width="72" height="72" alt=""></a>
            </div>
            <!-- topLogo���ֵ�icoDIV���� -->
      </div>
        <!-- top���ֵ�LogoDIV���� -->
        
        <!-- top���ֵ����ֵ��� -->
        <div id="topWordMenu">
        	<ul>
            	<li><a href="mainpage.jsp">��ҳ</a></li>
                <li><a href=<%out.println("home.jsp?id="+id);%>>�ҵ�״̬</a></li>
                <li><a href="profile.jsp">����</a></li>
                <li><a href="logout.jsp">�˳�</a></li>
            </ul>
        </div>
        <!-- top���ֵ����ֵ������� -->
    </div>
    <!-- topDIv ����-->
    <!-- ���������� mainDIV �� ʼ-->
<div id="main">
		<!-- ���mainBannerDIV ��ʼ -->
      	<div id="mainBanner">
            <!-- ���mainBannerTopDIV ��ʼ -->
            <div id="mainBannerTop">
                <!-- ���mainBannerTopImgDIV ��ʼ -->
                <div id="mainBannerTopImg">
                  <img src="images/head1.jpg" width="80" height="80" alt="" title="">
                </div>
                <% out.println("<div id='mainBannerTopWord'><font color='#330000' size='5'><b>"+account.getName()+"</b></font><br>"); %>
                <% out.println(account.getGender()+"<br>"+account.getBirthday()); %>
                </div>
            	<!-- ���mainBannerTopWordDIV ���� -->
            </div>
            <!-- ���mainBannerTopDIV ���� -->
            <!-- ���mainBannerMenuDIV ��ʼ -->
            <!-- banner����DIV -->
            <div id="mainBannerMenu">
                <!-- ���mainBannerMenuTopDIV ��ʼ -->
                <div id="mainBannerMenuTop">
                    <!-- ���mainBannerMenuTopWord1DIV ��ʼ -->
                    <div id="mainBannerMenuTopWord1"><b>����</b>
                    </div></div></div>
    <div id="banner">
        <!-- banner���ֵ�leftDIV -->
        <div class="left" id="left">
        <form id="form1" action="account?action=updateProfile"
		method="post">
            <table width="564" border="0" cellpadding="0" cellspacing="0" class="left">
                <!-- �ǳ� -->
                <tbody><tr>
                    <td width="120" height="50" align="right"><strong>����ǳ�</strong></td>
                    <td width="20" height="60">&nbsp;</td>
                    <td width="425" height="60"><label>
                         <input name="name" type="text" class="n1" id="name" value=<%=account.getName() %>>
<br>
                              �����ǳƽ���ʾ��������ҳ��</label></td>
                </tr>
                
                
                <!-- ���� -->
                <tr>
                    <td width="120" height="49" align="right"><strong>����</strong></td>
                    <td width="20" height="49">&nbsp;</td>
                    <td width="425" height="49"><label>
                         <input name="birthday" type="text" class="n3" id="birthday" value=<%=account.getBirthday() %>>
                             </label></td>
                </tr>
                <!-- ��ַ -->
                <tr>
                    <td width="120" height="52" align="right"><strong>��ַ</strong></td>
                    <td width="20" height="52">&nbsp;</td>
                    <td width="425" height="52">
                    <label>
                      <input name="hometown" type="text" class="n3" id="hometown" value=<%=account.getHometown() %>>
                    </label>
            <label>
              <br>
              �����ģ�������Χ�ĸ���������ҵ���</label></td>
                </tr>
                <!-- ϲ���˶� -->
                <tr>
                    <td width="120" height="68" align="right"><strong>ϲ���˶�</strong></td>
                    <td width="20" height="68">&nbsp;</td>
                    <td width="425" height="68"><label>
                        <input name="activity" type="text" class="n1" id="activity" value=<%=account.getFavoriteActivity() %>>
                        <br>
                         ˵����ϲ���˶�</label></td>
                </tr>
                <!-- ����ǩ�� -->
                <tr>
                    <td width="120" height="180" align="right"><strong>ϲ����ʳ��</strong></td>
                    <td width="20" height="180">&nbsp;</td>
                    <td width="425" height="180">
                       <div>
                            <label>
                                  <input name="food" type="text" class="n1" id="food" value=<%=account.getFavoriteFood() %>>
                            </label>
                       </div></td>
                </tr>
                <!-- ���水ť -->
                <tr>
                    <td width="120" height="20" align="right">&nbsp;</td>
                    <td width="20" height="44">&nbsp;</td>
                    <td width="425" height="44"><label>
                         <input name="button" type="submit" class="btn" id="button" value="����">
                            </label></td>
                </tr>
            </tbody></table></form>
        </div>
        <!-- banner_left����DIV���� -->
        <!-- banner_right����DIV -->
        <div class="right" id="right">
           <p>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp������
              ��������������˺ŵĻ�����Ϣ����˽��Ϣ��</p>
        </div>
        <!-- banner_right����DIV���� -->
    </div>
    <!-- banner����DIV���� -->
<%--             <div id="mainBannerMenu">
                <!-- ���mainBannerMenuTopDIV ��ʼ -->
                <div id="mainBannerMenuTop">
                    <!-- ���mainBannerMenuTopWord1DIV ��ʼ -->
                   
                    <!-- ���mainBannerMenuTopWord1DIV ����-->
                    <!-- ���mainBannerMenuTopWord2DIV ��ʼ -->
                    <%
                    if (qid.equals(id)) {
                    	out.println("<div id='mainBannerMenuTopWord2'><img src='images/mainBannerMenuTopWord2.gif' title='' alt=''><a href='mainpage.jsp'>��״̬</a></div>");
                    }
                    %>
                    <!-- ���mainBannerMenuTopWord2DIV ���� -->
                </div>
            	<!-- ���mainBannerMenuTopDIV ����-->
            </div> --%>
            <!-- ���mainBannerMenu DIV ����-->
            <!--�Լ���΢���ĵط�-->
            <div id="mainBannerContent"> 
                <!--��΢����λ-->
               <div id="mainBannerContent1">
                    <!--��΢����λ-->
                  <div id="mainBannerContent2">
                     <!--����΢��-->
 
                       <!-- ��һ����΢�� mainBannerContent2PeopleImg DIV ��ʼ -->

                  </div>  
                  <!--��΢����λ����-->
               </div>
                 <!--��΢����λ����-->
            </div>
             <!--�Լ���΢���ĵط�����-->
        </div>
        <!-- ���mainBannerDIV ���� -->                       
        <!-- �Ҳ�mainRight DIV��ʼ -->
        <div id="mainRight">
            <div id="mainRight1">
               <!-- �Ҳ�mainRightPostionFirstLine DIV ��ʼ -->
                <div id="mainRightPostionFirstLine">
                    <!-- �Ҳ�mainRightPostionFirstLineIcon DIV ��ʼ -->
                    <div id="mainRightPostionFirstLineIcon">
                    <a href="#"><img src="images/head1.jpg" alt="" width="48" height="48" align="absmiddle" title="" border="0"></a>
                    </div>
                    <!-- �Ҳ�mainRightPostionFirstLineIcon DIV ���� -->
                    <!-- �Ҳ�mainRightPostionFirstLineWord1 DIV ��ʼ -->
                    <div id="mainRightPostionFirstLineWord1">                 
                    &nbsp;<font color="#005DC3"><b><a href=<% out.println("home.jsp?id="+qid); %> class="a1"><% out.println(account.getName()); %></a></b></font><br>
                    <% out.println(account.getHometown()); %>
                    </div>
                    <!-- �Ҳ�mainRightPostionFirstLineWord1 DIV ���� -->
                    <!-- �Ҳ�mainRightPostionFirstLineWord2 DIV ��ʼ -->
                    <div id="mainRightPostionFirstLineWord2">
                    <ul id="ul1">
                    <li><font class="style1"><%out.println(statusCount); %></font><br><font class="style2">������</font></li>
                    <li><a href=<% out.println("friend.jsp?userid="+qid) ;%> class="a1"><font class="style1"><%out.println(friendList.size()); %></font><br><font class="style2">����</font></a></li>
                    </ul>
                    </div>
                <!-- �Ҳ�mainRightPostionFirstLineWord2 DIV ���� -->                    
                </div>
                <!-- �Ҳ�mainRightPostionFirstLine DIV ���� -->
              </div>
                <!-- �Ҳ�mainRightPostionSixthLine DIV ��ʼ -->

        </div>         
  </div>
  <!-- ���������� mainDIV ����-->
  <!-- footer���� -->
  <div id="footer">
      <!-- footer��վ��Ȩ��Ϣ -->
      <div id="footerCopy">
       	  ͬ������Ȩ����
      </div>
      <!-- footer��վ��Ȩ��Ϣ���� -->
  </div>
  <!-- footer���ֽ��� --> 
</div>
<!--������ container����-->


</body></html>