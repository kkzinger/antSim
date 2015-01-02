/*
 * antSim_main.cpp
 *
 *  Created on: 29.10.2014
 *      Author: Gerold
 */


#include <iostream>

#include "../header/ENVIRONMENT.h"

int main()
{
	ENVIRONMENT* env;
	env = ENVIRONMENT::createInstance(3,3);

	env->startArea->factory->setDefaultMaxAgeGlobal(9);	//Setze Default Max Age f�r alle Items die erstellt werden

	int i;

	env->placeInital(1,0,0);
	for(i=0;i<=10;i++)
	{
		env->actAll(1);
	}
	env->printEnvironment();
	return 0;
}

