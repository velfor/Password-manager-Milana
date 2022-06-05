#include <iostream>
#include <list>
#include <fstream>
#include <string>

struct Password {
    std::string name;
    std::string text;
    std::string category;
    std::string url;
    std::string login;
};
void print_menu();
void encrypt_data(std::string);
void add_password(std::list<Password*> list);
void sort_passwords(std::list<Password*> list);
Password* find_password(std::list<Password*> list);
void edit_password(Password*);
void load_data(std::ifstream& fin, std::list<Password*> list);
int main() {
    std::list<Password*> list1;
    std::string file_name;
    //ввод имени файла
    std::cout << "Input a file name\n";
    std::cin >> file_name;
    std::ifstream fin;
    fin.open(file_name);
    if (!fin.is_open()) {
        std::cout << "Can't open the file";
        return -1;
    }
    //считывание файла в хранилище
    load_data(fin, list1);
    //ввод мастер пароля
    std::string mpassword = "";
    std::cout << "Input the main password";
    std::cin >> mpassword;
    //расшифровка данных
    encrypt_data(mpassword);
    //меню
    while (true) {
        size_t menu_choice;
        print_menu();
        std::cin >> menu_choice;
        switch (menu_choice) {
        case 1:
            std::cout << "search for passwords";
            break;
        case 2:
            std::cout << "sort passwords";
            break;
        case 3:
            std::cout << "add a password";
            break;
        case 4:
            std::cout << "edit a password";
            break;
        case 5:
            std::cout << "remove a password";
            break;
        case 6:
            std::cout << "add a category";
            break;
        case 7:
            std::cout << "remove a category";
            break;
        case 8:
            //запись хранилища в файл
            //закрытие файла
            return 0;
            break;
        default:
            std::cout << "Incorrect choice";
        }
    }
}
void encrypt_data(std::string pass) {

}
void print_menu() {
    std::cout << "1. Search for passwords\n";
    std::cout << "2. Sort passwords\n";
    std::cout << "3. Add a password\n";
    std::cout << "4. Edit a password\n";
    std::cout << "5. Remove a password\n";
    std::cout << "6. Add a category\n";
    std::cout << "7. Remove a category\n";
    std::cout << "8. Exit the program\n";
    std::cout << "Enter your choice: ";
}

void add_password(std::list<Password*> list) {
    Password* pas = new Password();
    std::cout << "Input password name ";
    std::getline(std::cin, pas->name);
    std::cout << "Input password ";
    std::cin >> pas->text;
    std::cout << "Input category ";
    std::cin >> pas->category;
    std::cout << "If you'd like to input url and login press 0";
    int int1;
    std::cin >> int1;
    if (int1 == 0) {
        std::cin >> pas->url;
        std::cin >> pas->login;
    }
    else {
        pas->url="";
        pas->login="";
    }
    list.push_back(pas);
}
void sort_passwords(std::list<Password*> list) {
    std::cout << "1. Sort by name ";
    std::cout << "2. Sort by password ";
    std::cout << "3. Sort by category ";
    std::cout << "Enter your choice: ";
    int sort_criteria;
    std::cin >> sort_criteria;
    switch (sort_criteria) {
    case 1:
        list.sort([](Password* pass1, Password* pass2)->bool {return pass1->name < pass2->name; });
        break;
    case 2: //дописать
        break;
    case 3:
        break;
    default:
        std::cout << "Incorrect choice";
    }

}
Password* find_password(std::list<Password*> list) {
    std::cout << "You might enter only a part of the search string";
    std::cout << "1. Search by name ";
    std::cout << "2. Search by category ";
    std::cout << "Enter your choice: ";
    int search_criteria;
    std::cin >> search_criteria;
    std::string temp;
    Password* found = nullptr;
    switch (search_criteria) {
    case 1:
        std::cout << "Enter password name ";
        std::getline(std::cin, temp);
        for (auto it = list.begin(); it != list.end(); it++) {
            if ((*it)->name.find(temp) != std::string::npos) {
                found = *it;
            }
        }
        break;
    case 2:
        break;
    default:
        std::cout << "Incorrect choice\n";
    }
    return found;
}
void load_data(std::ifstream& fin,  std::list<Password*> list) {
    Password* pas = new Password();
    std::getline(fin, pas->name);
    fin >> pas->text;
    
    std::cin >> pas->category;
    
    int int1;
    std::cin >> int1;
    if (int1 == 0) {
        std::cin >> pas->url;
        std::cin >> pas->login;
    }
    list.push_back(pas);

    fin.close();
}
