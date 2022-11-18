# CS361_Project
This software represents a fitness health tracker. There will be two sides to the software, one focusing on fitness planning, the other on nutrition planning

COMPILE:
This software uses a Makefile, compile with: make

RUN:
The software's Makefile creates an executable 'run', execute software with: ./run
Additionally, start microservice with: python3 calculate_goals.py

SOFTWARE FEATURES:
	1. Create a User Profile, this includes:
		a. Height
		b. Weight
		c. Age
		d. Goal (bulk or cut weight)
		e. Computer generated
			1. Daily Macronutrient goals
			2. Daily Maintenance calories
			3. Daily Goal calories
	2. Load an existing User Profile
		a. Search via name
	3. Update existing User Profile
		a. Allows to update all user's data
