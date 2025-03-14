void ProcessCommonDialogEvent(ref NPChar, aref Link, aref NextDiag)
{

	switch (Dialog.CurrentNode)
	{
		case "quests":
			dialog.text = NPCStringReactionRepeat("Ask. What do you need?",
                          "We've just raised that topic. I gather you have forgotten...", "This is the third time today you've been talking about some question...",
                          "Listen, this is a store. People buy things here. Don't distract me!", "block", 1, npchar, Dialog.CurrentNode);
			link.l1 = HeroStringReactionRepeat("You know, " + NPChar.name + ", perhaps next time.", "Indeed, I forgot that...",
                      "One, two... you're right, third it is!", "Hm, I won't...", npchar, Dialog.CurrentNode);
			link.l1.go = "exit";
			if (pchar.questTemp.BlueBird == "toPuertoPrincipe")
			{
				link.l1 = "John, I come to you with business concerning Pascal Vousier.";
				link.l1.go = "BlueBird_1";
			}
		break;
		case "BlueBird_1":
			if (isBadReputation(pchar, 5)) 
			{
				dialog.text = NPCStringReactionRepeat("I won't talk about Pascal with a person of your reputation. I am ready to trade with you, no more.", 
					"I already told you everything.", 
					"We already spoke about that.",
					"I have nothing to add to what I said.", "block", 1, npchar, Dialog.CurrentNode);
				link.l1 = HeroStringReactionRepeat("But I really need a conversation with you, try to understand this...", 
					"Hmm...",
					"Yeah, that's for sure...", 
					"Understood...", npchar, Dialog.CurrentNode);
				link.l1.go = DialogGoNodeRepeat("BlueBird_close", "", "", "", npchar, Dialog.CurrentNode);
			}
			else
			{
				dialog.text = "Hm, don't even know what to tell you... So what business is this?";
				link.l1 = "Well... Oh, damn it, now I don't know what to say.";
				link.l1.go = "BlueBird_2";
			}
		break;

		case "BlueBird_close":
			dialog.text = "You'd better think about your reputation... I have nothing more to tell you.";
			link.l1 = "Heh!..";
			link.l1.go = "exit";
		break;

		case "BlueBird_2":
			dialog.text = "Begin with the main thing.";
			link.l1 = "Perhaps, that's what I'll do. I have a suspicion that Pascal Vousier is not a simple merchant. I was told that you are kind of enemies with him. That's why I'm here, I wish to learn as much as possible about this person.";
			link.l1.go = "BlueBird_3";
		break;
		case "BlueBird_3":
			dialog.text = "Huh! Did someone in the Caribbean sea finally start to see clearly? My friend, Pascal Vousier is really not a simple merchant. He's a top-tier rascal, but he's able to do things in a silent way, so he can get away with anything...";
			link.l1 = "Anything? With what can he get away?";
			link.l1.go = "BlueBird_4";
		break;
		case "BlueBird_4":
			dialog.text = "Let's begin with how this bastard took away my store. He cut me off from receiving any goods, even the local pirates didn't sell me anything, he bought it all up from them!";
			link.l1 = "Wow, his grasp is like that of a wolf!";
			link.l1.go = "BlueBird_5";
		break;
		case "BlueBird_5":
			dialog.text = "Of a jackal, that'll be more correct! And can you imagine - the whole trading community of the Caribbean sea considers him a decent person! And I think that all the merchants' troubles are due to him.";
			link.l1 = "D'you think so?";
			link.l1.go = "BlueBird_6";
		break;
		case "BlueBird_6":
			dialog.text = "I'm sure of it. Only no one listens to me, everyone thinks that I'm telling this because I'm mad at him for a lost business on Bermuda. Of course, that's important, but not to this degree!   \nAnd then I simply ceased telling anything - some kind people hinted me to be quiet...";
			link.l1 = "Well... You know, I am now engaged in searching for the xebec ' Blue Bird'. It's this ship that plunders the merchants' personal vessels.";
			link.l1.go = "BlueBird_7";
		break;
		case "BlueBird_7":
			dialog.text = "I think this xebec operates on hints of the bastard Pascal, at least. And it's even very probable that it's his own ship   \nJudge for yourself, what a sly fellow he is - plundering the merchants, and then lending them their own money!";
			link.l1 = "Oh yes, words escape me... Listen, so how could I catch this xebec?";
			link.l1.go = "BlueBird_8";
		break;
		case "BlueBird_8":
			dialog.text = "I do not know... But here's my advise. Think about how he delivers the goods to his store. I doubt his xebec moors in the port.";
			link.l1 = "It doesn't, I know for sure since I asked around.";
			link.l1.go = "BlueBird_9";
		break;
		case "BlueBird_9":
			dialog.text = "Well then, my reasoning seems to be true... You know, there is an underground passage on Bermuda, it leads from the shipyard directly to the bay. So just start searching, my friend, may the force be with you!";
			link.l1 = "Thank you, you helped me very much!";
			link.l1.go = "exit";
			pchar.questTemp.BlueBird = "toSeekBermudes";
			AddQuestRecord("Xebeca_BlueBird", "4");
		break;
	}
	UnloadSegment(NPChar.FileDialog2);
}

