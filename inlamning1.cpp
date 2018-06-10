#include<ctime>
#include<iostream>

using namespace std;
bool wantToKeepPlaying = true;
int myDice, compDice;
bool isEqual = false, readyToPlay = false, hasAnyoneWon = false;
int playerWins = 0, compWins = 0, nrOfRounds = 1, wallet = 0, moneyInThePot = 0, currentWallet = 0, answear = 0;

// TODO Måste nog lägga till en till do och while som ber dig
// lägga över pengar från din wallet till dina pengar som du har
// inne i spelet. Som det är nu så får currentWallet moneyInThePots
// värde så säg att man spelar en gång för 100 och vinner, då blir
// currentWallet 200 men om man väljer att forsätta spela
// så blir currentWallet det som man väljer att spela den omgången
// istället för att va vinsterna från förra omgången. Måste Kolla
// med variabler så att de får rätt värden. 

void diceThrow () {
	myDice = rand() % 6 + 1;
	compDice = rand() % 6 + 1;
}
		// Introduktion till spelet och maxgränsen att spela för.
void insertMoney() {
	do {
		cout << "Welcome to Dice 3000. Please insert money to play. "
		"The maximum amount is 5000 kr. \n";
		cin >> wallet;
	} while (wallet > 5000);
}

int main() {
	srand(time(0));		

	insertMoney();
			// Kollar så att man bettar en summa som är tillåten och som man har. 
	do { 
		do {		
			cout << "Please select if you want to play for 100 kr, "
			"300 kr or 500 kr. \n";
			cin >> moneyInThePot;

			if ((moneyInThePot == 100 || moneyInThePot == 300 || moneyInThePot == 500) && (moneyInThePot <= wallet)) {
				readyToPlay = true;
			} else {
				readyToPlay = false;
			}
			currentWallet = moneyInThePot;
			currentWallet = currentWallet - moneyInThePot;
			wallet = (wallet - moneyInThePot);
		} while (readyToPlay == false);

		cout << "You have " << wallet << " kr left in your wallet.\n";
		cout << "You have " << currentWallet << " kr left in the game. \n";

		do {
			do {
				diceThrow();
				cout << "\nPlaying round number " << nrOfRounds << ".\n\n";
				cout << "Player throws a " << myDice << ".\n";
				cout << "Computer throws a " << compDice << ".\n";

				if (myDice == compDice) {
					cout << "It's a draw, both throw again. \n";
					isEqual = true;
				} else { 
					isEqual = false;
				}

			} while (isEqual == true);

			nrOfRounds++;

			if (myDice > compDice) {
				playerWins++;
			} else if (myDice < compDice) {
				compWins++;
			}
			cout << "Player has won " << playerWins << " times.\n";
			cout << "Computer has won " << compWins << " times.\n";

			if (playerWins == 2) {
				cout << "Player won the game! \n\n";
				hasAnyoneWon = true;
				moneyInThePot = moneyInThePot * 2;
				currentWallet = currentWallet + moneyInThePot;
				cout << "You now have " << currentWallet << " kr to play for.\n" ;
			}

			if (compWins == 2) {
				cout << "Computer won the game! \n\n";
				hasAnyoneWon = true;

			}



		} while (hasAnyoneWon == false);

		moneyInThePot = 0;

		do {
			cout << "Do you wish to play again? \nType 1 if you "
			" wish to CONTINUE or 2 if want to QUIT\n";
			cin >> answear;

			if (answear == 1) {
				wantToKeepPlaying = true;
			} else if (answear == 2) {
				wantToKeepPlaying = false;
			}
		} while (!(answear == 1) && !(answear == 2));

	} while (wantToKeepPlaying == true);






}