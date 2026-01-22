#include<bits/stdc++.h>

using namespace std;

class Notification {
public:
    virtual void send(string message) = 0;
    virtual ~Notification() {}
};


class EmailNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending Email Notification: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending SMS Notification: " << message << endl;
    }
};
class PushNotification : public Notification {
public:
    void send(string message) override {
        cout << "Sending Push Notification: " << message << endl;
    }
};
class NotificationFactory {
public:
    Notification* createNotification(string& type) {
        if (type == "email") {
            return new EmailNotification();
        } else if (type == "sms") {
            return new SMSNotification();
        } else if (type == "push") {
            return new PushNotification();
        } else {
            cout << "Invalid notification type! " << endl;
            return nullptr;
        }
    }
};

int main(){
    string type= "sms";  

     NotificationFactory* myNotificationFactory = new NotificationFactory();

     Notification* myNotification = myNotificationFactory->createNotification(type);

        myNotification->send("Your order has been shipped!");
    
    return 0;
}