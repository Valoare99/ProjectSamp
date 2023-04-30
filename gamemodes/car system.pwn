CMD:buycar(playerid, params[]) {
	if(PlayerInfo[playerid][pLevel] < 3) return Message(playerid,COLOR_GREY,"Ai nevoie de nivel 3 pentru a iti cumpara o masina.","You need level 3 to buy a car.");
	if(!IsPlayerInRangeOfPoint(playerid, 5.0,DEALER_SHIP_POS) && !IsPlayerInRangeOfPoint(playerid, 5.0,DEALER_SHIP_POS2)) return Message(playerid,COLOR_GREY,"Nu esti la Dealer Ship.","You are not to Dealer Ship.");
	if(playerfind[playerid] != -1 || CP[playerid] != -1) if(GetPVarInt(playerid,"InDealerShip")) return Message(playerid,COLOR_GREY,"Nu poti folosii aceasta comanda deoarece ai un checkpoint activ. Foloseste /killcp.","You can't use this command because you have activ checkpoint. Use /killcp.");
	if(IsPlayerInAnyVehicle(playerid)) return Message(playerid,COLOR_GREY,"Nu poti folosii aceasta comanda dintr-un vehicul.","You can't use this command in vehicle.");
	new gString[150];
	format(gString,150,"Model:_%s~n~Price:_$%s_(-%d%%)~n~Stock:_%d~n~Top_Speed:_%d_km/h",
		NumeVehicul[DealerInfo[DealerPos[playerid]][dsModel]-400],fnr(calculate_percentage(DealerInfo[DealerPos[playerid]][dsPrice],DEALER_SHIP_DISCOUNT)),DEALER_SHIP_DISCOUNT,DealerInfo[DealerPos[playerid]][dsStock],DealerInfo[DealerPos[playerid]][dsSpeed]);
	TextDrawSetString(DealerTD[2], gString);
	PlayerTextDrawSetPreviewModel(playerid,DealerPTD, DealerInfo[DealerPos[playerid]][dsModel]);
	PlayerTextDrawSetPreviewRot(playerid,DealerPTD, 0.000000, 0.000000, 85.000000, 1.000000);
	PlayerTextDrawShow(playerid, DealerPTD);
	TogglePlayerControllable(playerid, 0);
	DealerPosCar[playerid] = 85;
	for(new i = 0; i<8;i++) TextDrawShowForPlayer(playerid, DealerTD[i]);
	if(!PlayerInfo[playerid][pAdmin]) TextDrawHideForPlayer(playerid, DealerTD[3]);
	SelectTextDraw(playerid, 0xDE1414FF);
	SetPlayerCameraPos(playerid, -1650.91, 1213.05, 11.20);
	SetPlayerCameraLookAt(playerid, -1660.9762,1213.1875,6.84);
	new Float: zet;
	if(DealerInfo[DealerPos[playerid]][dsModel] == 509 || DealerInfo[DealerPos[playerid]][dsModel] == 510 || DealerInfo[DealerPos[playerid]][dsModel] == 481 || DealerInfo[DealerPos[playerid]][dsModel] == 462) zet = 6.6000; else zet = 7.0000;
	DealerCar[playerid] = CreateVehicle(DealerInfo[DealerPos[playerid]][dsModel], -1662.0481, 1213.4545, zet, DealerPosCar[playerid]+(25*11), 1, 1, -1);
	SetPlayerVirtualWorld(playerid, PlayerInfo[playerid][pSQLID]);
	SetVehicleVirtualWorld(DealerCar[playerid], PlayerInfo[playerid][pSQLID]);
	SetPVarInt(playerid, "InDealerShip", 1);
	SetPlayerPosEx(playerid, -1677.5022,1209.2479,21.1487);
	if(markplayer[playerid] == 1) {
		Message(playerid,COLOR_GREY,"Punctul salvat din /mark a fost sters.","Your /mark was deleted.");
		markplayer[playerid] = 0;
	}
	GetPlayerPos(playerid,markx[playerid], marky[playerid], markz[playerid]);
	return 1;
}
CMD:sellcar(playerid, params[]) {
	if(!IsPlayerInRangeOfPoint(playerid, 15.0,DEALER_SHIP_POS) && !IsPlayerInRangeOfPoint(playerid, 5.0,DEALER_SHIP_POS2)) return Message(playerid,COLOR_GREY,"Nu esti la Dealer Ship.","You are not to Dealer Ship.");
	if(!IsPlayerInAnyVehicle(playerid)) return Message(playerid,COLOR_GREY, "Nu esti intr-un vehicul.","You are not in your vehicle.");
    new veh = GetPlayerVehicleID(playerid);
    new db = VehicleDB[veh];
    if(CarInfo[db][cOwned] != PlayerInfo[playerid][pSQLID]) return Message(playerid,COLOR_GREY, "Acesta nu este vehiculul tau.","This is not your car.");
    if(CarInfo[db][cinmarket]) return Message(playerid,COLOR_GREY,"Nu poti vinde masina daca acasta este la vanzare in market.","You can't sell car because its already selling in market.");
    new dsid = 0;
    for(new i = 0; i <= dscar; i ++) {
    	if(DealerInfo[i][dsModel] == CarInfo[db][cModel]) {
    		dsid = i;
    		break;
    	}
    }
    if(!dsid) return Message(playerid,COLOR_GREY,"Aceasta masina nu se poate vinde la dealer ship.","This vehicle cannot sell in dealer ship.");
    new cash = floatround(floatmul(DealerInfo[dsid][dsPrice], 0.70));
    SetPVarInt(playerid, "DSreciver", cash);
    SetPVarInt(playerid, "Dsdb", db);
    new gString[200];
    format(gString,200,"You want to sell this car off 70%% dealer ship price?\nModel: %s\nDealerShip price: $%s\nYou will be recived $%s for this car.\nSell?",NumeVehicul[CarInfo[db][cModel]-400],fnr(DealerInfo[dsid][dsPrice]),fnr(cash));
    ShowPlayerDialogEx(playerid,DIALOG_SELLCAR,DIALOG_STYLE_MSGBOX,"Sell Car:",gString,"Ok","Close");
	return 1;
}
CMD:insertds(playerid, params[]) {
	if(ADM(playerid,7) < 7) return 1;
	new car,carspeed,carprice,stockcar;
	if(sscanf(params, "iiii",car,carprice,carspeed,stockcar)) return scm(playerid, COLOR_GREY, "Syntax: {FFFFFF}/insertds <Vehicle Model> <Vehicle Price> <Vehicle Speed> <Stock>");
	if(car < 400 || car >611) return scm(playerid,COLOR_GREY,"INVALID MODEL!");
	if(carspeed > 210) return scm(playerid,COLOR_GREY,"INVALID SPEED!");
	if(carprice > 100000000) return scm(playerid,COLOR_GREY,"INVALID PRICE!");
	if(stockcar > 100) return scm(playerid,COLOR_GREY,"INVALID STOCK!");
	if(dscar >= MAX_DEALER_VEHICLE) return Message(playerid,COLOR_GREY,"Sunt prea multe masini in dealership.","There are to many cars in dealership.");
	new gString[200];
	dscar++;
	DealerInfo[dscar][dsID] 				= dscar;
	DealerInfo[dscar][dsModel]              = car;
	DealerInfo[dscar][dsPrice]              = carprice;
	DealerInfo[dscar][dsSpeed]         		= carspeed;
	DealerInfo[dscar][dsStock]          	= stockcar;
	mysql_format(handle,gString,100,"INSERT INTO dscars (Model,Price,Speed,Stock) VALUES(%d,%d,%d,%d)",car,carprice,carspeed,stockcar);
	mysql_tquery(handle,gString, "", "");
	SCMA(COLOR_WHITE,"({ffff00}Admin Info{ffffff}) Administratorul %s a adaugat vehiculul %s in DealerShip. [price:$%s,speed:%d,stock:%d]","({ffff00}Admin Info{ffffff}) Administratorul %s add vehicle %s in DealerShip. [price:$%s,speed:%d,stock:%d]",
		GetName(playerid),NumeVehicul[car-400],fnr(carprice),carspeed,stockcar);
	format(gString,200,"%s[sql:%d] add new car in dealership: vehicle: %s, speed: %d, stock: %d, price: %s",PlayerInfo[playerid][pUsername],PlayerInfo[playerid][pSQLID],NumeVehicul[car-400],carspeed,stockcar,fnr(carprice));
	log_admin(PlayerInfo[playerid][pUsername],"",gString);
	log_server(PlayerInfo[playerid][pUsername],"",gString);
	return 1;
}