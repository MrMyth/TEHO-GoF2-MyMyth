// диалог по городам
void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{
    switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat(RandPhraseSimple("What questions do you have?", "How can I help you, " + GetAddress_Form(NPChar) + "?"), "You tried to ask me some question not long ago, " + GetAddress_Form(NPChar) + "...", "Over this whole day, this is the third time you're talking about some question...",
                          "More questions, I presume?", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat(RandPhraseSimple("I've changed my mind...", "I've got nothing to talk about at the moment."), "Umph, where has my memory gone...",
                      "Yes, it really is the third time...", "No, what questions?...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (CheckAttribute(PChar, "questTemp.Guardoftruth.Archy") && pchar.questTemp.Guardoftruth.Archy == "islatesorotavern")
			{
				link.l1 = "Listen, "+npchar.name+", have you heard anything about a man named Miguel Dichoso? They say, his ship has been seen within waters of Isla Tesoro...";
				link.l1.go = "guardoftruth";
			}
			         if (pchar.RomanticQuest == "BrotherIsDead") 
			{				
                link.l1 = HeroStringReactionRepeat("Hey, do you know where Atila is hanging out these days?",
                "Yes, yes, we talked about Atila...", "Oh yes, truly...", "Ah, already figured it out. Sorry...", npchar, Dialog.CurrentNode);
                link.l1.go = DialogGoNodeRepeat("Step_Romantic_1", "", "", "", npchar, Dialog.CurrentNode);
            }
			if(CheckAttribute(pchar, "questTemp.Tieyasal") && pchar.questTemp.Tieyasal == "begin" && !CheckAttribute(npchar, "quest.Tieyasal"))
			{
				link.l1 = "Listen, "+npchar.name+", haven't you seen Miguel Dichoso lately on Isla Tesoro?";
				link.l1.go = "tieyasal";
			}
				if (pchar.questTemp.BlueBird == "toBermudes")
			{
				link.l1 = "Listen, friend, have you heard anything interesting in the tavern about a xebec called the 'Blue Bird'?";
				link.l1.go = "BlueBird_1";
			}
		break;
			case "Step_Romantic_1":
    		dialog.text = "I do know he bought a house here in town. So he should be there.";
    		link.l1 = "Thanks, pal...";
    		link.l1.go = "exit";
 		break;
				case "BlueBird_1":
			dialog.text = NPCStringReactionRepeat("I've heard a lot of things. Mostly, they say the ship is very fast. They tried to catch it, but to no avail...", 
				"We've already gone over this.", 
				"Again? We've already discussed everything.",
                "Excuse me... If you don't need anything, I must tend to other customers.", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("So who tried to catch it?", 
				"Yeah, that's for sure...",
                "Hm, indeed.", 
				"Fine...", npchar, Dialog.CurrentNode);
			link.l1.go = DialogGoNodeRepeat("BlueBird_2", "exit", "exit", "exit", npchar, Dialog.CurrentNode);
		break;

		case "BlueBird_2":
			dialog.text = "Many tried... and failed, ha-ha!";
			link.l1 = "Do you know anything useful? Like... Where do they usually meet her?";
			link.l1.go = "BlueBird_3";
		break;
		case "BlueBird_3":
			dialog.text = "Why, right here in Bermuda. Nothing rivals the 'Blue Bird' when it comes to dodging our reefs. Time and time again galleons and frigates collide into them while pursuing the xebec. They often end up at the bottom!";
			link.l1 = "You don't say... Well then, I'll keep looking. Listen, um, the local shopkeeper... What kind of man is he?";
			link.l1.go = "BlueBird_4";
		break;
		case "BlueBird_4":
			dialog.text = "He possesses much authority and is respected among the merchants.";
			link.l1 = "I understand... Is there anyone who's in bad standing with the shopkeeper?";
			link.l1.go = "BlueBird_5";
		break;
		case "BlueBird_5":
			dialog.text = "He doesn't have any open enemies, but I think the former owner of the store has a grudge against him, he-he...";
			link.l1 = "Would you be so kind as to tell me his name?";
			link.l1.go = "BlueBird_6";
		break;
		case "BlueBird_6":
			dialog.text = "His name is John Norton. You won't find him in Bermuda anymore. I heard he settled in Puerto Principe, quietly plying his trade and doesn't get out much.";
			link.l1 = "A big thank you, my friend. You're a good innkeeper.";
			link.l1.go = "BlueBird_7";
		break;
		case "BlueBird_7":
			dialog.text = "Thanks for the compliment, " + GetAddress_Form(NPChar) + ". Good luck to you!";
			link.l1 = "And best wishes to you, pal.";
			link.l1.go = "exit";
			AddQuestRecord("Xebeca_BlueBird", "3");
			pchar.questTemp.BlueBird = "toPuertoPrincipe";
		break;

		case "guardoftruth":
			dialog.text = "I have. That Spanish don sold Shark Dodson a remarkable ship, a frigate, when he still resided here. Eh that ship... She was an incredible...";
			link.l1 = "Let me guess: a uniquely outlined frame and capable of reaching a speed of sixteen knots? And her name was 'Santa Quitaria'?";
			link.l1.go = "guardoftruth_1";
		break;
		
		case "guardoftruth_1":
			dialog.text = "As for the frame and the speed, you're absolutely correct, but she had a different name: 'San Martin'. Shark paid a whole heap of gold to that rogue for that ship.";
			link.l1 = "Are you sure it was 'San Martin' and not 'Santa Quiteria'? And when was that deal formulated? And why did you call Dichoso a rogue?";
			link.l1.go = "guardoftruth_2";
		break;
		
		case "guardoftruth_2":
			dialog.text = "Absolutely sure that it was 'San Martin', because I personally witnessed how Alexus's workers were tearing a plate with this papist name from the stern. Shark Dodson named her 'Fortune', much more suitable name for such beauty. He had bought it at winter of 1654, not long before Blaze was murdered\nWhy did I call don Miguel a rogue? Because he had stolen this ship from Spanish navy of Providence's military base. Dodson set a performance with fire and smoke for St. Juan's fort and its garrison, as he was always telling me while he was drunk. Shark sacrificed with two damaged luggers in order to make the fight with the frigate look persuasively\nWhen the night had come, he secretly took 'San Martin' to Isla Tesoro. Shark got ship and Dichoso got money. Sly bastard later told his higher-ups that the frigate was sunk during the fight with pirate fleet, St. Juan's fort commandant confirmed it.";
			link.l1 = "Oh, those Spanish dons puff up their pockets! What a dodger! Tell me, are you sure that happened in the winter of 1654? Could it have been during the spring? And didn't that frigate show signs of wear and tear from the storm?";
			link.l1.go = "guardoftruth_3";
		break;
		
		case "guardoftruth_3":
			dialog.text = "I'm pretty sure it was winter... Oh, who knows. Maybe it was spring. I don't remember for sure. The frigate wasn't worn down at all it was brand spickin new.";
			link.l1 = "And where is that beauty of a frigate now?";
			link.l1.go = "guardoftruth_4";
		break;
		
		case "guardoftruth_4":
			dialog.text = "A dark story, it is... When Blaze was murdered, everyone suspected Shark because his trinket, a shark's tooth, was found on the corpse. Plus, some people saw Shark in Blaze's residence that night\nShark had escaped Isla Tesoro before they gave him a black mark. He paid a visit to Dark Pastor and exchanged his frigate for a brig. No clue where the man is now. Zachary has sold the frigate to William Patterson later.";
			link.l1 = "Who is this Patterson?";
			link.l1.go = "guardoftruth_5";
		break;
		
		case "guardoftruth_5":
			dialog.text = "What, you've never heard of Willie Patterson? The Scot, just arrived to the Caribbean, big shot, captain of the royal fleet, Colonel Fox's favorite himself? By the way, he started twiddling some business with Jackman too. He's a part of a powerful squadron and his flagship is 'Fortuna' herself.";
			link.l1 = "I see. Do you know where Dichoso is right now?";
			link.l1.go = "guardoftruth_6";
		break;
		
		case "guardoftruth_6":
			dialog.text = "I have no idea. After that jiggery pokery with 'Fortuna' I haven't seen him on Isla Tesoro again and I haven't heard anything about him.";
			link.l1 = "All right, "+npchar.name+", thanks for the in-depth information! You're an excellent tavern keeper! I wish there were more people like you... Bye!";
			link.l1.go = "guardoftruth_7";
		break;
		
		case "guardoftruth_7":
			dialog.text = "Good luck, "+pchar.name+"!";
			link.l1 = "...";
			link.l1.go = "guardoftruth_8";
		break;
		
		case "guardoftruth_8":
			DialogExit();
			AddQuestRecord("Guardoftruth", "60_1");
			pchar.questTemp.Guardoftruth.Archy = "guadeloupe";
			// маленькая развлекуха
			pchar.quest.GuardOT_cabinattack.win_condition.l1 = "EnterToSea";
			pchar.quest.GuardOT_cabinattack.function = "GuardOT_PrepareCreateBandosInCabin";
		break;
		
		case "tieyasal":
			dialog.text = "It looks as if both of you are chasing each other, buddy. Yes, Dichoso was here right where you're standing. And in the exact way he was interrogating about you that last time you were in Sharptown.";
			link.l1 = "Damn it! That's the news... And where's Miguel right now?";
			link.l1.go = "tieyasal_1";
		break;
		
		case "tieyasal_1":
			dialog.text = "I've got no idea. He's departed out to sea where... he said something about Blueweld. He probably went there just looking for you.";
			link.l1 = "Do you happen to be the one that sent him to Blueweld?";
			link.l1.go = "tieyasal_2";
		break;
		
		case "tieyasal_2":
			dialog.text = "No. All I told him was that I hadn't been seen you in for long time.";
			link.l1 = "I see. Alright, then. Thanks, buddy!";
			link.l1.go = "tieyasal_3";
		break;
		
		case "tieyasal_3":
			DialogExit();
			AddQuestRecord("Tieyasal", "3");
			npchar.quest.tieyasal = "true";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1 = "location";
			pchar.quest.Tieyasal_ITAttack.win_condition.l1.location = "Bermudes";
			pchar.quest.Tieyasal_ITAttack.function = "Tieyasal_CreateITShips";
		break;
	}
	UnloadSegment(NPChar.FileDialog2);  // если где-то выход внутри switch  по return не забыть сделать анлод
}