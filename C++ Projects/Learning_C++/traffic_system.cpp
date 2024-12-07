#include <iostream>
#include <string>

using namespace std;

// Enum for traffic light states
enum TrafficLightState
{
    RED,
    YELLOW,
    GREEN
};

// Function to display the current state of the traffic light
void displayTrafficLight(TrafficLightState state)
{
    switch (state)
    {
    case RED:
        cout << "Traffic Light: RED - Stop!" << endl;
        break;
    case YELLOW:
        cout << "Traffic Light: YELLOW - Get Ready!" << endl;
        break;
    case GREEN:
        cout << "Traffic Light: GREEN - Go!" << endl;
        break;
    }
}

// Structure to represent a Traffic Lane
struct TrafficLane
{
    string laneName;
    int vehicleCount;
    TrafficLightState lightState;
};

// Function to update the traffic light state
void updateTrafficLight(TrafficLane &lane, TrafficLightState newState)
{
    lane.lightState = newState;
    cout << "Updated traffic light for " << lane.laneName << " to ";
    displayTrafficLight(newState);
}

// Function to add or remove vehicles
void manageVehicles(TrafficLane &lane, int count)
{
    if (count > 0)
    {
        lane.vehicleCount += count;
        cout << count << " vehicles added to " << lane.laneName << endl;
    }
    else if (count < 0 && abs(count) <= lane.vehicleCount)
    {
        lane.vehicleCount += count;
        cout << abs(count) << " vehicles removed from " << lane.laneName << endl;
    }
    else
    {
        cout << "Invalid operation. Check vehicle count." << endl;
    }
    cout << "Current vehicle count in " << lane.laneName << ": " << lane.vehicleCount << endl;
}

int main()
{
    TrafficLane lane1 = {"North Lane", 0, RED};
    TrafficLane lane2 = {"South Lane", 0, RED};
    TrafficLane lane3 = {"East Lane", 0, RED};
    TrafficLane lane4 = {"West Lane", 0, RED};

    int choice;
    bool running = true;

    while (running)
    {
        cout << "\nTraffic Management System Menu" << endl;
        cout << "1. Display Traffic Lights" << endl;
        cout << "2. Change Traffic Light" << endl;
        cout << "3. Add Vehicles to Lane" << endl;
        cout << "4. Remove Vehicles from Lane" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Displaying current traffic light states:" << endl;
            displayTrafficLight(lane1.lightState);
            displayTrafficLight(lane2.lightState);
            displayTrafficLight(lane3.lightState);
            displayTrafficLight(lane4.lightState);
            break;
        }
        case 2:
        {
            int laneChoice;
            cout << "Select Lane to Change Traffic Light (1-North, 2-South, 3-East, 4-West): ";
            cin >> laneChoice;

            int newState;
            cout << "Enter New Traffic Light State (0-RED, 1-YELLOW, 2-GREEN): ";
            cin >> newState;

            if (laneChoice >= 1 && laneChoice <= 4 && newState >= 0 && newState <= 2)
            {
                switch (laneChoice)
                {
                case 1:
                    updateTrafficLight(lane1, static_cast<TrafficLightState>(newState));
                    break;
                case 2:
                    updateTrafficLight(lane2, static_cast<TrafficLightState>(newState));
                    break;
                case 3:
                    updateTrafficLight(lane3, static_cast<TrafficLightState>(newState));
                    break;
                case 4:
                    updateTrafficLight(lane4, static_cast<TrafficLightState>(newState));
                    break;
                }
            }
            else
            {
                cout << "Invalid lane or traffic light state." << endl;
            }
            break;
        }
        case 3:
        {
            int laneChoice, count;
            cout << "Select Lane to Add Vehicles (1-North, 2-South, 3-East, 4-West): ";
            cin >> laneChoice;
            cout << "Enter number of vehicles to add: ";
            cin >> count;

            if (laneChoice >= 1 && laneChoice <= 4 && count > 0)
            {
                switch (laneChoice)
                {
                case 1:
                    manageVehicles(lane1, count);
                    break;
                case 2:
                    manageVehicles(lane2, count);
                    break;
                case 3:
                    manageVehicles(lane3, count);
                    break;
                case 4:
                    manageVehicles(lane4, count);
                    break;
                }
            }
            else
            {
                cout << "Invalid lane or count." << endl;
            }
            break;
        }
        case 4:
        {
            int laneChoice, count;
            cout << "Select Lane to Remove Vehicles (1-North, 2-South, 3-East, 4-West): ";
            cin >> laneChoice;
            cout << "Enter number of vehicles to remove: ";
            cin >> count;

            if (laneChoice >= 1 && laneChoice <= 4 && count > 0)
            {
                switch (laneChoice)
                {
                case 1:
                    manageVehicles(lane1, -count);
                    break;
                case 2:
                    manageVehicles(lane2, -count);
                    break;
                case 3:
                    manageVehicles(lane3, -count);
                    break;
                case 4:
                    manageVehicles(lane4, -count);
                    break;
                }
            }
            else
            {
                cout << "Invalid lane or count." << endl;
            }
            break;
        }
        case 5:
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    cout << "Exiting Traffic Management System. Goodbye!" << endl;
    return 0;
}