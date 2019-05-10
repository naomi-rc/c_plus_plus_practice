#include <iostream>
#include <cmath>
using namespace std;

/**
  Author: Naomi Catwell
  Date: May 9, 2019
  Description: Calculates the distance between two cities and allows the user to specify a unit of distance
*/

double claculateDistance(double lat1, double lat2, double long1, double long2);
double degreeToRadians(double degrees);

int main(){
	
	cout << "This program calculates the distance between two cities and allows the user to specify a unit of distance." << endl << endl;
	
	int city1, city2, unit;
	double distance;
	
	string cities[] = {"temiscamingue", "portneuf", "gatineau", "pontiac", "montreal", "longueuil", "quebec city"};
	double coords[7][2] = {{47.2075, 78.7246}, {46.6985, 71.8910}, {45.4765, 75.7013}, {45.5423, 76.1091}, {45.5017, 73.5673}, {45.5369, 73.5107}, {46.8139, 71.2080}};
	string units[] = {"kilometers", "meters", "miles", "feet"};

	cout << "List of cities (Quebec)" << endl << endl;
	for(int i = 0; i < 7; i++){
		cout << i+1 << ") " << cities[i] << endl;
	}


	cout << "Choose a first city (number):";
	cin >> city1;
	city1--;
	
	cout << "Choose a second city (number):";
	cin >> city2;
	city2--;
	
	cout << "Units of distance:" << endl;
	for(int i = 0; i < 4; i++){
		cout << i+1 << ") " << units[i] << endl;
	}
	
	do{
		cout << "Choose a valid unit of distance (number): ";
		cin >> unit;
				
	}while(unit < 1 || unit > 4);	
	unit--;
	
	cout << coords[city1][0] << ", " << coords[city2][0] << ", " << coords[city1][1] << ", " << coords[city2][1] << endl << endl;
	distance = claculateDistance(coords[city1][0], coords[city2][0], coords[city1][1], coords[city2][1]);
	switch(unit){
		case 1: /*nothing*/; break; //km
		case 2: distance = distance * 1000; break; //m
		case 3: distance = distance * 0.62137; break; //miles
		case 4: distance= distance * 3280.8; break; //feet
	}
	
	cout << "The distance between " << cities[city1] << " and " << cities[city2] << " is " << distance << " " << units[unit];
	
	
	return 0;
}


double claculateDistance(double lat1, double lat2, double long1, double long2){
	double R = 6371; //Radius of Earth in KM
	double dLat = (lat2-lat1);
	double dLong = (long2-long1);
	
	double a = sin(dLat/2) * sin(dLat/2) + cos(degreeToRadians(lat1)) * cos(degreeToRadians(lat2)) * sin(dLong/2) * sin(dLong/2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	double d = R * c; // Distance in km 
	
  	return d;		
}


double degreeToRadians(double degrees){
	return degrees * (M_PI/180);
}
