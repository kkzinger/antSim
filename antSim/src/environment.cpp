/*
 * environment.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */

#include "environment.h"

ENVIRONMENT::ENVIRONMENT()
{

	this->startArea= new AREA;
	this->envExists= 0;

}

ENVIRONMENT::~ENVIRONMENT()
{
	delete this->startArea;

}

int ENVIRONMENT::createEnvironment(unsigned int sizeX, unsigned int sizeY)
{
	int status=0;
	unsigned int i, j;

	AREA *lastArea=this->startArea;
	AREA *newArea=NULL;

	for(i=0; i<sizeX; i++)
	{

		for(j=0; j<sizeY; j++)
		{
			if(i==0 && j==0) continue;  //Bei ersten element nichts zu tun --

			newArea= new AREA;

			if(i == 0)
			{
				newArea->north = lastArea;
				lastArea->south= newArea;
			}else if(j == 0)
			{
				lastArea = this->startArea;
				while(lastArea->east != NULL) lastArea = lastArea->east;

				newArea->west = lastArea;
				lastArea->east = newArea;
			}
			else
			{
				newArea->north = lastArea;
				lastArea->south= newArea;
				newArea->west = lastArea->west->south;
				lastArea->west->south->east = newArea;
			}

			lastArea = newArea;
		}

	}
	return status;
}

void ENVIRONMENT::printEnvironment()
{
	AREA *currArea;
	AREA *currArea1;

	currArea=this->startArea;
	currArea1 = currArea;


	while(currArea->east != NULL)
	{

		currArea1 = currArea;

		while(currArea1->south != NULL)
		{
			cout<<"X ";
			currArea1 = currArea1->south;
		}

	cout<<"X"<<endl;
	currArea = currArea->east;
	}


	currArea1 = currArea;

	while(currArea1->south != NULL)
	{
		cout<<"X ";
		currArea1 = currArea1->south;
	}

	cout<<"X"<<endl;
}

ENVIRONMENT* ENVIRONMENT::createInstance(unsigned int sizeX, unsigned int sizeY)
{
	static ENVIRONMENT instance;
	if(instance.envExists == 0)
	{
		instance.createEnvironment(sizeX,sizeY);
		instance.envExists = 1;
	}

	return &instance;
}
