void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	DeleteAttribute(&Dialog,"Links");
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	switch(Dialog.CurrentNode)
	{
		case "OffMushketer":
			dialog.text = "Welcome, noble visitor! What brings you here?";
			link.l1 = "Just want to get acquainted. The name's Captain " + GetFullName(pchar) + ".";
			link.l1.go = "OffM_1";
		break;
		case "OffM_1":
			dialog.text = "Good to meet you, Captain. What can I do for you?";
			link.l1 = "Well, nothing in particular... You look like a military man. Still in service?";
			link.l1.go = "OffM_2";
		break;
		case "OffM_2":
			dialog.text = "No, already let go.";
			link.l1 = "I see. What was your specialty?";
			link.l1.go = "OffM_4";
		break;
		case "OffM_4":
			dialog.text = "I was a musketeer. Best shot in the regiment!";
			link.l1 = "Oho! That's just the kind of man I need. Would you like to join my crew, as an officer?";
			link.l1.go = "OffM_5";
		break;
		case "OffM_5":
			dialog.text = "Thank you for the offer, but I must decline.";
			link.l1 = "Oh? Why? If you don't mind my asking, that is.";
			link.l1.go = "OffM_6";
		break;
		case "OffM_6":
			dialog.text = "Well, it's... a bit complicated. I've got a problem. I... well, I can't hold a weapon.";
			link.l1 = "That's strange. How did you fight in the army?";
			link.l1.go = "OffM_7";
		break;
		case "OffM_7":
			dialog.text = "It wasn't always a problem! You see, at one point I came to own a rare British musket. It had two barrels, and a sophisticated breach that allowed for rapid loading. Real work of art, by a real master. I got so used to that gun, that now I just can't use any other.";
			link.l1 = "That's... interesting. So where is the musket now?";
			link.l1.go = "OffM_8";
		break;
		case "OffM_8":
			dialog.text = "It hurts to talk about. You see... When I was sailing here from the Old World, our ship was attacked by pirates. I wanted to fire on them, and had I done so I probably would have slain many - but my own crew jumped me, and tied me up!";
			link.l1 = "Trust me, they did the right thing. At least you're alive.";
			link.l1.go = "OffM_9";
		break;
		case "OffM_9":
			dialog.text = "Alive, maybe! But without my musket! What life is it without glory!";
			link.l1 = "Well, there must be other nice muskets in the world.";
			link.l1.go = "OffM_10";
		break;
		case "OffM_10":
			dialog.text = "Maybe. Hmm... Listen, if you somehow find my musket, I will follow you wherever you go. I swear it.";
			link.l1 = "Fair enough. Who was it that captured your ship, and when?";
			link.l1.go = "OffM_11";
		break;
		case "OffM_11":
			dialog.text = "It was a couple of years ago, and I've been in a hole since then... I didn't see who the pirates were - I was tied down, with a sack on my head. I heard the crew yelling about some kind of arrow, but I don't know what that means, if anything.";
			link.l1 = "Okay... So this isn't going to be so simple. Never mind, I'll keep my eye out. If I find your musket, I'll definitely return it to you.";
			link.l1.go = "OffM_12";
		break;
		case "OffM_12":
			dialog.text = "Thank you. I won't keep my hopes up, though.";
			link.l1 = "Cheery fellow, aren't you.";
			link.l1.go = "exit";
			SetMushketCapitainInWorld();
			pchar.questTemp.mushket2x2 = true;
			AddQuestRecord("SeekDoubleMushket", "1");
			NextDiag.TempNode = "OffM_result";	
		break;

		case "OffM_result":
			dialog.text = "Did you find my musket?";
			if (CheckCharacterItem(pchar, "mushket2x2"))
			{
				link.l1 = "Yes, here it is. One double musket, like no other.";
				link.l1.go = "OffM_result_1";
			}
			else
			{
				link.l1 = "Yeah, pal, I did. Here it is, a rare two-barreled musket.";
				link.l1.go = "exit";
			}
		break;
		case "OffM_result_1":
			dialog.text = "Not yet, but I'm working on it.";
			link.l1 = "Excellent! This is the start of a new life!";
			link.l1.go = "OffM_result_2";
			TakeItemFromCharacter(pchar, "mushket2x2");
			Npchar.quest.OfficerPrice = sti(pchar.rank)*300;
		break;
		case "OffM_result_2":
			dialog.text = "My word is my bond. I'm ready. But first, let's discuss my honorarium. For my loyal service, I expect in the neighborhood of " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " per month.";
			link.l1 = "A bit much, wouldn't you say?";
			link.l1.go = "OffM_trade";
			link.l1 = "Very well. Agreed.";
			link.l1.go = "OffM_Ok";
		break;
		case "OffM_trade":
			dialog.text = "No, I'm worth whole a lot more.";
			link.l1 = "Very well. Agreed.";
			link.l1.go = "OffM_Ok";
		break;
		case "OffM_Ok":
			Npchar.quest.OfficerPrice.add = sti(pchar.rank)*1000;
			dialog.text = "All right. But there's one more thing. I need a one-time advance, so to speak. I was out of work for a while, and would like to pay off my debts. I think that " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + " should do it.";
			link.l1 = "Are you serious?";
			link.l1.go = "OffM_Ok_1";
		break;
		case "OffM_Ok_1":
			dialog.text = "Of course! Those are my terms. It's all up to you.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "I don't have that kind of money.";
				link.l1.go = "OffM_noMoney";
			}
			else
			{
				link.l1 = "That's... a bit steep for me.";
				link.l1.go = "OffM_noMoney";
				link.l2 = "Oh, all right. Deal.";
				link.l2.go = "OffM_Ok_3";
			}
			NextDiag.TempNode = "OffM_TWO";
		break;
		case "OffM_noMoney":
			dialog.text = "Then come back when you're rich. Best of luck.";
			link.l1 = "Thank you...";
			link.l1.go = "exit";
		break;
		case "OffM_Ok_3":
			dialog.text = "That's different! My loyalty is yours!";
			link.l1 = "Excellent. Welcome to my crew.";
			link.l1.go = "exit_hire";
		break;
		case "exit_hire":
			AddQuestRecord("SeekDoubleMushket", "3");
			CloseQuestHeader("SeekDoubleMushket");
			AddMoneyToCharacter(pchar, -sti(Npchar.quest.OfficerPrice.add));
			npchar.model = "MusketeerEnglish_2";
			npchar.model.animation = "mushketer";
			npchar.MusketerDistance = 5;
			npchar.greeting = "Gr_questOfficer";
			npchar.Dialog.Filename = "Enc_Officer_dialog.c";
			Pchar.questTemp.HiringOfficerIDX = GetCharacterIndex(Npchar.id);
			npchar.OfficerWantToGo.DontGo = true; //не пытаться уйти
			npchar.loyality = MAX_LOYALITY;
			AddDialogExitQuestFunction("LandEnc_OfficerHired");
			NextDiag.CurrentNode = NextDiag.TempNode;
			NPChar.quest.meeting = true;
			DialogExit();
		break;
		case "OffM_TWO":
			dialog.text = "So, how's the moneymaking? In case you forgot, I'm looking for a one-time fee of " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice.add)) + ", in addition to my " + FindRussianMoneyString(sti(Npchar.quest.OfficerPrice)) + " a month.";
			if (sti(pchar.money) < sti(Npchar.quest.OfficerPrice.add))
			{
				link.l1 = "No, that's still ridiculous.";
				link.l1.go = "OffM_noMoney";
			}
			else
			{
				link.l1 = "This is very expensive for me.";
				link.l1.go = "OffM_noMoney";
				link.l2 = "Very well, I agree.";
				link.l2.go = "OffM_Ok_3";
			}
			NextDiag.TempNode = "OffM_TWO";
		break;
				case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}