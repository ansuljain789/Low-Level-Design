#include<bits/stdc++.h>

using namespace std;

struct OrderItem {
    string name;
    int quantity;
    double price;
};


class orderService {
    public:
        vector<OrderItem> takeOrder() {

            vector<OrderItem> order;

            int n;

            cout<<"enter number of items to order: ";
            cin>>n;


            for(int i=0;i<n;i++){
                OrderItem item;
                cout<<"\nitem"<<i+1<<":"<<endl;
                cin>>item.name;

                cout<<"quantity: "; 
                cin>>item.quantity;

                cout<<"price: ";
                cin>>item.price;

                order.push_back(item);
            }
            return order;
            
        }
};

class kitchenService {
    public:
        void prepareFood(const vector<OrderItem>& order) {
        cout << "\n Kitchen preparing:\n";
        for (auto &item : order) {
            cout << "- " << item.quantity << " x " << item.name << endl;
        }
    }
};

class BillingService {
    public:
        double generateBill(const vector<OrderItem>& order) {

            double total = 0.0;

            for(auto &item: order){
                total += item.quantity * item.price;
            }
        return total;
    }
};

class ReceiptService {
    public:
       void printReceipt(const vector<OrderItem>& order, double amount) {
        cout << " RECEIPT\n";
        for(auto &item: order){
             cout << item.name << " x " << item.quantity
                 << " = " << item.quantity * item.price << endl; cout << item.name << " x " << item.quantity
                 << " = " << item.quantity * item.price << endl;
        }
        cout<<"\nTotal Amount:" << amount << endl;
        cout << "Thank you for dining with us!\n";
    }
};

class RestaurantSystem {

    private:
        orderService order_service;
        kitchenService kitchen_service;
        BillingService billing_service;
        ReceiptService receipt_service;

    public:
        void processOrder() {

            auto order = order_service.takeOrder();

            kitchen_service.prepareFood(order);

           double total = billing_service.generateBill(order);

           receipt_service.printReceipt(order,total);

        }
            

};

int main(){
    RestaurantSystem restaurant;
    restaurant.processOrder();
    return 0;

}
