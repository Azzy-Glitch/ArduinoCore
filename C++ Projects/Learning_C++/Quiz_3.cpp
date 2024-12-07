#include <iostream>
using namespace std;

int main()
{
    int Team_1_points, Team_2_points, Team_3_points;
    float Team_1_runRate, Team_2_runRate, Team_3_runRate;

    cout << "Enter points for team 1: ";
    cin >> Team_1_points;
    cout << "Enter run rate for team 1: ";
    cin >> Team_1_runRate;

    cout << "Enter points for team 2: ";
    cin >> Team_2_points;
    cout << "Enter run rate for team 2: ";
    cin >> Team_2_runRate;

    cout << "Enter points for team 3: ";
    cin >> Team_3_points;
    cout << "Enter run rate for team 3: ";
    cin >> Team_3_runRate;

     cout << "\t\tTeam Performance Summary" << endl;
    cout << "   -------------------------------------------------" << endl;
    cout << "   Team 1 has gained " << Team_1_points
         << " points with a run rate of " << Team_1_runRate << "." << endl;

    cout << "   Team 2 has gained " << Team_2_points
         << " points with a run rate of " << Team_2_runRate << "." << endl;

    cout << "   Team 3 has gained " << Team_3_points
         << " points with a run rate of " << Team_3_runRate << "." << endl;

    // Finding the best team based on points and run rate
    if (Team_1_points > Team_2_points && Team_1_points > Team_3_points)
    {
        cout << "Team 1 is the best team." << endl;
    }
    else if (Team_2_points > Team_1_points && Team_2_points > Team_3_points)
    {
        cout << "Team 2 is the best team." << endl;
    }
    else if (Team_3_points > Team_1_points && Team_3_points > Team_2_points)
    {
        cout << "Team 3 is the best team." << endl;
    }
    else
    {
        // If points are equal, compare run rates
        if (Team_1_points == Team_2_points && Team_1_points > Team_3_points)
        {
            if (Team_1_runRate > Team_2_runRate)
            {
                cout << "Team 1 is the best team." << endl;
            }
            else
            {
                cout << "Team 2 is the best team." << endl;
            }
        }
        else if (Team_1_points == Team_3_points && Team_1_points > Team_2_points)
        {
            if (Team_1_runRate > Team_3_runRate)
            {
                cout << "Team 1 is the best team." << endl;
            }
            else
            {
                cout << "Team 3 is the best team." << endl;
            }
        }
        else if (Team_2_points == Team_3_points && Team_2_points > Team_1_points)
        {
            if (Team_2_runRate > Team_3_runRate)
            {
                cout << "Team 2 is the best team." << endl;
            }
            else
            {
                cout << "Team 3 is the best team." << endl;
            }
        }
        else
        {
            // All teams have the same points
            if (Team_1_runRate > Team_2_runRate && Team_1_runRate > Team_3_runRate)
            {
                cout << "Team 1 is the best team." << endl;
            }
            else if (Team_2_runRate > Team_1_runRate && Team_2_runRate > Team_3_runRate)
            {
                cout << "Team 2 is the best team." << endl;
            }
            else if (Team_3_runRate > Team_1_runRate && Team_3_runRate > Team_2_runRate)
            {
                cout << "Team 3 is the best team." << endl;
            }
            else
            {
                cout << "It's a tie." << endl;
            }
        }
    }

    return 0;
}
