#pragma once
class GravityGame
{

public:

	double boxLocation;   //  horizontal location of box
	double boxVelocity;   //  horizontal velocity of box
	int boxWidth;         // width of box in pixels.
	double initialAltitude;
	double ballAltitude;  // vertical location of ball
	double ballLocation;  //  horizontal location of ball
	double g;         //  gravitational acceleration
	double time;      // elapsed time.
	double timeIncrement;

	GravityGame()
	{
		//  Set initial values.
		boxLocation = 0.0;
		boxVelocity = 25.0;
		boxWidth = 120;
		initialAltitude = 720.0;
		ballAltitude = initialAltitude;
		ballLocation = 230.0;
		time = 0.0;
		timeIncrement = 0.05;

		//g = 9.81;    // Earth
	    //g = 1.624;  //  Moon
	    g = 24.8;   //  Jupiter
	}

	void Game();
	
};

