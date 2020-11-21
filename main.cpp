#include <iostream>

using namespace std;

#pragma pack(1)
struct node
{
    int     value;
    node*   next;
};

static node *HEAD = nullptr;

void AddNode(int value)
{
    node    *temp = new node;
    temp->value = value;
    temp->next = nullptr;

    if(HEAD == nullptr)     /// This is the first node
    {
        HEAD = temp;
    }
    else
    {
        node *runner = HEAD;

        while(runner->next != nullptr)
        {
            runner = runner->next;
        }

        runner->next = temp;
    }
}

void RemoveNode(int value)
{
    if(HEAD == nullptr) /// No node in list
    {
        cout << "List is Empty" << endl;
        return;
    }

    if(HEAD->value == value)    /// First node
    {
        node *temp = HEAD;
        HEAD = HEAD->next;
        delete temp;

        return;
    }

    node *runner = HEAD;

    bool found_flag(false);
    while(runner->next != nullptr)
    {
        if(runner->next->value == value)
        {
            node *temp = runner->next;
            runner->next = runner->next->next;

            found_flag = true;
            delete temp;
            break;
        }

        runner = runner->next;
    }

    if(!found_flag)
    {
        cout << "Number not present in list" << endl;
    }
}

void PrintList()
{
    node *runner = HEAD;

    cout << "List:" << endl;
    while(runner != nullptr)
    {
        cout << runner->value << "->";
        runner = runner->next;
    }
    cout << "NULL" << endl;
}

void ReverseList3Pointers()
{
    node *previous_node, *next_node, *current_node;
    previous_node = nullptr;
    next_node = nullptr;
    current_node = HEAD;

    while(current_node != nullptr)
    {
        next_node = current_node->next;
        current_node->next = previous_node;

        previous_node = current_node;
        current_node = next_node;
    }

    HEAD = previous_node;

    PrintList();
}

void ReverseList2Pointers()
{
    node *prev_node = nullptr;
    node *next_node = nullptr;

    while (HEAD != nullptr)
    {
        next_node = HEAD->next;
        HEAD->next = prev_node;

        prev_node = HEAD;
        HEAD = next_node;
    }

    HEAD = prev_node;

    PrintList();
}

node *ReverseList1Pointer(node *head)
{
    if(head == nullptr)
        return nullptr;

    if(head->next == nullptr)
        return head;

    node *node1 = ReverseList1Pointer(head->next);
    head->next->next = head;
    head->next = nullptr;

    return node1;
}

int main()
{
    int ch (0);

    for(int i(0); i < 10; i++)
        AddNode(i + 1);

    do
    {
        cout << "1. Add node" <<endl;
        cout << "2. Delete node" << endl;
        cout << "3. Print" << endl;
        cout << "4. Reverse (3 Pointers)" << endl;
        cout << "5. Reverse (2 Pointers)" << endl;
        cout << "6. Reverse (1 Pointer)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice:";
        cin >> ch;

        cout << "----------------------------------------" << endl;

        switch (ch)
        {
        case 1:
        {
            int val;
            cout << "Enter Value:";
            cin >> val;

            AddNode(val);
        }
            break;

        case 2:
        {
            int val;
            cout << "Enter Value:";
            cin >> val;

            RemoveNode(val);
        }
            break;

        case 3:
            PrintList();
            break;

        case 4:
            ReverseList3Pointers();
            break;

        case 5:
            ReverseList2Pointers();
            break;

        case 6:
            HEAD = ReverseList1Pointer(HEAD);
            break;

        case 0:
            exit(0);

        default:
            break;
        }
    }while (ch != 0);

    return 0;
}
