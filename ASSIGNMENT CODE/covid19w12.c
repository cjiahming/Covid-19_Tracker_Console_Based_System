//#include <stdlib.h> //library
//#include <stdio.h>
//#include <math.h>
//#pragma warning (disable:4996)
//
//void main2() {
//
//	// Variables 
//	const int itcase = 100, itdeath = 2, itrec = 10, iundertreat = 88, yncase = 9;
//	const double prevpdeath = 2, prevprecover = 10, prevptreat = 88;
//	int undertreat, nlocal, nimport, ndeath, nrec, choose;
//	int totalcase, totaldeath, totalrec;
//	double pdeath, precover, ptreat;
//	int todayTncase;
//	int dncase, dtcase, dtdeath, dtrec, day=10;
//	double ddrate, drecrate, dtreatrate;
//	char choice;
//
//	// Looping (Daily Summary Report) 
//	int looplocal, loopimport, loopTotalcase, loopTotaldeath, loopTotalrec, loopUndertreat;
//
//	// Looping (Daily Comparative Report)
//
//	printf("----------------------------------------------COVID-19 TRACKER-------------------------------------------------------\n\n\n");
//	printf("Yesterday's Totals - (Day 9) :\n");
//	printf("-------------------------------------------------------------------------------------------------\n");
//	printf("|  Yesterday's Cases  |  Total Cases  ||  Total Deaths  |  Total Recovered  |  Under treatment  |\n");
//	printf("-------------------------------------------------------------------------------------------------\n");
//	printf("|%11d          |%9d      ||%8d        |%11d        |    %6d         |\n", yncase, itcase, itdeath, itrec, iundertreat);
//	printf("-------------------------------------------------------------------------------------------------\n");
//	printf("|                                      |%10.2lf%%     | %11.2lf%%      | %10.2lf%%       |\n", prevpdeath, prevprecover, prevptreat);
//	printf("-------------------------------------------------------------------------------------------------\n\n");
//
//	printf("Day 10\n");
//	printf("========\n\n");
//
//	// Input 
//	printf("Please enter today's data :\n");
//	printf("\t\tNumber of New Local Cases  : ");
//	scanf("%d", &nlocal);
//
//	printf("\t\tNumber of New Import Cases : ");
//	scanf("%d", &nimport);
//
//	printf("\t\tNumber of deaths : ");
//	scanf("%d", &ndeath);
//
//	printf("\t\tNumber recovered : ");
//	scanf("%d", &nrec);
//	printf("\n");
//
//	printf("Please choose between Daily Summary Report OR Daily Comparative Report\n");
//	printf("[1] - Daily Summary Report \n");
//	printf("[2] - Daily Comparative Report \n");
//	printf("Please enter the number : ");
//	scanf("%d", &choose);
//	printf("\n");
//
//	// Process 
//	totalcase = nlocal + nimport + itcase;
//	totaldeath = ndeath + itdeath;
//	totalrec = nrec + itrec;
//	undertreat = totalcase - totaldeath - totalrec;
//	pdeath = roundf(totaldeath * 100) / totalcase;
//	precover = roundf(totalrec * 100) / totalcase;
//	ptreat = roundf(undertreat * 100) / totalcase;
//
//	todayTncase = nlocal + nimport;
//	dncase = todayTncase - yncase;
//	dtcase = totalcase - itcase;
//	dtdeath = totaldeath - itdeath;
//	dtrec = totalrec - itrec;
//	ddrate = (pdeath - prevpdeath);
//	drecrate = (precover - prevprecover);
//	dtreatrate = ptreat - prevptreat;
//
//	if (choose == 1)
//	{
//		printf("+ + + + + + + + + Daily Summary Report + + + + + + + + \n");
//		printf("--------------------------------------------------------------------------------------------------------------------\n");
//		printf("|  New Local Cases  |  New Imported Cases  |  Total Cases  |  Total Death  |  Total Recovered  |  Under Treatment  |\n");
//		printf("--------------------------------------------------------------------------------------------------------------------\n");
//		printf("|%9d          |%12d          |%10d     |%8d       |%11d        |    %6d         |\n", nlocal, nimport, totalcase, totaldeath, totalrec, undertreat);
//		printf("--------------------------------------------------------------------------------------------------------------------\n");
//		printf("|                                                          |%10.1lf%%    | \t%8.1lf%%      | %10.1lf%%       |\n", pdeath, precover, ptreat);
//		printf("--------------------------------------------------------------------------------------------------------------------\n\n");
//		printf("-------------------------------------------------- END OF DAY 10----------------------------------------------------\n\n");
//	}
//	else if (choose == 2)
//	{
//		printf("+ + + + + + + + + Daily Comparative Report + + + + + + + + \n");
//		printf("---------------------------------------------------------------------------\n");
//		printf("|                |     Yesterday    |     TODAY      ||     DIFFERENCE    |\n");
//		printf("|                |       Day 9      |     Day 10     ||                   |\n");
//		printf("---------------------------------------------------------------------------\n");
//		printf("|New Cases       |%12d      | %10d     ||%12d       |\n", yncase, todayTncase, dncase);
//		printf("---------------------------------------------------------------------------\n");
//		printf("|Total Cases     |%12d      | %10d     ||%12d       |\n", itcase, totalcase, dtcase);
//		printf("---------------------------------------------------------------------------\n");
//		printf("|Total Death     |%12d      | %10d     ||%12d       |\n", itdeath, totaldeath, dtdeath);
//		printf("---------------------------------------------------------------------------\n");
//		printf("|Total Recovered |%12d      | %10d     ||%12d       |\n", itrec, totalrec, dtrec);
//		printf("---------------------------------------------------------------------------\n");
//		printf("|Death Rate      |%11.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevpdeath, pdeath, ddrate);
//		printf("---------------------------------------------------------------------------\n");
//		printf("|Recovery Rate   |%11.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevprecover, precover, drecrate);
//		printf("---------------------------------------------------------------------------\n");
//		printf("|Treatment Rate   |%10.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevprecover, ptreat, drecrate);
//		printf("---------------------------------------------------------------------------\n");
//	}
//	else
//	{
//		printf("SORRY PLEASE ENTER ONLY NUMBER [1] OR [2] ");
//	}
//
//	do {
//		printf("Continue to next day? [Y]-yes : ");
//		scanf("%s", &choice);
//		day += 1;
//		printf("Day %d\n", day);
//		printf("========\n\n");
//
//		// Input 
//		printf("Please enter today's data :\n");
//		printf("\t\tNumber of New Local Cases  : ");
//		scanf("%d", &nlocal);
//
//		printf("\t\tNumber of New Import Cases : ");
//		scanf("%d", &nimport);
//
//		printf("\t\tNumber of deaths : ");
//		scanf("%d", &ndeath);
//
//		printf("\t\tNumber recovered : ");
//		scanf("%d", &nrec);
//		printf("\n");
//		totalcase = nlocal + nimport + totalcase;
//		totaldeath = ndeath + totaldeath;
//		totalrec = nrec + totalrec;
//		undertreat = totalcase - totaldeath - totalrec;
//		pdeath = roundf(totaldeath * 100) / totalcase;
//		precover = roundf(totalrec * 100) / totalcase;
//		ptreat = roundf(undertreat * 100) / totalcase;
//		printf("Please choose between Daily Summary Report OR Daily Comparative Report\n");
//		printf("[1] - Daily Summary Report \n");
//		printf("[2] - Daily Comparative Report \n");
//		printf("Please enter the number : ");
//		scanf("%d", &choose);
//		printf("\n");
//
//
//		if (choose == 1)
//		{
//			printf("+ + + + + + + + + Daily Summary Report + + + + + + + + \n");
//			printf("--------------------------------------------------------------------------------------------------------------------\n");
//			printf("|  New Local Cases  |  New Imported Cases  |  Total Cases  |  Total Death  |  Total Recovered  |  Under Treatment  |\n");
//			printf("--------------------------------------------------------------------------------------------------------------------\n");
//			printf("|%9d          |%12d          |%10d     |%8d       |%11d        |    %6d         |\n", nlocal, nimport, totalcase, totaldeath, totalrec, undertreat);
//			printf("--------------------------------------------------------------------------------------------------------------------\n");
//			printf("|                                                          |%10.1lf%%    | \t%8.1lf%%      | %10.1lf%%       |\n", pdeath, precover, ptreat);
//			printf("--------------------------------------------------------------------------------------------------------------------\n\n");
//			printf("-------------------------------------------------- END OF DAY 10----------------------------------------------------\n\n");
//		}
//		else if (choose == 2)
//		{
//			printf("+ + + + + + + + + Daily Comparative Report + + + + + + + + \n");
//			printf("---------------------------------------------------------------------------\n");
//			printf("|                |     Yesterday    |     TODAY      ||     DIFFERENCE    |\n");
//			printf("|                |       Day 9      |     Day 10     ||                   |\n");
//			printf("---------------------------------------------------------------------------\n");
//			printf("|New Cases       |%12d      | %10d     ||%12d       |\n", yncase, todayTncase, dncase);
//			printf("---------------------------------------------------------------------------\n");
//			printf("|Total Cases     |%12d      | %10d     ||%12d       |\n", itcase, totalcase, dtcase);
//			printf("---------------------------------------------------------------------------\n");
//			printf("|Total Death     |%12d      | %10d     ||%12d       |\n", itdeath, totaldeath, dtdeath);
//			printf("---------------------------------------------------------------------------\n");
//			printf("|Total Recovered |%12d      | %10d     ||%12d       |\n", itrec, totalrec, dtrec);
//			printf("---------------------------------------------------------------------------\n");
//			printf("|Death Rate      |%11.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevpdeath, pdeath, ddrate);
//			printf("---------------------------------------------------------------------------\n");
//			printf("|Recovery Rate   |%11.1lf%%      |%10.1lf%%     ||%11.1lf%%       |\n", prevprecover, precover, drecrate);
//			printf("---------------------------------------------------------------------------\n\n");
//		}
//		else
//		{
//			printf("SORRY PLEASE ENTER ONLY NUMBER [1] OR [2] ");
//		}
//	} while (choice == 'Y' || choice == 'y');
//
//	system("pause");
//}