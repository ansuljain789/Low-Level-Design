#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Observer {
public:
    virtual void update(int orderId, const string& status) = 0;
    virtual ~Observer() {}
};

class EmailObserver : public Observer {
public:
    void update(int orderId, const string& status) override {
        cout << "📧 Email: Order " << orderId << " is " << status << endl;
    }
};

class SMSObserver : public Observer {
public:
    void update(int orderId, const string& status) override {
        cout << "📱 SMS: Order " << orderId << " is " << status << endl;
    }
};

class PushObserver : public Observer {
public:
    void update(int orderId, const string& status) override {
        cout << "🔔 Push: Order " << orderId << " is " << status << endl;
    }
};

class Order {
private:
    int orderId;
    string status;
    vector<Observer*> observers;

public:
    Order(int id) : orderId(id), status("CREATED") {
        cout << "\n🛒 Order " << orderId << " CREATED\n" << endl;
    }

    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers() {
        for (Observer* obs : observers) {
            obs->update(orderId, status);
        }
        cout << endl;
    }

    void updateStatus(const string& newStatus) {
        status = newStatus;
        notifyObservers();
    }
};

int main() {
    EmailObserver email;
    SMSObserver sms;
    PushObserver push;

    Order order(101);

    order.attach(&email);
    order.attach(&sms);
    order.attach(&push);

    order.updateStatus("SHIPPED");
    order.updateStatus("DELIVERED");

    return 0;
}
