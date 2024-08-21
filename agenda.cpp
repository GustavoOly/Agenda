#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>

using namespace std;

void show_menu(int &choice) {
    cout << "========== Menu ==========" << endl;
    cout << "1. Novo contato" << endl;
    cout << "2. Listar contatos" << endl;
    cout << "3. Remover contato" << endl;
    cout << "0. Sair" << endl;
    cout << "> ";
    cin >> choice;
    cout << "Opação selecionada: " << choice << endl;
    cout << endl;
}

void add_contact(list<map<string, string>> &contacts) {
    string name, email, phone;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, name);
    cout << "Email: ";
    getline(cin, email);
    cout << "Phone: ";
    getline(cin, phone);
    map<string, string> contact;
    contact.insert(make_pair("Nome", name));
    contact.insert(make_pair("Email", email));
    contact.insert(make_pair("Phone", phone));
    contacts.push_back(contact);
}

void list_contacts(list<map<string, string>> contacts) {
    for (map<string, string> contact : contacts) {
        cout << contact["Nome"] << ", " << contact["Email"] << ", "
             << contact["Phone"] << endl;
    }
}

void remove_contact(list<map<string, string>> &contacts) {
    string name;
    bool founded = false;
    cin.ignore();
    cout << "Nome: ";
    getline(cin, name);
    for (map<string, string> contact : contacts) {
        if (contact["Nome"] == name) {
            founded = true;
            contacts.remove(contact);
            break;
        }
    }
    string message = founded ? "Contato removido" : "Contato não encontrado";
    cout << message << endl;
}

int main(int argc, char const *argv[]) {
    int choice = 0;
    list<map<string, string>> contacts;
    do {
        show_menu(choice);
        switch (choice) {
        case 1:
            add_contact(contacts);
            break;
        case 2:
            list_contacts(contacts);
            break;
        case 3:
            remove_contact(contacts);
            break;
        case 0:
            cout << "até mais" << endl;
            break;
        default:
            cout << "opção invalida" << endl;
        }
    } while (choice != 0);

    return 0;
}