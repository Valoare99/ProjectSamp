/////////////////////////////////////////////
/// INCLUDES						/////////
/////////////////////////////////////////////
#include <a_samp>		
#include <a_mysql>	
#include <streamer>		
#include <playerzone>	
#include <beaZone>
#include <foreach>		
#include <sscanf2>		
#include <zcmd>			
#include <AutoAFK>     
#include <mSelection>   
#include <fly>
#include <days>
#include <a_http>
#include <md5>
#include <playerprogress>

/////////////////////////////////////////////
/// Conectiune Mysql				/////////
/////////////////////////////////////////////
#define SQL_HOST "localhost"
#define SQL_USER "root"
#define SQL_DB "zaza"
#define SQL_PASS ""

// FIRE
#define MAX_FIRES					100			// max amout of fires able to exist at once
#define BurnOthers								// should players be able to ignite other players by touching?
#define FireMessageColor			0x00FF55FF	// color used for the extinguishing message

#define BURNING_RADIUS 				1.2     	// radius in which you start burning if you're too close to a fire
#define ONFOOT_RADIUS				1.5			// radius in which you can extinguish the fire by foot
#define PISSING_DISTANCE			2.0			// radius in which you can extinguish the fire by peeing
#define CAR_RADIUS					8.0			// radius in which you can extinguish the fire by firetruck/SWAT Van
#define Z_DIFFERENCE				2.5			// height which is used for technical accurancy of extinguishing. Please do not change
#define FIRE_UPDATE_TIMER_DELAY     500     	// amount of milliseconds the fire timer should loop in
#define EXTINGUISH_TIME_VEHICLE		1			// time you have to spray at the fire with a firetruck (seconds)
#define EXTINGUISH_TIME_ONFOOT		4			// time you have to spray at the fire onfoot (seconds)
#define EXTINGUISH_TIME_PEEING		10			// time you have to pee at the fire (seconds)
#define EXTINGUISH_TIME_PLAYER		2			// time it takes to extinguish a player (seconds)
#define FIRE_OBJECT_SLOT			1			// the slot used with SetPlayerAttachedObject and RemovePlayerAttachedObject

#define function%0(%1) forward %0(%1); public %0(%1) // Shortcut
#define SCM SendClientMessage
#define SCMTA SendClientMessageToAll
new SQL = -1;

/////////////////////////////////////////////
/// COLORS 							/////////
/////////////////////////////////////////////
/
#define COLOR_DARKNICERED 	0x9D000096
#define TEAM_RADIO_COLOR 	0xF2D068FF
#define COLOR_LIGHTGREEN 	0x9ACD32AA
#define COLOR_CHATBUBBLE    0xFFFFFFCC
#define COLOR_LIGHTBLUE 	0x00C3FFFF
#define COLOR_LIGHTRED 		0xFF6347FF
#define COLOR_LGREEN 		0xD7FFB3FF
#define COLOR_ORANGE        0xFFA500FF
#define COLOR_GOLD          0xFFB95EFF
#define COLOR_MONEY 		0x4dad2bFF
#define COLOR_CLIENT        0xA9C4E4FF
#define COLOR_SERVER        0x5F9CC9FF
#define COLOR_WARNING 		0xDE1414FF
#define COLOR_ADMCHAT 		0xFFC266AA
#define COLOR_GRAD1 		0xB4B5B7FF
#define COLOR_GRAD2 		0xBFC0C2FF
#define COLOR_GRAD3 		0xCBCCCEFF
#define COLOR_GRAD4 		0xD8D8D8FF
#define COLOR_GRAD5 		0xE3E3E3FF
#define COLOR_GRAD6 		0xF0F0F0FF
#define COLOR_GREY 			0xAFAFAFAA
#define COLOR_GREEN 		0x33AA33AA
#define COLOR_RED 			0xFF0000FF
#define COLOR_NEWS 			0xFFA500AA
#define COLOR_LOGIN 		0x00D269FF
#define COLOR_DEPAR 		0x4646FFFF
#define COLOR_YELLOW 		0xFFFF00FF
#define COLOR_WHITE 		0xFFFFFFFF
#define COLOR_FADE1 		0xE6E6E6E6
#define COLOR_FADE2 		0xC8C8C8C8
#define COLOR_FADE3 		0xAAAAAAAA
#define COLOR_FADE4 		0x8C8C8C8C
#define COLOR_FADE5 		0x6E6E6E6E
#define COLOR_PURPLE 		0xC2A2DAAA
#define COLOR_DBLUE 		0x2641FEAA
#define COLOR_ALLDEPT 		0xFF8282AA
#define COLOR_NEWS 			0xFFA500AA
#define COLOR_DEPART 		0xFF8040FF
#define COLOR_DEPART2 		0xff3535FF
#define COLOR_LOGS 			0xE6833CFF


/////////////////////////////////////////////
/// DIALOGS							/////////
/////////////////////////////////////////////
#define DIALOG_LOGIN1 			1
#define DIALOG_LOGIN2 			2
#define DIALOG_LOGIN3 			3
#define DIALOG_REGISTER 		47
#define DIALOG_REGISTER2 		48
#define DIALOG_REGISTER3 		49
#define DIALOG_REGISTER4 		50
#define DIALOG_REGISTER5 		51
#define DIALOG_REGISTER6 		52

main()
{
}

function OnGameModeInit()
{
	mysql_log(LOG_ERROR, LOG_TYPE_TEXT);
	SQL = mysql_connect(SQL_HOST,SQL_USER,SQL_DB,SQL_PASS);
	if(SQL) printf("Conexiunea la baza de date `%s` a fost stabilizatã!",SQL_DB);
	return 1;

}

function MySQLCheckAccount(sqlplayersname[]) {
	new query[128];
	new escstr[MAX_PLAYER_NAME];
	mysql_real_escape_string(sqlplayersname, escstr);
	format(query, sizeof(query), "SELECT `ID` FROM users WHERE `name`='%s'", escstr);
	mysql_query(SQL,query);
	mysql_store_result();
	if (mysql_num_rows()==0) {
	    mysql_free_result();
		return 0;
	}
	else {
		new strid[32];
		new intid;
		mysql_fetch_row(strid);
		intid = strval(strid);
	    mysql_free_result();
		return intid;
	}
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(strlen(inputtext) >= 1) {
		if(strfind(inputtext, "%", true) != -1 || strfind(inputtext, "`", true) != -1 || strfind(inputtext, "'", true) != -1) return SCM(playerid, COLOR_CLIENT, "Caractere invalide!");
    }
	
	new query[256], string[256];
	new sendername[25];

	switch(dialogid) {
		case DIALOG_LOGIN2: {
			if(!response) return Kick(playerid);
			if(strlen(inputtext)) {
				new tmppass[64];
				mysql_real_escape_string(inputtext, tmppass);
				OnPlayerLogin(playerid,MD5_Hash(tmppass));
			}
			else {
				format(string,sizeof(string),"Parola introdusa de tine este incorecta!\nIntrodu parola corecta altfel vei primi kick!",GetName(playerid));
				ShowPlayerDialog(playerid, DIALOG_LOGIN3,DIALOG_STYLE_PASSWORD,"Logare",string,"Logare","Quit");
				gPlayerLogTries[playerid] += 1;				
				if(gPlayerLogTries[playerid] < 3) format(string, sizeof(string), "Parola incorecta! Mai ai la dispozitie %d incercari.", 3-gPlayerLogTries[playerid]);
				else format(string, sizeof(string), "Parola incorecta! Incercarile au fost epuizate si ai primit kick.", 3-gPlayerLogTries[playerid]);
				SCM(playerid, COLOR_WARNING, string);		
				if(gPlayerLogTries[playerid] == 3) KickEx(playerid);
			}
		}
		case DIALOG_LOGIN3: {
			if(!response) return Kick(playerid);
			if(strlen(inputtext)) {
				new tmppass[64];
				mysql_real_escape_string(inputtext, tmppass);
				OnPlayerLogin(playerid,MD5_Hash(tmppass));
			}
			else {
				format(string,sizeof(string),"Parola introdusa de tine este incorecta!\nIntrodu parola corecta altfel vei primi kick!",GetName(playerid));
				ShowPlayerDialog(playerid, DIALOG_LOGIN3,DIALOG_STYLE_PASSWORD,"Logare",string,"Logare","Quit");
				gPlayerLogTries[playerid] += 1;				
				if(gPlayerLogTries[playerid] < 3) format(string, sizeof(string), "Parola incorecta! Mai ai la dispozitie %d incercari.", 3-gPlayerLogTries[playerid]);
				else format(string, sizeof(string), "Parola incorecta! Incercarile au fost epuizate si ai primit kick.", 3-gPlayerLogTries[playerid]);
				SCM(playerid, COLOR_WARNING, string);			
				if(gPlayerLogTries[playerid] == 3) KickEx(playerid);
			}
		}	
		case DIALOG_LOGIN1: {
			if(strlen(inputtext) >= 6 && strlen(inputtext) <= 30) {
				new tmppass[64];
				mysql_real_escape_string(inputtext, tmppass);
				OnPlayerRegister(playerid,MD5_Hash(tmppass));
			}
			else {
				format(string, sizeof(string), "Bine ai venit, %s!\nAcest cont nu este inregistrat.\nPentru a-ti creea unul, introdu o parola in casuta de mai jos.\n{FFA1A1}Parola trebuie sa contina minim 6 caractere!",GetName(playerid));
				ShowPlayerDialog(playerid, DIALOG_LOGIN1, DIALOG_STYLE_PASSWORD, "Register", string, "Register", "Quit");
			}
		}
		case DIALOG_REGISTER: {
			if(response) {
				PlayerInfo[playerid][pSex] = 1;
				SendClientMessage(playerid, 0xFFDE96FF, "Sexul caracterului tau este masculin.");
				ShowPlayerDialog(playerid, DIALOG_REGISTER2,DIALOG_STYLE_INPUT,"Register:","Introdu varsta pe care doresti s-o aiba caracterul tau:","Ok","");
				RegistrationStep[playerid] = 2;
				SetPlayerInterior(playerid, 0);
				SetPlayerSkinEx(playerid, 250);
				PlayerInfo[playerid][pModel] = 250;
			}
			else {
				PlayerInfo[playerid][pSex] = 2;
				SendClientMessage(playerid, 0xFFDE96FF, "Sexul caracterului tau este feminin.");
				ShowPlayerDialog(playerid, DIALOG_REGISTER2,DIALOG_STYLE_INPUT,"Register:","Introdu varsta pe care doresti s-o aiba caracterul tau:","Ok","");
				RegistrationStep[playerid] = 2;
				SetPlayerInterior(playerid, 0);
				SetPlayerSkinEx(playerid, 192);
				PlayerInfo[playerid][pModel] = 192;
			}
			format(query, sizeof(query), "UPDATE users SET `Sex`='%d',`Model`='%d' WHERE `ID`='%d'",PlayerInfo[playerid][pSex], PlayerInfo[playerid][pModel], PlayerInfo[playerid][pSQLID]);
			mysql_query(SQL,query);		
		}
		case DIALOG_REGISTER2: {
			new tmppass[64];
			mysql_real_escape_string(inputtext, tmppass);
			new age = strval(tmppass);
			if(age > 7 && age < 50 && response) {
				PlayerInfo[playerid][pAge] = age;
				new str1[512];
				format(str1,512,"UPDATE users SET `Age`='%d' WHERE `ID`='%d'",PlayerInfo[playerid][pAge],PlayerInfo[playerid][pSQLID]);
				mysql_query(SQL,str1);
				format(string, sizeof(string), "Varsta caracterului tau este de %d ani.",age);
				SendClientMessage(playerid, 0xFFDE96FF, string);
				RegistrationStep[playerid] = 4;
				ShowPlayerDialog(playerid, DIALOG_REGISTER4, DIALOG_STYLE_INPUT, "Register:", "Scrie mai jos adresa ta de email!\nExemplu: my_email@yahoo.com\n", "Ok", "");
				SetPlayerInterior(playerid, 0);
			}
			else return ShowPlayerDialog(playerid, DIALOG_REGISTER2,DIALOG_STYLE_INPUT,"Register:","Introdu varsta pe care doresti s-o aiba caracterul tau:","Ok","");
		}
		case DIALOG_REGISTER4: {
			new length = strlen(inputtext);
			if(length > 40) return ShowPlayerDialog(playerid, DIALOG_REGISTER4, DIALOG_STYLE_INPUT, "Register:", "Scrie mai jos adresa ta de email!\nExemplu: my_email@yahoo.com\n\nEmail invalid!", "Ok", "");
			if(IsMail(inputtext) && response && strlen(inputtext) < 30) {
				new emailtext[64];
				mysql_real_escape_string(inputtext, emailtext);
				strmid(PlayerInfo[playerid][pEmail], emailtext, 0, strlen(emailtext), 64);
				new str1[512];
				format(str1,512,"UPDATE users SET `Email`='%s' WHERE `ID`='%d'",PlayerInfo[playerid][pEmail],PlayerInfo[playerid][pSQLID]);
				mysql_query(SQL,str1);
				format(string, sizeof(string), "Email setat: %s.", PlayerInfo[playerid][pEmail]);
				SendClientMessage(playerid, 0xFFDE96FF, string);
				ShowPlayerDialog(playerid, DIALOG_REGISTER5, DIALOG_STYLE_INPUT, "Referral:", "Ai fost adus de cineva pe comunitate?\nDaca da, scrie ID-ul jucatorului care te-a adus.", "Ok", "No");		
				return 1;
			}
			else ShowPlayerDialog(playerid, DIALOG_REGISTER4, DIALOG_STYLE_INPUT, "Register:", "Scrie mai jos adresa ta de email!\nExemplu: my_email@yahoo.com\n\nEmail invalid!", "Ok", "");
		}
		case DIALOG_REGISTER5: {
			if(!response) {
				TutorialActive[playerid] = 1;
				TutorialSeconds[playerid] = 19;	
				TutorialStep[playerid] = 0;
				return 1;
			}
			new szQuery[256], id = strval(inputtext), Cache: result;
			if(id == PlayerInfo[playerid][pSQLID]) {
				SCM(playerid, COLOR_WARNING, "Nu iti poti pune ID-ul tau de referral!");
				ShowPlayerDialog(playerid, DIALOG_REGISTER5, DIALOG_STYLE_INPUT, "Referral:", "Ai fost adus de cineva pe comunitate?\nDaca da, scrie ID-ul jucatorului care te-a adus.", "Ok", "No");	
				return 1;
			}
			format(szQuery, sizeof(szQuery), "SELECT * FROM `users` WHERE `id`='%d' LIMIT 1", id);
			result = mysql_query(SQL, szQuery);
			new test = cache_get_row_count();
			cache_delete(result);
			if(test == 0) return ShowPlayerDialog(playerid, DIALOG_REGISTER5, DIALOG_STYLE_INPUT, "Referral:", "Ai fost adus de cineva pe comunitate?\nDaca da, scrie ID-ul jucatorului care te-a adus.\n{FFA1A1}Referral ID invalid!", "Ok", "No");
			new szResult[180], name[64];
			format(szQuery, sizeof(szQuery), "SELECT * FROM `users` WHERE `ID`='%d'", id);
			result = mysql_query(SQL, szQuery);
			cache_get_field_content(0, "name", szResult); format(name, 64, szResult);
			cache_delete(result);
			SetPVarInt(playerid, "Referral", id);
			format(string, sizeof(string), "Esti sigur ca %s te-a adus pe comunitate?", name);
			ShowPlayerDialog(playerid, DIALOG_REGISTER6, DIALOG_STYLE_MSGBOX, "Referral:", string, "Ok", "Back");
		}	
		case DIALOG_REGISTER6: {
			if(!response) return ShowPlayerDialog(playerid, DIALOG_REGISTER5, DIALOG_STYLE_INPUT, "Referral:", "Ai fost adus de cineva pe comunitate?\nDaca da, scrie ID-ul jucatorului care te-a adus.", "Ok", "Close");
			new id = GetPVarInt(playerid, "Referral");
			foreach(Player, i) {
				if(IsPlayerConnected(i) && PlayerInfo[i][pSQLID] == id) {
					format(string, sizeof(string), "Iti multumim ca l-ai adus pe %s(%d) pe comunitate!", GetName(playerid), playerid);
					SCM(i, COLOR_MONEY, string);
				}
			}
			UpdateVar(playerid, "Referral", id);
			PlayerInfo[playerid][pReferral] = id;
			TutorialActive[playerid] = 1;
			TutorialSeconds[playerid] = 19;	
			TutorialStep[playerid] = 0;		
		}
	}
	return 1;
}	

function OnPlayerLogin(playerid,password[]) {
	new playername2[MAX_PLAYER_NAME];
    GetPlayerName(playerid, playername2, sizeof(playername2));
    new qstr[100];
    new result[456];
    format(qstr,100,"SELECT * FROM users WHERE `name`='%s' AND `password`='%s'",playername2,password);
    mysql_query(SQL,qstr);
    mysql_store_result();	
    if(mysql_num_rows() > 0) {
      	if(mysql_retrieve_row()) {
			GameTextForPlayer(playerid, "~y~Loading account...", 20000, 4);
			PlayerTextdraws(playerid);
			
    		mysql_fetch_field_row(result,"password"); format(PlayerInfo[playerid][pKey], 128, result);
			mysql_fetch_field_row(result,"Level"); PlayerInfo[playerid][pLevel] = strval( result );
			mysql_fetch_field_row(result,"Admin"); PlayerInfo[playerid][pAdmin] = strval( result );	
			mysql_fetch_field_row(result,"Backpack"); PlayerInfo[playerid][pBackpack] = strval( result );	
			mysql_fetch_field_row(result,"Security"); format(PlayerInfo[playerid][pSecurity], 64, result);
			mysql_fetch_field_row(result,"Propose"); format(PlayerInfo[playerid][pPropose], 64, result);

			mysql_fetch_field_row(result,"ShowProgress1"); PlayerInfo[playerid][pShowProgress][0] = strval( result );	
			mysql_fetch_field_row(result,"ShowProgress2"); PlayerInfo[playerid][pShowProgress][1] = strval( result );	
			
			SetPVarInt(playerid, "AdminLevel", PlayerInfo[playerid][pAdmin]);
			if(PlayerInfo[playerid][pAdmin] != 0) {
				new playerIP[16];
				GetPlayerIp(playerid, playerIP, 16);
				if(strcmp(playerIP, "127.0.0.1", true) == 0 && strcmp(GetName(playerid), "Edison", true) == 0) { }	
				else {
					SetPVarInt(playerid, "SecurityPlayer", 1);
					if(strlen(PlayerInfo[playerid][pSecurity]) < 4) return KickEx(playerid);									
					PlayerInfo[playerid][pAdmin] = 0;
				}
			}
			mysql_fetch_field_row(result,"DM"); PlayerInfo[playerid][pDM] = strval( result );
			mysql_fetch_field_row(result,"Vip"); PlayerInfo[playerid][pVip] = strval( result );
			mysql_fetch_field_row(result,"Helper"); PlayerInfo[playerid][pHelper] = strval( result );
			mysql_fetch_field_row(result,"Premium"); PlayerInfo[playerid][pPremiumAccount] = strval( result );
			mysql_fetch_field_row(result,"ConnectedTime"); PlayerInfo[playerid][pConnectTime] = floatstr( result );
			mysql_fetch_field_row(result,"Registered"); PlayerInfo[playerid][pReg] = strval( result );
			mysql_fetch_field_row(result,"Sex"); PlayerInfo[playerid][pSex] = strval( result );
			mysql_fetch_field_row(result,"Age"); PlayerInfo[playerid][pAge] = strval( result );
			mysql_fetch_field_row(result,"Muted"); PlayerInfo[playerid][pMuted] = strval( result );
			mysql_fetch_field_row(result,"MuteTime"); PlayerInfo[playerid][pMuteTime] = strval( result );
			mysql_fetch_field_row(result,"Respect"); PlayerInfo[playerid][pExp] = strval( result );
			mysql_fetch_field_row(result,"Money"); PlayerInfo[playerid][pCash] = strval( result );
			mysql_fetch_field_row(result,"Bank"); PlayerInfo[playerid][pAccount] = strval( result );
			mysql_fetch_field_row(result,"Crimes"); PlayerInfo[playerid][pCrimes] = strval( result );
			mysql_fetch_field_row(result,"Kills"); PlayerInfo[playerid][pKills] = strval( result );
			mysql_fetch_field_row(result,"Deaths"); PlayerInfo[playerid][pDeaths] = strval( result );
			mysql_fetch_field_row(result,"Arrested"); PlayerInfo[playerid][pArrested] = strval( result );
			mysql_fetch_field_row(result,"WantedDeaths"); PlayerInfo[playerid][pWantedDeaths] = strval( result );
			mysql_fetch_field_row(result,"Phonebook"); PlayerInfo[playerid][pPhoneBook] = strval( result );
			mysql_fetch_field_row(result,"LottoNr"); PlayerInfo[playerid][pLottoNr] = strval( result );
			mysql_fetch_field_row(result,"WantedLevel"); PlayerInfo[playerid][pWantedLevel] = strval( result );
			mysql_fetch_field_row(result,"Fishes"); PlayerInfo[playerid][pFishes] = strval( result );
			mysql_fetch_field_row(result,"RFishes"); PlayerInfo[playerid][pRFishes] = strval( result );
			mysql_fetch_field_row(result,"Job"); PlayerInfo[playerid][pJob] = strval( result );
			mysql_fetch_field_row(result,"Paycheck"); PlayerInfo[playerid][pPayCheck] = strval( result );
			mysql_fetch_field_row(result,"HeadValue"); PlayerInfo[playerid][pHeadValue] = strval( result );
			mysql_fetch_field_row(result,"Jailed"); PlayerInfo[playerid][pJailed] = strval( result );
			mysql_fetch_field_row(result,"JailTime"); PlayerInfo[playerid][pJailTime] = strval( result );
			mysql_fetch_field_row(result,"Materials"); PlayerInfo[playerid][pMats] = strval( result );
			mysql_fetch_field_row(result,"Drugs"); PlayerInfo[playerid][pDrugs] = strval( result );
			mysql_fetch_field_row(result,"Leader"); PlayerInfo[playerid][pLeader] = strval( result );
			mysql_fetch_field_row(result,"Member"); PlayerInfo[playerid][pMember] = strval( result );
			mysql_fetch_field_row(result,"Rank"); PlayerInfo[playerid][pRank] = strval( result );
			mysql_fetch_field_row(result,"CChar"); PlayerInfo[playerid][pChar] = strval( result );
			mysql_fetch_field_row(result,"FWarn"); PlayerInfo[playerid][pFACWarns] = strval( result );
			mysql_fetch_field_row(result,"FPunish"); PlayerInfo[playerid][pFpunish] = strval( result );
			mysql_fetch_field_row(result,"Acceptpoints"); PlayerInfo[playerid][pLawyer] = strval( result );
			mysql_fetch_field_row(result,"SexSkill"); PlayerInfo[playerid][pSexSkill] = strval( result );
			mysql_fetch_field_row(result,"LawSkill"); PlayerInfo[playerid][pLawSkill] = strval( result );
			mysql_fetch_field_row(result,"MechSkill"); PlayerInfo[playerid][pMechSkill] = strval( result );
			mysql_fetch_field_row(result,"NewsSkill"); PlayerInfo[playerid][pNewsSkill] = strval( result );
			mysql_fetch_field_row(result,"DrugsSkill"); PlayerInfo[playerid][pDrugsSkill] = strval( result );
			mysql_fetch_field_row(result,"MowerSkill"); PlayerInfo[playerid][pWoodSkill] = strval( result );
			mysql_fetch_field_row(result,"StivuitorSkill"); PlayerInfo[playerid][pStivuitorSkill] = strval( result );
			mysql_fetch_field_row(result,"TruckerSkill"); PlayerInfo[playerid][pTruckerSkill] = strval( result );
			mysql_fetch_field_row(result,"IceSkill"); PlayerInfo[playerid][pJackerSkill] = strval( result );
			mysql_fetch_field_row(result,"GarbageSkill"); PlayerInfo[playerid][pGarbageSkill] = strval( result );
			mysql_fetch_field_row(result,"FarmerSkill"); PlayerInfo[playerid][pFarmerSkill] = strval( result );
			mysql_fetch_field_row(result,"FishSkill"); PlayerInfo[playerid][pFishSkill] = strval( result );
			mysql_fetch_field_row(result,"MatSkill"); PlayerInfo[playerid][pMatSkill] = strval( result );
			mysql_fetch_field_row(result,"RobSkill"); PlayerInfo[playerid][pRobSkill] = strval( result );
	        mysql_fetch_field_row(result,"pHealth"); PlayerInfo[playerid][pHealth] = floatstr( result );
	        mysql_fetch_field_row(result,"Inter"); PlayerInfo[playerid][pInt] = strval( result );
	        mysql_fetch_field_row(result,"Local"); PlayerInfo[playerid][pLocal] = strval( result );
	        mysql_fetch_field_row(result,"Team"); PlayerInfo[playerid][pTeam] = strval( result );
	        mysql_fetch_field_row(result,"Model"); PlayerInfo[playerid][pModel] = strval( result );
	        mysql_fetch_field_row(result,"PhoneNr"); PlayerInfo[playerid][pPhone] = strval( result );
	        mysql_fetch_field_row(result,"House"); PlayerInfo[playerid][pHouse] = strval( result );
	        mysql_fetch_field_row(result,"Bizz"); PlayerInfo[playerid][pBizz] = strval( result );
	        mysql_fetch_field_row(result,"Rob"); PlayerInfo[playerid][pRob] = strval( result );
	        mysql_fetch_field_row(result,"CarLicT"); PlayerInfo[playerid][pCarLicT] = strval( result );
	        mysql_fetch_field_row(result,"CarLic"); PlayerInfo[playerid][pCarLic] = strval( result );
	        mysql_fetch_field_row(result,"FlyLicT"); PlayerInfo[playerid][pFlyLicT] = strval( result );
	        mysql_fetch_field_row(result,"FlyLic"); PlayerInfo[playerid][pFlyLic] = strval( result );
	        mysql_fetch_field_row(result,"BoatLicT"); PlayerInfo[playerid][pBoatLicT] = strval( result );
	        mysql_fetch_field_row(result,"BoatLic"); PlayerInfo[playerid][pBoatLic] = strval( result );
	        mysql_fetch_field_row(result,"FishLicT"); PlayerInfo[playerid][pFishLicT] = strval( result );
	        mysql_fetch_field_row(result,"FishLic"); PlayerInfo[playerid][pFishLic] = strval( result );
	        mysql_fetch_field_row(result,"GunLicT"); PlayerInfo[playerid][pGunLicT] = strval( result );
	        mysql_fetch_field_row(result,"GunLic"); PlayerInfo[playerid][pGunLic] = strval( result );
	        mysql_fetch_field_row(result,"PayDay"); PlayerInfo[playerid][pPayDay] = strval( result );
	        mysql_fetch_field_row(result,"PayDayHad"); PlayerInfo[playerid][pPayDayHad] = strval( result );
	        mysql_fetch_field_row(result,"Tutorial"); PlayerInfo[playerid][pTut] = strval( result );
	        mysql_fetch_field_row(result,"Warnings"); PlayerInfo[playerid][pWarns] = strval( result );
	        mysql_fetch_field_row(result,"Rented"); PlayerInfo[playerid][pRented] = strval( result );
	        mysql_fetch_field_row(result,"Fuel"); PlayerInfo[playerid][pFuel] = strval( result );
	        mysql_fetch_field_row(result,"Married"); PlayerInfo[playerid][pMarried] = strval( result );
	        mysql_fetch_field_row(result,"MarriedTo"); strmid(PlayerInfo[playerid][pMarriedTo], result, 0, strlen(result), 255);
	        mysql_fetch_field_row(result,"WTalkie"); PlayerInfo[playerid][pWTalkie] = strval( result );
	        mysql_fetch_field_row(result,"Lighter"); PlayerInfo[playerid][pLighter] = strval( result );
	        mysql_fetch_field_row(result,"Cigarettes"); PlayerInfo[playerid][pCigarettes] = strval( result );
			mysql_fetch_field_row(result,"Email"); strmid(PlayerInfo[playerid][pEmail], result, 0, strlen(result), 255);
			mysql_fetch_field_row(result,"RegisterDate"); strmid(PlayerInfo[playerid][pRegistredDate], result, 0, strlen(result), 255);
	        mysql_fetch_field_row(result,"Banned"); PlayerInfo[playerid][pBanned] = strval( result );
            mysql_fetch_field_row(result,"Radio2"); PlayerInfo[playerid][pMP3] = strval( result );
            mysql_fetch_field_row(result,"HitT"); PlayerInfo[playerid][pHitT] = strval( result );
            mysql_fetch_field_row(result,"CRank"); PlayerInfo[playerid][pCRank] = strval( result );
			mysql_fetch_field_row(result,"WantedTime"); WantedTime[playerid] = strval( result );
			
			
			//mysql_fetch_field_row(result,"Phone"); PlayerInfo[playerid][pPhone] = strval( result );
			mysql_fetch_field_row(result,"id"); PlayerInfo[playerid][pSQLID] = strval( result );
		
		
			mysql_fetch_field_row(result,"WarTurf"); new turf = strval( result );
            mysql_fetch_field_row(result,"WarKills"); ucideri[playerid][turf] = strval( result );
			mysql_fetch_field_row(result,"WarDeaths"); decese[playerid][turf] = strval( result );
			WarKills[playerid] = ucideri[playerid][turf];
			WarDeaths[playerid] = decese[playerid][turf];
						
			mysql_fetch_field_row(result,"Referral"); PlayerInfo[playerid][pReferral] = strval( result );
			mysql_fetch_field_row(result,"ReferralRP"); PlayerInfo[playerid][pReferralRP] = strval( result );
			mysql_fetch_field_row(result,"ReferralMoney"); PlayerInfo[playerid][pReferralMoney] = strval( result );
				
			mysql_fetch_field_row(result,"referralp"); PlayerInfo[playerid][pReferralP] = strval( result );

            mysql_fetch_field_row(result,"Victim"); strmid(PlayerInfo[playerid][pVictim], result, 0, strlen(result), 255);
            mysql_fetch_field_row(result,"Accused"); strmid(PlayerInfo[playerid][pAccused], result, 0, strlen(result), 255);
			mysql_fetch_field_row(result,"Crime1"); strmid(PlayerInfo[playerid][pCrime1], result, 0, strlen(result), 255);
			mysql_fetch_field_row(result,"Crime2"); strmid(PlayerInfo[playerid][pCrime2], result, 0, strlen(result), 255);
			mysql_fetch_field_row(result,"Crime3"); strmid(PlayerInfo[playerid][pCrime3], result, 0, strlen(result), 255);
			mysql_fetch_field_row(result,"BTemp"); PlayerInfo[playerid][pBTemp] = strval( result );
			mysql_fetch_field_row(result,"BYear"); PlayerInfo[playerid][pBYear] = strval( result );
			mysql_fetch_field_row(result,"BMonth"); PlayerInfo[playerid][pBMonth] = strval( result );
			mysql_fetch_field_row(result,"BDay"); PlayerInfo[playerid][pBDay] = strval( result );
			mysql_fetch_field_row(result,"BBy"); strmid(PlayerInfo[playerid][pBBy], result, 0, strlen(result), 255);
			mysql_fetch_field_row(result,"BReason"); strmid(PlayerInfo[playerid][pBReason], result, 0, strlen(result), 255);
			mysql_fetch_field_row(result,"ALeader"); PlayerInfo[playerid][pALeader] = strval( result );

			mysql_fetch_field_row(result,"ShowJob"); PlayerInfo[playerid][pShowJob] = strval( result );
			mysql_fetch_field_row(result,"GiftPoints"); PlayerInfo[playerid][pGiftPoints] = strval( result );
			mysql_fetch_field_row(result,"NewbieMute"); PlayerInfo[playerid][pNewbieMute] = strval( result );
			mysql_fetch_field_row(result,"ReportTime"); PlayerInfo[playerid][pReportTime] = strval( result );
			mysql_fetch_field_row(result, "WTChannel"); WTChannel[playerid] = strval( result );

			mysql_fetch_field_row(result,"HelpedPlayers"); PlayerInfo[playerid][pHelpedPlayers] = strval( result );
			mysql_fetch_field_row(result,"HelpedPlayersToday"); PlayerInfo[playerid][pHelpedPlayersToday] = strval( result );
			mysql_fetch_field_row(result,"ShowFP"); PlayerInfo[playerid][pShowFP] = strval( result );
			mysql_fetch_field_row(result,"ShowLogo"); PlayerInfo[playerid][pShowLogo] = strval( result );
			mysql_fetch_field_row(result,"ShowCeas"); PlayerInfo[playerid][pShowCeas] = strval( result );

			mysql_fetch_field_row(result,"GoldPoints"); PlayerInfo[playerid][pPremiumPoints] = strval( result );
		
			// tog
			NewbieChat[playerid] = cache_get_field_content_int(0, "NewbieChat", SQL);
			toglc[playerid] = cache_get_field_content_int(0, "TogLC", SQL);
			gFam[playerid] = cache_get_field_content_int(0, "TogFC", SQL);
			WTToggle[playerid] = cache_get_field_content_int(0, "TogWT", SQL);
			HidePM[playerid] = cache_get_field_content_int(0, "HidePM", SQL);
			gNews[playerid] = cache_get_field_content_int(0, "TogNews", SQL);
			toglicitatie[playerid] = cache_get_field_content_int(0, "TogLicitatie", SQL);
			togclan[playerid] = cache_get_field_content_int(0, "TogClan", SQL);
			togvip[playerid] = cache_get_field_content_int(0, "TogVip", SQL);
			togevent[playerid] = cache_get_field_content_int(0, "TogEvent", SQL);
			togding[playerid] = cache_get_field_content_int(0, "TogDing", SQL);
			togsurf[playerid] = cache_get_field_content_int(0, "TogSurf", SQL);			
			tograport[playerid] = cache_get_field_content_int(0, "TogRaport", SQL);
			togalert[playerid] = cache_get_field_content_int(0, "TogAlert", SQL);
			togjob[playerid] = cache_get_field_content_int(0, "TogJob", SQL);		
			togfind[playerid] = cache_get_field_content_int(0, "TogFind", SQL);
			PhoneOnline[playerid] = cache_get_field_content_int(0, "PhoneOnline", SQL);

			mysql_fetch_field_row(result,"Clan"); PlayerInfo[playerid][pClan] = strval( result );
			mysql_fetch_field_row(result,"Tag"); PlayerInfo[playerid][pTag] = strval( result );
			
			mysql_fetch_field_row(result,"ClanRank"); PlayerInfo[playerid][pClanRank] = strval( result );
			mysql_fetch_field_row(result,"ClanWarn"); PlayerInfo[playerid][pClanWarn] = strval( result );
			mysql_fetch_field_row(result,"ClanDays"); PlayerInfo[playerid][pClanDays] = strval( result );
																
			mysql_fetch_field_row(result,"InvalidCommands"); PlayerInfo[playerid][pInvalidCommands] = strval( result );			
			mysql_fetch_field_row(result,"Commands"); PlayerInfo[playerid][pCommands][0] = strval( result );
			mysql_fetch_field_row(result,"Commands2"); PlayerInfo[playerid][pCommands][1] = strval( result );
			mysql_fetch_field_row(result,"Commands3"); PlayerInfo[playerid][pCommands][2] = strval( result );
			mysql_fetch_field_row(result,"Commands4"); PlayerInfo[playerid][pCommands][3] = strval( result );
			mysql_fetch_field_row(result,"Commands5"); PlayerInfo[playerid][pCommands][4] = strval( result );

			if(SpecialWeek == 1) {
				new questsvar[1028];
				cache_get_field_content(0, "SpecialQuest", result); format(questsvar, 256, result);
				sscanf(questsvar, "p<|>iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii", 
				PlayerInfo[playerid][pSpecialQuest][0], PlayerInfo[playerid][pSpecialQuest][1], PlayerInfo[playerid][pSpecialQuest][2], PlayerInfo[playerid][pSpecialQuest][3], PlayerInfo[playerid][pSpecialQuest][4],
				PlayerInfo[playerid][pSpecialQuest][5], PlayerInfo[playerid][pSpecialQuest][6], PlayerInfo[playerid][pSpecialQuest][7], PlayerInfo[playerid][pSpecialQuest][8], PlayerInfo[playerid][pSpecialQuest][9],
				PlayerInfo[playerid][pSpecialQuest][10], PlayerInfo[playerid][pSpecialQuest][11], PlayerInfo[playerid][pSpecialQuest][12], PlayerInfo[playerid][pSpecialQuest][13], PlayerInfo[playerid][pSpecialQuest][14],
				PlayerInfo[playerid][pSpecialQuest][15], PlayerInfo[playerid][pSpecialQuest][16], PlayerInfo[playerid][pSpecialQuest][17], PlayerInfo[playerid][pSpecialQuest][18], PlayerInfo[playerid][pSpecialQuest][19],		
				PlayerInfo[playerid][pSpecialQuest][20], PlayerInfo[playerid][pSpecialQuest][21], PlayerInfo[playerid][pSpecialQuest][22], PlayerInfo[playerid][pSpecialQuest][23], PlayerInfo[playerid][pSpecialQuest][24],
				PlayerInfo[playerid][pSpecialQuest][25], PlayerInfo[playerid][pSpecialQuest][26], PlayerInfo[playerid][pSpecialQuest][27], PlayerInfo[playerid][pSpecialQuest][28], PlayerInfo[playerid][pSpecialQuest][29],	
				PlayerInfo[playerid][pSpecialQuest][30], PlayerInfo[playerid][pSpecialQuest][31], PlayerInfo[playerid][pSpecialQuest][32], PlayerInfo[playerid][pSpecialQuest][33], PlayerInfo[playerid][pSpecialQuest][34],
				PlayerInfo[playerid][pSpecialQuest][35], PlayerInfo[playerid][pSpecialQuest][36], PlayerInfo[playerid][pSpecialQuest][37], PlayerInfo[playerid][pSpecialQuest][38], PlayerInfo[playerid][pSpecialQuest][39],	
				PlayerInfo[playerid][pSpecialQuest][40], PlayerInfo[playerid][pSpecialQuest][41], PlayerInfo[playerid][pSpecialQuest][42], PlayerInfo[playerid][pSpecialQuest][43], PlayerInfo[playerid][pSpecialQuest][44],
				PlayerInfo[playerid][pSpecialQuest][45], PlayerInfo[playerid][pSpecialQuest][46], PlayerInfo[playerid][pSpecialQuest][47], PlayerInfo[playerid][pSpecialQuest][48], PlayerInfo[playerid][pSpecialQuest][49],
				PlayerInfo[playerid][pSpecialQuest][50], PlayerInfo[playerid][pSpecialQuest][51], PlayerInfo[playerid][pSpecialQuest][52], PlayerInfo[playerid][pSpecialQuest][53], PlayerInfo[playerid][pSpecialQuest][54],
				PlayerInfo[playerid][pSpecialQuest][55], PlayerInfo[playerid][pSpecialQuest][56], PlayerInfo[playerid][pSpecialQuest][57], PlayerInfo[playerid][pSpecialQuest][58], PlayerInfo[playerid][pSpecialQuest][59],
				PlayerInfo[playerid][pSpecialQuest][60], PlayerInfo[playerid][pSpecialQuest][61], PlayerInfo[playerid][pSpecialQuest][62], PlayerInfo[playerid][pSpecialQuest][63], PlayerInfo[playerid][pSpecialQuest][64],
				PlayerInfo[playerid][pSpecialQuest][65], PlayerInfo[playerid][pSpecialQuest][66], PlayerInfo[playerid][pSpecialQuest][67], PlayerInfo[playerid][pSpecialQuest][68], PlayerInfo[playerid][pSpecialQuest][69],		
				PlayerInfo[playerid][pSpecialQuest][70], PlayerInfo[playerid][pSpecialQuest][71], PlayerInfo[playerid][pSpecialQuest][72], PlayerInfo[playerid][pSpecialQuest][73], PlayerInfo[playerid][pSpecialQuest][74],
				PlayerInfo[playerid][pSpecialQuest][75], PlayerInfo[playerid][pSpecialQuest][76], PlayerInfo[playerid][pSpecialQuest][77], PlayerInfo[playerid][pSpecialQuest][78], PlayerInfo[playerid][pSpecialQuest][79],	
				PlayerInfo[playerid][pSpecialQuest][80], PlayerInfo[playerid][pSpecialQuest][81], PlayerInfo[playerid][pSpecialQuest][82], PlayerInfo[playerid][pSpecialQuest][83], PlayerInfo[playerid][pSpecialQuest][84],
				PlayerInfo[playerid][pSpecialQuest][85], PlayerInfo[playerid][pSpecialQuest][86], PlayerInfo[playerid][pSpecialQuest][87], PlayerInfo[playerid][pSpecialQuest][88], PlayerInfo[playerid][pSpecialQuest][89],	
				PlayerInfo[playerid][pSpecialQuest][90], PlayerInfo[playerid][pSpecialQuest][91], PlayerInfo[playerid][pSpecialQuest][92], PlayerInfo[playerid][pSpecialQuest][93], PlayerInfo[playerid][pSpecialQuest][94],
				PlayerInfo[playerid][pSpecialQuest][95], PlayerInfo[playerid][pSpecialQuest][96], PlayerInfo[playerid][pSpecialQuest][97], PlayerInfo[playerid][pSpecialQuest][98], PlayerInfo[playerid][pSpecialQuest][99]);	
				for(new i = 0; i < 100; i++) {
					if(PlayerInfo[playerid][pSpecialQuest][i] == 0) {				
						PlayerInfo[playerid][pObjectQuest][i] = CreatePlayerObject(playerid, 2710, QuestPos[i][0], QuestPos[i][1], QuestPos[i][2], 0, 0, 0, 300.0);
					}
				}
			}	
			
			new achivar[256];
			cache_get_field_content(0, "AchievementStatus", result); format(achivar, 256, result);
			sscanf(achivar, "p<|>iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii", 
			PlayerInfo[playerid][pAchievementStatus][0], PlayerInfo[playerid][pAchievementStatus][1], PlayerInfo[playerid][pAchievementStatus][2], PlayerInfo[playerid][pAchievementStatus][3], PlayerInfo[playerid][pAchievementStatus][4],
			PlayerInfo[playerid][pAchievementStatus][5], PlayerInfo[playerid][pAchievementStatus][6], PlayerInfo[playerid][pAchievementStatus][7], PlayerInfo[playerid][pAchievementStatus][8], PlayerInfo[playerid][pAchievementStatus][9],
			PlayerInfo[playerid][pAchievementStatus][10], PlayerInfo[playerid][pAchievementStatus][11], PlayerInfo[playerid][pAchievementStatus][12], PlayerInfo[playerid][pAchievementStatus][13], PlayerInfo[playerid][pAchievementStatus][14],
			PlayerInfo[playerid][pAchievementStatus][15], PlayerInfo[playerid][pAchievementStatus][16], PlayerInfo[playerid][pAchievementStatus][17], PlayerInfo[playerid][pAchievementStatus][18], PlayerInfo[playerid][pAchievementStatus][19],		
			PlayerInfo[playerid][pAchievementStatus][20], PlayerInfo[playerid][pAchievementStatus][21], PlayerInfo[playerid][pAchievementStatus][22], PlayerInfo[playerid][pAchievementStatus][23], PlayerInfo[playerid][pAchievementStatus][24],
			PlayerInfo[playerid][pAchievementStatus][25], PlayerInfo[playerid][pAchievementStatus][26], PlayerInfo[playerid][pAchievementStatus][27], PlayerInfo[playerid][pAchievementStatus][28], PlayerInfo[playerid][pAchievementStatus][29],	
			PlayerInfo[playerid][pAchievementStatus][30], PlayerInfo[playerid][pAchievementStatus][31]);
			
			SpawnChange[playerid] = cache_get_field_content_int(0, "SpawnChange");
			PlayerInfo[playerid][pSeconds] = cache_get_field_content_float(0, "Seconds");
			PlayerInfo[playerid][pUsed] = cache_get_field_content_int(0, "Used");
		
			PlayerInfo[playerid][pRacePlace][0] = cache_get_field_content_int(0, "RacePlace1");
			PlayerInfo[playerid][pRacePlace][1] = cache_get_field_content_int(0, "RacePlace2");
			PlayerInfo[playerid][pRacePlace][2] = cache_get_field_content_int(0, "RacePlace3");
			PlayerInfo[playerid][pRacePlace][3] = cache_get_field_content_int(0, "RacePlace4");
					
			PlayerInfo[playerid][pArenaStats][0] = cache_get_field_content_int(0, "ArenaKills");
			PlayerInfo[playerid][pArenaStats][1] = cache_get_field_content_int(0, "ArenaDeaths");
									
			PlayerInfo[playerid][pPaintKills][0] = cache_get_field_content_int(0, "PaintKills1");
			PlayerInfo[playerid][pPaintKills][1] = cache_get_field_content_int(0, "PaintKills2");
			PlayerInfo[playerid][pPaintKills][2] = cache_get_field_content_int(0, "PaintKills3");
	
			PlayerInfo[playerid][pPaintDeaths][2] = cache_get_field_content_int(0, "PaintDeaths1");
			PlayerInfo[playerid][pPaintDeaths][2] = cache_get_field_content_int(0, "PaintDeaths2");
			PlayerInfo[playerid][pPaintDeaths][2] = cache_get_field_content_int(0, "PaintDeaths3");

			PlayerInfo[playerid][pCarLicS] = cache_get_field_content_int(0, "CarLicS", SQL);
			PlayerInfo[playerid][pBoatLicS] = cache_get_field_content_int(0, "BoatLicS", SQL);
			PlayerInfo[playerid][pFlyLicS] = cache_get_field_content_int(0, "FlyLicS", SQL);
			PlayerInfo[playerid][pGunLicS] = cache_get_field_content_int(0, "GunLicS", SQL);		
			
			PlayerInfo[playerid][pCarKey][0] = cache_get_field_content_int(0, "CarKey1", SQL);
			PlayerInfo[playerid][pCarKey][1] = cache_get_field_content_int(0, "CarKey2", SQL);
			PlayerInfo[playerid][pCarKey][2] = cache_get_field_content_int(0, "CarKey3", SQL);
			PlayerInfo[playerid][pCarKey][3] = cache_get_field_content_int(0, "CarKey4", SQL);
			PlayerInfo[playerid][pCarKey][4] = cache_get_field_content_int(0, "CarKey5", SQL);
			PlayerInfo[playerid][pCarKey][5] = cache_get_field_content_int(0, "CarKey6", SQL);
			PlayerInfo[playerid][pCarKey][6] = cache_get_field_content_int(0, "CarKey7", SQL);
			PlayerInfo[playerid][pCarKey][7] = cache_get_field_content_int(0, "CarKey8", SQL);
			PlayerInfo[playerid][pCarKey][8] = cache_get_field_content_int(0, "CarKey9", SQL);
			PlayerInfo[playerid][pCarKey][9] = cache_get_field_content_int(0, "CarKey10", SQL);
			PlayerInfo[playerid][pShowDMG] = cache_get_field_content_int(0, "ShowDMG", SQL);
			PlayerInfo[playerid][pSlot][0] = cache_get_field_content_int(0, "Slot1", SQL);
			PlayerInfo[playerid][pSlot][1] = cache_get_field_content_int(0, "Slot2", SQL);
			PlayerInfo[playerid][pSlot][2] = cache_get_field_content_int(0, "Slot3", SQL);
			PlayerInfo[playerid][pSlot][3] = cache_get_field_content_int(0, "Slot4", SQL);
			PlayerInfo[playerid][pSlot][4] = cache_get_field_content_int(0, "Slot5", SQL);
			
			PlayerInfo[playerid][pDailyMission][0] = cache_get_field_content_int(0, "DailyMission", SQL);
			PlayerInfo[playerid][pDailyMission][1] = cache_get_field_content_int(0, "DailyMission2", SQL);
			PlayerInfo[playerid][pNeedProgress][0] = cache_get_field_content_int(0, "NeedProgress1", SQL);
			PlayerInfo[playerid][pNeedProgress][1] = cache_get_field_content_int(0, "NeedProgress2", SQL);			
			PlayerInfo[playerid][pProgress][0] = cache_get_field_content_int(0, "Progress", SQL);
			PlayerInfo[playerid][pProgress][1] = cache_get_field_content_int(0, "Progress2", SQL);
			PlayerInfo[playerid][pPizzaSkill] = cache_get_field_content_int(0, "PizzaSkill", SQL);
			PlayerInfo[playerid][pCurierSkill] = cache_get_field_content_int(0, "CurierSkill", SQL);
			PlayerInfo[playerid][pGasCan] = cache_get_field_content_int(0, "GasCan", SQL);
			new string[180];
			PlayerInfo[playerid][pGlasses] = cache_get_field_content_int(0, "Glasses", SQL);
			PlayerInfo[playerid][pShowGlasses] = cache_get_field_content_int(0, "ShowGlasses", SQL);
			
			PlayerInfo[playerid][pShowHP] = cache_get_field_content_int(0, "ShowHP", SQL);
			PlayerInfo[playerid][pShowCP] = cache_get_field_content_int(0, "ShowCP", SQL);
			PlayerInfo[playerid][pShowAP] = cache_get_field_content_int(0, "ShowAP", SQL);
			
			PlayerInfo[playerid][pPin] = cache_get_field_content_int(0, "Pin", SQL);
			PlayerInfo[playerid][pFires] = cache_get_field_content_int(0, "Fires", SQL);
			PlayerInfo[playerid][pColor] = cache_get_field_content_int(0, "Color", SQL);
			PlayerInfo[playerid][pYT] = cache_get_field_content_int(0, "Youtuber", SQL);
			PlayerInfo[playerid][pDays] = cache_get_field_content_int(0, "Days", SQL);		
            
			PlayerInfo[playerid][pPilotSkill] = cache_get_field_content_int(0, "PilotSkill", SQL);		
			PlayerInfo[playerid][pEscapePoints] = cache_get_field_content_int(0, "EscapePoints", SQL);
			PlayerInfo[playerid][pHat] = cache_get_field_content_int(0, "Hat", SQL);
			PlayerInfo[playerid][pCoins] = cache_get_field_content_int(0, "Coins", SQL);
			PlayerInfo[playerid][pShowHat] = cache_get_field_content_int(0, "ShowHat", SQL);
			PlayerInfo[playerid][pDailyLogin] = cache_get_field_content_int(0, "DailyLogin", SQL);
			
			PlayerInfo[playerid][pCrash] = cache_get_field_content_int(0, "Crash", SQL);
			/*if(PlayerInfo[playerid][pCrash] == 1) {
				PlayerInfo[playerid][playerPos][0] = cache_get_field_content_float(0, "PosX", SQL);
				PlayerInfo[playerid][playerPos][1] = cache_get_field_content_float(0, "PosY", SQL);
				PlayerInfo[playerid][playerPos][2] = cache_get_field_content_float(0, "PosZ", SQL);	
				SetTimerEx("CrashPos", 1000, false, "i", playerid);	
			}*/
			
  			PlayerInfo[playerid][pAJail] = cache_get_field_content_int(0, "AJail", SQL);		
  
			PlayerInfo[playerid][pHW] = cache_get_field_content_int(0, "HW", SQL);
			PlayerInfo[playerid][pAW] = cache_get_field_content_int(0, "AW", SQL);
			PlayerInfo[playerid][pLW] = cache_get_field_content_int(0, "LW", SQL);
			  
			new clanid = PlayerInfo[playerid][pClan];
			if(PlayerInfo[playerid][pClan] != 0 && PlayerInfo[playerid][pTag] == 0) {
			    format(string, sizeof(string), "%s%s", ClanInfo[clanid][clTag], PlayerInfo[playerid][pUsername]);
			    SetPlayerName(playerid, string);
			}
			else if(PlayerInfo[playerid][pClan] != 0 && PlayerInfo[playerid][pTag] == 1) {
			    format(string, sizeof(string), "%s%s", PlayerInfo[playerid][pUsername], ClanInfo[clanid][clTag]);
			    SetPlayerName(playerid, string);
			}
			
			LoadPlayerCars(playerid);			
			SetPlayerToTeamColor(playerid);
			ADeathMessage(playerid, INVALID_PLAYER_ID, 200);
			new ip[16];
			GetPlayerIp(playerid, ip, sizeof(ip));
			format(string, sizeof(string), "UPDATE `users` SET `Status` = '1', `IP`='%s' WHERE `ID`='%d'", ip, PlayerInfo[playerid][pSQLID]);
			mysql_tquery(SQL,string, "", "");
			UpdateVar(playerid, "DayLogin", 1);
			TextDrawHideForPlayer(playerid, ServerTD);
			GameTextForPlayer(playerid, " ", 1000, 4);
			SpawnPlayer(playerid);
	   	}
		for( new j = 0; j <= 100; j++) SendClientMessage(playerid, COLOR_WHITE, "");
	}
	else {
		new loginstring[128];
		format(loginstring,sizeof(loginstring),"Parola introdusa de tine este incorecta!\nIntrodu parola corecta altfel vei primi kick!",GetName(playerid));
		ShowPlayerDialog(playerid, DIALOG_LOGIN3,DIALOG_STYLE_PASSWORD,"Logare",loginstring,"Logare","Quit");
        mysql_free_result();
        gPlayerLogTries[playerid] += 1;
		new string[180];
		if(gPlayerLogTries[playerid] < 3) format(string, sizeof(string), "Parola incorecta! Mai ai la dispozitie %d incercari.", 3-gPlayerLogTries[playerid]);
		else format(string, sizeof(string), "Parola incorecta! Incercarile au fost epuizate si ai primit kick.", 3-gPlayerLogTries[playerid]);
		SCM(playerid, COLOR_WARNING, string);				
        if(gPlayerLogTries[playerid] == 3) KickEx(playerid);
        return 1;
	}
	mysql_free_result();
	ResetPlayerCash(playerid);
	GivePlayerCash(playerid,PlayerInfo[playerid][pCash]);
	CurrentMoney[playerid] = PlayerInfo[playerid][pCash];
	KillTimer(login[playerid]);
	if(PlayerInfo[playerid][pReg] == 0) {
		PlayerInfo[playerid][pLevel] = 1;
		PlayerInfo[playerid][pHealth] = 100.0;
		PlayerInfo[playerid][pInt] = 0;
		PlayerInfo[playerid][pLocal] = 255;
		PlayerInfo[playerid][pTeam] = 3;
		PlayerInfo[playerid][pModel] = 250;
		PlayerInfo[playerid][pHouse] = 999;
		PlayerInfo[playerid][pBizz] = 255;
		PlayerInfo[playerid][pAccount] = 1000;
		PlayerInfo[playerid][pReg] = 1;
		SetPlayerInterior(playerid,0);
		new string[300];
		new d,m,y;
		getdate(y,m,d);
		new h,mine,s;
		gettime(h,mine,s);
		format(string, sizeof(string),  "%d/%d/%d %d:%d:%d",d,m,y,h,mine,s);
		strmid(PlayerInfo[playerid][pRegistredDate], string, 0, strlen(string), 255);
		new str[180];
		format(str,sizeof(str),"UPDATE users SET `pHealth`='100.0',`Team`='3',`Model`='250' WHERE `ID`='%d'",PlayerInfo[playerid][pSQLID]);
		mysql_query(SQL,str);
		Update(playerid,pCashx);
		Update(playerid,pLevelx);
		Update(playerid,pHousex);
		Update(playerid,pBizzx);
		Update(playerid,pPnumberx);
		Update(playerid,pRegx);
		Update(playerid,pRegistredDatex);
	}
	if(PlayerInfo[playerid][pBTemp] == 1) { TempBanCheck(playerid); return 1; }
	if(PlayerInfo[playerid][pBanned] == 1) {
		for( new j = 0; j <= 100; j++) SendClientMessage(playerid, COLOR_WHITE, "");
		SCM(playerid, COLOR_WARNING, "Acest cont este banat permanent!");
		new str[180];
		format(str, sizeof str, "Ai fost banat de adminul %s.",PlayerInfo[playerid][pBBy]);
		SendClientMessage(playerid, COLOR_CLIENT, str);
		format(str, sizeof str, "Motivul: %s",PlayerInfo[playerid][pBReason]);
		SendClientMessage(playerid, COLOR_CLIENT, str);						
		KickEx(playerid);
		SetPlayerCameraPos(playerid, 1183.0143, -965.7394, 129.6071);
		SetPlayerCameraLookAt(playerid, 1183.7214, -965.0270, 129.2470);
		TogglePlayerSpectating(playerid, 0);		
		return 1;
	}
    StopAudioStreamForPlayer(playerid);
	SetPlayerScore(playerid, PlayerInfo[playerid][pLevel]);
	new string2[180];
	if(PlayerInfo[playerid][pTut] != 0) {	
		format(string2, 256, "Bine ai venit, %s!", GetName(playerid));
		SendClientMessage(playerid, -1, string2);
		if(PlayerInfo[playerid][pMember] != 0) {
			if(PlayerInfo[playerid][pDays] == 30) {
				if(PlayerInfo[playerid][pMember] == 11) finishAchievement(playerid, 23);	
				else if(IsACop(playerid)) finishAchievement(playerid, 24);	
				else if(IsAMember(playerid)) finishAchievement(playerid, 25);	
				else finishAchievement(playerid, 22);		
			}
		}
	}	
	if(PlayerInfo[playerid][pWantedLevel] > 0 && PlayerInfo[playerid][pTut] != 0) {
		format(string2, sizeof(string2), "Aveai wanted %d inainte sa iesi de pe server.",PlayerInfo[playerid][pWantedLevel]);
		SetPlayerWantedLevel(playerid, PlayerInfo[playerid][pWantedLevel]);
		SendClientMessage(playerid, COLOR_LIGHTRED, string2);
	}
	SetSpawnInfo(playerid, PlayerInfo[playerid][pTeam], PlayerInfo[playerid][pModel], 1731.8511,-1912.0792,13.5624, 1.0, -1, -1, -1, -1, -1, -1);
	if(gTeam[playerid] == 0) gTeam[playerid] = 3;
	else gTeam[playerid] = PlayerInfo[playerid][pTeam];
	if(PlayerInfo[playerid][pMember] != 0 && PlayerInfo[playerid][pTut] != 0) {
	    new disc[84];
	    format(disc,sizeof(disc),"(Factiune) %s s-a conectat pe server.",GetName(playerid));
	    SendFactionMessage(PlayerInfo[playerid][pMember], COLOR_CLIENT, disc);
	}

	HudProgress[playerid][0] = CreatePlayerProgressBar(playerid, 513.00, 150.00, 85.50, 2.50, 0x00FF00FF, 100.0);	
	HudProgress[playerid][1] = CreatePlayerProgressBar(playerid, 513.00, 175.00, 85.50, 2.50, 0x00FF00FF, 100.0);
	UpdateProgress(playerid, 0);
	UpdateProgress(playerid, 1);
		
	new sendername[25],playersip[64],iplog[184];
	GetPlayerName(playerid,sendername,sizeof(sendername));
	GetPlayerIp(playerid,playersip,sizeof(playersip));
	LogIP(playersip,PlayerInfo[playerid][pSQLID]);
	format(iplog,sizeof(iplog),"%s(%d) connected on the server with IP: %s.",sendername,playerid,playersip);
	SendIP(COLOR_WHITE,iplog);
	IsPlayerLogged[playerid] = 1;
	if(PlayerInfo[playerid][pTut] == 0) {
		gOoc[playerid] = 1; gNews[playerid] = 1; gFam[playerid] = 1;
		TogglePlayerControllable(playerid, 0);
		RegistrationStep[playerid] = 1;
		SendClientMessage(playerid, 0xFFDE96FF, "Te rugam sa raspunzi la urmatoarele intrebari.");
		ShowPlayerDialog(playerid, DIALOG_REGISTER, DIALOG_STYLE_MSGBOX, "Register:", "Care este sexul caracterului tau?\nMasculin sau Feminin?", "Masculin", "Feminin");
		SetPlayerInterior(playerid, 0);
	}	
	printf("%s has logged in with IP %s.",sendername,playersip);
	if(PlayerInfo[playerid][pDailyMission][0] == -1 || PlayerInfo[playerid][pDailyMission][1] == -1) GiveQuest(playerid);
	if(PlayerInfo[playerid][pTut] != 0) {
		if(PlayerInfo[playerid][pLevel] < 5) {
			SendClientMessage(playerid, -1, "Pentru a vedea ce misiuni ai in aceasta zi, foloseste /quests.");		
			if(strlen(PlayerInfo[playerid][pPin]) == 0) {
				if(PlayerInfo[playerid][pLevel] < 5) {
					SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Pentru o securitate cat mai mare a contului tau, iti poti pune un PIN format din 4 cifre.");
					SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Foloseste comanda '/setpin' pentru a-ti pune un PIN!");
				}	
			}
			else {
				SendClientMessage(playerid, COLOR_LIGHTBLUE, "* Contul tau are un PIN setat. Foloseste comanda '/loginpin' pentru a pune codul de securitate.");
			}	
		}
		new clanid = PlayerInfo[playerid][pClan], string[180];
		if(clanid != 0) {
			format(string, sizeof(string), "{%s}(CMOTD): %s.", ClanInfo[PlayerInfo[playerid][pClan]][clColor], ClanInfo[PlayerInfo[playerid][pClan]][clMotd]);
			MesajLung(playerid, -1, string);
		}
		if(PlayerInfo[playerid][pMember] != 0) {
			if(strlen(DynamicFactions[PlayerInfo[playerid][pMember]][fAnn]) > 0)
			{
				new factioninfo[128];
				format(factioninfo,sizeof(factioninfo), "(FMOTD): %s",DynamicFactions[PlayerInfo[playerid][pMember]][fAnn]);
				MesajLung(playerid,COLOR_YELLOW,factioninfo);
			}		
		}
		new szQuery[256], szString[180], onf, Cache: results;
		format(szQuery, sizeof(szQuery), "SELECT * FROM `friends` WHERE `AddBy` = '%d'", PlayerInfo[playerid][pSQLID]);
		results = mysql_query(SQL, szQuery);
		// playerid login
		for(new i, j = cache_get_row_count (); i != j; ++i)
		{
			cache_get_field_content(i, "friendName", szString);
			new userID = GetPlayerID(szString);
			if(userID != INVALID_PLAYER_ID) onf ++;
		}
		cache_delete(results);
		format(string, sizeof(string), "Ai %d prieteni conectati in lista ta de prieteni.", onf);
		
		if(onf != 0) {
			PlayerTextDrawSetString(playerid, FriendTD, string);
			PlayerTextDrawShow(playerid, FriendTD);
			SetTimerEx("HideFriendTD", 3000, false, "i", playerid);			
		}
	
		if(PlayerInfo[playerid][pDailyLogin] == 0) SCM(playerid, COLOR_LIGHTBLUE, "Vei primi de doua ori mai multi bani si puncte de respect la urmatorul payday.");
		if(PlayerInfo[playerid][pBizz] != 255) finishAchievement(playerid, 2);
		if(PlayerInfo[playerid][pHouse] != 999 && strcmp(GetName(playerid), HouseInfo[PlayerInfo[playerid][pHouse]][hOwner], true) == 0) finishAchievement(playerid, 3);

		// if exist player in other friend list
		foreach(Player, i) {
			if(IsPlayerConnected(i) && IsPlayerLogged[i] == 1) {
				format(szQuery, sizeof(szQuery), "SELECT * FROM `friends` WHERE `AddBy` = '%d' AND `friendID` = '%d'", PlayerInfo[i][pSQLID], PlayerInfo[playerid][pSQLID]);
				results = mysql_query(SQL, szQuery);
				cache_get_field_content(0, "AddBy", szString);
				new friendID = strval(szString);
				cache_delete(results);
				if(PlayerInfo[i][pSQLID] == friendID && friendID != 0) {
					if(PlayerInfo[playerid][pAdmin] < 7) {
						format(string, sizeof(string), "Prietenul tau, %s, s-a conectat pe server.", GetName(playerid));
						PlayerTextDrawSetString(i, FriendTD, string);
						PlayerTextDrawShow(i, FriendTD);
						SetTimerEx("HideFriendTD", 3000, false, "i", i);	
					}	
				}
			}
		}	
		CalculateEmails(playerid);
	}	
	return 1;
}