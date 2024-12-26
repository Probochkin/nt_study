Action()
{

	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1734526584639\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/

	lr_start_transaction("1_transaction");

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

	lr_think_time(4);

	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("1_transaction",LR_AUTO);

	lr_start_transaction("2_transaction");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(4);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=140504.622033212HccHcAzptQfiDDDDtDDzDpcDiQHf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=29", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("2_transaction",LR_AUTO);

	lr_start_transaction("3_transaction");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(4);

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3_transaction",LR_AUTO);

	lr_start_transaction("4_transaction");

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	lr_think_time(16);

	web_submit_data("itinerary.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=210297049-795-JB", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297049-1564-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-2333-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-3102-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-3872-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-4641-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-5410-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-6179-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-6949-JB", ENDITEM, 
		"Name=flightID", "Value=292222975-7718-JB", ENDITEM, 
		"Name=flightID", "Value=1163-8493-JB", ENDITEM, 
		"Name=flightID", "Value=210297460-9263-JB", ENDITEM, 
		"Name=flightID", "Value=210297452-10017-JB", ENDITEM, 
		"Name=flightID", "Value=210297163-10800-JB", ENDITEM, 
		"Name=removeFlights.x", "Value=18", ENDITEM, 
		"Name=removeFlights.y", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=14", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("4_transaction",LR_AUTO);

	return 0;
}