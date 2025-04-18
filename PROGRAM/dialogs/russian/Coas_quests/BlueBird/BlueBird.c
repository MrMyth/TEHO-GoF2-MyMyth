void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag, forName;
	string sTemp, sTitle;
	int iTemp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = "Nothing to say.";
			link.l1 = "Okay...";
			link.l1.go = "exit";	
			NextDiag.TempNode = "First time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "BlueBirdCapitain":
			dialog.text = "I'd like to know who you are.";
			link.l1 = "I'm called " + GetFullName(pchar) + ". I'm a privateer.";
			link.l1.go = "BlueBirdCapitain_1";
		break;
		case "BlueBirdCapitain_1":
			dialog.text = "Why the hell did you attack my xebec?!";
			link.l1 = "Just orders. I have to send you to the bottom. You ruined our relations with the merchants...";
			link.l1.go = "BlueBirdCapitain_2";
		break;
		case "BlueBirdCapitain_2":
			dialog.text = "And a privateer's saying this?! I don't think you pity the merchants that much...";
			link.l1 = "This is work, pal. Nothing personal. Why don't you tell me how you and Pascal keep in touch. Just curious, mind. It was too difficult to find you.";
			link.l1.go = "BlueBirdCapitain_3";
		break;
		case "BlueBirdCapitain_3":
			dialog.text = "?Caramba! That ain't your business! Thanks for letting me catch my breath, and let's continue!";
			link.l1 = "Well, fair enough...";
			link.l1.go = "BlueBirdCapitain_4";
		break;		
		case "BlueBirdCapitain_4":
			LAi_SetCurHPMax(npchar);
			QuestAboardCabinDialogExitWithBattle(""); 
            DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;	
		//капитаны флейтов торговцев
		case "BlueBirdTrader":
			dialog.text = "Damn it, why the hell did you attack us?!";
			link.l1 = "This is revenge for your owner, pal. I got nothing against you.";
			link.l1.go = "BlueBirdTrader_1";
		break;
		case "BlueBirdTrader_1":
			dialog.text = "Good to hear...";
			link.l1 = "Take your lifeboats, and with the remains of your team go back to your owner. Tell him that " + GetFullName(pchar) + " sends him a hello.";
			link.l1.go = "BlueBirdTrader_2";
		break;
		case "BlueBirdTrader_2":
			dialog.text = "Sure, I'll give him a hello.";
			link.l1 = "Then that's that. Live for now...";
			link.l1.go = "BlueBirdTrader_3";
		break;
		case "BlueBirdTrader_3":
			QuestAboardCabinDialogNotBattle(); 
            DialogExit();
		break;	

	}
}