#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int guess1, guess2;
int attempts1 = 0, attempts2 = 0;
int points1 = 100, points2 = 100;
int value;
int opt;

void singleplayer();
void multiplayer();
void rules();

int main() {
srand(time(0));
    cout << endl << "Welcome to the Number Guessing Game!";
    cout << endl << "1. Single player";
    cout << endl << "2. Multiplayer";
    cout << endl << "Enter your choice: ";
    cin >> opt;

    if (opt == 1) 
    {
	    singleplayer();	//singleplayer
	}
    else 
	{
	    multiplayer();		//multiplayer
	}
    return 0;
}
//------------singleplayer------------
void singleplayer(){
	while (true)
	{
        cout << endl << " What would you like to do?";
        cout << endl << " (1)Standard \n (2)High Stakes \n (3)display points \n (4)Rules \n (5)Exit\n";
        cin >> opt;
		// Generate a random number between 1 and 100
   		int secretNumber = rand() % 100 + 1;
        switch (opt) 
        {
	        case 1: 
            	cout << endl << "Selected a random number between 1 and 100. Try to guess it." << endl;
	            if(points1 >0)
				{ 
		            do {
		                cout << endl << "Enter your guess: ";
		                cin >> guess1;
		                attempts1++;
		                int difference = abs(secretNumber - guess1); // Calculate the absolute difference
		                if (guess1 < secretNumber) 
                        {
		                    cout << endl << "Too low! Try again." << endl;
		                    points1 -= 5; //Points deducted
		                    cout << endl << "Points = " << points1<<endl;
		                } 
                        else if (guess1 > secretNumber) 
                        {
		                    cout << endl << "Too high! Try again." << endl;
		                    points1 -= 5;
		                    cout << endl << "Points = " << points1<<endl;
		                } 
                        else 
                        {
		                    cout << endl << "Congratulations! You guessed the number " << secretNumber << " in " << attempts1 << " attempts." << endl;
		                    points1 += 100 - (10 * attempts1); //Reward
		                    break;
		                }
		
		                // Provide feedback for being closer
		                if (difference <= 10) 
                        {
		                    cout << endl << "Getting warm! You are close to the number." << endl;
		                }
		            } while (guess1 != secretNumber);
	            }
				else
	                cout << endl << "You dont have enough points to start" << endl;
	            break;
	            	
	        case 2: 
	            cout << endl << "Enter your bet amount: ";
	            cin >> value;
	            if(points1 >= value)
	            {
	                cout << endl << "Enter your guess between 1 and 10: ";
	                int secretNumber2 = rand() % 10 + 1;
	                cin >> guess1;

	                int difference = abs(secretNumber2 - guess1); // Calculate the absolute difference
	                if (guess1 != secretNumber2) 
                    {
                        cout << endl << "You Lost too bad !!";
                        points1 -= 3 * value;
	                    cout << endl << "Your Points:" << points1 - value<<endl;
	                } 
                    else 
                    {
	                    cout << endl << "Congratulations! You guessed the number " << secretNumber2;
	                    points1 += 2 * value;
	                    cout << endl << "Your Points:" << points1; //Reward
	                }
	            }
				else
	                cout << endl << "You dont have enough points to start" << endl;
	            break;
	            
	        case 3:
	            cout << endl << " Current points:" << points1<<endl;
	            break;
            case 4:
	            rules();
                break;
	        case 5:
	            cout<<endl<<"Thankyou for playing!";
                exit(0);
	    }
	}
}
//------------multiplayer-----------
void multiplayer(){
	while(true)
	{
        cout <<endl<<endl<< endl << " What would you like to do?";
	    cout << endl << " (1)Standard \n (2)display points \n (3)Rules \n (4)Exit\n";
	    cin >> opt;
		int secret1 = rand() % 100 + 1;
		int secret2 = rand() % 100 + 1;
	    if(points1 >0 && points2 >0)
		{
	        switch (opt) 
            {
	            case 1:
					cout << endl << "Selected a random number between 1 and 100. Player 1, Try to guess it." << endl;
			       	if(points1 >0)
					{ 
			            do {
				            cout << endl << "Enter your guess: ";
				            cin >> guess1;
				            attempts1++;
				            int difference1 = abs(secret1 - guess1); // Calculate the absolute difference
				            if (guess1 < secret1) 
                            {
				                cout << endl << "Too low! Try again." << endl;
				                points1 -= 5; //Points deducted
				                cout << endl << "Points = " << points1<<endl;
				            } 
                            else if (guess1 > secret1) 
                            {
				                cout << endl << "Too high! Try again." << endl;
				                points1 -= 5;
				                cout << endl << "Points = " << points1<<endl;
				            } 
                            else 
                            {
				                cout << endl << "Congratulations! You guessed the number " << secret1 << " in " << attempts1 << " attempts." << endl;
				                points1 += 100 - (10 * attempts1); //Reward
				                break;
				            }
				
				            // Provide feedback for being closer
				            if (difference1 <= 10) 
                            {
				                cout << endl << "Getting warm! You are close to the number." << endl;
				            }
				                    
				        } while (guess1 != secret1);
			        }
					else
			            cout << endl << "You dont have enough points to start" << endl;
			        cout << endl << "Selected a random number between 1 and 100. Player 2, Try to guess it." << endl;
			        if(points2 >0)
					{ 
		                do {
				                 
				            cout << endl << "Enter your guess: ";
				            cin >> guess2;
				            attempts2++;
				            int difference2 = abs(secret2 - guess2); // Calculate the absolute difference
				            if (guess2 < secret2) {
				                cout << endl << "Too low! Try again." << endl;
				                points2 -= 5; //Points deducted
				                cout << endl << "Points = " << points2<<endl;
				            } 
                            else if (guess2 > secret2) {
				                cout << endl << "Too high! Try again." << endl;
				                points2 -= 5;
				                cout << endl << "Points = " << points2<<endl;
				            } 
                            else {
				                cout << endl << "Congratulations! You guessed the number " << secret2 << " in " << attempts2 << " attempts." << endl;
				                points2 += 100 - (10 * attempts2); //Reward
				                break;
				            }
				            // Provide feedback for being closer
				            if (difference2 <= 10) {
				                cout << endl << "Getting warm! You are close to the number." << endl;
				            }
				        } while (guess2 != secret2);
			        }
					else
                    {
			            cout << endl << "You dont have enough points to start" << endl;
			           	break;
			        }
			        if(points1 > points2)
			           	cout<<endl<<"Player 1 won!"<<endl<<"Points = "<<points1;
			        else if(points1 < points2)
			          	cout<<endl<<"Player 2 won!"<<endl<<"Points = "<<points2;
			        else
			        {	
			           	char ch;
			           	cout<<endl<<"ITS A DRAW!!"<<endl;
			           	cout<<endl<<"Do you want to rematch? (y/n): ";
			           	cin>>ch;
			           	if(ch == 'Y' || ch == 'y')
			           		multiplayer();
			           	else
			           		break;
					}
	            case 2:
	                cout << endl << "Points of player 1: " << points1;
	                cout << endl << "Points of player 2: " << points2<<endl;
	                break;
	            case 3:
	                rules();
	                break;
	            case 4:
	               	cout<<endl<<"Thankyou for playing!";
	                exit(0);
	        }
		}
		else
			cout << endl << "One Player dont have enough points to start" << endl;   
	}
}

void rules() {
    cout << endl << "Rules:\n Standard: User has to guess a number between 1 and 100\n Loss: -5 per wrong guess\n Reward: 10 times the attempts remaining"<<endl;
    cout << endl << "Rules:\n High Stakes: User has to place a bet and guess a number between 1 and 10\n Loss: 3 times the bet\n Reward: 2 times the bet"<<endl;
}
