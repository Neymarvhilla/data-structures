#include <iostream>

/*
 * What is a hash table
 * Simply put, it is a data structure that is used with the technique of
 * hashing. Where hashing is a technique where you take a collection of
 * keys and put them through a 'hashing' function that converts them to
 * an index where they can be stored in the table.
 * */



template<typename T>
class LinkedListNode {
private:
    LinkedListNode *previous_node;
    LinkedListNode *next_node;
    T data;
public:
    LinkedListNode() : previous_node {nullptr}, next_node {nullptr} {};
    T get_data_value() {return data;};
    void set_data_value(T new_value) {data = new_value;};
    LinkedListNode *get_previous_node() {return previous_node;};
    LinkedListNode *get_next_node() {return next_node;};
    void set_previous_node(LinkedListNode *new_previous_node) {previous_node = new_previous_node;};
    void set_next_node(LinkedListNode *new_next_node) {next_node = new_next_node;}
};

template<typename T>
class LinkedList {
private:
    int key;
    LinkedListNode<T> *head;
    LinkedListNode<T> *tail;
    int size;
public:
    LinkedList() : head {nullptr}, tail {nullptr}, size {0} {};
    LinkedListNode<T> *get_head() {return head;};
    LinkedListNode<T> *get_tail() {return tail;};
    void set_head(LinkedListNode<T> new_head) {head = new_head;};
    void set_tail(LinkedListNode<T> new_tail) {tail = new_tail;};
    int get_size() const {return this->size;};
    void set_size(int new_size) {this->size = new_size;};
    int get_key() const{
        return key;
    }
    void set_key(int key_value) {
        this->key = key_value;
    }

    void append(T data_value) {
        auto *new_node = new LinkedListNode<T>;
        new_node->set_data_value(data_value);
        if (size == 0) {
            head = new_node;
            tail = new_node;
            size++;
            return;
        }
        if (size == 1) {
            head->set_next_node(new_node);
            new_node->set_previous_node(head);
            tail = new_node;
            size++;
            return;
        }

        new_node->set_previous_node(tail);
        tail->set_next_node(new_node);
        tail = new_node;
        size++;
    }

    // I want it work like a dictionary / unordered map
    // Hence, when the overloaded = operator is called we can create a node and set the value to the passed in integer
    LinkedList &operator=(T data_value) {
        auto *new_node = new LinkedListNode<T>;
        new_node->set_data_value(data_value);
        if (size == 0) {
            head = new_node;
            tail = new_node;
            size++;
            return *this;
        }
        if (size == 1) {
            head->set_next_node(new_node);
            new_node->set_previous_node(head);
            tail = new_node;
            size++;
            return *this;
        }

        new_node->set_previous_node(tail);
        tail->set_next_node(new_node);
        tail = new_node;
        size++;
        return *this;
    }
    ~LinkedList() {
        LinkedListNode<T> *destroy = head;
        while (destroy != nullptr) {
            destroy = destroy->get_next_node;
            delete destroy->get_previous_node();
        }
    }
};

// My Hashtable class
// I want it to have a fixed size
// I'm still unsure about making the hashing function a member function
template<typename T = LinkedList<int> *>
class Hash_Table{
private:
    int size {5}; // size has been set to five
    T *my_array; // using an array for the behind the scenes implementation
public:
    // when the default constructors is called
    // I want an array of pointers to LinkedList to be dynamically allocated on the heap or free store
    // set the elements in the array to nullptr
    Hash_Table() {
        my_array = new T [size];
        for (size_t i {0}; i < size; ++i) {
            my_array[i] = nullptr;
        }
    }
    // My hashing function
    // The idea is that the key values would be integers
    // the function takes the modulus of two
    // the return value would be the index in which we will store the values in our hashtable
    //
    int hashing_function(int key_value) {
        return key_value % size;
    }

    LinkedList<T> &operator[](int key_value) {
        // obtain the index value
        // we do this by utilizing the hashing function we defined earlier
        int index = hashing_function(key_value);
        if (my_array[index] != nullptr) {
            return *my_array[index];
        }
        // so we can use our overloaded assignment operator to add a new node using chaining
        else {
            my_array[index] = new LinkedList<T>;
            return *my_array[index];
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
