#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Constants for ISA model
const double SEA_LEVEL_PRESSURE = 101325.0; // Pa
const double SEA_LEVEL_TEMP = 288.15; // K (15°C)
const double TEMP_LAPSE_RATE = 0.0065; // K/m
const double GAS_CONSTANT = 8.31432; // J/(mol·K)
const double GRAVITY = 9.80665; // m/s²
const double MOLAR_MASS_AIR = 0.0289644; // kg/mol

bool getInput(const string& prompt, double& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return true;
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

double calculateAtmosphericPressure(double altitude, double temperature) {
    // Convert altitude to meters (assuming input is in feet)
    double altitude_m = altitude * 0.3048;
    
    // Convert temperature to Kelvin (assuming input is in Celsius)
    double temp_K = temperature + 273.15;
    
    // Calculate pressure using barometric formula
    // P = P0 * (T/T0)^(g*M/(R*L))
    double exponent = (GRAVITY * MOLAR_MASS_AIR) / (GAS_CONSTANT * TEMP_LAPSE_RATE);
    double pressure = SEA_LEVEL_PRESSURE * pow(temp_K / SEA_LEVEL_TEMP, exponent);
    
    return pressure;
}

double calculateDensity(double pressure, double temperature) {
    // Convert temperature to Kelvin
    double temp_K = temperature + 273.15;
    
    // Calculate density using ideal gas law: ρ = P*M/(R*T)
    double density = (pressure * MOLAR_MASS_AIR) / (GAS_CONSTANT * temp_K);
    
    return density;
}

int main() {
    double altitude, temperature;
    
    cout << "Atmospheric Pressure Calculator for Aircraft" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Calculates atmospheric pressure and air density at altitude" << endl;
    cout << "Using International Standard Atmosphere (ISA) model" << endl << endl;
    
    // Get altitude
    while (!getInput("Enter aircraft altitude (feet): ", altitude));
    
    // Get outside temperature
    while (!getInput("Enter outside air temperature (°C): ", temperature));
    
    // Calculate pressure and density
    double pressure = calculateAtmosphericPressure(altitude, temperature);
    double density = calculateDensity(pressure, temperature);
    
    // Convert pressure to different units
    double pressure_hPa = pressure / 100; // Convert Pa to hPa
    double pressure_inHg = pressure * 0.0002953; // Convert Pa to inches of mercury
    double pressure_psi = pressure / 6894.76; // Convert Pa to PSI
    
    cout << fixed << setprecision(2);
    cout << "\nResults at " << altitude << " ft altitude:" << endl;
    cout << "Temperature: " << temperature << "°C" << endl;
    cout << "Atmospheric Pressure:" << endl;
    cout << "  " << pressure << " Pa" << endl;
    cout << "  " << pressure_hPa << " hPa" << endl;
    cout << "  " << pressure_inHg << " inHg" << endl;
    cout << "  " << pressure_psi << " PSI" << endl;
    cout << "Air Density: " << density << " kg/m³" << endl;
    
    // Additional flight-related information
    cout << "\nFlight Information:" << endl;
    cout << "Pressure altitude: " << altitude << " ft" << endl;
    cout << "Density altitude: ";
    
    // Calculate density altitude
    double density_altitude = altitude + (SEA_LEVEL_TEMP - (temperature + 273.15)) / TEMP_LAPSE_RATE;
    cout << density_altitude << " ft" << endl;
    
    return 0;
}
