Action()
{
lr_start_transaction("04_itinerary");

	lr_start_transaction("1_webtour_homepage");
	
	
	web_reg_find("Text=To make reservations,please enter your account information to the left.",LAST);


	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Priority", 
		"u=0, i");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("header.html", 
		"URL=http://127.0.0.1:1080/WebTours/header.html", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

/*Correlation comment - Do not change!  Original value='140491.880842446HcczffVpVcAiDDDDtDDfQpDAzHcf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("webtour_homepage",LR_AUTO);

	lr_start_transaction("login");
	
	
web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",LAST);


	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(6);

/*Correlation comment - Do not change!  Original value='itinerary' Name ='page' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page",
		"RegExp=page=(.*?)\"\\ TARGET",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=81", ENDITEM,
		"Name=login.y", "Value=3", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	
	
	
	lr_start_transaction("show_Itinerary");

	
	
	
	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(5);

	



	web_reg_find("Search=Body",
		"TextPfx=<B>{firstName} {lastName}",
		"TextSfx='s Flight Transaction Summary</B>",
		LAST);

	web_url("Itinerary Button",
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page={page}",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t8.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("show_Itinerary",LR_AUTO);
	
lr_end_transaction("04_itinerary",LR_AUTO);
	return 0;
}