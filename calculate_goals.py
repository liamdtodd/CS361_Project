import time
import random


while (True):
    f = open("calculate_goals.txt", "r")
    contents = f.readline()

    time.sleep(2)

    if (contents == "run\n"):

        print("Received request...\n\n")

        user_maintenance = int(f.readline())
        user_goal = int(f.readline())

        f.close()

        protein_goal = (0.2 * user_goal) / 4
        fat_goal = (0.3 * user_goal) / 9
        carbs_goal = (0.5 * user_goal) / 4


        print("Writing return data to file.")

        f = open("calculate_goals.txt", "w")
        f.write(str(protein_goal) + "\n" + str(fat_goal) + "\n" + str(carbs_goal) + "\n")

    f.close()
