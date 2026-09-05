#include <iostream>
#include <string>
#include <regex>
#include <random>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

class PasswordAnalyzer {
private:
    string password;

public:
    PasswordAnalyzer(const string& pwd) : password(pwd) {}

    bool hasUppercase() const {
        return regex_search(password, regex("[A-Z]"));
    }

    bool hasLowercase() const {
        return regex_search(password, regex("[a-z]"));
    }

    bool hasDigit() const {
        return regex_search(password, regex("[0-9]"));
    }

    bool hasSpecialChar() const {
        return regex_search(password, regex("[^A-Za-z0-9]"));
    }

    bool hasRepeatedPattern() const {
        for (size_t i = 0; i + 2 < password.length(); i++) {
            if (password[i] == password[i + 1] &&
                password[i] == password[i + 2]) {
                return true;
            }
        }
        return false;
    }

    int calculateScore() const {
        int score = 0;

        if (password.length() >= 8) score += 15;
        if (password.length() >= 12) score += 15;
        if (password.length() >= 16) score += 10;

        if (hasUppercase()) score += 15;
        if (hasLowercase()) score += 15;
        if (hasDigit()) score += 15;
        if (hasSpecialChar()) score += 15;

        if (hasRepeatedPattern()) score -= 15;

        if (score < 0) score = 0;
        if (score > 100) score = 100;

        return score;
    }

    double calculateEntropy() const {
        int poolSize = 0;

        if (hasLowercase()) poolSize += 26;
        if (hasUppercase()) poolSize += 26;
        if (hasDigit()) poolSize += 10;
        if (hasSpecialChar()) poolSize += 32;

        if (poolSize == 0)
            return 0;

        return password.length() * log2(poolSize);
    }

    string getStrength() const {
        int score = calculateScore();

        if (score >= 85)
            return "VERY STRONG";
        else if (score >= 70)
            return "STRONG";
        else if (score >= 50)
            return "MEDIUM";
        else if (score >= 30)
            return "WEAK";
        else
            return "VERY WEAK";
    }

    void displayReport() const {
        cout << "\n========================================\n";
        cout << "      PASSWORD SECURITY ANALYSIS\n";
        cout << "========================================\n";

        cout << "Password Length       : "
             << password.length() << '\n';

        cout << "Uppercase Letter      : "
             << (hasUppercase() ? "YES" : "NO") << '\n';

        cout << "Lowercase Letter      : "
             << (hasLowercase() ? "YES" : "NO") << '\n';

        cout << "Digit                 : "
             << (hasDigit() ? "YES" : "NO") << '\n';

        cout << "Special Character     : "
             << (hasSpecialChar() ? "YES" : "NO") << '\n';

        cout << "Repeated Pattern      : "
             << (hasRepeatedPattern() ? "YES" : "NO") << '\n';

        cout << fixed << setprecision(2);

        cout << "Estimated Entropy     : "
             << calculateEntropy()
             << " bits\n";

        cout << "Security Score        : "
             << calculateScore()
             << "/100\n";

        cout << "Password Strength     : "
             << getStrength()
             << '\n';

        cout << "========================================\n";
    }
};


class PasswordGenerator {
private:
    mt19937 randomEngine;

public:
    PasswordGenerator()
        : randomEngine(random_device{}()) {}

    string generate(
        int length,
        bool useUppercase = true,
        bool useLowercase = true,
        bool useDigits = true,
        bool useSymbols = true
    ) {

        string characters;

        if (useUppercase)
            characters +=
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (useLowercase)
            characters +=
                "abcdefghijklmnopqrstuvwxyz";

        if (useDigits)
            characters +=
                "0123456789";

        if (useSymbols)
            characters +=
                "!@#$%^&*()-_=+[]{};:,.<>?";

        if (characters.empty())
            return "";

        uniform_int_distribution<int> distribution(
            0,
            characters.size() - 1
        );

        string result;

        for (int i = 0; i < length; i++) {
            result +=
                characters[distribution(randomEngine)];
        }

        return result;
    }
};


void displayMenu() {
    cout << "\n\n";
    cout << "========================================\n";
    cout << "      CYBER SECURITY TOOLKIT\n";
    cout << "========================================\n";
    cout << "1. Analyze Password\n";
    cout << "2. Generate Secure Password\n";
    cout << "3. Generate Multiple Passwords\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
}


int main() {

    PasswordGenerator generator;

    int choice;

    do {

        displayMenu();

        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {

            string password;

            cout << "\nEnter password: ";
            getline(cin, password);

            PasswordAnalyzer analyzer(password);

            analyzer.displayReport();
        }

        else if (choice == 2) {

            int length;

            cout << "\nEnter password length: ";
            cin >> length;

            if (length < 8) {
                cout << "\nRecommended minimum length is 8.\n";
                continue;
            }

            string password =
                generator.generate(length);

            cout << "\nGenerated Password:\n";
            cout << password << '\n';

            PasswordAnalyzer analyzer(password);

            analyzer.displayReport();
        }

        else if (choice == 3) {

            int count;
            int length;

            cout << "\nHow many passwords? ";
            cin >> count;

            cout << "Password length: ";
            cin >> length;

            cout << "\n========================================\n";
            cout << "        GENERATED PASSWORDS\n";
            cout << "========================================\n";

            for (int i = 1; i <= count; i++) {

                string password =
                    generator.generate(length);

                PasswordAnalyzer analyzer(password);

                cout
                    << setw(3)
                    << i
                    << ". "
                    << password
                    << "  ["
                    << analyzer.calculateScore()
                    << "/100]"
                    << '\n';
            }
        }

        else if (choice == 0) {
            cout << "\nSecurity Toolkit Closed.\n";
        }

        else {
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}