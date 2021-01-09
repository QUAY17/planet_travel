//Jennifer Quay Minnich jminnich@cnm.edu
//Program 3 Planet Travel!

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	//header
	cout << "\n Jennifer Q Minnich's Planet Travel Program";
	cout << "\n ************************************************************";
	cout << "\n Use this program as a guide to the galaxy! We will be traveling from Earth to other planets.";
	cout << "\n On our way, we will calculate the travel time depending on our speed in mph.";
	cout << "\n We will also determine our body weight by the planet's gravity.";
	cout << "\n ************************************************************";
	cout << "\n Please email me with any questions at jminnich@cnm.edu ";
	cout << "\n ************************************************************ \n";
	cout << "\n We are going to start with a few personal questions :) \n";
	

	//variables
	vector<string>planets = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune" };
	vector<unsigned int>distance = { 36000000, 67000000, 93000000, 141000000, 483000000, 886000000, 1782000000, 2793000000 };
	vector<float>gravity = { 0.27, 0.86, 1.00, 0.37, 2.64, 1.17, 0.92, 1.44 };
	string name = " ";
	int weight = 0;
	double speed = 0.0;
	char answer = ' ';
	int planetChoice = 0;

	//start program
	cout << "\n Please enter your name: ";
	getline(cin, name);
	cout << "\n Please enter your weight in pounds (lbs): ";
	cin >> weight;
	cout << "\n Now let's get to the fun stuff, " << name << "!";
	cout << "\n How fast would you like to travel across the solar system in miles per hour (mph)?";
	cin >> speed;

	//start play loop 
	do
	{
		//Ask user to choose what planet to travel to
		cout << "\n Let's send you to outer space, what planet would you like to vist? \n";

		//display the vector of planets 
		cout << setw(20);

		for (int i = 0; i < planets.size(); ++i)
		{
			cout << "\n" << i + 1 << ". " << setw(15) << planets.at(i);
		}

		//planet of choice
		cout << "\n\n Please enter the number: ";
		cin >> planetChoice;
		planetChoice--;
		cout << "\n ************************************************************ \n";

		//calculation of weight
		float planetWeight = 0.0;
		planetWeight = weight * gravity.at(planetChoice);
		cout << "\n Great choice, " << name << ", due to the surface gravity on " << planets.at(planetChoice) << " you will weigh " << planetWeight << " lbs.";

		//calculation of time traveled
		cout << "\n\n Now let's see how many hours it will take for you to get to " << planets.at(planetChoice) << " from Earth.";
		cout << "\n\n ************************************************************ \n";

		unsigned int travelTime = 0;
		unsigned int planetDistance = 0;
		unsigned int distanceEarth = 93000000;

		if (distance.at(planetChoice) > distanceEarth)
		{
			planetDistance = distance.at(planetChoice) - distanceEarth;
		}
		else
		{
			planetDistance = distanceEarth - distance.at(planetChoice);
		}

		travelTime = planetDistance / speed;

		//calculations to break down travel time
		//tell cout to write to 2 places of precision
		cout.setf(ios::showpoint | ios::fixed);
		cout.precision(2);
		cout << "\n Your trip to " << planets.at(planetChoice) << " will take approximately " << travelTime << " hours.";
		
		int years = 0;
		years = travelTime / 8760;
		int hoursLeft = 0;
		hoursLeft = travelTime - (8760 * years);
		int days = 0;
		days = hoursLeft / 24;
		int hours = 0;
		hours = hoursLeft - (days * 24);
		//summary
		cout << "\n That's " << years << " years " << days << " days and " << hours << " hours!";
		cout << "\n\n ************************************************************ \n";
		
		cout << "\n\n Do you want to travel to another planet? y/n";
		cin >> answer;
		 
	} while (answer == 'y');


	cout << "\n Hope you had an intergalactic adventure, come back to the comsos anytime, Bye!";

	return 0;
}



