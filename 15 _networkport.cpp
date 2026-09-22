#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {

    string ip;
    int startPort, endPort;

    cout << "========================================\n";
    cout << "        NETWORK PORT SCANNER\n";
    cout << "========================================\n";

    cout << "Enter target IP: ";
    cin >> ip;

    cout << "Enter starting port: ";
    cin >> startPort;

    cout << "Enter ending port: ";
    cin >> endPort;

    if (startPort < 1 || endPort > 65535 || startPort > endPort) {
        cout << "\nInvalid port range!\n";
        return 0;
    }

    srand(time(0));

    cout << "\nStarting scan on " << ip << "...\n";
    cout << "----------------------------------------\n";

    int openPorts = 0;

    for (int port = startPort; port <= endPort; port++) {

        int status = rand() % 10;

        if (status < 2) {

            openPorts++;

            string service;

            if (port == 21)
                service = "FTP";
            else if (port == 22)
                service = "SSH";
            else if (port == 25)
                service = "SMTP";
            else if (port == 53)
                service = "DNS";
            else if (port == 80)
                service = "HTTP";
            else if (port == 110)
                service = "POP3";
            else if (port == 143)
                service = "IMAP";
            else if (port == 443)
                service = "HTTPS";
            else if (port == 3306)
                service = "MySQL";
            else
                service = "Unknown";

            cout << "[OPEN]   Port "
                 << port
                 << "   Service: "
                 << service
                 << endl;
        }
    }

    cout << "----------------------------------------\n";

    cout << "\nScan completed.\n";
    cout << "Target: " << ip << endl;
    cout << "Ports scanned: "
         << endPort - startPort + 1 << endl;
    cout << "Open ports found: "
         << openPorts << endl;

    cout << "\n========================================\n";
    cout << "             SCAN COMPLETE\n";
    cout << "========================================\n";

    return 0;
}