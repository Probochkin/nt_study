Action()
{
lr_start_transaction("02_search_tickets");

	web_websocket_send("ID=0", 
	"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1734253030946\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	
	
	lr_start_transaction("1_webtour_homepage");
	web_reg_find("Text=Welcome to the Web Tours site",LAST);
	
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

/*Correlation comment - Do not change!  Original value='140482.686431754HcczAHipViDDDDDDtDDfzptzQV' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
		
lr_end_transaction("1_webtour_homepage",LR_AUTO);




lr_start_transaction("2_login");

	
	web_reg_find("Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",LAST);
	
	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_auto_header("Priority", 
		"u=4");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(16);

	web_submit_data("login.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t8.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=51", ENDITEM,
		"Name=login.y", "Value=5", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	
	lr_end_transaction("2_login",LR_AUTO);

	
	
	

	lr_start_transaction("flights_Button");

	web_reg_find("Text=Flight Selections",LAST);
	

	
	web_add_auto_header("Sec-Fetch-User",
		"?1");

	lr_think_time(19);
	
	web_reg_save_param_regexp("ParamName=arrivalCity","RegExp=\\>([A-Z].*?)\\<\\/option\\>\\\n","Ordinal=all",SEARCH_FILTERS,LAST);
	
/*Correlation comment - Do not change!  Original value='roundtrip' Name ='.cgifields' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=.cgifields",
		"TagName=input",
		"Extract=name",
		"Type=checkbox",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/reservations.pl*",
		LAST);

	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);


lr_end_transaction("flights_Button",LR_AUTO);

	
	

lr_start_transaction("find_flight");
	
	


lr_save_string(lr_paramarr_random("arrivalCity"),"randCityArrival");
lr_save_string(lr_paramarr_random("arrivalCity"),"randCityDepart");


while (strcmp(lr_eval_string("{randCityArrival}"),lr_eval_string("{randCityDepart}"))==0) {
	
	lr_output_message("%s и %s равны", lr_eval_string("{randCityArrival}"),lr_eval_string("{randCityDepart}"));
	
	lr_save_string(lr_paramarr_random("arrivalCity"),"randCityArrival");
	lr_save_string(lr_paramarr_random("arrivalCity"),"randCityDepart");

};
web_reg_find("Text=Flight departing from <B>{randCityDepart}</B> to <B>{randCityArrival}</B> on <B>{departDate}</B>",LAST);
	web_add_auto_header("Origin", 
		"http://127.0.0.1:1080");

	lr_think_time(25);
web_reg_save_param_regexp("ParamName=outboundFlight","RegExp=name\=\"outboundFlight\" value\=\"(.*?)\"","Ordinal=all",SEARCH_FILTERS,LAST);

	web_submit_data("reservations.pl",
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t10.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={randCityDepart}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={randCityArrival}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=45", ENDITEM,
		"Name=findFlights.y", "Value=6", ENDITEM,
		"Name=.cgifields", "Value={.cgifields}", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);



lr_end_transaction("find_flight",LR_AUTO);
lr_end_transaction("02_search_tickets",LR_AUTO);
	return 0;
}