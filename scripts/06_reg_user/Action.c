Action()
{

	char ConvertedName[100];
	char FPass[100];
	char FNameOrig[100];
	int n_length, i, k;

	strcpy( FNameOrig,
		lr_eval_string("{random_number}") );
	strcat( FPass,
		lr_eval_string("{random_number}") );
	n_length = strlen( FNameOrig );
	k = 0;
	for (i=0;i<n_length;i++)
	{
        if(FNameOrig[i] == '1')
		{
			ConvertedName[k] = 'a';
			k++;
		}
		else if(FNameOrig[i] == '2')
		{
			ConvertedName[k] = 'b';
			k++;
		}
		else if(FNameOrig[i] == '3')
		{
			ConvertedName[k] = 'c';
			k++;
		}
		else if(FNameOrig[i] == '4')
		{
			ConvertedName[k] = 'd';
			k++;
		}
		else if(FNameOrig[i] == '5')
		{
			ConvertedName[k] = 'e';
			k++;
		}
		else if(FNameOrig[i] == '6')
		{
			ConvertedName[k] = 'f';
			k++;
		}
		else if(FNameOrig[i] == '7')
		{
			ConvertedName[k] = 'g';
			k++;
		}
		else if(FNameOrig[i] == '8')
		{
			ConvertedName[k] = 'h';
			k++;
		}
		else if(FNameOrig[i] == '9')
		{
			ConvertedName[k] = 'i';
			k++;
		}
		else if(FNameOrig[i] == '0')
		{
			ConvertedName[k] = 'j';
			k++;
		}
        else if( FNameOrig[i] != '-' && FNameOrig[i] != ' ' && FNameOrig[i] != ':' )
		{
			ConvertedName[k] = FNameOrig[i];
			k++;
		}
        
	}
	ConvertedName[k] = '\0';
	lr_save_string( ConvertedName,
		"login" );
	lr_output_message("User Name is %s", lr_eval_string("{FName}"));
	lr_save_string( FPass,
		"password" );
	
	
	
	
lr_start_transaction("06_reg_user");
	web_websocket_send("ID=0", 
		"Buffer={\"messageType\":\"hello\",\"broadcasts\":{\"remote-settings/monitor_changes\":\"\\\"1733503317219\\\"\"},\"use_webpush\":true}", 
		"IsBinary=0", 
		LAST);

	/*Connection ID 0 received buffer WebSocketReceive0*/
	lr_start_transaction("homepage");

	web_reg_find("Text=To make reservations,please enter your account information to the left",LAST);
	
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

	lr_think_time(16);


	web_url("WebTours", 
		"URL=http://127.0.0.1:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("homepage",LR_AUTO);

	
	
	
	
	lr_start_transaction("singup");
web_reg_find("Text=Please choose a username and password combination for your account",LAST);
	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Priority", 
		"u=4");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(25);

	web_url("sign up now", 
		"URL=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("singup",LR_AUTO);

	
	
	
	
	lr_start_transaction("registr");
	
	web_reg_find("Text=Thank you, <b>{login}</b>, for registering and welcome to the Web Tours family",LAST);
	web_add_header("Origin", 
		"http://127.0.0.1:1080");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(46);

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=passwordConfirm", "Value={password}", ENDITEM, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={street}", ENDITEM, 
		"Name=address2", "Value={city}", ENDITEM, 
		"Name=register.x", "Value=32", ENDITEM, 
		"Name=register.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("registr",LR_AUTO);
lr_end_transaction("06_reg_user",LR_AUTO);
	return 0;
}