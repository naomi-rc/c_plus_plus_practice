#include <iostream>
#include <cmath>
using namespace std;

/**
  Author: Naomi Catwell
  Date: May 9, 2019
  Description: Calculates the distance between two cities and allows the user to specify a unit of distance
*/

double claculateDistance(double lat1, double long1, double lat2, double long2);
double degToRad(double degrees);

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
	
	cout << endl << "Units of distance:" << endl;
	for(int i = 0; i < 4; i++){
		cout << i+1 << ") " << units[i] << endl;
	}
	
	do{
		cout << "Choose a valid unit of distance (number): ";
		cin >> unit;
				
	}while(unit < 1 || unit > 4);	
	unit--;
	
	distance = claculateDistance(coords[city1][0], coords[city1][1], coords[city2][0], coords[city2][1]);
	switch(unit){
		case 0: /*nothing*/; break; //km
		case 1: distance = distance * 1000; break; //m
		case 2: distance = distance * 0.62137; break; //miles
		case 3: distance= distance * 3280.8; break; //feet
	}
	
	cout << "The distance between " << cities[city1] << " and " << cities[city2] << " is " << distance << " " << units[unit];
	
	
	return 0;
}


double claculateDistance(double lat1, double long1, double lat2, double long2){
	double radius = 6371; //Radius of Earth in KM
	double lat1rad = degToRad(lat1);
	double long1rad = degToRad(long1);
	double lat2rad = degToRad(lat2);
	double long2rad = degToRad(long2);
	
  	double a = sin((lat2rad - lat1rad)/2);
  	double b = sin((long2rad - long1rad)/2);
  	return 2.0 * radius * asin(sqrt(a * a + cos(lat1rad) * cos(lat2rad) * b * b));
}


double degToRad(double degrees){
	return (degrees * M_PI / 180);
}
