#include<iostream>
#include<string>
using namespace std;

struct Node {
    string name;
    int id;
    double value;
    Node* next;
};

bool is_equal(Node* check_node, string given_name, int given_id, double given_value) {
    if (check_node->name == given_name && check_node->id == given_id && check_node->value == given_value) {
        return true;
    }
    return false;
}

Node* create_node(string name, int id, double value) {
    Node* new_node = new Node;
    new_node->name = name;
    new_node->id = id;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

Node* add_first(Node* head_node, string name, int id, double value) {
    Node* new_node = create_node(name, id, value);
    new_node->next = head_node;
    return new_node;
}

Node* add_last(Node* head_node, string name, int id, double value) {
    // добавление в пустой список
    if (head_node == NULL) {
        head_node = add_first(head_node, name, id, value);
        return head_node;
    }

    Node* new_node = create_node(name, id, value);
    Node* last_node = head_node;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    return head_node;
}

Node* add_after(Node* head_node, string given_name, int given_id, double given_value, string new_name, int new_id, double new_value) {
    Node* current_node = head_node;
    while (!is_equal(current_node, given_name, given_id, given_value)) {
        current_node = current_node->next;
        if (current_node == NULL) {
            cout << "Node not found, nothing added.\n";
            return head_node;
        }
    }
    Node* new_node = create_node(new_name, new_id, new_value);
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head_node;
}

Node* add_before(Node* head_node, string given_name, int given_id, double given_value, string new_name, int new_id, double new_value) {
    //  если заданный элемент первый в списке
    if (is_equal(head_node, given_name, given_id, given_value)) {
        head_node = add_first(head_node, new_name, new_id, new_value);
        return head_node;
    }
    // находим элемент перед заданным, поставить после него = перед заданным
    Node* current_node = head_node;
    while (!is_equal(current_node->next, given_name, given_id, given_value)) {
        current_node = current_node->next;
        if (current_node->next == NULL) return head_node;
    }

    Node* new_node = create_node(new_name, new_id, new_value);
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head_node;
}

Node* remove_by_name(Node* head_node, string name) {
    Node* previous_node = head_node;
    Node* current_node = previous_node->next;
    if (head_node->name == name) {
        delete head_node;
        return current_node;
    }

    while (current_node->name != name) {
        current_node = current_node->next;
        previous_node = previous_node->next;
        if(current_node == NULL){
            cout << "Node not found, nothing deleted.\n";
            return head_node;
        }
    }
    previous_node->next = current_node->next;
    delete current_node;
    return head_node;
}

void print_list(Node* head_node) {
    Node* current_node = head_node;
    if (head_node == NULL) {
        cout << "List is empty.\n";
        return;
    }
    while (current_node != NULL) {
        cout << current_node->name << ' ' << current_node->id << ' ' << current_node->value << endl;
        if (current_node->next == NULL) break;
        current_node = current_node->next;
    }
    return;
}

int main() {
    Node* head = NULL;
    for (int i = 0; i < 10; i++) {
        head = add_last(head, "a" + to_string(i), i, 2 * i);
    }
    print_list(head);
    cout << "-----\n";
    head = remove_by_name(head, "a1");
    head = add_before(head, "a9", 9, 18, "b1", -1, -1);
    print_list(head);
    cout << "-----\n";
    head = add_after(head, "a9", 9, 18, "b2", -2, -4);
    print_list(head);
    cout << "-----\n";
    head = remove_by_name(head, "a4");
    print_list(head);
    cout << "-----\n";
    return 0;
}
