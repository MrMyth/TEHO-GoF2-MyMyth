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
		case "First time":
			dialog.text = "So, you're the thief who stole my map!";
			link.l1 = "What the..?! What are you babbling about? I've never seen you before, how could I steal anything from you?";
			link.l1.go = "2";
		break;

		case "2":
			dialog.text = "Oh, of course you didn't! You just found it lying on the ground. And the other half of it too, since you made it all the way here. Right?";
			link.l1 = "Look, I don't know why you think I stole it, but you're mistaken. How did YOU get here, by the way?";
			link.l1.go = "3";
		break;

		case "3":
			dialog.text = "I simply followed you, after I found out it was you who stole the map.";
			link.l1 = "And how did you find out it was me who stole the map? Easy now, just curious.";
			link.l1.go = "4";
		break;

		case "4":
			dialog.text = "Enough! I came here to cut you up, not chat you up, and now I'm going to do just that. Defend yourself!";
			link.l1 = "Oh, the hell with it...";
			link.l1.go = "Exit";
		break;

//grotto - dialog 2

		case "5":
			dialog.text = "Blast, you're a tough one. Why'd you stop? Come on, let's finish this!";
			link.l1 = "Look, if I wanted to kill you, you'd already be dead. What I want is to know why you think I stole your map. And why you think it's yours in the first place.";
			link.l1.go = "6";
		break;

		case "6":
			dialog.text = "Fair enough then, I'll answer. A strange man approached me not long ago, and gave me a half of the map, claiming he had promised my father he would. One morning not long after, some bastard thief filched the map from me in a tavern whilst my head was packed to the gunnels with hangover. I asked around, searched high and low, and finally found a man who claimed he had seen you talking to an innkeeper, haggling over what looked like a piece of a map. I assumed then, that it was you who stole my map, and that you were looking for the other half. So I decided to let you find it, and then follow you.";
			link.l1 = "Clever. You made one wrong assumption though - while I was indeed looking for the other half of the map, it was in fact your half I was searching for. I already had my piece of it by then, and that I got in the same manner you received yours. What I believed to be your half, I actually bought from that innkeeper - at an utterly insane price I might add. Remind me to have a word with him about selling stolen merchandise without a discount...";
			link.l1.go = "7";
		break;

		case "7":
			dialog.text = "But that means you're...";
			link.l1 = "The one and only. I am at your service, dear step-brother. It is sad that we should be brought together only by such regrettably absurd chance, but I'm more than happy to see you, nonetheless.";
			link.l1.go = "8";
			link.l2 = "Your step-sister. And now, brother dearest, I'm afraid you'll have to die, since I have no intention of sharing my treasure with anyone but me and, well, me. It's time to end our little reunion.";
			link.l2.go = "Exit kill";
		break;

		case "8":
			dialog.text = "Huh... Actually, now that I think about it, it looks less like chance than planning. I think father intended it to go this way - for us to have to find each other to get here. He probably didn't plan the pick pocketry, or the err, fight fightery, but otherwise it fits. Especially the whole business of giving us the half of the map with the other's name on it.";
			link.l1 = "Looks like you're right. I wonder if he wanted us to do something particular with all this gold though. I suppose he could have just left it for us to spend, but that seems a bit easy, not to mention unlikely...";
			link.l1.go = "9";
		break;

		case "9":
			dialog.text = "I don't know, maybe he did. But I do know this - originally, he gathered this fortune together for a purpose. You see, the man that gave me my half of the map also gave me father's diary. Did you know, he had a dream? A dream of founding a new nation in the Caribbean, free from the petty wars and greedy governors of the Old World. A dream to create a better future for the peoples of the Caribbean. He called it Libertania. This money was meant to fund its formation.";
			link.l1 = "'Libertania' eh? Well, that's a big damn dream and no mistake. I wonder if he made much progress in realising it? Besides gathering one hell of a big pile of treasure, that is.";
			link.l1.go = "10";
			link.l2 = "That money has one purpose - the lining of my pockets. Anyone who thinks differently either gets the hell out of my way or dies. Since you're not moving, you'll have to die.";
			link.l2.go = "Exit kill";
		break;

		case "10":
			dialog.text = "He did, but his enemies have gone to great lengths to make people forget about it. Twenty years ago, he amassed a powerful fleet with which to liberate the colonies, but he was betrayed by one of his men. His fleet was intercepted and utterly destroyed in battle by a joint force of English, French and Dutch ships. Our father was killed in that battle, and the nations put great effort into painting him as a vicious pirate scumbag. But, it looks like he made arrangements for us to be separated and hidden. He also made damn sure we'd inherit his treasure and his dreams, now that his deeds have been mostly forgotten.";
			link.l1 = "The bastards did a good job. All my life I thought my old man was 'just' a notorious pirate... Hang on, you just said we'd inherited his dreams. Are you suggesting that we should...";
			link.l1.go = "11";
		break;

		case "11":
			dialog.text = "Yes! Think about it! He went to great lengths to have us meet and find his treasure and his diary - he must have wanted us to finish what he started, to realise his glorious dream! And damn me if it isn't a dream worth pursuing! I don't know if I'll succeed, I don't know if it's even possible TO succeed, but I'm sure as hell going to try. What say you?";
			link.l1 = "Libertania... I like the sound of that. Even if it's the death of me, you can count me in, brother!";
			link.l1.go = "12";
			link.l2 = "You can't seriously be planning to kick the nations - with all their money and ships and power - off the islands just like that! And you're having an even bigger laugh if you think I want any part of this ludicrous plan! I'll just take my rightful half of the treasure and be off. You can do what the hell you like with your half, just leave me out of it.";
			link.l2.go = "Exit half";
			link.l3 = "I should've killed you right away and spared my ears these boring broadsides. Time to correct that mistake!";
			link.l3.go = "Exit kill";
		break;

//grotto - dialog 3

		case "12":
			dialog.text = "You know, it's nice to have a real family at last...";
			link.l1 = "Yeah, it is... ... So anyway, how does one go about creating a new nation?";
			link.l1.go = "13";
		break;

		case "13":
			dialog.text = "I haven't got the slightest idea to be honest. But I think I know someone who does. Father often mentions a certain Robert Staffordshire in his diary - it seems he was father's chief advisor on matters of state. I made some inquiries about him not long ago, and it turns out he's still alive and living on Isla Mona. I'm not sure if he'll help us, but he's our best bet anyway. I think we should go there and look him up.";
			link.l1 = "Agreed. If he worked with our father, he might be inclined to help us too.";
			link.l1.go = "14";
		break;

		case "14":
			dialog.text = "I'll go on ahead and arrange a meeting with him then. We'll wait for you in the tavern on Isla Mona.";
			link.l1 = "I'll be there.";
			link.l1.go = "Exit grotto end";
		break;

	case "15":
				//15
		//during advisor quest
		NextDiag.TempNode = "15";
			dialog.text = "Don't underestimate Marcus Le Sanguinaire. Many have made that mistake, and now their bones rot in the corals. He might be an idiot and a show-off, but he's a very well equipped one, and his crew is quite experienced.";
			link.l1 = "Thanks for the advice, I'll bear it in mind.";
			link.l1.go = "Exit";
		break;
//after advisor quest done

		case "16":
			dialog.text = "I think he's right you know, you'll do better with the captains than me. I can handle the traders and the loan Sharps just fine, I've had a lot of dealings with them already.";
			link.l1 = "Yeah, I was thinking the same thing. I'll leave that lot to you.";
			link.l1.go = "17";
		break;

		case "17":
			dialog.text = "Then I'll be on my way. We have much to do. I expect I'll be back in about two weeks, but it may take longer.";
			link.l1 = "Take care. I'd hate to lose you now.";
			link.l1.go = "18";
		break;

		case "18":
			dialog.text = "What a nice thing to say, Beatrice. I didn't think you cared much...";
			link.l1 = "I do actually, more than you think. Anyway - Godspeed.";
			link.l1.go = "Exit";
		break;

//boss killed rant

		case "19":
			dialog.text = "I'm the new boss around here. Got a problem with that?";
			link.l1 = "...";
			link.l1.go = "20";
		break;

		case "20":
			dialog.text = "No? I thought not. Now pin back your lugholes and listen good. In two weeks, I'm calling together a meeting of all free captains as are able to attend. I'll not tell you why I'm calling this meeting, but trust me, it affects everyone, and it'll take place here, in MY new residence.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

//at pirate meeting - autodialog 2

		case "21":
			dialog.text = "Gentlemen. I'm not a great speaker, so I'll get straight to the point. Some of you will remember - or will have heard - of my father - Nicolas Sharp. Some twenty years ago, he tried to create a new nation, here, on the islands. Libertania - a free nation. Free from the greedy exploitation of the Old World, free from their petty wars that serve no purpose other than the inflation of a king's ego, or his treasury. As you may also know, he failed - betrayed by one of his own men, his fleet was vanquished. However, what you certainly do not know is just how close he was to success. Here, now, I am just as close to fulfilling his dream, and have taken great care not to repeat his mistakes, but I can not win alone - I need you, free men with free ships, to fight against those who would stifle and control you, who impose their laws and their wars upon you. I am not asking you to do any more than you usually do - disrupt their shipping lanes, sink their convoys, harass their patrols - but I ask you to do it for something more than just loot and infamy. I ask you to do it for freedom! For liberty! For the betterment of every man, be he pirate or landlubber! I'm asking you now - who will step forward and join me in creating a brave new world for all! What say you?";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

//at pirate meeting

		case "22":
			dialog.text = "You doubt. You doubt Beatrice and the reality of her dreams. Well let me tell you - if there is anyone who can make such dreams real in this room, it's her. You hesitate. You hesitate because it seems like an impossible goal. But consider this - a chance to change the world is a rare thing. Precious few people ever get such a chance, and nobody ever gets it twice. Right here, right now, you have that chance. Take it, and use it to make a name for yourself that will live a thousand years after your corpse is one with the sea! Take it, and show all those bastards what it really means to be a free captain...";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

//at pirate meeting - autodialog 2

		case "23":
			dialog.text = "Gentlemen. I thank you, and applaud you. You will not regret this. Now gather round, we have much to discuss...";
			link.l1 = "...";
			link.l1.go = "23_exit";
		break;

		case "23_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_Sharp50");
		break;

		case "24":
			dialog.text = "...you know what to do now, gents. Do it well, and victory will be ours. Dismissed.";
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

//after pirate meeting

		case "25":
			dialog.text = "Well well, Beatrice. Looks like you've done it. Congratulations!";
			link.l1 = "WE did it, Blaze, WE. If it wasn't for your encouragement speech, they'd have just walked out on me.";
			link.l1.go = "26";
		break;

		case "26":
			dialog.text = "Well, if you insist. So... what do you suppose we should do now, dear step-sister?..";
			link.l1 = "Well, I can think of a few things that need attending to.";
			link.l1.go = "27";
		break;

		case "27":
			dialog.text = "Right, let's find somewhere quiet and have it all out.";
			link.l1 = "Aye-aye, Cap'n!";
			link.l1.go = "28";
		break;

		case "28":
			dialog.text = "It's quite a big place. There must be a spare room around here somewhere.";
			link.l1 = "I'll bet Karlos had himself some nice quarters. They should do nicely...";
			link.l1.go = "Exit";
		break;
//exits

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "Exit kill":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_Sharp10");
		break;
		case "Exit go to Pirates":
			AddDialogExitQuest("Story_Sharp15");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		case "Exit half":
			AddDialogExitQuest("Story_Sharp12");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}