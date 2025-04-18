
int CreateBermudesCharacters(int n)
{
	ref ch;
	
	///////////////////////////////////////////////////////////////////////////////
	// ОСНОВНЫЕ ПЕРСОНАЖИ
	///////////////////////////////////////////////////////////////////////////////
		
		makeref(ch,Characters[n]);			//Глава пиратов
	ch.id		= "SharpPirateLead";
	ch.name 	= "Karlos";
    ch.lastname = "";
	ch.rank = 30;
	ch.model	= "capitan";
	ch.sex = "man";
	ch.model.animation = "man";
	ch.City = "Pirates";
	ch.location	= "Pirates_townhall";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mayor\Karlos.c";
	ch.nation = PIRATE;
	ch.quest.type = "hovernor";
	ch.reputation = "35";
    SetRandSPECIAL(ch);
    SetSelfSkill(ch, 90, 90, 90, 70, 90);
    SetShipSkill(ch, 90, 80, 70, 10, 10, 20, 10, 10, 50);
	GiveItem2Character(ch, GUN_COMMON);
	ch.equip.gun = GUN_COMMON;
	GiveItem2Character(ch, BLADE_LONG);
	ch.equip.blade = BLADE_LONG;
	ch.Ship.Name = "Manchester";
	ch.Ship.Type = GenerateShip(SHIP_CORVETTE, true);
	ch.Ship.Stopped = true;
    SetCrewQuantityFull(ch);
    Fantom_SetBalls(ch, "pirate");    
	ch.rank 	= 20;
	ch.reputation = "25";
	ch.money = "25000";
	ch.greeting = "Gr_HeadPirates";
	SetCharacterPerk(ch, "FastReload");
	SetCharacterPerk(ch, "HullDamageUp");
	SetCharacterPerk(ch, "SailsDamageUp");
	SetCharacterPerk(ch, "CrewDamageUp");
	SetCharacterPerk(ch, "CriticalShoot");
	SetCharacterPerk(ch, "LongRangeShoot");
	SetCharacterPerk(ch, "CannonProfessional");
	SetCharacterPerk(ch, "ShipDefenseProfessional");
	SetCharacterPerk(ch, "ShipSpeedUp");
	SetCharacterPerk(ch, "ShipTurnRateUp");
	SetCharacterPerk(ch, "SwordplayProfessional");
	SetCharacterPerk(ch, "AdvancedDefense");
	SetCharacterPerk(ch, "CriticalHit");
	SetCharacterPerk(ch, "Sliding");
    SetSelfSkill(ch, 90, 90, 90, 60, 70);
    SetShipSkill(ch, 100, 10, 100, 100, 90, 60, 80, 90, 50);
	LAi_NoRebirthDisable(ch);
	LAi_RebirthOldName(ch);
	LAi_SetHuberType(ch);
    LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);		// ОФициантка
	ch.id		= "Pirates_waitress";
	ch.model	= "women_7";
	ch.sex = "woman";
	ch.City = "Pirates";
	ch.location	= "Pirates_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
	ch.Dialog.Filename = "Waitress_dialog.c";
	ch.greeting = "Waitress";
	ch.nation = PIRATE;
	LAi_SetWaitressType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Трактирщик
	ch.id		= "Pirates_tavernkeeper";
	ch.model	= "Tuerto";
	ch.greeting = "barmen_1";
	ch.name		= "One-eyed";
	ch.lastname = "";
	ch.sex = "man";
	ch.City = "Pirates";
	ch.location	= "Pirates_Tavern";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Tavern.c";
	ch.TavernMan = true;
	ch.nation = PIRATE;
	LAi_SetBarmanType(ch);
	LAi_RemoveLoginTime(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			//Торговец
	ch.id		= "Pirates_trader";
	ch.name		= "Pascal";
	ch.lastname = "Voisier";
	ch.model	= "Pasquale";
	ch.greeting = "store_3";
	ch.sex = "man";
	ch.City = "Pirates";
	ch.location	= "Pirates_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Common_Store.c";
	ch.quest.type = "trader";
	ch.nation = PIRATE;
	LAi_SetBarmanType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	ch.item_date = "";
	// настройка магазина -->
	ch.Storage 	  = true; // можем завести склад
	ch.StoreNum   = Pirates_STORE;
	ch.from_sea   = "Pirates_town";
	// настройка магазина <--
	n = n + 1;

	makeref(ch,Characters[n]);			//Корабел
	ch.id		= "Pirates_shipyarder";
	ch.model	= "Alexus";//"trader_15";
	ch.model.animation = "man_A1";
	ch.greeting = "Gr_shipyarderA";
	ch.name 	= "Master";
    ch.lastname = "Alexis";
	ch.sex = "man";
	ch.City = "Pirates";
	ch.location	= "Pirates_Shipyard";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Common_Shipyard.c";
	ch.nation = PIRATE;
	ch.quest.shiping = "0";
	//LAi_SetHuberType(ch);
	LAi_SetCitizenTypeNoGroup(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	LAi_SetImmortal(ch, true);
	n = n + 1;

	makeref(ch,Characters[n]);			// Норман
	ch.id		= "Norman";
	ch.name 	= "Abraham";
	ch.lastname = "Norman";
	ch.model	= "Norman_1";
    ch.rank     = 45;
	ch.sex = "man";
    ch.model.animation = "Norman"; 
	ch.City = "Pirates";
	ch.location	= "Pirates_town";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Quest\Sharlie\Norman.c";
	ch.dialog.currentnode = "norman_us";
	ch.greeting = "Norman_1";
	ch.nation = PIRATE;
	ch.MultiFighter = 2.5; // мультифайтер
	TakeNItems(ch, "potion2", 20);
	TakeNItems(ch, "bullet", 100);
	TakeNItems(ch, "gunpowder", 100);
	GiveItem2Character(ch, "pistol5");
	GiveItem2Character(ch, "blade_29");
	EquipCharacterbyItem(ch, "pistol5"); 
	EquipCharacterbyItem(ch, "blade_29");
	LAi_SetCharacterUseBullet(ch, "bullet");
	SetSPECIAL(ch, 10, 10, 10, 5, 5, 10, 5);
	LAi_SetHP(ch, 700, 700);
    SetSelfSkill(ch, 100, 100, 100, 100, 100);
	LAi_SetLoginTime(ch, 11.0, 20.0);
	LAi_SetWarriorType(ch);
	LAi_group_MoveCharacter(ch, "PIRATE_CITIZENS");
	//LAi_SetImmortal(ch, true);
	n = n + 1;

	return n;
}
