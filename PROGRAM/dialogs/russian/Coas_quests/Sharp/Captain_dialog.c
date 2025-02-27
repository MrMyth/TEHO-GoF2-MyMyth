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
		case "1":
			dialog.text = "...";
			link.l1 = "Gentlemen. I'm not a great speaker, so I'll get straight to the point. Some of you will remember - or will have heard - of my father - Nicolas Sharp. Some twenty years ago, he tried to create a new nation, here, on the islands. Libertania - a free nation. Free from the greedy exploitation of the Old World, free from their petty wars that serve no purpose other than the inflation of a king's ego, or his treasury. As you may also know, he failed - betrayed by one of his own men, his fleet was vanquished. However, what you certainly do not know is just how close he was to success. Here, now, I am just as close to fulfilling his dream, and have taken great care not to repeat his mistakes, but I can not win alone - I need you, free men with free ships, to fight against those who would stifle and control you, who impose their laws and their wars upon you. I am not asking you to do any more than you usually do - disrupt their shipping lanes, sink their convoys, harass their patrols - but I ask you to do it for something more than just loot and infamy. I ask you to do it for freedom! For liberty! For the betterment of every man, be he pirate or landlubber! I'm asking you now - who will step forward and join me in creating a brave new world for all! What say you?";
			link.l1.go = "Exit";
		break;

		case "2":
			dialog.text = "Anyone who commands such fierce loyalty and devotion from their followers is indeed worth following. I think I can speak for all of us here when I say that not only is your plan insane, it is daring to the point of suicide. But, there is a chance that it may actually work. And if it does... Well, the rewards will be beyond imagination. We're with you, captain.";
			link.l1 = "...";
			link.l1.go = "Exit";

		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}