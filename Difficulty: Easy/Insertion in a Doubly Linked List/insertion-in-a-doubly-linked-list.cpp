/* Structure of Doubly Linked List Node
class Node {
	public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int x) {
		data = x;
		next = prev = nullptr;
	}
};
*/

class Solution {
public:
    Node* insertAtPos(Node* head, int p, int x) {
        Node* q = new Node(x);

        Node* tmp = head;
        int t = 0;

        while (t < p && tmp != nullptr) {
            tmp = tmp->next;
            t++;
        }

        if (tmp == nullptr)
            return head;

        q->next = tmp->next;
        q->prev = tmp;

        if (tmp->next)
            tmp->next->prev = q;

        tmp->next = q;

        return head;
    }
};