Action()
{
	lr_start_transaction("01_Login");
		web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1733479031302\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);
	web_reg_find("Text=To make reservations,please enter your account information to the left.",LAST);



	lr_start_transaction("webtour_homepage");
web_reg_find("Text=To make reservations,please enter your account information to the left.",LAST);


	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Priority", 
		"u=0, i");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(18);

/*Correlation comment - Do not change!  Original value='140420.412312677HccciHtpQfiDDDDDtDDDHpctQHf' Name ='userSession' Type ='ResponseBased'*/
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

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("webtour_homepage",LR_AUTO);

	
	
	
	
	
	lr_start_transaction("login");

	
web_reg_find("Text=User password was correct",LAST);	
	
web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(14);

	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=47", ENDITEM,
		"Name=login.y", "Value=9", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	
	
	lr_start_transaction("transaction_logout");
	
web_reg_find("Text=To make reservations,please enter your account information to the left.",LAST);
	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(17);

	web_url("SignOff Button",
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t6.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("transaction_logout",LR_AUTO);
	
	
	
lr_end_transaction("01_Login",LR_AUTO);

	return 0;
}