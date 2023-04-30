#include a_samp>


cmd:startwork(playerid, params[], help) {
	if(PlayerInfo[playerid][pJob] == 11) return SCM(playerid, -1, "Foloseste /fish pentru a incepe munca la acest job!");
	if(IsPlayerInAnyVehicle(playerid)) return SCM(playerid, COLOR_LGREEN, "Eroare: Nu poti aceasta comanda dintr-un vehicul!");
	new Float: Pos[3], Float: CarAngle, string[128];
	new skill = GetPlayerSkill(playerid);
	if(PlayerInfo[playerid][pJob] == 0) return SCM(playerid, COLOR_GREY, "Nu ai un job!");
	if(JobWorking[playerid] == 1) return SCM(playerid, COLOR_WHITE, "Muncesti deja.");
 	GetPlayerPos(playerid, Pos[0], Pos[1], Pos[2]);
    if(targetfind[playerid] != -1) return ShowPlayerDialog(playerid, DIALOG_CHECKPOINT, DIALOG_STYLE_MSGBOX, "Checkpoint", "Ai deja un checkpoint activ.\nDoresti sa-l anulezi? Daca da, apasa pe 'Ok'.", "Ok", "Exit");
	if(GetPlayerVirtualWorld(playerid) != 0) return 1;
	if(JobDeelay[playerid][PlayerInfo[playerid][pJob]] != 0 && PlayerInfo[playerid][pAdmin] < 6) return JobTimeDeelay(playerid);
	switch(PlayerInfo[playerid][pJob]) {
		case 1: {        //FARMER
	        if(PlayerToPoint(7.0, playerid, -372.6979, -1456.3641, 26.4046)) {
				if(PlayerInfo[playerid][pCarLic] == 0) return SCM(playerid, COLOR_LGREEN, "Eroare: Ai nevoie de o licenta de condus pentru a putea munci la acest job!");
				JobSeconds[playerid] = 120;
                CarAngle = -184.0199;
                DisablePlayerCheckpointEx(playerid);
			}
			else {
 				if(CP[playerid] != 0) return ShowPlayerDialog(playerid, DIALOG_CHECKPOINT, DIALOG_STYLE_MSGBOX, "Checkpoint", "Ai deja un checkpoint activ.\nDoresti sa-l anulezi? Daca da, apasa pe 'Ok'.", "Ok", "Exit");
	          	CP[playerid] = 53;
				SCM(playerid, COLOR_GREY, "Nu esti la locul unde poti incepe munca. Ti-am pus un checkpoint, du-te la el!");
				SetPlayerCheckpointEx(playerid, -372.6979, -1456.3641, 26.4046, 7.0);
				return 1;
		    }
	    }
		case 2: {  //TRUCKER
	        if(PlayerToPoint(7.0, playerid, -1017.3097,-638.8459,32.0078)) {
				if(PlayerInfo[playerid][pCarLic] == 0) return SCM(playerid, COLOR_LGREEN, "Eroare: Ai nevoie de o licenta de condus pentru a putea munci la acest job!");
                CarAngle = 74.1729;
                CP[playerid] = 52;
                DisablePlayerCheckpointEx(playerid);
   		    	new szDialog2[1024];				
				strcat(szDialog2, "Destination\tCity\tDistance\tSkill\n");
				strcat(szDialog2, "Aeroport\tLos Santos\t%d\t1\n");
				strcat(szDialog2, "Odean Docks\tLos Santos\t%d\t1\n");
				strcat(szDialog2, "Burger Shot\tLos Santos\t%d\t1\n");
				strcat(szDialog2, "Aeroport\tLas Venturas\t%d\t1\n");
				strcat(szDialog2, "Rent\tLos Santos\t%d\t1\n");
				strcat(szDialog2, "Baza Militara\tLas Venturas\t%d\t1\n");
				strcat(szDialog2, "Depozit Amazon\tLas Venturas\t%d\t1\n");
				strcat(szDialog2, "Linden Side \tLas Venturas\t%d\t1\n");
				strcat(szDialog2, "Aeroport\tSan Fierro\t%d\t1\n");
				strcat(szDialog2, "Docks\tSan Fierro\t%d\t1\n");
				strcat(szDialog2, "Vest\tSan Fierro\t%d\t1\n");
				strcat(szDialog2, "Angel Pine\tSan Fierro\t%d\t1\n");
				ShowPlayerDialog(playerid, DIALOG_TRUCKER, DIALOG_STYLE_TABLIST_HEADERS, "Choose destination", szDialog2, "Select", "Cancel");			

			}
	        else {
 				if(CP[playerid] != 0) return ShowPlayerDialog(playerid, DIALOG_CHECKPOINT, DIALOG_STYLE_MSGBOX, "Checkpoint", "Ai deja un checkpoint activ.\nDoresti sa-l anulezi? Daca da, apasa pe 'Ok'.", "Ok", "Exit");
	          	CP[playerid] = 53;
				SCM(playerid, COLOR_GREY, "Nu esti la locul unde poti incepe munca. Ti-am pus un checkpoint, du-te la el!");
				SetPlayerCheckpointEx(playerid, -1017.3097,-638.8459,32.0078, 7.0);
				return 1;
		    }
	    }
	    case 3: { //CAR JACKER
			if(GetPlayerSkill(playerid) == 1) PlayerTextDrawSetString(playerid, InfosTD, "~y~Car Jacker~w~~h~~n~Fura un vehicul public!");
			else if(GetPlayerSkill(playerid) == 2) PlayerTextDrawSetString(playerid, InfosTD, "~y~Car Jacker~w~~h~~n~Fura un vehicul personal descuiat!");
			else if(GetPlayerSkill(playerid) == 3) PlayerTextDrawSetString(playerid, InfosTD, "~y~Car Jacker~w~~h~~n~Fura un vehicul ce apartine unei mafii!");
			else if(GetPlayerSkill(playerid) == 4) PlayerTextDrawSetString(playerid, InfosTD, "~y~Car Jacker~w~~h~~n~Fura un vehicul personal incuiat!");
			else if(GetPlayerSkill(playerid) == 5) PlayerTextDrawSetString(playerid, InfosTD, "~y~Car Jacker~w~~h~~n~Fura un vehicul ce apartine unui departament de politie!");
			PlayerTextDrawShow(playerid, InfosTD);
			JobWorking[playerid] = 1;
			SetTimerEx("HideTextdraw", 8000, 0, "%d", playerid);
			return 1;
	    }
	    case 4: { //ARMS DEALER
			if(PlayerInfo[playerid][pWantedLevel] != 0) return SCM(playerid, -1, "Nu poti munci la acest job deoarece ai wanted!");
			if(!PlayerToPoint(10.0, playerid, 2770.2822,-1610.9043,11.0418)) {				
				SCM(playerid, COLOR_GREY, "Nu esti la locul unde poti incepe munca. Ti-am pus un checkpoint, du-te la el!");
				SetPlayerCheckpointEx(playerid, 2770.2822,-1610.9043,11.0418, 10.0);
				CP[playerid] = 53;
				return 1;
			}
			if(PlayerInfo[playerid][pCarLic] == 0) return SCM(playerid, COLOR_LGREEN, "Eroare: Ai nevoie de o licenta de condus pentru a putea munci la acest job!");
			CP[playerid] = 156;
			new rand = random(3);			
			switch(rand) {
				case 0: SetPlayerCheckpointEx(playerid, 2790.6213,-2523.6418,13.6704, 5.0);
				case 1: SetPlayerCheckpointEx(playerid, 2529.4214,-2009.4240,13.5798, 5.0);
				case 2: SetPlayerCheckpointEx(playerid, 2180.0774,-2317.1672,13.5703, 5.0); 
				case 3: SetPlayerCheckpointEx(playerid, 681.2267,-442.6591,16.3633, 5.0);
			}
			
			format(string, sizeof(string), "Du-te la checkpoint-ul de pe mapa pentru a livra materialele!");
			PlayerTextDrawSetString(playerid, InfosTD, string);
			SetTimerEx("HideTextdraw", 8000, 0, "%d", playerid);
			PlayerTextDrawShow(playerid, InfosTD);
			
			CarAngle = 277.2561;
			StartingWork[playerid] = 0;
			CurseFacute[playerid] = 0;
			MoneyEarned[playerid] = 0;		
		}
		case 5..7: return 1;
		case 8: {//PIZZA
	        if(PlayerToPoint(7.0, playerid, 2113.9392,-1775.1980,13.3918)) {
				if(PlayerInfo[playerid][pCarLic] == 0) return SCM(playerid, COLOR_LGREEN, "Eroare: Ai nevoie de o licenta de condus pentru a putea munci la acest job!");
                CarAngle = 0;
                CP[playerid] = 155;
				new j = random(housess)+1;
				if(j == 0) j = 1;
				SetPlayerCheckpointEx(playerid, HouseInfo[j][hEntrancex],HouseInfo[j][hEntrancey],HouseInfo[j][hEntrancez], 7.0);
				format(string, sizeof(string), "Du-te la punctul ~r~~h~rosu~w~~h~ de pe mapa pentru a livra pizza.~n~Distanta: ~y~%0.1fm.", GetPlayerDistanceFromPoint(playerid, HouseInfo[j][hEntrancex],HouseInfo[j][hEntrancey],HouseInfo[j][hEntrancez]));
				PlayerTextDrawSetString(playerid, InfosTD, string);
				SetTimerEx("HideTextdraw", 8000, 0, "%d", playerid);
				PlayerTextDrawShow(playerid, InfosTD);				
			}
	        else {
 				if(CP[playerid] != 0) return ShowPlayerDialog(playerid, DIALOG_CHECKPOINT, DIALOG_STYLE_MSGBOX, "Checkpoint", "Ai deja un checkpoint activ.\nDoresti sa-l anulezi? Daca da, apasa pe 'Ok'.", "Ok", "Exit");
	          	CP[playerid] = 53;
				SCM(playerid, COLOR_GREY, "Nu esti la locul unde poti incepe munca. Ti-am pus un checkpoint, du-te la el!");
				SetPlayerCheckpointEx(playerid,2113.9392,-1775.1980,13.3918, 7.0);
				return 1;
		    }
	    }
	    case 9: {//AMAZON
			if(!PlayerToPoint(6.0, playerid, 1663.3005,729.2867,10.8203)) {
				SCM(playerid, COLOR_GREY, "Nu esti la locul unde poti incepe munca. Ti-am pus un checkpoint, du-te la el!");
				SetPlayerCheckpointEx(playerid, 1663.3005,729.2867,10.8203, 6.0);
				CP[playerid] = 53;
				return 1;
			}
			if(PlayerInfo[playerid][pCarLic] == 0) return SCM(playerid, COLOR_LGREEN, "Eroare: Ai nevoie de o licenta de condus pentru a putea munci la acest job!");
			CarAngle = 0.7028;
			CP[playerid] = 57;
			
			new rand = random(3);
			if(rand == 1) SetPlayerCheckpointEx(playerid, 830.0479, -611.8955, 16.3432, 5.0);
			else if(rand == 2) SetPlayerCheckpointEx(playerid, 820.7677, -612.4786, 16.3432, 5.0);
			else if(rand == 3) SetPlayerCheckpointEx(playerid, 790.9538, -612.2801, 16.3432, 5.0);
			else SetPlayerCheckpointEx(playerid, 830.0479, -611.8955, 16.3432, 5.0);
			
			PlayerTextDrawSetString(playerid, InfosTD, "Du-te la punctul ~r~rosu~w~~h~ pentru a incarca coletele!");
			SetTimerEx("HideTextdraw", 8000, 0, "%d", playerid);
			PlayerTextDrawShow(playerid, InfosTD);	
		}

	SetPVarInt(playerid, "Pressed", 0);
	SetPVarInt(playerid, "Trees", 0);
	SetPVarInt(playerid, "JobStep", 0);				
	SetPVarInt(playerid, "InHand", 0);				
	
    MoneyEarned[playerid] = 0;
	CurseFacute[playerid] = 0;
	if(PlayerInfo[playerid][pShowJob] == 0 && PlayerInfo[playerid][pJob] != 5 && PlayerInfo[playerid][pLevel] < 3) SCM(playerid, COLOR_YELLOW, "Daca doresti sa vezi mai multe informatii folositoare de la job, o poti face prin comanda (/hud > Informatii job).");
	new skill = GetPlayerSkill(playerid);
    PutPlayerInVehicleEx(playerid, JobVehicle[playerid], 0);
    JobWorking[playerid] = 1;
	if(PlayerInfo[playerid][pJob] != 2) UpdateJobStats(playerid);
    Gas[JobVehicle[playerid]] = 100;
	WorkingTime[playerid] = 0;
 	if(PlayerInfo[playerid][pJob] == 11) DisableRemoteVehicleCollisions(playerid, 1);
	SetPlayerVirtualWorld(playerid, 0);

	new engine,lights,alarm,doors,bonnet,boot,objective;
	vehEngine[JobVehicle[playerid]] = 1;
	GetVehicleParamsEx(JobVehicle[playerid],engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(JobVehicle[playerid],VEHICLE_PARAMS_ON,lights,alarm,doors,bonnet,boot,objective);	
	return 1;
}
function JobTimeDeelay(playerid) {
	new string[64];
	format(string, sizeof(string), "Please wait %d seconds!", JobDeelay[playerid][PlayerInfo[playerid][pJob]]);
	SCM(playerid, COLOR_LGREEN, string);
	return 1;
}
function JobProgress(playerid) {
	new string[128];	
	if(GetPlayerSkill(playerid) == 5) format(string, sizeof(string), "Progres job %s: %d (skill maxim)", JobInfo[PlayerInfo[playerid][pJob]][jName], JobPoints(playerid));
	else format(string, sizeof(string), "Progres job %s: %d/%d (%d necesare pentru urmatorul skill)", JobInfo[PlayerInfo[playerid][pJob]][jName], JobPoints(playerid), GetNeedPoints(playerid, PlayerInfo[playerid][pJob]), GetNeedPoints(playerid, PlayerInfo[playerid][pJob])-JobPoints(playerid));
	SCM(playerid, COLOR_YELLOW, string);
	return 1;
}
function GetPlayerSkill(playerid) {
    new level;
	switch(PlayerInfo[playerid][pJob]) {
	    case 1: {
			level = PlayerInfo[playerid][pFarmerSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 2: {
		    level = PlayerInfo[playerid][pTruckerSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 3: {
		    level = PlayerInfo[playerid][pJackerSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 4: {
		    level = PlayerInfo[playerid][pMatSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 5: {
		    level = PlayerInfo[playerid][pDrugsSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 6: {
		    level = PlayerInfo[playerid][pMechSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 8: {
		    level = PlayerInfo[playerid][pPizzaSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }	
	    case 9: {
		    level = PlayerInfo[playerid][pCurierSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }	
	    case 10: {
		    level = PlayerInfo[playerid][pFishSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }					
	}
	return level;
}

function GetPlayerSkill2(playerid, id) {
    new level;
	switch(id) {
	    case 1: {
			level = PlayerInfo[playerid][pFarmerSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 2: {
		    level = PlayerInfo[playerid][pTruckerSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 3: {
		    level = PlayerInfo[playerid][pJackerSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 4: {
		    level = PlayerInfo[playerid][pMatSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 5: {
		    level = PlayerInfo[playerid][pDrugsSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 6: {
		    level = PlayerInfo[playerid][pMechSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }
	    case 8: {
		    level = PlayerInfo[playerid][pPizzaSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }	
	    case 9: {
		    level = PlayerInfo[playerid][pCurierSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
	    }	
	    case 10: {
		    level = PlayerInfo[playerid][pFishSkill];
			if(level >= 0 && level < 30) level = 1;
			else if(level >= 30 && level < 90) level = 2;
			else if(level >= 90 && level < 210) level = 3;
			else if(level >= 210 && level < 450) level = 4;
			else if(level >= 450) level = 5;
		}
	}
	return level;
}

function GetNeedPoints(playerid, jid) {
	new x;
	new skill = GetPlayerSkill2(playerid, jid);
	if(skill == 1) x = 30;
	else if(skill == 2) x = 90;
	else if(skill == 3) x = 210;
	else if(skill == 4) x = 450;
	return x;
}

function GetNeedPoints4(playerid, jid) {
	new x;
	new skill = GetPlayerSkill2(playerid, jid);
	if(skill == 1) x = 30;
	else if(skill == 2) x = 90;
	else if(skill == 3) x = 210;
	else if(skill == 4) x = 450;
	return x;
}

// here 
function GiveJobSalary(playerid) {
	// var
	new string[128], skill = GetPlayerSkill(playerid), money, bonus;
	
	// ++
	switch(PlayerInfo[playerid][pJob]) {
		case 1: money = skill*100*KG[playerid] + 18000 + random(1000);
		case 2: {
			new category = GetPVarInt(playerid, "Category");
			switch(category) {
				case 0: money = skill*3000 + 28000 + random(1000);
				case 1: money = skill*3000 + 28000 + random(2000);
				case 2: money = skill*3000 + 28000 + random(3000);
				case 3: money = skill*3000 + 28000 + random(4000);
				case 4: money = skill*3000 + 28000 + random(5000);				
				case 5: money = skill*3000 + 28000 + random(6000);
			}
		}
		case 3: money = skill*5000 + 30000 + random(1000);
		case 4: money = skill*1000 + 25000 + random(1000);
		case 5: money = skill*1500 + 25000 + random(1000);
		//case 6: money = 10000 + random(200) + GetPlayerSkill(playerid)*4000;
		case 9: money = skill*1000 + 10000 + random(10000);
		case 10: money = skill*2000 + 28000 + random(1000);
	}
	if(WorkingTime[playerid] < 60 && PlayerInfo[playerid][pJob] != 13) money -= 10000; 
	//if(PlayerInfo[playerid][pPremiumAccount] == 1) bonus = money/2;
	
	// info
	JobDeelay[playerid][PlayerInfo[playerid][pJob]] = 180;
	
	MoneyEarned[playerid] += money+bonus;
	CurseFacute[playerid] ++;
	format(string, sizeof(string), "%s a primit $%s pentru munca efectuata la job-ul %s.", GetName(playerid), FormatNumber(money+bonus), JobInfo[PlayerInfo[playerid][pJob]][jName]);
	InsertLog(playerid, string, LOG_MONEY);		
			
	format(string, sizeof(string), "Castig: $%s", FormatNumber(money));
	SCM(playerid, COLOR_GRAD2, string);
	format(string, sizeof(string), "Castig total: $%s", FormatNumber(money+bonus));
	SCM(playerid, COLOR_GRAD2, string);	
	format(string, sizeof(string), "Timp job: %s", CalculeazaTimp2(WorkingTime[playerid]));
	SCM(playerid, COLOR_GRAD2, string);		
	
	GivePlayerCash(playerid, money+bonus);
	Update(playerid, pCashx);
	
	WorkingTime[playerid] = 0;
	if(JobPoints(playerid) == GetNeedPoints4(playerid, PlayerInfo[playerid][pJob])) {
		format(string, sizeof(string), "* Felicitari! Noul tau skill la acest job este %d.", GetPlayerSkill(playerid));
		SCM(playerid, COLOR_YELLOW, string);
	}	
	else {
		if(togjob[playerid] == 0) JobProgress(playerid);	
	}	
	if(GetPlayerSkill(playerid) == 5) finishAchievement(playerid, 0);	
	UpdateProgress(playerid, 1);
	return 1;
}

function UpdateProgress(playerid, bar) {
	if(PlayerInfo[playerid][pShowProgress][bar] == 0) return 1;
	new string[64];
	switch(bar) {
		case 0: {
			format(string, sizeof(string), "Level: %d-%d (%d/%d RP)", PlayerInfo[playerid][pLevel], PlayerInfo[playerid][pLevel]+1, PlayerInfo[playerid][pExp], PlayerInfo[playerid][pLevel]*levelexp);
			PlayerTextDrawSetString(playerid, HudTD[bar], string);
			PlayerTextDrawShow(playerid, HudTD[bar]);
			SetPlayerProgressBarMaxValue(playerid, HudProgress[playerid][bar], PlayerInfo[playerid][pLevel]*levelexp);
			SetPlayerProgressBarValue(playerid, HudProgress[playerid][bar], PlayerInfo[playerid][pExp]);
			SetPlayerProgressBarColor(playerid, HudProgress[playerid][bar], GetHudColor3(PlayerInfo[playerid][pShowProgress][0]));	
		}
		case 1: {
			if(PlayerInfo[playerid][pJob] != 0) {
				new job = PlayerInfo[playerid][pJob]; 
				if(GetPlayerSkill(playerid) == 5) format(string, sizeof(string), "Job %s: Skill maxim (%d)", JobInfo[job][jName], GetPlayerSkill(playerid), JobPoints(playerid), GetNeedPoints(playerid, job));
				else format(string, sizeof(string), "Job %s: %d-%d (%d/%d)", JobInfo[job][jName], GetPlayerSkill(playerid), GetPlayerSkill(playerid)+1, JobPoints(playerid), GetNeedPoints(playerid, job));
				PlayerTextDrawSetString(playerid, HudTD[bar], string);
				PlayerTextDrawShow(playerid, HudTD[bar]);
				
				if(GetPlayerSkill(playerid) == 5) SetPlayerProgressBarMaxValue(playerid, HudProgress[playerid][bar], 0);
				else SetPlayerProgressBarMaxValue(playerid, HudProgress[playerid][bar], GetNeedPoints(playerid, job));
				
				SetPlayerProgressBarValue(playerid, HudProgress[playerid][bar], JobPoints(playerid));
				SetPlayerProgressBarColor(playerid, HudProgress[playerid][bar], GetHudColor3(PlayerInfo[playerid][pShowProgress][1]));	
			}
			else return DestroyProgress(playerid, bar);
		}
	}
	ShowPlayerProgressBar(playerid, HudProgress[playerid][bar]);
	return 1;
}

function DestroyProgress(playerid, bar) {
	HidePlayerProgressBar(playerid, HudProgress[playerid][bar]);
	PlayerTextDrawHide(playerid, HudTD[bar]);
	return 1;
}
cmd:skills(playerid, params[], help) {
	new string[180], needp[10], skill;
	new szDialog[600];
    if(IsPlayerConnected(playerid))
    {
		// job 1
        skill = GetPlayerSkill2(playerid, 1);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 1));
		else needp = "-";
		format(string, sizeof(string), "* Farmer: %d (%d/%s)\n", GetPlayerSkill2(playerid, 1), PlayerInfo[playerid][pFarmerSkill], needp);
		strcat(szDialog, string);

		// job 2
		skill = GetPlayerSkill2(playerid, 2);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 2));
		else needp = "-";
		format(string, sizeof(string), "* Trucker: %d (%d/%s)\n", GetPlayerSkill2(playerid, 2), PlayerInfo[playerid][pTruckerSkill], needp);
		strcat(szDialog, string);

		// job 4
		skill = GetPlayerSkill2(playerid, 3);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 4));
		else needp = "-";
		format(string, sizeof(string), "* Car Jacker: %d (%d/%s)\n", GetPlayerSkill2(playerid, 4), PlayerInfo[playerid][pJackerSkill], needp);
		strcat(szDialog, string);

		// job 5
		skill = GetPlayerSkill2(playerid, 6);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 5));
		else needp = "-";
		format(string, sizeof(string), "* Arms Dealer: %d (%d/%s)\n", GetPlayerSkill2(playerid, 5), PlayerInfo[playerid][pMatSkill], needp);
		strcat(szDialog, string);
/*
		// job 6
		skill = GetPlayerSkill2(playerid, 6);
		if(skill == 1) format(needp, 10, "50");
		else if(skill == 2) format(needp, 10, "100");
		else if(skill == 3) format(needp, 10, "200");
		else if(skill == 4) format(needp, 10, "400");
		else if(skill == 5) format(needp, 10, "-");
		format(string, sizeof(string), "* Drugs Dealer: %d (%d/%s)\n", GetPlayerSkill2(playerid, 6), PlayerInfo[playerid][pDrugsSkill], needp);
		SCM(playerid, -1, string);*/

		// job 7
		skill = GetPlayerSkill2(playerid, 7);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 7));
		else needp = "-";
		format(string, sizeof(string), "* Mechanic: %d (%d/%s)\n", GetPlayerSkill2(playerid, 7), PlayerInfo[playerid][pMechSkill], needp);
		strcat(szDialog, string);

		// job 9
		skill = GetPlayerSkill2(playerid, 8);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 9));
		else needp = "-";
		format(string, sizeof(string), "* Pizza Boy: %d (%d/%s)\n", GetPlayerSkill2(playerid, 9), PlayerInfo[playerid][pPizzaSkill], needp);
		strcat(szDialog, string);
		// job 10
		skill = GetPlayerSkill2(playerid, 9);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 10));
		else needp = "-";
		format(string, sizeof(string), "* Curier: %d (%d/%s)\n", GetPlayerSkill2(playerid, 10), PlayerInfo[playerid][pCurierSkill], needp);
		strcat(szDialog, string);	
		
		// job 11
		skill = GetPlayerSkill2(playerid, 10);
		if(skill < 5) format(needp, 10, "%d", GetNeedPoints(playerid, 11));
		else needp = "-";
		format(string, sizeof(string), "* Fisher: %d (%d/%s)\n", GetPlayerSkill2(playerid, 11), PlayerInfo[playerid][pFishSkill], needp);
		strcat(szDialog, string);
		
		
		ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, "Skills", szDialog, "Ok", "");
    }
    return 1;
}
cmd::picklock(playerid, params[]) {
    if(JobWorking[playerid] == 0 || PlayerInfo[playerid][pJob] != 4) return 1;
    if(GetPlayerSkill(playerid) != 4) return SCM(playerid, COLOR_LGREEN, "Eroare: Ai nevoie de skill 4 pentru a folosi aceasta comanda!");
	if(IsPlayerInAnyVehicle(playerid)) return 1;
	new idd, car;
	car = GetClosestVehicle(playerid);
	idd = FindSpawnID(car);
	if(CarInfo[idd][Spawned] == 0) return SCM(playerid, COLOR_GREY, "Vehicul invalid!");
	if(CarInfo[idd][cLock] == 0) return SCM(playerid, COLOR_GREY, "Acest vehicul nu este inchis!");
	if(CarInfo[idd][Userid] == PlayerInfo[playerid][pSQLID]) return SCM(playerid, COLOR_LGREEN, "Eroare: Nu iti poti fura propria masina!");
	if(IsAFLYCar(car) || IsABOATCar(car)) return SCM(playerid, COLOR_LGREEN, "Eroare: Nu poti folosi aceasta comanda pe un avion/barca/elicopter!");
	
	new engine,lights,alarm,doors,bonnet,boot,objective;
	CarInfo[idd][cLock] = 0;
	GetVehicleParamsEx(CarInfo[idd][Spawned],engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(CarInfo[idd][Spawned],engine,lights,alarm,0,bonnet,boot,objective);
	new string[128];
	format(string, sizeof(string), "~w~%s~n~~g~Deschis",aVehicleNames[CarInfo[idd][cModel]-400]);
	GameTextForPlayer(playerid, string, 5000, 4);
	mysql_format(SQL, string, sizeof(string), "UPDATE cars SET Lockk='%d' WHERE ID=%d", CarInfo[idd][cLock], idd);
	mysql_tquery(SQL, string, "", "");
	PlayerInfo[playerid][pWantedLevel] += 1;
	SetPlayerWantedLevel(playerid, PlayerInfo[playerid][pWantedLevel]);
	SetPlayerCriminal(playerid,255, "car jacker");
    WantedTime[playerid] = 0;
    Update(playerid,pWantedLevelx);
	ShowWanted[playerid] = 1;	
	return 1;
}
function UpdateJobStats(playerid) {
	new i = playerid, string[300];
	if(JobWorking[i] == 1 && PlayerInfo[i][pShowJob] == 1 && PlayerInfo[i][pShowHud] == 0) {
		switch(PlayerInfo[i][pJob]) {
			case 1: {
				if(GetPlayerSkill(playerid) == 5) {
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Ai skill maxim la acest job.~n~Mai trebuie sa muncesti inca %d secunde.~n~Muncitori la datorie: %d.",
					GetPlayerSkill(i), PlayerInfo[i][pFarmerSkill], JobSeconds[i], GetJobWorkers(1));
				}
				else {
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Pentru a avansa, ai nevoie de inca %d puncte.~n~Mai trebuie sa muncesti inca %d secunde.~n~Muncitori la datorie: %d.",
					GetPlayerSkill(i), PlayerInfo[i][pFarmerSkill], GetNeedPoints(i, PlayerInfo[i][pJob])-PlayerInfo[i][pFarmerSkill], JobSeconds[i], GetJobWorkers(1));
				}	
				PlayerTextDrawSetString(i, JobTD, string);
				PlayerTextDrawShow(i, JobTD);
			}
			case 2: {				
				
				new szZone[180], routes = GetPVarInt(playerid, "Routes"), result[64];
				switch(routes) {
					case 0: result = "Rent (LS)";
					case 1: result = "Aeroport (LS)";
					case 2: result = "Ocean Docks (LS)";
					case 3: result = "Burger Shot (LS)";
					case 4: result = "Aeroport(LV)";
					case 5: result = "Military Base (LV)";
					case 6: result = "Amazon Deposit (LV)";
					case 7: result = "Linden Side (LV)";	
					case 8: result = "Aeroport (SF)";
					case 9: result = "Docks (SF)";
					case 10: result = "West (SF)";
					case 11: result = "Angel Pine (SF)";			
				}
				GetPlayer3DZone2(CheckpointPos[playerid][0], CheckpointPos[playerid][1], CheckpointPos[playerid][2], szZone, sizeof(szZone));
				if(GetPlayerSkill(playerid) == 5) {
					format(string, sizeof(string), "Locatie aleasa: %s (%s)~n~Ai skill %d si ai muncit de %d ori.~n~Ai skill maxim la acest job.~n~Curse facute %d, bani castigati $%s.~n~Muncitori la datorie: %d",
					szZone, result, GetPlayerSkill(i), PlayerInfo[i][pTruckerSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(1));								
				}
				else {				
					format(string, sizeof(string), "Locatie aleasa: %s (%s)~n~Ai skill %d si ai muncit de %d ori.~n~Pentru a avansa, ai nevoie de inca %d puncte.~n~Curse facute %d, bani castigati $%s.~n~Muncitori la datorie: %d",
					szZone, result, GetPlayerSkill(i), PlayerInfo[i][pTruckerSkill], GetNeedPoints(i, PlayerInfo[i][pJob])-PlayerInfo[i][pTruckerSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(1));
				}
				PlayerTextDrawSetString(i, JobTD, string);
				PlayerTextDrawShow(i, JobTD);
			}						
			case 3: {
				if(GetPlayerSkill(playerid) == 5) {
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Ai skill maxim la acest job.~n~Ai dus %d inghetate si ai castigat in total $%s.~n~Muncitori la datorie: %d",
					GetPlayerSkill(i), PlayerInfo[i][pJackerSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(4));
				}
				else {				
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Pentru a avansa, ai nevoie de inca %d puncte.~n~Ai dus %d inghetate si ai castigat in total $%s.~n~Muncitori la datorie: %d",
					GetPlayerSkill(i), PlayerInfo[i][pJackerSkill], GetNeedPoints(i, PlayerInfo[i][pJob])-PlayerInfo[i][pJackerSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(4));
				}
				PlayerTextDrawSetString(i, JobTD, string);
				PlayerTextDrawShow(i, JobTD);
			}
			case 8: {
				if(GetPlayerSkill(playerid) == 5) {
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Ai skill maxim la acest job.~n~Ai dus %d cutii cu pizza si ai castigat in total $%s.~n~Muncitori la datorie: %d",
					GetPlayerSkill(i), PlayerInfo[i][pPizzaSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(9));
				}
				else {				
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Pentru a avansa, ai nevoie de inca %d puncte.~n~Ai dus %d cutii cu pizza si ai castigat in total $%s.~n~Muncitori la datorie: %d",
					GetPlayerSkill(i), PlayerInfo[i][pPizzaSkill], GetNeedPoints(i, PlayerInfo[i][pJob])-PlayerInfo[i][pPizzaSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(9));
				}
				PlayerTextDrawSetString(i, JobTD, string);
				PlayerTextDrawShow(i, JobTD);
			}	
			case 9: {
				if(GetPlayerSkill(playerid) == 5) {
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Ai skill maxim la acest job.~n~Ai facut %d drumuri si ai castigat in total $%s.~n~Muncitori la datorie: %d",
					GetPlayerSkill(i), PlayerInfo[i][pCurierSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(10));
				}
				else {				
					format(string, sizeof(string), "Ai skill %d si ai muncit de %d ori.~n~Pentru a avansa, ai nevoie de inca %d puncte.~n~Ai facut %d drumuri si ai castigat in total $%s.~n~Muncitori la datorie: %d",
					GetPlayerSkill(i), PlayerInfo[i][pCurierSkill], GetNeedPoints(i, PlayerInfo[i][pJob])-PlayerInfo[i][pCurierSkill], CurseFacute[i], FormatNumber(MoneyEarned[i]), GetJobWorkers(10));
				}
				PlayerTextDrawSetString(i, JobTD, string);
				PlayerTextDrawShow(i, JobTD);
			}				
		}
	}
	return 1;
}
function Fish(playerid) {
	new x, string[180];
	if(!IsPlayerConnected(playerid)) return 1;
	if(PlayerInfo[playerid][pJob] == 11) {
	    RemovePlayerAttachedObject(playerid, 0);
		x = 3000 + random(1000) + GetPlayerSkill(playerid)*500;
		if(PlayerInfo[playerid][pPremiumAccount] == 1) x += x/2;
		new rar = random(500);
		if(rar >= 490 && rar < 495) {
			x += 3000 + random(5000);
			format(string, sizeof(string), "Ai prins un peste rar care valoreaza $%s!", FormatNumber(x));
			SCM(playerid, COLOR_YELLOW, string);
			SCM(playerid, -1, "Pentru a vinde pestele, trebuie sa mergi intr-un 24/7. (/gps)");			
			format(string, sizeof(string), "* %s a prins un peste rar ce valoreaza $%s.", GetName(playerid), FormatNumber(x));
			NearMessage(playerid, COLOR_YELLOW, string);						
		}
		else if(rar >= 495) {
			format(string, sizeof(string), "Ai prins un peste foarte rar!", FormatNumber(x));
			SCM(playerid, COLOR_BLUE, string);
			SCM(playerid, -1, "Pentru a vinde pestele, trebuie sa mergi intr-un 24/7. (/gps)");					
			format(string, sizeof(string), "* %s a prins un peste foarte rar care valoreaza %s.", GetName(playerid), FormatNumber(x));
			NearMessage(playerid, COLOR_YELLOW, string);	

		}
		else {
			format(string, sizeof(string), "Ai prins un peste normal care valoreaza $%s!", FormatNumber(x));
			SCM(playerid, COLOR_DARKPINK, string);	
			SCM(playerid, -1, "Pentru a vinde pestele, trebuie sa mergi intr-un 24/7. (/gps)");
			format(string, sizeof(string), "* %s a prins un peste normal ce valoreaza $%s.", GetName(playerid), FormatNumber(x));
			NearMessage(playerid, COLOR_YELLOW, string);				
		}
		
		HaveFish[playerid] = x;
		StartFish[playerid] = 0;
		TogglePlayerControllable(playerid, 1);
		Freezed[playerid] = 0;
	}
	return 1;
}
function JobPoints(playerid) {
    new level;
	switch(PlayerInfo[playerid][pJob]) {
	    case 1: level = PlayerInfo[playerid][pFarmerSkill];
	    case 2: level = PlayerInfo[playerid][pTruckerSkill];
	    case 3: level = PlayerInfo[playerid][pJackerSkill];
	    case 4: level = PlayerInfo[playerid][pMatSkill];
	    case 5: level = PlayerInfo[playerid][pDrugsSkill];
	    case 6: level = PlayerInfo[playerid][pMechSkill];
	    case 8: level = PlayerInfo[playerid][pPizzaSkill];
	    case 9: level = PlayerInfo[playerid][pCurierSkill];
	    case 10: level = PlayerInfo[playerid][pFishSkill];	
	}
	return level;
}