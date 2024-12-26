Action()
{
	int i;
	lr_start_transaction("05_deleting_reservation");
	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1734526584639\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/

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

	lr_think_time(4);

/*Correlation comment - Do not change!  Original value='140504.622033212HccHcAzptQfiDDDDtDDzDpcDiQHf' Name ='userSession' Type ='ResponseBased'*/
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
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("webtour_homepage",LR_AUTO);

	lr_start_transaction("login");

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
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=29", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("show_Itinerary");
	
	
	
	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(4);

	

	web_reg_save_param("scheduled",
		"LB=A total of ",
		"RB= scheduled flights.",
		LAST);
	
	 //<input type="hidden" name="flightID" value="14098-820-JM"  />

    web_reg_save_param("c_flightids",
    "lb=<input type=\"hidden\" name=\"flightID\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);

    //<input type="hidden" name=".cgifields" value="6"  />

    web_reg_save_param("c_cgifields",
    "lb=<input type=\"hidden\" name=\".cgifields\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);
	 
	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("show_Itinerary",LR_AUTO);

	lr_start_transaction("delete_etinerary");
lr_save_string("", "c_buffer");

    for (i=1;i<=2;i++)
    {
        lr_param_sprintf("c_buffer", "%s%d=on&", lr_eval_string("{c_buffer}"), i);
    }

    //This code selects what itinerary to cancel.
    //In this case it is the last one that was just created

    lr_param_sprintf("c_buffer",
    "%s=on&",
    lr_eval_string("{c_flightids_count}"));

    //This code builds the values for flight id and cgi fields

    for (i=1;i<=atoi(lr_eval_string("{c_flightids_count}"));i++)
    {
        lr_param_sprintf("c_buffer",
        "%sflightID=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("c_flightids",
        i));

        lr_param_sprintf("c_buffer",
        "%s.cgifields=%s&",
        lr_eval_string("{c_buffer}"),
        lr_paramarr_idx("c_cgifields",
        i));
    }

    //This line adds the suffix to the end of the request
    //and saves it as the c_wcr parameter

    lr_save_string(lr_eval_string("{c_buffer}removeFlights.x=36&removeFlights.y=4"), "c_wcr");


  
	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	lr_think_time(16);

lr_save_string(lr_eval_string(lr_eval_string("{c_flightids_{c_flightids_count}}")),
    "c_cancelflight");

    web_reg_find("Text={c_cancelflight}", "Fail=Found", LAST);

    //Here is the custome built web_custom_request

    web_custom_request("itinerary.pl_2",
    "URL=http://127.0.0.1:1080/cgi-bin/itinerary.pl",
    "Method=POST",
    "Resource=0",
    "RecContentType=text/html",
    "Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl",
    "Snapshot=t23.inf",
    "Mode=HTTP",
    "Body={c_wcr}",
    LAST);

	lr_end_transaction("delete_etinerary",LR_AUTO);
lr_end_transaction("05_deleting_reservation",LR_AUTO);
	return 0;
}