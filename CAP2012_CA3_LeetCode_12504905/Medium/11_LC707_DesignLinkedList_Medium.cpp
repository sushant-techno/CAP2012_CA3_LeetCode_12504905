// LeetCode 707 - Design Linked List
class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    Node* head;
    int length;

public:
    MyLinkedList() : head(nullptr), length(0) {}

    int get(int index) {
        if (index < 0 || index >= length) return -1;
        Node* cur = head;
        while (index--) cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        length++;
    }

    void addAtTail(int val) {
        Node* node = new Node(val);
        if (head == nullptr) {
            head = node;
        } else {
            Node* cur = head;
            while (cur->next != nullptr) cur = cur->next;
            cur->next = node;
        }
        length++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node* cur = head;
        for (int i = 0; i < index - 1; i++) cur = cur->next;
        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;
        length++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) {
            Node* old = head;
            head = head->next;
            delete old;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) cur = cur->next;
            Node* old = cur->next;
            cur->next = old->next;
            delete old;
        }
        length--;
    }

    // LeetCode manages object lifetime; destructor is optional there.
};
