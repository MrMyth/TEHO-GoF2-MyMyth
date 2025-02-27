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
		//1
			//first time
			dialog.text = "So, you're Sharp's kids, eh? Hmm... You don't really look like him...";
			link.l1 = "That as may be, but his memory and his spirit live on in us, and his ideals burn within us too. Libertania ring a bell?";
			link.l1.go = "2";

		break;

		case "2":
			dialog.text = "Now that, that I recognise. You sounded just like him there. All right then. I assume you have his diary - that was part of his plan too. And now you want to finish building the grand dreams he started to?";
			link.l1 = "Couldn't have said it better myself. And for that, we need your help sir.";
			link.l1.go = "3";
		break;

		case "3":
			dialog.text = "Ah, of course. You want to establish an independent state, but have no idea how to do it. A family trait, it seems.";
			link.l1 = "Err, well, yes. Err, Probably.";
			link.l1.go = "4";
		break;

		case "4":
			dialog.text = "If you're going to create a nation, you'll need to be a wee bit more eloquent than that. Oh well, I suppose we'll have to make do with what little we have. Yes, I can help you, of this there's no doubt. But first you must help me.";
			link.l1 = "Ha, how did I know that was coming? All right then sir, how might we aid you, this fine day?";
			link.l1.go = "5";
		break;

		case "5":
			dialog.text = "Now now, no need for sarcasm. Save it for matters of state, it's appreciated more there. Now pay attention. There's a certain pirate who's been a thorn in my side for longer than I care to remember, and now my patience with him has run out.";
			link.l1 = "Ah ha, let me guess. You want me to Sink his ship? Rip his head off? I know! I should run his cargo all over the Caribbean and pick up passengers for him from every damn island, whilst simultaneously collecting little scraps of paper for him and singing 'A Pirate's Life for Me' ?";
			link.l1.go = "6";
		break;

		case "6":
			dialog.text = "Hmm. I can see you've inherited your father's character. Look, do whatever you want with his ship, as long as her captain ends up as finely chopped chum. He frequents the waters around Isla Mona, so you'll have no trouble finding the stinking little bilge rat. He goes by the name of Marcus Le Sanguinaire, if you can believe that, and his ship, 'Bloody Michelle'.";
			link.l1 = "Right then. Doesn't seem like I have a choice really. I just hope you keep your end of the deal - for your own sake.";
			link.l1.go = "7";
		break;

		case "7":
			dialog.text = "Oh, don't worry, I will. Your father's dream was mine too. But I must be sure you have what it takes, and I absolutely must be rid of that fool Marcus. Hence, this little escapade should solve both my problems - if you're up to it, of course.";
			link.l1 = "Oh, don't worry. I'm more than capable. And don't you go anywhere either, this shouldn't take too long.";
			link.l1.go = "Exit";
		break;

		case "8":
				NextDiag.TempNode = "8";
			dialog.text = "I'm afraid we've got nothing to talk about while Marcus Le Sanguinaire continues to befoul the world with his presence.";
				link.l1 = "Right, yes, I'm on it.";
				link.l1.go = "Exit";
		break;
		case "9":
		FreeSitLocator("Pirates_tavern", "sit_front2");
			dialog.text = "I've been told that you defeated Marcus Le Sanguinaire. Brilliant! Now I'm convinced that you're capable of dealing with the formidable tasks that lies ahead of you.";
				link.l1 = "You can not even begin to imagine the depth of my relief. I shall forever praise your name in my prayers for all the priceless help you've rendered me. I'm so overjoyed at your recognition of my abilities, that I think I shall go into an ecstatic seizure on the spot!";
				link.l1.go = "10";
		break;
		case "10":
			dialog.text = "Hmm, yes, your eloquence seems to have magically improved since last we spoke. No need to practice it on my old ears any further, I get the message quite clearly. Settle down then, this will take some explaining, so listen well...";
			link.l1 = "Listen to his ramblings.";
			link.l1.go = "10_exit";
		break;

		case "10_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_Sharp22");
		break;

		case "11":
			dialog.text = "...and that's just about all there is worth knowing about building a nation. Plainly, it is not an easy task, but not as hellishly difficult as those already in power would have you believe, either.";
			link.l1 = "So let me summarise all that. We need a fleet to harass the nations' supply and military convoys, we need the support of the traders and bankers, and we need to liberate all the colonies from their Old World oppressors... Piece of hardtack!";
			link.l1.go = "12";
		break;

		case "12":
			dialog.text = "Well, I'm glad you don't feel overwhelmed by the challenge, although it would help if you took it a little more seriously. May I suggest that someone other than yourself take care of sweet-talking the traders and bankers? You seem to be more the cannons and cutlasses type, and thus are perfectly suited to assembling the fleet.";
			link.l1 = "Couldn't agree more. Excuse me for a moment.";
			link.l1.go = "12_Exit";
		break;

	case "12_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_Sharp24");
		break;
		case "13":
		dialog.text = "Good. Now that we've taken care of that part, let's concentrate on assembling a fleet. Any thoughts in this department?";
		link.l1 = "Hmm. To be honest, I thought you'd have an idea... Well, we don't need an armada - we can't hope to match the nations ship for ship. What we really need is a fleet of privateers, able to operate independently and respond quickly to any situation.";
		link.l1.go = "14";
		break;
		case "14":
			dialog.text = "My thoughts exactly. And I assume you already see a way to assemble such a fleet?";
			link.l1 = "Actually, yes, I do. The independent captains and various pirates - often one and the same - would be the logical choice to rally under our flag. The problem is to get them all, or most of them, or at least the most notorious of them, to listen to me.";
			link.l1.go = "15";
		break;

		case "15":
			dialog.text = "I think I know of a way to make them listen. As I'm sure you know, this island, being a pirate haven, is also home to the residence of their 'Leader' - although his functions are mostly those of arbiter, in disputes and suchlike. Still, his position is highly respected, and his word carries real weight with many pirates.";
			link.l1 = "Somehow, I doubt he'll listen to me - he would think I'm trying to usurp his power - and for the most part - he'd be right, too. Hell, his guards won't even let me in the front door.";
			link.l1.go = "16";
		break;

		case "16":
			dialog.text = "All true. You can't possibly hope to persuade him, but you can take his place, and persuade the others. You see, it's an old tradition among pirates that the Leader may be challenged to a fight to the death, when one disagrees with him or thinks he would make a better Leader. Refusing such a challenge would be considered cowardice of the foulest sort, and the Leader would loose any and all respect he has.";
			link.l1 = "Ah, I see. Just go in there, challenge him to a duel, and kill him? I suspect it's not that easy really, is it?";
			link.l1.go = "17";
		break;

		case "17":
			dialog.text = "Well, no, actually it isn't. Karlos is considered the best duellist in the Caribbean. They say that nobody who faced him in a duel lasted more than a minute. But if you do succeed in defeating him, you will succeed him, allowing you to call a meeting of the most notorious captains, and address them with real authority.";
			link.l1 = "Best duellist, eh? I do like a challenge. I think I'll go and pay him a visit then...";
			link.l1.go = "18";
		break;
		
			case "18":
			dialog.text = "I wish you luck. I look forward to your return.";
			link.l1 = "";
			link.l1.go = "Exit";
		break;

		case "19":
				NextDiag.TempNode = "19";
			dialog.text = "You have more pressing matters than talking to an old duffer like me, captain - you've got a duel to win.";
			link.l1 = "Right.";
			link.l1.go = "Exit";
		break;
		case "20":
				NextDiag.TempNode = "20";
				dialog.text = "You actually did it! Damn, that was as spectacular a fight as I've ever seen. Now all you have to do is convince the other captains. They'll be arriving here soon.";
				link.l1 = "Indeed. I suspect that will be the hardest part.";
				link.l1.go = "Exit";
		break;
		case "21":
		NextDiag.TempNode = "21";
		dialog.text = "You should go and see the captains now, they've already assembled at Krieger's old residence. Good luck! You'll need it.";
		link.l1 = "Thanks. I'll go and talk to them now.";
		link.l1.go = "Exit";
		break;
		case "22":
						NextDiag.TempNode = "22";
			dialog.text = "Well well captain, you impress me beyond all expectations! You've managed to get the pirates and the independent captains to work for you, and now that they're all harassing the nations' supply lines, it should be possible for a single well-equipped squadron to take all the colonies before they realise what's going on and call for help from Europe.";
			link.l1 = "Heh, yeah. I just wish all those forts didn't have so many damn cannons...";
			link.l1.go = "Exit";
		break;
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}