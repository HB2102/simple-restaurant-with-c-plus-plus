#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include <cstring>
    using namespace std;

#define MAX 1000
#define FoodCount 21

#define PATHusers "users.txt"
#define PATHorders "orders.txt"

void mainMenu();

struct food
{
    string name;
    int price;
    int preparetime;
    string description;
    string kind;
};

struct order
{
    string user;
    int foodID;
    bool isPayed = false;
    int preparetime;
    bool ready = false;
    clock_t timer;
};

struct user{
    string username;
    string password;
};

order orders[MAX];
food foods[MAX];
user users[MAX];
user owner = {"mamad", "123"};
user activeUser;
int ordCount, userCount;

void SwapFoods(food *a, food *b){
    food c = *a;
    *a = *b;
    *b = c;
}

void SortFoods(){
    for(int i = 0; i < FoodCount; i++)
        for(int j = i; j < FoodCount; j++)
            if(foods[j].price > foods[i].price)
                SwapFoods(&foods[j], &foods[i]);
}

void SetFoods(){
    foods[0] = {"Khoresht Boughalamoon", 30000, 25, "khoresht boughalamoon taze va moghalafat", "cholo khoresht"};
    foods[1] = {"Khoresht Bademjan", 25000, 25, "khoreshte bademjan va mokhalafat", "cholo khoresht"};
    foods[2] = {"Loobia Plo", 22000, 20, "loobia plo ba sib zamini va mokhalafat", "cholo khoresht"};
    foods[3] = {"Ghorme Sabzi", 17000, 20, "ba sabzi haye taze va mokhalafat", "cholo khoresht"};
    foods[4] = {"Gheyme", 15000, 15, "kamelan pokhte shode va tord ba mokhalafat", "cholo khoresht"};
    foods[5] = {"Khoresht Sibzamini", 14000, 15, "khoreshte sibzamini ba kare va mokhalafat", "cholo khoresht"};  
    foods[6] = {"Kabab Dande", 40000, 25, "kabab dande goosfandie taze va mokhalafat", "kabab"};
    foods[7] = {"kabab Torsh", 30000, 25, "kabab barg ba torshie ezafe va mokhalafat", "kabab"};
    foods[8] = {"Morghe Torsh", 30000, 35, "morghe motevaset ba torshi va mokhalafat", "kabab"};
    foods[9] = {"Chlo Kabab", 25000, 25, "gooshte taze va salem ba mokhalafat", "kabab"};
    foods[10] = {"Kabab Barg", 27000, 25, "kabab barg va mokhalafat", "kabab"};
    foods[11] = {"Jooje Kabab", 250000, 30, "akbar jooje va mokhalafat", "kabab"};       
    foods[12] = {"Zeytoon Parvardeh", 12000, 0, "zeytoon parvarde mahali", "mokhalafat"};
    foods[13] = {"Salad Fasl", 10000, 0, "salad fasle sade", "mokhalafat"};
    foods[14] = {"Salad Shirazi", 8000, 0, "salad shirazi taze", "mokhalafat"};
    foods[15] = {"Maste Mahali", 5000, 0, "mast mahali taze", "mokhalafat"};
    foods[16] = {"Dooghe mahali", 8000, 0, "doogh mahali taze", "noshidani"};
    foods[17] = {"Nooshabe Meshki", 8000, 0, "nooshabe sade", "noshidani"};
    foods[18] = {"Nooshabe Narenji", 8000, 0, "nooshabe sade", "noshidani"};
    foods[19] = {"Doogh", 5000, 0, "doogh karkhane ei", "noshidani"};
    foods[20] = {"Ab Madani", 4000, 0, "Ab madani damavand", "noshidani"};
}

void PrintFood(food food){
    cout << food.name << " " << food.price << " | " << food.description << "\n";
}

void PrintAllFoods(){
    for(int i = 0; i < FoodCount; i++){
        printf("%02d. ", i);
        PrintFood(foods[i]);
    }
}

void PrintFoodByCategory(string kind){
    for(int i = 0; i < FoodCount; i++)
        if(foods[i].kind == kind)
            PrintFood(foods[i]);
}

bool CheckUser(user u){
    for(int i = 0; i < userCount; i++)
        if(u.username == users[i].username && u.password == users[i].password)
            return true;
    
    return false;
}

bool CheckOwner(user u){
    if(u.username == owner.username && u.password == owner.password)
        return true;
    return false;
}

int CountItems(string path){
    ifstream fp(path);
    int cnt = 0;
    char c, bc;
    c = fp.get();
    while(c != EOF){
        bc = c;
        c = fp.get();
        if((c == '\n' || c == EOF) && bc != '\n')
            cnt++;
    }
    fp.close();
    return cnt;
}

void ReadUsers(){
    userCount = CountItems(PATHusers);
    ifstream fp(PATHusers);
    for(int i = 0; i < userCount; i++)
        fp >> users[i].username >> users[i].password;
    fp.close();
}

void UpdateUsersFile(){
    ofstream fp(PATHusers);
    int size = sizeof(users) / sizeof(user);
    for(int i = 0; i < size; i++)
        fp << users[i].username << " " << users[i].password << "\n";
    fp.close();
}



void ReadOrders(){
    ordCount = CountItems(PATHorders);
    ifstream fp(PATHorders);
    for(int i = 0; i < ordCount; i++)
        fp >> orders[i].user >> orders[i].foodID >> orders[i].isPayed >> orders[i].preparetime >> orders[i].ready;
    fp.close();
}

void UpdateOrdersFile(){
    ofstream fp(PATHorders);
    for(int i = 0; i < ordCount; i++)
        fp << orders[i].user << " " << orders[i].foodID << " " << orders[i].isPayed << " " << orders[i].preparetime << " " << orders[i].ready <<"\n";
    fp.close();
}

void AddOrder(){
    cout << "Enter your food:\n";
    cin >> orders[ordCount].foodID;
    orders[ordCount].user = activeUser.username;
    orders[ordCount].preparetime = foods[orders[ordCount].foodID].preparetime;
    cout << "Order of " << foods[orders[ordCount].foodID].name <<" was successfully added.\n";
    ordCount++;
}

void ReadyOrder(){
    int id;
    cout << "Enter the id of order:\n";
    cin >> id;
    orders[id].ready = true;
    if(orders[id].ready){
        cout << "Order is already READY!\n";
        return;
    }
    cout << "order of " << foods[orders[id].foodID].name << " by " << orders[id].user << " is ready.\n";
    UpdateOrdersFile();
}

void SwapOrders(order *a, order *b){
    order c = *a;
    *a = *b;
    *b = c;
}

void sortOrders(){
    for(int i = 0; i < ordCount; i++)
        for(int j = i; j < ordCount; j++)
            if(!orders[j].isPayed){
                SwapOrders(&orders[j], &orders[i]);
                break;
            }
}

void PayOrder(){
    int id;
    cout << "Enter the id of the order:\n";
    cin >> id;
    if(orders[id].isPayed){
        cout << "The order has already been paid.\n";
        return;
    }
    orders[id].isPayed = true;
    cout << "Order of " << foods[orders[id].foodID].name << " was paid.\n";
    UpdateOrdersFile();
}

void PrintOrder(order ord){
    cout << foods[ord.foodID].name << " " << foods[ord.foodID].price << " " << (ord.isPayed ? "paid" : "not-paid") << " " << (ord.ready ? "READY" : "NOT-READY") << "\n";
}

void PrintAllOrders(){
    for(int i = 0; i < ordCount; i++){
        printf("%02d. ", i);
        PrintOrder(orders[i]);
    }
}

void PrintActiveUserOrders(){
    for(int i = 0; i < ordCount; i++){
        printf("%02d. ", i);
        if(orders[i].user == activeUser.username)
            PrintOrder(orders[i]);
    }
}

void CustomerMenu(){
    int n;
    do{
        cout << "\n#################\n";
        cout << "1.See kababs\n2.See khoreshts\n3.See noshidanis\n4.See mokhalafats\n5.Order\n6.Show orders\n7.Pay\n8.log out\n";
        cin >> n;
        switch(n){
            case 1:
                PrintFoodByCategory("kabab");
                break;
            case 2:
                PrintFoodByCategory("cholo khoresht");
                break;
            case 3:
                PrintFoodByCategory("noshidani");
                break;
            case 4:
                PrintFoodByCategory("mokhalafat");
                break;
            case 5:
                PrintAllFoods();
                AddOrder();
                sortOrders();
                UpdateOrdersFile();
                break;
            case 6:
                PrintActiveUserOrders();
                break;
            case 7:
                PrintActiveUserOrders();
                PayOrder();
                UpdateOrdersFile();
                break;
            case 8:
                mainMenu();
                break;
        }
    }while(n != 8);
}

void SignUp(){
    cout << "Choose your username:\n";
    cin >> users[userCount].username;
    cout << "Choose your password\n";
    cin >> users[userCount].password;
    cout << "User " << users[userCount].username << " successfully signed up.\n"; 
    userCount++;
    UpdateUsersFile();
}

void OwnerMenu(){
    int n;
    do{
        cout << "\n***********************\n";
        cout << "1.See all foods\n2.See all orders\n3.Ready order\n4.Main menu\n";
        cin >> n;
        switch(n){
            case 1:
                PrintAllFoods();
                break;
            case 2:
                PrintAllOrders();
                break;
            case 3:
                PrintAllOrders();
                ReadyOrder();
                break;
            case 4:
                mainMenu();
                break;
        }
    }while(n != 4);
}

void Login(){
    user u;
    cout << "Enter Username:\n";
    cin >> u.username;
    cout << "Enter Password:\n";
    cin >> u.password;
    if(CheckUser(u)){
        // USER
        activeUser = u;
        cout << "successfully logged in as a customer\n";
        CustomerMenu();
    }
    else if(CheckOwner(u)){
        // OWNER
        activeUser = u;
        cout << "successfully logged in as the owner\n";
        OwnerMenu();
    }else
        cout << "Username or password is wrong\n";
}


void mainMenu(){
    int n;
    do{
        cout << "1. login\n2. sign up\n3. exit\n";
        cin >> n;
        switch(n){
            case 1:
                Login();
                break;
            case 2:
                SignUp();
                break;
        }
    }while(n != 3);
}

int main(){
    SetFoods();
    SortFoods();
    ReadUsers();
    ReadOrders();
    sortOrders();
    mainMenu();
}