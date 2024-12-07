#include <iostream>

using namespace std;

int main()
{
    double Amount_in_dollars;
    double British_pound, French_frac, Germen_deutshemark, Japanese_yen;

    cout << "Enter your amount in dollars: ";
    cin >> Amount_in_dollars;

    const double British_pound_rate = 1.487;
    const double French_frac_rate = 0.172;
    const double Germen_deutshemark_rate = 0.584;
    const double Japanese_yen_rate = 0.00955;

    British_pound = Amount_in_dollars / British_pound_rate;
    French_frac = Amount_in_dollars / French_frac_rate;
    Germen_deutshemark = Amount_in_dollars / Germen_deutshemark_rate;
    Japanese_yen = Amount_in_dollars / Japanese_yen_rate;

    cout << "British Pounds: " << British_pound << "\n";
    cout << "French_frac: " << French_frac << "\n";
    cout << "Germen_deutshemark: " << Germen_deutshemark << "\n";
    cout << " Japanese_yen: " << Japanese_yen << "\n";

    return 0;
}