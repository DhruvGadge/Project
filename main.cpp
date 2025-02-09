#include <iostream>
#include <string>
using namespace std;

// Define a proper structure for Voter
struct Voter {
    string name;
    int age;
    string vote;
};

class VotingSystem {
private:
    Voter voter[20]; // Array to store voter details
    int a, b, c1, d, e; // Vote counters for different parties
    int c; // Number of votes cast

public:
    // Constructor to initialize vote counters
    VotingSystem() : a(0), b(0), c1(0), d(0), e(0), c(0) {}

    void displayMenu() {
        cout << "Welcome to the Futuristic Voting System\n";
        cout << "Press 1 to Cast Vote\n";
        cout << "Press 2 to View Results\n";
        cout << "Press 3 to View Voter Details\n";
        cout << "Press 4 to Exit\n";
        cout << "Enter your choice: ";
    }

    void castVote() {
        if (c >= 20) {
            cout << "All voters have voted. No further votes will be accepted.\n";
            return;
        }

        cout << "Enter Your Name and Age: ";
        cin >> voter[c].name >> voter[c].age;

        if (voter[c].age < 18) {
            cout << "You are underage. You cannot vote!\n";
            return;
        }

        string cname;
        cout << "Enter the Name of the Political Party you want to vote for: ";
        cin >> cname;

        if (cname == "bjp" || cname == "BJP" || cname == "Bharatiya Janata Party" || cname == "bharatiya janata party") {
            a++;
        } else if (cname == "congress" || cname == "Congress" || cname == "INC" || cname == "inc") {
            b++;
        } else if (cname == "AAP" || cname == "aap" || cname == "Aam Aadmi Party" || cname == "aam aadmi party") {
            c1++;
        } else if (cname == "TMC" || cname == "tmc" || cname == "Trinamool Congress" || cname == "trinamool congress") {
            d++;
        } else if (cname == "SS" || cname == "ss" || cname == "Shiv Sena" || cname == "shiv sena") {
            e++;
        } else {
            cout << "Invalid party name. Please try again with a valid party name.\n";
            return;
        }

        // Store vote details in the array
        voter[c].vote = cname;
        c++; // Increment vote count
        cout << "Vote casted for " << cname << endl;
    }

    void voterdisplay() {
        cout << "Voter Details:\n";
        for (int i = 0; i < c; i++) {
            cout << "Name: " << voter[i].name << ", Age: " << voter[i].age << ", Voted for: " << voter[i].vote << endl;
        }
    }

    void displayResults() {
        cout << "Voting Results:\n";
        cout << "Votes Casted for BJP [Bharatiya Janata Party]: " << a << "\n";
        cout << "Votes Casted for INC [Indian National Congress]: " << b << "\n";
        cout << "Votes Casted for AAP [Aam Aadmi Party]: " << c1 << "\n";
        cout << "Votes Casted for TMC [Trimool Congress]: " << d << "\n";
        cout << "Votes Casted for Shiv Sena: " << e << "\n";
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    castVote();
                    break;
                case 2:
                    displayResults();
                    break;
                case 3:
                    voterdisplay();
                    break;
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    VotingSystem votingSystem;
    votingSystem.run();
    return 0;
}
