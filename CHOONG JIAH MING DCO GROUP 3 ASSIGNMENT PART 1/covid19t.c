#include <stdlib.h> //library
#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)

void main() {

	// Variables 
	const int itcase = 100, itdeath = 2, itrec = 10, iundertreat = 88, yncase = 9;
	const double prevpdeath = 2, prevprecover = 10, prevptreat = 88;
	int undertreat, nlocal, nimport, ndeath, nrec;
	int totalcase, totaldeath, totalrec;
	double pdeath, precover, ptreat;
	
	printf("----------------------------------------------COVID-19 TRACKER-------------------------------------------------------\n\n\n"); 
	printf("Yesterday's Totals - (Day 8) :\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|  %11Yesterday's Cases  |  Total Cases  ||  Total Deaths  |  Total Recovered  |  Under treatment  |\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|%11d          |%9d      ||%8d        |%11d        |    %6d         |\n", yncase, itcase, itdeath, itrec, iundertreat);
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("|                                      |%10.2lf%%     | %11.2lf%%      | %10.2lf%%       |\n", prevpdeath, prevprecover, prevptreat);
	printf("-------------------------------------------------------------------------------------------------\n\n");

	printf("Day 10\n");
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

	// Process 
	totalcase = nlocal + nimport + itcase;
	totaldeath = ndeath + itdeath;
	totalrec = nrec + itrec;
	undertreat = totalcase - totaldeath - totalrec;
	pdeath =  roundf(totaldeath * 100) / totalcase;
	precover = roundf(totalrec * 100) / totalcase;
	ptreat =  roundf(undertreat * 100) / totalcase;


	// Daily Summary Report Table
	printf("+ + + + + + + + + Daily Summary Report + + + + + + + + \n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("|  New Local Cases  |  New Imported Cases  |  Total Cases  |  Total Death  |  Total Recovered  |  Under Treatment  |\n");
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("|%9d          |%12d          |%10d     |%8d       |%11d        |    %6d         |\n", nlocal, nimport, totalcase, totaldeath, totalrec, undertreat);
	printf("--------------------------------------------------------------------------------------------------------------------\n");
	printf("|                                                          |%10.2lf%%    | \t%8.2lf%%      | %10.2lf%%       |\n", pdeath, precover, ptreat);
	printf("--------------------------------------------------------------------------------------------------------------------\n\n");
	printf("-------------------------------------------------- END OF DAY 10----------------------------------------------------\n\n");

	system("pause");
}