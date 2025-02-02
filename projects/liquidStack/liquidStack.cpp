#include <iostream>
using namespace std;

struct Liquid {
    string name;
    double density;
    double volume;
    Liquid* next;
    
    Liquid(string n, double d, double c) : name(n), density(d),volume(c) ,  next(nullptr) {};
};

class LiquidStack {
    private:
        Liquid* topNode;
        
    public:
        LiquidStack() : topNode(nullptr) {};
        
        void push(string name, double density, double volume){
            Liquid* current = topNode;
            Liquid* pre = nullptr;

            while (current != nullptr && current->density < density){
                pre = current;
                current = current->next;
            };

            if (current != nullptr && current->density == density) {
                    current->volume += volume;
            } else {
                Liquid* newLiquid = new Liquid(name, density, volume);
                if (pre == nullptr) {
                    newLiquid->next = topNode;
                    topNode = newLiquid;
                } else {
                    newLiquid->next = current;
                    pre->next = newLiquid;
                }
            }
        };

        void pop() {
            if (isEmpty()) {
                cout << "Stack is empty! Cannot pop." << endl;
                return;
            }
            Liquid* temp = topNode;
            topNode = topNode->next;
            delete temp;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
    Liquid top() {
        if (isEmpty()) {
            cout << "Stack is empty!"<< endl;
        }
        return *topNode;
    }

    ~LiquidStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};



int main() {
 LiquidStack stack;
    int choice;
    bool continueLoop = true;

    while (continueLoop) {
        cout << "Choose an action:\n";
        cout << "1. Push a liquid\n";
        cout << "2. Pop a liquid\n";
        cout << "3. View top liquid\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            double density, volume;
            cout << "Enter liquid name: ";
            cin >> name;
            cout << "Enter liquid density: ";
            cin >> density;
            cout << "Enter liquid volume: ";
            cin >> volume;
            stack.push(name, density, volume);
            break;
        }
        case 2:
            stack.pop();
            break;
        case 3:
            try {
                Liquid topLiquid = stack.top();
                cout << "Top Liquid: " << topLiquid.name << " with density " << topLiquid.density << " and volume " << topLiquid.volume << endl;
            } catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        case 4:
            continueLoop = false;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }

        if (continueLoop) {
            cout << "Do you want to continue? (1 for Yes, 0 for No): ";
            cin >> continueLoop;
        }
    }
    return 0;
}