#include <iostream>
#include <string>
using namespace std;

// 노드 구조체 정의
struct Node
{
    int value;
    Node* next;
    // cpp's member initializer list (생성자 정의)
    Node(int data) : value(data), next(nullptr) {};
};

// 큐 클래스 정의
class Queue {
    Node *front, *rear;
    int size;
public:
    Queue(){
        front = rear = nullptr;
    }

    void push(int value){
        this->size++;
        Node* newNode = new Node(value);
        if (rear == nullptr){
            front = rear = newNode;
            return;
        }
        // before update
        rear->next = newNode;
        rear = newNode;
    }

    void pop(){
        if (front == nullptr){
            cout << "-1\n";
            return ;
        }

        this->size--;
        Node* temp = front;
        front = front->next;
        if (front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }

    int front(){
        if (front == nullptr){
            return -1;
        }

        return front->value;
    }

    int back(){
        if (rear == nullptr){
            return -1;
        }

        return rear->value;
    }

    bool isEmpty(){
        if (front == nullptr && rear == nullptr){
            return true;
        }
        return false;
    }
    int size(){
        return this->size;
    }
};

int main(){
    int n_cmd;
    cin >> n_cmd;

    Queue q;
    string op;

    while(n_cmd--){
        cin >> op;
        if (op == "push") {
            int value;
			cin >> value;
			q.push(value);
		}
		else if (op == "pop") {
			if (q.isEmpty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (op == "size") {
			cout << q.size() << '\n';
		}
		else if (op == "empty") {
			cout << q.isEmpty() << '\n';
		}
		else if (op == "front") {
			if (q.isEmpty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (op == "back") {
			if (q.isEmpty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
    }
}