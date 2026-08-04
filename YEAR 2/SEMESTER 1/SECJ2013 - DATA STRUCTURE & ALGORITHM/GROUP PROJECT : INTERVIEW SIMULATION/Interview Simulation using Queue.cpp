#include<iostream>
#include <windows.h>
using namespace std;

struct Candidate {
    string name;
    int id;
    int age;
    int slot;
    string status;
    Candidate *next;
};

const string TIME_SLOTS[] = {
    "9:00 AM - 10:00 AM",  // Slot 1
    "10:30 AM - 11:30 AM", // Slot 2
    "1:00 PM - 2:00 PM",   // Slot 3
    "2:30 PM - 3:30 PM",   // Slot 4
    "4:00 PM - 5:00 PM"    // Slot 5
};

class Queue{
    private:
        Candidate* front;
        Candidate* rear;
        Candidate* processedFront;
        int numItems;

    public:
    //Constructor
    Queue() : front(NULL), rear(NULL), processedFront(NULL), numItems(0) {}

    //Destructor
    ~Queue() {
        clear();
        while (processedFront != NULL) {
            Candidate* temp = processedFront;
            processedFront = processedFront->next;
            delete temp;
        }
    }

    //Destroy Queue
    void enQueue(const Candidate& item){
        Candidate* newNode = new Candidate;
        *newNode = item;
        newNode->next = NULL;

        if(isEmpty()){
            front = newNode;
            rear = newNode;
        } else{
            rear->next = newNode;
            rear = newNode;
        }
        numItems++;
    }

    void deQueue(Candidate& item) {
        Candidate* temp = NULL;

        if (isEmpty()) {
            cout << "The queue is empty.\n";
        } else {
            item = *front;
            
            Candidate* processedNode = new Candidate;
            *processedNode = item;
            processedNode->status = "Processed";
            processedNode->next = NULL;

            if (processedFront == NULL) {
                processedFront = processedNode;
            } else {
                Candidate* current = processedFront;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = processedNode;
            }

            temp = front;
            front = front->next;
            delete temp;
            numItems = numItems - 1;
            if(front == NULL) {
                rear = NULL;
            }
        }
    }

    bool isEmpty() const{
        return numItems == 0;
    }

    void clear(){
        Candidate candidate;
        while (!isEmpty()){
            deQueue(candidate);
        }
    }

    void assignInterviewSlot() {
        if (isEmpty()) {
            cout << "No candidates in the queue to assign an interview slot.\n";
        } else {
            cout << "\nAssigning slot for the first candidate in queue:\n";
            cout << "--------------------------------\n";
            cout << "Candidate Name: " << front->name << "\n";
            cout << "Candidate ID: " << front->id << "\n";
            cout << "\nAvailable Time Slots:\n";
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << TIME_SLOTS[i] << "\n";
            }
            
            int selectedSlot;
            do {
                cout << "\nSelect interview slot (1-5): ";
                cin >> selectedSlot;
                if (selectedSlot < 1 || selectedSlot > 5) {
                    cout << "Invalid slot! Please select between 1-5.\n";
                }
            } while (selectedSlot < 1 || selectedSlot > 5);
            
            front->slot = selectedSlot;
            cout << "\nSlot assigned successfully!\n";
            cout << "Candidate: " << front->name << "\n";
            cout << "Assigned Time: " << TIME_SLOTS[selectedSlot - 1] << "\n";
            cout << "\nProcessing...";
            Sleep(3000);
            system("cls");
        }
    }   

    int getTotalInterviewees() const {
        return numItems;
    }

    void viewCurrentQueue() const {
        if (!isEmpty()) {
            cout << "\nWAITING CANDIDATES:\n";
            cout << "--------------------------------\n";
            Candidate* current = front;
            while (current != NULL) {
                cout << "Name: " << current->name << "\n";
                cout << "ID: " << current->id << "\n";
                cout << "Age: " << current->age << "\n";
                cout << "Time Slot: Waiting to be processed" << endl;
                cout << "Status: Waiting\n";
                cout << "--------------------------------\n";
                current = current->next;
            }
        }

        if (processedFront != NULL) {
            cout << "\nPROCESSED CANDIDATES:\n";
            cout << "--------------------------------\n";
            Candidate* current = processedFront;
            while (current != NULL) {
                cout << "Name: " << current->name << "\n";
                cout << "ID: " << current->id << "\n";
                cout << "Age: " << current->age << "\n";
                cout << "Time Slot: ";
                if (current->slot > 0 && current->slot <= 5) {
                    cout << TIME_SLOTS[current->slot - 1];
                } else {
                    cout << "Waiting to be processed";
                }
                cout << endl;
                cout << "Status: " << current->status << "\n";
                cout << "--------------------------------\n";
                current = current->next;
            }
        }

        if (isEmpty() && processedFront == NULL) {
            cout << "\nNo candidates in the system.\n";
        }
    }

    Candidate getFrontCandidate() const {
        if (!isEmpty()) {
            return *front;
        }
        throw runtime_error("Queue is empty");
    }

    void setFrontSlot(int slot) {
        if (!isEmpty() && slot >= 1 && slot <= 5) {
            front->slot = slot;
        }
    }
};

int main() {
    Queue interviewQueue;
    int choice;
    int nextId = 1001; 
    
    do {
        system("cls");
        cout << "\n=== Interview Simulation System ===\n";
        cout << "1. Add New Candidate\n";
        cout << "2. Process Next Candidate & Assign Slot\n";
        cout << "3. View Current Queue\n";
        cout << "4. View Total Candidates\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                Candidate newCandidate;
                cin.ignore(); 
                
                cout << "\nEnter candidate name: ";
                getline(cin, newCandidate.name);
                
                newCandidate.id = nextId++;
                cout << "\nAssigned ID: " << newCandidate.id << endl;
                
                cout << "\nEnter candidate age: ";
                cin >> newCandidate.age;
                
                newCandidate.status = "Waiting";
                newCandidate.next = nullptr;
                
                interviewQueue.enQueue(newCandidate);
                cout << "\nCandidate added successfully!\n";
                cout << "Time Slot: Waiting to be processing\n";
                cout << "\nProcessing application...";
                Sleep(3000);
                system("cls");
                break;
            }
            
            case 2: {
                Candidate processedCandidate;
                if (!interviewQueue.isEmpty()) {
                    try {
                        Candidate frontCandidate = interviewQueue.getFrontCandidate();
                        cout << "\nProcessing next candidate:\n";
                        cout << "--------------------------------\n";
                        cout << "ID: " << frontCandidate.id << endl;
                        cout << "Name: " << frontCandidate.name << endl;
                        cout << "Age: " << frontCandidate.age << endl;
                        cout << "--------------------------------\n";

                        cout << "\nAvailable Time Slots:\n";
                        for (int i = 0; i < 5; i++) {
                            cout << i + 1 << ". " << TIME_SLOTS[i] << "\n";
                        }
                        
                        int selectedSlot;
                        do {
                            cout << "\nSelect interview slot (1-5): ";
                            cin >> selectedSlot;
                            if (selectedSlot < 1 || selectedSlot > 5) {
                                cout << "Invalid slot! Please select between 1-5.\n";
                            }
                        } while (selectedSlot < 1 || selectedSlot > 5);

                        interviewQueue.setFrontSlot(selectedSlot);
                        
                        interviewQueue.deQueue(processedCandidate);
                        
                        cout << "\nCandidate processed successfully!\n";
                        cout << "Assigned Time: " << TIME_SLOTS[selectedSlot - 1] << "\n";
                        cout << "\nProcessing...";
                        Sleep(3000);
                    } catch (runtime_error& e) {
                        cout << e.what() << endl;
                        Sleep(2000);
                    }
                } else {
                    cout << "\nNo candidates in the queue to process.\n";
                    Sleep(2000);
                }
                system("cls");
                break;
            }
            
            case 3: {
                system("cls");
                cout << "\n=== Interview Queue Status ===\n";
                interviewQueue.viewCurrentQueue();
                cout << "\nPress Enter to return to main menu...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }
            
            case 4: {
                system("cls");
                cout << "Total candidates in queue: " 
                     << interviewQueue.getTotalInterviewees() << endl;
                cout << "\nPress Enter to return to main menu...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            }
            
            case 5: {
                system("cls");
                cout << "\n\nExiting the Interview Simulation System... Goodbye!\n\n";
                break;
            }
            
            default: {
                cout << "Invalid choice! Please try again.\n";
                system("cls");
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
