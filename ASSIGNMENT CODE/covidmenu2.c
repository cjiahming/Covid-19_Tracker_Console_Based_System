#include <stdlib.h> //library
#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)

void choice2(); //Menu for choosing whether to quit the program or continue to another menu.
void menu1(); //Menu for displaying the Tips on Preventing getting COVID-19.
void main() {

	// Variables 
	const int itcase = 100, itdeath = 2, itrec = 10, iundertreat = 88, yncase = 9;
	const double prevpdeath = 2, prevprecover = 10, prevptreat = 88;
	int undertreat, nlocal, nimport, ndeath, nrec, choose;
	int totalcase, totaldeath, totalrec;
	double pdeath, precover, ptreat;

	/*Add on variables for Daily Comparative Report*/
	int todayTncase, dttreat;
	int dncase, dtcase, dtdeath, dtrec, day = 9, cday = 9, day2 = 10;
	double ddrate, drecrate, dtreatrate;
	char choice;

	// Looping (Daily Comparative Report)
	int yncase2, itcase2, itdeath2, itrec2, iundertreat2;
	double prevpdeath2, prevprecover2, prevptreat2;

	// To find the highest record //
	int highest = 0, highDay = 0;

	// Variable for lowest record //
	int lowest = yncase, lowDay = day;

	// Variable for menu
	int choose2;

	printf("----------------------------------------------COVID-19 TRACKER-------------------------------------------------------\n\n\n");
	printf("Yesterday's Totals - (Day %d) :\n", day); //This day is going to be Day 9
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|  Yesterday's Cases  |  Total Cases  ||  Total Deaths  |  Total Recovered  |  Under treatment  |\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|%11d          |%9d      ||%8d        |%11d        |    %6d         |\n", yncase, itcase, itdeath, itrec, iundertreat);
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|                                      |%10.2lf%%     | %11.2lf%%      | %10.2lf%%       |\n", prevpdeath, prevprecover, prevptreat);
	printf("-------------------------------------------------------------------------------------------------\n\n");

	day++; //day++ to increase the value of day by 1 so the next day can be Day 10

	printf("Day %d\n", day); //It will be Day 10
	printf("========\n\n");

	// Input 
	printf("Please enter today's data :\n");
	printf("\t\tNumber of New Local Cases  : ");
	scanf("%d", &nlocal);

	printf("\t\tNumber of New Import Cases : ");
	scanf("%d", &nimport);

	printf("\t\tNumber of deaths : ");
	scanf("%d", &ndeath);

	printf("\t\tNumber recovered : ");
	scanf("%d", &nrec);
	printf("\n");

	printf("Please choose between Daily Summary Report OR Daily Comparative Report\n"); //Lets user to choose between Daily Summary Report or Daily Comparative Report
	printf("[1] - Daily Summary Report \n");
	printf("[2] - Daily Comparative Report \n");
	printf("Please enter the number : ");
	scanf("%d", &choose);
	printf("\n");

	//Daily Summary Report Process 
	totalcase = nlocal + nimport + itcase;
	totaldeath = ndeath + itdeath;
	totalrec = nrec + itrec;
	undertreat = totalcase - totaldeath - totalrec;
	pdeath = roundf(totaldeath * 100) / totalcase;
	precover = roundf(totalrec * 100) / totalcase;
	ptreat = roundf(undertreat * 100) / totalcase;

	//Daily Comparative Report Process
	todayTncase = nlocal + nimport;
	dncase = todayTncase - yncase;
	dtcase = totalcase - itcase;
	dtdeath = totaldeath - itdeath;
	dtrec = totalrec - itrec;
	dttreat = undertreat - iundertreat;
	ddrate = pdeath - prevpdeath;
	drecrate = precover - prevprecover;
	dtreatrate = ptreat - prevptreat;

	if (choose == 1)
	{
		printf("+ + + + + + + + + Daily Summary Report + + + + + + + + \n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("|  New Local Cases  |  New Imported Cases  |  Total Cases  |  Total Death  |  Total Recovered  |  Under Treatment  |\n");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("|%9d          |%12d          |%10d     |%8d       |%11d        |    %6d         |\n", nlocal, nimport, totalcase, totaldeath, totalrec, undertreat);
		printf("--------------------------------------------------------------------------------------------------------------------\n");
		printf("|                                                          |%10.1lf%%    | \t%8.1lf%%      | %10.1lf%%       |\n", pdeath, precover, ptreat);
		printf("--------------------------------------------------------------------------------------------------------------------\n\n");
		printf("-------------------------------------------------- END OF DAY 10----------------------------------------------------\n\n");
	}
	else if (choose == 2)
	{
		printf("+ + + + + + + + + Daily Comparative Report + + + + + + + + \n");
		printf("---------------------------------------------------------------------------\n");
		printf("|                |     Yesterday    |     TODAY      ||     DIFFERENCE    |\n");
		printf("|                |       Day 9      |     Day 10     ||                   |\n");
		printf("---------------------------------------------------------------------------\n");
		printf("|New Cases       |%12d      | %10d     ||%12d       |\n", yncase, todayTncase, dncase);
		printf("---------------------------------------------------------------------------\n");
		printf("|Total Cases     |%12d      | %10d     ||%12d       |\n", itcase, totalcase, dtcase);
		printf("---------------------------------------------------------------------------\n");
		printf("|Total Death     |%12d      | %10d     ||%12d       |\n", itdeath, totaldeath, dtdeath);
		printf("---------------------------------------------------------------------------\n");
		printf("|Total Recovered |%12d      | %10d     ||%12d       |\n", itrec, totalrec, dtrec);
		printf("---------------------------------------------------------------------------\n");
		printf("|Under Treatment |%12d      | %10d     ||%12d       |\n", iundertreat, undertreat, dttreat);
		printf("---------------------------------------------------------------------------\n");
		printf("|Death Rate      |%11.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevpdeath, pdeath, ddrate);
		printf("---------------------------------------------------------------------------\n");
		printf("|Recovery Rate   |%11.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevprecover, precover, drecrate);
		printf("---------------------------------------------------------------------------\n");
		printf("|Treatment Rate  |%11.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevptreat, ptreat, dtreatrate);
		printf("---------------------------------------------------------------------------\n");
		printf("-------------------------------------------------- END OF DAY 10----------------------------------------------------\n\n");
	}
	else
	{
		printf("SORRY PLEASE ENTER ONLY NUMBER [1] OR [2]\n\n");
	}

	printf("Continue to next day? [Y]-yes : ");
	scanf("%s", &choice);

	//Looping to continue let user calculate cases for the next day and so on.

	while (choice == 'Y' || choice == 'y') {

		day++; // To display what day is it at input cases and display what day is it during the Summary and Comparative Report.
		cday++; // To display previous day in Daily Comparative Report.
		printf("Day %d\n", day);
		printf("========\n\n");

		//All of this variable is set to 0 to make it able to display the previous day's data.
		yncase2 = 0;
		yncase2 = todayTncase;

		itcase2 = 0;
		itcase2 = totalcase;

		itdeath2 = 0;
		itdeath2 = totaldeath;

		itrec2 = 0;
		itrec2 = totalrec;

		iundertreat2 = 0;
		iundertreat2 = undertreat;

		prevpdeath2 = 0;
		prevpdeath2 = pdeath;

		prevprecover2 = 0;
		prevprecover2 = precover;

		prevptreat2 = 0;
		prevptreat2 = ptreat;


		// Input 
		printf("Please enter today's data :\n");
		printf("\t\tNumber of New Local Cases  : ");
		scanf("%d", &nlocal);

		printf("\t\tNumber of New Import Cases : ");
		scanf("%d", &nimport);

		printf("\t\tNumber of deaths : ");
		scanf("%d", &ndeath);

		printf("\t\tNumber recovered : ");
		scanf("%d", &nrec);
		printf("\n");
		//Daily Summary Report process
		totalcase = nlocal + nimport + totalcase;
		totaldeath = ndeath + totaldeath;
		totalrec = nrec + totalrec;
		undertreat = totalcase - totaldeath - totalrec;
		pdeath = roundf(totaldeath * 100) / totalcase;
		precover = roundf(totalrec * 100) / totalcase;
		ptreat = roundf(undertreat * 100) / totalcase;

		//Daily Comparative Report process
		todayTncase = nlocal + nimport;
		dncase = todayTncase - yncase2;
		dtcase = totalcase - itcase2;
		dtdeath = totaldeath - itdeath2;
		dtrec = totalrec - itrec2;
		dttreat = undertreat - iundertreat2;
		ddrate = pdeath - prevpdeath2;
		drecrate = precover - prevprecover2;
		dtreatrate = ptreat - prevptreat2;

		printf("Please choose between Daily Summary Report OR Daily Comparative Report\n"); //Lets user to choose between Daily Summary Report and Daily Comparative Report.
		printf("[1] - Daily Summary Report \n");
		printf("[2] - Daily Comparative Report \n");
		printf("Please enter the number : ");
		scanf("%d", &choose);
		printf("\n");


		if (choose == 1) // DAILY SUMMARY REPORT
		{
			printf("+ + + + + + + + + Daily Summary Report + + + + + + + + \n");
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("|  New Local Cases  |  New Imported Cases  |  Total Cases  |  Total Death  |  Total Recovered  |  Under Treatment  |\n");
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("|%9d          |%12d          |%10d     |%8d       |%11d        |    %6d         |\n", nlocal, nimport, totalcase, totaldeath, totalrec, undertreat);
			printf("--------------------------------------------------------------------------------------------------------------------\n");
			printf("|                                                          |%10.1lf%%    | \t%8.1lf%%      | %10.1lf%%       |\n", pdeath, precover, ptreat);
			printf("--------------------------------------------------------------------------------------------------------------------\n\n");
			printf("-------------------------------------------------- END OF DAY %d----------------------------------------------------\n\n", day);
		}
		else if (choose == 2) //DAILY COMPARATIVE REPORT
		{

			printf("+ + + + + + + + + Daily Comparative Report + + + + + + + + \n");
			printf("---------------------------------------------------------------------------\n");
			printf("|                |     Yesterday     |     TODAY      ||     DIFFERENCE    |\n");
			printf("|                |       Day %d      |     Day %d     ||                   |\n", cday, day);
			printf("---------------------------------------------------------------------------\n");
			printf("|New Cases       |%12d       | %10d     ||%12d       |\n", yncase2, todayTncase, dncase);
			printf("---------------------------------------------------------------------------\n");
			printf("|Total Cases     |%12d       | %10d     ||%12d       |\n", itcase2, totalcase, dtcase);
			printf("---------------------------------------------------------------------------\n");
			printf("|Total Death     |%12d       | %10d     ||%12d       |\n", itdeath2, totaldeath, dtdeath);
			printf("---------------------------------------------------------------------------\n");
			printf("|Total Recovered |%12d       | %10d     ||%12d       |\n", itrec2, totalrec, dtrec);
			printf("---------------------------------------------------------------------------\n");
			printf("|Under Treatment |%12d       | %10d     ||%12d       |\n", iundertreat2, undertreat, dttreat);
			printf("---------------------------------------------------------------------------\n");
			printf("|Death Rate      |%11.1lf%%       |%10.1lf%%     ||%11.1lf%%       |\n", prevpdeath2, pdeath, ddrate);
			printf("---------------------------------------------------------------------------\n");
			printf("|Recovery Rate   |%11.1lf%%       |%10.1lf%%     ||%11.1lf%%       |\n", prevprecover2, precover, drecrate);
			printf("---------------------------------------------------------------------------\n");
			printf("|Treatment Rate  |%11.1lf%%       |%10.1lf%%     ||%11.1lf%%       |\n", prevptreat2, ptreat, dtreatrate);
			printf("---------------------------------------------------------------------------\n\n");
			printf("-------------------------------------------------- END OF DAY %d----------------------------------------------------\n\n", day);
		}
		else
		{
			printf("SORRY PLEASE ENTER ONLY NUMBER [1] OR [2]\n\n");
		}
		
		printf("Continue to next day? [Y]-yes : ");
		scanf("%s", &choice);

		if (todayTncase > highest) {
			highest = todayTncase;
			highDay = day;
		}

		if (todayTncase < lowest) {
			lowest = todayTncase;
			lowDay = day;
		}
	}

	printf("\nTOTAL DAYS RECORDED     = %d days  (Day 10 to day %d)\n", (day - day2) + 1, day); //To display total days recorded.

	printf("HIGHEST number of cases = %d    (Occuring on day %d)\n", highest, highDay);//To display highest number of cases and which day is it.

	printf("LOWEST number of cases  = %d     (Occuring on day %d)\n", lowest, lowDay);//To display lowest number of cases and which day is it.

	choice2();

	system("pause");
}

void choice2() {
	int choose2;
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("\nHERE'S SOME USEFUL TIPS TO GET YOU SAFE FROM COVID-19.\n\n");
	printf("1. COVID-19 Prevention Tips\n");
	printf("2. Quit\n\n");
	printf("If you wish to continue,\n\n");
	printf("YES - [1]\n");
	printf("NO  - [2]\n\n");
	printf("Please enter your choice : ");
	scanf("%d", &choose2);
	

	switch (choose2) {
	case 1: menu1(); break; //GO TO THE MENU
	case 2: printf("\nThank you for using our system ! Take Care :)\n\n"); break;
	}
}
void menu1() { //MENU
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("=====================COVID-19 PREVENTION TIPS=====================\n");
	printf("\n\nBefore you go, here are some ways to prevent getting Covid-19 : \n\n");
	printf("1. Wear mask whevener you go out.\n");
	printf("2. Use hand sanitizer before you eat or after touching things.\n");
	printf("3. Dont touch ur eyes and nose when ur hands are not clean.\n");
	printf("4. Avoid going out to public alot.\n");
	printf("5. Wear your mask when talking to other people.\n\n");
	printf("Thank you for using our system ! Take Care :)\n\n");
}