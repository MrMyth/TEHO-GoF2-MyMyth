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
			dialog.text = "Are you captain Sharp?";
			link.l1 = "That's right. What can I?";
			link.l1.go = "1";

			NextDiag.TempNode = "First time";
		break;

		case "1":
			dialog.text = "Good. I have a package for you, from your father.";
			link.l1 = "But my father's been dead for 20 years! How could he send me a package?";
			link.l1.go = "2";
		break;

		case "2":
			dialog.text = "Listen matey, I'm just the messenger, doing what I was asked to do - which is to give you this. Now if you'll excuse me, I must be on my way.";
			link.l1 = "What is this? Hey, wait! ...";
			link.l1.go = "Exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		case "19":
			dialog.text = "I'm the new boss around here. Got a problem with that?";
			link.l1 = "...";
			link.l1.go = "20";
		break;

		case "20":
			dialog.text = "No? I thought not. Now pin back your lugholes and listen good. In two weeks, I'm calling together a meeting of all free captains as are able to attend. I'll not tell you why I'm calling this meeting, but trust me, it affects everyone, and it'll take place here, in MY new residence.";
			link.l1 = "...";
			link.l1.go = "20_exit";
		break;
		case "20_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("Story_Sharp40");
		break;
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

	}
}