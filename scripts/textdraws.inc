new 
	Text: TradeTD[21], Text: PinTDs[15], PinStep[MAX_PLAYERS], InputtText[MAX_PLAYERS][10], Text:ServerStatusBox, Text:ServerStatusBar,Text:ShopTD[5],
	Text:Time, Text:Jailtime[MAX_PLAYERS], Text:SafeTD[1], Text:HiddTD[7];
new 
	PlayerText: TradePTD[7], PlayerText: TradeIcon[10], PlayerText: TradeTitle[10],
	PlayerText: InfoDS, PlayerText: MainColor, PlayerText: SecColor, PlayerText: NextColorMain,
	PlayerText: BackColorMain, PlayerText: NextColorSec, PlayerText: BackColorSec,
	PlayerText: CarsCategory, PlayerText: BikesCategory, PlayerText: BoatsCategory, PlayerText: AirCategory,
	PlayerText: SpecialCategory, PlayerText: RotLeft, PlayerText: RotRight, PlayerText: BuyModel, PlayerText: TestModel,
	PlayerText: ExitDS, PlayerText: BackCar, PlayerText: NextCar, PlayerText:LoadingAccount[MAX_PLAYERS], PlayerText:HelpsInfo[MAX_PLAYERS],
	PlayerText: SpecTD, PlayerText:FareTD[3], PlayerText:CbugT, PlayerText: WantedTD[MAX_PLAYERS], PlayerText:RPTextdraw[3], PlayerText: FriendsTD,
	PlayerText:HiddTDs[3], PlayerText:ShopTDs[2], PlayerText:InfosTD, PlayerText: JobTD, PlayerText: ShowTD, PlayerText: Speedo, PlayerText:PlayerName[MAX_PLAYERS],
	PlayerText:ServerName, PlayerText:EventsInfo[MAX_PLAYERS], PlayerText:ReportsInfo[MAX_PLAYERS], PlayerText: GreenButton, PlayerText: RedButton, PlayerText: UndercoverTD,
	PlayerText: PinNumber[10], PlayerText: PinResult, PlayerText: FindTD, PlayerText: BGunTD[9], PlayerText: RentTD, PlayerText: CleoTD[MAX_PLAYERS][3], PlayerText: HudTD[2],
	PlayerText: PaintTD, PlayerText:PayDayText[MAX_PLAYERS] ,PlayerText: CpTDD;
	
stock LoadFunctions() {
	//TextDraws
	ShopTD[0] = TextDrawCreate(218.147888, 352.166687, "LD_BEAT:left");
	TextDrawLetterSize(ShopTD[0], 0.000000, 0.000000);
	TextDrawTextSize(ShopTD[0], 29.000000, 34.000000);
	TextDrawAlignment(ShopTD[0], 1);
	TextDrawColor(ShopTD[0], -1);
	TextDrawSetShadow(ShopTD[0], 0);
	TextDrawSetOutline(ShopTD[0], 0);
	TextDrawBackgroundColor(ShopTD[0], 255);
	TextDrawFont(ShopTD[0], 4);
	TextDrawSetProportional(ShopTD[0], 0);
	TextDrawSetShadow(ShopTD[0], 0);
	TextDrawSetSelectable(ShopTD[0], true);

	ShopTD[1] = TextDrawCreate(367.606292, 352.166625, "LD_BEAT:right");
	TextDrawLetterSize(ShopTD[1], 0.000000, 0.000000);
	TextDrawTextSize(ShopTD[1], 29.000000, 34.000000);
	TextDrawAlignment(ShopTD[1], 1);
	TextDrawColor(ShopTD[1], -1);
	TextDrawSetShadow(ShopTD[1], 0);
	TextDrawSetOutline(ShopTD[1], 0);
	TextDrawBackgroundColor(ShopTD[1], 255);
	TextDrawFont(ShopTD[1], 4);
	TextDrawSetProportional(ShopTD[1], 0);
	TextDrawSetShadow(ShopTD[1], 0);
	TextDrawSetSelectable(ShopTD[1], true);

	ShopTD[4] = TextDrawCreate(395.718414, 329.416717, "LD_BEAT:cross");
	TextDrawLetterSize(ShopTD[4], 0.000000, 0.000000);
	TextDrawTextSize(ShopTD[4], 15.000000, 17.000000);
	TextDrawAlignment(ShopTD[4], 1);
	TextDrawColor(ShopTD[4], -16777092);
	TextDrawSetShadow(ShopTD[4], 0);
	TextDrawSetOutline(ShopTD[4], 0);
	TextDrawBackgroundColor(ShopTD[4], 255);
	TextDrawFont(ShopTD[4], 4);
	TextDrawSetProportional(ShopTD[4], 0);
	TextDrawSetShadow(ShopTD[4], 0);
	TextDrawSetSelectable(ShopTD[4], true);

	Time = TextDrawCreate(578.623962, 4.666653, "~h~31/31/2017~n~20:00");
	TextDrawLetterSize(Time, 0.371288, 1.961666);
	TextDrawAlignment(Time, 2);
	TextDrawColor(Time, -1);
	TextDrawSetShadow(Time, 0);
	TextDrawSetOutline(Time, 1);
	TextDrawBackgroundColor(Time, 255);
	TextDrawFont(Time, 3);
	TextDrawSetProportional(Time, 1);
	
	ServerStatusBar = TextDrawCreate(11.714534, 425.833343, "Accounts: ~y~1,000,000~h~~w~ / Newest Account: ~y~Eveeeeeee~h~~w~ / Most Players Online: ~y~1000~h~~w~ (10.10.1999 20:100)");
	TextDrawLetterSize(ServerStatusBar, 0.253221, 1.687500);
	TextDrawAlignment(ServerStatusBar, 1);
	TextDrawColor(ServerStatusBar, -1);
	TextDrawSetShadow(ServerStatusBar, 0);
	TextDrawSetOutline(ServerStatusBar, 1);
	TextDrawBackgroundColor(ServerStatusBar, 51);
	TextDrawFont(ServerStatusBar, 1);
	TextDrawSetProportional(ServerStatusBar, 1);

	ServerStatusBox = TextDrawCreate(-1.279645, 427.333435, "usebox");
	TextDrawLetterSize(ServerStatusBox, -0.238945, 1.674348);
	TextDrawTextSize(ServerStatusBox, 642.685913, -0.583333);
	TextDrawAlignment(ServerStatusBox, 1);
	TextDrawColor(ServerStatusBox, 0);
	TextDrawUseBox(ServerStatusBox, true);
	TextDrawBoxColor(ServerStatusBox, 255);
	TextDrawSetShadow(ServerStatusBox, 0);
	TextDrawSetOutline(ServerStatusBox, 0);
	TextDrawBackgroundColor(ServerStatusBox, 255);
	TextDrawFont(ServerStatusBox, 0);
	
	SafeTD[0] = TextDrawCreate(312.333160, 2.918390, "safe-zone");
	TextDrawLetterSize(SafeTD[0], 0.382999, 1.475554);
	TextDrawAlignment(SafeTD[0], 2);
	TextDrawColor(SafeTD[0], -1);
	TextDrawSetShadow(SafeTD[0], 0);
	TextDrawSetOutline(SafeTD[0], 1);
	TextDrawBackgroundColor(SafeTD[0], 68);
	TextDrawFont(SafeTD[0], 3);
	TextDrawSetProportional(SafeTD[0], 1);
	TextDrawSetShadow(SafeTD[0], 0);

	HiddTD[0] = TextDrawCreate(244.385131, 354.499908, "LD_BEAT:left");
	TextDrawLetterSize(HiddTD[0], 0.000000, 0.000000);
	TextDrawTextSize(HiddTD[0], 14.000000, 19.000000);
	TextDrawAlignment(HiddTD[0], 1);
	TextDrawColor(HiddTD[0], -1);
	TextDrawSetShadow(HiddTD[0], 0);
	TextDrawSetOutline(HiddTD[0], 0);
	TextDrawBackgroundColor(HiddTD[0], 255);
	TextDrawFont(HiddTD[0], 4);
	TextDrawSetProportional(HiddTD[0], 0);
	TextDrawSetShadow(HiddTD[0], 0);
	TextDrawSetSelectable(HiddTD[0], true);

	HiddTD[1] = TextDrawCreate(380.724884, 353.333251, "LD_BEAT:right");
	TextDrawLetterSize(HiddTD[1], 0.000000, 0.000000);
	TextDrawTextSize(HiddTD[1], 14.000000, 19.000000);
	TextDrawAlignment(HiddTD[1], 1);
	TextDrawColor(HiddTD[1], -1);
	TextDrawSetShadow(HiddTD[1], 0);
	TextDrawSetOutline(HiddTD[1], 0);
	TextDrawBackgroundColor(HiddTD[1], 255);
	TextDrawFont(HiddTD[1], 4);
	TextDrawSetProportional(HiddTD[1], 0);
	TextDrawSetShadow(HiddTD[1], 0);
	TextDrawSetSelectable(HiddTD[1], true);

	HiddTD[2] = TextDrawCreate(409.305175, 325.333282, "LD_BEAT:cross");
	TextDrawLetterSize(HiddTD[2], 0.000000, 0.000000);
	TextDrawTextSize(HiddTD[2], 15.000000, 17.000000);
	TextDrawAlignment(HiddTD[2], 1);
	TextDrawColor(HiddTD[2], -16777092);
	TextDrawSetShadow(HiddTD[2], 0);
	TextDrawSetOutline(HiddTD[2], 0);
	TextDrawBackgroundColor(HiddTD[2], 255);
	TextDrawFont(HiddTD[2], 4);
	TextDrawSetProportional(HiddTD[2], 0);
	TextDrawSetShadow(HiddTD[2], 0);
	TextDrawSetSelectable(HiddTD[2], true);

	HiddTD[3] = TextDrawCreate(244.385040, 378.416656, "LD_BEAT:left");
	TextDrawLetterSize(HiddTD[3], 0.000000, 0.000000);
	TextDrawTextSize(HiddTD[3], 14.000000, 19.000000);
	TextDrawAlignment(HiddTD[3], 1);
	TextDrawColor(HiddTD[3], -1);
	TextDrawSetShadow(HiddTD[3], 0);
	TextDrawSetOutline(HiddTD[3], 0);
	TextDrawBackgroundColor(HiddTD[3], 255);
	TextDrawFont(HiddTD[3], 4);
	TextDrawSetProportional(HiddTD[3], 0);
	TextDrawSetShadow(HiddTD[3], 0);
	TextDrawSetSelectable(HiddTD[3], true);

	HiddTD[4] = TextDrawCreate(383.067321, 377.833221, "LD_BEAT:right");
	TextDrawLetterSize(HiddTD[4], 0.000000, 0.000000);
	TextDrawTextSize(HiddTD[4], 14.000000, 19.000000);
	TextDrawAlignment(HiddTD[4], 1);
	TextDrawColor(HiddTD[4], -1);
	TextDrawSetShadow(HiddTD[4], 0);
	TextDrawSetOutline(HiddTD[4], 0);
	TextDrawBackgroundColor(HiddTD[4], 255);
	TextDrawFont(HiddTD[4], 4);
	TextDrawSetProportional(HiddTD[4], 0);
	TextDrawSetShadow(HiddTD[4], 0);
	TextDrawSetSelectable(HiddTD[4], true);

 	
	// Dealer
	CreateDynamicObject(1557, 326.31738, -1513.20422, 34.93900,   0.00000, 0.00000, 50.39998);
	CreateDynamicObject(1557, 328.21768, -1510.92798, 34.93896,   0.00000, 0.00000, -130.02005);

    	// - - - - - - - PIN SYSTEM - - - - - - - -
	PinTDs[0] = TextDrawCreate(361.356048, 170.083251, "usebox");
	TextDrawLetterSize(PinTDs[0], 0.000000, 17.467430);
	TextDrawTextSize(PinTDs[0], 261.309173, 0.000000);
	TextDrawAlignment(PinTDs[0], 1);
	TextDrawColor(PinTDs[0], 0);
	TextDrawUseBox(PinTDs[0], true);
	TextDrawBoxColor(PinTDs[0], -2139062017);
	TextDrawSetShadow(PinTDs[0], 0);
	TextDrawSetOutline(PinTDs[0], 0);
	TextDrawFont(PinTDs[0], 0);

	PinTDs[1] = TextDrawCreate(293.420227, 208.583328, "usebox");
	TextDrawLetterSize(PinTDs[1], 0.000000, 2.560183);
	TextDrawTextSize(PinTDs[1], 270.679382, 0.000000);
	TextDrawAlignment(PinTDs[1], 1);
	TextDrawColor(PinTDs[1], 0);
	TextDrawUseBox(PinTDs[1], true);
	TextDrawBoxColor(PinTDs[1], 102);
	TextDrawSetShadow(PinTDs[1], 0);
	TextDrawSetOutline(PinTDs[1], 0);
	TextDrawFont(PinTDs[1], 0);

	PinTDs[2] = TextDrawCreate(293.014648, 239.333190, "usebox");
	TextDrawLetterSize(PinTDs[2], 0.000000, 2.513329);
	TextDrawTextSize(PinTDs[2], 270.679382, 0.000000);
	TextDrawAlignment(PinTDs[2], 1);
	TextDrawColor(PinTDs[2], 0);
	TextDrawUseBox(PinTDs[2], true);
	TextDrawBoxColor(PinTDs[2], 102);
	TextDrawSetShadow(PinTDs[2], 0);
	TextDrawSetOutline(PinTDs[2], 0);
	TextDrawFont(PinTDs[2], 0);

	PinTDs[3] = TextDrawCreate(293.077545, 270.666656, "usebox");
	TextDrawLetterSize(PinTDs[3], 0.000000, 2.419625);
	TextDrawTextSize(PinTDs[3], 270.679290, 0.000000);
	TextDrawAlignment(PinTDs[3], 1);
	TextDrawColor(PinTDs[3], 0);
	TextDrawUseBox(PinTDs[3], true);
	TextDrawBoxColor(PinTDs[3], 102);
	TextDrawSetShadow(PinTDs[3], 0);
	TextDrawSetOutline(PinTDs[3], 0);
	TextDrawFont(PinTDs[3], 0);

	PinTDs[4] = TextDrawCreate(322.657867, 208.666656, "usebox");
	TextDrawLetterSize(PinTDs[4], 0.000000, 2.607033);
	TextDrawTextSize(PinTDs[4], 300.196746, 0.000000);
	TextDrawAlignment(PinTDs[4], 1);
	TextDrawColor(PinTDs[4], 0);
	TextDrawUseBox(PinTDs[4], true);
	TextDrawBoxColor(PinTDs[4], 102);
	TextDrawSetShadow(PinTDs[4], 0);
	TextDrawSetOutline(PinTDs[4], 0);
	TextDrawFont(PinTDs[4], 0);

	PinTDs[5] = TextDrawCreate(322.721038, 239.416717, "usebox");
	TextDrawLetterSize(PinTDs[5], 0.000000, 2.513329);
	TextDrawTextSize(PinTDs[5], 300.196990, 0.000000);
	TextDrawAlignment(PinTDs[5], 1);
	TextDrawColor(PinTDs[5], 0);
	TextDrawUseBox(PinTDs[5], true);
	TextDrawBoxColor(PinTDs[5], 102);
	TextDrawSetShadow(PinTDs[5], 0);
	TextDrawSetOutline(PinTDs[5], 0);
	TextDrawFont(PinTDs[5], 0);

	PinTDs[6] = TextDrawCreate(322.315307, 270.166656, "usebox");
	TextDrawLetterSize(PinTDs[6], 0.000000, 2.513329);
	TextDrawTextSize(PinTDs[6], 300.196838, 0.000000);
	TextDrawAlignment(PinTDs[6], 1);
	TextDrawColor(PinTDs[6], 0);
	TextDrawUseBox(PinTDs[6], true);
	TextDrawBoxColor(PinTDs[6], 102);
	TextDrawSetShadow(PinTDs[6], 0);
	TextDrawSetOutline(PinTDs[6], 0);
	TextDrawFont(PinTDs[6], 0);

	PinTDs[7] = TextDrawCreate(351.832672, 208.333404, "usebox");
	TextDrawLetterSize(PinTDs[7], 0.000000, 2.607033);
	TextDrawTextSize(PinTDs[7], 329.245697, 0.000000);
	TextDrawAlignment(PinTDs[7], 1);
	TextDrawColor(PinTDs[7], 0);
	TextDrawUseBox(PinTDs[7], true);
	TextDrawBoxColor(PinTDs[7], 102);
	TextDrawSetShadow(PinTDs[7], 0);
	TextDrawSetOutline(PinTDs[7], 0);
	TextDrawFont(PinTDs[7], 0);

	PinTDs[8] = TextDrawCreate(351.427124, 239.666687, "usebox");
	TextDrawLetterSize(PinTDs[8], 0.000000, 2.513329);
	TextDrawTextSize(PinTDs[8], 329.245788, 0.000000);
	TextDrawAlignment(PinTDs[8], 1);
	TextDrawColor(PinTDs[8], 0);
	TextDrawUseBox(PinTDs[8], true);
	TextDrawBoxColor(PinTDs[8], 102);
	TextDrawSetShadow(PinTDs[8], 0);
	TextDrawSetOutline(PinTDs[8], 0);
	TextDrawFont(PinTDs[8], 0);

	PinTDs[9] = TextDrawCreate(351.021789, 270.416656, "usebox");
	TextDrawLetterSize(PinTDs[9], 0.000000, 2.466475);
	TextDrawTextSize(PinTDs[9], 329.246032, 0.000000);
	TextDrawAlignment(PinTDs[9], 1);
	TextDrawColor(PinTDs[9], 0);
	TextDrawUseBox(PinTDs[9], true);
	TextDrawBoxColor(PinTDs[9], 102);
	TextDrawSetShadow(PinTDs[9], 0);
	TextDrawSetOutline(PinTDs[9], 0);
	TextDrawFont(PinTDs[9], 0);

	PinTDs[10] = TextDrawCreate(322.036163, 300.583282, "usebox");
	TextDrawLetterSize(PinTDs[10], 0.000000, 2.419625);
	TextDrawTextSize(PinTDs[10], 300.197448, 0.000000);
	TextDrawAlignment(PinTDs[10], 1);
	TextDrawColor(PinTDs[10], 0);
	TextDrawUseBox(PinTDs[10], true);
	TextDrawBoxColor(PinTDs[10], 102);
	TextDrawSetShadow(PinTDs[10], 0);
	TextDrawSetOutline(PinTDs[10], 0);
	TextDrawFont(PinTDs[10], 0);

	PinTDs[11] = TextDrawCreate(267.868041, 202.166656, "usebox");
	TextDrawLetterSize(PinTDs[11], 0.000000, -3.701313);
	TextDrawTextSize(PinTDs[11], 355.481628, 0.000000);
	TextDrawAlignment(PinTDs[11], 1);
	TextDrawColor(PinTDs[11], 0);
	TextDrawUseBox(PinTDs[11], true);
	TextDrawBoxColor(PinTDs[11], 102);
	TextDrawSetShadow(PinTDs[11], 0);
	TextDrawSetOutline(PinTDs[11], 0);
	TextDrawFont(PinTDs[11], 0);

	PinTDs[12] = TextDrawCreate(294.825775, 303.083312, "usebox");
	TextDrawLetterSize(PinTDs[12], 0.000000, 1.685554);
	TextDrawTextSize(PinTDs[12], 269.742309, 0.000000);
	TextDrawAlignment(PinTDs[12], 1);
	TextDrawColor(PinTDs[12], 0);
	TextDrawUseBox(PinTDs[12], true);
	TextDrawBoxColor(PinTDs[12], 16711935);
	TextDrawSetShadow(PinTDs[12], 0);
	TextDrawSetOutline(PinTDs[12], 0);
	TextDrawFont(PinTDs[12], 0);

	PinTDs[13] = TextDrawCreate(353.922546, 302.916625, "usebox");
	TextDrawLetterSize(PinTDs[13], 0.000000, 1.685554);
	TextDrawTextSize(PinTDs[13], 326.902069, 0.000000);
	TextDrawAlignment(PinTDs[13], 1);
	TextDrawColor(PinTDs[13], 0);
	TextDrawUseBox(PinTDs[13], true);
	TextDrawBoxColor(PinTDs[13], -16776961);
	TextDrawSetShadow(PinTDs[13], 0);
	TextDrawSetOutline(PinTDs[13], 0);
	TextDrawFont(PinTDs[13], 0);
	
	//Objects
	
	CreateDynamicPickup(1239, 23, 1602.4291,-2177.7148,13.5547, -1, -1,-1,100.0);// Dealership1602.4291,-2177.7148,13.5547
	CreateDynamic3DTextLabel("DMV\nScrie [/exam] pentru a da de permis.",0xFFCF5EFF,1602.4291,-2177.7148,13.5547,7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);
	
	CreateDynamic3DTextLabel("Gun Shop\n[/buygun]",0xFFFFFF99,314.2594,-133.4281,999.6016,7.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, -1, -1, -1, 100.0);
	
    Create3DTextLabel("Dildo\nScrie /buydildo pentru a cumpara",0xFFFFFFFF,-103.7905,-22.0609,1000.7188,5.0, 0, 1);
    Create3DTextLabel("Muzica\nScrie /music pentru a schimba muzica din club",0xFFFFFFFF,475.6671,-14.8986,1003.6953,5.0, 0, 1);
    Create3DTextLabel("Droguri\nScrie /getdrugs pentru a cumpara droguri",0xFFFFFFFF,322.9745,1119.4409,1083.8828,20.0, 0, 1);
    Create3DTextLabel("National Guard Armoury\nApasa pe tasta 'F' pentru a intra",0xFFFFFFFF,157.3923,1903.2848,18.6660,20.0, 0, 1);
	Create3DTextLabel("Cluckin' Bell\nApasa pe tasta 'F' pentru a intra",0xFFFFFFFF,928.3403,-1352.9470,13.3438,20.0, 0, 1);
    Create3DTextLabel("Drugs House\nApasa pe tasta 'F' pentru a intra",0xFFFFFFFF,2166.4771,-1671.7883,15.0743,20.0, 0, 1);
    Create3DTextLabel("Gym Ls\nApasa pe tasta 'F' pentru a intra",0xFFFFFFFF,2229.3289,-1722.0793,13.5625,20.0, 0, 1);
    Create3DTextLabel("Bancomat\nScrie /withdraw pentru a scoate bani", 0xFFFFFF99,1137.1111,-1630.3916,13.8810,20.0, 0, 1);
    Create3DTextLabel("Bancomat\nScrie /withdraw pentru a scoate bani", 0xFFFFFF99,1009.0426,-929.6671,42.3281,20.0, 0, 1);
    Create3DTextLabel("Bancomat\nScrie /withdraw pentru a scoate bani", 0xFFFFFF99,1110.9364,-1788.1910,16.5938,20.0, 0, 1);
    Create3DTextLabel("Bancomat\nScrie /withdraw pentru a scoate bani", 0xFFFFFF99,1832.1864,-1849.8851,13.5781,20.0, 0, 1);
    Create3DTextLabel("Bancomat\nScrie /withdraw pentru a scoate bani", 0xFFFFFF99,411.9183,-1503.4347,31.4582,20.0, 0, 1);
    Create3DTextLabel("Bancomat\nScrie /withdraw pentru a scoate bani", 0xFFFFFF99,1646.5222,-2203.6174,13.5469,20.0, 0, 1);
    Create3DTextLabel("Primarie\nApasa pe tasta 'F' pentru a intra",0xFFFFFFFF,1481.1063,-1771.2532,18.7958,20.0, 0, 1);
	Create3DTextLabel("Materiale\nScrie /materials get to get some materials packages",-1,2770.4629,-1628.3237,12.1775,20.0, 0, 1);
    Create3DTextLabel("Price: 100$\nScrie /eat pentru a manca",0xFFFFFF99,377.8164,-119.4989,1001.4922,20.0, 0, 1);
    Create3DTextLabel("Price: 100$\nScrie /eat pentru a manca",0xFFFFFF99,371.5085,-6.9538,1001.8589,20.0, 0, 1);
    Create3DTextLabel("Price: 100$\nScrie /eat pentru a manca",0xFFFFFF99,377.7664,-68.4227,1001.5151,20.0, 0, 1);
    Create3DTextLabel("Price: 100$\nScrie /eat pentru a manca",0xFFFFFF99,-786.4063,500.0738,1371.7422,20.0, 0, 1);
	
	AddStaticPickup(1239, 23, 1481.1063,-1771.2532,18.7958); 			// City Hall
    AddStaticPickup(1239, 23, 1137.1111,-1630.3916,13.8810);			// ATM
    AddStaticPickup(1239, 23, 1009.0426,-929.6671,42.3281);				// ATM
	AddStaticPickup(1239, 23, 2229.3289,-1722.0793,13.5625);			// Gym Ls
	AddStaticPickup(1239, 23, 928.3403,-1352.9470,13.3438);				// Cluckin ls
	AddStaticPickup(1239, 23, 2770.4629,-1628.3237,12.1775); 			// MATSCOLLECT
	AddStaticPickup(1239, 23, 5.7771,-3989.8794,1003.5266); 			// STATION LS BUY
	AddStaticPickup(1239, 23, 157.3923,1903.2848,18.6660); 				// NG ARMOURY
	AddStaticPickup(1239, 23, 347.3933,162.1706,1025.7891); 			// CHECK CARITY


	AddStaticPickup(1239, 23, 2166.4771,-1671.7883,15.0743); 			// DRUGS HOUSE
	CreateDynamicPickup(1279, 23, 322.9745,1119.4409,1083.8828,-1,-1,-1,100.0);
	CreateDynamicPickup(1239, 23, -401.7662,-1418.7749,25.7209,-1,-1,-1,100.0);
	CreateDynamicPickup(1239, 23, 377.8164,-119.4989,1001.4922,-1,-1,-1,100.0); // eat pizzaboy
	CreateDynamicPickup(1239, 23, 371.5085,-6.9538,1001.8589,-1,-1,-1,100.0);   // eat cluckin
	CreateDynamicPickup(1239, 23, 377.7664,-68.4227,1001.5151,-1,-1,-1,100.0);  // eat burger
	CreateDynamicPickup(1239, 23, 1524.5557,-1677.8672,6.2188,-1,-1,-1,100.0); 	// /goup LSPD
	CreateDynamicPickup(1239, 23, 1564.9966,-1666.4923,28.3956,-1,-1,-1,100.0); // /godown LSPD
	CreateDynamicPickup(1239, 23, 2268.0696,2448.5889,3.5313,-1,-1,-1,100.0); 	// /goup LVPD
	CreateDynamicPickup(1239, 23, 2299.0493,2458.6294,38.6875,-1,-1,-1,100.0); // /godown LVPD
	CreateDynamicPickup(1239, 23, 1630.2517,1793.0970,10.8203,-1,-1,-1,100.0); 	// /goup Paramedics
	CreateDynamicPickup(1239, 23, 1608.1704,1787.0535,30.4688,-1,-1,-1,100.0); // /godown Paramedics
	CreateDynamicPickup(1239, 23, 475.6671,-14.8986,1003.6953,-1,-1,-1,100.0); 	// music alhambra
	CreateDynamicPickup(1239, 23, 830.6540,0.2702,1004.1797,-1,-1,-1,100.0); 	// bet
	CreateDynamicPickup(1239, 23, 1671.5824,-1329.4281,17.4524,-1,-1,-1,100.0); 	// event area enter
	CreateDynamicPickup(1239, 23, -1423.5153,935.8321,1036.4756,-1,-1,-1,100.0); // event area exit
	
	// mower
	CreateDynamicObject(11015, 1885.51526, -1154.34900, 24.91932,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1537, 1884.64392, -1163.13013, 23.03740,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1537, 1887.81311, -1145.54468, 23.01330,   0.00000, 0.00000, 0.00000);

	//Trash
	CreateDynamicObject(1332, 1923.72632, -1786.72913, 13.57835,   0.00000, 0.00000, -2.46000);
	CreateDynamicObject(1265, 1925.10718, -1787.04712, 13.26334,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1331, 1926.62195, -1786.90393, 13.57840,   0.00000, 0.00000, -0.66000);
	CreateDynamicObject(1333, 1393.08740, -1622.19958, 13.43071,   0.00000, 0.00000, -88.32005);
	CreateDynamicObject(1332, 1393.14136, -1625.28040, 13.43070,   0.00000, 0.00000, -90.06009);
	CreateDynamicObject(1264, 1392.55200, -1623.69958, 13.09461,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1334, 1109.56079, -1189.96130, 18.31467,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, 1111.40771, -1189.77881, 17.57407,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, 1111.59900, -1190.57324, 17.57407,   0.00000, 0.00000, 62.52001);
	CreateDynamicObject(1333, 1113.32458, -1190.04993, 18.07412,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1345, 978.96167, -1434.48706, 13.40298,   0.00000, 0.00000, 89.93999);
	CreateDynamicObject(1344, 732.00952, -1794.70129, 12.84622,   0.00000, 0.00000, 74.81998);
	CreateDynamicObject(1344, 731.28094, -1798.45508, 12.84622,   0.00000, 0.00000, 85.13998);
	CreateDynamicObject(1264, 731.34491, -1796.45764, 12.33037,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, -55.78953, -1585.60999, 2.68239,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, -55.23558, -1584.70386, 2.68239,   0.00000, 0.00000, 1.44000);
	CreateDynamicObject(1264, -54.88474, -1585.57239, 2.68239,   0.00000, 0.00000, 1.38000);
	CreateDynamicObject(1372, -54.53334, -1583.30994, 2.68240,   0.00000, 0.00000, -125.22000);
	CreateDynamicObject(1264, 255.59650, -264.09766, 1.07050,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, 249.55182, -262.76199, 1.07050,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1332, 605.17682, -1522.95325, 15.16066,   0.00000, 0.00000, 178.26001);
	CreateDynamicObject(1333, 602.02997, -1522.70996, 15.16070,   0.00000, 0.00000, 178.25999);
	CreateDynamicObject(1264, 603.55914, -1522.92810, 14.61454,   0.00000, 0.00000, 96.06001);
	CreateDynamicObject(1332, 1660.31909, -2115.62500, 13.58558,   0.00000, 0.00000, 91.26001);
	CreateDynamicObject(1331, 1660.41626, -2110.28442, 13.58560,   0.00000, 0.00000, 90.72000);
	CreateDynamicObject(1333, 1660.41077, -2113.12598, 13.58560,   0.00000, 0.00000, 90.72000);
	CreateDynamicObject(1264, 1660.04285, -2117.10889, 12.97071,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, 1660.28125, -2111.48560, 12.97071,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1332, 2271.41870, -1626.49451, 15.31296,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, 2273.11816, -1626.25500, 14.65405,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(1264, 2269.33398, -1626.23938, 14.65405,   0.00000, 0.00000, 0.00000);

	// GUNSHOS TONOMAT
	CreateDynamicObject(1977, 317.1961, -132.4190, 1002.9836,  356.9584, 0.1400, -90.5708);

	// NINJA OBJ
	CreateDynamicObject(19464, 966.09637, -17.38180, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19464, 963.04138, -8.57693, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 936.84985, -29.07637, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19464, 966.09637, -11.52280, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19464, 957.33081, -32.01170, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 951.47180, -32.01170, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 945.61279, -32.01170, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 939.75378, -32.01170, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 963.18982, -32.01175, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 957.18237, -8.57690, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 951.32343, -8.57690, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 945.46442, -8.57690, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 939.60541, -8.57690, 682.68018,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19464, 966.09637, -23.24080, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19465, 966.09637, -29.14710, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19464, 936.84991, -23.21740, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19464, 936.84991, -17.35840, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19464, 936.84991, -11.49940, 682.68018,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(19452, 937.24658, -27.35850, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 937.44531, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 961.03632, -27.35850, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 957.59442, -27.35850, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 954.13922, -27.35850, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 950.75861, -27.37330, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 947.34387, -27.35850, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 947.34387, -27.35850, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 943.84369, -27.36108, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 940.47839, -27.35850, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(1533, 966.09637, -28.39780, 680.15338,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(19452, 964.39697, -27.35847, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 937.80798, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 961.11328, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 957.73907, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 954.26093, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 950.80542, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 947.37878, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 944.04907, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 940.69781, -17.83690, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 964.49377, -17.83694, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 964.47217, -8.24414, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 961.23181, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 958.10028, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 954.66339, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 951.24542, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 947.89069, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 944.47729, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(19452, 941.15411, -8.24410, 680.06592,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(14787, 941.46375, -7.82082, 680.24762,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(14787, 943.79834, -32.27930, 680.24762,   0.00000, 0.00000, -180.00000);
	CreateDynamicObject(18981, 973.63208, -20.36405, 684.98309,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(18981, 949.18127, -20.38985, 684.98309,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(1985, 943.08337, -20.50240, 684.80872,   0.00000, 90.00000, 0.00000);
	CreateDynamicObject(1985, 942.96997, -26.58030, 683.61877,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(14778, 938.46637, -18.48480, 684.69733,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(1985, 939.61218, -22.47360, 680.57800,   0.00000, 90.00000, 91.00000);

	// BANK SEIF
	CreateDynamicObject(2332, 2314.28271, -0.10613, 26.13725,   0.00000, 0.00000, 0.00000);

	// mall radio obj door
	CreateDynamicObject(1557, 1260.45471, -805.83423, 1083.01282,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(1557, 1260.45605, -802.81403, 1083.01282,   0.00000, 0.00000, -90.00000);

	// alhambra music
	CreateDynamicObject(1958, 476.63626, -15.04685, 1003.50720,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(1958, 476.63336, -14.71221, 1003.50720,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(2232, 476.50940, -13.30400, 1003.27753,   0.00000, 0.00000, -45.00000);

	//carsellto
	CreateDynamicObject(16771, 411.43228, 2434.91479, 900.49469,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(16773, 419.89609, 2456.39746, 897.68597,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(16773, 405.67798, 2456.39526, 897.68597,   0.00000, 0.00000, 0.00000);
	CreateDynamicObject(16773, 402.10873, 2456.31104, 897.68597,   0.00000, 0.00000, 0.00000);

	// bug house
	CreateDynamicObject(19303, 442.47998, 509.23032, 1001.63678,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19304, 453.06204, 507.98209, 1001.92603,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(19304, 453.11362, 509.63824, 1001.92603,   0.00000, 0.00000, 90.00000);

	// anti car bomb
	CreateDynamicObject(971, 1843.32751, -1855.42114, 12.00100,   0.00000, 0.00000, 90.00000);
	
	//ATM
	CreateDynamicObject(2942, 1833.24634, -1849.86816, 13.20704,   0.00000, 0.00000, -90.00000); // spawn
	CreateDynamicObject(2942, 1111.92981, -1788.20508, 16.22382,   0.00000, 0.00000, -90.00000); // ds
	CreateDynamicObject(2942, 412.60052, -1504.30444, 31.07969,   0.00000, 0.00000, -140.00000); // atm fbi
	CreateDynamicObject(2942, 1646.52637, -2204.39355, 13.13628,   0.00000, 0.00000, -180.00000);
	
	CreateDynamicObject(970, 266.37939, 82.12314, 1000.48004,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(970, 266.37939, 82.12314, 1001.25946,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(970, 266.37939, 82.12314, 1002.01904,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(970, 266.37939, 82.12314, 1002.83704,   0.00000, 0.00000, 90.00000);
	CreateDynamicObject(970, 266.37354, 77.59760, 1000.47998,   0.00000, 0.00000, 89.94000);
	CreateDynamicObject(970, 266.37354, 77.59760, 1001.25946,   0.00000, 0.00000, 89.94000);
	CreateDynamicObject(970, 266.37354, 77.59760, 1002.03833,   0.00000, 0.00000, 89.94000);
	CreateDynamicObject(970, 266.37354, 77.59760, 1002.81781,   0.00000, 0.00000, 89.94000);
	CreateDynamicObject(970, 266.36737, 86.60525, 1000.48004,   0.00000, 0.00000, 90.29999);
	CreateDynamicObject(970, 266.36737, 86.60525, 1001.27924,   0.00000, 0.00000, 90.29999);
	CreateDynamicObject(970, 266.36737, 86.60525, 1002.07922,   0.00000, 0.00000, 90.29999);
	CreateDynamicObject(970, 266.36737, 86.60525, 1002.85907,   0.00000, 0.00000, 90.29999);
	//Police Departament Exterior
	CreateDynamicObject(11326, 1605.05212, -1623.62476, 14.96770,   0.00000, 0.00000, 89.46000);
	CreateDynamicObject(955, 1553.64233, -1683.42175, 12.92650,   0.00000, 0.00000, -90.00000);
	CreateDynamicObject(983, 1542.62939, -1641.17981, 27.70590,   0.00000, 0.00000, -180.48010);
	CreateDynamicObject(983, 1545.80750, -1650.77563, 27.68590,   0.00000, 0.00000, -270.12021);
	CreateDynamicObject(983, 1542.60828, -1647.55884, 27.70590,   -0.16000, -0.04000, -180.12010);
	CreateDynamicObject(983, 1550.38745, -1650.77563, 27.68590,   0.00000, 0.00000, -270.12021);
	CreateDynamicObject(983, 1542.62939, -1640.45984, 27.70590,   0.00000, 0.00000, -180.48010);
	CreateDynamicObject(983, 1545.85986, -1637.26941, 27.70590,   0.00000, 0.00000, -270.18002);
	CreateDynamicObject(983, 1552.21460, -1637.27222, 27.70590,   0.00000, 0.00000, -270.18002);
	CreateDynamicObject(983, 1558.61877, -1637.28772, 27.70590,   0.00000, 0.00000, -270.18002);
	CreateDynamicObject(983, 1565.02625, -1637.32434, 27.70590,   0.00000, 0.00000, -270.18002);
	CreateDynamicObject(983, 1571.40149, -1637.35168, 27.70590,   0.00000, 0.00000, -270.18002);
	CreateDynamicObject(983, 1574.66931, -1637.35522, 27.70590,   0.00000, 0.00000, -270.17999);
	CreateDynamicObject(983, 1577.83557, -1640.57202, 27.70590,   0.00000, 0.00000, -180.48010);
	CreateDynamicObject(983, 1577.77295, -1646.93713, 27.70590,   0.00000, 0.00000, -180.48010);
	CreateDynamicObject(983, 1577.78162, -1653.32056, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.78674, -1659.73962, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.77917, -1666.16150, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.75732, -1672.53748, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.72766, -1678.91931, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.73621, -1685.32568, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.72400, -1691.71228, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.71289, -1698.10791, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.72131, -1704.51245, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.69897, -1710.88159, 27.70590,   0.00000, 0.00000, -180.06012);
	CreateDynamicObject(983, 1577.69897, -1711.24158, 27.70590,   0.00000, 0.00000, -180.06010);
	CreateDynamicObject(983, 1574.44556, -1714.38306, 27.70590,   0.00000, 0.00000, -270.35995);
	CreateDynamicObject(983, 1568.07471, -1714.34656, 27.70590,   0.00000, 0.00000, -270.35995);
	CreateDynamicObject(983, 1561.66760, -1714.30737, 27.70590,   0.00000, 0.00000, -270.35995);
	CreateDynamicObject(983, 1555.31116, -1714.26440, 27.70590,   0.00000, 0.00000, -270.35995);
	CreateDynamicObject(983, 1548.95508, -1714.22168, 27.70590,   0.00000, 0.00000, -270.35995);
	CreateDynamicObject(983, 1545.76025, -1714.20190, 27.70590,   0.00000, 0.00000, -270.35995);
	CreateDynamicObject(983, 1542.57971, -1710.99304, 27.70590,   0.00000, 0.00000, -359.87982);
	CreateDynamicObject(983, 1542.54773, -1704.60864, 27.70590,   0.00000, 0.00000, -359.87982);
	CreateDynamicObject(983, 1542.54773, -1703.70862, 27.70590,   0.00000, 0.00000, -359.87979);
	CreateDynamicObject(983, 1545.74390, -1700.54211, 27.70590,   0.00000, 0.00000, -270.00009);
	CreateDynamicObject(983, 1550.38757, -1700.53650, 27.70590,   0.00000, 0.00000, -270.00009);
	CreateDynamicObject(983, 1553.58850, -1697.36475, 27.70590,   0.00000, 0.00000, -179.70013);
	CreateDynamicObject(983, 1553.56555, -1690.94910, 27.70590,   0.00000, 0.00000, -179.70013);
	CreateDynamicObject(983, 1553.56580, -1656.84106, 27.70590,   0.00000, 0.00000, -179.70010);
	CreateDynamicObject(983, 1553.55737, -1653.96729, 27.70590,   0.00000, 0.00000, -179.70010);
	CreateDynamicObject(3934, 1562.89099, -1700.73755, 27.38710,   0.00000, -0.02000, -0.84000);
	CreateDynamicObject(3934, 1560.78516, -1650.95300, 27.38710,   0.00000, -0.02000, 1.02000);
	//Pompe de benzina
	CreateDynamicObject(1676, 1009.18927, -936.09637, 42.78190,   0.00000, 0.00000, 6.66000);
	CreateDynamicObject(1676, 1005.57520, -936.67499, 42.78190,   0.00000, 0.00000, 6.66000);
	CreateDynamicObject(1676, 1002.23541, -937.06488, 42.78190,   0.00000, 0.00000, 6.66000);
	CreateDynamicObject(1676, 998.64508, -937.57654, 42.78190,   0.00000, 0.00000, 6.66000);
	
    CreateObject(3095, 166.58797, 1849.71204, 26.68690,   0.00000, 0.00000, 0.00000);
    CreateDynamicObject(1496, 1780.61328, -1569.65259, 1737.62109,   0.00000, 0.00000, -88.43999); // usa

    //Training
    CreateObject(19447, -2438.28955, 1545.89087, 15.75533,   0.00000, 90.00000, 0.00000);
	CreateObject(19447, -2438.27197, 1536.22925, 15.75533,   0.00000, 90.00000, 0.00000);
	CreateObject(19447, -2438.27197, 1536.22925, 14.71679,   0.00000, 90.00000, 0.00000);
	CreateObject(19447, -2438.04785, 1545.83386, 14.71679,   0.00000, 90.00000, 0.00000);

    //JAIL
    CreatePickup(1239, 23, 1798.3613,-1578.8060,14.0908);
	// ROB!
	CreateObject(14576, -296.85858154297, 1494.0521240234, 1078.1756591797, 0, 0, 0);
	CreateObject(2634, -296.79376220703, 1501.7164306641, 1071.6612548828, 0, 0, 180);
	CreateObject(2332, -299.64529418945, 1517.2493896484, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -298.7919921875, 1517.2420654297, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -297.92276000977, 1517.2474365234, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -297.0446472168, 1517.2532958984, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -296.16833496094, 1517.26953125, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -295.28771972656, 1517.3234863281, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -294.40380859375, 1517.3400878906, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -299.50650024414, 1517.0925292969, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -298.72805786133, 1517.0700683594, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -297.94815063477, 1517.1951904297, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -297.0751953125, 1517.1483154297, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -296.12149047852, 1517.2202148438, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -295.23345947266, 1517.2153320313, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -294.41537475586, 1517.4155273438, 1071.3913574219, 0, 0, 0);
	CreateObject(2754, -290.54275512695, 1493.1734619141, 1071.0080566406, 0, 0, 0);
	CreateObject(2180, -292.33065795898, 1497.4266357422, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -294.31716918945, 1497.3857421875, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -296.32635498047, 1497.4061279297, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -298.34826660156, 1497.4069824219, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -300.37774658203, 1497.4206542969, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -302.3835144043, 1497.4039306641, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -304.87002563477, 1499.376953125, 1070.1059570313, 0, 0, 270);
	CreateObject(2180, -304.87603759766, 1501.3273925781, 1070.1059570313, 0, 0, 270);
	CreateObject(2180, -290.44012451172, 1498.3767089844, 1070.1059570313, 0, 0, 90);
	CreateObject(2180, -290.41708374023, 1500.3509521484, 1070.1059570313, 0, 0, 90);
	CreateObject(2309, -300.53225708008, 1498.4547119141, 1070.1059570313, 0, 0, 180);
	CreateObject(2309, -298.62414550781, 1498.4822998047, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -296.85922241211, 1498.494140625, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -295.17156982422, 1498.6375732422, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -293.26782226563, 1498.6136474609, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -291.59939575195, 1498.7593994141, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(1649, -292.86682128906, 1497.2641601563, 1073.5322265625, 0, 0, 0);
	CreateObject(1649, -296.59625244141, 1497.3249511719, 1073.5714111328, 0, 0, 0);
	CreateObject(1649, -300.78131103516, 1497.3314208984, 1073.5513916016, 0, 0, 0);
	CreateObject(1491, -304.36709594727, 1497.1517333984, 1070.1419677734, 0, 0, 0);
	CreateObject(2180, -304.36709594727, 1497.5606689453, 1072.4119873047, 0, 0, 0);
	CreateObject(3260, -303.89990234375, 1497.4362792969, 1074.2059326172, 0, 0, 0);
	CreateObject(1649, -305.39376831055, 1499.4538574219, 1073.8479003906, 0, 0, 270);
	CreateObject(1649, -290.15014648438, 1499.8581542969, 1073.5062255859, 0, 0, 90);
	CreateObject(2754, -290.54351806641, 1493.9809570313, 1071.0080566406, 0, 0, 0);
	CreateObject(2754, -290.54168701172, 1494.7744140625, 1071.0080566406, 0, 0, 0);
	CreateObject(2754, -304.90341186523, 1493.2034912109, 1071.0153808594, 0, 0, 180);
	CreateObject(2754, -304.90866088867, 1493.9771728516, 1071.0080566406, 0, 0, 179.99450683594);
	CreateObject(2754, -304.9248046875, 1494.7788085938, 1071.0056152344, 0, 0, 180);
	CreateObject(2771, -300.58331298828, 1497.1810302734, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -298.56274414063, 1497.2697753906, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -296.6213684082, 1497.3538818359, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -295.02041625977, 1497.2557373047, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -293.24566650391, 1497.4337158203, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -291.58123779297, 1497.4664306641, 1071.1298828125, 0, 0, 0);
	CreateObject(2614, -296.94174194336, 1481.5251464844, 1073.6715087891, 0, 0, 180);
	CreateObject(2614, -296.79406738281, 1501.4273681641, 1074.1142578125, 0, 0, 0);
	CreateObject(2957, -297.67880249023, 1481.3848876953, 1071.3101806641, 0, 0, 0);
	CreateObject(1892, -297.18051147461, 1482.3099365234, 1070.1059570313, 0, 0, 0);
	CreateObject(1892, -303.97128295898, 1495.9926757813, 1070.1059570313, 0, 0, 0);
	CreateObject(2894, -294.09530639648, 1497.2047119141, 1070.9769287109, 0, 0, 0);
	CreateObject(1622, -291.38186645508, 1491.8608398438, 1074.1547851563, 0, 0, 0);
	CreateObject(1627, -291.01019287109, 1491.9876708984, 1073.0720214844, 0, 0, 0);
	CreateObject(1616, -291.35781860352, 1496.8079833984, 1074.1136474609, 0, 0, 0);
	CreateObject(1550, -302.4655456543, 1497.7889404297, 1070.4992675781, 0, 0, 0);
	CreateObject(3389, -304.92987060547, 1489.1530761719, 1070.1059570313, 0, 0, 0);
	CreateObject(3389, -304.91171264648, 1488.1590576172, 1070.1059570313, 0, 0, 0);
	CreateObject(3389, -304.93658447266, 1490.1348876953, 1070.1059570313, 0, 0, 0);
	CreateObject(3389, -304.93856811523, 1491.0897216797, 1070.1059570313, 0, 0, 0);
	CreateObject(2009, -305.70278930664, 1483.0612792969, 1070.1059570313, 0, 0, 270);
	CreateObject(2120, -305.58801269531, 1482.1243896484, 1070.7437744141, 0, 0, 180);
	CreateObject(14532, -307.78625488281, 1481.8435058594, 1071.0886230469, 0, 0, 0);

	CreateObject(14576, -296.85858154297, 1494.0521240234, 1078.1756591797, 0, 0, 0);
	CreateObject(2634, -296.79376220703, 1501.7164306641, 1071.6612548828, 0, 0, 180); //This is the vault door, script it to blow open!
	CreateObject(2332, -299.64529418945, 1517.2493896484, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -298.7919921875, 1517.2420654297, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -297.92276000977, 1517.2474365234, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -297.0446472168, 1517.2532958984, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -296.16833496094, 1517.26953125, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -295.28771972656, 1517.3234863281, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -294.40380859375, 1517.3400878906, 1070.4569091797, 0, 0, 0);
	CreateObject(2332, -299.50650024414, 1517.0925292969, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -298.72805786133, 1517.0700683594, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -297.94815063477, 1517.1951904297, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -297.0751953125, 1517.1483154297, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -296.12149047852, 1517.2202148438, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -295.23345947266, 1517.2153320313, 1071.3913574219, 0, 0, 0);
	CreateObject(2332, -294.41537475586, 1517.4155273438, 1071.3913574219, 0, 0, 0);
	CreateObject(2754, -290.54275512695, 1493.1734619141, 1071.0080566406, 0, 0, 0);
	CreateObject(2180, -292.33065795898, 1497.4266357422, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -294.31716918945, 1497.3857421875, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -296.32635498047, 1497.4061279297, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -298.34826660156, 1497.4069824219, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -300.37774658203, 1497.4206542969, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -302.3835144043, 1497.4039306641, 1070.1059570313, 0, 0, 0);
	CreateObject(2180, -304.87002563477, 1499.376953125, 1070.1059570313, 0, 0, 270);
	CreateObject(2180, -304.87603759766, 1501.3273925781, 1070.1059570313, 0, 0, 270);
	CreateObject(2180, -290.44012451172, 1498.3767089844, 1070.1059570313, 0, 0, 90);
	CreateObject(2180, -290.41708374023, 1500.3509521484, 1070.1059570313, 0, 0, 90);
	CreateObject(2309, -300.53225708008, 1498.4547119141, 1070.1059570313, 0, 0, 180);
	CreateObject(2309, -298.62414550781, 1498.4822998047, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -296.85922241211, 1498.494140625, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -295.17156982422, 1498.6375732422, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -293.26782226563, 1498.6136474609, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(2309, -291.59939575195, 1498.7593994141, 1070.1059570313, 0, 0, 179.99450683594);
	CreateObject(1649, -292.86682128906, 1497.2641601563, 1073.5322265625, 0, 0, 0);
	CreateObject(1649, -296.59625244141, 1497.3249511719, 1073.5714111328, 0, 0, 0);
	CreateObject(1649, -300.78131103516, 1497.3314208984, 1073.5513916016, 0, 0, 0);
	CreateObject(1491, -304.36709594727, 1497.1517333984, 1070.1419677734, 0, 0, 0);
	CreateObject(2180, -304.36709594727, 1497.5606689453, 1072.4119873047, 0, 0, 0);
	CreateObject(3260, -303.89990234375, 1497.4362792969, 1074.2059326172, 0, 0, 0);
	CreateObject(1649, -305.39376831055, 1499.4538574219, 1073.8479003906, 0, 0, 270);
	CreateObject(1649, -290.15014648438, 1499.8581542969, 1073.5062255859, 0, 0, 90);
	CreateObject(2754, -290.54351806641, 1493.9809570313, 1071.0080566406, 0, 0, 0);
	CreateObject(2754, -290.54168701172, 1494.7744140625, 1071.0080566406, 0, 0, 0);
	CreateObject(2754, -304.90341186523, 1493.2034912109, 1071.0153808594, 0, 0, 180);
	CreateObject(2754, -304.90866088867, 1493.9771728516, 1071.0080566406, 0, 0, 179.99450683594);
	CreateObject(2754, -304.9248046875, 1494.7788085938, 1071.0056152344, 0, 0, 180);
	CreateObject(2771, -300.58331298828, 1497.1810302734, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -298.56274414063, 1497.2697753906, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -296.6213684082, 1497.3538818359, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -295.02041625977, 1497.2557373047, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -293.24566650391, 1497.4337158203, 1071.1298828125, 0, 0, 0);
	CreateObject(2771, -291.58123779297, 1497.4664306641, 1071.1298828125, 0, 0, 0);
	CreateObject(2614, -296.94174194336, 1481.5251464844, 1073.6715087891, 0, 0, 180);
	CreateObject(2614, -296.79406738281, 1501.4273681641, 1074.1142578125, 0, 0, 0);
	CreateObject(2957, -297.67880249023, 1481.3848876953, 1071.3101806641, 0, 0, 0);
	CreateObject(1892, -297.18051147461, 1482.3099365234, 1070.1059570313, 0, 0, 0);
	CreateObject(1892, -303.97128295898, 1495.9926757813, 1070.1059570313, 0, 0, 0);
	CreateObject(2894, -294.09530639648, 1497.2047119141, 1070.9769287109, 0, 0, 0);
	CreateObject(1622, -291.38186645508, 1491.8608398438, 1074.1547851563, 0, 0, 0);
	CreateObject(1627, -291.01019287109, 1491.9876708984, 1073.0720214844, 0, 0, 0);
	CreateObject(1616, -291.35781860352, 1496.8079833984, 1074.1136474609, 0, 0, 0);
	CreateObject(1550, -302.4655456543, 1497.7889404297, 1070.4992675781, 0, 0, 0);
	CreateObject(3389, -304.92987060547, 1489.1530761719, 1070.1059570313, 0, 0, 0);
	CreateObject(3389, -304.91171264648, 1488.1590576172, 1070.1059570313, 0, 0, 0);
	CreateObject(3389, -304.93658447266, 1490.1348876953, 1070.1059570313, 0, 0, 0);
	CreateObject(3389, -304.93856811523, 1491.0897216797, 1070.1059570313, 0, 0, 0);
	CreateObject(2009, -305.70278930664, 1483.0612792969, 1070.1059570313, 0, 0, 270);
	CreateObject(2120, -305.58801269531, 1482.1243896484, 1070.7437744141, 0, 0, 180);
	CreateObject(14532, -307.78625488281, 1481.8435058594, 1071.0886230469, 0, 0, 0);
	
	//DMV
	CreateObject(11015, 1592.77185, -2176.05713, 14.49280,   0.00000, 0.00000, 89.99999);
	CreateObject(8661, 1611.28064, -2174.95605, 12.55233,   0.00000, 0.00000, 0.00000);
	CreateObject(1538, 1601.6345, -2178.4473, 12.6644,   0.00000, 0.00000, 90.00000);
	CreateObject(984, 1607.35413, -2164.92993, 13.20367,   0.00000, 0.00000, 90.00000);
	CreateObject(984, 1600.94385, -2171.33008, 13.20370,   0.00000, 0.00000, 0.00000);
	CreateObject(984, 1620.17065, -2164.92798, 13.20367,   0.00000, 0.00000, 90.00000);
	CreateObject(984, 1624.91113, -2164.92676, 13.20367,   0.00000, 0.00000, 90.00000);
	CreateObject(984, 1631.30481, -2171.30762, 13.20370,   0.00000, 0.00000, 0.00000);
	CreateObject(984, 1631.29517, -2178.48779, 13.20370,   0.00000, 0.00000, 0.00000);
	CreateObject(3472, 1601.71106, -2165.78638, 12.58255,   0.00000, 0.00000, 0.00000);
	CreateObject(3472, 1631.40564, -2185.16479, 12.58024,   0.00000, 0.00000, 0.00000);

	//
	// area 51
	CreateDynamicObject(3749, 135.77930, 1995.75391, 24.17426,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(9254, 158.64410, 1969.52661, 19.18244,   0.00000, 0.00000, 90.45837, 51, -1, -1, 200.0);
	CreateDynamicObject(7191, 164.48360, 1997.64697, 17.41398,   0.00000, 0.00000, 269.31531, 51, -1, -1, 200.0);
	CreateDynamicObject(7191, 176.05420, 1974.62891, 17.41398,   0.00000, 0.00000, 179.58356, 51, -1, -1, 200.0);
	CreateDynamicObject(7191, 175.96587, 1963.49561, 17.41398,   0.00000, 0.00000, 179.58252, 51, -1, -1, 200.0);
	CreateDynamicObject(7191, 163.60716, 1941.51843, 17.41398,   0.00000, 0.00000, 90.15930, 51, -1, -1, 200.0);
	CreateDynamicObject(16061, 182.78891, 1975.80872, 16.91743,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 145.69157, 1997.12927, 18.81375,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 157.65073, 1997.08008, 18.81375,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 163.65820, 1997.08301, 18.81375,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 175.76755, 1997.07300, 18.73875,   0.00000, 0.00000, 268.69519, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 175.53583, 1985.06433, 18.73875,   0.00000, 0.00000, 268.69263, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 175.24164, 1973.01843, 18.73875,   0.00000, 0.00000, 268.69263, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 175.18321, 1961.08691, 18.73875,   0.00000, 0.00000, 268.69263, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 175.05280, 1952.08618, 18.73875,   0.00000, 0.00000, 268.69263, 51, -1, -1, 200.0);
	CreateDynamicObject(987, 188.23828, 1997.51465, 15.73875,   0.00000, 0.00000, 180.44495, 51, -1, -1, 200.0);
	CreateDynamicObject(7657, 135.89258, 1996.23242, 20.20536,   0.00000, 0.00000, 179.45618, 51, -1, -1, 200.0);
	CreateDynamicObject(8165, 99.19238, 1980.11719, 20.44577,   0.00000, 0.00000, 280.23926, 51, -1, -1, 200.0);
	CreateDynamicObject(8165, 65.94008, 1930.20862, 18.92077,   0.00000, 0.00000, 330.08911, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 110.30697, 1886.50122, 19.46836,   0.00000, 0.00000, 89.01001, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 110.00310, 1849.51294, 19.46836,   0.00000, 0.00000, 90.94568, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 138.55739, 1820.66431, 19.46836,   0.00000, 0.00000, 178.64478, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 193.96484, 1819.35352, 19.46836,   0.00000, 0.00000, 178.63770, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 239.94629, 1818.26001, 19.46836,   0.00000, 0.00000, 178.63770, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 131.22754, 1922.04883, 19.46836,   0.00000, 0.00000, 178.63770, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 186.63867, 1920.38672, 19.49336,   0.00000, 0.00000, 177.90710, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 242.10156, 1918.32813, 19.49336,   0.00000, 0.00000, 177.90710, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 104.07129, 1922.96484, 22.54728,   0.00000, 0.00000, 358.99475, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 109.99708, 1913.82825, 18.79730,   0.00000, 0.00000, 358.99475, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 109.99707, 1913.82813, 21.29730,   0.00000, 0.00000, 358.99475, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 98.72530, 1912.39771, 18.44731,   0.00000, 0.00000, 358.99475, 51, -1, -1, 200.0);
	CreateDynamicObject(971, 104.43750, 1913.20215, 19.43171,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 97.86523, 1912.39355, 18.44731,   0.00000, 0.00000, 358.99475, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 97.86523, 1912.39355, 21.17230,   0.00000, 0.00000, 358.99475, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 98.70313, 1912.42285, 21.17230,   0.00000, 0.00000, 358.99475, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 103.92676, 1923.06641, 22.54728,   0.00000, 0.00000, 88.72009, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 103.92043, 1923.05920, 19.77228,   0.00000, 0.00000, 88.72009, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 104.08185, 1922.99194, 19.77228,   0.00000, 0.00000, 358.99008, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 104.08105, 1922.99121, 18.02228,   0.00000, 0.00000, 358.98926, 51, -1, -1, 200.0);
	CreateDynamicObject(7922, 103.89114, 1923.07178, 18.02228,   0.00000, 0.00000, 88.71924, 51, -1, -1, 200.0);
	CreateDynamicObject(971, 101.30469, 1922.89551, 20.33169,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(971, 110.19922, 1918.69043, 19.18171,   0.00000, 0.00000, 270.31311, 51, -1, -1, 200.0);
	CreateDynamicObject(971, 96.67881, 1919.23840, 19.18171,   0.00000, 0.00000, 270.31311, 51, -1, -1, 200.0);
	CreateDynamicObject(8165, 78.47784, 1869.79407, 17.47079,   0.00000, 0.00000, 11.94910, 51, -1, -1, 200.0);
	CreateDynamicObject(8378, 215.07622, 1875.20862, 5.86033,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(3819, 206.80524, 1870.14709, 17.63871,   0.00000, 0.00000, 269.81250, 51, -1, -1, 200.0);
	CreateDynamicObject(3819, 226.66119, 1872.32544, 17.63871,   0.00000, 0.00000, 358.76404, 51, -1, -1, 200.0);
	CreateDynamicObject(3819, 192.59851, 1882.11829, 17.63838,   0.00000, 0.00000, 180.47791, 51, -1, -1, 200.0);
	CreateDynamicObject(6066, 147.55284, 1875.85583, 19.27088,   0.00000, 0.00000, 181.39990, 51, -1, -1, 200.0);
	CreateDynamicObject(3089, 145.11375, 1879.23083, 18.16494,   0.00000, 0.00000, 272.45032, 51, -1, -1, 200.0);
	CreateDynamicObject(833, 245.98195, 1862.52258, 20.27188,   0.00000, 0.00000, 308.20996, 51, -1, -1, 200.0);
	CreateDynamicObject(947, 146.88770, 1895.91504, 19.69527,   0.00000, 0.00000, 180.76355, 51, -1, -1, 200.0);
	CreateDynamicObject(947, 151.73535, 1895.81348, 19.69527,   0.00000, 0.00000, 180.75806, 51, -1, -1, 200.0);
	CreateDynamicObject(4010, 210.32227, 1898.62549, 16.73993,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(5061, 259.20795, 1918.25732, 18.08186,   0.00000, 0.00000, 270.02014, 51, -1, -1, 200.0);
	CreateDynamicObject(8210, 266.74167, 1845.41028, 19.46836,   0.00000, 0.00000, 272.38269, 51, -1, -1, 200.0);
	CreateDynamicObject(4141, 253.40047, 1897.84790, 27.51808,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(5061, 231.89529, 1886.83496, 18.08186,   0.00000, 0.00000, 359.36108, 51, -1, -1, 200.0);
	CreateDynamicObject(9241, 254.40829, 1900.40271, 40.24517,   0.00000, 0.00000, 0.00000, 51, -1, -1, 200.0);
	CreateDynamicObject(3029, 251.79494, 1883.47253, 38.84553,   0.00000, 0.00000, 270.31531, 51, -1, -1, 200.0);
	CreateDynamicObject(7657, 135.89258, 1996.23242, 23.55536,   0.00000, 0.00000, 179.45618, 51, -1, -1, 200.0);
	CreateDynamicObject(10562, 172.45107, 1918.39722, 16.56282,   0.00000, 0.00000, 87.69995, 51, -1, -1, 200.0);
	CreateDynamicObject(10562, 166.85867, 1889.35767, 16.56282,   0.00000, 0.00000, 87.69836, 51, -1, -1, 200.0);
}
stock PlayerTextdraws(playerid) {	
	TradePTD[0] = CreatePlayerTextDraw(playerid, 225.666641, 116.992660, "Bunurile tale");
	PlayerTextDrawLetterSize(playerid, TradePTD[0], 0.176999, 1.077332);
	PlayerTextDrawAlignment(playerid, TradePTD[0], 2);
	PlayerTextDrawColor(playerid, TradePTD[0], -166);
	PlayerTextDrawSetShadow(playerid, TradePTD[0], 0);
	PlayerTextDrawSetOutline(playerid, TradePTD[0], 0);
	PlayerTextDrawBackgroundColor(playerid, TradePTD[0], -231);
	PlayerTextDrawFont(playerid, TradePTD[0], 2);
	PlayerTextDrawSetProportional(playerid, TradePTD[0], 1);
	PlayerTextDrawSetShadow(playerid, TradePTD[0], 0);

	CpTDD = CreatePlayerTextDraw(playerid, 87.333328, 328.548217, "Distance: 1002.m");
	PlayerTextDrawLetterSize(playerid, CpTDD, 0.286666, 1.367704);
	PlayerTextDrawAlignment(playerid, CpTDD, 2);
	PlayerTextDrawColor(playerid, CpTDD, -1);
	PlayerTextDrawSetShadow(playerid, CpTDD, 0);
	PlayerTextDrawSetOutline(playerid, CpTDD, 1);
	PlayerTextDrawBackgroundColor(playerid, CpTDD, 96);
	PlayerTextDrawFont(playerid, CpTDD, 3);
	PlayerTextDrawSetProportional(playerid, CpTDD, 1);
	PlayerTextDrawSetShadow(playerid, CpTDD, 0);

	TradePTD[1] = CreatePlayerTextDraw(playerid, 418.333099, 116.992668, "Bunurile lui Sky");
	PlayerTextDrawLetterSize(playerid, TradePTD[1], 0.176999, 1.077332);
	PlayerTextDrawAlignment(playerid, TradePTD[1], 2);
	PlayerTextDrawColor(playerid, TradePTD[1], -166);
	PlayerTextDrawSetShadow(playerid, TradePTD[1], 0);
	PlayerTextDrawSetOutline(playerid, TradePTD[1], 0);
	PlayerTextDrawBackgroundColor(playerid, TradePTD[1], -231);
	PlayerTextDrawFont(playerid, TradePTD[1], 2);
	PlayerTextDrawSetProportional(playerid, TradePTD[1], 1);
	PlayerTextDrawSetShadow(playerid, TradePTD[1], 0);

	TradePTD[2] = CreatePlayerTextDraw(playerid, 188.666763, 355.511138, "Adauga");
	PlayerTextDrawLetterSize(playerid, TradePTD[2], 0.246665, 1.122962);
	PlayerTextDrawTextSize(playerid, TradePTD[2], 10.000000, 35.000000);
	PlayerTextDrawAlignment(playerid, TradePTD[2], 2);
	PlayerTextDrawColor(playerid, TradePTD[2], -65281);
	PlayerTextDrawBoxColor(playerid, TradePTD[2], 255);
	PlayerTextDrawSetShadow(playerid, TradePTD[2], 0);
	PlayerTextDrawSetOutline(playerid, TradePTD[2], 1);
	PlayerTextDrawBackgroundColor(playerid, TradePTD[2], 47);
	PlayerTextDrawFont(playerid, TradePTD[2], 1);
	PlayerTextDrawSetProportional(playerid, TradePTD[2], 1);
	PlayerTextDrawSetShadow(playerid, TradePTD[2], 0);
	PlayerTextDrawSetSelectable(playerid, TradePTD[2], true);

	TradePTD[3] = CreatePlayerTextDraw(playerid, 262.999816, 355.511138, "Sterge");
	PlayerTextDrawLetterSize(playerid, TradePTD[3], 0.246665, 1.122962);
	PlayerTextDrawTextSize(playerid, TradePTD[3], 10.000000, 28.000000);
	PlayerTextDrawAlignment(playerid, TradePTD[3], 2);
	PlayerTextDrawColor(playerid, TradePTD[3], -16776961);
	PlayerTextDrawBoxColor(playerid, TradePTD[3], 255);
	PlayerTextDrawSetShadow(playerid, TradePTD[3], 0);
	PlayerTextDrawSetOutline(playerid, TradePTD[3], 1);
	PlayerTextDrawBackgroundColor(playerid, TradePTD[3], 47);
	PlayerTextDrawFont(playerid, TradePTD[3], 1);
	PlayerTextDrawSetProportional(playerid, TradePTD[3], 1);
	PlayerTextDrawSetShadow(playerid, TradePTD[3], 0);
	PlayerTextDrawSetSelectable(playerid, TradePTD[3], true);

	TradePTD[4] = CreatePlayerTextDraw(playerid, 199.666656, 139.392700, "nepregatitt");
	PlayerTextDrawLetterSize(playerid, TradePTD[4], 0.246665, 1.122962);
	PlayerTextDrawTextSize(playerid, TradePTD[4], 253.000000, 10.000000);
	PlayerTextDrawAlignment(playerid, TradePTD[4], 1);
	PlayerTextDrawColor(playerid, TradePTD[4], -1);
	PlayerTextDrawBoxColor(playerid, TradePTD[4], 255);
	PlayerTextDrawSetShadow(playerid, TradePTD[4], 0);
	PlayerTextDrawSetOutline(playerid, TradePTD[4], 1);
	PlayerTextDrawBackgroundColor(playerid, TradePTD[4], 47);
	PlayerTextDrawFont(playerid, TradePTD[4], 3);
	PlayerTextDrawSetProportional(playerid, TradePTD[4], 1);
	PlayerTextDrawSetShadow(playerid, TradePTD[4], 0);
	PlayerTextDrawSetSelectable(playerid, TradePTD[4], true);

	TradePTD[5] = CreatePlayerTextDraw(playerid, 390.333312, 139.807510, "nepregatitt");
	PlayerTextDrawLetterSize(playerid, TradePTD[5], 0.246665, 1.122962);
	PlayerTextDrawTextSize(playerid, TradePTD[5], 447.000000, 10.000000);
	PlayerTextDrawAlignment(playerid, TradePTD[5], 1);
	PlayerTextDrawColor(playerid, TradePTD[5], -1);
	PlayerTextDrawBoxColor(playerid, TradePTD[5], 255);
	PlayerTextDrawSetShadow(playerid, TradePTD[5], 0);
	PlayerTextDrawSetOutline(playerid, TradePTD[5], 1);
	PlayerTextDrawBackgroundColor(playerid, TradePTD[5], 47);
	PlayerTextDrawFont(playerid, TradePTD[5], 3);
	PlayerTextDrawSetProportional(playerid, TradePTD[5], 1);
	PlayerTextDrawSetShadow(playerid, TradePTD[5], 0);
	PlayerTextDrawSetSelectable(playerid, TradePTD[5], true);

	TradePTD[6] = CreatePlayerTextDraw(playerid, 305.333404, 114.918479, "01:00");
	PlayerTextDrawLetterSize(playerid, TradePTD[6], 0.298999, 1.405037);
	PlayerTextDrawAlignment(playerid, TradePTD[6], 1);
	PlayerTextDrawColor(playerid, TradePTD[6], -65281);
	PlayerTextDrawSetShadow(playerid, TradePTD[6], 1);
	PlayerTextDrawSetOutline(playerid, TradePTD[6], 0);
	PlayerTextDrawBackgroundColor(playerid, TradePTD[6], -234);
	PlayerTextDrawFont(playerid, TradePTD[6], 2);
	PlayerTextDrawSetProportional(playerid, TradePTD[6], 1);
	PlayerTextDrawSetShadow(playerid, TradePTD[6], 1);

	TradeTitle[0] = CreatePlayerTextDraw(playerid, 182.333343, 171.333297, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[0], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[0], 1);
	PlayerTextDrawColor(playerid, TradeTitle[0], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[0], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[0], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[0], 54);
	PlayerTextDrawFont(playerid, TradeTitle[0], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[0], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[0], 0);

	TradeTitle[1] = CreatePlayerTextDraw(playerid, 183.000015, 201.614837, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[1], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[1], 1);
	PlayerTextDrawColor(playerid, TradeTitle[1], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[1], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[1], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[1], 54);
	PlayerTextDrawFont(playerid, TradeTitle[1], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[1], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[1], 0);

	TradeTitle[2] = CreatePlayerTextDraw(playerid, 183.666671, 234.800003, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[2], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[2], 1);
	PlayerTextDrawColor(playerid, TradeTitle[2], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[2], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[2], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[2], 54);
	PlayerTextDrawFont(playerid, TradeTitle[2], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[2], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[2], 0);

	TradeTitle[3] = CreatePlayerTextDraw(playerid, 184.666641, 268.400115, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[3], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[3], 1);
	PlayerTextDrawColor(playerid, TradeTitle[3], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[3], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[3], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[3], 54);
	PlayerTextDrawFont(playerid, TradeTitle[3], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[3], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[3], 0);

	TradeTitle[4] = CreatePlayerTextDraw(playerid, 184.999984, 305.733520, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[4], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[4], 1);
	PlayerTextDrawColor(playerid, TradeTitle[4], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[4], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[4], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[4], 54);
	PlayerTextDrawFont(playerid, TradeTitle[4], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[4], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[4], 0);

	TradeTitle[5] = CreatePlayerTextDraw(playerid, 369.000030, 169.259399, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[5], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[5], 1);
	PlayerTextDrawColor(playerid, TradeTitle[5], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[5], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[5], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[5], 54);
	PlayerTextDrawFont(playerid, TradeTitle[5], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[5], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[5], 0);

	TradeTitle[6] = CreatePlayerTextDraw(playerid, 369.666778, 198.711242, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[6], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[6], 1);
	PlayerTextDrawColor(playerid, TradeTitle[6], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[6], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[6], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[6], 54);
	PlayerTextDrawFont(playerid, TradeTitle[6], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[6], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[6], 0);

	TradeTitle[7] = CreatePlayerTextDraw(playerid, 370.666717, 233.970474, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[7], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[7], 1);
	PlayerTextDrawColor(playerid, TradeTitle[7], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[7], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[7], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[7], 54);
	PlayerTextDrawFont(playerid, TradeTitle[7], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[7], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[7], 0);

	TradeTitle[8] = CreatePlayerTextDraw(playerid, 372.666809, 269.229766, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[8], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[8], 1);
	PlayerTextDrawColor(playerid, TradeTitle[8], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[8], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[8], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[8], 54);
	PlayerTextDrawFont(playerid, TradeTitle[8], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[8], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[8], 0);

	TradeTitle[9] = CreatePlayerTextDraw(playerid, 372.666809, 304.074249, "House: #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[9], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[9], 1);
	PlayerTextDrawColor(playerid, TradeTitle[9], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[9], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[9], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[9], 54);
	PlayerTextDrawFont(playerid, TradeTitle[9], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[9], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[9], 0);

	TradeIcon[0] = CreatePlayerTextDraw(playerid, 141.333419, 164.955612, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[0], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[0], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[0], 1);
	PlayerTextDrawColor(playerid, TradeIcon[0], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[0], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[0], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[0], -235);
	PlayerTextDrawFont(playerid, TradeIcon[0], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[0], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[0], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[0], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[0], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[1] = CreatePlayerTextDraw(playerid, 141.333419, 198.555618, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[1], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[1], 1);
	PlayerTextDrawColor(playerid, TradeIcon[1], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[1], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[1], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[1], -235);
	PlayerTextDrawFont(playerid, TradeIcon[1], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[1], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[1], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[1], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[1], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[2] = CreatePlayerTextDraw(playerid, 141.333419, 231.740814, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[2], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[2], 1);
	PlayerTextDrawColor(playerid, TradeIcon[2], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[2], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[2], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[2], -235);
	PlayerTextDrawFont(playerid, TradeIcon[2], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[2], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[2], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[2], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[2], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[3] = CreatePlayerTextDraw(playerid, 141.000091, 264.926025, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[3], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[3], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[3], 1);
	PlayerTextDrawColor(playerid, TradeIcon[3], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[3], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[3], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[3], -235);
	PlayerTextDrawFont(playerid, TradeIcon[3], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[3], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[3], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[3], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[3], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[4] = CreatePlayerTextDraw(playerid, 141.000091, 298.940673, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[4], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[4], 1);
	PlayerTextDrawColor(playerid, TradeIcon[4], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[4], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[4], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[4], -235);
	PlayerTextDrawFont(playerid, TradeIcon[4], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[4], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[4], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[4], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[4], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[5] = CreatePlayerTextDraw(playerid, 331.666748, 165.370376, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[5], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[5], 1);
	PlayerTextDrawColor(playerid, TradeIcon[5], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[5], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[5], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[5], -235);
	PlayerTextDrawFont(playerid, TradeIcon[5], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[5], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[5], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[5], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[5], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[6] = CreatePlayerTextDraw(playerid, 331.666778, 198.140762, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[6], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[6], 1);
	PlayerTextDrawColor(playerid, TradeIcon[6], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[6], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[6], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[6], -235);
	PlayerTextDrawFont(playerid, TradeIcon[6], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[6], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[6], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[6], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[6], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[7] = CreatePlayerTextDraw(playerid, 332.000061, 231.325973, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[7], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[7], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[7], 1);
	PlayerTextDrawColor(playerid, TradeIcon[7], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[7], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[7], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[7], -235);
	PlayerTextDrawFont(playerid, TradeIcon[7], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[7], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[7], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[7], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[7], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[8] = CreatePlayerTextDraw(playerid, 332.000091, 264.926025, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[8], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[8], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[8], 1);
	PlayerTextDrawColor(playerid, TradeIcon[8], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[8], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[8], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[8], -235);
	PlayerTextDrawFont(playerid, TradeIcon[8], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[8], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[8], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[8], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[8], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[9] = CreatePlayerTextDraw(playerid, 332.000122, 298.526245, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[9], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[9], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[9], 1);
	PlayerTextDrawColor(playerid, TradeIcon[9], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[9], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[9], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[9], -235);
	PlayerTextDrawFont(playerid, TradeIcon[9], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[9], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[9], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[9], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[9], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeTitle[0] = CreatePlayerTextDraw(playerid, 182.333343, 171.333297, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[0], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[0], 1);
	PlayerTextDrawColor(playerid, TradeTitle[0], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[0], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[0], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[0], 54);
	PlayerTextDrawFont(playerid, TradeTitle[0], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[0], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[0], 0);

	TradeTitle[1] = CreatePlayerTextDraw(playerid, 183.000015, 201.614837, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[1], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[1], 1);
	PlayerTextDrawColor(playerid, TradeTitle[1], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[1], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[1], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[1], 54);
	PlayerTextDrawFont(playerid, TradeTitle[1], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[1], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[1], 0);

	TradeTitle[2] = CreatePlayerTextDraw(playerid, 183.666671, 234.800003, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[2], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[2], 1);
	PlayerTextDrawColor(playerid, TradeTitle[2], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[2], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[2], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[2], 54);
	PlayerTextDrawFont(playerid, TradeTitle[2], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[2], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[2], 0);

	TradeTitle[3] = CreatePlayerTextDraw(playerid, 184.666641, 268.400115, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[3], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[3], 1);
	PlayerTextDrawColor(playerid, TradeTitle[3], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[3], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[3], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[3], 54);
	PlayerTextDrawFont(playerid, TradeTitle[3], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[3], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[3], 0);

	TradeTitle[4] = CreatePlayerTextDraw(playerid, 184.999984, 305.733520, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[4], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[4], 1);
	PlayerTextDrawColor(playerid, TradeTitle[4], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[4], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[4], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[4], 54);
	PlayerTextDrawFont(playerid, TradeTitle[4], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[4], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[4], 0);

	TradeTitle[5] = CreatePlayerTextDraw(playerid, 369.000030, 169.259399, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[5], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[5], 1);
	PlayerTextDrawColor(playerid, TradeTitle[5], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[5], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[5], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[5], 54);
	PlayerTextDrawFont(playerid, TradeTitle[5], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[5], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[5], 0);

	TradeTitle[6] = CreatePlayerTextDraw(playerid, 369.666778, 198.711242, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[6], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[6], 1);
	PlayerTextDrawColor(playerid, TradeTitle[6], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[6], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[6], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[6], 54);
	PlayerTextDrawFont(playerid, TradeTitle[6], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[6], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[6], 0);

	TradeTitle[7] = CreatePlayerTextDraw(playerid, 370.666717, 233.970474, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[7], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[7], 1);
	PlayerTextDrawColor(playerid, TradeTitle[7], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[7], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[7], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[7], 54);
	PlayerTextDrawFont(playerid, TradeTitle[7], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[7], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[7], 0);

	TradeTitle[8] = CreatePlayerTextDraw(playerid, 372.666809, 269.229766, "House #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[8], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[8], 1);
	PlayerTextDrawColor(playerid, TradeTitle[8], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[8], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[8], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[8], 54);
	PlayerTextDrawFont(playerid, TradeTitle[8], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[8], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[8], 0);

	TradeTitle[9] = CreatePlayerTextDraw(playerid, 372.666809, 304.074249, "House: #5");
	PlayerTextDrawLetterSize(playerid, TradeTitle[9], 0.225666, 0.965332);
	PlayerTextDrawAlignment(playerid, TradeTitle[9], 1);
	PlayerTextDrawColor(playerid, TradeTitle[9], -1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[9], 0);
	PlayerTextDrawSetOutline(playerid, TradeTitle[9], 1);
	PlayerTextDrawBackgroundColor(playerid, TradeTitle[9], 54);
	PlayerTextDrawFont(playerid, TradeTitle[9], 1);
	PlayerTextDrawSetProportional(playerid, TradeTitle[9], 1);
	PlayerTextDrawSetShadow(playerid, TradeTitle[9], 0);

	TradeIcon[0] = CreatePlayerTextDraw(playerid, 141.333419, 164.955612, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[0], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[0], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[0], 1);
	PlayerTextDrawColor(playerid, TradeIcon[0], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[0], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[0], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[0], -235);
	PlayerTextDrawFont(playerid, TradeIcon[0], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[0], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[0], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[0], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[0], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[1] = CreatePlayerTextDraw(playerid, 141.333419, 198.555618, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[1], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[1], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[1], 1);
	PlayerTextDrawColor(playerid, TradeIcon[1], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[1], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[1], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[1], -235);
	PlayerTextDrawFont(playerid, TradeIcon[1], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[1], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[1], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[1], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[1], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[2] = CreatePlayerTextDraw(playerid, 141.333419, 231.740814, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[2], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[2], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[2], 1);
	PlayerTextDrawColor(playerid, TradeIcon[2], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[2], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[2], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[2], -235);
	PlayerTextDrawFont(playerid, TradeIcon[2], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[2], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[2], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[2], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[2], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[3] = CreatePlayerTextDraw(playerid, 141.000091, 264.926025, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[3], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[3], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[3], 1);
	PlayerTextDrawColor(playerid, TradeIcon[3], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[3], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[3], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[3], -235);
	PlayerTextDrawFont(playerid, TradeIcon[3], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[3], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[3], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[3], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[3], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[4] = CreatePlayerTextDraw(playerid, 141.000091, 298.940673, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[4], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[4], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[4], 1);
	PlayerTextDrawColor(playerid, TradeIcon[4], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[4], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[4], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[4], -235);
	PlayerTextDrawFont(playerid, TradeIcon[4], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[4], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[4], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[4], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[4], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[5] = CreatePlayerTextDraw(playerid, 331.666748, 165.370376, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[5], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[5], 1);
	PlayerTextDrawColor(playerid, TradeIcon[5], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[5], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[5], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[5], -235);
	PlayerTextDrawFont(playerid, TradeIcon[5], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[5], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[5], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[5], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[5], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[6] = CreatePlayerTextDraw(playerid, 331.666778, 198.140762, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[6], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[6], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[6], 1);
	PlayerTextDrawColor(playerid, TradeIcon[6], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[6], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[6], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[6], -235);
	PlayerTextDrawFont(playerid, TradeIcon[6], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[6], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[6], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[6], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[6], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[7] = CreatePlayerTextDraw(playerid, 332.000061, 231.325973, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[7], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[7], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[7], 1);
	PlayerTextDrawColor(playerid, TradeIcon[7], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[7], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[7], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[7], -235);
	PlayerTextDrawFont(playerid, TradeIcon[7], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[7], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[7], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[7], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[7], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[8] = CreatePlayerTextDraw(playerid, 332.000091, 264.926025, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[8], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[8], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[8], 1);
	PlayerTextDrawColor(playerid, TradeIcon[8], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[8], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[8], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[8], -235);
	PlayerTextDrawFont(playerid, TradeIcon[8], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[8], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[8], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[8], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[8], 0.000000, 0.000000, 348.000000, 0.849843);

	TradeIcon[9] = CreatePlayerTextDraw(playerid, 332.000122, 298.526245, "");
	PlayerTextDrawLetterSize(playerid, TradeIcon[9], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, TradeIcon[9], 29.000000, 31.000000);
	PlayerTextDrawAlignment(playerid, TradeIcon[9], 1);
	PlayerTextDrawColor(playerid, TradeIcon[9], -1);
	PlayerTextDrawSetShadow(playerid, TradeIcon[9], 0);
	PlayerTextDrawSetOutline(playerid, TradeIcon[9], 0);
	PlayerTextDrawBackgroundColor(playerid, TradeIcon[9], -235);
	PlayerTextDrawFont(playerid, TradeIcon[9], 5);
	PlayerTextDrawSetProportional(playerid, TradeIcon[9], 0);
	PlayerTextDrawSetShadow(playerid, TradeIcon[9], 0);
	PlayerTextDrawSetPreviewModel(playerid, TradeIcon[9], 19523);
	PlayerTextDrawSetPreviewRot(playerid, TradeIcon[9], 0.000000, 0.000000, 348.000000, 0.849843);
	
	SpecTD = CreatePlayerTextDraw(playerid, 215.666778, 343.481872, "~y~s (d)~n~~w~~h~Health: ~r~.1f  ~w~~h~Armour: ~r~.1f~n~~w~~h~Wanted: ~r~s~w~~h~  ~w~~h~Jail: ~r~s~n~~w~~h~Vehicle ID: ~r~d");
	PlayerTextDrawLetterSize(playerid, SpecTD, 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, SpecTD, 1);
	PlayerTextDrawColor(playerid, SpecTD, -1);
	PlayerTextDrawSetShadow(playerid, SpecTD, 0);
	PlayerTextDrawSetOutline(playerid, SpecTD, 1);
	PlayerTextDrawBackgroundColor(playerid, SpecTD, 255);
	PlayerTextDrawFont(playerid, SpecTD, 2);
	PlayerTextDrawSetProportional(playerid, SpecTD, 1);
	PlayerTextDrawSetShadow(playerid, SpecTD, 0);

	PaintTD = CreatePlayerTextDraw(playerid, 552.333740, 377.481536, "Timp paintball: 12:00~n~Statistici: 5 ucideri si 5 decese.~n~Cel mai bun: (scor: 1)~n~Cel mai slab: GoForGame (scor: -1)");
	PlayerTextDrawLetterSize(playerid, PaintTD, 0.175666, 0.849184);
	PlayerTextDrawTextSize(playerid, PaintTD, 741.333190, 149.333297);
	PlayerTextDrawAlignment(playerid, PaintTD, 2);
	PlayerTextDrawColor(playerid, PaintTD, -1);
	PlayerTextDrawUseBox(playerid, PaintTD, true);
	PlayerTextDrawBoxColor(playerid, PaintTD, 98);
	PlayerTextDrawSetShadow(playerid, PaintTD, 0);
	PlayerTextDrawSetOutline(playerid, PaintTD, 1);
	PlayerTextDrawBackgroundColor(playerid, PaintTD, 89);
	PlayerTextDrawFont(playerid, PaintTD, 1);
	PlayerTextDrawSetProportional(playerid, PaintTD, 1);
	
	HudTD[0] = CreatePlayerTextDraw(playerid, 87.999992, 269.644470, "Level: 5-6 (0/5 RP)");
	PlayerTextDrawLetterSize(playerid, HudTD[0], 0.176666, 0.865778);
	PlayerTextDrawAlignment(playerid, HudTD[0], 2);
	PlayerTextDrawColor(playerid, HudTD[0], -1);
	PlayerTextDrawSetShadow(playerid, HudTD[0], 1);
	PlayerTextDrawSetOutline(playerid, HudTD[0], 1);
	PlayerTextDrawBackgroundColor(playerid, HudTD[0], 118);
	PlayerTextDrawFont(playerid, HudTD[0], 1);
	PlayerTextDrawSetProportional(playerid, HudTD[0], 1);
	PlayerTextDrawSetShadow(playerid, HudTD[0], 1);

	HudTD[1] = CreatePlayerTextDraw(playerid, 88.000007, 304.074096, "Raport: 1-5 (0/2)");
	PlayerTextDrawLetterSize(playerid, HudTD[1], 0.176666, 0.865778);
	PlayerTextDrawAlignment(playerid, HudTD[1], 2);
	PlayerTextDrawColor(playerid, HudTD[1], -1);
	PlayerTextDrawSetShadow(playerid, HudTD[1], 1);
	PlayerTextDrawSetOutline(playerid, HudTD[1], 1);
	PlayerTextDrawBackgroundColor(playerid, HudTD[1], 118);
	PlayerTextDrawFont(playerid, HudTD[1], 1);
	PlayerTextDrawSetProportional(playerid, HudTD[1], 1);
	PlayerTextDrawSetShadow(playerid, HudTD[1], 1);

	CleoTD[playerid][0] = CreatePlayerTextDraw(playerid, 3.000005, 431.407684, "100");
	PlayerTextDrawLetterSize(playerid, CleoTD[playerid][0], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, CleoTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, CleoTD[playerid][0], -65281);
	PlayerTextDrawSetShadow(playerid, CleoTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, CleoTD[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, CleoTD[playerid][0], 51);
	PlayerTextDrawFont(playerid, CleoTD[playerid][0], 3);
	PlayerTextDrawSetProportional(playerid, CleoTD[playerid][0], 1);

	CleoTD[playerid][1] = CreatePlayerTextDraw(playerid, 576.999023, 65.711311, "100");
	PlayerTextDrawLetterSize(playerid, CleoTD[playerid][1], 0.302999, 1.006815);
	PlayerTextDrawAlignment(playerid, CleoTD[playerid][1], 2);
	PlayerTextDrawColor(playerid, CleoTD[playerid][1], -1);
	PlayerTextDrawSetShadow(playerid, CleoTD[playerid][1], 0);
	PlayerTextDrawSetOutline(playerid, CleoTD[playerid][1], 1);
	PlayerTextDrawBackgroundColor(playerid, CleoTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, CleoTD[playerid][1], 1);
	PlayerTextDrawSetProportional(playerid, CleoTD[playerid][1], 1);

	CleoTD[playerid][2] = CreatePlayerTextDraw(playerid, 576.332458, 45.140953, "100");
	PlayerTextDrawLetterSize(playerid, CleoTD[playerid][2], 0.302999, 1.006815);
	PlayerTextDrawAlignment(playerid, CleoTD[playerid][2], 2);
	PlayerTextDrawColor(playerid, CleoTD[playerid][2], -1);
	PlayerTextDrawSetShadow(playerid, CleoTD[playerid][2], 0);
	PlayerTextDrawSetOutline(playerid, CleoTD[playerid][2], 1);
	PlayerTextDrawBackgroundColor(playerid, CleoTD[playerid][2], 255);
	PlayerTextDrawFont(playerid, CleoTD[playerid][2], 1);
	PlayerTextDrawSetProportional(playerid, CleoTD[playerid][2], 1);
	
	RentTD = CreatePlayerTextDraw(playerid, 33.265197, 305.083160, ""); // fare
	PlayerTextDrawLetterSize(playerid, RentTD, 0.321155, 1.308333);
	PlayerTextDrawAlignment(playerid, RentTD, 1);
	PlayerTextDrawColor(playerid, RentTD, -1);
	PlayerTextDrawSetShadow(playerid, RentTD, 0);
	PlayerTextDrawSetOutline(playerid, RentTD, 1);
	PlayerTextDrawBackgroundColor(playerid, RentTD, 255);
	PlayerTextDrawFont(playerid, RentTD, 3);
	PlayerTextDrawSetProportional(playerid, RentTD, 1);
	
	BGunTD[6] = CreatePlayerTextDraw(playerid, 431.165466, 338.666687, "usebox");
	PlayerTextDrawLetterSize(playerid, BGunTD[6], 0.000000, 7.655553);
	PlayerTextDrawTextSize(playerid, BGunTD[6], 211.177169, 0.000000);
	PlayerTextDrawAlignment(playerid, BGunTD[6], 1);
	PlayerTextDrawColor(playerid, BGunTD[6], 0);
	PlayerTextDrawUseBox(playerid, BGunTD[6], true);
	PlayerTextDrawBoxColor(playerid, BGunTD[6], 102);
	PlayerTextDrawSetShadow(playerid, BGunTD[6], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[6], 0);
	PlayerTextDrawFont(playerid, BGunTD[6], 0);

	BGunTD[7] = CreatePlayerTextDraw(playerid, 427.885803, 341.000000, "usebox");
	PlayerTextDrawLetterSize(playerid, BGunTD[7], 0.000000, 7.007409);
	PlayerTextDrawTextSize(playerid, BGunTD[7], 213.988296, 0.000000);
	PlayerTextDrawAlignment(playerid, BGunTD[7], 1);
	PlayerTextDrawColor(playerid, BGunTD[7], 0);
	PlayerTextDrawUseBox(playerid, BGunTD[7], true);
	PlayerTextDrawBoxColor(playerid, BGunTD[7], 102);
	PlayerTextDrawSetShadow(playerid, BGunTD[7], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[7], 0);
	PlayerTextDrawFont(playerid, BGunTD[7], 0);

	BGunTD[0] = CreatePlayerTextDraw(playerid, 319.531646, 345.333312, "Desert Eagle");
	PlayerTextDrawLetterSize(playerid, BGunTD[0], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, BGunTD[0], 2);
	PlayerTextDrawColor(playerid, BGunTD[0], -1);
	PlayerTextDrawSetShadow(playerid, BGunTD[0], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[0], 1);
	PlayerTextDrawBackgroundColor(playerid, BGunTD[0], 255);
	PlayerTextDrawFont(playerid, BGunTD[0], 3);
	PlayerTextDrawSetProportional(playerid, BGunTD[0], 1);

	BGunTD[1] = CreatePlayerTextDraw(playerid, 316.720397, 363.416748, "~g~$5.000");
	PlayerTextDrawLetterSize(playerid, BGunTD[1], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, BGunTD[1], 2);
	PlayerTextDrawColor(playerid, BGunTD[1], -1);
	PlayerTextDrawSetShadow(playerid, BGunTD[1], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[1], 1);
	PlayerTextDrawBackgroundColor(playerid, BGunTD[1], 255);
	PlayerTextDrawFont(playerid, BGunTD[1], 3);
	PlayerTextDrawSetProportional(playerid, BGunTD[1], 1);

	BGunTD[2] = CreatePlayerTextDraw(playerid, 224.016357, 358.583312, "LD_BEAT:left");
	PlayerTextDrawLetterSize(playerid, BGunTD[2], -0.173352, -1.954166);
	PlayerTextDrawTextSize(playerid, BGunTD[2], 25.768692, 26.833332);
	PlayerTextDrawAlignment(playerid, BGunTD[2], 1);
	PlayerTextDrawColor(playerid, BGunTD[2], -1);
	PlayerTextDrawUseBox(playerid, BGunTD[2], true);
	PlayerTextDrawBoxColor(playerid, BGunTD[2], 255);
	PlayerTextDrawSetShadow(playerid, BGunTD[2], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[2], 0);
	PlayerTextDrawFont(playerid, BGunTD[2], 4);
	PlayerTextDrawSetSelectable(playerid, BGunTD[2], true);

	BGunTD[3] = CreatePlayerTextDraw(playerid, 303.133392, 387.333251, " ~y~Buy");
	PlayerTextDrawLetterSize(playerid, BGunTD[3], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, BGunTD[3], 1);
	PlayerTextDrawColor(playerid, BGunTD[3], -1);
	PlayerTextDrawSetShadow(playerid, BGunTD[3], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[3], 1);
	PlayerTextDrawBackgroundColor(playerid, BGunTD[3], 255);
	PlayerTextDrawFont(playerid, BGunTD[3], 3);
	PlayerTextDrawSetProportional(playerid, BGunTD[3], 1);
	PlayerTextDrawSetSelectable(playerid, BGunTD[3], true);

	BGunTD[4] = CreatePlayerTextDraw(playerid, 389.341369, 357.583282, "LD_BEAT:right");
	PlayerTextDrawLetterSize(playerid, BGunTD[4], -0.173352, -1.954166);
	PlayerTextDrawTextSize(playerid, BGunTD[4], 25.768692, 26.833332);
	PlayerTextDrawAlignment(playerid, BGunTD[4], 1);
	PlayerTextDrawColor(playerid, BGunTD[4], -1);
	PlayerTextDrawUseBox(playerid, BGunTD[4], true);
	PlayerTextDrawBoxColor(playerid, BGunTD[4], 255);
	PlayerTextDrawSetShadow(playerid, BGunTD[4], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[4], 0);
	PlayerTextDrawFont(playerid, BGunTD[4], 4);
	PlayerTextDrawSetSelectable(playerid, BGunTD[4], true);

	BGunTD[5] = CreatePlayerTextDraw(playerid, 418.389770, 328.999969, "LD_BEAT:cross");
	PlayerTextDrawLetterSize(playerid, BGunTD[5], 0.000000, 0.000000);
	PlayerTextDrawTextSize(playerid, BGunTD[5], 16.866790, 16.333309);
	PlayerTextDrawAlignment(playerid, BGunTD[5], 1);
	PlayerTextDrawColor(playerid, BGunTD[5], -1);
	PlayerTextDrawSetShadow(playerid, BGunTD[5], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[5], 0);
	PlayerTextDrawFont(playerid, BGunTD[5], 4);
	PlayerTextDrawSetSelectable(playerid, BGunTD[5], true);

	BGunTD[8] = CreatePlayerTextDraw(playerid, 284.861236, 323.750122, "Buy Gun");
	PlayerTextDrawLetterSize(playerid, BGunTD[8], 0.607423, 1.920832);
	PlayerTextDrawAlignment(playerid, BGunTD[8], 1);
	PlayerTextDrawColor(playerid, BGunTD[8], -1);
	PlayerTextDrawSetShadow(playerid, BGunTD[8], 0);
	PlayerTextDrawSetOutline(playerid, BGunTD[8], 1);
	PlayerTextDrawBackgroundColor(playerid, BGunTD[8], 255);
	PlayerTextDrawFont(playerid, BGunTD[8], 0);
	PlayerTextDrawSetProportional(playerid, BGunTD[8], 1);
	
	UndercoverTD = CreatePlayerTextDraw(playerid, 317.333343, 413.170288, "~r~you are undercover!");
	PlayerTextDrawLetterSize(playerid, UndercoverTD, 0.382999, 1.475555);
	PlayerTextDrawAlignment(playerid, UndercoverTD, 2);
	PlayerTextDrawColor(playerid, UndercoverTD, -1);
	PlayerTextDrawSetShadow(playerid, UndercoverTD, 0);
	PlayerTextDrawSetOutline(playerid, UndercoverTD, 1);
	PlayerTextDrawBackgroundColor(playerid, UndercoverTD, 68);
	PlayerTextDrawFont(playerid, UndercoverTD, 3);
	PlayerTextDrawSetProportional(playerid, UndercoverTD, 1);
	PlayerTextDrawSetShadow(playerid, UndercoverTD, 0);
	
	FindTD = CreatePlayerTextDraw(playerid, 319.666595, 348.874298, "Name: ~r~ (60)~w~~n~Distance: ~r~1000.2m (LS)");
	PlayerTextDrawLetterSize(playerid, FindTD, 0.260332, 1.687110);
	PlayerTextDrawAlignment(playerid, FindTD, 2);
	PlayerTextDrawColor(playerid, FindTD, -1);
	PlayerTextDrawSetShadow(playerid, FindTD, 0);
	PlayerTextDrawSetOutline(playerid, FindTD, 1);
	PlayerTextDrawBackgroundColor(playerid, FindTD, 114);
	PlayerTextDrawFont(playerid, FindTD, 2);
	PlayerTextDrawSetProportional(playerid, FindTD, 1);
	PlayerTextDrawSetShadow(playerid, FindTD, 0);

	RPTextdraw[0] = CreatePlayerTextDraw(playerid, 265.651672, 417.666900, "256");
	PlayerTextDrawLetterSize(playerid, RPTextdraw[0], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, RPTextdraw[0], 3);
	PlayerTextDrawColor(playerid, RPTextdraw[0], -1);
	PlayerTextDrawSetShadow(playerid, RPTextdraw[0], 0);
	PlayerTextDrawSetOutline(playerid, RPTextdraw[0], 2);
	PlayerTextDrawBackgroundColor(playerid, RPTextdraw[0], 255);
	PlayerTextDrawFont(playerid, RPTextdraw[0], 3);
	PlayerTextDrawSetProportional(playerid, RPTextdraw[0], 1);

	RPTextdraw[1] = CreatePlayerTextDraw(playerid, 351.453491, 417.500244, "257");
	PlayerTextDrawLetterSize(playerid, RPTextdraw[1], 0.449999, 1.600000);
	PlayerTextDrawAlignment(playerid, RPTextdraw[1], 1);
	PlayerTextDrawColor(playerid, RPTextdraw[1], -1);
	PlayerTextDrawSetShadow(playerid, RPTextdraw[1], 0);
	PlayerTextDrawSetOutline(playerid, RPTextdraw[1], 2);
	PlayerTextDrawBackgroundColor(playerid, RPTextdraw[1], 255);
	PlayerTextDrawFont(playerid, RPTextdraw[1], 3);
	PlayerTextDrawSetProportional(playerid, RPTextdraw[1], 1);
	PlayerTextDrawSetSelectable(playerid, RPTextdraw[1], true);

	RPTextdraw[2] = CreatePlayerTextDraw(playerid, 308.287384, 432.249786, "RP: 350/2500");
	PlayerTextDrawLetterSize(playerid, RPTextdraw[2], 0.239631, 0.999166);
	PlayerTextDrawAlignment(playerid, RPTextdraw[2], 2);
	PlayerTextDrawColor(playerid, RPTextdraw[2], -1);
	PlayerTextDrawSetShadow(playerid, RPTextdraw[2], 0);
	PlayerTextDrawSetOutline(playerid, RPTextdraw[2], 1);
	PlayerTextDrawBackgroundColor(playerid, RPTextdraw[2], 255);
	PlayerTextDrawFont(playerid, RPTextdraw[2], 2);
	PlayerTextDrawSetProportional(playerid, RPTextdraw[2], 1);

	FareTD[0] = CreatePlayerTextDraw(playerid, 158.485656, 213.250030, "usebox");
	PlayerTextDrawLetterSize(playerid, FareTD[0], 0.000000, 9.275930);
	PlayerTextDrawTextSize(playerid, FareTD[0], 28.922229, 0.000000);
	PlayerTextDrawAlignment(playerid, FareTD[0], 1);
	PlayerTextDrawColor(playerid, FareTD[0], 0);
	PlayerTextDrawUseBox(playerid, FareTD[0], true);
	PlayerTextDrawBoxColor(playerid, FareTD[0], 164);
	PlayerTextDrawSetShadow(playerid, FareTD[0], 0);
	PlayerTextDrawSetOutline(playerid, FareTD[0], 0);
	PlayerTextDrawBackgroundColor(playerid, FareTD[0], 511);
	PlayerTextDrawFont(playerid, FareTD[0], 0);

	FareTD[1] = CreatePlayerTextDraw(playerid, 46.852077, 226.916625, "Compania Taxi");
	PlayerTextDrawLetterSize(playerid, FareTD[1], 0.375504, 1.366666);
	PlayerTextDrawAlignment(playerid, FareTD[1], 1);
	PlayerTextDrawColor(playerid, FareTD[1], -65281);
	PlayerTextDrawSetShadow(playerid, FareTD[1], 0);
	PlayerTextDrawSetOutline(playerid, FareTD[1], 1);
	PlayerTextDrawBackgroundColor(playerid, FareTD[1], 255);
	PlayerTextDrawFont(playerid, FareTD[1], 1);
	PlayerTextDrawSetProportional(playerid, FareTD[1], 1);

	FareTD[2] = CreatePlayerTextDraw(playerid, 40.824260, 248.916656, "Distanta: 0.0 Km~n~Tarif: ~g~20~w~~n~Costul cursei: ~g~20");
	PlayerTextDrawLetterSize(playerid, FareTD[2], 0.290234, 1.121666);
	PlayerTextDrawAlignment(playerid, FareTD[2], 1);
	PlayerTextDrawColor(playerid, FareTD[2], -1);
	PlayerTextDrawSetShadow(playerid, FareTD[2], 0);
	PlayerTextDrawSetOutline(playerid, FareTD[2], 1);
	PlayerTextDrawBackgroundColor(playerid, FareTD[2], 255);
	PlayerTextDrawFont(playerid, FareTD[2], 1);
	PlayerTextDrawSetProportional(playerid, FareTD[2], 1);

	WantedTD[playerid] = CreatePlayerTextDraw(playerid, 554.999755, 124.044372, "WANTED SCADE IN~N~~r~5 MINUTE");
	PlayerTextDrawLetterSize(playerid, WantedTD[playerid], 0.233000, 1.533630);
	PlayerTextDrawAlignment(playerid, WantedTD[playerid], 2);
	PlayerTextDrawColor(playerid, WantedTD[playerid], -1);
	PlayerTextDrawSetShadow(playerid, WantedTD[playerid], 0);
	PlayerTextDrawSetOutline(playerid, WantedTD[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, WantedTD[playerid], 70);
	PlayerTextDrawFont(playerid, WantedTD[playerid], 2);
	PlayerTextDrawSetProportional(playerid, WantedTD[playerid], 1);
	PlayerTextDrawSetShadow(playerid, WantedTD[playerid], 0);
	
	FriendsTD = CreatePlayerTextDraw(playerid, 91.666687, 271.303710, "Prietenul tau, s-a conectat!");
	PlayerTextDrawLetterSize(playerid, FriendsTD, 0.243999, 0.940444);
	PlayerTextDrawTextSize(playerid, FriendsTD, 0.000000, 124.000000);
	PlayerTextDrawAlignment(playerid, FriendsTD, 2);
	PlayerTextDrawColor(playerid, FriendsTD, -1);
	PlayerTextDrawUseBox(playerid, FriendsTD, 1);
	PlayerTextDrawBoxColor(playerid, FriendsTD, 255);
	PlayerTextDrawSetShadow(playerid, FriendsTD, 0);
	PlayerTextDrawSetOutline(playerid, FriendsTD, 0);
	PlayerTextDrawBackgroundColor(playerid, FriendsTD, 255);
	PlayerTextDrawFont(playerid, FriendsTD, 1);
	PlayerTextDrawSetProportional(playerid, FriendsTD, 1);
	PlayerTextDrawSetShadow(playerid, FriendsTD, 0);
	
	TradeTD[0] = TextDrawCreate(132.666702, 131.925888, "box");
	TextDrawLetterSize(TradeTD[0], 0.000000, 27.133333);
	TextDrawTextSize(TradeTD[0], 512.000000, 0.000000);
	TextDrawAlignment(TradeTD[0], 1);
	TextDrawColor(TradeTD[0], -1);
	TextDrawUseBox(TradeTD[0], 1);
	TextDrawBoxColor(TradeTD[0], 155);
	TextDrawSetShadow(TradeTD[0], 0);
	TextDrawSetOutline(TradeTD[0], 0);
	TextDrawBackgroundColor(TradeTD[0], 255);
	TextDrawFont(TradeTD[0], 1);
	TextDrawSetProportional(TradeTD[0], 1);
	TextDrawSetShadow(TradeTD[0], 0);

	TradeTD[1] = TextDrawCreate(132.666687, 114.918548, "box");
	TextDrawLetterSize(TradeTD[1], 0.000000, 1.566666);
	TextDrawTextSize(TradeTD[1], 512.000000, 0.000000);
	TextDrawAlignment(TradeTD[1], 1);
	TextDrawColor(TradeTD[1], -1);
	TextDrawUseBox(TradeTD[1], 1);
	TextDrawBoxColor(TradeTD[1], 255);
	TextDrawSetShadow(TradeTD[1], 0);
	TextDrawSetOutline(TradeTD[1], 0);
	TextDrawBackgroundColor(TradeTD[1], 255);
	TextDrawFont(TradeTD[1], 1);
	TextDrawSetProportional(TradeTD[1], 0);
	TextDrawSetShadow(TradeTD[1], 0);

	TradeTD[2] = TextDrawCreate(319.999877, 117.822219, "box");
	TextDrawLetterSize(TradeTD[2], 0.000000, 28.699993);
	TextDrawTextSize(TradeTD[2], 318.000000, 0.000000);
	TextDrawAlignment(TradeTD[2], 1);
	TextDrawColor(TradeTD[2], -1);
	TextDrawUseBox(TradeTD[2], 1);
	TextDrawBoxColor(TradeTD[2], 255);
	TextDrawSetShadow(TradeTD[2], 0);
	TextDrawSetOutline(TradeTD[2], 0);
	TextDrawBackgroundColor(TradeTD[2], 255);
	TextDrawFont(TradeTD[2], 1);
	TextDrawSetProportional(TradeTD[2], 1);
	TextDrawSetShadow(TradeTD[2], 0);

	TradeTD[3] = TextDrawCreate(140.666809, 155.155532, "box");
	TextDrawLetterSize(TradeTD[3], 0.000000, 21.633325);
	TextDrawTextSize(TradeTD[3], 310.000000, 0.000000);
	TextDrawAlignment(TradeTD[3], 1);
	TextDrawColor(TradeTD[3], -1);
	TextDrawUseBox(TradeTD[3], 1);
	TextDrawBoxColor(TradeTD[3], -250);
	TextDrawSetShadow(TradeTD[3], 0);
	TextDrawSetOutline(TradeTD[3], 0);
	TextDrawBackgroundColor(TradeTD[3], 255);
	TextDrawFont(TradeTD[3], 1);
	TextDrawSetProportional(TradeTD[3], 1);
	TextDrawSetShadow(TradeTD[3], 0);

	TradeTD[4] = TextDrawCreate(329.333557, 154.325988, "box");
	TextDrawLetterSize(TradeTD[4], 0.000000, 21.733324);
	TextDrawTextSize(TradeTD[4], 504.000000, 0.000000);
	TextDrawAlignment(TradeTD[4], 1);
	TextDrawColor(TradeTD[4], -1);
	TextDrawUseBox(TradeTD[4], 1);
	TextDrawBoxColor(TradeTD[4], -252);
	TextDrawSetShadow(TradeTD[4], 0);
	TextDrawSetOutline(TradeTD[4], 0);
	TextDrawBackgroundColor(TradeTD[4], 255);
	TextDrawFont(TradeTD[4], 1);
	TextDrawSetProportional(TradeTD[4], 1);
	TextDrawSetShadow(TradeTD[4], 0);

	TradeTD[5] = TextDrawCreate(140.666671, 352.607391, "box");
	TextDrawLetterSize(TradeTD[5], 0.000000, 1.733332);
	TextDrawTextSize(TradeTD[5], 310.000000, 0.000000);
	TextDrawAlignment(TradeTD[5], 1);
	TextDrawColor(TradeTD[5], -1);
	TextDrawUseBox(TradeTD[5], 1);
	TextDrawBoxColor(TradeTD[5], -251);
	TextDrawSetShadow(TradeTD[5], 0);
	TextDrawSetOutline(TradeTD[5], 0);
	TextDrawBackgroundColor(TradeTD[5], 255);
	TextDrawFont(TradeTD[5], 1);
	TextDrawSetProportional(TradeTD[5], 1);
	TextDrawSetShadow(TradeTD[5], 0);

	TradeTD[6] = TextDrawCreate(140.666656, 136.903656, "box");
	TextDrawLetterSize(TradeTD[6], 0.000000, 1.733332);
	TextDrawTextSize(TradeTD[6], 310.000000, 0.000000);
	TextDrawAlignment(TradeTD[6], 1);
	TextDrawColor(TradeTD[6], -1);
	TextDrawUseBox(TradeTD[6], 1);
	TextDrawBoxColor(TradeTD[6], -251);
	TextDrawSetShadow(TradeTD[6], 0);
	TextDrawSetOutline(TradeTD[6], 0);
	TextDrawBackgroundColor(TradeTD[6], 255);
	TextDrawFont(TradeTD[6], 1);
	TextDrawSetProportional(TradeTD[6], 1);
	TextDrawSetShadow(TradeTD[6], 0);

	TradeTD[7] = TextDrawCreate(329.333190, 352.607269, "box");
	TextDrawLetterSize(TradeTD[7], 0.000000, 1.666666);
	TextDrawTextSize(TradeTD[7], 504.000000, 0.000000);
	TextDrawAlignment(TradeTD[7], 1);
	TextDrawColor(TradeTD[7], -1);
	TextDrawUseBox(TradeTD[7], 1);
	TextDrawBoxColor(TradeTD[7], -251);
	TextDrawSetShadow(TradeTD[7], 0);
	TextDrawSetOutline(TradeTD[7], 0);
	TextDrawBackgroundColor(TradeTD[7], 255);
	TextDrawFont(TradeTD[7], 1);
	TextDrawSetProportional(TradeTD[7], 1);
	TextDrawSetShadow(TradeTD[7], 0);

	TradeTD[8] = TextDrawCreate(328.666473, 137.733154, "box");
	TextDrawLetterSize(TradeTD[8], 0.000000, 1.533332);
	TextDrawTextSize(TradeTD[8], 504.000000, 0.000000);
	TextDrawAlignment(TradeTD[8], 1);
	TextDrawColor(TradeTD[8], -1);
	TextDrawUseBox(TradeTD[8], 1);
	TextDrawBoxColor(TradeTD[8], -251);
	TextDrawSetShadow(TradeTD[8], 0);
	TextDrawSetOutline(TradeTD[8], 0);
	TextDrawBackgroundColor(TradeTD[8], 255);
	TextDrawFont(TradeTD[8], 1);
	TextDrawSetProportional(TradeTD[8], 1);
	TextDrawSetShadow(TradeTD[8], 0);

	TradeTD[9] = TextDrawCreate(382.000183, 355.096252, "Adauga");
	TextDrawLetterSize(TradeTD[9], 0.246665, 1.122962);
	TextDrawTextSize(TradeTD[9], 10.000000, 37.000000);
	TextDrawAlignment(TradeTD[9], 2);
	TextDrawColor(TradeTD[9], -65281);
	TextDrawBoxColor(TradeTD[9], 255);
	TextDrawSetShadow(TradeTD[9], 0);
	TextDrawSetOutline(TradeTD[9], 1);
	TextDrawBackgroundColor(TradeTD[9], 47);
	TextDrawFont(TradeTD[9], 1);
	TextDrawSetProportional(TradeTD[9], 1);
	TextDrawSetShadow(TradeTD[9], 0);
	TextDrawSetSelectable(TradeTD[9], true);

	TradeTD[10] = TextDrawCreate(455.666687, 355.096374, "Sterge");
	TextDrawLetterSize(TradeTD[10], 0.246665, 1.122962);
	TextDrawTextSize(TradeTD[10], 10.000000, 31.000000);
	TextDrawAlignment(TradeTD[10], 2);
	TextDrawColor(TradeTD[10], -16776961);
	TextDrawBoxColor(TradeTD[10], 255);
	TextDrawSetShadow(TradeTD[10], 0);
	TextDrawSetOutline(TradeTD[10], 1);
	TextDrawBackgroundColor(TradeTD[10], 47);
	TextDrawFont(TradeTD[10], 1);
	TextDrawSetProportional(TradeTD[10], 1);
	TextDrawSetShadow(TradeTD[10], 0);
	TextDrawSetSelectable(TradeTD[10], true);

	TradeTD[11] = TextDrawCreate(142.666809, 166.355468, "box");
	TextDrawLetterSize(TradeTD[11], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[11], 307.000000, 0.000000);
	TextDrawAlignment(TradeTD[11], 1);
	TextDrawColor(TradeTD[11], -1);
	TextDrawUseBox(TradeTD[11], 1);
	TextDrawBoxColor(TradeTD[11], -238);
	TextDrawSetShadow(TradeTD[11], 0);
	TextDrawSetOutline(TradeTD[11], 0);
	TextDrawBackgroundColor(TradeTD[11], 255);
	TextDrawFont(TradeTD[11], 1);
	TextDrawSetProportional(TradeTD[11], 1);
	TextDrawSetShadow(TradeTD[11], 0);

	TradeTD[12] = TextDrawCreate(143.000137, 199.540725, "box");
	TextDrawLetterSize(TradeTD[12], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[12], 307.000000, 0.000000);
	TextDrawAlignment(TradeTD[12], 1);
	TextDrawColor(TradeTD[12], -1);
	TextDrawUseBox(TradeTD[12], 1);
	TextDrawBoxColor(TradeTD[12], -236);
	TextDrawSetShadow(TradeTD[12], 0);
	TextDrawSetOutline(TradeTD[12], 0);
	TextDrawBackgroundColor(TradeTD[12], 255);
	TextDrawFont(TradeTD[12], 1);
	TextDrawSetProportional(TradeTD[12], 1);
	TextDrawSetShadow(TradeTD[12], 0);

	TradeTD[13] = TextDrawCreate(143.000106, 232.725921, "box");
	TextDrawLetterSize(TradeTD[13], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[13], 307.000000, 0.000000);
	TextDrawAlignment(TradeTD[13], 1);
	TextDrawColor(TradeTD[13], -1);
	TextDrawUseBox(TradeTD[13], 1);
	TextDrawBoxColor(TradeTD[13], -236);
	TextDrawSetShadow(TradeTD[13], 0);
	TextDrawSetOutline(TradeTD[13], 0);
	TextDrawBackgroundColor(TradeTD[13], 255);
	TextDrawFont(TradeTD[13], 1);
	TextDrawSetProportional(TradeTD[13], 1);
	TextDrawSetShadow(TradeTD[13], 0);

	TradeTD[14] = TextDrawCreate(142.666778, 266.325988, "box");
	TextDrawLetterSize(TradeTD[14], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[14], 307.000000, 0.000000);
	TextDrawAlignment(TradeTD[14], 1);
	TextDrawColor(TradeTD[14], -1);
	TextDrawUseBox(TradeTD[14], 1);
	TextDrawBoxColor(TradeTD[14], -236);
	TextDrawSetShadow(TradeTD[14], 0);
	TextDrawSetOutline(TradeTD[14], 0);
	TextDrawBackgroundColor(TradeTD[14], 255);
	TextDrawFont(TradeTD[14], 1);
	TextDrawSetProportional(TradeTD[14], 1);
	TextDrawSetShadow(TradeTD[14], 0);

	TradeTD[15] = TextDrawCreate(142.333465, 299.926025, "box");
	TextDrawLetterSize(TradeTD[15], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[15], 307.000000, 0.000000);
	TextDrawAlignment(TradeTD[15], 1);
	TextDrawColor(TradeTD[15], -1);
	TextDrawUseBox(TradeTD[15], 1);
	TextDrawBoxColor(TradeTD[15], -236);
	TextDrawSetShadow(TradeTD[15], 0);
	TextDrawSetOutline(TradeTD[15], 0);
	TextDrawBackgroundColor(TradeTD[15], 255);
	TextDrawFont(TradeTD[15], 1);
	TextDrawSetProportional(TradeTD[15], 1);
	TextDrawSetShadow(TradeTD[15], 0);

	TradeTD[16] = TextDrawCreate(333.000488, 166.355560, "box");
	TextDrawLetterSize(TradeTD[16], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[16], 500.000000, 0.000000);
	TextDrawAlignment(TradeTD[16], 1);
	TextDrawColor(TradeTD[16], -1);
	TextDrawUseBox(TradeTD[16], 1);
	TextDrawBoxColor(TradeTD[16], -236);
	TextDrawSetShadow(TradeTD[16], 0);
	TextDrawSetOutline(TradeTD[16], 0);
	TextDrawBackgroundColor(TradeTD[16], 255);
	TextDrawFont(TradeTD[16], 1);
	TextDrawSetProportional(TradeTD[16], 1);
	TextDrawSetShadow(TradeTD[16], 0);

	TradeTD[17] = TextDrawCreate(333.000701, 199.540756, "box");
	TextDrawLetterSize(TradeTD[17], 0.000000, 3.099998);
	TextDrawTextSize(TradeTD[17], 500.000000, 0.000000);
	TextDrawAlignment(TradeTD[17], 1);
	TextDrawColor(TradeTD[17], -1);
	TextDrawUseBox(TradeTD[17], 1);
	TextDrawBoxColor(TradeTD[17], -236);
	TextDrawSetShadow(TradeTD[17], 0);
	TextDrawSetOutline(TradeTD[17], 0);
	TextDrawBackgroundColor(TradeTD[17], 255);
	TextDrawFont(TradeTD[17], 1);
	TextDrawSetProportional(TradeTD[17], 1);
	TextDrawSetShadow(TradeTD[17], 0);

	TradeTD[18] = TextDrawCreate(333.000701, 232.311096, "box");
	TextDrawLetterSize(TradeTD[18], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[18], 501.000000, 0.000000);
	TextDrawAlignment(TradeTD[18], 1);
	TextDrawColor(TradeTD[18], -1);
	TextDrawUseBox(TradeTD[18], 1);
	TextDrawBoxColor(TradeTD[18], -236);
	TextDrawSetShadow(TradeTD[18], 0);
	TextDrawSetOutline(TradeTD[18], 0);
	TextDrawBackgroundColor(TradeTD[18], 255);
	TextDrawFont(TradeTD[18], 1);
	TextDrawSetProportional(TradeTD[18], 1);
	TextDrawSetShadow(TradeTD[18], 0);

	TradeTD[19] = TextDrawCreate(333.333984, 265.911102, "box");
	TextDrawLetterSize(TradeTD[19], 0.000000, 3.166666);
	TextDrawTextSize(TradeTD[19], 501.000000, 0.000000);
	TextDrawAlignment(TradeTD[19], 1);
	TextDrawColor(TradeTD[19], -1);
	TextDrawUseBox(TradeTD[19], 1);
	TextDrawBoxColor(TradeTD[19], -236);
	TextDrawSetShadow(TradeTD[19], 0);
	TextDrawSetOutline(TradeTD[19], 0);
	TextDrawBackgroundColor(TradeTD[19], 255);
	TextDrawFont(TradeTD[19], 1);
	TextDrawSetProportional(TradeTD[19], 1);
	TextDrawSetShadow(TradeTD[19], 0);

	TradeTD[20] = TextDrawCreate(332.667358, 299.511260, "box");
	TextDrawLetterSize(TradeTD[20], 0.000000, 3.199999);
	TextDrawTextSize(TradeTD[20], 501.000000, 0.000000);
	TextDrawAlignment(TradeTD[20], 1);
	TextDrawColor(TradeTD[20], -1);
	TextDrawUseBox(TradeTD[20], 1);
	TextDrawBoxColor(TradeTD[20], -236);
	TextDrawSetShadow(TradeTD[20], 0);
	TextDrawSetOutline(TradeTD[20], 0);
	TextDrawBackgroundColor(TradeTD[20], 255);
	TextDrawFont(TradeTD[20], 1);
	TextDrawSetProportional(TradeTD[20], 1);
	TextDrawSetShadow(TradeTD[20], 0);
	
	HiddTDs[0] = CreatePlayerTextDraw(playerid, 264.231353, 354.500061, "Color_1:_255");
	PlayerTextDrawLetterSize(playerid, HiddTDs[0], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, HiddTDs[0], 1);
	PlayerTextDrawColor(playerid, HiddTDs[0], -1);
	PlayerTextDrawSetShadow(playerid, HiddTDs[0], 0);
	PlayerTextDrawSetOutline(playerid, HiddTDs[0], 1);
	PlayerTextDrawBackgroundColor(playerid, HiddTDs[0], 255);
	PlayerTextDrawFont(playerid, HiddTDs[0], 2);
	PlayerTextDrawSetProportional(playerid, HiddTDs[0], 1);
	PlayerTextDrawSetShadow(playerid, HiddTDs[0], 0);

	HiddTDs[1] = CreatePlayerTextDraw(playerid, 279.692474, 407.583251, "Cumpara");
	PlayerTextDrawLetterSize(playerid, HiddTDs[1], 0.529779, 1.576665);
	PlayerTextDrawTextSize(playerid, HiddTDs[1], 359.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, HiddTDs[1], 1);
	PlayerTextDrawColor(playerid, HiddTDs[1], -1);
	PlayerTextDrawSetShadow(playerid, HiddTDs[1], 0);
	PlayerTextDrawSetOutline(playerid, HiddTDs[1], 1);
	PlayerTextDrawBackgroundColor(playerid, HiddTDs[1], 255);
	PlayerTextDrawFont(playerid, HiddTDs[1], 3);
	PlayerTextDrawSetProportional(playerid, HiddTDs[1], 1);
	PlayerTextDrawSetShadow(playerid, HiddTDs[1], 0);
	PlayerTextDrawSetSelectable(playerid, HiddTDs[1], true);

	HiddTDs[2] = CreatePlayerTextDraw(playerid, 262.825714, 378.999969, "Color_2:_255");
	PlayerTextDrawLetterSize(playerid, HiddTDs[2], 0.400000, 1.600000);
	PlayerTextDrawAlignment(playerid, HiddTDs[2], 1);
	PlayerTextDrawColor(playerid, HiddTDs[2], -1);
	PlayerTextDrawSetShadow(playerid, HiddTDs[2], 0);
	PlayerTextDrawSetOutline(playerid, HiddTDs[2], 1);
	PlayerTextDrawBackgroundColor(playerid, HiddTDs[2], 255);
	PlayerTextDrawFont(playerid, HiddTDs[2], 2);
	PlayerTextDrawSetProportional(playerid, HiddTDs[2], 1);
	PlayerTextDrawSetShadow(playerid, HiddTDs[2], 0);

	ShopTDs[0] = CreatePlayerTextDraw(playerid, 258.609130, 360.333251, "Interior ID: 5");
	PlayerTextDrawLetterSize(playerid, ShopTDs[0], 0.318944, 1.570832);
	PlayerTextDrawAlignment(playerid, ShopTDs[0], 1);
	PlayerTextDrawColor(playerid, ShopTDs[0], -1);
	PlayerTextDrawSetShadow(playerid, ShopTDs[0], 0);
	PlayerTextDrawSetOutline(playerid, ShopTDs[0], 1);
	PlayerTextDrawBackgroundColor(playerid, ShopTDs[0], 255);
	PlayerTextDrawFont(playerid, ShopTDs[0], 2);
	PlayerTextDrawSetProportional(playerid, ShopTDs[0], 1);
	PlayerTextDrawSetShadow(playerid, ShopTDs[0], 0);

	ShopTDs[1] = CreatePlayerTextDraw(playerid, 265.636871, 381.916564, "Cumpara");
	PlayerTextDrawLetterSize(playerid, ShopTDs[1], 0.529779, 1.576666);
	PlayerTextDrawTextSize(playerid, ShopTDs[1], 359.000000, 15.000000);
	PlayerTextDrawAlignment(playerid, ShopTDs[1], 1);
	PlayerTextDrawColor(playerid, ShopTDs[1], -1);
	PlayerTextDrawSetShadow(playerid, ShopTDs[1], 0);
	PlayerTextDrawSetOutline(playerid, ShopTDs[1], 1);
	PlayerTextDrawBackgroundColor(playerid, ShopTDs[1], 255);
	PlayerTextDrawFont(playerid, ShopTDs[1], 3);
	PlayerTextDrawSetProportional(playerid, ShopTDs[1], 1);
	PlayerTextDrawSetShadow(playerid, ShopTDs[1], 0);
	PlayerTextDrawSetSelectable(playerid, ShopTDs[1], true);

    PinStep[playerid] = 0;
	// - - - - - - - - PIN SYSTEM - - - - - - - - -
	RedButton = CreatePlayerTextDraw(playerid, 330.307556, 302.750061, " ");
	PlayerTextDrawLetterSize(playerid, RedButton, 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, RedButton, 350.922637, 23.916666);
	PlayerTextDrawAlignment(playerid, RedButton, 1);
	PlayerTextDrawColor(playerid, RedButton, -16776961);
	PlayerTextDrawSetShadow(playerid, RedButton, 0);
	PlayerTextDrawSetOutline(playerid, RedButton, 0);
	PlayerTextDrawBackgroundColor(playerid, RedButton, 51);
	PlayerTextDrawFont(playerid, RedButton, 1);
	PlayerTextDrawSetProportional(playerid, RedButton, 1);
	PlayerTextDrawSetSelectable(playerid, RedButton, true);

	GreenButton = CreatePlayerTextDraw(playerid, 273.615997, 303.333343, " ");
	PlayerTextDrawLetterSize(playerid, GreenButton, 0.449999, 1.600000);
	PlayerTextDrawTextSize(playerid, GreenButton, 291.420501, 23.916666);
	PlayerTextDrawAlignment(playerid, GreenButton, 1);
	PlayerTextDrawColor(playerid, GreenButton, 16711935);
	PlayerTextDrawSetShadow(playerid, GreenButton, 0);
	PlayerTextDrawSetOutline(playerid, GreenButton, 0);
	PlayerTextDrawBackgroundColor(playerid, GreenButton, 51);
	PlayerTextDrawFont(playerid, GreenButton, 1);
	PlayerTextDrawSetProportional(playerid, GreenButton, 1);
	PlayerTextDrawSetSelectable(playerid, GreenButton, true);

	PinNumber[0] = CreatePlayerTextDraw(playerid, 306.043579, 297.166656, "0");
	PlayerTextDrawTextSize(playerid, PinNumber[0], 317.188842, 23.916666);
	PlayerTextDrawSetSelectable(playerid, PinNumber[0], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[0], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[0], 1);
	PlayerTextDrawColor(playerid, PinNumber[0], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[0], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[0], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[0], 255);
	PlayerTextDrawFont(playerid, PinNumber[0], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[0], 1);

	PinNumber[1] = CreatePlayerTextDraw(playerid, 277.364654, 205.916732, "1");
	PlayerTextDrawTextSize(playerid, PinNumber[1], 289.077880, 24.500007);
	PlayerTextDrawSetSelectable(playerid, PinNumber[1], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[1], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[1], 1);
	PlayerTextDrawColor(playerid, PinNumber[1], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[1], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[1], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[1], 255);
	PlayerTextDrawFont(playerid, PinNumber[1], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[1], 1);

	PinNumber[2] = CreatePlayerTextDraw(playerid, 306.007659, 206.333404, "2");
	PlayerTextDrawTextSize(playerid, PinNumber[2], 317.188842, 23.916666);
	PlayerTextDrawSetSelectable(playerid, PinNumber[2], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[2], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[2], 1);
	PlayerTextDrawColor(playerid, PinNumber[2], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[2], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[2], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[2], 255);
	PlayerTextDrawFont(playerid, PinNumber[2], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[2], 1);

	PinNumber[3] = CreatePlayerTextDraw(playerid, 335.119171, 206.166748, "3");
	PlayerTextDrawTextSize(playerid, PinNumber[3], 346.705810, 23.916666);
	PlayerTextDrawSetSelectable(playerid, PinNumber[3], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[3], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[3], 1);
	PlayerTextDrawColor(playerid, PinNumber[3], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[3], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[3], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[3], 255);
	PlayerTextDrawFont(playerid, PinNumber[3], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[3], 1);

	PinNumber[4] = CreatePlayerTextDraw(playerid, 275.679809, 236.916748, "4");
	PlayerTextDrawTextSize(playerid, PinNumber[4], 289.077880, 24.500007);
	PlayerTextDrawSetSelectable(playerid, PinNumber[4], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[4], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[4], 1);
	PlayerTextDrawColor(playerid, PinNumber[4], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[4], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[4], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[4], 255);
	PlayerTextDrawFont(playerid, PinNumber[4], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[4], 1);

	PinNumber[5] = CreatePlayerTextDraw(playerid, 306.196807, 237.333404, "5");
	PlayerTextDrawTextSize(playerid, PinNumber[5], 317.188842, 23.916666);
	PlayerTextDrawSetSelectable(playerid, PinNumber[5], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[5], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[5], 1);
	PlayerTextDrawColor(playerid, PinNumber[5], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[5], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[5], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[5], 255);
	PlayerTextDrawFont(playerid, PinNumber[5], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[5], 1);

	PinNumber[6] = CreatePlayerTextDraw(playerid, 335.308410, 237.166763, "6");
	PlayerTextDrawTextSize(playerid, PinNumber[6], 346.705810, 23.916666);
	PlayerTextDrawSetSelectable(playerid, PinNumber[6], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[6], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[6], 1);
	PlayerTextDrawColor(playerid, PinNumber[6], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[6], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[6], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[6], 255);
	PlayerTextDrawFont(playerid, PinNumber[6], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[6], 1);

	PinNumber[7] = CreatePlayerTextDraw(playerid, 277.274658, 267.333404, "7");
	PlayerTextDrawTextSize(playerid, PinNumber[7], 289.077880, 24.500007);
	PlayerTextDrawSetSelectable(playerid, PinNumber[7], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[7], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[7], 1);
	PlayerTextDrawColor(playerid, PinNumber[7], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[7], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[7], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[7], 255);
	PlayerTextDrawFont(playerid, PinNumber[7], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[7], 1);

	PinNumber[8] = CreatePlayerTextDraw(playerid, 305.917602, 267.166748, "8");
	PlayerTextDrawTextSize(playerid, PinNumber[8], 317.188842, 23.916666);
	PlayerTextDrawSetSelectable(playerid, PinNumber[8], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[8], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[8], 1);
	PlayerTextDrawColor(playerid, PinNumber[8], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[8], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[8], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[8], 255);
	PlayerTextDrawFont(playerid, PinNumber[8], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[8], 1);

	PinNumber[9] = CreatePlayerTextDraw(playerid, 335.029083, 267.583404, "9");
	PlayerTextDrawTextSize(playerid, PinNumber[9], 346.705810, 23.916666);
	PlayerTextDrawSetSelectable(playerid, PinNumber[9], 1);
	PlayerTextDrawLetterSize(playerid, PinNumber[9], 0.599927, 2.790002);
	PlayerTextDrawAlignment(playerid, PinNumber[9], 1);
	PlayerTextDrawColor(playerid, PinNumber[9], -1);
	PlayerTextDrawSetShadow(playerid, PinNumber[9], 0);
	PlayerTextDrawSetOutline(playerid, PinNumber[9], 0);
	PlayerTextDrawBackgroundColor(playerid, PinNumber[9], 255);
	PlayerTextDrawFont(playerid, PinNumber[9], 3);
	PlayerTextDrawSetProportional(playerid, PinNumber[9], 1);

	PinResult = CreatePlayerTextDraw(playerid, 284.861328, 173.833236, "");
	PlayerTextDrawLetterSize(playerid, PinResult, 0.483262, 2.469165);
	PlayerTextDrawAlignment(playerid, PinResult, 2);
	PlayerTextDrawColor(playerid, PinResult, -5963521);
	PlayerTextDrawSetShadow(playerid, PinResult, 0);
	PlayerTextDrawSetOutline(playerid, PinResult, 0);
	PlayerTextDrawBackgroundColor(playerid, PinResult, 51);
	PlayerTextDrawFont(playerid, PinResult, 0);
	PlayerTextDrawSetProportional(playerid, PinResult, 1);
	// --------------------------------------------

	// ------------------------------ Dealership TextDraw ------------------------------ //
	InfoDS = CreatePlayerTextDraw(playerid, 483.045471, 230.416671, "Model: Perrenial~n~Viteza maxima: 133 km/h~n~Pret: ~g~$3,000~n~~w~Tip: ~g~Normal");
	PlayerTextDrawLetterSize(playerid, InfoDS, 0.389092, 1.308333);
	PlayerTextDrawAlignment(playerid, InfoDS, 1);
	PlayerTextDrawColor(playerid, InfoDS, -1);
	PlayerTextDrawSetShadow(playerid, InfoDS, 0);
	PlayerTextDrawSetOutline(playerid, InfoDS, 1);
	PlayerTextDrawBackgroundColor(playerid, InfoDS, 255);
	PlayerTextDrawFont(playerid, InfoDS, 1);
	PlayerTextDrawSetProportional(playerid, InfoDS, 1);

	MainColor = CreatePlayerTextDraw(playerid, 522.401489, 308.583343, "Main Color");
	PlayerTextDrawLetterSize(playerid, MainColor, 0.426573, 1.249999);
	PlayerTextDrawAlignment(playerid, MainColor, 1);
	PlayerTextDrawColor(playerid, MainColor, -1);
	PlayerTextDrawSetShadow(playerid, MainColor, 0);
	PlayerTextDrawSetOutline(playerid, MainColor, 1);
	PlayerTextDrawBackgroundColor(playerid, MainColor, 255);
	PlayerTextDrawFont(playerid, MainColor, 1);
	PlayerTextDrawSetProportional(playerid, MainColor, 1);

	SecColor = CreatePlayerTextDraw(playerid, 527.618164, 323.583404, "Sec. Color");
	PlayerTextDrawLetterSize(playerid, SecColor, 0.426573, 1.249999);
	PlayerTextDrawAlignment(playerid, SecColor, 1);
	PlayerTextDrawColor(playerid, SecColor, -1);
	PlayerTextDrawSetShadow(playerid, SecColor, 0);
	PlayerTextDrawSetOutline(playerid, SecColor, 1);
	PlayerTextDrawBackgroundColor(playerid, SecColor, 255);
	PlayerTextDrawFont(playerid, SecColor, 1);
	PlayerTextDrawSetProportional(playerid, SecColor, 1);

	BackColorMain = CreatePlayerTextDraw(playerid, 507.877319, 307.416503, "<");
	PlayerTextDrawLetterSize(playerid, BackColorMain, 0.440629, 1.454166);
	PlayerTextDrawTextSize(playerid, BackColorMain, 519.121643, 10.333330);
	PlayerTextDrawAlignment(playerid, BackColorMain, 1);
	PlayerTextDrawColor(playerid, BackColorMain, -1);
	PlayerTextDrawSetShadow(playerid, BackColorMain, 0);
	PlayerTextDrawSetOutline(playerid, BackColorMain, 1);
	PlayerTextDrawBackgroundColor(playerid, BackColorMain, 255);
	PlayerTextDrawFont(playerid, BackColorMain, 1);
	PlayerTextDrawSetProportional(playerid, BackColorMain, 1);
	PlayerTextDrawSetSelectable(playerid, BackColorMain, true);

	NextColorMain = CreatePlayerTextDraw(playerid, 606.329711, 308.416564, ">");
	PlayerTextDrawLetterSize(playerid, NextColorMain, 0.440629, 1.454166);
	PlayerTextDrawTextSize(playerid, NextColorMain, 618.447998, 10.833335);
	PlayerTextDrawAlignment(playerid, NextColorMain, 1);
	PlayerTextDrawColor(playerid, NextColorMain, -1);
	PlayerTextDrawSetShadow(playerid, NextColorMain, 0);
	PlayerTextDrawSetOutline(playerid, NextColorMain, 1);
	PlayerTextDrawBackgroundColor(playerid, NextColorMain, 255);
	PlayerTextDrawFont(playerid, NextColorMain, 1);
	PlayerTextDrawSetProportional(playerid, NextColorMain, 1);
	PlayerTextDrawSetSelectable(playerid, NextColorMain, true);

	BackColorSec = CreatePlayerTextDraw(playerid, 507.940246, 322.416503, "<");
	PlayerTextDrawLetterSize(playerid, BackColorSec, 0.440629, 1.454166);
	PlayerTextDrawTextSize(playerid, BackColorSec, 519.121337, 10.499984);
	PlayerTextDrawAlignment(playerid, BackColorSec, 1);
	PlayerTextDrawColor(playerid, BackColorSec, -1);
	PlayerTextDrawSetShadow(playerid, BackColorSec, 0);
	PlayerTextDrawSetOutline(playerid, BackColorSec, 1);
	PlayerTextDrawBackgroundColor(playerid, BackColorSec, 255);
	PlayerTextDrawFont(playerid, BackColorSec, 1);
	PlayerTextDrawSetProportional(playerid, BackColorSec, 1);
	PlayerTextDrawSetSelectable(playerid, BackColorSec, true);

	NextColorSec = CreatePlayerTextDraw(playerid, 607.329650, 322.833190, ">");
	PlayerTextDrawLetterSize(playerid, NextColorSec, 0.440629, 1.454166);
	PlayerTextDrawTextSize(playerid, NextColorSec, 618.447875, 10.416666);
	PlayerTextDrawAlignment(playerid, NextColorSec, 1);
	PlayerTextDrawColor(playerid, NextColorSec, -1);
	PlayerTextDrawSetShadow(playerid, NextColorSec, 0);
	PlayerTextDrawSetOutline(playerid, NextColorSec, 1);
	PlayerTextDrawBackgroundColor(playerid, NextColorSec, 255);
	PlayerTextDrawFont(playerid, NextColorSec, 1);
	PlayerTextDrawSetProportional(playerid, NextColorSec, 1);
	PlayerTextDrawSetSelectable(playerid, NextColorSec, true);

	CarsCategory = CreatePlayerTextDraw(playerid, 0.937097, 228.666549, "Cars");
	PlayerTextDrawLetterSize(playerid, CarsCategory, 0.507159, 1.512497);
	PlayerTextDrawTextSize(playerid, CarsCategory, 38.418746, 8.416666);
	PlayerTextDrawAlignment(playerid, CarsCategory, 1);
	PlayerTextDrawColor(playerid, CarsCategory, -1);
	PlayerTextDrawSetShadow(playerid, CarsCategory, 0);
	PlayerTextDrawSetOutline(playerid, CarsCategory, 1);
	PlayerTextDrawBackgroundColor(playerid, CarsCategory, 255);
	PlayerTextDrawFont(playerid, CarsCategory, 1);
	PlayerTextDrawSetProportional(playerid, CarsCategory, 1);
	PlayerTextDrawSetSelectable(playerid, CarsCategory, true);

	BikesCategory = CreatePlayerTextDraw(playerid, 0.531533, 246.583190, "Bikes");
	PlayerTextDrawLetterSize(playerid, BikesCategory, 0.507158, 1.512496);
	PlayerTextDrawTextSize(playerid, BikesCategory, 44.040996, 8.916666);
	PlayerTextDrawAlignment(playerid, BikesCategory, 1);
	PlayerTextDrawColor(playerid, BikesCategory, -1);
	PlayerTextDrawSetShadow(playerid, BikesCategory, 0);
	PlayerTextDrawSetOutline(playerid, BikesCategory, 1);
	PlayerTextDrawBackgroundColor(playerid, BikesCategory, 255);
	PlayerTextDrawFont(playerid, BikesCategory, 1);
	PlayerTextDrawSetProportional(playerid, BikesCategory, 1);
	PlayerTextDrawSetSelectable(playerid, BikesCategory, true);

	BoatsCategory = CreatePlayerTextDraw(playerid, 0.594491, 263.333099, "Boats");
	PlayerTextDrawLetterSize(playerid, BoatsCategory, 0.507158, 1.512496);
	PlayerTextDrawTextSize(playerid, BoatsCategory, 48.726203, 8.000000);
	PlayerTextDrawAlignment(playerid, BoatsCategory, 1);
	PlayerTextDrawColor(playerid, BoatsCategory, -1);
	PlayerTextDrawSetShadow(playerid, BoatsCategory, 0);
	PlayerTextDrawSetOutline(playerid, BoatsCategory, 1);
	PlayerTextDrawBackgroundColor(playerid, BoatsCategory, 255);
	PlayerTextDrawFont(playerid, BoatsCategory, 1);
	PlayerTextDrawSetProportional(playerid, BoatsCategory, 1);
	PlayerTextDrawSetSelectable(playerid, BoatsCategory, true);

	AirCategory = CreatePlayerTextDraw(playerid, 0.188927, 280.666473, "Aircrafts");
	PlayerTextDrawLetterSize(playerid, AirCategory, 0.507158, 1.512496);
	PlayerTextDrawTextSize(playerid, AirCategory, 74.026351, 8.166666);
	PlayerTextDrawAlignment(playerid, AirCategory, 1);
	PlayerTextDrawColor(playerid, AirCategory, -1);
	PlayerTextDrawSetShadow(playerid, AirCategory, 0);
	PlayerTextDrawSetOutline(playerid, AirCategory, 1);
	PlayerTextDrawBackgroundColor(playerid, AirCategory, 255);
	PlayerTextDrawFont(playerid, AirCategory, 1);
	PlayerTextDrawSetProportional(playerid, AirCategory, 1);
	PlayerTextDrawSetSelectable(playerid, AirCategory, true);

	SpecialCategory = CreatePlayerTextDraw(playerid, 0.251885, 297.999877, "Special");
	PlayerTextDrawLetterSize(playerid, SpecialCategory, 0.507158, 1.512496);
	PlayerTextDrawTextSize(playerid, SpecialCategory, 60.439231, 8.666667);
	PlayerTextDrawAlignment(playerid, SpecialCategory, 1);
	PlayerTextDrawColor(playerid, SpecialCategory, -1);
	PlayerTextDrawSetShadow(playerid, SpecialCategory, 0);
	PlayerTextDrawSetOutline(playerid, SpecialCategory, 1);
	PlayerTextDrawBackgroundColor(playerid, SpecialCategory, 255);
	PlayerTextDrawFont(playerid, SpecialCategory, 1);
	PlayerTextDrawSetProportional(playerid, SpecialCategory, 1);
	PlayerTextDrawSetSelectable(playerid, SpecialCategory, true);

	RotLeft = CreatePlayerTextDraw(playerid, 189.751113, 329.583343, "Left");
	PlayerTextDrawLetterSize(playerid, RotLeft, 0.361449, 1.273333);
	PlayerTextDrawTextSize(playerid, RotLeft, 244.568038, 8.166666);
	PlayerTextDrawAlignment(playerid, RotLeft, 1);
	PlayerTextDrawColor(playerid, RotLeft, -1);
	PlayerTextDrawSetShadow(playerid, RotLeft, 0);
	PlayerTextDrawSetOutline(playerid, RotLeft, 1);
	PlayerTextDrawBackgroundColor(playerid, RotLeft, 255);
	PlayerTextDrawFont(playerid, RotLeft, 1);
	PlayerTextDrawSetProportional(playerid, RotLeft, 1);
	PlayerTextDrawSetSelectable(playerid, RotLeft, true);

	RotRight = CreatePlayerTextDraw(playerid, 361.293212, 328.833282, "Rightt");
	PlayerTextDrawLetterSize(playerid, RotRight, 0.361449, 1.273333);
	PlayerTextDrawTextSize(playerid, RotRight, 423.543579, 8.416656);
	PlayerTextDrawAlignment(playerid, RotRight, 1);
	PlayerTextDrawColor(playerid, RotRight, -1);
	PlayerTextDrawSetShadow(playerid, RotRight, 0);
	PlayerTextDrawSetOutline(playerid, RotRight, 1);
	PlayerTextDrawBackgroundColor(playerid, RotRight, 255);
	PlayerTextDrawFont(playerid, RotRight, 1);
	PlayerTextDrawSetProportional(playerid, RotRight, 1);
	PlayerTextDrawSetSelectable(playerid, RotRight, true);

	BuyModel = CreatePlayerTextDraw(playerid, 186.471466, 362.833404, "Buy model");
	PlayerTextDrawLetterSize(playerid, BuyModel, 0.593367, 1.897500);
	PlayerTextDrawTextSize(playerid, BuyModel, 295.636871, 15.333333);
	PlayerTextDrawAlignment(playerid, BuyModel, 1);
	PlayerTextDrawColor(playerid, BuyModel, -1);
	PlayerTextDrawSetShadow(playerid, BuyModel, 0);
	PlayerTextDrawSetOutline(playerid, BuyModel, 1);
	PlayerTextDrawBackgroundColor(playerid, BuyModel, 255);
	PlayerTextDrawFont(playerid, BuyModel, 1);
	PlayerTextDrawSetProportional(playerid, BuyModel, 1);
	PlayerTextDrawSetSelectable(playerid, BuyModel, true);

	TestModel = CreatePlayerTextDraw(playerid, 306.476196, 362.666839, "Test drive");
	PlayerTextDrawLetterSize(playerid, TestModel, 0.593367, 1.897500);
	PlayerTextDrawTextSize(playerid, TestModel, 419.326416, 15.083343);
	PlayerTextDrawAlignment(playerid, TestModel, 1);
	PlayerTextDrawColor(playerid, TestModel, -1);
	PlayerTextDrawSetShadow(playerid, TestModel, 0);
	PlayerTextDrawSetOutline(playerid, TestModel, 1);
	PlayerTextDrawBackgroundColor(playerid, TestModel, 255);
	PlayerTextDrawFont(playerid, TestModel, 1);
	PlayerTextDrawSetProportional(playerid, TestModel, 1);
	PlayerTextDrawSetSelectable(playerid, TestModel, true);

	ExitDS = CreatePlayerTextDraw(playerid, 280.770416, 384.083496, "Cancel");
	PlayerTextDrawLetterSize(playerid, ExitDS, 0.593367, 1.897500);
	PlayerTextDrawTextSize(playerid, ExitDS, 317.657379, 15.416665);
	PlayerTextDrawAlignment(playerid, ExitDS, 1);
	PlayerTextDrawColor(playerid, ExitDS, -1);
	PlayerTextDrawSetShadow(playerid, ExitDS, 0);
	PlayerTextDrawSetOutline(playerid, ExitDS, 1);
	PlayerTextDrawBackgroundColor(playerid, ExitDS, 255);
	PlayerTextDrawFont(playerid, ExitDS, 1);
	PlayerTextDrawSetProportional(playerid, ExitDS, 1);
	PlayerTextDrawSetSelectable(playerid, ExitDS, true);

	BackCar = CreatePlayerTextDraw(playerid, 158.360183, 362.833404, "<");
	PlayerTextDrawLetterSize(playerid, BackCar, 0.628038, 2.066666);
	PlayerTextDrawTextSize(playerid, BackCar, 176.163955, 20.583334);
	PlayerTextDrawAlignment(playerid, BackCar, 1);
	PlayerTextDrawColor(playerid, BackCar, -1);
	PlayerTextDrawSetShadow(playerid, BackCar, 0);
	PlayerTextDrawSetOutline(playerid, BackCar, 1);
	PlayerTextDrawBackgroundColor(playerid, BackCar, 255);
	PlayerTextDrawFont(playerid, BackCar, 1);
	PlayerTextDrawSetProportional(playerid, BackCar, 1);
	PlayerTextDrawSetSelectable(playerid, BackCar, true);

	NextCar = CreatePlayerTextDraw(playerid, 433.445190, 360.916717, ">");
	PlayerTextDrawLetterSize(playerid, NextCar, 0.628038, 2.066666);
	PlayerTextDrawTextSize(playerid, NextCar, 449.780273, 20.333337);
	PlayerTextDrawAlignment(playerid, NextCar, 1);
	PlayerTextDrawColor(playerid, NextCar, -1);
	PlayerTextDrawSetShadow(playerid, NextCar, 0);
	PlayerTextDrawSetOutline(playerid, NextCar, 1);
	PlayerTextDrawBackgroundColor(playerid, NextCar, 255);
	PlayerTextDrawFont(playerid, NextCar, 1);
	PlayerTextDrawSetProportional(playerid, NextCar, 1);
	PlayerTextDrawSetSelectable(playerid, NextCar, true);
	// ------------------------------ Dealership TextDraw ------------------------------ //

    LoadingAccount[playerid] = CreatePlayerTextDraw(playerid, 320.000274, 419.417114, "~h~Your account is loading...");
	PlayerTextDrawLetterSize(playerid, LoadingAccount[playerid], 0.316939, 1.518333);
	PlayerTextDrawAlignment(playerid, LoadingAccount[playerid], 2);
	PlayerTextDrawColor(playerid, LoadingAccount[playerid], -1);
	PlayerTextDrawSetShadow(playerid, LoadingAccount[playerid], 0);
	PlayerTextDrawSetOutline(playerid, LoadingAccount[playerid], -1);
	PlayerTextDrawBackgroundColor(playerid, LoadingAccount[playerid], 51);
	PlayerTextDrawFont(playerid, LoadingAccount[playerid], 1);
	PlayerTextDrawSetProportional(playerid, LoadingAccount[playerid], 1);

	ReportsInfo[playerid] = CreatePlayerTextDraw(playerid, 516.729583, 7.000000, "~r~~h~0");
	PlayerTextDrawLetterSize(playerid, ReportsInfo[playerid], 0.358638, 1.629166);
	PlayerTextDrawAlignment(playerid, ReportsInfo[playerid], 2);
	PlayerTextDrawColor(playerid, ReportsInfo[playerid], -1);
	PlayerTextDrawSetShadow(playerid, ReportsInfo[playerid], 1);
	PlayerTextDrawSetOutline(playerid, ReportsInfo[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, ReportsInfo[playerid], 255);
	PlayerTextDrawFont(playerid, ReportsInfo[playerid], 1);
	PlayerTextDrawSetProportional(playerid, ReportsInfo[playerid], 1);

	HelpsInfo[playerid] = CreatePlayerTextDraw(playerid, 488.729583, 7.000000, "0");
	PlayerTextDrawLetterSize(playerid, HelpsInfo[playerid], 0.358638, 1.629166);
	PlayerTextDrawAlignment(playerid, HelpsInfo[playerid], 2);
	PlayerTextDrawColor(playerid, HelpsInfo[playerid], -65281);
	PlayerTextDrawSetShadow(playerid, HelpsInfo[playerid], 1);
	PlayerTextDrawSetOutline(playerid, HelpsInfo[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, HelpsInfo[playerid], 255);
	PlayerTextDrawFont(playerid, HelpsInfo[playerid], 1);
	PlayerTextDrawSetProportional(playerid, HelpsInfo[playerid], 1);

	EventsInfo[playerid] = CreatePlayerTextDraw(playerid, 460.729583, 7.000000, "~b~~h~~h~0");
	PlayerTextDrawLetterSize(playerid, EventsInfo[playerid], 0.358638, 1.629166);
	PlayerTextDrawAlignment(playerid, EventsInfo[playerid], 2);
	PlayerTextDrawColor(playerid, EventsInfo[playerid], -65281);
	PlayerTextDrawSetShadow(playerid, EventsInfo[playerid], 1);
	PlayerTextDrawSetOutline(playerid, EventsInfo[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, EventsInfo[playerid], 255);
	PlayerTextDrawFont(playerid, EventsInfo[playerid], 1);
	PlayerTextDrawSetProportional(playerid, EventsInfo[playerid], 1);

    PayDayText[playerid] = CreatePlayerTextDraw(playerid, 543.484863, 218.249984, "~y~P~w~ay~y~D~w~ay~n~- ~y~P~w~lata: 999,999$~n~- ~y~B~w~alanta: 999,999,999$~n~- ~y~R~w~ent: 99,999$");
	PlayerTextDrawLetterSize(playerid, PayDayText[playerid], 0.246190, 1.285001);
	PlayerTextDrawTextSize(playerid, PayDayText[playerid], 562.225280, 165.083312);
	PlayerTextDrawAlignment(playerid, PayDayText[playerid], 2);
	PlayerTextDrawColor(playerid, PayDayText[playerid], -1);
	PlayerTextDrawUseBox(playerid, PayDayText[playerid], true);
	PlayerTextDrawBoxColor(playerid, PayDayText[playerid], 255);
	PlayerTextDrawSetShadow(playerid, PayDayText[playerid], 0);
	PlayerTextDrawSetOutline(playerid, PayDayText[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PayDayText[playerid], 255);
	PlayerTextDrawFont(playerid, PayDayText[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PayDayText[playerid], 1);

	ShowTD = CreatePlayerTextDraw(playerid, 89.004348, 315.416473, "FPS: ~y~Se incarca...~w~~h~~n~Ping: ~y~Se incarca...");
	PlayerTextDrawLetterSize(playerid, ShowTD, 0.274904, 1.121667);
	PlayerTextDrawAlignment(playerid, ShowTD, 2);
	PlayerTextDrawColor(playerid, ShowTD, -21);
	PlayerTextDrawSetShadow(playerid, ShowTD, 1);
	PlayerTextDrawSetOutline(playerid, ShowTD, 0);
	PlayerTextDrawBackgroundColor(playerid, ShowTD, 255);
	PlayerTextDrawFont(playerid, ShowTD, 1);
	PlayerTextDrawSetProportional(playerid, ShowTD, 1);
	PlayerTextDrawSetShadow(playerid, ShowTD, 1);

	JobTD = CreatePlayerTextDraw(playerid, 540.999633, 378.740631, "Teritoriu atacat de %s~n~%s - %s~n~Scor: %.1f - %.1f~n~Timp war: %s~n~Ucideri: %d Decese: %d Scor: %d");
	PlayerTextDrawLetterSize(playerid, JobTD, 0.188666, 0.786961);
	PlayerTextDrawTextSize(playerid, JobTD, 0.000000, 132.000000);
	PlayerTextDrawAlignment(playerid, JobTD, 2);
	PlayerTextDrawColor(playerid, JobTD, -1);
	PlayerTextDrawUseBox(playerid, JobTD, 1);
	PlayerTextDrawBoxColor(playerid, JobTD, 227);
	PlayerTextDrawSetShadow(playerid, JobTD, 0);
	PlayerTextDrawSetOutline(playerid, JobTD, 0);
	PlayerTextDrawBackgroundColor(playerid, JobTD, 255);
	PlayerTextDrawFont(playerid, JobTD, 1);
	PlayerTextDrawSetProportional(playerid, JobTD, 1);
	PlayerTextDrawSetShadow(playerid, JobTD, 0);

    CbugT = CreatePlayerTextDraw(playerid, 320.468414, 147.000030, "~y~C-bug is ~r~forbidden!");
	PlayerTextDrawLetterSize(playerid, CbugT, 0.556354, 2.830835);
	PlayerTextDrawAlignment(playerid, CbugT, 2);
	PlayerTextDrawColor(playerid, CbugT, 255);
	PlayerTextDrawSetShadow(playerid, CbugT, 2);
	PlayerTextDrawSetOutline(playerid, CbugT, 0);
	PlayerTextDrawBackgroundColor(playerid, CbugT, 255);
	PlayerTextDrawFont(playerid, CbugT, 1);
	PlayerTextDrawSetProportional(playerid, CbugT, 1);


	InfosTD = CreatePlayerTextDraw(playerid, 304.992889, 386.000122, "");
	PlayerTextDrawLetterSize(playerid, InfosTD, 0.240234, 1.110000);
	PlayerTextDrawTextSize(playerid, InfosTD, 0.000000, 303.000000);
	PlayerTextDrawAlignment(playerid, InfosTD, 2);
	PlayerTextDrawColor(playerid, InfosTD, -1);
	PlayerTextDrawSetShadow(playerid, InfosTD, 0);
	PlayerTextDrawSetOutline(playerid, InfosTD, 1);
	PlayerTextDrawBackgroundColor(playerid, InfosTD, 248);
	PlayerTextDrawFont(playerid, InfosTD, 1);
	PlayerTextDrawSetProportional(playerid, InfosTD, 1);
	PlayerTextDrawSetShadow(playerid, InfosTD, 0);

	Speedo = CreatePlayerTextDraw(playerid, 556.958984, 151.083450, "Combustibil: %d%s~w~~h~~n~Viteza: %d km/h~n~Kilometraj: %.2f km~w~~n~~h~Status: %s");
	PlayerTextDrawLetterSize(playerid, Speedo, 0.329120, 1.075000);
	PlayerTextDrawAlignment(playerid, Speedo, 2);
	PlayerTextDrawColor(playerid, Speedo, -1);
	PlayerTextDrawSetShadow(playerid, Speedo, 1);
	PlayerTextDrawSetOutline(playerid, Speedo, 0);
	PlayerTextDrawBackgroundColor(playerid, Speedo, 255);
	PlayerTextDrawFont(playerid, Speedo, 1);
	PlayerTextDrawSetProportional(playerid, Speedo, 1);

	PlayerName[playerid] = CreatePlayerTextDraw(playerid, 86.739898, 429.066625, "~b~~h~BesTySor");
	PlayerTextDrawLetterSize(playerid, PlayerName[playerid], 0.391434, 1.483333);
	PlayerTextDrawAlignment(playerid, PlayerName[playerid], 2);
	PlayerTextDrawColor(playerid, PlayerName[playerid], -1);
	PlayerTextDrawSetShadow(playerid, PlayerName[playerid], 1);
	PlayerTextDrawSetOutline(playerid, PlayerName[playerid], 0);
	PlayerTextDrawBackgroundColor(playerid, PlayerName[playerid], 255);
	PlayerTextDrawFont(playerid, PlayerName[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PlayerName[playerid], 1);
	
	ServerName = CreatePlayerTextDraw(playerid,587.525756, 429.066625, "~b~~h~RPG.[].RO");
	PlayerTextDrawLetterSize(playerid,ServerName, 0.391434, 1.483333);
	PlayerTextDrawAlignment(playerid,ServerName, 2);
	PlayerTextDrawColor(playerid,ServerName, -1);
	PlayerTextDrawSetShadow(playerid,ServerName, 1);
	PlayerTextDrawSetOutline(playerid,ServerName, 0);
	PlayerTextDrawBackgroundColor(playerid,ServerName, 255);
	PlayerTextDrawFont(playerid,ServerName, 1);
	PlayerTextDrawSetProportional(playerid,ServerName, 1);
	return 1;
}
